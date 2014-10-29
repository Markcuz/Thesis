#include "media.h"

Media::Media()
{

}

bool Media::init() {
    playlistPath = "/Users/Markcuz/Desktop/";
    QDir::setCurrent(playlistPath);
    playlistFile.setFileName("playlist.txt");
    playlistFile.open(QIODevice::ReadWrite|QIODevice::Text);
    playlistString.clear();

    read();

    player.setPlaylist(&playlist);
    player.setVolume(150);

    qDebug() << "started media";
    return true;
}

void Media::add(QString pathName) {
    playlist.addMedia(QUrl::fromLocalFile(pathName));
    playlistString.append(pathName);

    qDebug() << "added song";

    write();
}

void Media::remove() {
    int temp = playlist.currentIndex();
    playlistString.removeAt(temp);
    playlist.removeMedia(temp);
    write();
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

    while(!in.atEnd()) {
        QString line = in.readLine();
        add(line);
    }
}

void Media::pause() {
    player.pause();
}

void Media::stop() {
    player.stop();
}

void Media::play() {
    player.play();
}

void Media::next() {
    playlist.next();
}

void Media::prev() {
    playlist.previous();
}

void Media::shuffle() {

    playlist.shuffle();
}

QStringList Media::mediaList() {
    return playlistString;
}



