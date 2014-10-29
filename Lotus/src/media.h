#ifndef MEDIA_H
#define MEDIA_H
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QList>

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
    void add(QString);
    void remove();
   // QList<QString> mediaList();

private:
    QMediaPlayer player;
    QMediaPlaylist playlist;
    QString playlistPath;

private slots:
    void read();
    void write();
};

#endif // MEDIA_H
