#ifndef ENGINE_PORT_H
#define ENGINE_PORT_H

#define GETZ
/*#if defined(_WIN32)
#pragma message("Warning: Windows detected.")
#include <WinSock2.h>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")
#else if defined(linux)
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#endif*/
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <QThread>
#include <string>
#include <sstream>
#include <string>
#include <QtCore>
#include <QTcpSocket>
#include "io.h"
#include "/Users/Markcuz/Desktop/Thesis/REVGUI/alsa-lib-1.0.27.2/include/asoundlib.h"

/* SIMULATED GEAR SETTINGS */
#define MAX_GEARS					12
#define DEFAULT_NUM_GEARS			6
#define DEFAULT_BASE_RATIO			0.009f
#define DEFAULT_RATIO_GROWTH		1.700f
#define DEFAULT_GROWTH_REDUCTION	0.920f
#define RPM_CRUISE_LOW				1950
#define RPM_CRUISE_IDEAL			2300
#define RPM_CRUISE_HIGH				2700
#define RPM_MIN						2000
#define RPM_MAX						5000
#define TURBO_SHIFT_DOWN_THROTTLE	0.400f

static const QString soundDir = "Sounds/";
static const QString clickf = "click.wav";
static const QString vf = "vol.wav";
static const QString bf = "alert.wav";
static const QString Name = "Engine Simu";
static const int defaultVolume = 50;
#define RATE 44100
#define CHANNELS 2
#define PCM_DEVICE "default"

Q_DECLARE_METATYPE(QtMsgType)

class engine_port : public QObject
{

Q_OBJECT

public:
    engine_port();
    virtual ~engine_port();
    void end();

    void volumeChange();
    void currentSend(float);

    bool run;
    int vol;
    int RPM;
    char cRPM[5];

private:
    void stopClick();
    void stopVolEffect();
    void stopLowBatt();
    void setDir();
    void stop();

    QSettings settings;
    unsigned int tmp;
    unsigned int rate;
    int channels;
    snd_pcm_t *pcm_handle;
    snd_pcm_hw_params_t *params;
    snd_pcm_uframes_t frames;
    char *buff;
    int buff_size, loops, pcm;
    int seconds;
    int val;
    QFile clickFile;
    QFile bFile;
    QFile vFile;
    QFile file;
    qint64 fsize;
    int fd, cfd, vfd, bfd;
    int buff_total;
    int curvol;
    char* dir;
    char *filename;
    bool stopped;
    bool cstopped;
    bool vstopped;
    bool bstopped;
    int alertCount;

signals:
    void debugMsg(QtMsgType, QString, QString);
    void ready();
    void finished();
    void checkRun();
    void checkRPM();
    void clicking(bool);

public slots:
    void init();
    void runSimu();
    void click();
    void close();
    void volEffect();
    void lowBatt();
/*
public:
    engine_port();


    bool init(int);
    //void connect_engine();
    void close();
    void sendData(int);
    void testSend();
    void testSend2();
    void currentSend(float);
    void boot_failure();
    void volumeChange(int);
    void GearBox_Update_Auto(int, float);
    void GearBox_SetNumGears(int);
    void GearBox_ApplyGearRatios();
    void GearBox_SetGearRatios(float, float, float);
    char* itoa(int, char*, int);

signals:
    void debugMsg(QtMsgType, QString, QString);

private:
    char                sendbuf[5];
    int                 BytesSent, nlen;
    static const unsigned int        port = 3000;
    QString host;
    int  RetCode;
    QString devName;
    QTcpSocket  m_socket;
    int volume;

    // Car Data
    int 	CurrentRPM;
    int 	DeltaRPM;
    int 	CurrentSpeed;
    int 	CurrentGear;
    float 	Throttle;

    //Gear Configuration
    int 	 NumGears;
    float 	 GearRatios[DEFAULT_NUM_GEARS];
    float 	 RatioBase;
    float 	 RatioGrowth;
    float 	 GrowthReduction;
    bool         gearsOn;

private slots:
    void connectionError(QAbstractSocket::SocketError);
    void state_change(QAbstractSocket::SocketState);
    void connect_engine();
*/
};

#endif // ENGINE_PORT_H
