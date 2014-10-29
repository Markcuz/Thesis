/********************************************************************************
** Form generated from reading UI file 'getz_hmi.ui'
**
** Created by: Qt User Interface Compiler version 5.1.2
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
#include <QtWidgets/QFormLayout>
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
#include <qtransparentwidget.h>
#include "mapwidget.h"

QT_BEGIN_NAMESPACE

class Ui_REV_HMI
{
public:
    QWidget *centralWidget;
    MapWidget *map;
    MapWidget *mapWidget;
    QWidget *controls;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_8;
    QTransparentWidget *mapControls;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_zoomIn;
    QPushButton *pushButton_zoomOut;
    QCheckBox *checkBox_showComments;
    QCheckBox *checkBox_showTestTrack;
    QCheckBox *checkBox_autoFollow;
    QCheckBox *checkBox_showMyTrack;
    QCheckBox *checkBox_nightMode;
    QPushButton *pushButton_loadTrack;
    QPushButton *mapContHide;
    QWidget *traf;
    QPushButton *pushButton_updateTrafficData;
    QTransparentWidget *traffic_info;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_52;
    QLabel *label_51;
    QLabel *label_53;
    QTextBrowser *textBrowser_traffic;
    QWidget *music;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_6;
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
    QTransparentWidget *tripWidget1;
    QGridLayout *trip1;
    QLabel *label_0100s;
    QLabel *label_elapsed;
    QLabel *label_driveA;
    QFrame *line_2;
    QLabel *l_trip_ncurrentMax;
    QLabel *label_dist;
    QLabel *label_tripspeed;
    QLabel *label_currentdrive;
    QLabel *label_speeddrive;
    QFrame *line_3;
    QLabel *l_trip_ncurrentAvg;
    QLabel *label_current;
    QLabel *l_trip_Accel60;
    QLabel *label_050;
    QLabel *l_trip_Accel100;
    QLabel *label_0100;
    QLabel *label_avg;
    QLabel *l_trip_speedMax;
    QLabel *label_speedekmh;
    QLabel *label_speeddkmh;
    QLabel *l_trip_speedAvg;
    QLabel *l_trip_speedAvgElapsed;
    QLabel *label_050s;
    QLabel *label_distkm;
    QLabel *l_trip_distance;
    QLabel *label_max;
    QLabel *label_accel;
    QTransparentWidget *transparentWidgetA;
    QGridLayout *gridLayout_5;
    QVBoxLayout *verticalLayout_7;
    QSpacerItem *verticalSpacer_7;
    QLabel *editname_label;
    QTextEdit *editname;
    QSpacerItem *verticalSpacer_4;
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
    QWidget *log;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout_2;
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
    QWidget *home;
    QWidget *carInfo;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_speed;
    QLabel *l_speed;
    QLabel *label_voltage;
    QLabel *l_voltage;
    QLabel *l_time;
    QWidget *mapInfo;
    QWidget *formLayoutWidget;
    QFormLayout *gpsLayout;
    QLabel *gpsFix;
    QLabel *valFix;
    QLabel *gpsLat;
    QLabel *valLat;
    QLabel *gpsLon;
    QLabel *valLon;
    QWidget *gridLayoutWidget_2;
    QGridLayout *WarningIcons;
    QLabel *Handbrakeicon;
    QLabel *lowBatticon;
    QLabel *Dooricon;
    QLabel *SeatBelticon;
    QLabel *CELicon;
    QLabel *Neticon;
    QLabel *Fueldooricon;
    QLabel *Safetyswitchicon;
    QLabel *GPSicon;
    QLabel *TBSicon;
    QWidget *gridLayoutWidget;
    QGridLayout *batteryInfo;
    QProgressBar *progressBar_battery;
    QHBoxLayout *horizontalLayout;
    QLabel *l_remdist;
    QLabel *label_KM;
    QHBoxLayout *horizontalLayout_2;
    QLabel *l_current;
    QLabel *label_A;
    QProgressBar *progressBar_amps;
    QWidget *musicInfo;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout;
    QLabel *label_prevSong;
    QLabel *val_prevSong;
    QLabel *label_currentSong;
    QLabel *val_currentSong;
    QLabel *label_nextSong;
    QLabel *val_nextSong;
    QSlider *info_playerseekslider;
    QWidget *trafInfo;
    QTextBrowser *info_twit;
    QWidget *tripInfo;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_4;
    QLabel *val_tripDist;
    QLabel *label_tripDist;
    QLabel *label_tripTime;
    QLabel *val_tripTime;
    QGraphicsView *homeBut;
    QGraphicsView *mapBut;
    QGraphicsView *trafBut;
    QGraphicsView *musicBut;
    QGraphicsView *page7;
    QGraphicsView *optBut;
    QGraphicsView *tripBut;
    QGraphicsView *logBut;
    QWidget *logInfo;
    QTextBrowser *logSmallBrowser;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *driver_label;
    QLabel *driver_name;
    QWidget *optInfo;
    QWidget *sleep;
    QWidget *car;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *Revs;
    QLabel *l_RPM;
    QLabel *val_RPM;
    QWidget *Gearchangegauge1;
    QFrame *RPMline1;
    QWidget *Gearchangegauge2;
    QFrame *RPMline2;
    QWidget *Gearchangegauge3;
    QFrame *RPMline3;
    QWidget *Gearchangegauge4;
    QFrame *RPMline4;
    QWidget *Gearchangegauge5;
    QFrame *RPMline5;
    QLabel *gear1;
    QLabel *gear3;
    QLabel *gear5;
    QLabel *gear2;
    QLabel *gear4;
    QGraphicsView *LED1;
    QGraphicsView *LED2;
    QGraphicsView *LED3;
    QGraphicsView *LED4;
    QGraphicsView *LED5;

    void setupUi(QMainWindow *REV_HMI)
    {
        if (REV_HMI->objectName().isEmpty())
            REV_HMI->setObjectName(QStringLiteral("REV_HMI"));
        REV_HMI->resize(692, 464);
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
        centralWidget->setStyleSheet(QLatin1String("#centralWidget{\n"
"border-image: url(:/images/bg.png);\n"
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
        map = new MapWidget(centralWidget);
        map->setObjectName(QStringLiteral("map"));
        map->setEnabled(true);
        map->setGeometry(QRect(24, 10, 668, 454));
        map->setFocusPolicy(Qt::NoFocus);
        map->setStyleSheet(QLatin1String("QPushButton:focus{\n"
"color: rgb(255, 0, 4);\n"
"}\n"
"QCheckBox:focus{\n"
"background-color: rgba(255, 0, 4, 50);\n"
"}\n"
""));
        mapWidget = new MapWidget(map);
        mapWidget->setObjectName(QStringLiteral("mapWidget"));
        mapWidget->setGeometry(QRect(0, -3, 668, 454));
        controls = new QWidget(map);
        controls->setObjectName(QStringLiteral("controls"));
        controls->setGeometry(QRect(450, 10, 201, 381));
        controls->setStyleSheet(QLatin1String("#controls{\n"
"background-color: rgba(59, 59, 59, 50);\n"
"}"));
        verticalLayoutWidget_3 = new QWidget(controls);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(0, 0, 201, 381));
        verticalLayout_8 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        mapControls = new QTransparentWidget(verticalLayoutWidget_3);
        mapControls->setObjectName(QStringLiteral("mapControls"));
        mapControls->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(mapControls);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(-1, -1, 25, -1);
        pushButton_zoomIn = new QPushButton(mapControls);
        pushButton_zoomIn->setObjectName(QStringLiteral("pushButton_zoomIn"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_zoomIn->sizePolicy().hasHeightForWidth());
        pushButton_zoomIn->setSizePolicy(sizePolicy);
        pushButton_zoomIn->setMinimumSize(QSize(165, 25));
        pushButton_zoomIn->setMaximumSize(QSize(165, 25));
        QFont font;
        font.setFamily(QStringLiteral("Latha"));
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        pushButton_zoomIn->setFont(font);
        pushButton_zoomIn->setStyleSheet(QStringLiteral(""));

        verticalLayout->addWidget(pushButton_zoomIn);

        pushButton_zoomOut = new QPushButton(mapControls);
        pushButton_zoomOut->setObjectName(QStringLiteral("pushButton_zoomOut"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_zoomOut->sizePolicy().hasHeightForWidth());
        pushButton_zoomOut->setSizePolicy(sizePolicy1);
        pushButton_zoomOut->setMinimumSize(QSize(165, 25));
        pushButton_zoomOut->setMaximumSize(QSize(165, 25));
        pushButton_zoomOut->setStyleSheet(QStringLiteral(""));

        verticalLayout->addWidget(pushButton_zoomOut);

        checkBox_showComments = new QCheckBox(mapControls);
        checkBox_showComments->setObjectName(QStringLiteral("checkBox_showComments"));
        sizePolicy.setHeightForWidth(checkBox_showComments->sizePolicy().hasHeightForWidth());
        checkBox_showComments->setSizePolicy(sizePolicy);
        checkBox_showComments->setMinimumSize(QSize(165, 15));
        checkBox_showComments->setMaximumSize(QSize(165, 15));

        verticalLayout->addWidget(checkBox_showComments);

        checkBox_showTestTrack = new QCheckBox(mapControls);
        checkBox_showTestTrack->setObjectName(QStringLiteral("checkBox_showTestTrack"));
        sizePolicy.setHeightForWidth(checkBox_showTestTrack->sizePolicy().hasHeightForWidth());
        checkBox_showTestTrack->setSizePolicy(sizePolicy);
        checkBox_showTestTrack->setMinimumSize(QSize(165, 15));
        checkBox_showTestTrack->setMaximumSize(QSize(165, 15));

        verticalLayout->addWidget(checkBox_showTestTrack);

        checkBox_autoFollow = new QCheckBox(mapControls);
        checkBox_autoFollow->setObjectName(QStringLiteral("checkBox_autoFollow"));
        sizePolicy.setHeightForWidth(checkBox_autoFollow->sizePolicy().hasHeightForWidth());
        checkBox_autoFollow->setSizePolicy(sizePolicy);
        checkBox_autoFollow->setMinimumSize(QSize(165, 15));
        checkBox_autoFollow->setMaximumSize(QSize(165, 15));
        checkBox_autoFollow->setStyleSheet(QStringLiteral(""));
        checkBox_autoFollow->setChecked(true);

        verticalLayout->addWidget(checkBox_autoFollow);

        checkBox_showMyTrack = new QCheckBox(mapControls);
        checkBox_showMyTrack->setObjectName(QStringLiteral("checkBox_showMyTrack"));
        sizePolicy.setHeightForWidth(checkBox_showMyTrack->sizePolicy().hasHeightForWidth());
        checkBox_showMyTrack->setSizePolicy(sizePolicy);
        checkBox_showMyTrack->setMinimumSize(QSize(165, 15));
        checkBox_showMyTrack->setMaximumSize(QSize(165, 15));
        checkBox_showMyTrack->setChecked(true);

        verticalLayout->addWidget(checkBox_showMyTrack);

        checkBox_nightMode = new QCheckBox(mapControls);
        checkBox_nightMode->setObjectName(QStringLiteral("checkBox_nightMode"));
        sizePolicy.setHeightForWidth(checkBox_nightMode->sizePolicy().hasHeightForWidth());
        checkBox_nightMode->setSizePolicy(sizePolicy);
        checkBox_nightMode->setMinimumSize(QSize(165, 15));
        checkBox_nightMode->setMaximumSize(QSize(165, 15));
        checkBox_nightMode->setStyleSheet(QStringLiteral(""));

        verticalLayout->addWidget(checkBox_nightMode);

        pushButton_loadTrack = new QPushButton(mapControls);
        pushButton_loadTrack->setObjectName(QStringLiteral("pushButton_loadTrack"));
        sizePolicy.setHeightForWidth(pushButton_loadTrack->sizePolicy().hasHeightForWidth());
        pushButton_loadTrack->setSizePolicy(sizePolicy);
        pushButton_loadTrack->setMinimumSize(QSize(165, 25));
        pushButton_loadTrack->setMaximumSize(QSize(165, 25));

        verticalLayout->addWidget(pushButton_loadTrack);


        verticalLayout_8->addWidget(mapControls);

        mapContHide = new QPushButton(verticalLayoutWidget_3);
        mapContHide->setObjectName(QStringLiteral("mapContHide"));

        verticalLayout_8->addWidget(mapContHide);

        traf = new QWidget(centralWidget);
        traf->setObjectName(QStringLiteral("traf"));
        traf->setGeometry(QRect(24, 10, 668, 454));
        traf->setStyleSheet(QLatin1String("QPushButton:focus{\n"
"color: rgb(255, 0, 4);\n"
"}\n"
"QCheckBox:focus{\n"
"background-color: rgba(255, 0, 4, 50);\n"
"}"));
        pushButton_updateTrafficData = new QPushButton(traf);
        pushButton_updateTrafficData->setObjectName(QStringLiteral("pushButton_updateTrafficData"));
        pushButton_updateTrafficData->setGeometry(QRect(495, 150, 161, 27));
        sizePolicy.setHeightForWidth(pushButton_updateTrafficData->sizePolicy().hasHeightForWidth());
        pushButton_updateTrafficData->setSizePolicy(sizePolicy);
        pushButton_updateTrafficData->setMaximumSize(QSize(180, 30));
        traffic_info = new QTransparentWidget(traf);
        traffic_info->setObjectName(QStringLiteral("traffic_info"));
        traffic_info->setGeometry(QRect(495, 10, 161, 131));
        verticalLayout_5 = new QVBoxLayout(traffic_info);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_52 = new QLabel(traffic_info);
        label_52->setObjectName(QStringLiteral("label_52"));
        QFont font1;
        font1.setFamily(QStringLiteral("Liberation serif"));
        font1.setPointSize(15);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(9);
        label_52->setFont(font1);

        verticalLayout_5->addWidget(label_52);

        label_51 = new QLabel(traffic_info);
        label_51->setObjectName(QStringLiteral("label_51"));

        verticalLayout_5->addWidget(label_51);

        label_53 = new QLabel(traffic_info);
        label_53->setObjectName(QStringLiteral("label_53"));
        label_53->setStyleSheet(QStringLiteral("font: 10pt \"Latha\";"));
        label_53->setWordWrap(true);

        verticalLayout_5->addWidget(label_53);

        textBrowser_traffic = new QTextBrowser(traf);
        textBrowser_traffic->setObjectName(QStringLiteral("textBrowser_traffic"));
        textBrowser_traffic->setGeometry(QRect(10, 10, 481, 431));
        sizePolicy.setHeightForWidth(textBrowser_traffic->sizePolicy().hasHeightForWidth());
        textBrowser_traffic->setSizePolicy(sizePolicy);
        textBrowser_traffic->setStyleSheet(QLatin1String("font: 10pt \"Latha\";\n"
"background-color: rgba(255,255,255,100);"));
        textBrowser_traffic->setOpenLinks(false);
        music = new QWidget(centralWidget);
        music->setObjectName(QStringLiteral("music"));
        music->setGeometry(QRect(24, 10, 668, 454));
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
        layoutWidget->setGeometry(QRect(10, 40, 651, 411));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(3);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, -1, -1, -1);
        pushButton_moveUp = new QPushButton(layoutWidget);
        pushButton_moveUp->setObjectName(QStringLiteral("pushButton_moveUp"));

        verticalLayout_6->addWidget(pushButton_moveUp);

        pushButton_moveDown = new QPushButton(layoutWidget);
        pushButton_moveDown->setObjectName(QStringLiteral("pushButton_moveDown"));

        verticalLayout_6->addWidget(pushButton_moveDown);

        checkBox_repeatThis = new QCheckBox(layoutWidget);
        checkBox_repeatThis->setObjectName(QStringLiteral("checkBox_repeatThis"));

        verticalLayout_6->addWidget(checkBox_repeatThis);

        checkBox_repeatAll = new QCheckBox(layoutWidget);
        checkBox_repeatAll->setObjectName(QStringLiteral("checkBox_repeatAll"));

        verticalLayout_6->addWidget(checkBox_repeatAll);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_2);

        pushButton_addDirectory = new QPushButton(layoutWidget);
        pushButton_addDirectory->setObjectName(QStringLiteral("pushButton_addDirectory"));

        verticalLayout_6->addWidget(pushButton_addDirectory);


        gridLayout->addLayout(verticalLayout_6, 0, 2, 1, 1);

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
        layoutWidget_2->setGeometry(QRect(10, 10, 651, 23));
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
        trip->setGeometry(QRect(24, 10, 668, 454));
        trip->setStyleSheet(QLatin1String("QPushButton:focus{\n"
"color: rgb(255, 0, 4);\n"
"}\n"
"QCheckBox:focus{\n"
"background-color: rgba(255, 0, 4, 50);\n"
"}"));
        tripWidget1 = new QTransparentWidget(trip);
        tripWidget1->setObjectName(QStringLiteral("tripWidget1"));
        tripWidget1->setGeometry(QRect(10, 1, 350, 441));
        trip1 = new QGridLayout(tripWidget1);
        trip1->setObjectName(QStringLiteral("trip1"));
        trip1->setContentsMargins(-1, -1, 20, -1);
        label_0100s = new QLabel(tripWidget1);
        label_0100s->setObjectName(QStringLiteral("label_0100s"));
        label_0100s->setMinimumSize(QSize(45, 25));
        label_0100s->setMaximumSize(QSize(45, 25));

        trip1->addWidget(label_0100s, 13, 3, 1, 1);

        label_elapsed = new QLabel(tripWidget1);
        label_elapsed->setObjectName(QStringLiteral("label_elapsed"));
        label_elapsed->setMinimumSize(QSize(0, 25));
        label_elapsed->setMaximumSize(QSize(16777215, 25));
        label_elapsed->setIndent(15);

        trip1->addWidget(label_elapsed, 3, 0, 1, 1);

        label_driveA = new QLabel(tripWidget1);
        label_driveA->setObjectName(QStringLiteral("label_driveA"));
        label_driveA->setMinimumSize(QSize(45, 25));
        label_driveA->setMaximumSize(QSize(45, 25));

        trip1->addWidget(label_driveA, 8, 3, 1, 1);

        line_2 = new QFrame(tripWidget1);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        trip1->addWidget(line_2, 10, 0, 1, 4);

        l_trip_ncurrentMax = new QLabel(tripWidget1);
        l_trip_ncurrentMax->setObjectName(QStringLiteral("l_trip_ncurrentMax"));
        l_trip_ncurrentMax->setMinimumSize(QSize(75, 25));
        l_trip_ncurrentMax->setMaximumSize(QSize(75, 25));
        l_trip_ncurrentMax->setAlignment(Qt::AlignCenter);

        trip1->addWidget(l_trip_ncurrentMax, 8, 2, 1, 1);

        label_dist = new QLabel(tripWidget1);
        label_dist->setObjectName(QStringLiteral("label_dist"));
        label_dist->setMinimumSize(QSize(0, 25));
        label_dist->setMaximumSize(QSize(16777215, 25));

        trip1->addWidget(label_dist, 0, 0, 1, 1);

        label_tripspeed = new QLabel(tripWidget1);
        label_tripspeed->setObjectName(QStringLiteral("label_tripspeed"));
        label_tripspeed->setMinimumSize(QSize(0, 25));
        label_tripspeed->setMaximumSize(QSize(16777215, 25));

        trip1->addWidget(label_tripspeed, 2, 0, 1, 1);

        label_currentdrive = new QLabel(tripWidget1);
        label_currentdrive->setObjectName(QStringLiteral("label_currentdrive"));
        label_currentdrive->setMinimumSize(QSize(0, 25));
        label_currentdrive->setMaximumSize(QSize(16777215, 25));
        label_currentdrive->setFont(font1);
        label_currentdrive->setIndent(15);

        trip1->addWidget(label_currentdrive, 8, 0, 1, 1);

        label_speeddrive = new QLabel(tripWidget1);
        label_speeddrive->setObjectName(QStringLiteral("label_speeddrive"));
        label_speeddrive->setMinimumSize(QSize(0, 25));
        label_speeddrive->setMaximumSize(QSize(16777215, 25));
        label_speeddrive->setIndent(15);

        trip1->addWidget(label_speeddrive, 5, 0, 1, 1);

        line_3 = new QFrame(tripWidget1);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        trip1->addWidget(line_3, 6, 0, 1, 4);

        l_trip_ncurrentAvg = new QLabel(tripWidget1);
        l_trip_ncurrentAvg->setObjectName(QStringLiteral("l_trip_ncurrentAvg"));
        l_trip_ncurrentAvg->setMinimumSize(QSize(75, 25));
        l_trip_ncurrentAvg->setMaximumSize(QSize(75, 25));
        l_trip_ncurrentAvg->setFont(font1);
        l_trip_ncurrentAvg->setAlignment(Qt::AlignCenter);

        trip1->addWidget(l_trip_ncurrentAvg, 8, 1, 1, 1);

        label_current = new QLabel(tripWidget1);
        label_current->setObjectName(QStringLiteral("label_current"));
        label_current->setMinimumSize(QSize(0, 25));
        label_current->setMaximumSize(QSize(16777215, 25));
        label_current->setText(QStringLiteral("Current "));
        label_current->setIndent(-1);

        trip1->addWidget(label_current, 7, 0, 1, 1);

        l_trip_Accel60 = new QLabel(tripWidget1);
        l_trip_Accel60->setObjectName(QStringLiteral("l_trip_Accel60"));
        l_trip_Accel60->setMinimumSize(QSize(75, 25));
        l_trip_Accel60->setMaximumSize(QSize(75, 25));
        l_trip_Accel60->setAlignment(Qt::AlignCenter);

        trip1->addWidget(l_trip_Accel60, 12, 2, 1, 1);

        label_050 = new QLabel(tripWidget1);
        label_050->setObjectName(QStringLiteral("label_050"));
        label_050->setMinimumSize(QSize(0, 25));
        label_050->setMaximumSize(QSize(16777215, 25));
        label_050->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_050->setIndent(15);

        trip1->addWidget(label_050, 12, 0, 1, 1);

        l_trip_Accel100 = new QLabel(tripWidget1);
        l_trip_Accel100->setObjectName(QStringLiteral("l_trip_Accel100"));
        l_trip_Accel100->setMinimumSize(QSize(75, 25));
        l_trip_Accel100->setMaximumSize(QSize(75, 25));
        l_trip_Accel100->setText(QStringLiteral("0.00"));
        l_trip_Accel100->setAlignment(Qt::AlignCenter);

        trip1->addWidget(l_trip_Accel100, 13, 2, 1, 1);

        label_0100 = new QLabel(tripWidget1);
        label_0100->setObjectName(QStringLiteral("label_0100"));
        label_0100->setMinimumSize(QSize(0, 25));
        label_0100->setMaximumSize(QSize(16777215, 25));
        label_0100->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_0100->setIndent(15);

        trip1->addWidget(label_0100, 13, 0, 1, 1);

        label_avg = new QLabel(tripWidget1);
        label_avg->setObjectName(QStringLiteral("label_avg"));
        label_avg->setMinimumSize(QSize(75, 25));
        label_avg->setMaximumSize(QSize(75, 25));
        label_avg->setAlignment(Qt::AlignCenter);

        trip1->addWidget(label_avg, 1, 1, 1, 1);

        l_trip_speedMax = new QLabel(tripWidget1);
        l_trip_speedMax->setObjectName(QStringLiteral("l_trip_speedMax"));
        l_trip_speedMax->setMinimumSize(QSize(75, 25));
        l_trip_speedMax->setMaximumSize(QSize(75, 25));
        l_trip_speedMax->setText(QStringLiteral("0.00"));
        l_trip_speedMax->setAlignment(Qt::AlignCenter);

        trip1->addWidget(l_trip_speedMax, 5, 2, 1, 1);

        label_speedekmh = new QLabel(tripWidget1);
        label_speedekmh->setObjectName(QStringLiteral("label_speedekmh"));

        trip1->addWidget(label_speedekmh, 3, 3, 1, 1);

        label_speeddkmh = new QLabel(tripWidget1);
        label_speeddkmh->setObjectName(QStringLiteral("label_speeddkmh"));
        label_speeddkmh->setText(QStringLiteral("km/h"));

        trip1->addWidget(label_speeddkmh, 5, 3, 1, 1);

        l_trip_speedAvg = new QLabel(tripWidget1);
        l_trip_speedAvg->setObjectName(QStringLiteral("l_trip_speedAvg"));
        l_trip_speedAvg->setMinimumSize(QSize(75, 25));
        l_trip_speedAvg->setMaximumSize(QSize(75, 25));
        l_trip_speedAvg->setText(QStringLiteral("0.00"));
        l_trip_speedAvg->setAlignment(Qt::AlignCenter);

        trip1->addWidget(l_trip_speedAvg, 5, 1, 1, 1);

        l_trip_speedAvgElapsed = new QLabel(tripWidget1);
        l_trip_speedAvgElapsed->setObjectName(QStringLiteral("l_trip_speedAvgElapsed"));
        l_trip_speedAvgElapsed->setMinimumSize(QSize(75, 25));
        l_trip_speedAvgElapsed->setMaximumSize(QSize(75, 25));
        l_trip_speedAvgElapsed->setAlignment(Qt::AlignCenter);

        trip1->addWidget(l_trip_speedAvgElapsed, 3, 1, 1, 1);

        label_050s = new QLabel(tripWidget1);
        label_050s->setObjectName(QStringLiteral("label_050s"));
        label_050s->setMinimumSize(QSize(45, 25));
        label_050s->setMaximumSize(QSize(45, 25));

        trip1->addWidget(label_050s, 12, 3, 1, 1);

        label_distkm = new QLabel(tripWidget1);
        label_distkm->setObjectName(QStringLiteral("label_distkm"));
        label_distkm->setMinimumSize(QSize(45, 25));
        label_distkm->setMaximumSize(QSize(45, 25));
        label_distkm->setLayoutDirection(Qt::LeftToRight);
        label_distkm->setText(QStringLiteral("km"));
        label_distkm->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        trip1->addWidget(label_distkm, 0, 3, 1, 1);

        l_trip_distance = new QLabel(tripWidget1);
        l_trip_distance->setObjectName(QStringLiteral("l_trip_distance"));
        l_trip_distance->setMinimumSize(QSize(75, 25));
        l_trip_distance->setMaximumSize(QSize(75, 25));
        l_trip_distance->setText(QStringLiteral("0.00"));
        l_trip_distance->setAlignment(Qt::AlignCenter);

        trip1->addWidget(l_trip_distance, 0, 2, 1, 1);

        label_max = new QLabel(tripWidget1);
        label_max->setObjectName(QStringLiteral("label_max"));
        label_max->setMinimumSize(QSize(75, 25));
        label_max->setMaximumSize(QSize(75, 25));
        label_max->setAlignment(Qt::AlignCenter);
        label_max->setIndent(15);

        trip1->addWidget(label_max, 1, 2, 1, 1);

        label_accel = new QLabel(tripWidget1);
        label_accel->setObjectName(QStringLiteral("label_accel"));
        label_accel->setMinimumSize(QSize(0, 25));
        label_accel->setMaximumSize(QSize(16777215, 25));

        trip1->addWidget(label_accel, 11, 0, 1, 2);

        transparentWidgetA = new QTransparentWidget(trip);
        transparentWidgetA->setObjectName(QStringLiteral("transparentWidgetA"));
        transparentWidgetA->setGeometry(QRect(470, 1, 191, 441));
        gridLayout_5 = new QGridLayout(transparentWidgetA);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setVerticalSpacing(5);
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(10);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(10, -1, 10, -1);
        verticalSpacer_7 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_7);

        editname_label = new QLabel(transparentWidgetA);
        editname_label->setObjectName(QStringLiteral("editname_label"));
        editname_label->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(editname_label);

        editname = new QTextEdit(transparentWidgetA);
        editname->setObjectName(QStringLiteral("editname"));
        editname->setMaximumSize(QSize(16777215, 30));

        verticalLayout_7->addWidget(editname);

        verticalSpacer_4 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_4);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        pushButton_startRecording = new QPushButton(transparentWidgetA);
        pushButton_startRecording->setObjectName(QStringLiteral("pushButton_startRecording"));
        sizePolicy1.setHeightForWidth(pushButton_startRecording->sizePolicy().hasHeightForWidth());
        pushButton_startRecording->setSizePolicy(sizePolicy1);
        pushButton_startRecording->setMinimumSize(QSize(80, 25));
        pushButton_startRecording->setMaximumSize(QSize(80, 25));

        gridLayout_6->addWidget(pushButton_startRecording, 1, 0, 1, 1);

        pushButton_stopRecording = new QPushButton(transparentWidgetA);
        pushButton_stopRecording->setObjectName(QStringLiteral("pushButton_stopRecording"));
        sizePolicy1.setHeightForWidth(pushButton_stopRecording->sizePolicy().hasHeightForWidth());
        pushButton_stopRecording->setSizePolicy(sizePolicy1);
        pushButton_stopRecording->setMinimumSize(QSize(80, 25));
        pushButton_stopRecording->setMaximumSize(QSize(80, 25));

        gridLayout_6->addWidget(pushButton_stopRecording, 1, 1, 1, 1);


        verticalLayout_7->addLayout(gridLayout_6);

        pushButton_changeRange = new QPushButton(transparentWidgetA);
        pushButton_changeRange->setObjectName(QStringLiteral("pushButton_changeRange"));

        verticalLayout_7->addWidget(pushButton_changeRange);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_6);

        label_10 = new QLabel(transparentWidgetA);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font1);
        label_10->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_10);

        l_trip_time = new QLabel(transparentWidgetA);
        l_trip_time->setObjectName(QStringLiteral("l_trip_time"));
        l_trip_time->setText(QStringLiteral("00:00:00"));
        l_trip_time->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(l_trip_time);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_3);

        label_4 = new QLabel(transparentWidgetA);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_4);

        l_drive_time = new QLabel(transparentWidgetA);
        l_drive_time->setObjectName(QStringLiteral("l_drive_time"));
        l_drive_time->setText(QStringLiteral("00:00:00"));
        l_drive_time->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(l_drive_time);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_5);

        label_54 = new QLabel(transparentWidgetA);
        label_54->setObjectName(QStringLiteral("label_54"));
        label_54->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_54);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        pushButton_location = new QPushButton(transparentWidgetA);
        pushButton_location->setObjectName(QStringLiteral("pushButton_location"));
        pushButton_location->setMinimumSize(QSize(0, 25));
        pushButton_location->setMaximumSize(QSize(80, 25));

        gridLayout_7->addWidget(pushButton_location, 1, 0, 1, 1);

        pushButton_export = new QPushButton(transparentWidgetA);
        pushButton_export->setObjectName(QStringLiteral("pushButton_export"));
        pushButton_export->setMinimumSize(QSize(0, 25));
        pushButton_export->setMaximumSize(QSize(80, 25));

        gridLayout_7->addWidget(pushButton_export, 1, 1, 1, 1);


        verticalLayout_7->addLayout(gridLayout_7);

        label_exportLocation = new QLabel(transparentWidgetA);
        label_exportLocation->setObjectName(QStringLiteral("label_exportLocation"));
        label_exportLocation->setStyleSheet(QLatin1String("QLabel{\n"
"font: 75 10pt \"Liberation serif\";\n"
"}"));
        label_exportLocation->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout_7->addWidget(label_exportLocation);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer);


        gridLayout_5->addLayout(verticalLayout_7, 0, 0, 1, 1);

        log = new QWidget(centralWidget);
        log->setObjectName(QStringLiteral("log"));
        log->setGeometry(QRect(24, 10, 668, 454));
        log->setStyleSheet(QLatin1String("QPushButton:focus{\n"
"color: rgb(255, 0, 4);\n"
"}\n"
"QCheckBox:focus{\n"
"background-color: rgba(255, 0, 4, 50);\n"
"}"));
        layoutWidget_3 = new QWidget(log);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(520, 10, 156, 421));
        verticalLayout_2 = new QVBoxLayout(layoutWidget_3);
        verticalLayout_2->setSpacing(3);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(10, 0, 10, 0);
        pushButton_clear_errors = new QPushButton(layoutWidget_3);
        pushButton_clear_errors->setObjectName(QStringLiteral("pushButton_clear_errors"));

        verticalLayout_2->addWidget(pushButton_clear_errors);

        checkBox_logGpsRaw = new QCheckBox(layoutWidget_3);
        checkBox_logGpsRaw->setObjectName(QStringLiteral("checkBox_logGpsRaw"));

        verticalLayout_2->addWidget(checkBox_logGpsRaw);

        checkBox_logBmsRaw = new QCheckBox(layoutWidget_3);
        checkBox_logBmsRaw->setObjectName(QStringLiteral("checkBox_logBmsRaw"));

        verticalLayout_2->addWidget(checkBox_logBmsRaw);

        pushButton_Runsound = new QPushButton(layoutWidget_3);
        pushButton_Runsound->setObjectName(QStringLiteral("pushButton_Runsound"));

        verticalLayout_2->addWidget(pushButton_Runsound);

        horizontalSlider = new QSlider(layoutWidget_3);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(horizontalSlider->sizePolicy().hasHeightForWidth());
        horizontalSlider->setSizePolicy(sizePolicy2);
        horizontalSlider->setFocusPolicy(Qt::NoFocus);
        horizontalSlider->setMaximum(100);
        horizontalSlider->setValue(50);
        horizontalSlider->setSliderPosition(50);
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(horizontalSlider);

        checkBox_GPSFile = new QCheckBox(layoutWidget_3);
        checkBox_GPSFile->setObjectName(QStringLiteral("checkBox_GPSFile"));

        verticalLayout_2->addWidget(checkBox_GPSFile);

        checkBox_BMSFile = new QCheckBox(layoutWidget_3);
        checkBox_BMSFile->setObjectName(QStringLiteral("checkBox_BMSFile"));

        verticalLayout_2->addWidget(checkBox_BMSFile);

        pushButton_defaultSettings = new QPushButton(layoutWidget_3);
        pushButton_defaultSettings->setObjectName(QStringLiteral("pushButton_defaultSettings"));

        verticalLayout_2->addWidget(pushButton_defaultSettings);

        pushButton_exit = new QPushButton(layoutWidget_3);
        pushButton_exit->setObjectName(QStringLiteral("pushButton_exit"));

        verticalLayout_2->addWidget(pushButton_exit);

        textBrowser_errors = new QTextBrowser(log);
        textBrowser_errors->setObjectName(QStringLiteral("textBrowser_errors"));
        textBrowser_errors->setGeometry(QRect(10, 10, 511, 421));
        textBrowser_errors->setFocusPolicy(Qt::NoFocus);
        textBrowser_errors->setStyleSheet(QLatin1String("font: 10pt \"Lucida Console\";\n"
"background-color: rgb(212, 212, 212);"));
        home = new QWidget(centralWidget);
        home->setObjectName(QStringLiteral("home"));
        home->setGeometry(QRect(24, 10, 666, 454));
        home->setStyleSheet(QStringLiteral(""));
        carInfo = new QWidget(home);
        carInfo->setObjectName(QStringLiteral("carInfo"));
        carInfo->setEnabled(true);
        carInfo->setGeometry(QRect(280, 80, 150, 271));
        carInfo->setMinimumSize(QSize(150, 0));
        QFont font2;
        font2.setFamily(QStringLiteral("Latha"));
        font2.setPointSize(15);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        carInfo->setFont(font2);
        carInfo->setFocusPolicy(Qt::NoFocus);
        carInfo->setStyleSheet(QStringLiteral(""));
        gridLayout_2 = new QGridLayout(carInfo);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(0);
        gridLayout_2->setVerticalSpacing(10);
        gridLayout_2->setContentsMargins(0, 10, 5, 5);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(10);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_speed = new QLabel(carInfo);
        label_speed->setObjectName(QStringLiteral("label_speed"));
        label_speed->setMinimumSize(QSize(150, 20));
        label_speed->setMaximumSize(QSize(150, 20));
        label_speed->setStyleSheet(QStringLiteral(""));
        label_speed->setAlignment(Qt::AlignCenter);
        label_speed->setWordWrap(true);

        verticalLayout_3->addWidget(label_speed);

        l_speed = new QLabel(carInfo);
        l_speed->setObjectName(QStringLiteral("l_speed"));
        l_speed->setMinimumSize(QSize(150, 30));
        l_speed->setMaximumSize(QSize(150, 30));
        QFont font3;
        font3.setFamily(QStringLiteral("Lucida Console"));
        font3.setPointSize(24);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(9);
        l_speed->setFont(font3);
        l_speed->setStyleSheet(QStringLiteral("font: 75 24pt \"Lucida Console\";"));
        l_speed->setText(QStringLiteral("--"));
        l_speed->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(l_speed);

        label_voltage = new QLabel(carInfo);
        label_voltage->setObjectName(QStringLiteral("label_voltage"));
        label_voltage->setMinimumSize(QSize(150, 50));
        label_voltage->setMaximumSize(QSize(150, 50));
        label_voltage->setFont(font1);
        label_voltage->setScaledContents(true);
        label_voltage->setAlignment(Qt::AlignCenter);
        label_voltage->setWordWrap(true);

        verticalLayout_3->addWidget(label_voltage);

        l_voltage = new QLabel(carInfo);
        l_voltage->setObjectName(QStringLiteral("l_voltage"));
        l_voltage->setMinimumSize(QSize(150, 30));
        l_voltage->setMaximumSize(QSize(150, 30));
        l_voltage->setStyleSheet(QStringLiteral("font: 75 24pt \"Lucida Console\";"));
        l_voltage->setText(QStringLiteral("--"));
        l_voltage->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(l_voltage);

        l_time = new QLabel(carInfo);
        l_time->setObjectName(QStringLiteral("l_time"));
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

        verticalLayout_3->addWidget(l_time);


        gridLayout_2->addLayout(verticalLayout_3, 0, 0, 1, 1);

        mapInfo = new QWidget(home);
        mapInfo->setObjectName(QStringLiteral("mapInfo"));
        mapInfo->setGeometry(QRect(250, 160, 221, 111));
        mapInfo->setStyleSheet(QLatin1String("#mapInfo{\n"
"opacity:0;\n"
"}"));
        formLayoutWidget = new QWidget(mapInfo);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(0, 0, 221, 131));
        gpsLayout = new QFormLayout(formLayoutWidget);
        gpsLayout->setObjectName(QStringLiteral("gpsLayout"));
        gpsLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gpsLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        gpsLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        gpsLayout->setFormAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        gpsLayout->setVerticalSpacing(15);
        gpsLayout->setContentsMargins(0, 0, 0, 0);
        gpsFix = new QLabel(formLayoutWidget);
        gpsFix->setObjectName(QStringLiteral("gpsFix"));

        gpsLayout->setWidget(0, QFormLayout::LabelRole, gpsFix);

        valFix = new QLabel(formLayoutWidget);
        valFix->setObjectName(QStringLiteral("valFix"));
        valFix->setAlignment(Qt::AlignCenter);

        gpsLayout->setWidget(0, QFormLayout::FieldRole, valFix);

        gpsLat = new QLabel(formLayoutWidget);
        gpsLat->setObjectName(QStringLiteral("gpsLat"));

        gpsLayout->setWidget(1, QFormLayout::LabelRole, gpsLat);

        valLat = new QLabel(formLayoutWidget);
        valLat->setObjectName(QStringLiteral("valLat"));
        valLat->setAlignment(Qt::AlignCenter);

        gpsLayout->setWidget(1, QFormLayout::FieldRole, valLat);

        gpsLon = new QLabel(formLayoutWidget);
        gpsLon->setObjectName(QStringLiteral("gpsLon"));

        gpsLayout->setWidget(2, QFormLayout::LabelRole, gpsLon);

        valLon = new QLabel(formLayoutWidget);
        valLon->setObjectName(QStringLiteral("valLon"));
        valLon->setAlignment(Qt::AlignCenter);

        gpsLayout->setWidget(2, QFormLayout::FieldRole, valLon);

        gridLayoutWidget_2 = new QWidget(home);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(550, 70, 111, 281));
        WarningIcons = new QGridLayout(gridLayoutWidget_2);
        WarningIcons->setObjectName(QStringLiteral("WarningIcons"));
        WarningIcons->setContentsMargins(0, 0, 0, 0);
        Handbrakeicon = new QLabel(gridLayoutWidget_2);
        Handbrakeicon->setObjectName(QStringLiteral("Handbrakeicon"));
        Handbrakeicon->setEnabled(true);
        Handbrakeicon->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/images/Handbrakeicon.png);"));

        WarningIcons->addWidget(Handbrakeicon, 3, 0, 1, 1);

        lowBatticon = new QLabel(gridLayoutWidget_2);
        lowBatticon->setObjectName(QStringLiteral("lowBatticon"));
        lowBatticon->setEnabled(true);
        lowBatticon->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/images/Lowbatticon.png);"));

        WarningIcons->addWidget(lowBatticon, 3, 1, 1, 1);

        Dooricon = new QLabel(gridLayoutWidget_2);
        Dooricon->setObjectName(QStringLiteral("Dooricon"));
        Dooricon->setEnabled(true);
        Dooricon->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/images/Dooricon.png);"));

        WarningIcons->addWidget(Dooricon, 2, 0, 1, 1);

        SeatBelticon = new QLabel(gridLayoutWidget_2);
        SeatBelticon->setObjectName(QStringLiteral("SeatBelticon"));
        SeatBelticon->setEnabled(true);
        SeatBelticon->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/images/Belticon.png);"));

        WarningIcons->addWidget(SeatBelticon, 2, 1, 1, 1);

        CELicon = new QLabel(gridLayoutWidget_2);
        CELicon->setObjectName(QStringLiteral("CELicon"));
        CELicon->setEnabled(true);
        CELicon->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/images/CELicon.png);"));

        WarningIcons->addWidget(CELicon, 4, 0, 1, 1);

        Neticon = new QLabel(gridLayoutWidget_2);
        Neticon->setObjectName(QStringLiteral("Neticon"));
        Neticon->setEnabled(true);
        Neticon->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/images/3Gicon.png);"));

        WarningIcons->addWidget(Neticon, 4, 1, 1, 1);

        Fueldooricon = new QLabel(gridLayoutWidget_2);
        Fueldooricon->setObjectName(QStringLiteral("Fueldooricon"));
        Fueldooricon->setEnabled(true);
        Fueldooricon->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/images/Fueldooricon.png);"));

        WarningIcons->addWidget(Fueldooricon, 5, 1, 1, 1);

        Safetyswitchicon = new QLabel(gridLayoutWidget_2);
        Safetyswitchicon->setObjectName(QStringLiteral("Safetyswitchicon"));
        Safetyswitchicon->setEnabled(true);
        Safetyswitchicon->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/images/Safetyswitchicon.png);"));

        WarningIcons->addWidget(Safetyswitchicon, 5, 0, 1, 1);

        GPSicon = new QLabel(gridLayoutWidget_2);
        GPSicon->setObjectName(QStringLiteral("GPSicon"));
        GPSicon->setEnabled(true);
        GPSicon->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/images/GPSicon.png);"));

        WarningIcons->addWidget(GPSicon, 1, 0, 1, 1);

        TBSicon = new QLabel(gridLayoutWidget_2);
        TBSicon->setObjectName(QStringLiteral("TBSicon"));
        TBSicon->setEnabled(true);
        TBSicon->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/images/TBSicon.png);"));

        WarningIcons->addWidget(TBSicon, 1, 1, 1, 1);

        gridLayoutWidget = new QWidget(home);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 40, 161, 361));
        batteryInfo = new QGridLayout(gridLayoutWidget);
        batteryInfo->setObjectName(QStringLiteral("batteryInfo"));
        batteryInfo->setContentsMargins(0, 0, 0, 0);
        progressBar_battery = new QProgressBar(gridLayoutWidget);
        progressBar_battery->setObjectName(QStringLiteral("progressBar_battery"));
        progressBar_battery->setEnabled(true);
        sizePolicy.setHeightForWidth(progressBar_battery->sizePolicy().hasHeightForWidth());
        progressBar_battery->setSizePolicy(sizePolicy);
        QFont font5;
        font5.setFamily(QStringLiteral("Latha"));
        font5.setPointSize(20);
        font5.setBold(false);
        font5.setItalic(false);
        font5.setWeight(9);
        progressBar_battery->setFont(font5);
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

        batteryInfo->addWidget(progressBar_battery, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        l_remdist = new QLabel(gridLayoutWidget);
        l_remdist->setObjectName(QStringLiteral("l_remdist"));
        l_remdist->setMinimumSize(QSize(40, 30));
        l_remdist->setMaximumSize(QSize(40, 30));
        l_remdist->setFont(font1);
        l_remdist->setStyleSheet(QStringLiteral(""));
        l_remdist->setText(QStringLiteral("0"));
        l_remdist->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(l_remdist);

        label_KM = new QLabel(gridLayoutWidget);
        label_KM->setObjectName(QStringLiteral("label_KM"));
        label_KM->setMinimumSize(QSize(0, 30));
        label_KM->setMaximumSize(QSize(30, 30));
        label_KM->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_KM);


        batteryInfo->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        l_current = new QLabel(gridLayoutWidget);
        l_current->setObjectName(QStringLiteral("l_current"));
        l_current->setMinimumSize(QSize(40, 30));
        l_current->setMaximumSize(QSize(40, 30));
        l_current->setFont(font1);
        l_current->setStyleSheet(QStringLiteral(""));
        l_current->setText(QStringLiteral("0"));
        l_current->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(l_current);

        label_A = new QLabel(gridLayoutWidget);
        label_A->setObjectName(QStringLiteral("label_A"));
        label_A->setMinimumSize(QSize(30, 30));
        label_A->setMaximumSize(QSize(30, 30));
        label_A->setText(QStringLiteral("[A]"));
        label_A->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_A);


        batteryInfo->addLayout(horizontalLayout_2, 1, 1, 1, 1);

        progressBar_amps = new QProgressBar(gridLayoutWidget);
        progressBar_amps->setObjectName(QStringLiteral("progressBar_amps"));
        sizePolicy.setHeightForWidth(progressBar_amps->sizePolicy().hasHeightForWidth());
        progressBar_amps->setSizePolicy(sizePolicy);
        progressBar_amps->setMinimumSize(QSize(50, 300));
        progressBar_amps->setMaximumSize(QSize(50, 300));
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

        batteryInfo->addWidget(progressBar_amps, 2, 1, 1, 1);

        musicInfo = new QWidget(home);
        musicInfo->setObjectName(QStringLiteral("musicInfo"));
        musicInfo->setGeometry(QRect(230, 160, 251, 121));
        musicInfo->setStyleSheet(QStringLiteral("font: 75 12pt \"Liberation serif\";"));
        formLayoutWidget_2 = new QWidget(musicInfo);
        formLayoutWidget_2->setObjectName(QStringLiteral("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(10, 0, 241, 119));
        formLayout = new QFormLayout(formLayoutWidget_2);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        formLayout->setFormAlignment(Qt::AlignHCenter|Qt::AlignTop);
        formLayout->setVerticalSpacing(15);
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_prevSong = new QLabel(formLayoutWidget_2);
        label_prevSong->setObjectName(QStringLiteral("label_prevSong"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_prevSong);

        val_prevSong = new QLabel(formLayoutWidget_2);
        val_prevSong->setObjectName(QStringLiteral("val_prevSong"));
        val_prevSong->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(0, QFormLayout::FieldRole, val_prevSong);

        label_currentSong = new QLabel(formLayoutWidget_2);
        label_currentSong->setObjectName(QStringLiteral("label_currentSong"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_currentSong);

        val_currentSong = new QLabel(formLayoutWidget_2);
        val_currentSong->setObjectName(QStringLiteral("val_currentSong"));
        val_currentSong->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(1, QFormLayout::FieldRole, val_currentSong);

        label_nextSong = new QLabel(formLayoutWidget_2);
        label_nextSong->setObjectName(QStringLiteral("label_nextSong"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_nextSong);

        val_nextSong = new QLabel(formLayoutWidget_2);
        val_nextSong->setObjectName(QStringLiteral("val_nextSong"));
        val_nextSong->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(2, QFormLayout::FieldRole, val_nextSong);

        info_playerseekslider = new QSlider(musicInfo);
        info_playerseekslider->setObjectName(QStringLiteral("info_playerseekslider"));
        info_playerseekslider->setGeometry(QRect(0, 100, 251, 20));
        info_playerseekslider->setFocusPolicy(Qt::NoFocus);
        info_playerseekslider->setOrientation(Qt::Horizontal);
        trafInfo = new QWidget(home);
        trafInfo->setObjectName(QStringLiteral("trafInfo"));
        trafInfo->setGeometry(QRect(240, 150, 231, 151));
        info_twit = new QTextBrowser(trafInfo);
        info_twit->setObjectName(QStringLiteral("info_twit"));
        info_twit->setGeometry(QRect(10, 0, 221, 151));
        info_twit->setFocusPolicy(Qt::NoFocus);
        info_twit->setStyleSheet(QLatin1String("font: 10pt \"Latha\";\n"
"background-color: rgba(255,255,255,100);"));
        info_twit->setOpenLinks(false);
        tripInfo = new QWidget(home);
        tripInfo->setObjectName(QStringLiteral("tripInfo"));
        tripInfo->setGeometry(QRect(230, 160, 251, 121));
        gridLayoutWidget_3 = new QWidget(tripInfo);
        gridLayoutWidget_3->setObjectName(QStringLiteral("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(10, 0, 241, 121));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        val_tripDist = new QLabel(gridLayoutWidget_3);
        val_tripDist->setObjectName(QStringLiteral("val_tripDist"));

        gridLayout_4->addWidget(val_tripDist, 0, 1, 1, 1);

        label_tripDist = new QLabel(gridLayoutWidget_3);
        label_tripDist->setObjectName(QStringLiteral("label_tripDist"));

        gridLayout_4->addWidget(label_tripDist, 0, 0, 1, 1);

        label_tripTime = new QLabel(gridLayoutWidget_3);
        label_tripTime->setObjectName(QStringLiteral("label_tripTime"));

        gridLayout_4->addWidget(label_tripTime, 1, 0, 1, 1);

        val_tripTime = new QLabel(gridLayoutWidget_3);
        val_tripTime->setObjectName(QStringLiteral("val_tripTime"));

        gridLayout_4->addWidget(val_tripTime, 1, 1, 1, 1);

        homeBut = new QGraphicsView(home);
        homeBut->setObjectName(QStringLiteral("homeBut"));
        homeBut->setGeometry(QRect(220, 30, 148, 94));
        homeBut->setFocusPolicy(Qt::NoFocus);
        homeBut->setStyleSheet(QLatin1String("#homeBut:focus{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/Buttons/TLs.png);\n"
"}\n"
"#homeBut{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/Buttons/TL.png);\n"
"}\n"
""));
        homeBut->setFrameShape(QFrame::NoFrame);
        mapBut = new QGraphicsView(home);
        mapBut->setObjectName(QStringLiteral("mapBut"));
        mapBut->setGeometry(QRect(343, 30, 148, 94));
        mapBut->setFocusPolicy(Qt::NoFocus);
        mapBut->setStyleSheet(QLatin1String("#mapBut:focus{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/Buttons/TRs.png);\n"
"}\n"
"#mapBut{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/Buttons/TR.png);\n"
"}"));
        mapBut->setFrameShape(QFrame::NoFrame);
        trafBut = new QGraphicsView(home);
        trafBut->setObjectName(QStringLiteral("trafBut"));
        trafBut->setGeometry(QRect(449, 83, 89, 141));
        QFont font6;
        font6.setKerning(true);
        trafBut->setFont(font6);
        trafBut->setFocusPolicy(Qt::NoFocus);
        trafBut->setStyleSheet(QLatin1String("#trafBut:focus{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/Buttons/R1s.png);\n"
"}\n"
"#trafBut{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/Buttons/R1.png);\n"
"}"));
        trafBut->setFrameShape(QFrame::NoFrame);
        musicBut = new QGraphicsView(home);
        musicBut->setObjectName(QStringLiteral("musicBut"));
        musicBut->setGeometry(QRect(447, 208, 89, 141));
        musicBut->setFocusPolicy(Qt::NoFocus);
        musicBut->setStyleSheet(QLatin1String("#musicBut:focus{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/Buttons/R2s.png);\n"
"}\n"
"#musicBut{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/Buttons/R2.png);\n"
"}"));
        musicBut->setFrameShape(QFrame::NoFrame);
        page7 = new QGraphicsView(home);
        page7->setObjectName(QStringLiteral("page7"));
        page7->setGeometry(QRect(344, 306, 148, 94));
        page7->setFocusPolicy(Qt::NoFocus);
        page7->setStyleSheet(QLatin1String("#page7:focus{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/Buttons/BR.png);\n"
"}\n"
"#page7{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/Buttons/BR.png);\n"
"}"));
        page7->setFrameShape(QFrame::NoFrame);
        optBut = new QGraphicsView(home);
        optBut->setObjectName(QStringLiteral("optBut"));
        optBut->setGeometry(QRect(219, 306, 148, 94));
        optBut->setFocusPolicy(Qt::NoFocus);
        optBut->setStyleSheet(QLatin1String("#optBut:focus{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/Buttons/BLs.png);\n"
"}\n"
"#optBut{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/Buttons/BL.png);\n"
"}"));
        optBut->setFrameShape(QFrame::NoFrame);
        tripBut = new QGraphicsView(home);
        tripBut->setObjectName(QStringLiteral("tripBut"));
        tripBut->setGeometry(QRect(172, 208, 89, 141));
        tripBut->setFocusPolicy(Qt::NoFocus);
        tripBut->setStyleSheet(QLatin1String("#tripBut:focus{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/Buttons/L2s.png);\n"
"}\n"
"#tripBut{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/Buttons/L2.png);\n"
"}"));
        tripBut->setFrameShape(QFrame::NoFrame);
        logBut = new QGraphicsView(home);
        logBut->setObjectName(QStringLiteral("logBut"));
        logBut->setGeometry(QRect(172, 83, 89, 141));
        logBut->setFocusPolicy(Qt::NoFocus);
        logBut->setStyleSheet(QLatin1String("#logBut:focus{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/Buttons/L1s.png);\n"
"}\n"
"#logBut{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/Buttons/L1.png);\n"
"}"));
        logBut->setFrameShape(QFrame::NoFrame);
        logInfo = new QWidget(home);
        logInfo->setObjectName(QStringLiteral("logInfo"));
        logInfo->setGeometry(QRect(230, 130, 231, 171));
        logSmallBrowser = new QTextBrowser(logInfo);
        logSmallBrowser->setObjectName(QStringLiteral("logSmallBrowser"));
        logSmallBrowser->setGeometry(QRect(20, 0, 211, 171));
        horizontalLayoutWidget_2 = new QWidget(home);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 420, 341, 31));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        driver_label = new QLabel(horizontalLayoutWidget_2);
        driver_label->setObjectName(QStringLiteral("driver_label"));
        driver_label->setMaximumSize(QSize(65, 16777215));

        horizontalLayout_3->addWidget(driver_label);

        driver_name = new QLabel(horizontalLayoutWidget_2);
        driver_name->setObjectName(QStringLiteral("driver_name"));

        horizontalLayout_3->addWidget(driver_name);

        optInfo = new QWidget(home);
        optInfo->setObjectName(QStringLiteral("optInfo"));
        optInfo->setGeometry(QRect(320, 120, 120, 80));
        gridLayoutWidget_2->raise();
        gridLayoutWidget->raise();
        mapInfo->raise();
        musicInfo->raise();
        trafInfo->raise();
        carInfo->raise();
        homeBut->raise();
        mapBut->raise();
        trafBut->raise();
        musicBut->raise();
        page7->raise();
        optBut->raise();
        tripBut->raise();
        logBut->raise();
        logInfo->raise();
        tripInfo->raise();
        horizontalLayoutWidget_2->raise();
        optInfo->raise();
        sleep = new QWidget(centralWidget);
        sleep->setObjectName(QStringLiteral("sleep"));
        sleep->setEnabled(true);
        sleep->setGeometry(QRect(24, 10, 668, 454));
        sleep->setStyleSheet(QStringLiteral("background-color: rgb(0,0,0);"));
        car = new QWidget(centralWidget);
        car->setObjectName(QStringLiteral("car"));
        car->setGeometry(QRect(24, 10, 668, 454));
        horizontalLayoutWidget = new QWidget(car);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(250, 200, 171, 61));
        Revs = new QHBoxLayout(horizontalLayoutWidget);
        Revs->setObjectName(QStringLiteral("Revs"));
        Revs->setContentsMargins(0, 0, 0, 0);
        l_RPM = new QLabel(horizontalLayoutWidget);
        l_RPM->setObjectName(QStringLiteral("l_RPM"));
        l_RPM->setStyleSheet(QStringLiteral("font: 75 17pt \"Liberation serif\";"));

        Revs->addWidget(l_RPM);

        val_RPM = new QLabel(horizontalLayoutWidget);
        val_RPM->setObjectName(QStringLiteral("val_RPM"));
        val_RPM->setStyleSheet(QStringLiteral("font: 75 17pt \"Liberation serif\";"));

        Revs->addWidget(val_RPM);

        Gearchangegauge1 = new QWidget(car);
        Gearchangegauge1->setObjectName(QStringLiteral("Gearchangegauge1"));
        Gearchangegauge1->setGeometry(QRect(20, 110, 200, 40));
        Gearchangegauge1->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:reflect, x1:0.49995, y1:0, x2:1, y2:0, stop:0 rgba(85, 248, 33, 255), stop:0.212871 rgba(205, 251, 32, 255), stop:0.712871 rgba(255, 40, 40, 255));"));
        RPMline1 = new QFrame(Gearchangegauge1);
        RPMline1->setObjectName(QStringLiteral("RPMline1"));
        RPMline1->setGeometry(QRect(100, 0, 5, 40));
        RPMline1->setFrameShape(QFrame::VLine);
        RPMline1->setFrameShadow(QFrame::Sunken);
        Gearchangegauge2 = new QWidget(car);
        Gearchangegauge2->setObjectName(QStringLiteral("Gearchangegauge2"));
        Gearchangegauge2->setGeometry(QRect(20, 330, 200, 40));
        Gearchangegauge2->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:reflect, x1:0.49995, y1:0, x2:1, y2:0, stop:0 rgba(85, 248, 33, 255), stop:0.212871 rgba(205, 251, 32, 255), stop:0.712871 rgba(255, 40, 40, 255));"));
        RPMline2 = new QFrame(Gearchangegauge2);
        RPMline2->setObjectName(QStringLiteral("RPMline2"));
        RPMline2->setGeometry(QRect(100, 0, 5, 40));
        RPMline2->setFrameShape(QFrame::VLine);
        RPMline2->setFrameShadow(QFrame::Sunken);
        Gearchangegauge3 = new QWidget(car);
        Gearchangegauge3->setObjectName(QStringLiteral("Gearchangegauge3"));
        Gearchangegauge3->setGeometry(QRect(240, 110, 200, 40));
        Gearchangegauge3->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:reflect, x1:0.49995, y1:0, x2:1, y2:0, stop:0 rgba(85, 248, 33, 255), stop:0.212871 rgba(205, 251, 32, 255), stop:0.712871 rgba(255, 40, 40, 255));"));
        RPMline3 = new QFrame(Gearchangegauge3);
        RPMline3->setObjectName(QStringLiteral("RPMline3"));
        RPMline3->setGeometry(QRect(100, 0, 5, 40));
        RPMline3->setFrameShape(QFrame::VLine);
        RPMline3->setFrameShadow(QFrame::Sunken);
        Gearchangegauge4 = new QWidget(car);
        Gearchangegauge4->setObjectName(QStringLiteral("Gearchangegauge4"));
        Gearchangegauge4->setGeometry(QRect(240, 330, 200, 40));
        Gearchangegauge4->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:reflect, x1:0.49995, y1:0, x2:1, y2:0, stop:0 rgba(85, 248, 33, 255), stop:0.212871 rgba(205, 251, 32, 255), stop:0.712871 rgba(255, 40, 40, 255));"));
        RPMline4 = new QFrame(Gearchangegauge4);
        RPMline4->setObjectName(QStringLiteral("RPMline4"));
        RPMline4->setGeometry(QRect(100, 0, 5, 40));
        RPMline4->setFrameShape(QFrame::VLine);
        RPMline4->setFrameShadow(QFrame::Sunken);
        Gearchangegauge5 = new QWidget(car);
        Gearchangegauge5->setObjectName(QStringLiteral("Gearchangegauge5"));
        Gearchangegauge5->setGeometry(QRect(460, 110, 200, 40));
        Gearchangegauge5->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:reflect, x1:0.49995, y1:0, x2:1, y2:0, stop:0 rgba(85, 248, 33, 255), stop:0.212871 rgba(205, 251, 32, 255), stop:0.712871 rgba(255, 40, 40, 255));"));
        RPMline5 = new QFrame(Gearchangegauge5);
        RPMline5->setObjectName(QStringLiteral("RPMline5"));
        RPMline5->setGeometry(QRect(100, 0, 5, 40));
        RPMline5->setFrameShape(QFrame::VLine);
        RPMline5->setFrameShadow(QFrame::Sunken);
        gear1 = new QLabel(car);
        gear1->setObjectName(QStringLiteral("gear1"));
        gear1->setGeometry(QRect(105, 80, 25, 20));
        gear1->setStyleSheet(QStringLiteral("font: 75 20pt \"Liberation serif\";"));
        gear1->setAlignment(Qt::AlignCenter);
        gear3 = new QLabel(car);
        gear3->setObjectName(QStringLiteral("gear3"));
        gear3->setGeometry(QRect(327, 80, 25, 20));
        gear3->setStyleSheet(QStringLiteral("font: 75 20pt \"Liberation serif\";"));
        gear3->setAlignment(Qt::AlignCenter);
        gear5 = new QLabel(car);
        gear5->setObjectName(QStringLiteral("gear5"));
        gear5->setGeometry(QRect(547, 80, 25, 20));
        gear5->setStyleSheet(QStringLiteral("font: 75 20pt \"Liberation serif\";"));
        gear5->setAlignment(Qt::AlignCenter);
        gear2 = new QLabel(car);
        gear2->setObjectName(QStringLiteral("gear2"));
        gear2->setGeometry(QRect(105, 300, 25, 20));
        gear2->setStyleSheet(QStringLiteral("font: 75 20pt \"Liberation serif\";"));
        gear2->setAlignment(Qt::AlignCenter);
        gear4 = new QLabel(car);
        gear4->setObjectName(QStringLiteral("gear4"));
        gear4->setGeometry(QRect(327, 300, 25, 20));
        gear4->setStyleSheet(QStringLiteral("font: 75 20pt \"Liberation serif\";"));
        gear4->setAlignment(Qt::AlignCenter);
        LED1 = new QGraphicsView(car);
        LED1->setObjectName(QStringLiteral("LED1"));
        LED1->setGeometry(QRect(107, 160, 31, 31));
        LED1->setStyleSheet(QStringLiteral("border-image: url(:/images/3Gicon.png);"));
        LED2 = new QGraphicsView(car);
        LED2->setObjectName(QStringLiteral("LED2"));
        LED2->setGeometry(QRect(327, 160, 31, 31));
        LED2->setStyleSheet(QStringLiteral("border-image: url(:/images/blueLED.png);"));
        LED3 = new QGraphicsView(car);
        LED3->setObjectName(QStringLiteral("LED3"));
        LED3->setGeometry(QRect(547, 160, 31, 31));
        LED3->setStyleSheet(QStringLiteral("border-image: url(:/images/blueLED.png);"));
        LED4 = new QGraphicsView(car);
        LED4->setObjectName(QStringLiteral("LED4"));
        LED4->setGeometry(QRect(107, 380, 31, 31));
        LED4->setStyleSheet(QStringLiteral("border-image: url(:/images/blueLED.png);"));
        LED5 = new QGraphicsView(car);
        LED5->setObjectName(QStringLiteral("LED5"));
        LED5->setGeometry(QRect(327, 380, 31, 31));
        LED5->setStyleSheet(QStringLiteral("border-image: url(:/images/blueLED.png);"));
        REV_HMI->setCentralWidget(centralWidget);
        log->raise();
        map->raise();
        car->raise();
        trip->raise();
        traf->raise();
        music->raise();
        sleep->raise();
        home->raise();
        QWidget::setTabOrder(pushButton_updateTrafficData, textBrowser_traffic);
        QWidget::setTabOrder(textBrowser_traffic, pushButton_moveUp);
        QWidget::setTabOrder(pushButton_moveUp, pushButton_moveDown);
        QWidget::setTabOrder(pushButton_moveDown, checkBox_repeatThis);
        QWidget::setTabOrder(checkBox_repeatThis, checkBox_repeatAll);
        QWidget::setTabOrder(checkBox_repeatAll, pushButton_addDirectory);
        QWidget::setTabOrder(pushButton_addDirectory, toolButton_mute);
        QWidget::setTabOrder(toolButton_mute, toolButton_prev);
        QWidget::setTabOrder(toolButton_prev, toolButton_play);
        QWidget::setTabOrder(toolButton_play, toolButton_stop);
        QWidget::setTabOrder(toolButton_stop, toolButton_next);
        QWidget::setTabOrder(toolButton_next, pushButton_clear_errors);
        QWidget::setTabOrder(pushButton_clear_errors, checkBox_logGpsRaw);
        QWidget::setTabOrder(checkBox_logGpsRaw, checkBox_logBmsRaw);
        QWidget::setTabOrder(checkBox_logBmsRaw, pushButton_Runsound);
        QWidget::setTabOrder(pushButton_Runsound, pushButton_defaultSettings);
        QWidget::setTabOrder(pushButton_defaultSettings, pushButton_exit);

        retranslateUi(REV_HMI);

        QMetaObject::connectSlotsByName(REV_HMI);
    } // setupUi

    void retranslateUi(QMainWindow *REV_HMI)
    {
        REV_HMI->setWindowTitle(QApplication::translate("REV_HMI", "MainWindow", 0));
        pushButton_zoomIn->setText(QApplication::translate("REV_HMI", "Zoom in", 0));
        pushButton_zoomOut->setText(QApplication::translate("REV_HMI", "Zoom out", 0));
        checkBox_showComments->setText(QApplication::translate("REV_HMI", "Show comments", 0));
        checkBox_showTestTrack->setText(QApplication::translate("REV_HMI", "Show test track", 0));
        checkBox_autoFollow->setText(QApplication::translate("REV_HMI", "Center", 0));
        checkBox_showMyTrack->setText(QApplication::translate("REV_HMI", "Show my track", 0));
        checkBox_nightMode->setText(QApplication::translate("REV_HMI", "Nightmode", 0));
        pushButton_loadTrack->setText(QApplication::translate("REV_HMI", "Load track", 0));
        mapContHide->setText(QApplication::translate("REV_HMI", "Hide Controls", 0));
        pushButton_updateTrafficData->setText(QApplication::translate("REV_HMI", "Update", 0));
        label_52->setText(QApplication::translate("REV_HMI", "Main Roads WA", 0));
        label_51->setText(QApplication::translate("REV_HMI", "@Perth_Traffic", 0));
        label_53->setText(QApplication::translate("REV_HMI", "For updates on traffic issues affecting main roads in Perth...", 0));
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
        label_0100s->setText(QApplication::translate("REV_HMI", "s", 0));
        label_elapsed->setText(QApplication::translate("REV_HMI", "Elapsed", 0));
        label_driveA->setText(QApplication::translate("REV_HMI", "A", 0));
        l_trip_ncurrentMax->setText(QApplication::translate("REV_HMI", "0.00", 0));
        label_dist->setText(QApplication::translate("REV_HMI", "Distance", 0));
        label_tripspeed->setText(QApplication::translate("REV_HMI", "Speed", 0));
        label_currentdrive->setText(QApplication::translate("REV_HMI", "Drive", 0));
        label_speeddrive->setText(QApplication::translate("REV_HMI", "Drive", 0));
        l_trip_ncurrentAvg->setText(QApplication::translate("REV_HMI", "0.00", 0));
        l_trip_Accel60->setText(QApplication::translate("REV_HMI", "0.00", 0));
        label_050->setText(QApplication::translate("REV_HMI", "0 .. 50", 0));
        label_0100->setText(QApplication::translate("REV_HMI", "0 .. 100", 0));
        label_avg->setText(QApplication::translate("REV_HMI", "Avg", 0));
        label_speedekmh->setText(QApplication::translate("REV_HMI", "km/h", 0));
        l_trip_speedAvgElapsed->setText(QApplication::translate("REV_HMI", "0.00", 0));
        label_050s->setText(QApplication::translate("REV_HMI", "s", 0));
        label_max->setText(QApplication::translate("REV_HMI", "Max", 0));
        label_accel->setText(QApplication::translate("REV_HMI", "Acceleration", 0));
        editname_label->setText(QApplication::translate("REV_HMI", "Name", 0));
        pushButton_startRecording->setText(QApplication::translate("REV_HMI", "Start", 0));
        pushButton_stopRecording->setText(QApplication::translate("REV_HMI", "Stop", 0));
        pushButton_changeRange->setText(QApplication::translate("REV_HMI", "Change max range", 0));
        label_10->setText(QApplication::translate("REV_HMI", "Elapsed", 0));
        label_4->setText(QApplication::translate("REV_HMI", "Driving", 0));
        label_54->setText(QApplication::translate("REV_HMI", "Export to:", 0));
        pushButton_location->setText(QApplication::translate("REV_HMI", "Location", 0));
        pushButton_export->setText(QApplication::translate("REV_HMI", "Export", 0));
        label_exportLocation->setText(QApplication::translate("REV_HMI", "Directory", 0));
        pushButton_clear_errors->setText(QApplication::translate("REV_HMI", "Clear Log", 0));
        checkBox_logGpsRaw->setText(QApplication::translate("REV_HMI", "GPS raw data", 0));
        checkBox_logBmsRaw->setText(QApplication::translate("REV_HMI", "BMS raw data", 0));
        pushButton_Runsound->setText(QApplication::translate("REV_HMI", "Run Eng Simu", 0));
        checkBox_GPSFile->setText(QApplication::translate("REV_HMI", "GPS File", 0));
        checkBox_BMSFile->setText(QApplication::translate("REV_HMI", "BMS File", 0));
        pushButton_defaultSettings->setText(QApplication::translate("REV_HMI", "Default Settings", 0));
        pushButton_exit->setText(QApplication::translate("REV_HMI", "Exit Program", 0));
        label_speed->setText(QApplication::translate("REV_HMI", "Speed", 0));
        label_voltage->setText(QApplication::translate("REV_HMI", "Voltage", 0));
        gpsFix->setText(QApplication::translate("REV_HMI", "GPS Fixed", 0));
        valFix->setText(QApplication::translate("REV_HMI", "No", 0));
        gpsLat->setText(QApplication::translate("REV_HMI", "Latitude", 0));
        valLat->setText(QApplication::translate("REV_HMI", "---.-", 0));
        gpsLon->setText(QApplication::translate("REV_HMI", "Longitude", 0));
        valLon->setText(QApplication::translate("REV_HMI", "---.-", 0));
        Handbrakeicon->setText(QString());
        lowBatticon->setText(QString());
        Dooricon->setText(QString());
        SeatBelticon->setText(QString());
        CELicon->setText(QString());
        Neticon->setText(QString());
        Fueldooricon->setText(QString());
        Safetyswitchicon->setText(QString());
        GPSicon->setText(QString());
        TBSicon->setText(QString());
        label_KM->setText(QApplication::translate("REV_HMI", "Km", 0));
        label_prevSong->setText(QApplication::translate("REV_HMI", "Prev", 0));
        val_prevSong->setText(QApplication::translate("REV_HMI", "Prev Song", 0));
        label_currentSong->setText(QApplication::translate("REV_HMI", "Current", 0));
        val_currentSong->setText(QApplication::translate("REV_HMI", "Current Song", 0));
        label_nextSong->setText(QApplication::translate("REV_HMI", "Next", 0));
        val_nextSong->setText(QApplication::translate("REV_HMI", "Next Song", 0));
        val_tripDist->setText(QApplication::translate("REV_HMI", "0.00 Km", 0));
        label_tripDist->setText(QApplication::translate("REV_HMI", "Trip Distance", 0));
        label_tripTime->setText(QApplication::translate("REV_HMI", "Trip Time", 0));
        val_tripTime->setText(QApplication::translate("REV_HMI", "00:00:00", 0));
        driver_label->setText(QApplication::translate("REV_HMI", "Driver:", 0));
        driver_name->setText(QApplication::translate("REV_HMI", "Name", 0));
        l_RPM->setText(QApplication::translate("REV_HMI", "RPM :", 0));
        val_RPM->setText(QApplication::translate("REV_HMI", "0", 0));
        gear1->setText(QApplication::translate("REV_HMI", "1", 0));
        gear3->setText(QApplication::translate("REV_HMI", "3", 0));
        gear5->setText(QApplication::translate("REV_HMI", "5", 0));
        gear2->setText(QApplication::translate("REV_HMI", "2", 0));
        gear4->setText(QApplication::translate("REV_HMI", "4", 0));
    } // retranslateUi

};

namespace Ui {
    class REV_HMI: public Ui_REV_HMI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GETZ_HMI_H
