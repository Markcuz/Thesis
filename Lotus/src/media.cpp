#include "media.h"

Media::Media()
{

}

bool Media::init() {
    playlistPath = "/home/pi/";
    read();
    playlist.setCurrentIndex(1);

    player.setPlaylist(&playlist);

    return true;
}

void Media::add(QString pathName) {
    playlist.addMedia(QUrl::fromLocalFile(pathName));
    write();
}

void Media::remove() {
    playlist.removeMedia(playlist.currentIndex());
}

void Media::write() {
    playlist.save(QUrl::fromLocalFile(playlistPath));
}

void Media::read() {
    playlist.load(QUrl::fromLocalFile(playlistPath));
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

/*QList<QString> Media::mediaList() {

}*/



