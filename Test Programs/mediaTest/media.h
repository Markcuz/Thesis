#ifndef MEDIA_H
#define MEDIA_H
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QMediaContent>
#include <QFile>
#include <QStringList>
#include <QDir>
#include <QTextStream>
#include <QDebug>

class Media : public QObject
{
    Q_OBJECT

public:
    Media();

public slots:
    bool init();
    void play();
    void pause();
    void stop();
    void next();
    void prev();
    void add(QString pathName);
    void remove();
    void shuffle();
    QStringList mediaList();

private:
    QMediaPlayer player;
    QMediaPlaylist playlist;
    QString playlistPath;
    QFile playlistFile;
    QStringList playlistString;

private slots:
    void read();
    void write();
};

#endif // MEDIA_H
