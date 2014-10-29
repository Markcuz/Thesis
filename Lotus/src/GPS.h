#ifndef GPS_H
#define GPS_H

#define LOTUS

#include <QtCore>
#include "qextserialport.h"

static const QString defaultGpsDeviceName = "QSTARZ GPS 818X";
#ifdef WIN32
static const QString defaultGpsPort = "COM2";
#else
static const QString defaultGpsPort = "/dev/ttyACM0";
#endif


struct PositionData
{
    bool valid;

    //utc time from satellites
    QDateTime UTCDateTime;
    int UTCDay;
    int UTCMonth;
    int UTCYear;
    int UTCHour;
    int UTCMinute;
    int UTCSecond;
    int UTCMilliSec;

    //latitude ranges from -90 to 90. N is +ve
    qreal latitude;
    //longitude ranges from -180 to 180. E is +ve.
    qreal longitude;
    //altitude above sea level
    qreal altitude;
    //horizontal dilution of precision
    qreal hdop;
    //number of satellites
    int numSat;
    //heading in degrees
    qreal heading;
    //speed in km/h
    qreal speed;

    //overall distance in km
    qreal totalDistance;

    //initialize default values
    PositionData()  {
        valid = false;
        UTCDay = 0;
        UTCMonth = 0;
        UTCYear = 0;
        UTCHour = 0;
        UTCMinute = 0;
        UTCSecond = 0;
        UTCMilliSec = 0;
        UTCDateTime.setTimeSpec(Qt::UTC);
        latitude = 0;
        longitude = 0;
        altitude = 0;
        hdop = 0;
        numSat = 0;
        heading = 0;
        speed = 0;
        totalDistance = 0;
    }

};


class GPS : public QObject
{
    Q_OBJECT

public:
    GPS();
    virtual ~GPS();

    PositionData getPositionData();

    QFile commandLog;
    QTextStream cLog;

public slots:
    bool init();
    void end();
    void setDefaultSettings();
    void displayRawData(bool);
    void saveCommands(bool);


signals:
    void updated(PositionData positionData);
    void debugMsg(QtMsgType, QString, QString);
    void error(bool);
    void error(QString);

private:
    QSettings settings;
    QTimer *updateTimer;
    QTimer *errorTimer;
    QextSerialPort *port;
    QString devName;

    PositionData positionData;
    bool rawDisplay;
    bool commandLogging;

private slots:
    bool gps_connect(QString portName);
    void update();
    bool parseNMEA(QString gpsString);

};

#endif // GPS_H
