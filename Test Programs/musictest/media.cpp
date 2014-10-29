#include "media.h"

Media::Media()
{

}

bool Media::init() {
    playlistPath = "/home/pi/";
    QDir::setCurrent(playlistPath);
    playlistFile.setFileName("playlist.txt");
    playlistFile.open(QIODevice::ReadWrite|QIODevice::Text);

    read();

    QString program = "mplayer";
    QStringList arguments;
    arguments << "-slave";
    arguments << "-quiet";
    if(playlistString.size()!=0) {
    arguments << "-playlist";
    arguments << "playlist.txt";
    }

    player = new QProcess(this);
    player->start(program,arguments);

    isPlay = false;

    qDebug() << "init Media player";

    updateTimer = new QTimer(this);
    connect(updateTimer, SIGNAL(timeout()), this, SLOT(getData()));
    updateTimer->start(2000);

    return true;
}

/**
 * @brief Media::add
 * @param pathName
 */
void Media::add(QString pathName) {

    qDebug() << "adding song";

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
    qDebug() << "paused";
    isPlay = false;
}

void Media::stop() {
    player->write("stop\n");
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
    QString temp = player->readAll();
    qDebug() << temp;
    qDebug() << temp.length();
    if (!temp.isEmpty()) {
        songName = getSongName(temp);
        artist = getArtist(temp);
        emit songChanged();
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
    qDebug() << name;
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
    qDebug() << name;
    return name;
}

void Media::removeAll() {
    playlistString.clear();
    write();

    QString writeString = "loadlist "+playlistPath+"playlist.txt\n";

    player->write(writeString.toLatin1().data());
}

QStringList Media::mediaList() {
    return playlistString;
}

void Media::selectItem(int row, int col) {

}
