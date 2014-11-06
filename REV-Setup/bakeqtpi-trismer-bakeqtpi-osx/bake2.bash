#!/bin/bash
#This script will download, set up, compile QT5, and set up the SDCard image ready to use.
#Pass -h to use https for git


SCRIPT_DIR=$PWD
OPT_DIRECTORY=~/opt
QTBASE=$OPT_DIRECTORY/qt5

#Some sensible defaults
CROSSCOMPILER=$/Users/Markcuz/Desktop/Thesis/REV-Setup/newQT/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian
CROSSCOMPILETOOLS=$/Users/Markcuz/Desktop/Thesis/REV-Setup/newQT/cross-compile-tools
CROSSCOMPILERPATH=$CROSSCOMPILER/bin/arm-linux-gnueabihf-gcc

MOUNT=$OPT_DIRECTORY/rasp-pi-image
ROOTFS=$OPT_DIRECTORY/rasp-pi-rootfs

QT5PIPREFIX=/usr/local/qt5pi
QT5ROOTFSPREFIX=$ROOTFS/usr/local/qt5pi

#Raspbian image and download stuff
RASPBIAN=2012-09-18-wheezy-raspbian

RASPBIAN_HTTP=http://ftp.snt.utwente.nl/pub/software/rpi/images/raspbian/$RASPBIAN/$RASPBIAN.zip
RASPBIAN_TORRENT=http://downloads.raspberrypi.org/images/raspbian/$RASPBIAN/$RASPBIAN.zip.torrent

CUSTOM_RASPBIAN=""

WGET_OPT="-nc -c"

command -v sudo >/dev/null 2>&1 || { echo >&2  "Sudo needs to be installed for the fixQualifiedLibraryPaths script to work"; exit 1; }

