#ifndef MEDIA_H
#define MEDIA_H
//#include <QMediaPlayer>
//#include <QMediaPlaylist>
//#include <QMediaContent>
#include <QFile>
#include <QStringList>
#include <QDir>
#include <QTextStream>
#include <QDebug>
#include <QProcess>
#include <QTimer>

//This class can be much cleaner and improved if the install of gstreamer or omx is installed on RPi with QT5, code has already been written and working on MAC OSX
//currently using backend method using QProcess and MPG321
class Media : public QObject
{
    Q_OBJECT

public:
    Media();
    QString songName;
    QString artist;

public slots:
    bool init();
    void play();
    void pause();
    void stop();
    void next();
    void prev();
    void add(QString pathName);
    void remove(int index);
    QStringList mediaList();
    void selectItem(int,int);
    QString getSongName(QString raw);
    QString getArtist(QString raw);
    void getData();
    void removeAll();

signals:
    void isPlaying(bool);
    void selected(int);
    void mediaListUpdated();
    void songChanged();

private:

    int currentIndex;
    QProcess *player;
    QString playlistPath;
    QFile playlistFile;
    QStringList playlistString;
    bool isPlay;
    QTimer *updateTimer;

private slots:
    void read();
    void write();
};

#endif // MEDIA_H
