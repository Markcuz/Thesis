/********************************************************************************
** Form generated from reading UI file 'getz_hmi.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GETZ_HMI_H
#define UI_GETZ_HMI_H

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

QT_BEGIN_NAMESPACE

class Ui_REV_HMI
{
public:
    QWidget *centralWidget;
    QWidget *menuButt;
    QHBoxLayout *menuButtons;
    QGraphicsView *logBut;
    QGraphicsView *tripBut;
    QGraphicsView *homeBut;
    QGraphicsView *musicBut;
    QGraphicsView *mapBut;
    QGraphicsView *uwaLogo;
    QGraphicsView *REVlogo;
    QWidget *log;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout;
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
    QWidget *music;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_moveUp;
    QPushButton *pushButton_moveDown;
    QCheckBox *checkBox_repeatThis;
    QCheckBox *checkBox_repeatAll;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton_addDirectory;
    QSlider *playervolSlider;
    QTableWidget *tableWidget_mediaList;
    QLabel *musicDir;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_7;
    QToolButton *toolButton_mute;
    QToolButton *toolButton_prev;
    QToolButton *toolButton_play;
    QToolButton *toolButton_stop;
    QToolButton *toolButton_next;
    QSlider *playerseekSlider;
    QWidget *trip;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *tripButLayout;
    QLabel *editname_label;
    QSpacerItem *verticalSpacer_4;
    QTextEdit *editname;
    QSpacerItem *verticalSpacer_7;
    QGridLayout *gridLayout_6;
    QPushButton *pushButton_startRecording;
    QPushButton *pushButton_stopRecording;
    QPushButton *pushButton_changeRange;
    QSpacerItem *verticalSpacer_6;
    QLabel *label_10;
    QLabel *l_trip_time;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_4;
    QLabel *l_drive_time;
    QSpacerItem *verticalSpacer_5;
    QLabel *label_54;
    QGridLayout *gridLayout_7;
    QPushButton *pushButton_location;
    QPushButton *pushButton_export;
    QLabel *label_exportLocation;
    QSpacerItem *verticalSpacer;
    QWidget *gridLayoutWidget_2;
    QGridLayout *trip_stats_layout;
    QWidget *trip_hori2;
    QLabel *label_avg;
    QLabel *label_max;
    QWidget *trip_hori3_2;
    QLabel *label_tripspeed;
    QLabel *l_trip_speedAvgElapsed;
    QLabel *l_trip_speedMax;
    QLabel *label_speedekmh;
    QHBoxLayout *horizontalLayout_2;
    QLabel *energyRem_label;
    QLabel *energyRem;
    QHBoxLayout *horizontalLayout_3;
    QLabel *pervTrip_label;
    QLabel *prevTrip;
    QFrame *line_4;
    QHBoxLayout *trip_hori5;
    QLabel *label_accel;
    QLabel *label_050;
    QLabel *l_trip_Accel60;
    QLabel *label_050s;
    QHBoxLayout *trip_hori1;
    QLabel *trip_slabel_dist;
    QLabel *l_trip_distance;
    QLabel *label_distkm;
    QFrame *line_3;
    QHBoxLayout *trip_hori4;
    QLabel *label_current;
    QLabel *l_trip_ncurrentAvg;
    QLabel *l_trip_ncurrentMax;
    QLabel *label_driveA;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *totalenergy_label;
    QLabel *energyUse;
    QWidget *current_graph;
    QWidget *efficiency_graph;
    QWidget *home;
    QWidget *warningIcons;
    QGridLayout *WarningIcons;
    QLabel *Handbrakeicon;
    QLabel *lowBatticon;
    QLabel *Fueldooricon;
    QLabel *TBSicon;
    QLabel *Neticon;
    QLabel *CELicon;
    QLabel *Dooricon;
    QLabel *Safetyswitchicon;
    QLabel *SeatBelticon;
    QLabel *GPSicon;
    QWidget *speed;
    QLabel *l_speed;
    QLabel *label_kmh;
    QLabel *l_time;
    QWidget *tripInfo;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_4;
    QLabel *val_tripDist;
    QLabel *label_tripDist;
    QLabel *label_tripTime;
    QLabel *val_tripTime;
    QLabel *label;
    QLabel *temperature;
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
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *l_remdist;
    QLabel *label_KM;
    QProgressBar *progressBar_ampsCharge;
    MapWidget *tempBlack;
    MapWidget *mapWidget;
    QTransparentWidget *mapControls;
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
    QWidget *map;
    QWidget *controls;
    QVBoxLayout *verticalLayout_4;
    MapWidget *widget;
    QLabel *label_2;

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
        REV_HMI->setStyleSheet(QLatin1String("\n"
"QProgressBar:vertical {\n"
"	background-color: rgba(255, 255, 255, 150);\n"
"    border: 2px solid grey;\n"
"    border-radius: 5px;\n"
"	text-align: center;\n"
"}\n"
"/*only one big chunk*/\n"
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
        centralWidget->setStyleSheet(QLatin1String("#centralWidget{\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(0, 129, 9, 255));\n"
"}\n"
"\n"
"QLabel{\n"
"font: 75 15pt \"Liberation serif\";\n"
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
        menuButt->setGeometry(QRect(330, 590, 631, 131));
        menuButtons = new QHBoxLayout(menuButt);
        menuButtons->setObjectName(QStringLiteral("menuButtons"));
        logBut = new QGraphicsView(menuButt);
        logBut->setObjectName(QStringLiteral("logBut"));
        logBut->setMaximumSize(QSize(100, 100));
        logBut->setFocusPolicy(Qt::NoFocus);
        logBut->setStyleSheet(QLatin1String("#logBut:focus{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"	border-image: url(:/images/log.png);\n"
"}\n"
"#logBut{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"	border-image: url(:/images/logbw.png);\n"
"}"));
        logBut->setFrameShape(QFrame::NoFrame);

        menuButtons->addWidget(logBut);

        tripBut = new QGraphicsView(menuButt);
        tripBut->setObjectName(QStringLiteral("tripBut"));
        tripBut->setMaximumSize(QSize(100, 100));
        tripBut->setFocusPolicy(Qt::NoFocus);
        tripBut->setStyleSheet(QLatin1String("#tripBut:focus{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"	border-image: url(:/images/settings.png);\n"
"}\n"
"#tripBut{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"	border-image: url(:/images/settingsbw.png);\n"
"}"));
        tripBut->setFrameShape(QFrame::NoFrame);

        menuButtons->addWidget(tripBut);

        homeBut = new QGraphicsView(menuButt);
        homeBut->setObjectName(QStringLiteral("homeBut"));
        homeBut->setMaximumSize(QSize(100, 100));
        homeBut->setFocusPolicy(Qt::NoFocus);
        homeBut->setStyleSheet(QLatin1String("#homeBut:focus{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"	border-image: url(:/images/car.png);\n"
"}\n"
"#homeBut{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"	border-image: url(:/images/carbw.png);\n"
"}\n"
""));
        homeBut->setFrameShape(QFrame::NoFrame);

        menuButtons->addWidget(homeBut);

        musicBut = new QGraphicsView(menuButt);
        musicBut->setObjectName(QStringLiteral("musicBut"));
        musicBut->setMaximumSize(QSize(100, 100));
        musicBut->setFocusPolicy(Qt::NoFocus);
        musicBut->setStyleSheet(QLatin1String("#musicBut:focus{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"	border-image: url(:/images/music.png);\n"
"}\n"
"#musicBut{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"	border-image: url(:/images/musicbw.png);\n"
"}"));
        musicBut->setFrameShape(QFrame::NoFrame);

        menuButtons->addWidget(musicBut);

        mapBut = new QGraphicsView(menuButt);
        mapBut->setObjectName(QStringLiteral("mapBut"));
        mapBut->setMaximumSize(QSize(100, 100));
        mapBut->setFocusPolicy(Qt::NoFocus);
        mapBut->setStyleSheet(QLatin1String("#mapBut:focus{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"	border-image: url(:/images/map.png);\n"
"}\n"
"#mapBut{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"	border-image: url(:/images/mapbw.png);\n"
"}"));
        mapBut->setFrameShape(QFrame::NoFrame);

        menuButtons->addWidget(mapBut);

        uwaLogo = new QGraphicsView(centralWidget);
        uwaLogo->setObjectName(QStringLiteral("uwaLogo"));
        uwaLogo->setGeometry(QRect(40, 620, 261, 71));
        uwaLogo->setStyleSheet(QStringLiteral("border-image: url(:/images/UWA-logo.png);"));
        REVlogo = new QGraphicsView(centralWidget);
        REVlogo->setObjectName(QStringLiteral("REVlogo"));
        REVlogo->setGeometry(QRect(940, 610, 321, 81));
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
        verticalLayout = new QVBoxLayout(layoutWidget_3);
        verticalLayout->setSpacing(3);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(10, 0, 10, 0);
        pushButton_clear_errors = new QPushButton(layoutWidget_3);
        pushButton_clear_errors->setObjectName(QStringLiteral("pushButton_clear_errors"));

        verticalLayout->addWidget(pushButton_clear_errors);

        checkBox_logGpsRaw = new QCheckBox(layoutWidget_3);
        checkBox_logGpsRaw->setObjectName(QStringLiteral("checkBox_logGpsRaw"));

        verticalLayout->addWidget(checkBox_logGpsRaw);

        checkBox_logBmsRaw = new QCheckBox(layoutWidget_3);
        checkBox_logBmsRaw->setObjectName(QStringLiteral("checkBox_logBmsRaw"));

        verticalLayout->addWidget(checkBox_logBmsRaw);

        pushButton_Runsound = new QPushButton(layoutWidget_3);
        pushButton_Runsound->setObjectName(QStringLiteral("pushButton_Runsound"));

        verticalLayout->addWidget(pushButton_Runsound);

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

        verticalLayout->addWidget(horizontalSlider);

        checkBox_GPSFile = new QCheckBox(layoutWidget_3);
        checkBox_GPSFile->setObjectName(QStringLiteral("checkBox_GPSFile"));

        verticalLayout->addWidget(checkBox_GPSFile);

        checkBox_BMSFile = new QCheckBox(layoutWidget_3);
        checkBox_BMSFile->setObjectName(QStringLiteral("checkBox_BMSFile"));

        verticalLayout->addWidget(checkBox_BMSFile);

        pushButton_defaultSettings = new QPushButton(layoutWidget_3);
        pushButton_defaultSettings->setObjectName(QStringLiteral("pushButton_defaultSettings"));

        verticalLayout->addWidget(pushButton_defaultSettings);

        pushButton_exit = new QPushButton(layoutWidget_3);
        pushButton_exit->setObjectName(QStringLiteral("pushButton_exit"));

        verticalLayout->addWidget(pushButton_exit);

        textBrowser_errors = new QTextBrowser(log);
        textBrowser_errors->setObjectName(QStringLiteral("textBrowser_errors"));
        textBrowser_errors->setGeometry(QRect(80, 30, 621, 521));
        textBrowser_errors->setFocusPolicy(Qt::NoFocus);
        textBrowser_errors->setStyleSheet(QLatin1String("font: 10pt \"Lucida Console\";\n"
"background-color: rgb(212, 212, 212);"));
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
        layoutWidget->setGeometry(QRect(10, 40, 1241, 541));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(3);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, -1, -1, -1);
        pushButton_moveUp = new QPushButton(layoutWidget);
        pushButton_moveUp->setObjectName(QStringLiteral("pushButton_moveUp"));

        verticalLayout_2->addWidget(pushButton_moveUp);

        pushButton_moveDown = new QPushButton(layoutWidget);
        pushButton_moveDown->setObjectName(QStringLiteral("pushButton_moveDown"));

        verticalLayout_2->addWidget(pushButton_moveDown);

        checkBox_repeatThis = new QCheckBox(layoutWidget);
        checkBox_repeatThis->setObjectName(QStringLiteral("checkBox_repeatThis"));

        verticalLayout_2->addWidget(checkBox_repeatThis);

        checkBox_repeatAll = new QCheckBox(layoutWidget);
        checkBox_repeatAll->setObjectName(QStringLiteral("checkBox_repeatAll"));

        verticalLayout_2->addWidget(checkBox_repeatAll);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        pushButton_addDirectory = new QPushButton(layoutWidget);
        pushButton_addDirectory->setObjectName(QStringLiteral("pushButton_addDirectory"));

        verticalLayout_2->addWidget(pushButton_addDirectory);


        gridLayout->addLayout(verticalLayout_2, 0, 2, 1, 1);

        playervolSlider = new QSlider(layoutWidget);
        playervolSlider->setObjectName(QStringLiteral("playervolSlider"));
        playervolSlider->setFocusPolicy(Qt::NoFocus);
        playervolSlider->setValue(60);
        playervolSlider->setSliderPosition(60);
        playervolSlider->setOrientation(Qt::Vertical);

        gridLayout->addWidget(playervolSlider, 0, 0, 1, 1);

        tableWidget_mediaList = new QTableWidget(layoutWidget);
        if (tableWidget_mediaList->columnCount() < 3)
            tableWidget_mediaList->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_mediaList->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_mediaList->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_mediaList->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget_mediaList->setObjectName(QStringLiteral("tableWidget_mediaList"));
        tableWidget_mediaList->setEnabled(true);
        tableWidget_mediaList->setMinimumSize(QSize(500, 0));
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
        layoutWidget_2->setGeometry(QRect(10, 10, 1241, 30));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        toolButton_mute = new QToolButton(layoutWidget_2);
        toolButton_mute->setObjectName(QStringLiteral("toolButton_mute"));
        toolButton_mute->setAutoRaise(true);

        horizontalLayout_7->addWidget(toolButton_mute);

        toolButton_prev = new QToolButton(layoutWidget_2);
        toolButton_prev->setObjectName(QStringLiteral("toolButton_prev"));
        toolButton_prev->setText(QStringLiteral("|<"));
        toolButton_prev->setAutoRaise(true);

        horizontalLayout_7->addWidget(toolButton_prev);

        toolButton_play = new QToolButton(layoutWidget_2);
        toolButton_play->setObjectName(QStringLiteral("toolButton_play"));
        toolButton_play->setText(QStringLiteral(">"));
        toolButton_play->setIconSize(QSize(40, 40));
        toolButton_play->setToolButtonStyle(Qt::ToolButtonIconOnly);
        toolButton_play->setAutoRaise(true);

        horizontalLayout_7->addWidget(toolButton_play);

        toolButton_stop = new QToolButton(layoutWidget_2);
        toolButton_stop->setObjectName(QStringLiteral("toolButton_stop"));
        toolButton_stop->setText(QStringLiteral("[]"));
        toolButton_stop->setAutoRaise(true);

        horizontalLayout_7->addWidget(toolButton_stop);

        toolButton_next = new QToolButton(layoutWidget_2);
        toolButton_next->setObjectName(QStringLiteral("toolButton_next"));
        toolButton_next->setText(QStringLiteral(">|"));
        toolButton_next->setAutoRaise(true);

        horizontalLayout_7->addWidget(toolButton_next);

        playerseekSlider = new QSlider(layoutWidget_2);
        playerseekSlider->setObjectName(QStringLiteral("playerseekSlider"));
        playerseekSlider->setFocusPolicy(Qt::NoFocus);
        playerseekSlider->setMaximum(1000);
        playerseekSlider->setOrientation(Qt::Horizontal);
        playerseekSlider->setTickPosition(QSlider::NoTicks);

        horizontalLayout_7->addWidget(playerseekSlider);

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
        verticalLayoutWidget->setGeometry(QRect(1020, 60, 245, 451));
        tripButLayout = new QVBoxLayout(verticalLayoutWidget);
        tripButLayout->setObjectName(QStringLiteral("tripButLayout"));
        tripButLayout->setContentsMargins(0, 0, 0, 0);
        editname_label = new QLabel(verticalLayoutWidget);
        editname_label->setObjectName(QStringLiteral("editname_label"));
        editname_label->setAlignment(Qt::AlignCenter);

        tripButLayout->addWidget(editname_label);

        verticalSpacer_4 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Expanding);

        tripButLayout->addItem(verticalSpacer_4);

        editname = new QTextEdit(verticalLayoutWidget);
        editname->setObjectName(QStringLiteral("editname"));
        editname->setMaximumSize(QSize(16777215, 30));

        tripButLayout->addWidget(editname);

        verticalSpacer_7 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        tripButLayout->addItem(verticalSpacer_7);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        pushButton_startRecording = new QPushButton(verticalLayoutWidget);
        pushButton_startRecording->setObjectName(QStringLiteral("pushButton_startRecording"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_startRecording->sizePolicy().hasHeightForWidth());
        pushButton_startRecording->setSizePolicy(sizePolicy2);
        pushButton_startRecording->setMinimumSize(QSize(80, 25));
        pushButton_startRecording->setMaximumSize(QSize(80, 25));

        gridLayout_6->addWidget(pushButton_startRecording, 1, 0, 1, 1);

        pushButton_stopRecording = new QPushButton(verticalLayoutWidget);
        pushButton_stopRecording->setObjectName(QStringLiteral("pushButton_stopRecording"));
        sizePolicy2.setHeightForWidth(pushButton_stopRecording->sizePolicy().hasHeightForWidth());
        pushButton_stopRecording->setSizePolicy(sizePolicy2);
        pushButton_stopRecording->setMinimumSize(QSize(80, 25));
        pushButton_stopRecording->setMaximumSize(QSize(80, 25));

        gridLayout_6->addWidget(pushButton_stopRecording, 1, 1, 1, 1);


        tripButLayout->addLayout(gridLayout_6);

        pushButton_changeRange = new QPushButton(verticalLayoutWidget);
        pushButton_changeRange->setObjectName(QStringLiteral("pushButton_changeRange"));

        tripButLayout->addWidget(pushButton_changeRange);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        tripButLayout->addItem(verticalSpacer_6);

        label_10 = new QLabel(verticalLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        QFont font;
        font.setFamily(QStringLiteral("Liberation serif"));
        font.setPointSize(15);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        label_10->setFont(font);
        label_10->setAlignment(Qt::AlignCenter);

        tripButLayout->addWidget(label_10);

        l_trip_time = new QLabel(verticalLayoutWidget);
        l_trip_time->setObjectName(QStringLiteral("l_trip_time"));
        l_trip_time->setText(QStringLiteral("00:00:00"));
        l_trip_time->setAlignment(Qt::AlignCenter);

        tripButLayout->addWidget(l_trip_time);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        tripButLayout->addItem(verticalSpacer_3);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        tripButLayout->addWidget(label_4);

        l_drive_time = new QLabel(verticalLayoutWidget);
        l_drive_time->setObjectName(QStringLiteral("l_drive_time"));
        l_drive_time->setText(QStringLiteral("00:00:00"));
        l_drive_time->setAlignment(Qt::AlignCenter);

        tripButLayout->addWidget(l_drive_time);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        tripButLayout->addItem(verticalSpacer_5);

        label_54 = new QLabel(verticalLayoutWidget);
        label_54->setObjectName(QStringLiteral("label_54"));
        label_54->setAlignment(Qt::AlignCenter);

        tripButLayout->addWidget(label_54);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        pushButton_location = new QPushButton(verticalLayoutWidget);
        pushButton_location->setObjectName(QStringLiteral("pushButton_location"));
        pushButton_location->setMinimumSize(QSize(0, 25));
        pushButton_location->setMaximumSize(QSize(80, 25));

        gridLayout_7->addWidget(pushButton_location, 1, 0, 1, 1);

        pushButton_export = new QPushButton(verticalLayoutWidget);
        pushButton_export->setObjectName(QStringLiteral("pushButton_export"));
        pushButton_export->setMinimumSize(QSize(0, 25));
        pushButton_export->setMaximumSize(QSize(80, 25));

        gridLayout_7->addWidget(pushButton_export, 1, 1, 1, 1);


        tripButLayout->addLayout(gridLayout_7);

        label_exportLocation = new QLabel(verticalLayoutWidget);
        label_exportLocation->setObjectName(QStringLiteral("label_exportLocation"));
        label_exportLocation->setStyleSheet(QLatin1String("QLabel{\n"
"font: 75 10pt \"Liberation serif\";\n"
"}"));
        label_exportLocation->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        tripButLayout->addWidget(label_exportLocation);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        tripButLayout->addItem(verticalSpacer);

        gridLayoutWidget_2 = new QWidget(trip);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(500, 40, 501, 481));
        trip_stats_layout = new QGridLayout(gridLayoutWidget_2);
        trip_stats_layout->setObjectName(QStringLiteral("trip_stats_layout"));
        trip_stats_layout->setContentsMargins(0, 0, 0, 0);
        trip_hori2 = new QWidget(gridLayoutWidget_2);
        trip_hori2->setObjectName(QStringLiteral("trip_hori2"));
        label_avg = new QLabel(trip_hori2);
        label_avg->setObjectName(QStringLiteral("label_avg"));
        label_avg->setGeometry(QRect(280, 10, 75, 25));
        label_avg->setMinimumSize(QSize(75, 25));
        label_avg->setMaximumSize(QSize(75, 25));
        label_avg->setAlignment(Qt::AlignCenter);
        label_max = new QLabel(trip_hori2);
        label_max->setObjectName(QStringLiteral("label_max"));
        label_max->setGeometry(QRect(360, 10, 75, 25));
        label_max->setMinimumSize(QSize(75, 25));
        label_max->setMaximumSize(QSize(75, 25));
        label_max->setAlignment(Qt::AlignCenter);
        label_max->setIndent(15);

        trip_stats_layout->addWidget(trip_hori2, 1, 0, 1, 1);

        trip_hori3_2 = new QWidget(gridLayoutWidget_2);
        trip_hori3_2->setObjectName(QStringLiteral("trip_hori3_2"));
        label_tripspeed = new QLabel(trip_hori3_2);
        label_tripspeed->setObjectName(QStringLiteral("label_tripspeed"));
        label_tripspeed->setGeometry(QRect(0, 20, 131, 25));
        label_tripspeed->setMinimumSize(QSize(0, 25));
        label_tripspeed->setMaximumSize(QSize(16777215, 25));
        l_trip_speedAvgElapsed = new QLabel(trip_hori3_2);
        l_trip_speedAvgElapsed->setObjectName(QStringLiteral("l_trip_speedAvgElapsed"));
        l_trip_speedAvgElapsed->setGeometry(QRect(260, 20, 75, 25));
        l_trip_speedAvgElapsed->setMinimumSize(QSize(75, 25));
        l_trip_speedAvgElapsed->setMaximumSize(QSize(75, 25));
        l_trip_speedAvgElapsed->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        l_trip_speedMax = new QLabel(trip_hori3_2);
        l_trip_speedMax->setObjectName(QStringLiteral("l_trip_speedMax"));
        l_trip_speedMax->setGeometry(QRect(360, 20, 75, 25));
        l_trip_speedMax->setMinimumSize(QSize(75, 25));
        l_trip_speedMax->setMaximumSize(QSize(75, 25));
        l_trip_speedMax->setText(QStringLiteral("0.00"));
        l_trip_speedMax->setAlignment(Qt::AlignCenter);
        label_speedekmh = new QLabel(trip_hori3_2);
        label_speedekmh->setObjectName(QStringLiteral("label_speedekmh"));
        label_speedekmh->setGeometry(QRect(440, 20, 40, 18));
        sizePolicy.setHeightForWidth(label_speedekmh->sizePolicy().hasHeightForWidth());
        label_speedekmh->setSizePolicy(sizePolicy);
        label_speedekmh->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        trip_stats_layout->addWidget(trip_hori3_2, 3, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        energyRem_label = new QLabel(gridLayoutWidget_2);
        energyRem_label->setObjectName(QStringLiteral("energyRem_label"));

        horizontalLayout_2->addWidget(energyRem_label);

        energyRem = new QLabel(gridLayoutWidget_2);
        energyRem->setObjectName(QStringLiteral("energyRem"));

        horizontalLayout_2->addWidget(energyRem);


        trip_stats_layout->addLayout(horizontalLayout_2, 8, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pervTrip_label = new QLabel(gridLayoutWidget_2);
        pervTrip_label->setObjectName(QStringLiteral("pervTrip_label"));

        horizontalLayout_3->addWidget(pervTrip_label);

        prevTrip = new QLabel(gridLayoutWidget_2);
        prevTrip->setObjectName(QStringLiteral("prevTrip"));

        horizontalLayout_3->addWidget(prevTrip);


        trip_stats_layout->addLayout(horizontalLayout_3, 9, 0, 1, 1);

        line_4 = new QFrame(gridLayoutWidget_2);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        trip_stats_layout->addWidget(line_4, 6, 0, 1, 1);

        trip_hori5 = new QHBoxLayout();
        trip_hori5->setObjectName(QStringLiteral("trip_hori5"));
        label_accel = new QLabel(gridLayoutWidget_2);
        label_accel->setObjectName(QStringLiteral("label_accel"));
        label_accel->setMinimumSize(QSize(0, 25));
        label_accel->setMaximumSize(QSize(16777215, 25));

        trip_hori5->addWidget(label_accel);

        label_050 = new QLabel(gridLayoutWidget_2);
        label_050->setObjectName(QStringLiteral("label_050"));
        label_050->setMinimumSize(QSize(0, 25));
        label_050->setMaximumSize(QSize(16777215, 25));
        label_050->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_050->setIndent(15);

        trip_hori5->addWidget(label_050);

        l_trip_Accel60 = new QLabel(gridLayoutWidget_2);
        l_trip_Accel60->setObjectName(QStringLiteral("l_trip_Accel60"));
        l_trip_Accel60->setMinimumSize(QSize(75, 25));
        l_trip_Accel60->setMaximumSize(QSize(75, 25));
        l_trip_Accel60->setAlignment(Qt::AlignCenter);

        trip_hori5->addWidget(l_trip_Accel60);

        label_050s = new QLabel(gridLayoutWidget_2);
        label_050s->setObjectName(QStringLiteral("label_050s"));
        label_050s->setMinimumSize(QSize(45, 25));
        label_050s->setMaximumSize(QSize(45, 25));

        trip_hori5->addWidget(label_050s);


        trip_stats_layout->addLayout(trip_hori5, 7, 0, 1, 1);

        trip_hori1 = new QHBoxLayout();
        trip_hori1->setObjectName(QStringLiteral("trip_hori1"));
        trip_slabel_dist = new QLabel(gridLayoutWidget_2);
        trip_slabel_dist->setObjectName(QStringLiteral("trip_slabel_dist"));
        trip_slabel_dist->setMinimumSize(QSize(0, 25));
        trip_slabel_dist->setMaximumSize(QSize(16777215, 25));

        trip_hori1->addWidget(trip_slabel_dist);

        l_trip_distance = new QLabel(gridLayoutWidget_2);
        l_trip_distance->setObjectName(QStringLiteral("l_trip_distance"));
        l_trip_distance->setMinimumSize(QSize(75, 25));
        l_trip_distance->setMaximumSize(QSize(75, 25));
        l_trip_distance->setText(QStringLiteral("0.00"));
        l_trip_distance->setAlignment(Qt::AlignCenter);

        trip_hori1->addWidget(l_trip_distance);

        label_distkm = new QLabel(gridLayoutWidget_2);
        label_distkm->setObjectName(QStringLiteral("label_distkm"));
        label_distkm->setMinimumSize(QSize(45, 25));
        label_distkm->setMaximumSize(QSize(45, 25));
        label_distkm->setLayoutDirection(Qt::LeftToRight);
        label_distkm->setText(QStringLiteral("km"));
        label_distkm->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        trip_hori1->addWidget(label_distkm);


        trip_stats_layout->addLayout(trip_hori1, 0, 0, 1, 1);

        line_3 = new QFrame(gridLayoutWidget_2);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        trip_stats_layout->addWidget(line_3, 2, 0, 1, 1);

        trip_hori4 = new QHBoxLayout();
        trip_hori4->setObjectName(QStringLiteral("trip_hori4"));
        label_current = new QLabel(gridLayoutWidget_2);
        label_current->setObjectName(QStringLiteral("label_current"));
        label_current->setMinimumSize(QSize(0, 25));
        label_current->setMaximumSize(QSize(280, 25));
        label_current->setText(QStringLiteral("Current "));
        label_current->setIndent(-1);

        trip_hori4->addWidget(label_current);

        l_trip_ncurrentAvg = new QLabel(gridLayoutWidget_2);
        l_trip_ncurrentAvg->setObjectName(QStringLiteral("l_trip_ncurrentAvg"));
        l_trip_ncurrentAvg->setMinimumSize(QSize(75, 25));
        l_trip_ncurrentAvg->setMaximumSize(QSize(75, 25));
        l_trip_ncurrentAvg->setFont(font);
        l_trip_ncurrentAvg->setAlignment(Qt::AlignCenter);

        trip_hori4->addWidget(l_trip_ncurrentAvg);

        l_trip_ncurrentMax = new QLabel(gridLayoutWidget_2);
        l_trip_ncurrentMax->setObjectName(QStringLiteral("l_trip_ncurrentMax"));
        l_trip_ncurrentMax->setMinimumSize(QSize(75, 25));
        l_trip_ncurrentMax->setMaximumSize(QSize(75, 25));
        l_trip_ncurrentMax->setAlignment(Qt::AlignCenter);

        trip_hori4->addWidget(l_trip_ncurrentMax);

        label_driveA = new QLabel(gridLayoutWidget_2);
        label_driveA->setObjectName(QStringLiteral("label_driveA"));
        label_driveA->setMinimumSize(QSize(45, 25));
        label_driveA->setMaximumSize(QSize(45, 25));

        trip_hori4->addWidget(label_driveA);


        trip_stats_layout->addLayout(trip_hori4, 5, 0, 1, 1);

        line_2 = new QFrame(gridLayoutWidget_2);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        trip_stats_layout->addWidget(line_2, 4, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        totalenergy_label = new QLabel(gridLayoutWidget_2);
        totalenergy_label->setObjectName(QStringLiteral("totalenergy_label"));

        horizontalLayout_4->addWidget(totalenergy_label);

        energyUse = new QLabel(gridLayoutWidget_2);
        energyUse->setObjectName(QStringLiteral("energyUse"));

        horizontalLayout_4->addWidget(energyUse);


        trip_stats_layout->addLayout(horizontalLayout_4, 10, 0, 1, 1);

        current_graph = new QWidget(trip);
        current_graph->setObjectName(QStringLiteral("current_graph"));
        current_graph->setGeometry(QRect(30, 30, 441, 241));
        current_graph->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        efficiency_graph = new QWidget(trip);
        efficiency_graph->setObjectName(QStringLiteral("efficiency_graph"));
        efficiency_graph->setGeometry(QRect(30, 290, 441, 261));
        efficiency_graph->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        home = new QWidget(centralWidget);
        home->setObjectName(QStringLiteral("home"));
        home->setGeometry(QRect(0, 0, 1280, 600));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(60);
        sizePolicy3.setHeightForWidth(home->sizePolicy().hasHeightForWidth());
        home->setSizePolicy(sizePolicy3);
        home->setMinimumSize(QSize(1280, 550));
        home->setMaximumSize(QSize(16777215, 600));
        warningIcons = new QWidget(home);
        warningIcons->setObjectName(QStringLiteral("warningIcons"));
        warningIcons->setGeometry(QRect(249, 20, 801, 100));
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

        lowBatticon = new QLabel(warningIcons);
        lowBatticon->setObjectName(QStringLiteral("lowBatticon"));
        lowBatticon->setEnabled(true);
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(50);
        sizePolicy4.setVerticalStretch(50);
        sizePolicy4.setHeightForWidth(lowBatticon->sizePolicy().hasHeightForWidth());
        lowBatticon->setSizePolicy(sizePolicy4);
        lowBatticon->setMinimumSize(QSize(75, 75));
        lowBatticon->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/images/Lowbatticon.png);"));

        WarningIcons->addWidget(lowBatticon, 5, 5, 1, 1);

        Fueldooricon = new QLabel(warningIcons);
        Fueldooricon->setObjectName(QStringLiteral("Fueldooricon"));
        Fueldooricon->setEnabled(true);
        sizePolicy.setHeightForWidth(Fueldooricon->sizePolicy().hasHeightForWidth());
        Fueldooricon->setSizePolicy(sizePolicy);
        Fueldooricon->setMinimumSize(QSize(75, 75));
        Fueldooricon->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/images/Fueldooricon.png);"));

        WarningIcons->addWidget(Fueldooricon, 5, 9, 1, 1);

        TBSicon = new QLabel(warningIcons);
        TBSicon->setObjectName(QStringLiteral("TBSicon"));
        TBSicon->setEnabled(true);
        sizePolicy.setHeightForWidth(TBSicon->sizePolicy().hasHeightForWidth());
        TBSicon->setSizePolicy(sizePolicy);
        TBSicon->setMinimumSize(QSize(75, 75));
        TBSicon->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/images/TBSicon.png);"));

        WarningIcons->addWidget(TBSicon, 5, 1, 1, 1);

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

        Safetyswitchicon = new QLabel(warningIcons);
        Safetyswitchicon->setObjectName(QStringLiteral("Safetyswitchicon"));
        Safetyswitchicon->setEnabled(true);
        sizePolicy.setHeightForWidth(Safetyswitchicon->sizePolicy().hasHeightForWidth());
        Safetyswitchicon->setSizePolicy(sizePolicy);
        Safetyswitchicon->setMinimumSize(QSize(75, 75));
        Safetyswitchicon->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/images/Safetyswitchicon.png);"));

        WarningIcons->addWidget(Safetyswitchicon, 5, 8, 1, 1);

        SeatBelticon = new QLabel(warningIcons);
        SeatBelticon->setObjectName(QStringLiteral("SeatBelticon"));
        SeatBelticon->setEnabled(true);
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(50);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(SeatBelticon->sizePolicy().hasHeightForWidth());
        SeatBelticon->setSizePolicy(sizePolicy5);
        SeatBelticon->setMinimumSize(QSize(75, 75));
        SeatBelticon->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/images/Belticon.png);"));

        WarningIcons->addWidget(SeatBelticon, 5, 3, 1, 1);

        GPSicon = new QLabel(warningIcons);
        GPSicon->setObjectName(QStringLiteral("GPSicon"));
        GPSicon->setEnabled(true);
        sizePolicy.setHeightForWidth(GPSicon->sizePolicy().hasHeightForWidth());
        GPSicon->setSizePolicy(sizePolicy);
        GPSicon->setMinimumSize(QSize(75, 75));
        GPSicon->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/images/GPSicon.png);"));

        WarningIcons->addWidget(GPSicon, 5, 0, 1, 1);

        speed = new QWidget(home);
        speed->setObjectName(QStringLiteral("speed"));
        speed->setEnabled(true);
        speed->setGeometry(QRect(540, 99, 221, 191));
        speed->setMinimumSize(QSize(150, 0));
        QFont font1;
        font1.setFamily(QStringLiteral("Latha"));
        font1.setPointSize(15);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        speed->setFont(font1);
        speed->setFocusPolicy(Qt::NoFocus);
        speed->setStyleSheet(QStringLiteral(""));
        l_speed = new QLabel(speed);
        l_speed->setObjectName(QStringLiteral("l_speed"));
        l_speed->setGeometry(QRect(0, 0, 201, 121));
        l_speed->setMinimumSize(QSize(150, 30));
        l_speed->setMaximumSize(QSize(2000, 2000));
        QFont font2;
        font2.setFamily(QStringLiteral("Lucida Console"));
        font2.setPointSize(50);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(9);
        l_speed->setFont(font2);
        l_speed->setStyleSheet(QStringLiteral("font: 75 50pt \"Lucida Console\";"));
        l_speed->setText(QStringLiteral("--"));
        l_speed->setAlignment(Qt::AlignCenter);
        label_kmh = new QLabel(speed);
        label_kmh->setObjectName(QStringLiteral("label_kmh"));
        label_kmh->setGeometry(QRect(0, 100, 200, 18));
        label_kmh->setMaximumSize(QSize(200, 100));
        label_kmh->setAlignment(Qt::AlignCenter);
        l_time = new QLabel(home);
        l_time->setObjectName(QStringLiteral("l_time"));
        l_time->setGeometry(QRect(1090, 60, 150, 25));
        l_time->setMinimumSize(QSize(150, 25));
        l_time->setMaximumSize(QSize(150, 25));
        QFont font3;
        font3.setFamily(QStringLiteral("Liberation serif"));
        font3.setPointSize(15);
        font3.setBold(true);
        font3.setItalic(false);
        font3.setWeight(75);
        l_time->setFont(font3);
        l_time->setStyleSheet(QLatin1String("font: 75 15pt \"Liberation serif\";\n"
"font-weight:bold;"));
        l_time->setText(QStringLiteral("--:--:--"));
        l_time->setAlignment(Qt::AlignCenter);
        tripInfo = new QWidget(home);
        tripInfo->setObjectName(QStringLiteral("tripInfo"));
        tripInfo->setGeometry(QRect(400, 460, 491, 111));
        gridLayoutWidget_3 = new QWidget(tripInfo);
        gridLayoutWidget_3->setObjectName(QStringLiteral("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(40, 7, 391, 91));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        val_tripDist = new QLabel(gridLayoutWidget_3);
        val_tripDist->setObjectName(QStringLiteral("val_tripDist"));
        val_tripDist->setStyleSheet(QStringLiteral("font: 75 20pt \"Lucida Console\";"));

        gridLayout_4->addWidget(val_tripDist, 0, 1, 1, 1);

        label_tripDist = new QLabel(gridLayoutWidget_3);
        label_tripDist->setObjectName(QStringLiteral("label_tripDist"));
        label_tripDist->setStyleSheet(QStringLiteral("font: 75 20pt \"Lucida Console\";"));

        gridLayout_4->addWidget(label_tripDist, 0, 0, 1, 1);

        label_tripTime = new QLabel(gridLayoutWidget_3);
        label_tripTime->setObjectName(QStringLiteral("label_tripTime"));
        label_tripTime->setStyleSheet(QStringLiteral("font: 75 20pt \"Lucida Console\";"));

        gridLayout_4->addWidget(label_tripTime, 1, 0, 1, 1);

        val_tripTime = new QLabel(gridLayoutWidget_3);
        val_tripTime->setObjectName(QStringLiteral("val_tripTime"));
        val_tripTime->setStyleSheet(QStringLiteral("font: 75 20pt \"Lucida Console\";"));

        gridLayout_4->addWidget(val_tripTime, 1, 1, 1, 1);

        label = new QLabel(gridLayoutWidget_3);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral("font: 75 20pt \"Lucida Console\";"));

        gridLayout_4->addWidget(label, 2, 0, 1, 1);

        temperature = new QLabel(gridLayoutWidget_3);
        temperature->setObjectName(QStringLiteral("temperature"));
        temperature->setStyleSheet(QStringLiteral("font: 75 20pt \"Lucida Console\";"));

        gridLayout_4->addWidget(temperature, 2, 1, 1, 1);

        graphicsView = new QGraphicsView(home);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(550, 250, 181, 191));
        graphicsView->setStyleSheet(QStringLiteral("border-image: url(:/images/REV-logo---round.png);"));
        driver_name = new QLabel(home);
        driver_name->setObjectName(QStringLiteral("driver_name"));
        driver_name->setGeometry(QRect(80, 70, 62, 16));
        progressBar_battery = new QProgressBar(home);
        progressBar_battery->setObjectName(QStringLiteral("progressBar_battery"));
        progressBar_battery->setEnabled(true);
        progressBar_battery->setGeometry(QRect(50, 200, 120, 400));
        sizePolicy.setHeightForWidth(progressBar_battery->sizePolicy().hasHeightForWidth());
        progressBar_battery->setSizePolicy(sizePolicy);
        progressBar_battery->setMinimumSize(QSize(0, 200));
        progressBar_battery->setMaximumSize(QSize(200, 400));
        QFont font4;
        font4.setFamily(QStringLiteral("Latha"));
        font4.setPointSize(20);
        font4.setBold(false);
        font4.setItalic(false);
        font4.setWeight(9);
        progressBar_battery->setFont(font4);
        progressBar_battery->setAutoFillBackground(false);
        progressBar_battery->setStyleSheet(QLatin1String("QProgressBar::chunk {\n"
"	background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(0, 200, 0), stop:1 rgb(90, 255,80));\n"
"}"));
        progressBar_battery->setMaximum(100);
        progressBar_battery->setValue(0);
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
        QFont font5;
        font5.setFamily(QStringLiteral("Lucida Console"));
        font5.setPointSize(30);
        font5.setBold(false);
        font5.setItalic(false);
        font5.setWeight(9);
        l_voltage->setFont(font5);
        l_voltage->setStyleSheet(QStringLiteral("font: 75 30pt \"Lucida Console\";"));
        l_voltage->setText(QStringLiteral("0"));
        l_voltage->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        l_voltage->setWordWrap(true);

        voltageText->addWidget(l_voltage);

        labelVoltage = new QLabel(layoutWidget1);
        labelVoltage->setObjectName(QStringLiteral("labelVoltage"));
        labelVoltage->setMinimumSize(QSize(0, 0));
        labelVoltage->setMaximumSize(QSize(300, 200));
        labelVoltage->setStyleSheet(QStringLiteral("font: 75 30pt \"Lucida Console\";"));
        labelVoltage->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        labelVoltage->setWordWrap(true);

        voltageText->addWidget(labelVoltage);

        progressBar_amps = new QProgressBar(home);
        progressBar_amps->setObjectName(QStringLiteral("progressBar_amps"));
        progressBar_amps->setGeometry(QRect(1110, 200, 120, 300));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(progressBar_amps->sizePolicy().hasHeightForWidth());
        progressBar_amps->setSizePolicy(sizePolicy6);
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
        progressBar_amps->setValue(0);
        progressBar_amps->setAlignment(Qt::AlignCenter);
        progressBar_amps->setTextVisible(false);
        progressBar_amps->setOrientation(Qt::Vertical);
        progressBar_amps->setInvertedAppearance(false);
        progressBar_amps->setTextDirection(QProgressBar::TopToBottom);
        layoutWidget2 = new QWidget(home);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(1070, 130, 191, 71));
        currentText = new QHBoxLayout(layoutWidget2);
        currentText->setObjectName(QStringLiteral("currentText"));
        currentText->setContentsMargins(0, 0, 0, 0);
        l_current = new QLabel(layoutWidget2);
        l_current->setObjectName(QStringLiteral("l_current"));
        l_current->setMinimumSize(QSize(0, 0));
        l_current->setMaximumSize(QSize(1000, 100));
        l_current->setFont(font5);
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

        horizontalLayoutWidget = new QWidget(home);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(190, 360, 131, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        l_remdist = new QLabel(horizontalLayoutWidget);
        l_remdist->setObjectName(QStringLiteral("l_remdist"));
        l_remdist->setMinimumSize(QSize(0, 0));
        l_remdist->setMaximumSize(QSize(200, 200));
        l_remdist->setFont(font5);
        l_remdist->setStyleSheet(QStringLiteral("font: 75 30pt \"Lucida Console\";"));
        l_remdist->setText(QStringLiteral("0"));
        l_remdist->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(l_remdist);

        label_KM = new QLabel(horizontalLayoutWidget);
        label_KM->setObjectName(QStringLiteral("label_KM"));
        label_KM->setMinimumSize(QSize(0, 30));
        label_KM->setMaximumSize(QSize(100, 100));
        label_KM->setFont(font5);
        label_KM->setStyleSheet(QStringLiteral("font: 75 30pt \"Lucida Console\";"));
        label_KM->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_KM);

        progressBar_ampsCharge = new QProgressBar(home);
        progressBar_ampsCharge->setObjectName(QStringLiteral("progressBar_ampsCharge"));
        progressBar_ampsCharge->setGeometry(QRect(1110, 500, 120, 100));
        sizePolicy6.setHeightForWidth(progressBar_ampsCharge->sizePolicy().hasHeightForWidth());
        progressBar_ampsCharge->setSizePolicy(sizePolicy6);
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
        tempBlack = new MapWidget(centralWidget);
        tempBlack->setObjectName(QStringLiteral("tempBlack"));
        tempBlack->setEnabled(true);
        tempBlack->setGeometry(QRect(0, 0, 1281, 601));
        tempBlack->setFocusPolicy(Qt::NoFocus);
        tempBlack->setStyleSheet(QStringLiteral("background-color: rgb(255, 0, 3);"));
        mapWidget = new MapWidget(tempBlack);
        mapWidget->setObjectName(QStringLiteral("mapWidget"));
        mapWidget->setGeometry(QRect(0, -3, 668, 454));
        mapControls = new QTransparentWidget(tempBlack);
        mapControls->setObjectName(QStringLiteral("mapControls"));
        mapControls->setGeometry(QRect(1030, 250, 249, 399));
        mapControls->setStyleSheet(QStringLiteral(""));
        verticalLayout_3 = new QVBoxLayout(mapControls);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, -1, 25, -1);
        pushButton_zoomIn = new QPushButton(mapControls);
        pushButton_zoomIn->setObjectName(QStringLiteral("pushButton_zoomIn"));
        sizePolicy6.setHeightForWidth(pushButton_zoomIn->sizePolicy().hasHeightForWidth());
        pushButton_zoomIn->setSizePolicy(sizePolicy6);
        pushButton_zoomIn->setMinimumSize(QSize(165, 25));
        pushButton_zoomIn->setMaximumSize(QSize(165, 25));
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
        sizePolicy2.setHeightForWidth(pushButton_zoomOut->sizePolicy().hasHeightForWidth());
        pushButton_zoomOut->setSizePolicy(sizePolicy2);
        pushButton_zoomOut->setMinimumSize(QSize(165, 25));
        pushButton_zoomOut->setMaximumSize(QSize(165, 25));
        pushButton_zoomOut->setStyleSheet(QStringLiteral(""));

        verticalLayout_3->addWidget(pushButton_zoomOut);

        checkBox_showComments = new QCheckBox(mapControls);
        checkBox_showComments->setObjectName(QStringLiteral("checkBox_showComments"));
        sizePolicy6.setHeightForWidth(checkBox_showComments->sizePolicy().hasHeightForWidth());
        checkBox_showComments->setSizePolicy(sizePolicy6);
        checkBox_showComments->setMinimumSize(QSize(165, 15));
        checkBox_showComments->setMaximumSize(QSize(165, 15));

        verticalLayout_3->addWidget(checkBox_showComments);

        checkBox_showTestTrack = new QCheckBox(mapControls);
        checkBox_showTestTrack->setObjectName(QStringLiteral("checkBox_showTestTrack"));
        sizePolicy6.setHeightForWidth(checkBox_showTestTrack->sizePolicy().hasHeightForWidth());
        checkBox_showTestTrack->setSizePolicy(sizePolicy6);
        checkBox_showTestTrack->setMinimumSize(QSize(165, 15));
        checkBox_showTestTrack->setMaximumSize(QSize(165, 15));

        verticalLayout_3->addWidget(checkBox_showTestTrack);

        checkBox_autoFollow = new QCheckBox(mapControls);
        checkBox_autoFollow->setObjectName(QStringLiteral("checkBox_autoFollow"));
        sizePolicy6.setHeightForWidth(checkBox_autoFollow->sizePolicy().hasHeightForWidth());
        checkBox_autoFollow->setSizePolicy(sizePolicy6);
        checkBox_autoFollow->setMinimumSize(QSize(165, 15));
        checkBox_autoFollow->setMaximumSize(QSize(165, 15));
        checkBox_autoFollow->setStyleSheet(QStringLiteral(""));
        checkBox_autoFollow->setChecked(true);

        verticalLayout_3->addWidget(checkBox_autoFollow);

        checkBox_showMyTrack = new QCheckBox(mapControls);
        checkBox_showMyTrack->setObjectName(QStringLiteral("checkBox_showMyTrack"));
        sizePolicy6.setHeightForWidth(checkBox_showMyTrack->sizePolicy().hasHeightForWidth());
        checkBox_showMyTrack->setSizePolicy(sizePolicy6);
        checkBox_showMyTrack->setMinimumSize(QSize(165, 15));
        checkBox_showMyTrack->setMaximumSize(QSize(165, 15));
        checkBox_showMyTrack->setChecked(true);

        verticalLayout_3->addWidget(checkBox_showMyTrack);

        checkBox_nightMode = new QCheckBox(mapControls);
        checkBox_nightMode->setObjectName(QStringLiteral("checkBox_nightMode"));
        sizePolicy6.setHeightForWidth(checkBox_nightMode->sizePolicy().hasHeightForWidth());
        checkBox_nightMode->setSizePolicy(sizePolicy6);
        checkBox_nightMode->setMinimumSize(QSize(165, 15));
        checkBox_nightMode->setMaximumSize(QSize(165, 15));
        checkBox_nightMode->setStyleSheet(QStringLiteral(""));

        verticalLayout_3->addWidget(checkBox_nightMode);

        pushButton_loadTrack = new QPushButton(mapControls);
        pushButton_loadTrack->setObjectName(QStringLiteral("pushButton_loadTrack"));
        sizePolicy6.setHeightForWidth(pushButton_loadTrack->sizePolicy().hasHeightForWidth());
        pushButton_loadTrack->setSizePolicy(sizePolicy6);
        pushButton_loadTrack->setMinimumSize(QSize(165, 25));
        pushButton_loadTrack->setMaximumSize(QSize(165, 25));

        verticalLayout_3->addWidget(pushButton_loadTrack);

        pushButton_deleteTrack = new QPushButton(mapControls);
        pushButton_deleteTrack->setObjectName(QStringLiteral("pushButton_deleteTrack"));

        verticalLayout_3->addWidget(pushButton_deleteTrack);

        mapContHide = new QPushButton(mapControls);
        mapContHide->setObjectName(QStringLiteral("mapContHide"));

        verticalLayout_3->addWidget(mapContHide);

        pushButton_zoomIn->raise();
        pushButton_zoomOut->raise();
        checkBox_showComments->raise();
        checkBox_showTestTrack->raise();
        checkBox_autoFollow->raise();
        checkBox_nightMode->raise();
        pushButton_loadTrack->raise();
        pushButton_deleteTrack->raise();
        checkBox_showMyTrack->raise();
        mapContHide->raise();
        map = new QWidget(centralWidget);
        map->setObjectName(QStringLiteral("map"));
        map->setGeometry(QRect(0, 0, 1280, 800));
        controls = new QWidget(map);
        controls->setObjectName(QStringLiteral("controls"));
        controls->setGeometry(QRect(750, 90, 251, 401));
        verticalLayout_4 = new QVBoxLayout(controls);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        widget = new MapWidget(map);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(210, 110, 261, 311));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(100, 170, 62, 16));
        REV_HMI->setCentralWidget(centralWidget);
        log->raise();
        menuButt->raise();
        uwaLogo->raise();
        REVlogo->raise();
        trip->raise();
        home->raise();
        music->raise();
        tempBlack->raise();
        map->raise();

        retranslateUi(REV_HMI);

        QMetaObject::connectSlotsByName(REV_HMI);
    } // setupUi

    void retranslateUi(QMainWindow *REV_HMI)
    {
        REV_HMI->setWindowTitle(QApplication::translate("REV_HMI", "MainWindow", 0));
        pushButton_clear_errors->setText(QApplication::translate("REV_HMI", "Clear Log", 0));
        checkBox_logGpsRaw->setText(QApplication::translate("REV_HMI", "GPS raw data", 0));
        checkBox_logBmsRaw->setText(QApplication::translate("REV_HMI", "BMS raw data", 0));
        pushButton_Runsound->setText(QApplication::translate("REV_HMI", "Run Eng Simu", 0));
        checkBox_GPSFile->setText(QApplication::translate("REV_HMI", "GPS File", 0));
        checkBox_BMSFile->setText(QApplication::translate("REV_HMI", "BMS File", 0));
        pushButton_defaultSettings->setText(QApplication::translate("REV_HMI", "Default Settings", 0));
        pushButton_exit->setText(QApplication::translate("REV_HMI", "Exit Program", 0));
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
        pushButton_startRecording->setText(QApplication::translate("REV_HMI", "Start", 0));
        pushButton_stopRecording->setText(QApplication::translate("REV_HMI", "Stop", 0));
        pushButton_changeRange->setText(QApplication::translate("REV_HMI", "Change max range", 0));
        label_10->setText(QApplication::translate("REV_HMI", "Elapsed", 0));
        label_4->setText(QApplication::translate("REV_HMI", "Driving", 0));
        label_54->setText(QApplication::translate("REV_HMI", "Export to:", 0));
        pushButton_location->setText(QApplication::translate("REV_HMI", "Location", 0));
        pushButton_export->setText(QApplication::translate("REV_HMI", "Export", 0));
        label_exportLocation->setText(QApplication::translate("REV_HMI", "Directory", 0));
        label_avg->setText(QApplication::translate("REV_HMI", "Avg", 0));
        label_max->setText(QApplication::translate("REV_HMI", "Max", 0));
        label_tripspeed->setText(QApplication::translate("REV_HMI", "Speed", 0));
        l_trip_speedAvgElapsed->setText(QApplication::translate("REV_HMI", "0.00", 0));
        label_speedekmh->setText(QApplication::translate("REV_HMI", "km/h", 0));
        energyRem_label->setText(QApplication::translate("REV_HMI", "Energy Remaining", 0));
        energyRem->setText(QApplication::translate("REV_HMI", "0", 0));
        pervTrip_label->setText(QApplication::translate("REV_HMI", "Previous Trip Average", 0));
        prevTrip->setText(QApplication::translate("REV_HMI", "0", 0));
        label_accel->setText(QApplication::translate("REV_HMI", "Acceleration", 0));
        label_050->setText(QApplication::translate("REV_HMI", "0 .. 50", 0));
        l_trip_Accel60->setText(QApplication::translate("REV_HMI", "0.00", 0));
        label_050s->setText(QApplication::translate("REV_HMI", "s", 0));
        trip_slabel_dist->setText(QApplication::translate("REV_HMI", "Distance", 0));
        l_trip_ncurrentAvg->setText(QApplication::translate("REV_HMI", "0.00", 0));
        l_trip_ncurrentMax->setText(QApplication::translate("REV_HMI", "0.00", 0));
        label_driveA->setText(QApplication::translate("REV_HMI", "A", 0));
        totalenergy_label->setText(QApplication::translate("REV_HMI", "Total Energy Usage", 0));
        energyUse->setText(QApplication::translate("REV_HMI", "0", 0));
        Handbrakeicon->setText(QString());
        lowBatticon->setText(QString());
        Fueldooricon->setText(QString());
        TBSicon->setText(QString());
        Neticon->setText(QString());
        CELicon->setText(QString());
        Dooricon->setText(QString());
        Safetyswitchicon->setText(QString());
        SeatBelticon->setText(QString());
        GPSicon->setText(QString());
        label_kmh->setText(QApplication::translate("REV_HMI", "km/h", 0));
        val_tripDist->setText(QApplication::translate("REV_HMI", "0.00 Km", 0));
        label_tripDist->setText(QApplication::translate("REV_HMI", "Trip Distance", 0));
        label_tripTime->setText(QApplication::translate("REV_HMI", "Trip Time", 0));
        val_tripTime->setText(QApplication::translate("REV_HMI", "00:00:00", 0));
        label->setText(QApplication::translate("REV_HMI", "Battery Temp", 0));
        temperature->setText(QApplication::translate("REV_HMI", "--", 0));
        driver_name->setText(QApplication::translate("REV_HMI", "Default Driver", 0));
        labelVoltage->setText(QApplication::translate("REV_HMI", "V", 0));
        label_KM->setText(QApplication::translate("REV_HMI", "Km", 0));
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
        label_2->setText(QApplication::translate("REV_HMI", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class REV_HMI: public Ui_REV_HMI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GETZ_HMI_H
