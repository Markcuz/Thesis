/********************************************************************************
** Form generated from reading UI file 'lotus_hmi.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOTUS_HMI_H
#define UI_LOTUS_HMI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <mapwidget.h>
#include <qtransparentwidget.h>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_REV_HMI
{
public:
    QWidget *centralWidget;
    QWidget *menuButt;
    QHBoxLayout *menuButtons;
    QPushButton *logBut;
    QPushButton *tripBut;
    QPushButton *homeBut;
    QPushButton *battBut;
    QPushButton *musicBut;
    QPushButton *mapBut;
    QGraphicsView *uwaLogo;
    QGraphicsView *REVlogo;
    QWidget *log;
    QWidget *layoutWidget_3;
    QVBoxLayout *logLayout;
    QPushButton *pushButton_clear_errors;
    QCheckBox *checkBox_logGpsRaw;
    QCheckBox *checkBox_logBmsRaw;
    QPushButton *pushButton_Runsound;
    QSlider *horizontalSlider;
    QCheckBox *checkBox_GPSFile;
    QCheckBox *checkBox_BMSFile;
    QPushButton *pushButton_defaultSettings;
    QPushButton *pushButton_exit;
    QTextBrowser *textBrowser_errors;
    QCustomPlot *efficiencyPlot;
    QWidget *battInfo;
    QTableWidget *info_battTable;
    QWidget *music;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *musicLayout;
    QPushButton *pushButton_moveUp;
    QPushButton *pushButton_moveDown;
    QCheckBox *checkBox_repeatThis;
    QCheckBox *checkBox_repeatAll;
    QPushButton *pushButton_addDirectory;
    QSlider *volumeSlider;
    QTableWidget *tableWidget_mediaList;
    QLabel *musicDir;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_7;
    QToolButton *toolButton_mute;
    QToolButton *toolButton_prev;
    QToolButton *toolButton_play;
    QToolButton *toolButton_stop;
    QToolButton *toolButton_next;
    QSlider *seekSlider;
    QWidget *trip;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *tripButLayout;
    QLabel *editname_label;
    QTextEdit *editname;
    QLabel *label_7;
    QGridLayout *gridLayout_6;
    QPushButton *pushButton_stopRecording;
    QPushButton *pushButton_startRecording;
    QPushButton *pushButton_changeRange;
    QLabel *label_10;
    QLabel *l_trip_time;
    QLabel *label_4;
    QLabel *l_drive_time;
    QLabel *label_54;
    QGridLayout *gridLayout_7;
    QPushButton *pushButton_location;
    QPushButton *pushButton_export;
    QLabel *label_exportLocation;
    QWidget *gridLayoutWidget_2;
    QGridLayout *trip_stats_layout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *totalenergy_label;
    QLabel *energyUse;
    QLabel *label_2;
    QHBoxLayout *trip_hori1;
    QLabel *trip_slabel_dist;
    QLabel *l_trip_distance;
    QLabel *label_distkm;
    QHBoxLayout *horizontalLayout_2;
    QLabel *energyRem_label;
    QLabel *energyRem;
    QLabel *label_5;
    QHBoxLayout *trip_hori5;
    QLabel *label_accel;
    QLabel *l_trip_Accel60;
    QLabel *label_050s;
    QCustomPlot *IVPlot;
    QLabel *label_max;
    QLabel *label_avg;
    QFrame *line_3;
    QLabel *label_speedekmh;
    QLabel *l_trip_speedMax;
    QLabel *l_trip_speedAvgElapsed;
    QLabel *label_tripspeed;
    QLabel *label_driveA;
    QLabel *l_trip_ncurrentMax;
    QLabel *l_trip_ncurrentAvg;
    QLabel *label_current;
    QFrame *line;
    QFrame *line_2;
    QWidget *home;
    QWidget *warningIcons;
    QGridLayout *WarningIcons;
    QLabel *Handbrakeicon;
    QLabel *Neticon;
    QLabel *CELicon;
    QLabel *Dooricon;
    QLabel *SeatBelticon;
    QWidget *speed;
    QLabel *l_speed;
    QLabel *label_kmh;
    QLabel *l_time;
    QGraphicsView *graphicsView;
    QLabel *driver_name;
    QProgressBar *progressBar_battery;
    QWidget *layoutWidget1;
    QHBoxLayout *voltageText;
    QLabel *l_voltage;
    QLabel *labelVoltage;
    QProgressBar *progressBar_amps;
    QWidget *layoutWidget2;
    QHBoxLayout *currentText;
    QLabel *l_current;
    QLabel *label_A;
    QProgressBar *progressBar_ampsCharge;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_tripDist;
    QLabel *val_tripDist;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_tripTime;
    QLabel *val_tripTime;
    QLabel *label_6;
    QLabel *economy_label;
    QLabel *val_economy;
    QLabel *l_remdist;
    QLabel *label_KM;
    QWidget *horizontalWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *GPSicon;
    QLabel *TBSicon;
    QLabel *lowBatticon;
    QLabel *Fueldooricon;
    QLabel *Safetyswitchicon;
    QProgressBar *efficiencyBar;
    QLabel *label;
    QLabel *efficiencyLabel;
    QWidget *tempBlack;
    QWidget *map;
    MapWidget *mapWidget;
    QWidget *controls;
    QVBoxLayout *verticalLayout_4;
    QWidget *mapControls;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_zoomIn;
    QPushButton *pushButton_zoomOut;
    QCheckBox *checkBox_showComments;
    QCheckBox *checkBox_showTestTrack;
    QCheckBox *checkBox_autoFollow;
    QCheckBox *checkBox_showMyTrack;
    QCheckBox *checkBox_nightMode;
    QPushButton *pushButton_loadTrack;
    QPushButton *pushButton_deleteTrack;
    QPushButton *mapContHide;
    QWidget *battery;
    QTableWidget *tableWidget_cellValues;
    QTransparentWidget *transparentWidget;
    QLabel *l_cell_ave;
    QLabel *label_32;
    QLabel *label_33;
    QLabel *l_cell_max;
    QLabel *l_cell_min;
    QLabel *label_35;
    QLabel *label_36;
    QLabel *label_50;
    QLabel *label_56;
    QLabel *est_cap;
    QLabel *label_57;
    QPushButton *pushButton_NNreset;
    QWidget *layoutWidget_4;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_maxVoltage;
    QLabel *l_trip_voltageMax;
    QTableWidget *tableWidget_batteryCells_max;
    QSpacerItem *verticalSpacer_5;
    QLabel *label_17;
    QGridLayout *gridLayout_8;
    QLabel *l_max_bat;
    QLabel *l_max_volt;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_minVoltage;
    QLabel *l_trip_voltageMin;
    QTableWidget *tableWidget_batteryCells_min;
    QLabel *label_12;
    QGridLayout *gridLayout_2;
    QLabel *l_min_bat;
    QLabel *l_min_volt;
    QSpacerItem *verticalSpacer_12;
    QTransparentWidget *tripWidget1;
    QGridLayout *trip1;
    QLabel *label_18;
    QLabel *label_22;
    QLabel *label_14;
    QLabel *l_trip_ncurrentAvg_2;
    QLabel *label_21;
    QLabel *label_44;
    QLabel *l_trip_capacityPerKm;
    QLabel *label_34;
    QLabel *label_16;
    QLabel *l_trip_pcurrentAvg;
    QLabel *label_15;
    QLabel *label_25;
    QLabel *label_19;
    QLabel *l_trip_ncurrentMax_2;
    QLabel *label_8;
    QLabel *l_trip_pcurrentMax;
    QLabel *l_trip_capacityUsed;
    QLabel *l_trip_capacityRegenerated;
    QFrame *line_6;
    QLabel *label_43;
    QLabel *label_13;
    QLabel *label_9;
    QLabel *label_28;

    void setupUi(QMainWindow *REV_HMI)
    {
        if (REV_HMI->objectName().isEmpty())
            REV_HMI->setObjectName(QStringLiteral("REV_HMI"));
        REV_HMI->resize(1280, 720);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(REV_HMI->sizePolicy().hasHeightForWidth());
        REV_HMI->setSizePolicy(sizePolicy);
        REV_HMI->setMinimumSize(QSize(1280, 720));
        REV_HMI->setMaximumSize(QSize(1280, 720));
        QFont font;
        font.setFamily(QStringLiteral("Abadi MT Condensed Extra Bold"));
        font.setKerning(true);
        font.setStyleStrategy(QFont::PreferDefault);
        REV_HMI->setFont(font);
        REV_HMI->setFocusPolicy(Qt::ClickFocus);
        REV_HMI->setContextMenuPolicy(Qt::CustomContextMenu);
        REV_HMI->setWindowOpacity(1);
        REV_HMI->setStyleSheet(QLatin1String("\n"
"QProgressBar {\n"
"	background-color: rgba(255, 255, 255, 150);\n"
"    border: 2px solid grey;\n"
"    border-radius: 5px;\n"
"	text-align: center;\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"    border-radius: 3px;\n"
"    margin: 1.0px;\n"
"}\n"
"QProgressBar{\n"
"font: 75 20pt \"Latha\";\n"
"}\n"
"\n"
"\n"
""));
        centralWidget = new QWidget(REV_HMI);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMinimumSize(QSize(1280, 720));
        centralWidget->setMaximumSize(QSize(1280, 720));
        QPalette palette;
        QRadialGradient gradient(0.5, 0.5, 0.5, 0.5, 0.5);
        gradient.setSpread(QGradient::PadSpread);
        gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient.setColorAt(0, QColor(255, 255, 255, 255));
        gradient.setColorAt(1, QColor(0, 129, 9, 255));
        QBrush brush(gradient);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush1);
        QRadialGradient gradient1(0.5, 0.5, 0.5, 0.5, 0.5);
        gradient1.setSpread(QGradient::PadSpread);
        gradient1.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient1.setColorAt(0, QColor(255, 255, 255, 255));
        gradient1.setColorAt(1, QColor(0, 129, 9, 255));
        QBrush brush2(gradient1);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        QRadialGradient gradient2(0.5, 0.5, 0.5, 0.5, 0.5);
        gradient2.setSpread(QGradient::PadSpread);
        gradient2.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient2.setColorAt(0, QColor(255, 255, 255, 255));
        gradient2.setColorAt(1, QColor(0, 129, 9, 255));
        QBrush brush3(gradient2);
        palette.setBrush(QPalette::Active, QPalette::Window, brush3);
        QRadialGradient gradient3(0.5, 0.5, 0.5, 0.5, 0.5);
        gradient3.setSpread(QGradient::PadSpread);
        gradient3.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient3.setColorAt(0, QColor(255, 255, 255, 255));
        gradient3.setColorAt(1, QColor(0, 129, 9, 255));
        QBrush brush4(gradient3);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        QRadialGradient gradient4(0.5, 0.5, 0.5, 0.5, 0.5);
        gradient4.setSpread(QGradient::PadSpread);
        gradient4.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient4.setColorAt(0, QColor(255, 255, 255, 255));
        gradient4.setColorAt(1, QColor(0, 129, 9, 255));
        QBrush brush5(gradient4);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        QRadialGradient gradient5(0.5, 0.5, 0.5, 0.5, 0.5);
        gradient5.setSpread(QGradient::PadSpread);
        gradient5.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient5.setColorAt(0, QColor(255, 255, 255, 255));
        gradient5.setColorAt(1, QColor(0, 129, 9, 255));
        QBrush brush6(gradient5);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        QRadialGradient gradient6(0.5, 0.5, 0.5, 0.5, 0.5);
        gradient6.setSpread(QGradient::PadSpread);
        gradient6.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient6.setColorAt(0, QColor(255, 255, 255, 255));
        gradient6.setColorAt(1, QColor(0, 129, 9, 255));
        QBrush brush7(gradient6);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        QRadialGradient gradient7(0.5, 0.5, 0.5, 0.5, 0.5);
        gradient7.setSpread(QGradient::PadSpread);
        gradient7.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient7.setColorAt(0, QColor(255, 255, 255, 255));
        gradient7.setColorAt(1, QColor(0, 129, 9, 255));
        QBrush brush8(gradient7);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush8);
        QRadialGradient gradient8(0.5, 0.5, 0.5, 0.5, 0.5);
        gradient8.setSpread(QGradient::PadSpread);
        gradient8.setCoordinateMode(QGradient::ObjectBoundingMode);
        gradient8.setColorAt(0, QColor(255, 255, 255, 255));
        gradient8.setColorAt(1, QColor(0, 129, 9, 255));
        QBrush brush9(gradient8);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        centralWidget->setPalette(palette);
        QFont font1;
        font1.setFamily(QStringLiteral("Abadi MT Condensed Extra Bold"));
        centralWidget->setFont(font1);
        centralWidget->setStyleSheet(QLatin1String("#centralWidget{\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(0, 129, 9, 255));\n"
"}\n"
"\n"
"QToolButton{\n"
"color: rgb(0, 0, 0);\n"
"}\n"
"\n"
"QCheckBox {\n"
"color: rgb(0,0,0);\n"
"}"));
        menuButt = new QWidget(centralWidget);
        menuButt->setObjectName(QStringLiteral("menuButt"));
        menuButt->setGeometry(QRect(290, 590, 721, 131));
        menuButt->setFocusPolicy(Qt::NoFocus);
        menuButt->setContextMenuPolicy(Qt::DefaultContextMenu);
        menuButtons = new QHBoxLayout(menuButt);
        menuButtons->setObjectName(QStringLiteral("menuButtons"));
        logBut = new QPushButton(menuButt);
        logBut->setObjectName(QStringLiteral("logBut"));
        logBut->setMaximumSize(QSize(100, 100));
        logBut->setFocusPolicy(Qt::ClickFocus);
        logBut->setStyleSheet(QLatin1String("#logBut:focus{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"	border-image: url(:/images/logbw.png);\n"
"}\n"
"#logBut{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"	border-image: url(:/images/log.png);\n"
"}"));

        menuButtons->addWidget(logBut);

        tripBut = new QPushButton(menuButt);
        tripBut->setObjectName(QStringLiteral("tripBut"));
        tripBut->setMinimumSize(QSize(0, 0));
        tripBut->setMaximumSize(QSize(100, 100));
        tripBut->setFocusPolicy(Qt::ClickFocus);
        tripBut->setStyleSheet(QLatin1String("#tripBut:focus{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"	border-image: url(:/images/settingsbw.png);\n"
"}\n"
"#tripBut{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"	border-image: url(:/images/settings.png);\n"
"}"));

        menuButtons->addWidget(tripBut);

        homeBut = new QPushButton(menuButt);
        homeBut->setObjectName(QStringLiteral("homeBut"));
        homeBut->setMaximumSize(QSize(100, 100));
        homeBut->setFocusPolicy(Qt::ClickFocus);
        homeBut->setStyleSheet(QLatin1String("#homeBut:focus{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"	border-image: url(:/images/carbw.png);\n"
"}\n"
"#homeBut{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"	border-image: url(:/images/car.png);\n"
"}"));

        menuButtons->addWidget(homeBut);

        battBut = new QPushButton(menuButt);
        battBut->setObjectName(QStringLiteral("battBut"));
        battBut->setMaximumSize(QSize(100, 100));
        battBut->setFocusPolicy(Qt::ClickFocus);
        battBut->setStyleSheet(QLatin1String("#battBut:focus{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"	border-image: url(:/images/batterybw.png);\n"
"}\n"
"#battBut{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"	border-image: url(:/images/battry.png);\n"
"}\n"
""));

        menuButtons->addWidget(battBut);

        musicBut = new QPushButton(menuButt);
        musicBut->setObjectName(QStringLiteral("musicBut"));
        musicBut->setMaximumSize(QSize(100, 100));
        musicBut->setFocusPolicy(Qt::ClickFocus);
        musicBut->setStyleSheet(QLatin1String("#musicBut:focus{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"	border-image: url(:/images/musicbw.png);\n"
"}\n"
"#musicBut{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"	border-image: url(:/images/music.png);\n"
"}"));

        menuButtons->addWidget(musicBut);

        mapBut = new QPushButton(menuButt);
        mapBut->setObjectName(QStringLiteral("mapBut"));
        mapBut->setMaximumSize(QSize(100, 100));
        mapBut->setFocusPolicy(Qt::ClickFocus);
        mapBut->setStyleSheet(QLatin1String("#mapBut:focus{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"	border-image: url(:/images/mapbw.png);\n"
"}\n"
"#mapBut{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"	border-image: url(:/images/map.png);\n"
"}"));

        menuButtons->addWidget(mapBut);

        uwaLogo = new QGraphicsView(centralWidget);
        uwaLogo->setObjectName(QStringLiteral("uwaLogo"));
        uwaLogo->setEnabled(true);
        uwaLogo->setGeometry(QRect(40, 620, 231, 51));
        uwaLogo->setFocusPolicy(Qt::NoFocus);
        uwaLogo->setStyleSheet(QStringLiteral("border-image: url(:/images/UWA-logo.png);"));
        REVlogo = new QGraphicsView(centralWidget);
        REVlogo->setObjectName(QStringLiteral("REVlogo"));
        REVlogo->setEnabled(true);
        REVlogo->setGeometry(QRect(1000, 610, 261, 71));
        REVlogo->setFocusPolicy(Qt::NoFocus);
        REVlogo->setStyleSheet(QStringLiteral("border-image: url(:/images/logo.png);"));
        log = new QWidget(centralWidget);
        log->setObjectName(QStringLiteral("log"));
        log->setGeometry(QRect(0, 0, 1280, 600));
        log->setStyleSheet(QLatin1String("QPushButton:focus{\n"
"color: rgb(255, 0, 4);\n"
"}\n"
"QCheckBox:focus{\n"
"background-color: rgba(255, 0, 4, 50);\n"
"}"));
        layoutWidget_3 = new QWidget(log);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(950, 40, 291, 501));
        logLayout = new QVBoxLayout(layoutWidget_3);
        logLayout->setSpacing(3);
        logLayout->setObjectName(QStringLiteral("logLayout"));
        logLayout->setContentsMargins(10, 0, 10, 0);
        pushButton_clear_errors = new QPushButton(layoutWidget_3);
        pushButton_clear_errors->setObjectName(QStringLiteral("pushButton_clear_errors"));
        pushButton_clear_errors->setMaximumSize(QSize(16777215, 50));

        logLayout->addWidget(pushButton_clear_errors);

        checkBox_logGpsRaw = new QCheckBox(layoutWidget_3);
        checkBox_logGpsRaw->setObjectName(QStringLiteral("checkBox_logGpsRaw"));

        logLayout->addWidget(checkBox_logGpsRaw);

        checkBox_logBmsRaw = new QCheckBox(layoutWidget_3);
        checkBox_logBmsRaw->setObjectName(QStringLiteral("checkBox_logBmsRaw"));

        logLayout->addWidget(checkBox_logBmsRaw);

        pushButton_Runsound = new QPushButton(layoutWidget_3);
        pushButton_Runsound->setObjectName(QStringLiteral("pushButton_Runsound"));
        pushButton_Runsound->setMaximumSize(QSize(16777215, 50));

        logLayout->addWidget(pushButton_Runsound);

        horizontalSlider = new QSlider(layoutWidget_3);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(horizontalSlider->sizePolicy().hasHeightForWidth());
        horizontalSlider->setSizePolicy(sizePolicy1);
        horizontalSlider->setFocusPolicy(Qt::NoFocus);
        horizontalSlider->setMaximum(100);
        horizontalSlider->setValue(50);
        horizontalSlider->setSliderPosition(50);
        horizontalSlider->setOrientation(Qt::Horizontal);

        logLayout->addWidget(horizontalSlider);

        checkBox_GPSFile = new QCheckBox(layoutWidget_3);
        checkBox_GPSFile->setObjectName(QStringLiteral("checkBox_GPSFile"));

        logLayout->addWidget(checkBox_GPSFile);

        checkBox_BMSFile = new QCheckBox(layoutWidget_3);
        checkBox_BMSFile->setObjectName(QStringLiteral("checkBox_BMSFile"));

        logLayout->addWidget(checkBox_BMSFile);

        pushButton_defaultSettings = new QPushButton(layoutWidget_3);
        pushButton_defaultSettings->setObjectName(QStringLiteral("pushButton_defaultSettings"));
        pushButton_defaultSettings->setMaximumSize(QSize(16777215, 50));

        logLayout->addWidget(pushButton_defaultSettings);

        pushButton_exit = new QPushButton(layoutWidget_3);
        pushButton_exit->setObjectName(QStringLiteral("pushButton_exit"));
        pushButton_exit->setMaximumSize(QSize(16777215, 50));

        logLayout->addWidget(pushButton_exit);

        textBrowser_errors = new QTextBrowser(log);
        textBrowser_errors->setObjectName(QStringLiteral("textBrowser_errors"));
        textBrowser_errors->setGeometry(QRect(470, 30, 471, 521));
        textBrowser_errors->setFocusPolicy(Qt::NoFocus);
        textBrowser_errors->setStyleSheet(QLatin1String("font: 10pt \"Lucida Console\";\n"
"background-color: rgb(212, 212, 212);"));
        efficiencyPlot = new QCustomPlot(log);
        efficiencyPlot->setObjectName(QStringLiteral("efficiencyPlot"));
        efficiencyPlot->setGeometry(QRect(0, 30, 461, 251));
        efficiencyPlot->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        battInfo = new QWidget(log);
        battInfo->setObjectName(QStringLiteral("battInfo"));
        battInfo->setGeometry(QRect(60, 300, 301, 261));
        info_battTable = new QTableWidget(battInfo);
        if (info_battTable->columnCount() < 11)
            info_battTable->setColumnCount(11);
        if (info_battTable->rowCount() < 8)
            info_battTable->setRowCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        info_battTable->setItem(0, 0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        info_battTable->setItem(0, 1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        info_battTable->setItem(0, 2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        info_battTable->setItem(1, 1, __qtablewidgetitem3);
        info_battTable->setObjectName(QStringLiteral("info_battTable"));
        info_battTable->setEnabled(false);
        info_battTable->setGeometry(QRect(10, 0, 291, 261));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(100);
        sizePolicy2.setVerticalStretch(100);
        sizePolicy2.setHeightForWidth(info_battTable->sizePolicy().hasHeightForWidth());
        info_battTable->setSizePolicy(sizePolicy2);
        info_battTable->setFocusPolicy(Qt::NoFocus);
        info_battTable->setStyleSheet(QStringLiteral(""));
        info_battTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        info_battTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        info_battTable->setAutoScroll(false);
        info_battTable->setTabKeyNavigation(false);
        info_battTable->setSelectionMode(QAbstractItemView::NoSelection);
        info_battTable->setShowGrid(true);
        info_battTable->setRowCount(8);
        info_battTable->setColumnCount(11);
        info_battTable->horizontalHeader()->setVisible(false);
        info_battTable->horizontalHeader()->setDefaultSectionSize(12);
        info_battTable->horizontalHeader()->setHighlightSections(false);
        info_battTable->horizontalHeader()->setMinimumSectionSize(5);
        info_battTable->verticalHeader()->setVisible(false);
        info_battTable->verticalHeader()->setDefaultSectionSize(12);
        info_battTable->verticalHeader()->setMinimumSectionSize(5);
        music = new QWidget(centralWidget);
        music->setObjectName(QStringLiteral("music"));
        music->setGeometry(QRect(0, 0, 1280, 600));
        music->setStyleSheet(QLatin1String("QPushButton:focus{\n"
"color: rgb(255, 0, 4);\n"
"}\n"
"QCheckBox:focus{\n"
"background-color: rgba(255, 0, 4, 50);\n"
"}\n"
"QToolButton:focus{\n"
"background-color:rgba(255,0,4,50);\n"
"}"));
        layoutWidget = new QWidget(music);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 110, 1241, 441));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        musicLayout = new QVBoxLayout();
        musicLayout->setSpacing(0);
        musicLayout->setObjectName(QStringLiteral("musicLayout"));
        musicLayout->setContentsMargins(0, -1, -1, -1);
        pushButton_moveUp = new QPushButton(layoutWidget);
        pushButton_moveUp->setObjectName(QStringLiteral("pushButton_moveUp"));
        pushButton_moveUp->setMaximumSize(QSize(300, 50));

        musicLayout->addWidget(pushButton_moveUp);

        pushButton_moveDown = new QPushButton(layoutWidget);
        pushButton_moveDown->setObjectName(QStringLiteral("pushButton_moveDown"));
        pushButton_moveDown->setMaximumSize(QSize(300, 50));

        musicLayout->addWidget(pushButton_moveDown);

        checkBox_repeatThis = new QCheckBox(layoutWidget);
        checkBox_repeatThis->setObjectName(QStringLiteral("checkBox_repeatThis"));
        checkBox_repeatThis->setMaximumSize(QSize(300, 50));

        musicLayout->addWidget(checkBox_repeatThis);

        checkBox_repeatAll = new QCheckBox(layoutWidget);
        checkBox_repeatAll->setObjectName(QStringLiteral("checkBox_repeatAll"));
        checkBox_repeatAll->setMaximumSize(QSize(300, 50));

        musicLayout->addWidget(checkBox_repeatAll);

        pushButton_addDirectory = new QPushButton(layoutWidget);
        pushButton_addDirectory->setObjectName(QStringLiteral("pushButton_addDirectory"));
        pushButton_addDirectory->setMaximumSize(QSize(300, 50));

        musicLayout->addWidget(pushButton_addDirectory);


        gridLayout->addLayout(musicLayout, 0, 2, 1, 1);

        volumeSlider = new QSlider(layoutWidget);
        volumeSlider->setObjectName(QStringLiteral("volumeSlider"));
        volumeSlider->setFocusPolicy(Qt::NoFocus);
        volumeSlider->setValue(60);
        volumeSlider->setSliderPosition(60);
        volumeSlider->setOrientation(Qt::Vertical);

        gridLayout->addWidget(volumeSlider, 0, 0, 1, 1);

        tableWidget_mediaList = new QTableWidget(layoutWidget);
        if (tableWidget_mediaList->columnCount() < 3)
            tableWidget_mediaList->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_mediaList->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_mediaList->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_mediaList->setHorizontalHeaderItem(2, __qtablewidgetitem6);
        tableWidget_mediaList->setObjectName(QStringLiteral("tableWidget_mediaList"));
        tableWidget_mediaList->setEnabled(true);
        tableWidget_mediaList->setMinimumSize(QSize(800, 0));
        tableWidget_mediaList->setMaximumSize(QSize(500, 16777215));
        tableWidget_mediaList->setFocusPolicy(Qt::NoFocus);
        tableWidget_mediaList->setStyleSheet(QStringLiteral("font: 75 10pt \"Latha\";"));
        tableWidget_mediaList->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_mediaList->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget_mediaList->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_mediaList->setRowCount(0);
        tableWidget_mediaList->setColumnCount(3);
        tableWidget_mediaList->horizontalHeader()->setDefaultSectionSize(150);
        tableWidget_mediaList->horizontalHeader()->setMinimumSectionSize(150);
        tableWidget_mediaList->verticalHeader()->setMinimumSectionSize(30);

        gridLayout->addWidget(tableWidget_mediaList, 0, 1, 1, 1);

        musicDir = new QLabel(layoutWidget);
        musicDir->setObjectName(QStringLiteral("musicDir"));
        musicDir->setStyleSheet(QStringLiteral("font: 75 10pt \"Liberation serif\";"));

        gridLayout->addWidget(musicDir, 1, 1, 1, 1);

        layoutWidget_2 = new QWidget(music);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 10, 1241, 91));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        toolButton_mute = new QToolButton(layoutWidget_2);
        toolButton_mute->setObjectName(QStringLiteral("toolButton_mute"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(toolButton_mute->sizePolicy().hasHeightForWidth());
        toolButton_mute->setSizePolicy(sizePolicy3);
        toolButton_mute->setAutoRaise(true);

        horizontalLayout_7->addWidget(toolButton_mute);

        toolButton_prev = new QToolButton(layoutWidget_2);
        toolButton_prev->setObjectName(QStringLiteral("toolButton_prev"));
        sizePolicy3.setHeightForWidth(toolButton_prev->sizePolicy().hasHeightForWidth());
        toolButton_prev->setSizePolicy(sizePolicy3);
        toolButton_prev->setText(QStringLiteral("|<"));
        toolButton_prev->setAutoRaise(true);

        horizontalLayout_7->addWidget(toolButton_prev);

        toolButton_play = new QToolButton(layoutWidget_2);
        toolButton_play->setObjectName(QStringLiteral("toolButton_play"));
        sizePolicy3.setHeightForWidth(toolButton_play->sizePolicy().hasHeightForWidth());
        toolButton_play->setSizePolicy(sizePolicy3);
        toolButton_play->setText(QStringLiteral(">"));
        toolButton_play->setIconSize(QSize(40, 40));
        toolButton_play->setToolButtonStyle(Qt::ToolButtonIconOnly);
        toolButton_play->setAutoRaise(true);

        horizontalLayout_7->addWidget(toolButton_play);

        toolButton_stop = new QToolButton(layoutWidget_2);
        toolButton_stop->setObjectName(QStringLiteral("toolButton_stop"));
        sizePolicy3.setHeightForWidth(toolButton_stop->sizePolicy().hasHeightForWidth());
        toolButton_stop->setSizePolicy(sizePolicy3);
        toolButton_stop->setText(QStringLiteral("[]"));
        toolButton_stop->setAutoRaise(true);

        horizontalLayout_7->addWidget(toolButton_stop);

        toolButton_next = new QToolButton(layoutWidget_2);
        toolButton_next->setObjectName(QStringLiteral("toolButton_next"));
        sizePolicy3.setHeightForWidth(toolButton_next->sizePolicy().hasHeightForWidth());
        toolButton_next->setSizePolicy(sizePolicy3);
        toolButton_next->setText(QStringLiteral(">|"));
        toolButton_next->setAutoRaise(true);

        horizontalLayout_7->addWidget(toolButton_next);

        seekSlider = new QSlider(layoutWidget_2);
        seekSlider->setObjectName(QStringLiteral("seekSlider"));
        seekSlider->setFocusPolicy(Qt::NoFocus);
        seekSlider->setMaximum(1000);
        seekSlider->setOrientation(Qt::Horizontal);
        seekSlider->setTickPosition(QSlider::NoTicks);

        horizontalLayout_7->addWidget(seekSlider);

        trip = new QWidget(centralWidget);
        trip->setObjectName(QStringLiteral("trip"));
        trip->setGeometry(QRect(0, 0, 1280, 600));
        trip->setStyleSheet(QLatin1String("QPushButton:focus{\n"
"color: rgb(255, 0, 4);\n"
"}\n"
"QCheckBox:focus{\n"
"background-color: rgba(255, 0, 4, 50);\n"
"}"));
        verticalLayoutWidget = new QWidget(trip);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(1020, 10, 251, 591));
        tripButLayout = new QVBoxLayout(verticalLayoutWidget);
        tripButLayout->setObjectName(QStringLiteral("tripButLayout"));
        tripButLayout->setContentsMargins(0, 0, 0, 0);
        editname_label = new QLabel(verticalLayoutWidget);
        editname_label->setObjectName(QStringLiteral("editname_label"));
        editname_label->setStyleSheet(QStringLiteral("font: 75 30pt \"Lucida Console\";"));
        editname_label->setAlignment(Qt::AlignCenter);

        tripButLayout->addWidget(editname_label);

        editname = new QTextEdit(verticalLayoutWidget);
        editname->setObjectName(QStringLiteral("editname"));
        editname->setMaximumSize(QSize(16777215, 30));

        tripButLayout->addWidget(editname);

        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setStyleSheet(QStringLiteral("font: 75 30pt \"Lucida Console\";"));
        label_7->setAlignment(Qt::AlignCenter);

        tripButLayout->addWidget(label_7);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        pushButton_stopRecording = new QPushButton(verticalLayoutWidget);
        pushButton_stopRecording->setObjectName(QStringLiteral("pushButton_stopRecording"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(pushButton_stopRecording->sizePolicy().hasHeightForWidth());
        pushButton_stopRecording->setSizePolicy(sizePolicy4);
        pushButton_stopRecording->setMinimumSize(QSize(80, 25));
        pushButton_stopRecording->setMaximumSize(QSize(125, 50));

        gridLayout_6->addWidget(pushButton_stopRecording, 1, 1, 1, 1);

        pushButton_startRecording = new QPushButton(verticalLayoutWidget);
        pushButton_startRecording->setObjectName(QStringLiteral("pushButton_startRecording"));
        sizePolicy4.setHeightForWidth(pushButton_startRecording->sizePolicy().hasHeightForWidth());
        pushButton_startRecording->setSizePolicy(sizePolicy4);
        pushButton_startRecording->setMinimumSize(QSize(80, 50));
        pushButton_startRecording->setMaximumSize(QSize(125, 50));

        gridLayout_6->addWidget(pushButton_startRecording, 1, 0, 1, 1);


        tripButLayout->addLayout(gridLayout_6);

        pushButton_changeRange = new QPushButton(verticalLayoutWidget);
        pushButton_changeRange->setObjectName(QStringLiteral("pushButton_changeRange"));
        pushButton_changeRange->setMaximumSize(QSize(250, 50));

        tripButLayout->addWidget(pushButton_changeRange);

        label_10 = new QLabel(verticalLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        QFont font2;
        font2.setFamily(QStringLiteral("Lucida Console"));
        font2.setPointSize(30);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(9);
        label_10->setFont(font2);
        label_10->setStyleSheet(QStringLiteral("font: 75 30pt \"Lucida Console\";"));
        label_10->setAlignment(Qt::AlignCenter);

        tripButLayout->addWidget(label_10);

        l_trip_time = new QLabel(verticalLayoutWidget);
        l_trip_time->setObjectName(QStringLiteral("l_trip_time"));
        l_trip_time->setStyleSheet(QStringLiteral("font: 75 20pt \"Lucida Console\";"));
        l_trip_time->setText(QStringLiteral("00:00:00"));
        l_trip_time->setAlignment(Qt::AlignCenter);

        tripButLayout->addWidget(l_trip_time);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QStringLiteral("font: 75 30pt \"Lucida Console\";"));
        label_4->setAlignment(Qt::AlignCenter);

        tripButLayout->addWidget(label_4);

        l_drive_time = new QLabel(verticalLayoutWidget);
        l_drive_time->setObjectName(QStringLiteral("l_drive_time"));
        l_drive_time->setStyleSheet(QStringLiteral("font: 75 20pt \"Lucida Console\";"));
        l_drive_time->setText(QStringLiteral("00:00:00"));
        l_drive_time->setAlignment(Qt::AlignCenter);

        tripButLayout->addWidget(l_drive_time);

        label_54 = new QLabel(verticalLayoutWidget);
        label_54->setObjectName(QStringLiteral("label_54"));
        label_54->setStyleSheet(QStringLiteral("font: 75 30pt \"Lucida Console\";"));
        label_54->setAlignment(Qt::AlignCenter);

        tripButLayout->addWidget(label_54);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        pushButton_location = new QPushButton(verticalLayoutWidget);
        pushButton_location->setObjectName(QStringLiteral("pushButton_location"));
        sizePolicy.setHeightForWidth(pushButton_location->sizePolicy().hasHeightForWidth());
        pushButton_location->setSizePolicy(sizePolicy);
        pushButton_location->setMinimumSize(QSize(100, 50));
        pushButton_location->setMaximumSize(QSize(125, 100));

        gridLayout_7->addWidget(pushButton_location, 1, 0, 1, 1);

        pushButton_export = new QPushButton(verticalLayoutWidget);
        pushButton_export->setObjectName(QStringLiteral("pushButton_export"));
        pushButton_export->setMinimumSize(QSize(0, 25));
        pushButton_export->setMaximumSize(QSize(125, 50));

        gridLayout_7->addWidget(pushButton_export, 1, 1, 1, 1);


        tripButLayout->addLayout(gridLayout_7);

        label_exportLocation = new QLabel(verticalLayoutWidget);
        label_exportLocation->setObjectName(QStringLiteral("label_exportLocation"));
        label_exportLocation->setStyleSheet(QStringLiteral("font: 75 30pt \"Lucida Console\";"));
        label_exportLocation->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        tripButLayout->addWidget(label_exportLocation);

        gridLayoutWidget_2 = new QWidget(trip);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(480, 310, 541, 291));
        trip_stats_layout = new QGridLayout(gridLayoutWidget_2);
        trip_stats_layout->setObjectName(QStringLiteral("trip_stats_layout"));
        trip_stats_layout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        totalenergy_label = new QLabel(gridLayoutWidget_2);
        totalenergy_label->setObjectName(QStringLiteral("totalenergy_label"));
        totalenergy_label->setMinimumSize(QSize(400, 50));
        totalenergy_label->setMaximumSize(QSize(16777215, 50));
        totalenergy_label->setFont(font2);
        totalenergy_label->setStyleSheet(QStringLiteral("font: 75 30pt \"Lucida Console\";"));

        horizontalLayout_4->addWidget(totalenergy_label);

        energyUse = new QLabel(gridLayoutWidget_2);
        energyUse->setObjectName(QStringLiteral("energyUse"));
        energyUse->setStyleSheet(QStringLiteral("font: 75 30pt \"Lucida Console\";"));

        horizontalLayout_4->addWidget(energyUse);

        label_2 = new QLabel(gridLayoutWidget_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QStringLiteral("font: 75 30pt \"Lucida Console\";"));

        horizontalLayout_4->addWidget(label_2);


        trip_stats_layout->addLayout(horizontalLayout_4, 5, 0, 1, 1);

        trip_hori1 = new QHBoxLayout();
        trip_hori1->setObjectName(QStringLiteral("trip_hori1"));
        trip_slabel_dist = new QLabel(gridLayoutWidget_2);
        trip_slabel_dist->setObjectName(QStringLiteral("trip_slabel_dist"));
        trip_slabel_dist->setMinimumSize(QSize(0, 50));
        trip_slabel_dist->setMaximumSize(QSize(350, 50));
        trip_slabel_dist->setFont(font2);
        trip_slabel_dist->setStyleSheet(QStringLiteral("font: 75 30pt \"Lucida Console\";"));

        trip_hori1->addWidget(trip_slabel_dist);

        l_trip_distance = new QLabel(gridLayoutWidget_2);
        l_trip_distance->setObjectName(QStringLiteral("l_trip_distance"));
        l_trip_distance->setMinimumSize(QSize(75, 25));
        l_trip_distance->setMaximumSize(QSize(100, 100));
        l_trip_distance->setStyleSheet(QStringLiteral("font: 75 30pt \"Lucida Console\";"));
        l_trip_distance->setText(QStringLiteral("0.00"));
        l_trip_distance->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        trip_hori1->addWidget(l_trip_distance);

        label_distkm = new QLabel(gridLayoutWidget_2);
        label_distkm->setObjectName(QStringLiteral("label_distkm"));
        label_distkm->setMinimumSize(QSize(45, 25));
        label_distkm->setMaximumSize(QSize(60, 100));
        label_distkm->setLayoutDirection(Qt::LeftToRight);
        label_distkm->setStyleSheet(QStringLiteral("font: 75 30pt \"Lucida Console\";"));
        label_distkm->setText(QStringLiteral("km"));
        label_distkm->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        trip_hori1->addWidget(label_distkm);


        trip_stats_layout->addLayout(trip_hori1, 4, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        energyRem_label = new QLabel(gridLayoutWidget_2);
        energyRem_label->setObjectName(QStringLiteral("energyRem_label"));
        energyRem_label->setMinimumSize(QSize(400, 50));
        energyRem_label->setMaximumSize(QSize(0, 50));
        energyRem_label->setFont(font2);
        energyRem_label->setStyleSheet(QStringLiteral("font: 75 30pt \"Lucida Console\";"));
        energyRem_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(energyRem_label);

        energyRem = new QLabel(gridLayoutWidget_2);
        energyRem->setObjectName(QStringLiteral("energyRem"));
        energyRem->setStyleSheet(QStringLiteral("font: 75 30pt \"Lucida Console\";"));

        horizontalLayout_2->addWidget(energyRem);

        label_5 = new QLabel(gridLayoutWidget_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setStyleSheet(QStringLiteral("font: 75 30pt \"Lucida Console\";"));

        horizontalLayout_2->addWidget(label_5);


        trip_stats_layout->addLayout(horizontalLayout_2, 6, 0, 1, 1);

        trip_hori5 = new QHBoxLayout();
        trip_hori5->setObjectName(QStringLiteral("trip_hori5"));
        label_accel = new QLabel(gridLayoutWidget_2);
        label_accel->setObjectName(QStringLiteral("label_accel"));
        label_accel->setMinimumSize(QSize(100, 50));
        label_accel->setMaximumSize(QSize(400, 50));
        label_accel->setFont(font2);
        label_accel->setStyleSheet(QStringLiteral("font: 75 30pt \"Lucida Console\";"));

        trip_hori5->addWidget(label_accel);

        l_trip_Accel60 = new QLabel(gridLayoutWidget_2);
        l_trip_Accel60->setObjectName(QStringLiteral("l_trip_Accel60"));
        l_trip_Accel60->setMinimumSize(QSize(75, 25));
        l_trip_Accel60->setMaximumSize(QSize(75, 50));
        l_trip_Accel60->setStyleSheet(QStringLiteral("font: 75 30pt \"Lucida Console\";"));
        l_trip_Accel60->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        trip_hori5->addWidget(l_trip_Accel60);

        label_050s = new QLabel(gridLayoutWidget_2);
        label_050s->setObjectName(QStringLiteral("label_050s"));
        label_050s->setMinimumSize(QSize(40, 25));
        label_050s->setMaximumSize(QSize(45, 50));
        label_050s->setStyleSheet(QStringLiteral("font: 75 30pt \"Lucida Console\";"));

        trip_hori5->addWidget(label_050s);


        trip_stats_layout->addLayout(trip_hori5, 7, 0, 1, 1);

        IVPlot = new QCustomPlot(trip);
        IVPlot->setObjectName(QStringLiteral("IVPlot"));
        IVPlot->setGeometry(QRect(10, 10, 1001, 291));
        IVPlot->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        label_max = new QLabel(trip);
        label_max->setObjectName(QStringLiteral("label_max"));
        label_max->setGeometry(QRect(270, 310, 100, 86));
        label_max->setMinimumSize(QSize(75, 25));
        label_max->setMaximumSize(QSize(100, 100));
        label_max->setStyleSheet(QStringLiteral("font: 75 30pt \"Lucida Console\";"));
        label_max->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_max->setIndent(15);
        label_avg = new QLabel(trip);
        label_avg->setObjectName(QStringLiteral("label_avg"));
        label_avg->setGeometry(QRect(160, 310, 100, 86));
        label_avg->setMinimumSize(QSize(50, 25));
        label_avg->setMaximumSize(QSize(100, 100));
        label_avg->setStyleSheet(QStringLiteral("font: 75 30pt \"Lucida Console\";"));
        label_avg->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        line_3 = new QFrame(trip);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(0, 380, 479, 3));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        label_speedekmh = new QLabel(trip);
        label_speedekmh->setObjectName(QStringLiteral("label_speedekmh"));
        label_speedekmh->setGeometry(QRect(370, 400, 101, 71));
        sizePolicy.setHeightForWidth(label_speedekmh->sizePolicy().hasHeightForWidth());
        label_speedekmh->setSizePolicy(sizePolicy);
        label_speedekmh->setMinimumSize(QSize(45, 0));
        label_speedekmh->setMaximumSize(QSize(100000, 16777215));
        label_speedekmh->setStyleSheet(QStringLiteral("font: 75 30pt \"Lucida Console\";"));
        label_speedekmh->setAlignment(Qt::AlignCenter);
        l_trip_speedMax = new QLabel(trip);
        l_trip_speedMax->setObjectName(QStringLiteral("l_trip_speedMax"));
        l_trip_speedMax->setGeometry(QRect(290, 410, 75, 50));
        l_trip_speedMax->setMinimumSize(QSize(75, 25));
        l_trip_speedMax->setMaximumSize(QSize(75, 50));
        l_trip_speedMax->setStyleSheet(QStringLiteral("font: 75 30pt \"Lucida Console\";"));
        l_trip_speedMax->setText(QStringLiteral("0.00"));
        l_trip_speedMax->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        l_trip_speedAvgElapsed = new QLabel(trip);
        l_trip_speedAvgElapsed->setObjectName(QStringLiteral("l_trip_speedAvgElapsed"));
        l_trip_speedAvgElapsed->setGeometry(QRect(170, 410, 75, 50));
        l_trip_speedAvgElapsed->setMinimumSize(QSize(75, 25));
        l_trip_speedAvgElapsed->setMaximumSize(QSize(75, 50));
        l_trip_speedAvgElapsed->setStyleSheet(QStringLiteral("font: 75 30pt \"Lucida Console\";"));
        l_trip_speedAvgElapsed->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_tripspeed = new QLabel(trip);
        label_tripspeed->setObjectName(QStringLiteral("label_tripspeed"));
        label_tripspeed->setGeometry(QRect(10, 410, 220, 50));
        label_tripspeed->setMinimumSize(QSize(220, 50));
        label_tripspeed->setMaximumSize(QSize(220, 50));
        label_tripspeed->setStyleSheet(QStringLiteral("font: 75 30pt \"Lucida Console\";"));
        label_driveA = new QLabel(trip);
        label_driveA->setObjectName(QStringLiteral("label_driveA"));
        label_driveA->setGeometry(QRect(400, 500, 70, 50));
        label_driveA->setMinimumSize(QSize(45, 25));
        label_driveA->setMaximumSize(QSize(70, 50));
        label_driveA->setStyleSheet(QStringLiteral("font: 75 30pt \"Lucida Console\";"));
        l_trip_ncurrentMax = new QLabel(trip);
        l_trip_ncurrentMax->setObjectName(QStringLiteral("l_trip_ncurrentMax"));
        l_trip_ncurrentMax->setGeometry(QRect(290, 500, 75, 50));
        l_trip_ncurrentMax->setMinimumSize(QSize(75, 25));
        l_trip_ncurrentMax->setMaximumSize(QSize(75, 50));
        l_trip_ncurrentMax->setStyleSheet(QStringLiteral("font: 75 30pt \"Lucida Console\";"));
        l_trip_ncurrentMax->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        l_trip_ncurrentAvg = new QLabel(trip);
        l_trip_ncurrentAvg->setObjectName(QStringLiteral("l_trip_ncurrentAvg"));
        l_trip_ncurrentAvg->setGeometry(QRect(170, 500, 75, 50));
        l_trip_ncurrentAvg->setMinimumSize(QSize(75, 25));
        l_trip_ncurrentAvg->setMaximumSize(QSize(75, 50));
        l_trip_ncurrentAvg->setFont(font2);
        l_trip_ncurrentAvg->setStyleSheet(QStringLiteral("font: 75 30pt \"Lucida Console\";"));
        l_trip_ncurrentAvg->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_current = new QLabel(trip);
        label_current->setObjectName(QStringLiteral("label_current"));
        label_current->setGeometry(QRect(10, 500, 200, 50));
        label_current->setMinimumSize(QSize(200, 50));
        label_current->setMaximumSize(QSize(200, 50));
        label_current->setStyleSheet(QStringLiteral("font: 75 30pt \"Lucida Console\";"));
        label_current->setText(QStringLiteral("Current "));
        label_current->setIndent(-1);
        line = new QFrame(trip);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(470, 310, 20, 291));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(trip);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(1010, 10, 20, 591));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        gridLayoutWidget_2->raise();
        IVPlot->raise();
        verticalLayoutWidget->raise();
        label_max->raise();
        label_avg->raise();
        line_3->raise();
        label_speedekmh->raise();
        l_trip_speedMax->raise();
        l_trip_speedAvgElapsed->raise();
        label_tripspeed->raise();
        label_driveA->raise();
        l_trip_ncurrentMax->raise();
        l_trip_ncurrentAvg->raise();
        label_current->raise();
        line->raise();
        line_2->raise();
        home = new QWidget(centralWidget);
        home->setObjectName(QStringLiteral("home"));
        home->setEnabled(true);
        home->setGeometry(QRect(0, 0, 1280, 600));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(home->sizePolicy().hasHeightForWidth());
        home->setSizePolicy(sizePolicy5);
        home->setMinimumSize(QSize(1280, 600));
        home->setMaximumSize(QSize(16777215, 600));
        QPalette palette1;
        home->setPalette(palette1);
        home->setFocusPolicy(Qt::ClickFocus);
        home->setStyleSheet(QStringLiteral("font: 75 30pt \"Lucida Console\";"));
        warningIcons = new QWidget(home);
        warningIcons->setObjectName(QStringLiteral("warningIcons"));
        warningIcons->setGeometry(QRect(200, 20, 400, 100));
        warningIcons->setMaximumSize(QSize(900, 100));
        WarningIcons = new QGridLayout(warningIcons);
        WarningIcons->setObjectName(QStringLiteral("WarningIcons"));
        Handbrakeicon = new QLabel(warningIcons);
        Handbrakeicon->setObjectName(QStringLiteral("Handbrakeicon"));
        Handbrakeicon->setEnabled(true);
        sizePolicy.setHeightForWidth(Handbrakeicon->sizePolicy().hasHeightForWidth());
        Handbrakeicon->setSizePolicy(sizePolicy);
        Handbrakeicon->setMinimumSize(QSize(75, 75));
        Handbrakeicon->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/images/Handbrakeicon.png);"));

        WarningIcons->addWidget(Handbrakeicon, 5, 4, 1, 1);

        Neticon = new QLabel(warningIcons);
        Neticon->setObjectName(QStringLiteral("Neticon"));
        Neticon->setEnabled(true);
        sizePolicy.setHeightForWidth(Neticon->sizePolicy().hasHeightForWidth());
        Neticon->setSizePolicy(sizePolicy);
        Neticon->setMinimumSize(QSize(75, 75));
        Neticon->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/images/3Gicon.png);"));

        WarningIcons->addWidget(Neticon, 5, 7, 1, 1);

        CELicon = new QLabel(warningIcons);
        CELicon->setObjectName(QStringLiteral("CELicon"));
        CELicon->setEnabled(true);
        sizePolicy.setHeightForWidth(CELicon->sizePolicy().hasHeightForWidth());
        CELicon->setSizePolicy(sizePolicy);
        CELicon->setMinimumSize(QSize(75, 75));
        CELicon->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/images/CELicon.png);"));

        WarningIcons->addWidget(CELicon, 5, 6, 1, 1);

        Dooricon = new QLabel(warningIcons);
        Dooricon->setObjectName(QStringLiteral("Dooricon"));
        Dooricon->setEnabled(true);
        sizePolicy.setHeightForWidth(Dooricon->sizePolicy().hasHeightForWidth());
        Dooricon->setSizePolicy(sizePolicy);
        Dooricon->setMinimumSize(QSize(75, 75));
        Dooricon->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/images/Dooricon.png);"));

        WarningIcons->addWidget(Dooricon, 5, 2, 1, 1);

        SeatBelticon = new QLabel(warningIcons);
        SeatBelticon->setObjectName(QStringLiteral("SeatBelticon"));
        SeatBelticon->setEnabled(true);
        QSizePolicy sizePolicy6(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(50);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(SeatBelticon->sizePolicy().hasHeightForWidth());
        SeatBelticon->setSizePolicy(sizePolicy6);
        SeatBelticon->setMinimumSize(QSize(75, 75));
        SeatBelticon->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/images/Belticon.png);"));

        WarningIcons->addWidget(SeatBelticon, 5, 3, 1, 1);

        speed = new QWidget(home);
        speed->setObjectName(QStringLiteral("speed"));
        speed->setEnabled(true);
        speed->setGeometry(QRect(480, 270, 311, 231));
        speed->setMinimumSize(QSize(150, 0));
        speed->setFont(font2);
        speed->setFocusPolicy(Qt::NoFocus);
        speed->setStyleSheet(QStringLiteral(""));
        l_speed = new QLabel(speed);
        l_speed->setObjectName(QStringLiteral("l_speed"));
        l_speed->setGeometry(QRect(70, 70, 191, 91));
        l_speed->setMinimumSize(QSize(150, 30));
        l_speed->setMaximumSize(QSize(2000, 2000));
        QFont font3;
        font3.setFamily(QStringLiteral("Lucida Console"));
        font3.setPointSize(60);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(9);
        l_speed->setFont(font3);
        l_speed->setStyleSheet(QStringLiteral("font: 75 60pt \"Lucida Console\";"));
        l_speed->setText(QStringLiteral("--"));
        l_speed->setAlignment(Qt::AlignCenter);
        label_kmh = new QLabel(speed);
        label_kmh->setObjectName(QStringLiteral("label_kmh"));
        label_kmh->setGeometry(QRect(60, 180, 200, 18));
        label_kmh->setMaximumSize(QSize(200, 100));
        label_kmh->setStyleSheet(QStringLiteral("font: 75 20pt \"Lucida Console\";"));
        label_kmh->setAlignment(Qt::AlignCenter);
        l_time = new QLabel(home);
        l_time->setObjectName(QStringLiteral("l_time"));
        l_time->setGeometry(QRect(1090, 60, 150, 25));
        l_time->setMinimumSize(QSize(150, 25));
        l_time->setMaximumSize(QSize(150, 25));
        QFont font4;
        font4.setFamily(QStringLiteral("Liberation serif"));
        font4.setPointSize(15);
        font4.setBold(true);
        font4.setItalic(false);
        font4.setWeight(75);
        l_time->setFont(font4);
        l_time->setStyleSheet(QLatin1String("font: 75 15pt \"Liberation serif\";\n"
"font-weight:bold;"));
        l_time->setText(QStringLiteral("--:--:--"));
        l_time->setAlignment(Qt::AlignCenter);
        graphicsView = new QGraphicsView(home);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(550, 90, 181, 191));
        graphicsView->setFocusPolicy(Qt::NoFocus);
        graphicsView->setStyleSheet(QStringLiteral("border-image: url(:/images/REV-logo---round.png);"));
        driver_name = new QLabel(home);
        driver_name->setObjectName(QStringLiteral("driver_name"));
        driver_name->setGeometry(QRect(40, 40, 211, 71));
        driver_name->setStyleSheet(QStringLiteral("font: 75 15pt \"Lucida Console\";"));
        progressBar_battery = new QProgressBar(home);
        progressBar_battery->setObjectName(QStringLiteral("progressBar_battery"));
        progressBar_battery->setEnabled(true);
        progressBar_battery->setGeometry(QRect(50, 200, 120, 400));
        sizePolicy.setHeightForWidth(progressBar_battery->sizePolicy().hasHeightForWidth());
        progressBar_battery->setSizePolicy(sizePolicy);
        progressBar_battery->setMinimumSize(QSize(0, 200));
        progressBar_battery->setMaximumSize(QSize(200, 400));
        progressBar_battery->setFont(font2);
        progressBar_battery->setAutoFillBackground(false);
        progressBar_battery->setStyleSheet(QLatin1String("QProgressBar::chunk {\n"
"	background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(0, 200, 0), stop:1 rgb(90, 255,80));\n"
"}"));
        progressBar_battery->setMaximum(100);
        progressBar_battery->setValue(90);
        progressBar_battery->setAlignment(Qt::AlignCenter);
        progressBar_battery->setTextVisible(true);
        progressBar_battery->setOrientation(Qt::Vertical);
        progressBar_battery->setInvertedAppearance(false);
        progressBar_battery->setFormat(QStringLiteral("%p%"));
        layoutWidget1 = new QWidget(home);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(50, 140, 121, 51));
        voltageText = new QHBoxLayout(layoutWidget1);
        voltageText->setObjectName(QStringLiteral("voltageText"));
        voltageText->setContentsMargins(0, 0, 0, 0);
        l_voltage = new QLabel(layoutWidget1);
        l_voltage->setObjectName(QStringLiteral("l_voltage"));
        l_voltage->setMinimumSize(QSize(0, 0));
        l_voltage->setMaximumSize(QSize(400, 200));
        l_voltage->setFont(font2);
        l_voltage->setStyleSheet(QStringLiteral("font: 75 30pt \"Lucida Console\";"));
        l_voltage->setText(QStringLiteral("0"));
        l_voltage->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        l_voltage->setWordWrap(true);

        voltageText->addWidget(l_voltage);

        labelVoltage = new QLabel(layoutWidget1);
        labelVoltage->setObjectName(QStringLiteral("labelVoltage"));
        labelVoltage->setMinimumSize(QSize(0, 0));
        labelVoltage->setMaximumSize(QSize(300, 200));
        labelVoltage->setFont(font2);
        labelVoltage->setStyleSheet(QStringLiteral("font: 75 30pt \"Lucida Console\";"));
        labelVoltage->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        labelVoltage->setWordWrap(true);

        voltageText->addWidget(labelVoltage);

        progressBar_amps = new QProgressBar(home);
        progressBar_amps->setObjectName(QStringLiteral("progressBar_amps"));
        progressBar_amps->setGeometry(QRect(1110, 200, 120, 300));
        sizePolicy5.setHeightForWidth(progressBar_amps->sizePolicy().hasHeightForWidth());
        progressBar_amps->setSizePolicy(sizePolicy5);
        progressBar_amps->setMinimumSize(QSize(0, 0));
        progressBar_amps->setMaximumSize(QSize(200, 600));
        progressBar_amps->setAutoFillBackground(false);
        progressBar_amps->setStyleSheet(QLatin1String("QProgressBar:verticall {\n"
"border: 1px solid gray;\n"
"border-radius: 3px;\n"
"background: white;\n"
"padding: 1px;\n"
"text-align: right;\n"
"}\n"
"QProgressBar::chunk:vertical {\n"
"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #00AA00, stop: 1 #66FF66);\n"
"margin-top: 2px; /* space */\n"
"height: 10px;\n"
"}"));
        progressBar_amps->setValue(50);
        progressBar_amps->setAlignment(Qt::AlignCenter);
        progressBar_amps->setTextVisible(false);
        progressBar_amps->setOrientation(Qt::Vertical);
        progressBar_amps->setInvertedAppearance(false);
        progressBar_amps->setTextDirection(QProgressBar::TopToBottom);
        layoutWidget2 = new QWidget(home);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(1100, 140, 131, 51));
        currentText = new QHBoxLayout(layoutWidget2);
        currentText->setObjectName(QStringLiteral("currentText"));
        currentText->setContentsMargins(0, 0, 0, 0);
        l_current = new QLabel(layoutWidget2);
        l_current->setObjectName(QStringLiteral("l_current"));
        l_current->setMinimumSize(QSize(0, 0));
        l_current->setMaximumSize(QSize(1000, 100));
        l_current->setFont(font2);
        l_current->setStyleSheet(QStringLiteral("font: 75 30pt \"Lucida Console\";"));
        l_current->setText(QStringLiteral("0"));
        l_current->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        currentText->addWidget(l_current);

        label_A = new QLabel(layoutWidget2);
        label_A->setObjectName(QStringLiteral("label_A"));
        label_A->setMinimumSize(QSize(0, 0));
        label_A->setMaximumSize(QSize(100, 100));
        label_A->setStyleSheet(QStringLiteral("font: 75 30pt \"Lucida Console\";"));
        label_A->setText(QStringLiteral("A"));
        label_A->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        currentText->addWidget(label_A);

        progressBar_ampsCharge = new QProgressBar(home);
        progressBar_ampsCharge->setObjectName(QStringLiteral("progressBar_ampsCharge"));
        progressBar_ampsCharge->setGeometry(QRect(1110, 500, 120, 100));
        sizePolicy5.setHeightForWidth(progressBar_ampsCharge->sizePolicy().hasHeightForWidth());
        progressBar_ampsCharge->setSizePolicy(sizePolicy5);
        progressBar_ampsCharge->setMinimumSize(QSize(0, 0));
        progressBar_ampsCharge->setMaximumSize(QSize(200, 600));
        progressBar_ampsCharge->setAutoFillBackground(false);
        progressBar_ampsCharge->setStyleSheet(QLatin1String("QProgressBar:verticall {\n"
"border: 1px solid gray;\n"
"border-radius: 3px;\n"
"background: white;\n"
"padding: 1px;\n"
"text-align: right;\n"
"}\n"
"QProgressBar::chunk:vertical {\n"
"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #00AA00, stop: 1 #66FF66);\n"
"margin-top: 2px; /* space */\n"
"height: 10px;\n"
"}"));
        progressBar_ampsCharge->setValue(0);
        progressBar_ampsCharge->setAlignment(Qt::AlignCenter);
        progressBar_ampsCharge->setTextVisible(false);
        progressBar_ampsCharge->setOrientation(Qt::Vertical);
        progressBar_ampsCharge->setInvertedAppearance(true);
        progressBar_ampsCharge->setTextDirection(QProgressBar::TopToBottom);
        horizontalLayoutWidget_2 = new QWidget(home);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(190, 200, 271, 80));
        horizontalLayout_9 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        label_tripDist = new QLabel(horizontalLayoutWidget_2);
        label_tripDist->setObjectName(QStringLiteral("label_tripDist"));
        label_tripDist->setStyleSheet(QStringLiteral("font: 75 20pt \"Lucida Console\";"));

        horizontalLayout_9->addWidget(label_tripDist);

        val_tripDist = new QLabel(horizontalLayoutWidget_2);
        val_tripDist->setObjectName(QStringLiteral("val_tripDist"));
        QFont font5;
        font5.setFamily(QStringLiteral("Lucida Console"));
        font5.setPointSize(20);
        font5.setBold(false);
        font5.setItalic(false);
        font5.setWeight(9);
        val_tripDist->setFont(font5);
        val_tripDist->setStyleSheet(QStringLiteral("font: 75 20pt \"Lucida Console\";"));

        horizontalLayout_9->addWidget(val_tripDist);

        horizontalLayoutWidget_3 = new QWidget(home);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(860, 210, 251, 80));
        horizontalLayout_10 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        label_tripTime = new QLabel(horizontalLayoutWidget_3);
        label_tripTime->setObjectName(QStringLiteral("label_tripTime"));
        label_tripTime->setStyleSheet(QStringLiteral("font: 75 20pt \"Lucida Console\";"));

        horizontalLayout_10->addWidget(label_tripTime);

        val_tripTime = new QLabel(horizontalLayoutWidget_3);
        val_tripTime->setObjectName(QStringLiteral("val_tripTime"));
        val_tripTime->setStyleSheet(QStringLiteral("font: 75 20pt \"Lucida Console\";"));

        horizontalLayout_10->addWidget(val_tripTime);

        label_6 = new QLabel(home);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(190, 320, 241, 31));
        label_6->setStyleSheet(QLatin1String("font: 75 20pt \"Lucida Console\";\n"
""));
        economy_label = new QLabel(home);
        economy_label->setObjectName(QStringLiteral("economy_label"));
        economy_label->setGeometry(QRect(950, 320, 141, 31));
        economy_label->setStyleSheet(QStringLiteral("font: 75 20pt \"Lucida Console\";"));
        economy_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        val_economy = new QLabel(home);
        val_economy->setObjectName(QStringLiteral("val_economy"));
        val_economy->setGeometry(QRect(770, 350, 321, 111));
        val_economy->setStyleSheet(QStringLiteral("font: 75 30pt \"Lucida Console\";"));
        val_economy->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        l_remdist = new QLabel(home);
        l_remdist->setObjectName(QStringLiteral("l_remdist"));
        l_remdist->setGeometry(QRect(190, 360, 61, 78));
        l_remdist->setMinimumSize(QSize(0, 0));
        l_remdist->setMaximumSize(QSize(200, 200));
        l_remdist->setFont(font2);
        l_remdist->setStyleSheet(QStringLiteral("font: 75 30pt \"Lucida Console\";"));
        l_remdist->setText(QStringLiteral("0"));
        l_remdist->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_KM = new QLabel(home);
        label_KM->setObjectName(QStringLiteral("label_KM"));
        label_KM->setGeometry(QRect(230, 360, 100, 78));
        label_KM->setMinimumSize(QSize(0, 30));
        label_KM->setMaximumSize(QSize(100, 100));
        label_KM->setFont(font2);
        label_KM->setStyleSheet(QStringLiteral("font: 75 30pt \"Lucida Console\";"));
        label_KM->setAlignment(Qt::AlignCenter);
        horizontalWidget = new QWidget(home);
        horizontalWidget->setObjectName(QStringLiteral("horizontalWidget"));
        horizontalWidget->setGeometry(QRect(680, 30, 400, 80));
        horizontalLayout = new QHBoxLayout(horizontalWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        GPSicon = new QLabel(horizontalWidget);
        GPSicon->setObjectName(QStringLiteral("GPSicon"));
        GPSicon->setEnabled(true);
        sizePolicy.setHeightForWidth(GPSicon->sizePolicy().hasHeightForWidth());
        GPSicon->setSizePolicy(sizePolicy);
        GPSicon->setMinimumSize(QSize(75, 75));
        GPSicon->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/images/GPSicon.png);"));

        horizontalLayout->addWidget(GPSicon);

        TBSicon = new QLabel(horizontalWidget);
        TBSicon->setObjectName(QStringLiteral("TBSicon"));
        TBSicon->setEnabled(true);
        sizePolicy.setHeightForWidth(TBSicon->sizePolicy().hasHeightForWidth());
        TBSicon->setSizePolicy(sizePolicy);
        TBSicon->setMinimumSize(QSize(75, 75));
        TBSicon->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/images/TBSicon.png);"));

        horizontalLayout->addWidget(TBSicon);

        lowBatticon = new QLabel(horizontalWidget);
        lowBatticon->setObjectName(QStringLiteral("lowBatticon"));
        lowBatticon->setEnabled(true);
        QSizePolicy sizePolicy7(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(50);
        sizePolicy7.setVerticalStretch(50);
        sizePolicy7.setHeightForWidth(lowBatticon->sizePolicy().hasHeightForWidth());
        lowBatticon->setSizePolicy(sizePolicy7);
        lowBatticon->setMinimumSize(QSize(75, 75));
        lowBatticon->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/images/Lowbatticon.png);"));

        horizontalLayout->addWidget(lowBatticon);

        Fueldooricon = new QLabel(horizontalWidget);
        Fueldooricon->setObjectName(QStringLiteral("Fueldooricon"));
        Fueldooricon->setEnabled(true);
        sizePolicy.setHeightForWidth(Fueldooricon->sizePolicy().hasHeightForWidth());
        Fueldooricon->setSizePolicy(sizePolicy);
        Fueldooricon->setMinimumSize(QSize(75, 75));
        Fueldooricon->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/images/Fueldooricon.png);"));

        horizontalLayout->addWidget(Fueldooricon);

        Safetyswitchicon = new QLabel(horizontalWidget);
        Safetyswitchicon->setObjectName(QStringLiteral("Safetyswitchicon"));
        Safetyswitchicon->setEnabled(true);
        sizePolicy.setHeightForWidth(Safetyswitchicon->sizePolicy().hasHeightForWidth());
        Safetyswitchicon->setSizePolicy(sizePolicy);
        Safetyswitchicon->setMinimumSize(QSize(75, 75));
        Safetyswitchicon->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/images/Safetyswitchicon.png);"));

        horizontalLayout->addWidget(Safetyswitchicon);

        efficiencyBar = new QProgressBar(home);
        efficiencyBar->setObjectName(QStringLiteral("efficiencyBar"));
        efficiencyBar->setGeometry(QRect(440, 550, 411, 51));
        efficiencyBar->setValue(50);
        efficiencyBar->setTextVisible(false);
        label = new QLabel(home);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(520, 510, 141, 41));
        label->setStyleSheet(QStringLiteral("font: 75 20pt \"Lucida Console\";"));
        efficiencyLabel = new QLabel(home);
        efficiencyLabel->setObjectName(QStringLiteral("efficiencyLabel"));
        efficiencyLabel->setGeometry(QRect(690, 510, 141, 31));
        efficiencyLabel->setStyleSheet(QStringLiteral("font: 75 20pt \"Lucida Console\";"));
        tempBlack = new QWidget(centralWidget);
        tempBlack->setObjectName(QStringLiteral("tempBlack"));
        tempBlack->setEnabled(true);
        tempBlack->setGeometry(QRect(0, 0, 1281, 711));
        tempBlack->setFocusPolicy(Qt::NoFocus);
        tempBlack->setStyleSheet(QLatin1String("\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(0, 129, 9, 255));\n"
""));
        map = new QWidget(centralWidget);
        map->setObjectName(QStringLiteral("map"));
        map->setGeometry(QRect(0, 0, 1280, 600));
        mapWidget = new MapWidget(map);
        mapWidget->setObjectName(QStringLiteral("mapWidget"));
        mapWidget->setGeometry(QRect(0, 0, 1280, 600));
        controls = new QWidget(mapWidget);
        controls->setObjectName(QStringLiteral("controls"));
        controls->setGeometry(QRect(860, 30, 351, 521));
        verticalLayout_4 = new QVBoxLayout(controls);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        mapControls = new QWidget(controls);
        mapControls->setObjectName(QStringLiteral("mapControls"));
        mapControls->setStyleSheet(QStringLiteral(""));
        verticalLayout_3 = new QVBoxLayout(mapControls);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, -1, 25, -1);
        pushButton_zoomIn = new QPushButton(mapControls);
        pushButton_zoomIn->setObjectName(QStringLiteral("pushButton_zoomIn"));
        sizePolicy5.setHeightForWidth(pushButton_zoomIn->sizePolicy().hasHeightForWidth());
        pushButton_zoomIn->setSizePolicy(sizePolicy5);
        pushButton_zoomIn->setMinimumSize(QSize(165, 25));
        pushButton_zoomIn->setMaximumSize(QSize(10000, 50));
        QFont font6;
        font6.setFamily(QStringLiteral("Latha"));
        font6.setPointSize(12);
        font6.setBold(false);
        font6.setItalic(false);
        font6.setWeight(50);
        pushButton_zoomIn->setFont(font6);
        pushButton_zoomIn->setStyleSheet(QStringLiteral(""));

        verticalLayout_3->addWidget(pushButton_zoomIn);

        pushButton_zoomOut = new QPushButton(mapControls);
        pushButton_zoomOut->setObjectName(QStringLiteral("pushButton_zoomOut"));
        sizePolicy4.setHeightForWidth(pushButton_zoomOut->sizePolicy().hasHeightForWidth());
        pushButton_zoomOut->setSizePolicy(sizePolicy4);
        pushButton_zoomOut->setMinimumSize(QSize(165, 25));
        pushButton_zoomOut->setMaximumSize(QSize(1000, 50));
        pushButton_zoomOut->setStyleSheet(QStringLiteral(""));

        verticalLayout_3->addWidget(pushButton_zoomOut);

        checkBox_showComments = new QCheckBox(mapControls);
        checkBox_showComments->setObjectName(QStringLiteral("checkBox_showComments"));
        sizePolicy5.setHeightForWidth(checkBox_showComments->sizePolicy().hasHeightForWidth());
        checkBox_showComments->setSizePolicy(sizePolicy5);
        checkBox_showComments->setMinimumSize(QSize(165, 15));
        checkBox_showComments->setMaximumSize(QSize(165, 30));

        verticalLayout_3->addWidget(checkBox_showComments);

        checkBox_showTestTrack = new QCheckBox(mapControls);
        checkBox_showTestTrack->setObjectName(QStringLiteral("checkBox_showTestTrack"));
        sizePolicy5.setHeightForWidth(checkBox_showTestTrack->sizePolicy().hasHeightForWidth());
        checkBox_showTestTrack->setSizePolicy(sizePolicy5);
        checkBox_showTestTrack->setMinimumSize(QSize(165, 15));
        checkBox_showTestTrack->setMaximumSize(QSize(165, 30));

        verticalLayout_3->addWidget(checkBox_showTestTrack);

        checkBox_autoFollow = new QCheckBox(mapControls);
        checkBox_autoFollow->setObjectName(QStringLiteral("checkBox_autoFollow"));
        sizePolicy5.setHeightForWidth(checkBox_autoFollow->sizePolicy().hasHeightForWidth());
        checkBox_autoFollow->setSizePolicy(sizePolicy5);
        checkBox_autoFollow->setMinimumSize(QSize(165, 15));
        checkBox_autoFollow->setMaximumSize(QSize(165, 30));
        checkBox_autoFollow->setStyleSheet(QStringLiteral(""));
        checkBox_autoFollow->setChecked(true);

        verticalLayout_3->addWidget(checkBox_autoFollow);

        checkBox_showMyTrack = new QCheckBox(mapControls);
        checkBox_showMyTrack->setObjectName(QStringLiteral("checkBox_showMyTrack"));
        sizePolicy5.setHeightForWidth(checkBox_showMyTrack->sizePolicy().hasHeightForWidth());
        checkBox_showMyTrack->setSizePolicy(sizePolicy5);
        checkBox_showMyTrack->setMinimumSize(QSize(165, 15));
        checkBox_showMyTrack->setMaximumSize(QSize(165, 30));
        checkBox_showMyTrack->setChecked(true);

        verticalLayout_3->addWidget(checkBox_showMyTrack);

        checkBox_nightMode = new QCheckBox(mapControls);
        checkBox_nightMode->setObjectName(QStringLiteral("checkBox_nightMode"));
        sizePolicy5.setHeightForWidth(checkBox_nightMode->sizePolicy().hasHeightForWidth());
        checkBox_nightMode->setSizePolicy(sizePolicy5);
        checkBox_nightMode->setMinimumSize(QSize(165, 15));
        checkBox_nightMode->setMaximumSize(QSize(165, 30));
        checkBox_nightMode->setStyleSheet(QStringLiteral(""));

        verticalLayout_3->addWidget(checkBox_nightMode);

        pushButton_loadTrack = new QPushButton(mapControls);
        pushButton_loadTrack->setObjectName(QStringLiteral("pushButton_loadTrack"));
        sizePolicy5.setHeightForWidth(pushButton_loadTrack->sizePolicy().hasHeightForWidth());
        pushButton_loadTrack->setSizePolicy(sizePolicy5);
        pushButton_loadTrack->setMinimumSize(QSize(165, 25));
        pushButton_loadTrack->setMaximumSize(QSize(500, 50));

        verticalLayout_3->addWidget(pushButton_loadTrack);

        pushButton_deleteTrack = new QPushButton(mapControls);
        pushButton_deleteTrack->setObjectName(QStringLiteral("pushButton_deleteTrack"));
        pushButton_deleteTrack->setMaximumSize(QSize(500, 50));

        verticalLayout_3->addWidget(pushButton_deleteTrack);

        pushButton_zoomIn->raise();
        pushButton_zoomOut->raise();
        checkBox_showComments->raise();
        checkBox_showTestTrack->raise();
        checkBox_autoFollow->raise();
        checkBox_nightMode->raise();
        pushButton_loadTrack->raise();
        pushButton_deleteTrack->raise();
        checkBox_showMyTrack->raise();

        verticalLayout_4->addWidget(mapControls);

        mapContHide = new QPushButton(controls);
        mapContHide->setObjectName(QStringLiteral("mapContHide"));
        mapContHide->setMaximumSize(QSize(300, 50));
        mapContHide->setLayoutDirection(Qt::LeftToRight);

        verticalLayout_4->addWidget(mapContHide);

        battery = new QWidget(centralWidget);
        battery->setObjectName(QStringLiteral("battery"));
        battery->setEnabled(false);
        battery->setGeometry(QRect(0, 0, 1280, 600));
        sizePolicy.setHeightForWidth(battery->sizePolicy().hasHeightForWidth());
        battery->setSizePolicy(sizePolicy);
        battery->setStyleSheet(QLatin1String("QPushButton:focus{\n"
"color: rgb(255, 0, 4);\n"
"}\n"
"QCheckBox:focus{\n"
"background-color: rgba(255, 0, 4, 50);\n"
"}"));
        tableWidget_cellValues = new QTableWidget(battery);
        if (tableWidget_cellValues->columnCount() < 11)
            tableWidget_cellValues->setColumnCount(11);
        if (tableWidget_cellValues->rowCount() < 8)
            tableWidget_cellValues->setRowCount(8);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidget_cellValues->setItem(0, 0, __qtablewidgetitem7);
        tableWidget_cellValues->setObjectName(QStringLiteral("tableWidget_cellValues"));
        tableWidget_cellValues->setGeometry(QRect(10, 10, 681, 411));
        QSizePolicy sizePolicy8(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy8.setHorizontalStretch(100);
        sizePolicy8.setVerticalStretch(100);
        sizePolicy8.setHeightForWidth(tableWidget_cellValues->sizePolicy().hasHeightForWidth());
        tableWidget_cellValues->setSizePolicy(sizePolicy8);
        tableWidget_cellValues->setSizeIncrement(QSize(1, 1));
        QFont font7;
        font7.setFamily(QStringLiteral("Lucida Console"));
        font7.setPointSize(11);
        font7.setBold(true);
        font7.setItalic(false);
        font7.setWeight(75);
        tableWidget_cellValues->setFont(font7);
        tableWidget_cellValues->setFocusPolicy(Qt::NoFocus);
        tableWidget_cellValues->setStyleSheet(QLatin1String("font: 75 11pt \"Lucida Console\";\n"
"font-weight: bold;\n"
"text-align: center;"));
        tableWidget_cellValues->setMidLineWidth(0);
        tableWidget_cellValues->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_cellValues->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_cellValues->setTabKeyNavigation(false);
        tableWidget_cellValues->setSelectionMode(QAbstractItemView::NoSelection);
        tableWidget_cellValues->setIconSize(QSize(20, 20));
        tableWidget_cellValues->setShowGrid(true);
        tableWidget_cellValues->setCornerButtonEnabled(false);
        tableWidget_cellValues->setRowCount(8);
        tableWidget_cellValues->setColumnCount(11);
        tableWidget_cellValues->horizontalHeader()->setVisible(false);
        tableWidget_cellValues->horizontalHeader()->setDefaultSectionSize(40);
        tableWidget_cellValues->horizontalHeader()->setHighlightSections(false);
        tableWidget_cellValues->horizontalHeader()->setMinimumSectionSize(10);
        tableWidget_cellValues->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget_cellValues->verticalHeader()->setVisible(false);
        tableWidget_cellValues->verticalHeader()->setDefaultSectionSize(25);
        tableWidget_cellValues->verticalHeader()->setMinimumSectionSize(5);
        transparentWidget = new QTransparentWidget(battery);
        transparentWidget->setObjectName(QStringLiteral("transparentWidget"));
        transparentWidget->setGeometry(QRect(10, 420, 651, 161));
        QSizePolicy sizePolicy9(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy9.setHorizontalStretch(0);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(transparentWidget->sizePolicy().hasHeightForWidth());
        transparentWidget->setSizePolicy(sizePolicy9);
        l_cell_ave = new QLabel(transparentWidget);
        l_cell_ave->setObjectName(QStringLiteral("l_cell_ave"));
        l_cell_ave->setGeometry(QRect(140, 10, 61, 32));
        l_cell_ave->setAlignment(Qt::AlignCenter);
        label_32 = new QLabel(transparentWidget);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setGeometry(QRect(20, 50, 121, 32));
        label_33 = new QLabel(transparentWidget);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setGeometry(QRect(20, 90, 121, 32));
        l_cell_max = new QLabel(transparentWidget);
        l_cell_max->setObjectName(QStringLiteral("l_cell_max"));
        l_cell_max->setGeometry(QRect(140, 90, 61, 32));
        l_cell_max->setAlignment(Qt::AlignCenter);
        l_cell_min = new QLabel(transparentWidget);
        l_cell_min->setObjectName(QStringLiteral("l_cell_min"));
        l_cell_min->setGeometry(QRect(140, 50, 61, 32));
        l_cell_min->setAlignment(Qt::AlignCenter);
        label_35 = new QLabel(transparentWidget);
        label_35->setObjectName(QStringLiteral("label_35"));
        label_35->setGeometry(QRect(20, 10, 111, 32));
        QSizePolicy sizePolicy10(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy10.setHorizontalStretch(0);
        sizePolicy10.setVerticalStretch(0);
        sizePolicy10.setHeightForWidth(label_35->sizePolicy().hasHeightForWidth());
        label_35->setSizePolicy(sizePolicy10);
        label_36 = new QLabel(transparentWidget);
        label_36->setObjectName(QStringLiteral("label_36"));
        label_36->setGeometry(QRect(220, 10, 21, 32));
        label_50 = new QLabel(transparentWidget);
        label_50->setObjectName(QStringLiteral("label_50"));
        label_50->setGeometry(QRect(220, 50, 21, 32));
        label_56 = new QLabel(transparentWidget);
        label_56->setObjectName(QStringLiteral("label_56"));
        label_56->setGeometry(QRect(220, 90, 21, 32));
        est_cap = new QLabel(transparentWidget);
        est_cap->setObjectName(QStringLiteral("est_cap"));
        est_cap->setGeometry(QRect(510, 50, 91, 20));
        est_cap->setAlignment(Qt::AlignCenter);
        label_57 = new QLabel(transparentWidget);
        label_57->setObjectName(QStringLiteral("label_57"));
        label_57->setGeometry(QRect(440, 20, 251, 21));
        pushButton_NNreset = new QPushButton(transparentWidget);
        pushButton_NNreset->setObjectName(QStringLiteral("pushButton_NNreset"));
        pushButton_NNreset->setGeometry(QRect(507, 82, 101, 31));
        layoutWidget_4 = new QWidget(battery);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(970, 10, 261, 581));
        verticalLayout_10 = new QVBoxLayout(layoutWidget_4);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        label_maxVoltage = new QLabel(layoutWidget_4);
        label_maxVoltage->setObjectName(QStringLiteral("label_maxVoltage"));
        label_maxVoltage->setAlignment(Qt::AlignCenter);

        verticalLayout_10->addWidget(label_maxVoltage);

        l_trip_voltageMax = new QLabel(layoutWidget_4);
        l_trip_voltageMax->setObjectName(QStringLiteral("l_trip_voltageMax"));
        l_trip_voltageMax->setText(QStringLiteral("0"));
        l_trip_voltageMax->setAlignment(Qt::AlignCenter);

        verticalLayout_10->addWidget(l_trip_voltageMax);

        tableWidget_batteryCells_max = new QTableWidget(layoutWidget_4);
        if (tableWidget_batteryCells_max->columnCount() < 11)
            tableWidget_batteryCells_max->setColumnCount(11);
        if (tableWidget_batteryCells_max->rowCount() < 8)
            tableWidget_batteryCells_max->setRowCount(8);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_batteryCells_max->setItem(0, 0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_batteryCells_max->setItem(0, 1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_batteryCells_max->setItem(0, 2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_batteryCells_max->setItem(1, 1, __qtablewidgetitem11);
        tableWidget_batteryCells_max->setObjectName(QStringLiteral("tableWidget_batteryCells_max"));
        tableWidget_batteryCells_max->setEnabled(false);
        tableWidget_batteryCells_max->setFocusPolicy(Qt::NoFocus);
        tableWidget_batteryCells_max->setStyleSheet(QLatin1String("QTableWidget{\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color: darkgrey;\n"
"border-radius: 8px;\n"
"padding:4px;\n"
"}\n"
"\n"
""));
        tableWidget_batteryCells_max->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_batteryCells_max->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_batteryCells_max->setAutoScroll(false);
        tableWidget_batteryCells_max->setSelectionMode(QAbstractItemView::NoSelection);
        tableWidget_batteryCells_max->setRowCount(8);
        tableWidget_batteryCells_max->setColumnCount(11);
        tableWidget_batteryCells_max->horizontalHeader()->setVisible(false);
        tableWidget_batteryCells_max->horizontalHeader()->setDefaultSectionSize(12);
        tableWidget_batteryCells_max->horizontalHeader()->setHighlightSections(false);
        tableWidget_batteryCells_max->horizontalHeader()->setMinimumSectionSize(8);
        tableWidget_batteryCells_max->verticalHeader()->setVisible(false);
        tableWidget_batteryCells_max->verticalHeader()->setDefaultSectionSize(12);
        tableWidget_batteryCells_max->verticalHeader()->setMinimumSectionSize(8);

        verticalLayout_10->addWidget(tableWidget_batteryCells_max);

        verticalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer_5);

        label_17 = new QLabel(layoutWidget_4);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setAlignment(Qt::AlignCenter);

        verticalLayout_10->addWidget(label_17);

        gridLayout_8 = new QGridLayout();
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        l_max_bat = new QLabel(layoutWidget_4);
        l_max_bat->setObjectName(QStringLiteral("l_max_bat"));
        l_max_bat->setAlignment(Qt::AlignCenter);

        gridLayout_8->addWidget(l_max_bat, 0, 0, 1, 1);

        l_max_volt = new QLabel(layoutWidget_4);
        l_max_volt->setObjectName(QStringLiteral("l_max_volt"));
        l_max_volt->setAlignment(Qt::AlignCenter);

        gridLayout_8->addWidget(l_max_volt, 0, 1, 1, 1);


        verticalLayout_10->addLayout(gridLayout_8);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer_3);

        label_minVoltage = new QLabel(layoutWidget_4);
        label_minVoltage->setObjectName(QStringLiteral("label_minVoltage"));
        label_minVoltage->setAlignment(Qt::AlignCenter);

        verticalLayout_10->addWidget(label_minVoltage);

        l_trip_voltageMin = new QLabel(layoutWidget_4);
        l_trip_voltageMin->setObjectName(QStringLiteral("l_trip_voltageMin"));
        l_trip_voltageMin->setText(QStringLiteral("0"));
        l_trip_voltageMin->setAlignment(Qt::AlignCenter);

        verticalLayout_10->addWidget(l_trip_voltageMin);

        tableWidget_batteryCells_min = new QTableWidget(layoutWidget_4);
        if (tableWidget_batteryCells_min->columnCount() < 11)
            tableWidget_batteryCells_min->setColumnCount(11);
        if (tableWidget_batteryCells_min->rowCount() < 8)
            tableWidget_batteryCells_min->setRowCount(8);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_batteryCells_min->setItem(0, 0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_batteryCells_min->setItem(0, 1, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget_batteryCells_min->setItem(0, 2, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget_batteryCells_min->setItem(1, 1, __qtablewidgetitem15);
        tableWidget_batteryCells_min->setObjectName(QStringLiteral("tableWidget_batteryCells_min"));
        tableWidget_batteryCells_min->setEnabled(false);
        tableWidget_batteryCells_min->setFocusPolicy(Qt::NoFocus);
        tableWidget_batteryCells_min->setStyleSheet(QLatin1String("QTableWidget{\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color: darkgrey;\n"
"border-radius: 8px;\n"
"padding:4px;\n"
"}\n"
"\n"
""));
        tableWidget_batteryCells_min->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_batteryCells_min->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_batteryCells_min->setAutoScroll(false);
        tableWidget_batteryCells_min->setSelectionMode(QAbstractItemView::NoSelection);
        tableWidget_batteryCells_min->setRowCount(8);
        tableWidget_batteryCells_min->setColumnCount(11);
        tableWidget_batteryCells_min->horizontalHeader()->setVisible(false);
        tableWidget_batteryCells_min->horizontalHeader()->setDefaultSectionSize(12);
        tableWidget_batteryCells_min->horizontalHeader()->setHighlightSections(false);
        tableWidget_batteryCells_min->horizontalHeader()->setMinimumSectionSize(8);
        tableWidget_batteryCells_min->verticalHeader()->setVisible(false);
        tableWidget_batteryCells_min->verticalHeader()->setDefaultSectionSize(12);
        tableWidget_batteryCells_min->verticalHeader()->setMinimumSectionSize(8);

        verticalLayout_10->addWidget(tableWidget_batteryCells_min);

        label_12 = new QLabel(layoutWidget_4);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setAlignment(Qt::AlignCenter);

        verticalLayout_10->addWidget(label_12);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        l_min_bat = new QLabel(layoutWidget_4);
        l_min_bat->setObjectName(QStringLiteral("l_min_bat"));
        l_min_bat->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(l_min_bat, 0, 1, 1, 1);

        l_min_volt = new QLabel(layoutWidget_4);
        l_min_volt->setObjectName(QStringLiteral("l_min_volt"));
        l_min_volt->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(l_min_volt, 0, 2, 1, 1);


        verticalLayout_10->addLayout(gridLayout_2);

        verticalSpacer_12 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer_12);

        tripWidget1 = new QTransparentWidget(battery);
        tripWidget1->setObjectName(QStringLiteral("tripWidget1"));
        tripWidget1->setGeometry(QRect(690, 10, 271, 581));
        trip1 = new QGridLayout(tripWidget1);
        trip1->setObjectName(QStringLiteral("trip1"));
        label_18 = new QLabel(tripWidget1);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setStyleSheet(QStringLiteral("text-decoration: underline;"));
        label_18->setAlignment(Qt::AlignCenter);

        trip1->addWidget(label_18, 0, 0, 1, 4);

        label_22 = new QLabel(tripWidget1);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setIndent(15);

        trip1->addWidget(label_22, 12, 0, 1, 2);

        label_14 = new QLabel(tripWidget1);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setIndent(15);

        trip1->addWidget(label_14, 1, 2, 1, 1);

        l_trip_ncurrentAvg_2 = new QLabel(tripWidget1);
        l_trip_ncurrentAvg_2->setObjectName(QStringLiteral("l_trip_ncurrentAvg_2"));
        l_trip_ncurrentAvg_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        trip1->addWidget(l_trip_ncurrentAvg_2, 6, 1, 1, 1);

        label_21 = new QLabel(tripWidget1);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setText(QStringLiteral("kWh"));

        trip1->addWidget(label_21, 11, 3, 1, 1);

        label_44 = new QLabel(tripWidget1);
        label_44->setObjectName(QStringLiteral("label_44"));
        label_44->setText(QStringLiteral("Current "));
        label_44->setIndent(-1);

        trip1->addWidget(label_44, 4, 0, 1, 1);

        l_trip_capacityPerKm = new QLabel(tripWidget1);
        l_trip_capacityPerKm->setObjectName(QStringLiteral("l_trip_capacityPerKm"));
        l_trip_capacityPerKm->setText(QStringLiteral("0.00"));
        l_trip_capacityPerKm->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        trip1->addWidget(l_trip_capacityPerKm, 13, 2, 1, 1);

        label_34 = new QLabel(tripWidget1);
        label_34->setObjectName(QStringLiteral("label_34"));

        trip1->addWidget(label_34, 9, 0, 1, 1);

        label_16 = new QLabel(tripWidget1);
        label_16->setObjectName(QStringLiteral("label_16"));

        trip1->addWidget(label_16, 5, 3, 1, 1);

        l_trip_pcurrentAvg = new QLabel(tripWidget1);
        l_trip_pcurrentAvg->setObjectName(QStringLiteral("l_trip_pcurrentAvg"));
        l_trip_pcurrentAvg->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        trip1->addWidget(l_trip_pcurrentAvg, 5, 1, 1, 1);

        label_15 = new QLabel(tripWidget1);
        label_15->setObjectName(QStringLiteral("label_15"));

        trip1->addWidget(label_15, 13, 3, 1, 1);

        label_25 = new QLabel(tripWidget1);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setMargin(0);
        label_25->setIndent(15);

        trip1->addWidget(label_25, 5, 0, 1, 1);

        label_19 = new QLabel(tripWidget1);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setIndent(15);

        trip1->addWidget(label_19, 11, 0, 1, 1);

        l_trip_ncurrentMax_2 = new QLabel(tripWidget1);
        l_trip_ncurrentMax_2->setObjectName(QStringLiteral("l_trip_ncurrentMax_2"));
        l_trip_ncurrentMax_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        trip1->addWidget(l_trip_ncurrentMax_2, 6, 2, 1, 1);

        label_8 = new QLabel(tripWidget1);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        trip1->addWidget(label_8, 1, 1, 1, 1);

        l_trip_pcurrentMax = new QLabel(tripWidget1);
        l_trip_pcurrentMax->setObjectName(QStringLiteral("l_trip_pcurrentMax"));
        l_trip_pcurrentMax->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        trip1->addWidget(l_trip_pcurrentMax, 5, 2, 1, 1);

        l_trip_capacityUsed = new QLabel(tripWidget1);
        l_trip_capacityUsed->setObjectName(QStringLiteral("l_trip_capacityUsed"));
        l_trip_capacityUsed->setText(QStringLiteral("0.00"));
        l_trip_capacityUsed->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        trip1->addWidget(l_trip_capacityUsed, 11, 2, 1, 1);

        l_trip_capacityRegenerated = new QLabel(tripWidget1);
        l_trip_capacityRegenerated->setObjectName(QStringLiteral("l_trip_capacityRegenerated"));
        l_trip_capacityRegenerated->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        trip1->addWidget(l_trip_capacityRegenerated, 12, 2, 1, 1);

        line_6 = new QFrame(tripWidget1);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        trip1->addWidget(line_6, 8, 0, 1, 4);

        label_43 = new QLabel(tripWidget1);
        label_43->setObjectName(QStringLiteral("label_43"));
        label_43->setIndent(15);

        trip1->addWidget(label_43, 6, 0, 1, 1);

        label_13 = new QLabel(tripWidget1);
        label_13->setObjectName(QStringLiteral("label_13"));

        trip1->addWidget(label_13, 12, 3, 1, 1);

        label_9 = new QLabel(tripWidget1);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setIndent(15);

        trip1->addWidget(label_9, 13, 0, 1, 1);

        label_28 = new QLabel(tripWidget1);
        label_28->setObjectName(QStringLiteral("label_28"));

        trip1->addWidget(label_28, 6, 3, 1, 1);

        REV_HMI->setCentralWidget(centralWidget);
        battery->raise();
        trip->raise();
        map->raise();
        music->raise();
        home->raise();
        uwaLogo->raise();
        REVlogo->raise();
        tempBlack->raise();
        log->raise();
        menuButt->raise();
        QWidget::setTabOrder(pushButton_stopRecording, pushButton_clear_errors);
        QWidget::setTabOrder(pushButton_clear_errors, checkBox_logGpsRaw);
        QWidget::setTabOrder(checkBox_logGpsRaw, checkBox_logBmsRaw);
        QWidget::setTabOrder(checkBox_logBmsRaw, pushButton_Runsound);
        QWidget::setTabOrder(pushButton_Runsound, checkBox_GPSFile);
        QWidget::setTabOrder(checkBox_GPSFile, checkBox_BMSFile);
        QWidget::setTabOrder(checkBox_BMSFile, pushButton_defaultSettings);
        QWidget::setTabOrder(pushButton_defaultSettings, pushButton_exit);
        QWidget::setTabOrder(pushButton_exit, pushButton_location);
        QWidget::setTabOrder(pushButton_location, toolButton_mute);
        QWidget::setTabOrder(toolButton_mute, toolButton_prev);
        QWidget::setTabOrder(toolButton_prev, toolButton_play);
        QWidget::setTabOrder(toolButton_play, toolButton_stop);
        QWidget::setTabOrder(toolButton_stop, toolButton_next);
        QWidget::setTabOrder(toolButton_next, editname);
        QWidget::setTabOrder(editname, pushButton_startRecording);
        QWidget::setTabOrder(pushButton_startRecording, pushButton_export);
        QWidget::setTabOrder(pushButton_export, pushButton_zoomIn);
        QWidget::setTabOrder(pushButton_zoomIn, pushButton_zoomOut);
        QWidget::setTabOrder(pushButton_zoomOut, checkBox_showComments);
        QWidget::setTabOrder(checkBox_showComments, checkBox_showTestTrack);
        QWidget::setTabOrder(checkBox_showTestTrack, checkBox_autoFollow);
        QWidget::setTabOrder(checkBox_autoFollow, checkBox_showMyTrack);
        QWidget::setTabOrder(checkBox_showMyTrack, checkBox_nightMode);
        QWidget::setTabOrder(checkBox_nightMode, pushButton_loadTrack);
        QWidget::setTabOrder(pushButton_loadTrack, pushButton_deleteTrack);
        QWidget::setTabOrder(pushButton_deleteTrack, mapContHide);
        QWidget::setTabOrder(mapContHide, pushButton_moveUp);
        QWidget::setTabOrder(pushButton_moveUp, pushButton_moveDown);
        QWidget::setTabOrder(pushButton_moveDown, checkBox_repeatThis);
        QWidget::setTabOrder(checkBox_repeatThis, checkBox_repeatAll);
        QWidget::setTabOrder(checkBox_repeatAll, pushButton_addDirectory);

        retranslateUi(REV_HMI);

        QMetaObject::connectSlotsByName(REV_HMI);
    } // setupUi

    void retranslateUi(QMainWindow *REV_HMI)
    {
        REV_HMI->setWindowTitle(QApplication::translate("REV_HMI", "MainWindow", 0));
        logBut->setText(QString());
        tripBut->setText(QString());
        homeBut->setText(QString());
        battBut->setText(QString());
        musicBut->setText(QString());
        mapBut->setText(QString());
        pushButton_clear_errors->setText(QApplication::translate("REV_HMI", "Clear Log", 0));
        checkBox_logGpsRaw->setText(QApplication::translate("REV_HMI", "GPS raw data", 0));
        checkBox_logBmsRaw->setText(QApplication::translate("REV_HMI", "BMS raw data", 0));
        pushButton_Runsound->setText(QApplication::translate("REV_HMI", "Run Eng Simu", 0));
        checkBox_GPSFile->setText(QApplication::translate("REV_HMI", "GPS File", 0));
        checkBox_BMSFile->setText(QApplication::translate("REV_HMI", "BMS File", 0));
        pushButton_defaultSettings->setText(QApplication::translate("REV_HMI", "Default Settings", 0));
        pushButton_exit->setText(QApplication::translate("REV_HMI", "Exit Program", 0));

        const bool __sortingEnabled = info_battTable->isSortingEnabled();
        info_battTable->setSortingEnabled(false);
        info_battTable->setSortingEnabled(__sortingEnabled);

        pushButton_moveUp->setText(QApplication::translate("REV_HMI", "Move Up", 0));
        pushButton_moveDown->setText(QApplication::translate("REV_HMI", "Move Down", 0));
        checkBox_repeatThis->setText(QApplication::translate("REV_HMI", "Repeat This", 0));
        checkBox_repeatAll->setText(QApplication::translate("REV_HMI", "Repeat All", 0));
        pushButton_addDirectory->setText(QApplication::translate("REV_HMI", "Choose Dir.", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_mediaList->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("REV_HMI", "Title", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_mediaList->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("REV_HMI", "Artist", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_mediaList->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("REV_HMI", "Album", 0));
        musicDir->setText(QApplication::translate("REV_HMI", "Music Directory", 0));
        toolButton_mute->setText(QApplication::translate("REV_HMI", "<x", 0));
        editname_label->setText(QApplication::translate("REV_HMI", "Driver Name", 0));
        label_7->setText(QApplication::translate("REV_HMI", "Logging", 0));
        pushButton_stopRecording->setText(QApplication::translate("REV_HMI", "Stop", 0));
        pushButton_startRecording->setText(QApplication::translate("REV_HMI", "Start", 0));
        pushButton_changeRange->setText(QApplication::translate("REV_HMI", "Change max range", 0));
        label_10->setText(QApplication::translate("REV_HMI", "Elapsed Time", 0));
        label_4->setText(QApplication::translate("REV_HMI", "Driving Time", 0));
        label_54->setText(QApplication::translate("REV_HMI", "Export to:", 0));
        pushButton_location->setText(QApplication::translate("REV_HMI", "Location", 0));
        pushButton_export->setText(QApplication::translate("REV_HMI", "Export", 0));
        label_exportLocation->setText(QApplication::translate("REV_HMI", "Directory", 0));
        totalenergy_label->setText(QApplication::translate("REV_HMI", "Total Energy Usage", 0));
        energyUse->setText(QApplication::translate("REV_HMI", "0", 0));
        label_2->setText(QApplication::translate("REV_HMI", "kWh", 0));
        trip_slabel_dist->setText(QApplication::translate("REV_HMI", "Distance", 0));
        energyRem_label->setText(QApplication::translate("REV_HMI", "Energy Remaining", 0));
        energyRem->setText(QApplication::translate("REV_HMI", "0", 0));
        label_5->setText(QApplication::translate("REV_HMI", "kWh", 0));
        label_accel->setText(QApplication::translate("REV_HMI", "Accel 0-50 km/h", 0));
        l_trip_Accel60->setText(QApplication::translate("REV_HMI", "0.00", 0));
        label_050s->setText(QApplication::translate("REV_HMI", "s", 0));
        label_max->setText(QApplication::translate("REV_HMI", "Max", 0));
        label_avg->setText(QApplication::translate("REV_HMI", "Avg", 0));
        label_speedekmh->setText(QApplication::translate("REV_HMI", "km/h", 0));
        l_trip_speedAvgElapsed->setText(QApplication::translate("REV_HMI", "0.00", 0));
        label_tripspeed->setText(QApplication::translate("REV_HMI", "Speed", 0));
        label_driveA->setText(QApplication::translate("REV_HMI", "A", 0));
        l_trip_ncurrentMax->setText(QApplication::translate("REV_HMI", "0.00", 0));
        l_trip_ncurrentAvg->setText(QApplication::translate("REV_HMI", "0.00", 0));
        Handbrakeicon->setText(QString());
        Neticon->setText(QString());
        CELicon->setText(QString());
        Dooricon->setText(QString());
        SeatBelticon->setText(QString());
        label_kmh->setText(QApplication::translate("REV_HMI", "km/h", 0));
        driver_name->setText(QApplication::translate("REV_HMI", "UWA REV Project", 0));
        labelVoltage->setText(QApplication::translate("REV_HMI", "V", 0));
        label_tripDist->setText(QApplication::translate("REV_HMI", "Trip Distance", 0));
        val_tripDist->setText(QApplication::translate("REV_HMI", "0.00 km", 0));
        label_tripTime->setText(QApplication::translate("REV_HMI", "Trip Time", 0));
        val_tripTime->setText(QApplication::translate("REV_HMI", "00:00:00", 0));
        label_6->setText(QApplication::translate("REV_HMI", "Distance Remaining", 0));
        economy_label->setText(QApplication::translate("REV_HMI", "Economy", 0));
        val_economy->setText(QApplication::translate("REV_HMI", "0.00 km/kWh", 0));
        label_KM->setText(QApplication::translate("REV_HMI", "km", 0));
        GPSicon->setText(QString());
        TBSicon->setText(QString());
        lowBatticon->setText(QString());
        Fueldooricon->setText(QString());
        Safetyswitchicon->setText(QString());
        label->setText(QApplication::translate("REV_HMI", "Efficiency", 0));
        efficiencyLabel->setText(QApplication::translate("REV_HMI", "-- %", 0));
        pushButton_zoomIn->setText(QApplication::translate("REV_HMI", "Zoom in", 0));
        pushButton_zoomOut->setText(QApplication::translate("REV_HMI", "Zoom out", 0));
        checkBox_showComments->setText(QApplication::translate("REV_HMI", "Show comments", 0));
        checkBox_showTestTrack->setText(QApplication::translate("REV_HMI", "Show test track", 0));
        checkBox_autoFollow->setText(QApplication::translate("REV_HMI", "Center", 0));
        checkBox_showMyTrack->setText(QApplication::translate("REV_HMI", "Show my track", 0));
        checkBox_nightMode->setText(QApplication::translate("REV_HMI", "Nightmode", 0));
        pushButton_loadTrack->setText(QApplication::translate("REV_HMI", "Load track", 0));
        pushButton_deleteTrack->setText(QApplication::translate("REV_HMI", "Delete track", 0));
        mapContHide->setText(QApplication::translate("REV_HMI", "Hide Controls", 0));

        const bool __sortingEnabled1 = tableWidget_cellValues->isSortingEnabled();
        tableWidget_cellValues->setSortingEnabled(false);
        tableWidget_cellValues->setSortingEnabled(__sortingEnabled1);

        l_cell_ave->setText(QApplication::translate("REV_HMI", "--", 0));
        label_32->setText(QApplication::translate("REV_HMI", "Minimum", 0));
        label_33->setText(QApplication::translate("REV_HMI", "Maximum", 0));
        l_cell_max->setText(QApplication::translate("REV_HMI", "--", 0));
        l_cell_min->setText(QApplication::translate("REV_HMI", "--", 0));
        label_35->setText(QApplication::translate("REV_HMI", "Average", 0));
        label_36->setText(QApplication::translate("REV_HMI", "V", 0));
        label_50->setText(QApplication::translate("REV_HMI", "V", 0));
        label_56->setText(QApplication::translate("REV_HMI", "V", 0));
        est_cap->setText(QApplication::translate("REV_HMI", "--", 0));
        label_57->setText(QApplication::translate("REV_HMI", "NN Estimator Value", 0));
        pushButton_NNreset->setText(QApplication::translate("REV_HMI", "RESET", 0));
        label_maxVoltage->setText(QApplication::translate("REV_HMI", "Max. Voltage", 0));

        const bool __sortingEnabled2 = tableWidget_batteryCells_max->isSortingEnabled();
        tableWidget_batteryCells_max->setSortingEnabled(false);
        tableWidget_batteryCells_max->setSortingEnabled(__sortingEnabled2);

        label_17->setText(QApplication::translate("REV_HMI", "Maximum Cell", 0));
        l_max_bat->setText(QApplication::translate("REV_HMI", "--", 0));
        l_max_volt->setText(QApplication::translate("REV_HMI", "--", 0));
        label_minVoltage->setText(QApplication::translate("REV_HMI", "Min. Voltage", 0));

        const bool __sortingEnabled3 = tableWidget_batteryCells_min->isSortingEnabled();
        tableWidget_batteryCells_min->setSortingEnabled(false);
        tableWidget_batteryCells_min->setSortingEnabled(__sortingEnabled3);

        label_12->setText(QApplication::translate("REV_HMI", "Minimum Cell", 0));
        l_min_bat->setText(QApplication::translate("REV_HMI", "--", 0));
        l_min_volt->setText(QApplication::translate("REV_HMI", "--", 0));
        label_18->setText(QApplication::translate("REV_HMI", "Trip Statistics", 0));
        label_22->setText(QApplication::translate("REV_HMI", "Regenerated", 0));
        label_14->setText(QApplication::translate("REV_HMI", "Max", 0));
        l_trip_ncurrentAvg_2->setText(QApplication::translate("REV_HMI", "0.00", 0));
        label_34->setText(QApplication::translate("REV_HMI", "Energy", 0));
        label_16->setText(QApplication::translate("REV_HMI", "A", 0));
        l_trip_pcurrentAvg->setText(QApplication::translate("REV_HMI", "0.00", 0));
        label_15->setText(QApplication::translate("REV_HMI", "kWh", 0));
        label_25->setText(QApplication::translate("REV_HMI", "Charge", 0));
        label_19->setText(QApplication::translate("REV_HMI", "Used", 0));
        l_trip_ncurrentMax_2->setText(QApplication::translate("REV_HMI", "0.00", 0));
        label_8->setText(QApplication::translate("REV_HMI", "Avg", 0));
        l_trip_pcurrentMax->setText(QApplication::translate("REV_HMI", "0.00", 0));
        l_trip_capacityRegenerated->setText(QApplication::translate("REV_HMI", "0.00", 0));
        label_43->setText(QApplication::translate("REV_HMI", "Drive", 0));
        label_13->setText(QApplication::translate("REV_HMI", "kWh", 0));
        label_9->setText(QApplication::translate("REV_HMI", "Per km", 0));
        label_28->setText(QApplication::translate("REV_HMI", "A", 0));
    } // retranslateUi

};

namespace Ui {
    class REV_HMI: public Ui_REV_HMI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOTUS_HMI_H
