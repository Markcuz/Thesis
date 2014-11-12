#ifndef REV_HMI_H
#define REV_HMI_H

#define LOTUS //In GPS.h, battery.h, debuglogger.h, engine_port.h, io.h, logger.h. Also need to change .pro file

#include <QMainWindow>
#include <QProcess>
#include <QString>
#include <QDomDocument>
#include <QInputDialog>
#include <QMessageBox>
#include <QFileDialog>
#include <QShortcut>
#include <QSoundEffect>
#include <QAudioDeviceInfo>
#include <QList>
#include <cmath>
#include <iostream>

#include <QTimer>

#include "GPS.h"
#include "battery.h"
#include "io.h"
#include "media.h"
#include "logger.h"
#include "debuglogger.h"
#include "engine_port.h"
//#include "traffic.h"

#include "external-libraries/qcustomplot/qcustomplot.h"

#ifdef LOTUS
#include "ui_lotus_hmi.h"
#endif
#ifdef GETZ
#include "ui_getz_hmi.h"
#endif

#ifdef LOTUS
#define MAXRANGE 90
#endif
#ifdef GETZ
#define MAXRANGE 50
#endif

static const QString revPassword = "revAdmin";
#ifdef LOTUS
static const double final = 4.2;
static const double ratio1 = 2.92 * final;
static const double ratio2 = 1.750 * final;
static const double ratio3 = 1.31 * final;
static const double ratio4 = 1.03 * final;
static const double ratio5 = 0.85 * final;
static const double radius = 0.3;
#endif
#ifdef GETZ
static const double final = 3.842;
static const double ratio1 = 3.615 * final;
static const double ratio2 = 1.950 * final;
static const double ratio3 = 1.286 * final;
static const double ratio4 = 1.061 * final;
static const double ratio5 = 0.838 * final;
static const double radius = 0.469;
#endif

namespace Ui {
    class REV_HMI;
}

class REV_HMI : public QMainWindow {
    Q_OBJECT
public:
    REV_HMI(QWidget *parent = 0);
    ~REV_HMI();

protected:
    void changeEvent(QEvent *e);

private slots:
#ifdef LOTUS
    void on_pushButton_NNreset_clicked();
    void horizontalSlider_released();
    void on_homeBut_clicked();
    void on_mapBut_clicked();
    void on_musicBut_clicked();
    void on_battBut_clicked();
    void on_tripBut_clicked();
    void on_logBut_clicked();
    void init_ui_battery(int cellCount = 12);

    QColor v2Color(double voltage, BatteryType);
#endif
#ifdef GETZ
    void init_shortcuts();
    void changeNextTab();
    void changePrevTab();
#endif
    void on_pushButton_export_clicked();
    void on_pushButton_location_clicked();
    void on_horizontalSlider_valueChanged(int);
    void incVol();
    void decVol();
    void on_pushButton_defaultSettings_clicked();
    void on_pushButton_exit_clicked();
    void on_pushButton_Runsound_clicked();
    void on_pushButton_changeRange_clicked();
    void on_pushButton_loadTrack_clicked();
    void on_pushButton_deleteTrack_clicked();
    void on_pushButton_tripReset_clicked();

    void init_ui();
    void init_io();
    void init_sound();
    void init_ui_map();
    void on_mapContHide_clicked();
    void init_ui_logger();
    void init_ui_debugLogging();

    void driverChanged();

    void update_ui_gps(PositionData positionData);
    void update_ui_battery(BatteryData batteryData);
    void update_ui_trip(TripData tripData);
    void update_ui_io(IOData ioData);
    //void update_ui_gears(IOData ioData);


    void changeLogButtonStart(bool isLogging);
    void changeLogButtonPause(bool isPaused);

    //Navigation
    void setInfo();
    void enterPage();
    void leavePage();

    //Sound
    void checkRun();
    void checkRPM();

    //Graphing
    void graphIV(QCustomPlot *IVPlot);
    void graphIVSlot();

    void graphEfficiency(QCustomPlot *efficiencyPlot);


    //Previous
    //void on_pushButton_updateTrafficData_clicked();
    //void on_pushButton_addDirectory_clicked();
    //void on_pushButton_addWebradio_clicked();
    //void on_pushButton_addMediaObjects_clicked();
    //void on_pushButton_loadTrack_clicked();

    //void init_ui_player(); //Not including player for now
    //void setMediaTable(QList< QMap<QString,QString> > mediaList);
    //void changePlayIcon(bool isPlaying);
    //QColor v2Color(qreal voltage, BatteryType);
    //void on_comboBox_language_currentIndexChanged(QString );
    //void init_ui_translation();

private:
    Ui::REV_HMI *ui;
    QSettings settings;
    QMap <QString,QString> languages;
    QThread* simuThread;
    engine_port eng;
    GPS gps;
    BMS bms;
    IOMODULE io;
    Logger logger;
    Media media;
    DebugLogger debugLogger;
    QString export_path;
    QShortcut* nextTab;
    QShortcut* prevTab;
    QShortcut* changePage;
    QShortcut* changeHome;
    QShortcut* playPause;
    QShortcut* nextTrack;
    QShortcut* prevTrack;
    QShortcut* volUp;
    QShortcut* volDown;
    QShortcut* mute;
    QTime night;
    QTime day;
    QTime midnight;
    int tabIndex;
    int prevtabIndex;
    bool onHome;
    bool isNight;
    bool soundOn;    
    int maxRange;

    float startCharge;

    void nightMode(bool);

    QList<int> currentList;
    QList<int> voltageList;
    QList<int> speedList;
    int efficiencyCount;
    int totalRecords;

    QTimer dataTimer;

#ifdef GETZ
    QProcess *gizmod;
#endif
    //Previous
    //traffic traf;
    //Player player;
    //QTranslator translator;
signals:
    void debugMsg(QtMsgType, QString, QString);
    void runEngSimu();
    void stopEngSimu();
    void nameChanged();
    void click();
    void setVol(int);
    void volChanged();
    void lowBatt();

};

#endif // REV_HMI_H
