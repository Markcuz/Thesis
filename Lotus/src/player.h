#ifndef PLAYER_H
#define PLAYER_H

#include <QtCore>

#include <Phonon>
#include <Phonon/MediaObject>
#include <Phonon/AudioOutput>

static const bool defaultRepeatItem = false;
static const bool defaultRepeatAll  = false;
static const qreal defaultVolume  = 0.8;

class Player : public QObject
{
    Q_OBJECT

public:
    Player();

    //needs to be public for the seek /volume slider
    Phonon::MediaObject *mediaObject;
    Phonon::AudioOutput *audioOutput;

public slots:
    void loadSettings();
    void saveSettings();
    void setDefaultSettings();

    void addSources(QDir dir);
    void addSources(QString sourceName);
    void addSources(QStringList sourceNames);
    void selectItem(int index);
    void selectItem(int row, int col);
    void deleteItem();
    void deleteItem(int index);
    void deleteAll();
    void moveItemUp();
    void moveItemDown();
    void moveItem(int index, int newIndex);
    void setRepeatItem(bool repeat);
    void setRepeatAll(bool repeat);
    bool isRepeatItem();
    bool isRepeatAll();

    void play();
    void play(int number);
    void togglePlay();
    void pause();
    void stop();
    void next();
    void prev();

signals:
    void isPlaying(bool);
    void selected(int);
    void mediaListUpdated(QList< QMap<QString,QString> >);
    void debugMsg(QtMsgType, QString, QString);

private:
    QString objName;
    QSettings settings;
    QList<Phonon::MediaSource> sources;
    QList< QMap<QString,QString> > mediaList;
    Phonon::MediaObject *metaInformationResolver;

    bool repeatItem;
    bool repeatAll;
    bool loaded;
    bool playing;
    int metaDataIndex;

private slots:
    void aboutToFinish();
    void stateChanged(Phonon::State newState, Phonon::State oldState);
    void sourceChanged(Phonon::MediaSource);
    void getMetaData();
    void metaError(Phonon::State newState, Phonon::State oldState);

};

#endif // PLAYER_H
