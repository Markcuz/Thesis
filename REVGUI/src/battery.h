#ifndef BATTERY_H
#define BATTERY_H

#define GETZ

#include <QtCore>
#include <QColor>
#include "qextserialport.h"
#include <QSound>
#include <qfile.h>
#include <qtextstream.h>

#ifdef LOTUS
static const QString defaultBatteryDeviceName = "Battery Module";
#endif
#ifdef GETZ
static const QString defaultBatteryDeviceName = "TBS";
#endif
#ifdef WIN32
static const QString defaultBatteryPort = "COM3";
#else
static const QString defaultBatteryPort = "/dev/ttyUSB0";
#endif
static const QString defaultBatteryType = "BATTERY_DEFAULTS";

struct BatteryType
{
    qreal cellVoltageOverCharged;
    qreal cellVoltageFull;
    qreal cellVoltageNormal;
    qreal cellVoltageWarn;
    qreal cellVoltageEmpty;
    qreal cellCapacity;
    qreal maxChargeCurrent;
    qreal maxDischargeCurrent;
};

static const BatteryType TS_LYP60AHA = { 3.9, 3.8, 3.1, 2.8, 2.6, 60.0, 80.0, 600.0 };

static const BatteryType TS_LYP90AHA = { 3.9, 3.8, 3.1, 2.8, 2.6, 90.0, 80.0, 600.0 };

static const BatteryType BATTERY_DEFAULTS = { 3.83, 3.2, 3.1, 2.8, 2.6, 90.0, 80.0, 600.0 };

#ifdef LOTUS
struct BatteryData
{
    int cellNumber;
    BatteryType batteryType;
    int soc;

    qreal voltage;
    qreal current;

    qreal p_current;
    qreal n_current;
    qreal o_current;

    int n_points;
    int p_points;

    float barlow;
    float barhigh;
    float cell_low_average;

    qreal energyUsed;
    qreal energyRegenerated;
    qreal ampHour;
    
    float alarm;

    QList<qreal> cellVoltage;
    QList<qreal> cellVoltageMax;
    QList<qreal> cellVoltageMin;

    BatteryData() {
        cellNumber = 0;
        batteryType = BATTERY_DEFAULTS;
        voltage = 0;
        current = 0;
        p_current = 0;
        n_current = 0;
        n_points = 1;
        p_points = 1;
        energyUsed = 0;
        energyRegenerated = 0;
        ampHour = 60;
    }
};
#endif

#ifdef GETZ
struct BatteryData {
    float voltage;
    float current;
    float ampHours;
    float soc;
    float timeRemaining;
    float monitorStatus;
    float auxVoltage;
    float temperature;
    float maxVoltage;
    float maxCurrent;
    float alarm;
    QByteArray temp;
    BatteryType batteryType;

    BatteryData() {
        voltage = 0;
        current = 0;
        ampHours = 0;
        soc = 0;
        timeRemaining = 0;
        monitorStatus = 0;
        auxVoltage = 0;
        temperature = 0;
        maxVoltage = 172.433;
        maxCurrent = 300;
        batteryType = BATTERY_DEFAULTS;
        alarm = 25.0;
    }
};
#endif

class BMS : public QObject
{
  Q_OBJECT

public:
    BMS();
    virtual ~BMS();

    BatteryData getBatteryData();
    BatteryType getBatteryType();

    float getDischargeCurrent();

#ifdef LOTUS
    int getMinimumBatteryCell();
    int getMaximumBatteryCell();
    float getMinimumBatteryVoltage();
    float getMaximumBatteryVoltage();

    int global_getMinimumBatteryCell();
    int global_getMaximumBatteryCell();
    float global_getMinimumBatteryVoltage();
    float global_getMaximumBatteryVoltage();

    void NNreset();

    float getBarlow();
    float getBarhigh();

    float getCellVoltageTotal();
    float getAverageVoltage();
    float getCellLowAverage();

    QFile capacityLog;
    QTextStream capLog;
#endif

#ifdef GETZ
    BatteryData getTBSData();
    float rawToFloat(QByteArray, int);
#endif
    QFile commandLog;
    QTextStream cLog;

public slots:
    bool init();
    void end();
    void setDefaultSettings();
    void displayRawData(bool);
    void saveCommands(bool);
	
private slots:
#ifdef LOTUS
    bool parseBatteryString(QString batteryString);//Lotus
#endif
#ifdef GETZ
    bool parseBatteryString(QByteArray batteryString);//Getz
#endif
    bool bms_connect(QString portName);
    void update();

signals:
    void updated(BatteryData);
    void debugMsg(QtMsgType, QString, QString);
    void error(bool);
    void error(QString);

private:
    QSettings settings;
    QString devName;
    QextSerialPort *port;
    QTimer *updateTimer;

    QFile file;
    QTextStream stream;

    BatteryData batteryData;

    bool rawDisplay;
    bool commandLogging;

#ifdef LOTUS
    float cellVoltageTotal;
    float averageVoltage;

    int min_bat;
    int max_bat;
    float min_v;
    float max_v;

    int temp_min_bat;
    int temp_max_bat;
    float temp_min_v;
    float temp_max_v;

    bool sw;

    int global_min_bat;
    int global_max_bat;
    float global_min_v;
    float global_max_v;

    qreal auxVoltage;
    qreal capacityPerKm;
    QList<qreal> lastCurrent;
    QList<qreal> engCurrent;
    QList<qreal> v_ind;
#endif


};

#endif // BATTERY_H
