#ifndef TBS_H
#define TBS_H

#include <QtCore>
#include "qextserialport.h"

static const QString defaultTbsDeviceName = "TBS";
#ifdef WIN32
static const QString defaultTbsPort = "COM4";
#else
static const QString defaultTbsPort = "/dev/ttyACM0";
#endif

struct TbsData {
    float packVoltage;
    float packCurrent;
    float ampHours;
    float soc;
    float timeRemaining;
    float monitorStatus;
    float auxVoltage;
    float temperature;

    TbsData() {
        packVoltage = 0;
        packCurrent = 0;
        ampHours = 0;
        soc = 0;
        timeRemaining = 0;
        monitorStatus = 0;
        auxVoltage = 0;
        temperature = 0;
    }
};

class TBS: public QObject
{
    Q_OBJECT

public:
    TBS();
    virtual ~TBS();

    TbsData getTBSData();

    QFile commandLog;
    QTextStream cLog;

public slots:
    bool init();
    void setDefaultSettings();
    void logRawData(bool);
   // void saveCommands(bool);
    void end();

signals:
    void updated(TbsData tbsData);
    void debugMsg(QtMsgType, QString, QString);
    void error(bool);
    void error(QString);

private:
    QSettings settings;
    QTimer *updateTimer;
    QextSerialPort *port;
    QString devName;

    TbsData tbsData;
    bool rawLogging;
    bool commandLogging;

private slots:
    bool tbs_connect(QString portName);
    void update();
    bool parseMsg(QByteArray tbsArray);

};


#endif // TBS_H
