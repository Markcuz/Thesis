#include "media.h"

Media::Media()
{

}

void Media::start() {
    qDebug() <<"starting media";
    QString program = "mplayer";
    QStringList arguments;
    arguments << "-slave";
    arguments << "-quiet";
    if(playlistString.size()!=0) {
        arguments << "-playlist";
        arguments << "playlist.txt";

        player = new QProcess(this);
        player->start(program,arguments);
        isPlay = true;
        qDebug() << "finsihed start player";
    }
    else {
        songName = "Please Add to playlist";
        artist = "Then press Start";
        emit songChanged();
        emit artistChanged();
    }
}

bool Media::init() {
        qDebug() << "got to inint";
    playlistPath = "/home/pi/";
    QDir::setCurrent(playlistPath);
    playlistFile.setFileName("playlist.txt");
    playlistFile.open(QIODevice::ReadWrite|QIODevice::Text);
    playlistString.clear();

    updateTimer = new QTimer(this);
    connect(updateTimer, SIGNAL(timeout()), this, SLOT(getData()));

    qDebug() << "got to before start player";

    read();
        start();
    updateTimer->start(2000);
    return true;
}

/**
 * @brief Media::add
 * @param pathName
 */
void Media::add(QString pathName) {

    playlistString.append(pathName);
    QString writeString = "loadlist "+pathName+" 1\n";
    player->write(writeString.toLatin1().data());

    write();
    qDebug() << "added song";
}

/**
 * @brief Media::remove removes the current played song from the playlist
 */
void Media::remove(int index) {
    playlistString.removeAt(index);
    write();
    QString writeString = "loadlist "+playlistPath+"playlist.txt\n";

    player->write(writeString.toLatin1().data());
}

void Media::write() {
    QString temp;
    QTextStream out(&playlistFile);

    for(int i = 0; i<playlistString.length(); i++) {
        temp.append(playlistString.at(i));
        temp.append('\n');
    }
    playlistFile.resize(0);
    out<<temp;
}

void Media::read() {
    QTextStream in(&playlistFile);

    playlistString.clear();

    while(!in.atEnd()) {
        QString line = in.readLine();
        playlistString.append(line);
    }
}

void Media::pause() {
    player->write("pause\n");
    isPlay = false;
}

void Media::stop() {
    player->write("quit\n");
    isPlay = false;
}

void Media::play() {
    player->write("pause\n");
    isPlay = true;
}

void Media::next() {
    player->write("pt_step 1\n");
}

void Media::prev() {
    player->write("pt_step -1\n");
}

void Media::getData() {
    if(isPlay) {
    QString temp = player->readAll();
    if (temp.size()>50) {
        songName = getSongName(temp);
        artist = getArtist(temp);
        emit songChanged();
        emit artistChanged();
    }
    else if (temp.size()>5&&temp.size()<20){
        isPlay = false;
    }
    }
}

QString Media::getSongName(QString rawString) {
    QString name;
    int index = rawString.indexOf("Title: ");
    index = index + 7;
    while(rawString.at(index) != '\n') {
        name.append(rawString.at(index));
        index++;
    }
    return name;
}

QString Media::getArtist(QString rawString) {
    QString name;
    int index = rawString.indexOf("Artist: ");
    index = index + 8;
    while(rawString.at(index) != '\n') {
        name.append(rawString.at(index));
        index++;
    }
    return name;
}

void Media::removeAll() {
    playlistString.clear();
    write();
    player->write("quit\n");
    start();
}

QStringList Media::mediaList() {
    return playlistString;
}
