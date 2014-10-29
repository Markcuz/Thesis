# -------------------------------------------------
# Project created by QtCreator 2010-05-07T00:13:06
# -------------------------------------------------
QT += network \
    svg \
    xml \
    multimedia \
    quick \
    widgets printsupport \

target.path = /home/pi
TARGET = REV_HMI_LOTUS
INSTALLS += target
TEMPLATE = app
#LIBS +=C:\Qt\2010.05\mingw\lib\libws2_32.a
#LIBS += $$(QTCC)\\lib\\libws2_32.a #C:\\Compiler\\QtSDK\\mingw
#LIBS+= "C:/Users/tylerm03/Desktop/REV/Lotus/REV_HMI-build-desktop/twitcurl/libtwitcurl.a"
#LIBS += ../external-libraries/twitcurl/libs/libtwitcurl.a
LIBS += -L~/Qt/rasp-pi-rootfs/usr/lib/arm-linux-gnueabihf -lasound
FORMS += lotus_hmi.ui
RESOURCES = resources.qrc
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x000000
include(external-libraries/qextserialport-1.2rc/src/qextserialport.pri)
#INCLUDEPATH += ../external-libraries/qextserialport/src
#INCLUDEPATH += ../external-libraries/curl-7.21.7-devel-mingw32/include/
#INCLUDEPATH += ../external-libraries/xsens/dll
#INCLUDEPATH += ../external-libraries/twitcurl/
#INCLUDEPATH += ../external-libraries/phonon_backend/
INCLUDEPATH += ~/Qt/rasp-pi-rootfs/usr/include
INCLUDEPATH += ~/opt/rasp-pi-rootfs/usr/include
DEPENDPATH += ~/Qt/rasp-pi-rootfs/usr/include
DEPENDPATH += ~/opt/rasp-pi-rootfs/usr/include
DEPENDPATH += external-libraries/qextserialport-1.2rc/src/
#DEPENDPATH += ../external-libraries/qextserialport/src/
#DEPENDPATH += ../external-libraries/xsens/dll
#LIBS += -L../external-libraries/xsens/dll/ -lxsens_cmt
#win32::SOURCES += win_qextserialport.cpp
#unix::SOURCES += ../external-libraries/qextserialport/src/posix_qextserialport.cpp
SOURCES += main.cpp \
    rev_hmi.cpp \
    GPS.cpp \
    battery.cpp \
#    iomodule.cpp \
#    ../external-libraries/qextserialport/src/qextserialport.cpp \
#    player.cpp \
    logger.cpp \
    mapwidget.cpp \
    debuglogger.cpp \
       engine_port.cpp \
#	energymeter.cpp \
#    quaternions.cpp \
        qtransparentwidget.cpp \
#        traffic.cpp \
#    lotusmechanics.cpp \
    io.cpp \
    qcustomplot.cpp \
    media.cpp

HEADERS += rev_hmi.h \
#	../external-libraries/twitcurl/twitcurl.h \
#	../external-libraries/xsens/dll/xsens_cmt.h \
    GPS.h \
    battery.h \
#   iomodule.h \
#    ../external-libraries/qextserialport/src/qextserialport.h \
#    player.h \
    logger.h \
    mapwidget.h \
    debuglogger.h \
        engine_port.h \
#	energymeter.h \
#    quaternions.h \
        qtransparentwidget.h \
#        traffic.h \
#    lotusmechanics.h \
    io.h \
    qcustomplot.h \
    media.h

CONFIG(debug, debug|release) DEFINES += DEBUG
CONFIG(release, debug|release) DEFINES += RELEASE
#DEFINES += TEST
TRANSLATIONS =  localisations/rev_hmi_en.ts \
                localisations/rev_hmi_de.ts \
                localisations/rev_hmi_fr.ts


 Release:DESTDIR = ../REV_HMI-result
 Debug:DESTDIR = ../REV_HMI-result