#Debugfs path
DEBUGFS=/usr/local/Cellar/e2fsprogs/*/sbin/debugfs

#Git repos
if [[ "$OSTYPE" =~ darwin.* ]]
then
CROSSCOMPILEGIT="gitorious.org/~trismer/cross-compile-tools/trismers-cross-compile-tools-osx.git"
else
CROSSCOMPILEGIT="gitorious.org/cross-compile-tools/cross-compile-tools.git "
fi

QT_GIT="gitorious.org/qt/qt5.git"
GIT=GIT

INITREPOARGS="--no-webkit -f"

#Basically, a list of all the folders in the checked out qt5 repo to cd into and build. qtbase will already be done by this point
QT_COMPILE_LIST="qtimageformats qtsvg qtjsbackend qtscript qtxmlpatterns qtdeclarative qtsensors qt3d qtgraphicaleffects qtlocation qtquick1 qtsystems qtmultimedia"

CONFIGURE_OPTIONS=""

#Work out how many concurrent threads to run
if [[ "$OSTYPE" =~ darwin.* ]]
then
CORES=`sysctl -a | grep machdep.cpu.thread_count | awk '{print $2}'`
else
CORES=`grep -c '^processor' /proc/cpuinfo`
fi

CORES=`echo $CORES | grep '^[[:digit:]]*$'`

if [ "$CORES" == "" ]
then
CORES=1
echo "CPU Core count failed, defaulting to single thread compilation"
else
echo "Using $CORES threads for compilation"
fi


#Parse arguments
while test $# -gt 0
do
case $1 in
# Normal option processing
-h | --help)
# usage and help
echo "Usage:"
echo "		./bakeqtpi.bash [options]"
echo "options:"
echo "		--http			Tells git and init-repository to use http(s)"
echo "		--httppi 		Tells the script to download the Raspbian image using http/wget"
echo "		--torrentpi		Tells the script to download the Raspbian image using torrent/ctorrent"
echo "		--raspbian <path>	Use custom raspbian. Note, you can point this to your SD card, assuming it's a standard"
echo "						raspbian sd card using --raspbian /dev/sdX (Don't put the partition number in)"
echo "		--confclean		Runs 'make confclean' before running ./configure"
echo "		-v, --version		Version Info"
echo "		-h, --help		Help and usage info"
exit
;;
-v | --version)
# version info
echo "Version 0.1"
exit
;;
--http)
GIT=HTTPS
;;
--httppi)
HTTPPI=1
;;
--torrentpi)
TORRENT=1
;;
--raspbian)
shift
CUSTOM_RASPBIAN=$1
;;
--confclean)
CONFCLEAN=1
;;

# Special cases
--)
break
;;
--*)
# error unknown (long) option $1
;;
-?)
# error unknown (short) option $1
;;

# FUN STUFF HERE:
# Split apart combined short options
-*)
split=$1
shift
set -- $(echo "$split" | cut -c 2- | sed 's/./-& /g') "$@"
continue
;;

# Done with options
*)
break
;;
esac

shift
done

if [ "$GIT" == "HTTPS" ]; then
CROSSCOMPILEGIT="https://git."$CROSSCOMPILEGIT
QT_GIT="https://git."$QT_GIT
INITREPOARGS="$INITREPOARGS --http"
else
CROSSCOMPILEGIT="git://"$CROSSCOMPILEGIT
QT_GIT="git://"$QT_GIT
fi


function error {
case "$1" in

1) echo "Error making directories"
;;
2) echo "Error downloading raspbian image"
;;
3) echo "Error mounting raspbian image"
;;
4) echo "Error downloading cross compilation tools"
;;
5) echo "Error extracting cross compilation tools"
;;
6) echo "Error cloning qt5 repo"
;;
7) echo "Error initialising qt5 repo"
;;
8) echo "Error running fixQualifiedLibraryPaths"
;;
9) echo "Configuring QT Failed"
;;
10) echo "Make failed for QTBase"
;;
*) echo "Unknown error"
;;

esac
exit -1
}

#Download and mount the Raspbian image, tested on OS X and Ubuntu
function downloadAndMountPi {
cd $OPT_DIRECTORY

if [ "$CUSTOM_RASPBIAN" == "" ]; then
echo "Downloading Raspbian"
if [ "$TORRENT" == 1 ]; then
dl="T"
elif [ "$HTTPPI" == 1 ];then
dl="H"
else
echo "Would you like to download the Raspbian image using HTTP(H) or ctorrent(T)"
read -e dl

while [[ ! $dl =~ [TtHh] ]]; do
echo "Please type H for HTTP or T for ctorrent"
read dl
done
fi

if [[ $dl =~ [Hh] ]]; then
wget $WGET_OPT $RASPBIAN_HTTP || error 2
else
wget $WGET_OPT $RASPBIAN_TORRENT || error 2
ctorrent -a -e - $RASPBIAN.zip.torrent || error 2
fi

unzip $RASPBIAN.zip || error 2
RASPBIAN_IMG=$RASPBIAN.img
else
RASPBIAN_IMG=$CUSTOM_RASPBIAN
fi

echo "Using Raspbian image at $CUSTOM_RASPBIAN"

echo "Mounting raspbian image"

if [[ "$OSTYPE" =~ darwin.* ]]
then
if [ -d $MOUNT ]; then
hdiutil detach $MOUNT
fi
#echo "hdiutil attach -mountpoint $SCRIPT_DIR $MOUNT $RASPBIAN_IMG"
DISK=`hdiutil attach -mountpoint $MOUNT $RASPBIAN_IMG | grep Linux | awk '{print $1}'`
if [[ ! "$DISK" =~ /dev/disk* ]]; then
error 3
fi
echo "rdump lib $ROOTFS" > $OPT_DIRECTORY/rdump.lst
echo "rdump opt $ROOTFS" >> $OPT_DIRECTORY/rdump.lst
echo "rdump usr $ROOTFS" >> $OPT_DIRECTORY/rdump.lst
echo "rdump var $ROOTFS" >> $OPT_DIRECTORY/rdump.lst
if [ ! -d $ROOTFS ]; then
mkdir $ROOTFS
$DEBUGFS -f $OPT_DIRECTORY/rdump.lst $DISK || error 3
fi
else
if [ ! -d $ROOTFS ]; then
if [ "$(id -u)" != "0" ]; then
sudo mkdir $ROOTFS || error 3
else
mkdir $ROOTFS || error 3
fi
else
if [ "$(id -u)" != "0" ]; then
sudo umount $ROOTFS
else
umount $ROOTFS
fi
fi
if [ "$(id -u)" != "0" ]; then
sudo mount -o loop,offset=62914560 $RASPBIAN_IMG $ROOTFS || error 3
else
mount -o loop,offset=62914560 $RASPBIAN_IMG $ROOTFS || error 3
fi
fi
echo "Raspbian mounted"
}

#Download and extract cross compiler and tools
function dlcc {
cd $OPT_DIRECTORY
echo "Downloading Cross compiler and extra tools"
if [[ "$OSTYPE" =~ darwin.* ]]
then
wget $WGET_OPT http://trismer.com/downloads/arm-linux-gnueabihf-osx-2012-08-28.tar.gz || error 4
tar -xf arm-linux-gnueabihf-osx-2012-08-28.tar.gz || error 5
CROSSCOMPILER=$OPT_DIRECTORY/arm-linux-gnueabihf-osx
CROSSCOMPILERPATH=$CROSSCOMPILER/bin/arm-linux-gnueabihf-gcc
#create symbolic link for readelf
ln -s $CROSSCOMPILER/bin/arm-linux-gnueabihf-readelf readelf
export PATH=$OPT_DIRECTORY:$PATH
else
wget $WGET_OPT http://blueocean.qmh-project.org/gcc-4.7-linaro-rpi-gnueabihf.tbz || error 4
tar -xf gcc-4.7-linaro-rpi-gnueabihf.tbz || error 5
CROSSCOMPILERPATH=$CROSSCOMPILER/bin/arm-linux-gnueabihf-gcc
fi

if [ ! -d $CROSSCOMPILETOOLS/.git ]; then
git clone $CROSSCOMPILEGIT || error 4
else
cd $CROSSCOMPILETOOLS && git pull && cd $OPT_DIRECTORY
fi
echo "Cross Compilation tools downloaded and extracted"
}

function dlqt {
echo "Cloning QT Code"
cd $OPT_DIRECTORY
if [ ! -d $OPT_DIRECTORY/qt5/.git ]; then
git clone $QT_GIT || error 6
else
cd $OPT_DIRECTORY/qt5/ && git pull
cd $CROSSCOMPILETOOLS
./syncQt5
cd $OPT_DIRECTORY
fi
cd qt5
while [ ! -e $OPT_DIRECTORY/qt5/.initialised ]
do
./init-repository $INITREPOARGS && touch $OPT_DIRECTORY/qt5/.initialised
done || error 7
echo "Code cloned"
#cd $OPT_DIRECTORY/qt5/qtjsbackend
#git fetch https://codereview.qt-project.org/p/qt/qtjsbackend refs/changes/56/27256/4 && git cherry-pick FETCH_HEAD
}

function prepcctools {
cd $CROSSCOMPILETOOLS
echo "Fixing Qualified Library Paths, whatever that means..."
./fixQualifiedLibraryPaths $ROOTFS $CROSSCOMPILERPATH || error 8
cd $OPT_DIRECTORY/qt5/qtbase
}

function configureandmakeqtbase {
echo "Configuring QT Base"

CONFIGURE_OPTIONS="-opengl es2 -device linux-rasp-pi-g++ -device-option CROSS_COMPILE=$CROSSCOMPILER/bin/arm-linux-gnueabihf- -sysroot $ROOTFS -opensource -confirm-license -optimized-qmake -release -make libs -prefix $QT5PIPREFIX -no-pch"

if [ ! -f /etc/redhat-release ]
then
CONFIGURE_OPTIONS="$CONFIGURE_OPTIONS -reduce-exports -reduce-relocations"
fi

cd $OPT_DIRECTORY/qt5/qtbase
if [ "$CONFCLEAN" == 1 ]; then
echo "Cleaning first"
rm -f $OPT_DIRECTORY/qt5/qtbase/.CONFIGURED
cd $OPT_DIRECTORY/qt5/qtbase
make confclean
fi
if [ ! -e $OPT_DIRECTORY/qt5/qtbase/.CONFIGURED ]; then
./configure $CONFIGURE_OPTIONS && touch $OPT_DIRECTORY/qt5/qtbase/.CONFIGURED || error 9
fi
echo "Making QT Base"
make -j $CORES || error 10
}

function installqtbase {
echo "Installing QT Base"
cd $OPT_DIRECTORY/qt5/qtbase
if [ "$(id -u)" != "0" ]; then
sudo make install
sudo cp -r $QT5PIPREFIX/mkspecs $QT5ROOTFSPREFIX/
else
make install
cp -r $QT5PIPREFIX/mkspecs $QT5ROOTFSPREFIX/
fi
echo "QT Base Installed"
}

function makemodules {
echo "Making QT Modules $QT_COMPILE_LIST"
for i in $QT_COMPILE_LIST
do
if [ "$(id -u)" != "0" ]; then
cd $OPT_DIRECTORY/qt5/$i && echo "Building $i" && sleep 3 && $QT5PIPREFIX/bin/qmake . && make -j $CORES && sudo make install && touch .COMPILED
else
cd $OPT_DIRECTORY/qt5/$i && echo "Building $i" && sleep 3 && $QT5PIPREFIX/bin/qmake . && make -j $CORES && make install && touch .COMPILED
fi
cd $OPT_DIRECTORY/qt5/
done

cd $OPT_DIRECTORY/qt5/qtdeclarative/examples/demos/samegame
$QT5PIPREFIX/bin/qmake .
make -j $CORES
sudo make install

for i in $QT_COMPILE_LIST
do
if [ -e "$OPT_DIRECTORY/qt5/$i/.COMPILED" ]
then
echo "Compiled $i"
else
echo "Failed   $i"
fi
done
}

function copyToImage {
if [[ "$OSTYPE" =~ darwin.* ]]
then
cd $ROOTFS
tar -czf $OPT_DIRECTORY/qt5pi.tgz usr/local/qt5pi
echo "Adding qt5pi.tgz to the Raspbian image at /"
$DEBUGFS -w -R "rm qt5pi.tgz" $DISK
$DEBUGFS -w -R "write $OPT_DIRECTORY/qt5pi.tgz qt5pi.tgz" $DISK
echo "Extract qt5pi.tgz on your pi at /"
echo "Unmounting image"
hdiutil detach $MOUNT
fi
}

#Start of script

mkdir -p $OPT_DIRECTORY || error 1
cd $OPT_DIRECTORY || error 1

downloadAndMountPi
#dlcc
#dlqt
prepcctools
configureandmakeqtbase
installqtbase
makemodules
copyToImage

