/********************************************************************************
** Form generated from reading UI file 'lotus_hmi.ui'
**
** Created by: Qt User Interface Compiler version 5.1.2
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
#include <qtransparentwidget.h>
#include "mapwidget.h"

QT_BEGIN_NAMESPACE

class Ui_REV_HMI
{
public:
    QWidget *centralWidget;
    QWidget *map;
    MapWidget *mapWidget;
    QWidget *controls;
    QWidget *verticalLayoutWidget_2;
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
    QPushButton *pushButton_deleteTrack;
    QPushButton *mapContHide;
    QPushButton *showButton;
    QWidget *traf;
    QPushButton *pushButton_updateTrafficData;
    QTransparentWidget *traffic_info;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_52;
    QLabel *label_51;
    QLabel *label_53;
    QTextBrowser *textBrowser_traffic;
    QWidget *music;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_7;
    QToolButton *toolButton_mute;
    QToolButton *toolButton_prev;
    QToolButton *toolButton_play;
    QToolButton *toolButton_stop;
    QToolButton *toolButton_next;
    QSlider *playerseekSlider;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_6;
    QPushButton *pushButton_moveUp;
    QPushButton *pushButton_moveDown;
    QCheckBox *checkBox_repeatThis;
    QCheckBox *checkBox_repeatAll;
    QPushButton *pushButton_addDirectory;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_4;
    QSlider *playervolSlider;
    QTableWidget *tableWidget_mediaList;
    QLabel *musicDir;
    QWidget *trip;
    QTransparentWidget *tripWidget1;
    QGridLayout *trip1;
    QLabel *label_21;
    QLabel *label_13;
    QLabel *l_trip_capacityPerKm;
    QLabel *label_34;
    QLabel *label_24;
    QLabel *label_9;
    QLabel *l_trip_capacityRegenerated;
    QLabel *label_5;
    QFrame *line_4;
    QLabel *label_48;
    QLabel *l_trip_speedAvgElapsed;
    QLabel *label_29;
    QLabel *l_trip_pcurrentAvg;
    QLabel *label_43;
    QLabel *label_14;
    QLabel *label_16;
    QFrame *line_3;
    QLabel *label_25;
    QLabel *l_trip_ncurrentAvg;
    QLabel *l_trip_pcurrentMax;
    QLabel *label_44;
    QFrame *line;
    QLabel *l_trip_Accel60;
    QLabel *l_trip_capacityUsed;
    QLabel *label_15;
    QLabel *label_11;
    QLabel *label_49;
    QLabel *l_trip_Accel100;
    QLabel *label_19;
    QLabel *label_28;
    QLabel *l_trip_ncurrentMax;
    QFrame *line_2;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_40;
    QLabel *label_22;
    QLabel *l_trip_speedMax;
    QLabel *label_27;
    QLabel *label_8;
    QLabel *l_trip_distance;
    QTransparentWidget *transparentWidgetA;
    QGridLayout *gridLayout_5;
    QVBoxLayout *verticalLayout_7;
    QLabel *editname_label;
    QTextEdit *editname;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout;
    QPushButton *pushButton_stopRecording;
    QPushButton *pushButton_startRecording;
    QSpacerItem *verticalSpacer_18;
    QPushButton *pushButton_changeRange;
    QSpacerItem *verticalSpacer_16;
    QLabel *label_10;
    QLabel *l_trip_time;
    QSpacerItem *verticalSpacer_15;
    QLabel *label_4;
    QLabel *l_drive_time;
    QPushButton *pushButton_tripReset;
    QSpacerItem *verticalSpacer_17;
    QLabel *label_54;
    QGridLayout *gridLayout_7;
    QPushButton *pushButton_location;
    QPushButton *pushButton_export;
    QTextBrowser *label_exportLocation;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_maxVoltage;
    QLabel *l_trip_voltageMax;
    QTableWidget *tableWidget_batteryCells_max;
    QSpacerItem *verticalSpacer_5;
    QLabel *label_17;
    QGridLayout *gridLayout_6;
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
    QWidget *log;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_clear_errors;
    QCheckBox *checkBox_logGpsRaw;
    QCheckBox *checkBox_logBmsRaw;
    QPushButton *pushButton_Runsound;
    QSlider *horizontalSlider;
    QCheckBox *checkBox_BMSFile;
    QCheckBox *checkBox_GPSFile;
    QPushButton *pushButton_defaultSettings;
    QPushButton *pushButton_exit;
    QTextBrowser *textBrowser_errors;
    QWidget *home;
    QWidget *carInfo;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_8;
    QLabel *label_speed;
    QLabel *l_speed;
    QSpacerItem *verticalSpacer_6;
    QLabel *label_voltage;
    QLabel *l_voltage;
    QSpacerItem *verticalSpacer_7;
    QLabel *l_time;
    QSpacerItem *verticalSpacer_9;
    QWidget *gridLayoutWidget;
    QGridLayout *batteryInfo;
    QProgressBar *progressBar_battery;
    QHBoxLayout *horizontalLayout_2;
    QLabel *l_current;
    QLabel *label_A;
    QProgressBar *progressBar_amps;
    QHBoxLayout *horizontalLayout;
    QLabel *l_remdist;
    QLabel *label_KM;
    QWidget *battInfo;
    QTableWidget *info_battTable;
    QPushButton *carBut;
    QPushButton *mapBut;
    QPushButton *trafBut;
    QPushButton *musicBut;
    QPushButton *battBut;
    QPushButton *tripBut;
    QPushButton *logBut;
    QPushButton *optBut;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *driver_label;
    QLabel *driver_name;
    QLabel *Dooricon;
    QLabel *Safetyswitchicon;
    QLabel *GPSicon;
    QLabel *Handbrakeicon;
    QLabel *Neticon;
    QLabel *lowBatticon;
    QLabel *CELicon;
    QLabel *TBSicon;
    QLabel *SeatBelticon;
    QPushButton *hideBatt;
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
    QWidget *sleep;
    QPushButton *backBut;
    QWidget *car;
    QWidget *Gearchangegauge1;
    QFrame *RPMline1;
    QLabel *gear1;
    QLabel *gear2;
    QLabel *gear4;
    QWidget *Gearchangegauge2;
    QFrame *RPMline2;
    QWidget *Gearchangegauge4;
    QFrame *RPMline4;
    QWidget *Gearchangegauge3;
    QFrame *RPMline3;
    QLabel *gear5;
    QLabel *gear3;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *Revs;
    QLabel *l_RPM;
    QLabel *val_RPM;
    QWidget *Gearchangegauge5;
    QFrame *RPMline5;
    QGraphicsView *LED1;
    QGraphicsView *LED2;
    QGraphicsView *LED3;
    QGraphicsView *LED4;
    QGraphicsView *LED5;

    void setupUi(QMainWindow *REV_HMI)
    {
        if (REV_HMI->objectName().isEmpty())
            REV_HMI->setObjectName(QStringLiteral("REV_HMI"));
        REV_HMI->resize(1025, 768);
        REV_HMI->setStyleSheet(QLatin1String("QProgressBar:vertical {\n"
"	background-color: rgba(255, 255, 255, 150);\n"
"    border: 2px solid grey;\n"
"    border-radius: 5px;\n"
"	text-align: center;\n"
"}\n"
"/*only one big chunk*/\n"
"QProgressBar::chunk:vertical {\n"
"    border-radius: 3px;\n"
"    margin: 1.0px;\n"
"}\n"
"QProgressBar{\n"
"font: 75 20pt \"Arial\";\n"
"}\n"
"\n"
""));
        centralWidget = new QWidget(REV_HMI);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QLatin1String("#centralWidget {\n"
"border-image: url(:/images/bg.png);\n"
"}\n"
"QLabel{\n"
"font: 75 20pt \"Arial\";\n"
"}\n"
"QToolbar{\n"
"color:rgb(0,0,0);\n"
"}\n"
"QCheckBox{\n"
"color:rgb(0,0,0);\n"
"font: 75 17pt \"Arial\";\n"
"}\n"
"QPushButton{\n"
"font: 75 17pt \"Arial\";\n"
"}"));
        map = new QWidget(centralWidget);
        map->setObjectName(QStringLiteral("map"));
        map->setEnabled(true);
        map->setGeometry(QRect(0, 0, 1025, 768));
        map->setFocusPolicy(Qt::NoFocus);
        map->setStyleSheet(QLatin1String("QPushButton:focus{\n"
"color: rgb(255, 0, 4);\n"
"}\n"
"QCheckBox:focus{\n"
"background-color: rgba(255, 0, 4, 50);\n"
"}"));
        mapWidget = new MapWidget(map);
        mapWidget->setObjectName(QStringLiteral("mapWidget"));
        mapWidget->setGeometry(QRect(0, 0, 1025, 768));
        controls = new QWidget(map);
        controls->setObjectName(QStringLiteral("controls"));
        controls->setGeometry(QRect(720, 50, 301, 521));
        verticalLayoutWidget_2 = new QWidget(controls);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(0, 0, 301, 521));
        verticalLayout_8 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        mapControls = new QTransparentWidget(verticalLayoutWidget_2);
        mapControls->setObjectName(QStringLiteral("mapControls"));
        mapControls->setEnabled(true);
        verticalLayout = new QVBoxLayout(mapControls);
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(-1, -1, 25, -1);
        pushButton_zoomIn = new QPushButton(mapControls);
        pushButton_zoomIn->setObjectName(QStringLiteral("pushButton_zoomIn"));
        pushButton_zoomIn->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_zoomIn->sizePolicy().hasHeightForWidth());
        pushButton_zoomIn->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(17);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        pushButton_zoomIn->setFont(font);
        pushButton_zoomIn->setStyleSheet(QStringLiteral(""));

        verticalLayout->addWidget(pushButton_zoomIn);

        pushButton_zoomOut = new QPushButton(mapControls);
        pushButton_zoomOut->setObjectName(QStringLiteral("pushButton_zoomOut"));
        pushButton_zoomOut->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_zoomOut->sizePolicy().hasHeightForWidth());
        pushButton_zoomOut->setSizePolicy(sizePolicy1);
        pushButton_zoomOut->setStyleSheet(QStringLiteral(""));

        verticalLayout->addWidget(pushButton_zoomOut);

        checkBox_showComments = new QCheckBox(mapControls);
        checkBox_showComments->setObjectName(QStringLiteral("checkBox_showComments"));
        checkBox_showComments->setEnabled(true);
        sizePolicy.setHeightForWidth(checkBox_showComments->sizePolicy().hasHeightForWidth());
        checkBox_showComments->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(checkBox_showComments);

        checkBox_showTestTrack = new QCheckBox(mapControls);
        checkBox_showTestTrack->setObjectName(QStringLiteral("checkBox_showTestTrack"));
        checkBox_showTestTrack->setEnabled(true);
        sizePolicy.setHeightForWidth(checkBox_showTestTrack->sizePolicy().hasHeightForWidth());
        checkBox_showTestTrack->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(checkBox_showTestTrack);

        checkBox_autoFollow = new QCheckBox(mapControls);
        checkBox_autoFollow->setObjectName(QStringLiteral("checkBox_autoFollow"));
        checkBox_autoFollow->setEnabled(true);
        sizePolicy.setHeightForWidth(checkBox_autoFollow->sizePolicy().hasHeightForWidth());
        checkBox_autoFollow->setSizePolicy(sizePolicy);
        checkBox_autoFollow->setStyleSheet(QStringLiteral(""));
        checkBox_autoFollow->setChecked(true);

        verticalLayout->addWidget(checkBox_autoFollow);

        checkBox_showMyTrack = new QCheckBox(mapControls);
        checkBox_showMyTrack->setObjectName(QStringLiteral("checkBox_showMyTrack"));
        checkBox_showMyTrack->setEnabled(true);
        sizePolicy.setHeightForWidth(checkBox_showMyTrack->sizePolicy().hasHeightForWidth());
        checkBox_showMyTrack->setSizePolicy(sizePolicy);
        checkBox_showMyTrack->setChecked(true);

        verticalLayout->addWidget(checkBox_showMyTrack);

        checkBox_nightMode = new QCheckBox(mapControls);
        checkBox_nightMode->setObjectName(QStringLiteral("checkBox_nightMode"));
        checkBox_nightMode->setEnabled(true);
        sizePolicy.setHeightForWidth(checkBox_nightMode->sizePolicy().hasHeightForWidth());
        checkBox_nightMode->setSizePolicy(sizePolicy);
        checkBox_nightMode->setStyleSheet(QStringLiteral(""));

        verticalLayout->addWidget(checkBox_nightMode);

        pushButton_loadTrack = new QPushButton(mapControls);
        pushButton_loadTrack->setObjectName(QStringLiteral("pushButton_loadTrack"));
        pushButton_loadTrack->setEnabled(true);
        sizePolicy.setHeightForWidth(pushButton_loadTrack->sizePolicy().hasHeightForWidth());
        pushButton_loadTrack->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(pushButton_loadTrack);

        pushButton_deleteTrack = new QPushButton(mapControls);
        pushButton_deleteTrack->setObjectName(QStringLiteral("pushButton_deleteTrack"));
        sizePolicy.setHeightForWidth(pushButton_deleteTrack->sizePolicy().hasHeightForWidth());
        pushButton_deleteTrack->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(pushButton_deleteTrack);


        verticalLayout_8->addWidget(mapControls);

        mapContHide = new QPushButton(verticalLayoutWidget_2);
        mapContHide->setObjectName(QStringLiteral("mapContHide"));
        mapContHide->setEnabled(true);
        mapContHide->setMinimumSize(QSize(0, 40));
        mapContHide->setStyleSheet(QStringLiteral(""));

        verticalLayout_8->addWidget(mapContHide);

        showButton = new QPushButton(map);
        showButton->setObjectName(QStringLiteral("showButton"));
        showButton->setGeometry(QRect(950, 10, 61, 61));
        showButton->setStyleSheet(QStringLiteral("border-image: url(:/Buttons/Showmap.png);"));
        traf = new QWidget(centralWidget);
        traf->setObjectName(QStringLiteral("traf"));
        traf->setEnabled(false);
        traf->setGeometry(QRect(0, 0, 1025, 768));
        traf->setStyleSheet(QLatin1String("QPushButton:focus{\n"
"color: rgb(255, 0, 4);\n"
"}\n"
"QCheckBox:focus{\n"
"background-color: rgba(255, 0, 4, 50);\n"
"}"));
        pushButton_updateTrafficData = new QPushButton(traf);
        pushButton_updateTrafficData->setObjectName(QStringLiteral("pushButton_updateTrafficData"));
        pushButton_updateTrafficData->setGeometry(QRect(730, 220, 281, 31));
        sizePolicy.setHeightForWidth(pushButton_updateTrafficData->sizePolicy().hasHeightForWidth());
        pushButton_updateTrafficData->setSizePolicy(sizePolicy);
        pushButton_updateTrafficData->setStyleSheet(QStringLiteral(""));
        traffic_info = new QTransparentWidget(traf);
        traffic_info->setObjectName(QStringLiteral("traffic_info"));
        traffic_info->setGeometry(QRect(730, 10, 281, 201));
        verticalLayout_5 = new QVBoxLayout(traffic_info);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_52 = new QLabel(traffic_info);
        label_52->setObjectName(QStringLiteral("label_52"));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(20);
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
        label_53->setStyleSheet(QStringLiteral("font: 13pt \"Arial\";"));
        label_53->setWordWrap(true);

        verticalLayout_5->addWidget(label_53);

        textBrowser_traffic = new QTextBrowser(traf);
        textBrowser_traffic->setObjectName(QStringLiteral("textBrowser_traffic"));
        textBrowser_traffic->setGeometry(QRect(10, 10, 711, 731));
        sizePolicy.setHeightForWidth(textBrowser_traffic->sizePolicy().hasHeightForWidth());
        textBrowser_traffic->setSizePolicy(sizePolicy);
        textBrowser_traffic->setStyleSheet(QLatin1String("font: 10pt \"Latha\";\n"
"background-color: rgba(255,255,255,100);"));
        textBrowser_traffic->setOpenLinks(false);
        music = new QWidget(centralWidget);
        music->setObjectName(QStringLiteral("music"));
        music->setEnabled(false);
        music->setGeometry(QRect(0, 0, 1025, 768));
        music->setStyleSheet(QLatin1String("QPushButton:focus{\n"
"color: rgb(255, 0, 4);\n"
"}\n"
"QCheckBox:focus{\n"
"background-color: rgba(255, 0, 4, 50);\n"
"}\n"
"QToolButton:focus{\n"
"background-color: rgba(255, 0, 4, 50);\n"
"}"));
        verticalLayout_4 = new QVBoxLayout(music);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(-1, -1, -1, 35);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, -1, -1);
        toolButton_mute = new QToolButton(music);
        toolButton_mute->setObjectName(QStringLiteral("toolButton_mute"));
        toolButton_mute->setMinimumSize(QSize(0, 0));
        QFont font2;
        font2.setPointSize(17);
        toolButton_mute->setFont(font2);
        toolButton_mute->setStyleSheet(QStringLiteral(""));
        toolButton_mute->setIconSize(QSize(20, 20));
        toolButton_mute->setAutoRaise(true);

        horizontalLayout_7->addWidget(toolButton_mute);

        toolButton_prev = new QToolButton(music);
        toolButton_prev->setObjectName(QStringLiteral("toolButton_prev"));
        QFont font3;
        font3.setPointSize(15);
        toolButton_prev->setFont(font3);
        toolButton_prev->setText(QStringLiteral("|<"));
        toolButton_prev->setAutoRaise(true);

        horizontalLayout_7->addWidget(toolButton_prev);

        toolButton_play = new QToolButton(music);
        toolButton_play->setObjectName(QStringLiteral("toolButton_play"));
        toolButton_play->setMinimumSize(QSize(0, 0));
        toolButton_play->setFont(font3);
        toolButton_play->setText(QStringLiteral(">"));
        toolButton_play->setIconSize(QSize(40, 40));
        toolButton_play->setToolButtonStyle(Qt::ToolButtonIconOnly);
        toolButton_play->setAutoRaise(true);

        horizontalLayout_7->addWidget(toolButton_play);

        toolButton_stop = new QToolButton(music);
        toolButton_stop->setObjectName(QStringLiteral("toolButton_stop"));
        toolButton_stop->setFont(font3);
        toolButton_stop->setText(QStringLiteral("[]"));
        toolButton_stop->setAutoRaise(true);

        horizontalLayout_7->addWidget(toolButton_stop);

        toolButton_next = new QToolButton(music);
        toolButton_next->setObjectName(QStringLiteral("toolButton_next"));
        toolButton_next->setMinimumSize(QSize(0, 0));
        toolButton_next->setFont(font3);
        toolButton_next->setText(QStringLiteral(">|"));
        toolButton_next->setAutoRaise(true);

        horizontalLayout_7->addWidget(toolButton_next);

        playerseekSlider = new QSlider(music);
        playerseekSlider->setObjectName(QStringLiteral("playerseekSlider"));
        playerseekSlider->setFocusPolicy(Qt::NoFocus);
        playerseekSlider->setMaximum(1000);
        playerseekSlider->setOrientation(Qt::Horizontal);
        playerseekSlider->setTickPosition(QSlider::NoTicks);

        horizontalLayout_7->addWidget(playerseekSlider);


        verticalLayout_4->addLayout(horizontalLayout_7);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, -1, -1);
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(3);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, -1, -1, -1);
        pushButton_moveUp = new QPushButton(music);
        pushButton_moveUp->setObjectName(QStringLiteral("pushButton_moveUp"));

        verticalLayout_6->addWidget(pushButton_moveUp);

        pushButton_moveDown = new QPushButton(music);
        pushButton_moveDown->setObjectName(QStringLiteral("pushButton_moveDown"));

        verticalLayout_6->addWidget(pushButton_moveDown);

        checkBox_repeatThis = new QCheckBox(music);
        checkBox_repeatThis->setObjectName(QStringLiteral("checkBox_repeatThis"));

        verticalLayout_6->addWidget(checkBox_repeatThis);

        checkBox_repeatAll = new QCheckBox(music);
        checkBox_repeatAll->setObjectName(QStringLiteral("checkBox_repeatAll"));

        verticalLayout_6->addWidget(checkBox_repeatAll);

        pushButton_addDirectory = new QPushButton(music);
        pushButton_addDirectory->setObjectName(QStringLiteral("pushButton_addDirectory"));

        verticalLayout_6->addWidget(pushButton_addDirectory);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_2);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_4);


        gridLayout_3->addLayout(verticalLayout_6, 0, 2, 1, 1);

        playervolSlider = new QSlider(music);
        playervolSlider->setObjectName(QStringLiteral("playervolSlider"));
        playervolSlider->setFocusPolicy(Qt::NoFocus);
        playervolSlider->setValue(60);
        playervolSlider->setSliderPosition(60);
        playervolSlider->setOrientation(Qt::Vertical);

        gridLayout_3->addWidget(playervolSlider, 0, 0, 1, 1);

        tableWidget_mediaList = new QTableWidget(music);
        if (tableWidget_mediaList->columnCount() < 3)
            tableWidget_mediaList->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_mediaList->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_mediaList->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_mediaList->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget_mediaList->setObjectName(QStringLiteral("tableWidget_mediaList"));
        tableWidget_mediaList->setEnabled(false);
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

        gridLayout_3->addWidget(tableWidget_mediaList, 0, 1, 1, 1);

        musicDir = new QLabel(music);
        musicDir->setObjectName(QStringLiteral("musicDir"));
        musicDir->setMinimumSize(QSize(0, 40));
        musicDir->setStyleSheet(QStringLiteral("font: 75 14pt \"Arial\";"));

        gridLayout_3->addWidget(musicDir, 1, 1, 1, 1);


        verticalLayout_4->addLayout(gridLayout_3);

        trip = new QWidget(centralWidget);
        trip->setObjectName(QStringLiteral("trip"));
        trip->setEnabled(false);
        trip->setGeometry(QRect(0, 0, 1025, 768));
        trip->setStyleSheet(QLatin1String("QPushButton:focus{\n"
"color: rgb(255, 0, 4);\n"
"}\n"
"QCheckBox:focus{\n"
"background-color: rgba(255, 0, 4, 50);\n"
"}"));
        tripWidget1 = new QTransparentWidget(trip);
        tripWidget1->setObjectName(QStringLiteral("tripWidget1"));
        tripWidget1->setGeometry(QRect(30, 29, 381, 711));
        trip1 = new QGridLayout(tripWidget1);
        trip1->setObjectName(QStringLiteral("trip1"));
        label_21 = new QLabel(tripWidget1);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setText(QStringLiteral("kWh"));

        trip1->addWidget(label_21, 19, 3, 1, 1);

        label_13 = new QLabel(tripWidget1);
        label_13->setObjectName(QStringLiteral("label_13"));

        trip1->addWidget(label_13, 20, 3, 1, 1);

        l_trip_capacityPerKm = new QLabel(tripWidget1);
        l_trip_capacityPerKm->setObjectName(QStringLiteral("l_trip_capacityPerKm"));
        l_trip_capacityPerKm->setText(QStringLiteral("0.00"));
        l_trip_capacityPerKm->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        trip1->addWidget(l_trip_capacityPerKm, 21, 2, 1, 1);

        label_34 = new QLabel(tripWidget1);
        label_34->setObjectName(QStringLiteral("label_34"));

        trip1->addWidget(label_34, 17, 0, 1, 1);

        label_24 = new QLabel(tripWidget1);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_24->setIndent(15);

        trip1->addWidget(label_24, 15, 0, 1, 1);

        label_9 = new QLabel(tripWidget1);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setIndent(15);

        trip1->addWidget(label_9, 21, 0, 1, 1);

        l_trip_capacityRegenerated = new QLabel(tripWidget1);
        l_trip_capacityRegenerated->setObjectName(QStringLiteral("l_trip_capacityRegenerated"));
        l_trip_capacityRegenerated->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        trip1->addWidget(l_trip_capacityRegenerated, 20, 2, 1, 1);

        label_5 = new QLabel(tripWidget1);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        trip1->addWidget(label_5, 2, 1, 1, 1);

        line_4 = new QFrame(tripWidget1);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        trip1->addWidget(line_4, 12, 0, 1, 4);

        label_48 = new QLabel(tripWidget1);
        label_48->setObjectName(QStringLiteral("label_48"));

        trip1->addWidget(label_48, 4, 3, 1, 1);

        l_trip_speedAvgElapsed = new QLabel(tripWidget1);
        l_trip_speedAvgElapsed->setObjectName(QStringLiteral("l_trip_speedAvgElapsed"));
        l_trip_speedAvgElapsed->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        trip1->addWidget(l_trip_speedAvgElapsed, 4, 1, 1, 1);

        label_29 = new QLabel(tripWidget1);
        label_29->setObjectName(QStringLiteral("label_29"));

        trip1->addWidget(label_29, 14, 3, 1, 1);

        l_trip_pcurrentAvg = new QLabel(tripWidget1);
        l_trip_pcurrentAvg->setObjectName(QStringLiteral("l_trip_pcurrentAvg"));
        l_trip_pcurrentAvg->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        trip1->addWidget(l_trip_pcurrentAvg, 8, 1, 1, 1);

        label_43 = new QLabel(tripWidget1);
        label_43->setObjectName(QStringLiteral("label_43"));
        label_43->setIndent(15);

        trip1->addWidget(label_43, 9, 0, 1, 1);

        label_14 = new QLabel(tripWidget1);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setIndent(15);

        trip1->addWidget(label_14, 2, 2, 1, 1);

        label_16 = new QLabel(tripWidget1);
        label_16->setObjectName(QStringLiteral("label_16"));

        trip1->addWidget(label_16, 8, 3, 1, 1);

        line_3 = new QFrame(tripWidget1);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        trip1->addWidget(line_3, 6, 0, 1, 4);

        label_25 = new QLabel(tripWidget1);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setMargin(0);
        label_25->setIndent(15);

        trip1->addWidget(label_25, 8, 0, 1, 1);

        l_trip_ncurrentAvg = new QLabel(tripWidget1);
        l_trip_ncurrentAvg->setObjectName(QStringLiteral("l_trip_ncurrentAvg"));
        l_trip_ncurrentAvg->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        trip1->addWidget(l_trip_ncurrentAvg, 9, 1, 1, 1);

        l_trip_pcurrentMax = new QLabel(tripWidget1);
        l_trip_pcurrentMax->setObjectName(QStringLiteral("l_trip_pcurrentMax"));
        l_trip_pcurrentMax->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        trip1->addWidget(l_trip_pcurrentMax, 8, 2, 1, 1);

        label_44 = new QLabel(tripWidget1);
        label_44->setObjectName(QStringLiteral("label_44"));
        label_44->setText(QStringLiteral("Current "));
        label_44->setIndent(-1);

        trip1->addWidget(label_44, 7, 0, 1, 1);

        line = new QFrame(tripWidget1);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        trip1->addWidget(line, 16, 0, 1, 4);

        l_trip_Accel60 = new QLabel(tripWidget1);
        l_trip_Accel60->setObjectName(QStringLiteral("l_trip_Accel60"));
        l_trip_Accel60->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        trip1->addWidget(l_trip_Accel60, 14, 2, 1, 1);

        l_trip_capacityUsed = new QLabel(tripWidget1);
        l_trip_capacityUsed->setObjectName(QStringLiteral("l_trip_capacityUsed"));
        l_trip_capacityUsed->setText(QStringLiteral("0.00"));
        l_trip_capacityUsed->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        trip1->addWidget(l_trip_capacityUsed, 19, 2, 1, 1);

        label_15 = new QLabel(tripWidget1);
        label_15->setObjectName(QStringLiteral("label_15"));

        trip1->addWidget(label_15, 21, 3, 1, 1);

        label_11 = new QLabel(tripWidget1);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_11->setIndent(15);

        trip1->addWidget(label_11, 14, 0, 1, 1);

        label_49 = new QLabel(tripWidget1);
        label_49->setObjectName(QStringLiteral("label_49"));

        trip1->addWidget(label_49, 15, 3, 1, 1);

        l_trip_Accel100 = new QLabel(tripWidget1);
        l_trip_Accel100->setObjectName(QStringLiteral("l_trip_Accel100"));
        l_trip_Accel100->setText(QStringLiteral("0.00"));
        l_trip_Accel100->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        trip1->addWidget(l_trip_Accel100, 15, 2, 1, 1);

        label_19 = new QLabel(tripWidget1);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setIndent(15);

        trip1->addWidget(label_19, 19, 0, 1, 1);

        label_28 = new QLabel(tripWidget1);
        label_28->setObjectName(QStringLiteral("label_28"));

        trip1->addWidget(label_28, 9, 3, 1, 1);

        l_trip_ncurrentMax = new QLabel(tripWidget1);
        l_trip_ncurrentMax->setObjectName(QStringLiteral("l_trip_ncurrentMax"));
        l_trip_ncurrentMax->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        trip1->addWidget(l_trip_ncurrentMax, 9, 2, 1, 1);

        line_2 = new QFrame(tripWidget1);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        trip1->addWidget(line_2, 11, 0, 1, 4);

        label_3 = new QLabel(tripWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));

        trip1->addWidget(label_3, 1, 0, 1, 1);

        label_2 = new QLabel(tripWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QStringLiteral("text-decoration: underline;"));
        label_2->setAlignment(Qt::AlignCenter);

        trip1->addWidget(label_2, 0, 0, 1, 4);

        label_40 = new QLabel(tripWidget1);
        label_40->setObjectName(QStringLiteral("label_40"));

        trip1->addWidget(label_40, 13, 0, 1, 2);

        label_22 = new QLabel(tripWidget1);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setIndent(15);

        trip1->addWidget(label_22, 20, 0, 1, 2);

        l_trip_speedMax = new QLabel(tripWidget1);
        l_trip_speedMax->setObjectName(QStringLiteral("l_trip_speedMax"));
        l_trip_speedMax->setText(QStringLiteral("0.00"));
        l_trip_speedMax->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        trip1->addWidget(l_trip_speedMax, 4, 2, 1, 1);

        label_27 = new QLabel(tripWidget1);
        label_27->setObjectName(QStringLiteral("label_27"));

        trip1->addWidget(label_27, 4, 0, 1, 1);

        label_8 = new QLabel(tripWidget1);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setText(QStringLiteral("km"));

        trip1->addWidget(label_8, 1, 3, 1, 1);

        l_trip_distance = new QLabel(tripWidget1);
        l_trip_distance->setObjectName(QStringLiteral("l_trip_distance"));
        l_trip_distance->setMinimumSize(QSize(90, 0));
        l_trip_distance->setText(QStringLiteral("0.00"));
        l_trip_distance->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        trip1->addWidget(l_trip_distance, 1, 1, 1, 2);

        transparentWidgetA = new QTransparentWidget(trip);
        transparentWidgetA->setObjectName(QStringLiteral("transparentWidgetA"));
        transparentWidgetA->setGeometry(QRect(750, 30, 261, 631));
        gridLayout_5 = new QGridLayout(transparentWidgetA);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(8, 5, 8, 5);
        editname_label = new QLabel(transparentWidgetA);
        editname_label->setObjectName(QStringLiteral("editname_label"));
        editname_label->setStyleSheet(QLatin1String("QLabel{\n"
"font: 75 18pt \"Arial\";\n"
"}"));
        editname_label->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(editname_label);

        editname = new QTextEdit(transparentWidgetA);
        editname->setObjectName(QStringLiteral("editname"));
        editname->setMaximumSize(QSize(16777215, 30));

        verticalLayout_7->addWidget(editname);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_stopRecording = new QPushButton(transparentWidgetA);
        pushButton_stopRecording->setObjectName(QStringLiteral("pushButton_stopRecording"));
        sizePolicy1.setHeightForWidth(pushButton_stopRecording->sizePolicy().hasHeightForWidth());
        pushButton_stopRecording->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButton_stopRecording, 0, 1, 1, 1);

        pushButton_startRecording = new QPushButton(transparentWidgetA);
        pushButton_startRecording->setObjectName(QStringLiteral("pushButton_startRecording"));
        sizePolicy1.setHeightForWidth(pushButton_startRecording->sizePolicy().hasHeightForWidth());
        pushButton_startRecording->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButton_startRecording, 0, 0, 1, 1);


        verticalLayout_7->addLayout(gridLayout);

        verticalSpacer_18 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_18);

        pushButton_changeRange = new QPushButton(transparentWidgetA);
        pushButton_changeRange->setObjectName(QStringLiteral("pushButton_changeRange"));

        verticalLayout_7->addWidget(pushButton_changeRange);

        verticalSpacer_16 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_16);

        label_10 = new QLabel(transparentWidgetA);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font1);
        label_10->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_10);

        l_trip_time = new QLabel(transparentWidgetA);
        l_trip_time->setObjectName(QStringLiteral("l_trip_time"));
        l_trip_time->setMinimumSize(QSize(85, 0));
        l_trip_time->setText(QStringLiteral("00:00:00"));
        l_trip_time->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(l_trip_time);

        verticalSpacer_15 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_15);

        label_4 = new QLabel(transparentWidgetA);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_4);

        l_drive_time = new QLabel(transparentWidgetA);
        l_drive_time->setObjectName(QStringLiteral("l_drive_time"));
        l_drive_time->setText(QStringLiteral("00:00:00"));
        l_drive_time->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(l_drive_time);

        pushButton_tripReset = new QPushButton(transparentWidgetA);
        pushButton_tripReset->setObjectName(QStringLiteral("pushButton_tripReset"));

        verticalLayout_7->addWidget(pushButton_tripReset);

        verticalSpacer_17 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_17);

        label_54 = new QLabel(transparentWidgetA);
        label_54->setObjectName(QStringLiteral("label_54"));
        label_54->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_54);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        pushButton_location = new QPushButton(transparentWidgetA);
        pushButton_location->setObjectName(QStringLiteral("pushButton_location"));

        gridLayout_7->addWidget(pushButton_location, 0, 0, 1, 1);

        pushButton_export = new QPushButton(transparentWidgetA);
        pushButton_export->setObjectName(QStringLiteral("pushButton_export"));

        gridLayout_7->addWidget(pushButton_export, 0, 1, 1, 1);


        verticalLayout_7->addLayout(gridLayout_7);

        label_exportLocation = new QTextBrowser(transparentWidgetA);
        label_exportLocation->setObjectName(QStringLiteral("label_exportLocation"));
        label_exportLocation->setMaximumSize(QSize(16777215, 50));
        label_exportLocation->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"font: 13pt \"Arial\";"));
        label_exportLocation->setFrameShape(QFrame::NoFrame);

        verticalLayout_7->addWidget(label_exportLocation);


        gridLayout_5->addLayout(verticalLayout_7, 2, 0, 1, 1);

        layoutWidget = new QWidget(trip);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(470, 30, 221, 711));
        verticalLayout_10 = new QVBoxLayout(layoutWidget);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        label_maxVoltage = new QLabel(layoutWidget);
        label_maxVoltage->setObjectName(QStringLiteral("label_maxVoltage"));
        label_maxVoltage->setAlignment(Qt::AlignCenter);

        verticalLayout_10->addWidget(label_maxVoltage);

        l_trip_voltageMax = new QLabel(layoutWidget);
        l_trip_voltageMax->setObjectName(QStringLiteral("l_trip_voltageMax"));
        l_trip_voltageMax->setText(QStringLiteral("0"));
        l_trip_voltageMax->setAlignment(Qt::AlignCenter);

        verticalLayout_10->addWidget(l_trip_voltageMax);

        tableWidget_batteryCells_max = new QTableWidget(layoutWidget);
        if (tableWidget_batteryCells_max->columnCount() < 11)
            tableWidget_batteryCells_max->setColumnCount(11);
        if (tableWidget_batteryCells_max->rowCount() < 8)
            tableWidget_batteryCells_max->setRowCount(8);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_batteryCells_max->setItem(0, 0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_batteryCells_max->setItem(0, 1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_batteryCells_max->setItem(0, 2, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_batteryCells_max->setItem(1, 1, __qtablewidgetitem6);
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

        label_17 = new QLabel(layoutWidget);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setAlignment(Qt::AlignCenter);

        verticalLayout_10->addWidget(label_17);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        l_max_bat = new QLabel(layoutWidget);
        l_max_bat->setObjectName(QStringLiteral("l_max_bat"));
        l_max_bat->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(l_max_bat, 0, 0, 1, 1);

        l_max_volt = new QLabel(layoutWidget);
        l_max_volt->setObjectName(QStringLiteral("l_max_volt"));
        l_max_volt->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(l_max_volt, 0, 1, 1, 1);


        verticalLayout_10->addLayout(gridLayout_6);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer_3);

        label_minVoltage = new QLabel(layoutWidget);
        label_minVoltage->setObjectName(QStringLiteral("label_minVoltage"));
        label_minVoltage->setAlignment(Qt::AlignCenter);

        verticalLayout_10->addWidget(label_minVoltage);

        l_trip_voltageMin = new QLabel(layoutWidget);
        l_trip_voltageMin->setObjectName(QStringLiteral("l_trip_voltageMin"));
        l_trip_voltageMin->setText(QStringLiteral("0"));
        l_trip_voltageMin->setAlignment(Qt::AlignCenter);

        verticalLayout_10->addWidget(l_trip_voltageMin);

        tableWidget_batteryCells_min = new QTableWidget(layoutWidget);
        if (tableWidget_batteryCells_min->columnCount() < 11)
            tableWidget_batteryCells_min->setColumnCount(11);
        if (tableWidget_batteryCells_min->rowCount() < 8)
            tableWidget_batteryCells_min->setRowCount(8);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_batteryCells_min->setItem(0, 0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_batteryCells_min->setItem(0, 1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_batteryCells_min->setItem(0, 2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_batteryCells_min->setItem(1, 1, __qtablewidgetitem10);
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

        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setAlignment(Qt::AlignCenter);

        verticalLayout_10->addWidget(label_12);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        l_min_bat = new QLabel(layoutWidget);
        l_min_bat->setObjectName(QStringLiteral("l_min_bat"));
        l_min_bat->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(l_min_bat, 0, 1, 1, 1);

        l_min_volt = new QLabel(layoutWidget);
        l_min_volt->setObjectName(QStringLiteral("l_min_volt"));
        l_min_volt->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(l_min_volt, 0, 2, 1, 1);


        verticalLayout_10->addLayout(gridLayout_2);

        verticalSpacer_12 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer_12);

        log = new QWidget(centralWidget);
        log->setObjectName(QStringLiteral("log"));
        log->setEnabled(false);
        log->setGeometry(QRect(0, 0, 1025, 768));
        log->setStyleSheet(QLatin1String("QPushButton:focus{\n"
"color: rgb(255, 0, 4);\n"
"}\n"
"QCheckBox:focus{\n"
"background-color: rgba(255, 0, 4, 50);\n"
"}"));
        layoutWidget_3 = new QWidget(log);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(766, 10, 251, 461));
        verticalLayout_2 = new QVBoxLayout(layoutWidget_3);
        verticalLayout_2->setSpacing(5);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(10, 0, 10, 5);
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

        checkBox_BMSFile = new QCheckBox(layoutWidget_3);
        checkBox_BMSFile->setObjectName(QStringLiteral("checkBox_BMSFile"));

        verticalLayout_2->addWidget(checkBox_BMSFile);

        checkBox_GPSFile = new QCheckBox(layoutWidget_3);
        checkBox_GPSFile->setObjectName(QStringLiteral("checkBox_GPSFile"));

        verticalLayout_2->addWidget(checkBox_GPSFile);

        pushButton_defaultSettings = new QPushButton(layoutWidget_3);
        pushButton_defaultSettings->setObjectName(QStringLiteral("pushButton_defaultSettings"));

        verticalLayout_2->addWidget(pushButton_defaultSettings);

        pushButton_exit = new QPushButton(layoutWidget_3);
        pushButton_exit->setObjectName(QStringLiteral("pushButton_exit"));

        verticalLayout_2->addWidget(pushButton_exit);

        textBrowser_errors = new QTextBrowser(log);
        textBrowser_errors->setObjectName(QStringLiteral("textBrowser_errors"));
        textBrowser_errors->setGeometry(QRect(15, 10, 741, 731));
        textBrowser_errors->setFocusPolicy(Qt::NoFocus);
        textBrowser_errors->setStyleSheet(QLatin1String("font: 10pt \"Lucida Console\";\n"
"background-color: rgb(212, 212, 212);"));
        home = new QWidget(centralWidget);
        home->setObjectName(QStringLiteral("home"));
        home->setEnabled(true);
        home->setGeometry(QRect(0, 0, 1025, 768));
        home->setStyleSheet(QStringLiteral(""));
        carInfo = new QWidget(home);
        carInfo->setObjectName(QStringLiteral("carInfo"));
        carInfo->setEnabled(true);
        carInfo->setGeometry(QRect(450, 190, 221, 351));
        carInfo->setMinimumSize(QSize(150, 0));
        QFont font4;
        font4.setFamily(QStringLiteral("Latha"));
        font4.setPointSize(15);
        font4.setBold(false);
        font4.setItalic(false);
        font4.setWeight(50);
        carInfo->setFont(font4);
        carInfo->setFocusPolicy(Qt::NoFocus);
        carInfo->setStyleSheet(QLatin1String("QLabel{\n"
"font: 75 30pt \"Arial\";\n"
"}"));
        layoutWidget1 = new QWidget(carInfo);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 0, 201, 351));
        verticalLayout_3 = new QVBoxLayout(layoutWidget1);
        verticalLayout_3->setSpacing(10);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_8);

        label_speed = new QLabel(layoutWidget1);
        label_speed->setObjectName(QStringLiteral("label_speed"));
        label_speed->setStyleSheet(QStringLiteral(""));
        label_speed->setAlignment(Qt::AlignCenter);
        label_speed->setWordWrap(true);

        verticalLayout_3->addWidget(label_speed);

        l_speed = new QLabel(layoutWidget1);
        l_speed->setObjectName(QStringLiteral("l_speed"));
        QFont font5;
        font5.setFamily(QStringLiteral("Lucida Console"));
        font5.setPointSize(24);
        font5.setBold(false);
        font5.setItalic(false);
        font5.setWeight(9);
        l_speed->setFont(font5);
        l_speed->setStyleSheet(QStringLiteral("font: 75 24pt \"Lucida Console\";"));
        l_speed->setText(QStringLiteral("--"));
        l_speed->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(l_speed);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_6);

        label_voltage = new QLabel(layoutWidget1);
        label_voltage->setObjectName(QStringLiteral("label_voltage"));
        QFont font6;
        font6.setFamily(QStringLiteral("Arial"));
        font6.setPointSize(30);
        font6.setBold(false);
        font6.setItalic(false);
        font6.setWeight(9);
        label_voltage->setFont(font6);
        label_voltage->setScaledContents(true);
        label_voltage->setAlignment(Qt::AlignCenter);
        label_voltage->setWordWrap(true);

        verticalLayout_3->addWidget(label_voltage);

        l_voltage = new QLabel(layoutWidget1);
        l_voltage->setObjectName(QStringLiteral("l_voltage"));
        l_voltage->setStyleSheet(QStringLiteral("font: 75 24pt \"Lucida Console\";"));
        l_voltage->setText(QStringLiteral("--"));
        l_voltage->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(l_voltage);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_7);

        l_time = new QLabel(layoutWidget1);
        l_time->setObjectName(QStringLiteral("l_time"));
        QFont font7;
        font7.setFamily(QStringLiteral("Liberation serif"));
        font7.setPointSize(15);
        font7.setBold(true);
        font7.setItalic(false);
        font7.setWeight(75);
        l_time->setFont(font7);
        l_time->setStyleSheet(QLatin1String("font: 75 15pt \"Liberation serif\";\n"
"font-weight:bold;"));
        l_time->setText(QStringLiteral("--:--:--"));
        l_time->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(l_time);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_9);

        gridLayoutWidget = new QWidget(home);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(30, 10, 241, 698));
        batteryInfo = new QGridLayout(gridLayoutWidget);
        batteryInfo->setObjectName(QStringLiteral("batteryInfo"));
        batteryInfo->setContentsMargins(0, 0, 0, 0);
        progressBar_battery = new QProgressBar(gridLayoutWidget);
        progressBar_battery->setObjectName(QStringLiteral("progressBar_battery"));
        progressBar_battery->setEnabled(true);
        sizePolicy.setHeightForWidth(progressBar_battery->sizePolicy().hasHeightForWidth());
        progressBar_battery->setSizePolicy(sizePolicy);
        progressBar_battery->setMinimumSize(QSize(100, 620));
        progressBar_battery->setMaximumSize(QSize(100, 620));
        progressBar_battery->setFont(font1);
        progressBar_battery->setStyleSheet(QLatin1String("QProgressBar::chunk{\n"
"	background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(0, 200, 0), stop:1 rgb(90, 255,80));\n"
"}"));
        progressBar_battery->setMaximum(100);
        progressBar_battery->setValue(90);
        progressBar_battery->setAlignment(Qt::AlignCenter);
        progressBar_battery->setTextVisible(true);
        progressBar_battery->setOrientation(Qt::Vertical);
        progressBar_battery->setFormat(QStringLiteral("%p%"));

        batteryInfo->addWidget(progressBar_battery, 2, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        l_current = new QLabel(gridLayoutWidget);
        l_current->setObjectName(QStringLiteral("l_current"));
        l_current->setFont(font1);
        l_current->setStyleSheet(QStringLiteral(""));
        l_current->setText(QStringLiteral("400"));
        l_current->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(l_current);

        label_A = new QLabel(gridLayoutWidget);
        label_A->setObjectName(QStringLiteral("label_A"));
        label_A->setText(QStringLiteral("[A]"));
        label_A->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_A);


        batteryInfo->addLayout(horizontalLayout_2, 1, 1, 1, 1);

        progressBar_amps = new QProgressBar(gridLayoutWidget);
        progressBar_amps->setObjectName(QStringLiteral("progressBar_amps"));
        sizePolicy.setHeightForWidth(progressBar_amps->sizePolicy().hasHeightForWidth());
        progressBar_amps->setSizePolicy(sizePolicy);
        progressBar_amps->setMinimumSize(QSize(60, 620));
        progressBar_amps->setMaximumSize(QSize(60, 620));
        progressBar_amps->setAutoFillBackground(false);
        progressBar_amps->setStyleSheet(QLatin1String("QProgressBar:verticall {\n"
"border: 1px solid gray;\n"
"border-radius: 3px;\n"
"background: white;\n"
"padding: 1px;\n"
"text-align: right;\n"
"}\n"
"QProgressBar::chunk:vertical {\n"
"background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #00AA00, stop: 1 #88FF88);\n"
"margin-top: 2px; /* space */\n"
"height: 10px;\n"
"}"));
        progressBar_amps->setValue(50);
        progressBar_amps->setAlignment(Qt::AlignCenter);
        progressBar_amps->setTextVisible(false);
        progressBar_amps->setOrientation(Qt::Vertical);
        progressBar_amps->setInvertedAppearance(false);
        progressBar_amps->setTextDirection(QProgressBar::TopToBottom);

        batteryInfo->addWidget(progressBar_amps, 2, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        l_remdist = new QLabel(gridLayoutWidget);
        l_remdist->setObjectName(QStringLiteral("l_remdist"));
        l_remdist->setFont(font1);
        l_remdist->setStyleSheet(QStringLiteral(""));
        l_remdist->setText(QStringLiteral("60"));
        l_remdist->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(l_remdist);

        label_KM = new QLabel(gridLayoutWidget);
        label_KM->setObjectName(QStringLiteral("label_KM"));
        label_KM->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_KM);


        batteryInfo->addLayout(horizontalLayout, 1, 0, 1, 1);

        battInfo = new QWidget(home);
        battInfo->setObjectName(QStringLiteral("battInfo"));
        battInfo->setGeometry(QRect(410, 250, 301, 261));
        info_battTable = new QTableWidget(battInfo);
        if (info_battTable->columnCount() < 11)
            info_battTable->setColumnCount(11);
        if (info_battTable->rowCount() < 8)
            info_battTable->setRowCount(8);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        info_battTable->setItem(0, 0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        info_battTable->setItem(0, 1, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        info_battTable->setItem(0, 2, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        info_battTable->setItem(1, 1, __qtablewidgetitem14);
        info_battTable->setObjectName(QStringLiteral("info_battTable"));
        info_battTable->setEnabled(false);
        info_battTable->setGeometry(QRect(10, 0, 291, 261));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(100);
        sizePolicy3.setVerticalStretch(100);
        sizePolicy3.setHeightForWidth(info_battTable->sizePolicy().hasHeightForWidth());
        info_battTable->setSizePolicy(sizePolicy3);
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
        carBut = new QPushButton(home);
        carBut->setObjectName(QStringLiteral("carBut"));
        carBut->setGeometry(QRect(365, 100, 218, 148));
        carBut->setFocusPolicy(Qt::NoFocus);
        carBut->setStyleSheet(QLatin1String("#carBut:pressed{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/Buttons/TLs.png);\n"
"}\n"
"#carBut{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/Buttons/TL.png);\n"
"}"));
        mapBut = new QPushButton(home);
        mapBut->setObjectName(QStringLiteral("mapBut"));
        mapBut->setGeometry(QRect(547, 100, 218, 148));
        mapBut->setFocusPolicy(Qt::NoFocus);
        mapBut->setStyleSheet(QLatin1String("#mapBut:pressed{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/Buttons/TRs.png);\n"
"}\n"
"#mapBut{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/Buttons/TR.png);\n"
"}"));
        trafBut = new QPushButton(home);
        trafBut->setObjectName(QStringLiteral("trafBut"));
        trafBut->setGeometry(QRect(700, 185, 142, 209));
        trafBut->setFocusPolicy(Qt::NoFocus);
        trafBut->setStyleSheet(QLatin1String("#trafBut:pressed{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/Buttons/R1s.png);\n"
"}\n"
"#trafBut{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/Buttons/R1.png);\n"
"}"));
        musicBut = new QPushButton(home);
        musicBut->setObjectName(QStringLiteral("musicBut"));
        musicBut->setGeometry(QRect(695, 370, 142, 209));
        musicBut->setFocusPolicy(Qt::NoFocus);
        musicBut->setStyleSheet(QLatin1String("#musicBut:pressed{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/Buttons/R2s.png);\n"
"}\n"
"#musicBut{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/Buttons/R2.png);\n"
"}"));
        battBut = new QPushButton(home);
        battBut->setObjectName(QStringLiteral("battBut"));
        battBut->setGeometry(QRect(547, 513, 218, 148));
        battBut->setFocusPolicy(Qt::NoFocus);
        battBut->setStyleSheet(QLatin1String("#battBut:pressed{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/Buttons/LBRs.png);\n"
"}\n"
"#battBut{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/Buttons/LBR.png);\n"
"}"));
        tripBut = new QPushButton(home);
        tripBut->setObjectName(QStringLiteral("tripBut"));
        tripBut->setGeometry(QRect(290, 370, 142, 209));
        tripBut->setFocusPolicy(Qt::NoFocus);
        tripBut->setStyleSheet(QLatin1String("#tripBut:pressed{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/Buttons/L2s.png);\n"
"}\n"
"#tripBut{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/Buttons/L2.png);\n"
"}"));
        logBut = new QPushButton(home);
        logBut->setObjectName(QStringLiteral("logBut"));
        logBut->setGeometry(QRect(290, 185, 140, 209));
        logBut->setFocusPolicy(Qt::NoFocus);
        logBut->setStyleSheet(QLatin1String("#logBut:pressed{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/Buttons/L1s.png);\n"
"}\n"
"#logBut{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/Buttons/L1.png);\n"
"}"));
        optBut = new QPushButton(home);
        optBut->setObjectName(QStringLiteral("optBut"));
        optBut->setGeometry(QRect(365, 513, 218, 148));
        optBut->setFocusPolicy(Qt::NoFocus);
        optBut->setStyleSheet(QLatin1String("#optBut:pressed{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/Buttons/BLs.png);\n"
"}\n"
"#optBut{\n"
"background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/Buttons/BL.png);\n"
"}"));
        horizontalLayoutWidget_2 = new QWidget(home);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(30, 720, 661, 33));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        driver_label = new QLabel(horizontalLayoutWidget_2);
        driver_label->setObjectName(QStringLiteral("driver_label"));
        driver_label->setMaximumSize(QSize(85, 16777215));

        horizontalLayout_3->addWidget(driver_label);

        driver_name = new QLabel(horizontalLayoutWidget_2);
        driver_name->setObjectName(QStringLiteral("driver_name"));

        horizontalLayout_3->addWidget(driver_name);

        Dooricon = new QLabel(home);
        Dooricon->setObjectName(QStringLiteral("Dooricon"));
        Dooricon->setEnabled(true);
        Dooricon->setGeometry(QRect(881, 268, 50, 50));
        Dooricon->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/images/Dooricon.png);"));
        Dooricon->setFrameShape(QFrame::Box);
        Safetyswitchicon = new QLabel(home);
        Safetyswitchicon->setObjectName(QStringLiteral("Safetyswitchicon"));
        Safetyswitchicon->setEnabled(true);
        Safetyswitchicon->setGeometry(QRect(881, 439, 50, 50));
        Safetyswitchicon->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/images/Safetyswitchicon.png);"));
        GPSicon = new QLabel(home);
        GPSicon->setObjectName(QStringLiteral("GPSicon"));
        GPSicon->setEnabled(true);
        GPSicon->setGeometry(QRect(881, 211, 50, 50));
        GPSicon->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/images/GPSicon.png);"));
        GPSicon->setFrameShape(QFrame::NoFrame);
        Handbrakeicon = new QLabel(home);
        Handbrakeicon->setObjectName(QStringLiteral("Handbrakeicon"));
        Handbrakeicon->setEnabled(true);
        Handbrakeicon->setGeometry(QRect(881, 325, 50, 50));
        Handbrakeicon->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/images/Handbrakeicon.png);"));
        Neticon = new QLabel(home);
        Neticon->setObjectName(QStringLiteral("Neticon"));
        Neticon->setEnabled(true);
        Neticon->setGeometry(QRect(939, 382, 50, 50));
        Neticon->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/images/3Gicon.png);"));
        lowBatticon = new QLabel(home);
        lowBatticon->setObjectName(QStringLiteral("lowBatticon"));
        lowBatticon->setEnabled(true);
        lowBatticon->setGeometry(QRect(939, 325, 50, 50));
        lowBatticon->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/images/Lowbatticon.png);"));
        CELicon = new QLabel(home);
        CELicon->setObjectName(QStringLiteral("CELicon"));
        CELicon->setEnabled(true);
        CELicon->setGeometry(QRect(881, 382, 50, 50));
        CELicon->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/images/CELicon.png);"));
        TBSicon = new QLabel(home);
        TBSicon->setObjectName(QStringLiteral("TBSicon"));
        TBSicon->setEnabled(true);
        TBSicon->setGeometry(QRect(939, 211, 50, 50));
        TBSicon->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/images/TBSicon.png);"));
        SeatBelticon = new QLabel(home);
        SeatBelticon->setObjectName(QStringLiteral("SeatBelticon"));
        SeatBelticon->setEnabled(true);
        SeatBelticon->setGeometry(QRect(939, 268, 50, 50));
        SeatBelticon->setStyleSheet(QLatin1String("background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/images/Belticon.png);"));
        hideBatt = new QPushButton(home);
        hideBatt->setObjectName(QStringLiteral("hideBatt"));
        hideBatt->setGeometry(QRect(550, 200, 31, 31));
        hideBatt->setStyleSheet(QStringLiteral("border-image: url(:/Buttons/CloseBut.png);"));
        gridLayoutWidget->raise();
        carBut->raise();
        mapBut->raise();
        trafBut->raise();
        musicBut->raise();
        battBut->raise();
        tripBut->raise();
        logBut->raise();
        optBut->raise();
        horizontalLayoutWidget_2->raise();
        Dooricon->raise();
        Safetyswitchicon->raise();
        GPSicon->raise();
        Handbrakeicon->raise();
        Neticon->raise();
        lowBatticon->raise();
        CELicon->raise();
        TBSicon->raise();
        SeatBelticon->raise();
        carInfo->raise();
        hideBatt->raise();
        trip->raise();
        battInfo->raise();
        battery = new QWidget(centralWidget);
        battery->setObjectName(QStringLiteral("battery"));
        battery->setEnabled(false);
        battery->setGeometry(QRect(0, 0, 1025, 768));
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
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidget_cellValues->setItem(0, 0, __qtablewidgetitem15);
        tableWidget_cellValues->setObjectName(QStringLiteral("tableWidget_cellValues"));
        tableWidget_cellValues->setGeometry(QRect(10, 20, 991, 521));
        QSizePolicy sizePolicy4(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy4.setHorizontalStretch(100);
        sizePolicy4.setVerticalStretch(100);
        sizePolicy4.setHeightForWidth(tableWidget_cellValues->sizePolicy().hasHeightForWidth());
        tableWidget_cellValues->setSizePolicy(sizePolicy4);
        tableWidget_cellValues->setSizeIncrement(QSize(1, 1));
        QFont font8;
        font8.setFamily(QStringLiteral("Lucida Console"));
        font8.setPointSize(11);
        font8.setBold(true);
        font8.setItalic(false);
        font8.setWeight(75);
        tableWidget_cellValues->setFont(font8);
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
        transparentWidget->setGeometry(QRect(20, 580, 721, 131));
        QSizePolicy sizePolicy5(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(transparentWidget->sizePolicy().hasHeightForWidth());
        transparentWidget->setSizePolicy(sizePolicy5);
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
        QSizePolicy sizePolicy6(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(label_35->sizePolicy().hasHeightForWidth());
        label_35->setSizePolicy(sizePolicy6);
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
        sleep = new QWidget(centralWidget);
        sleep->setObjectName(QStringLiteral("sleep"));
        sleep->setGeometry(QRect(0, 0, 1025, 768));
        sleep->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        backBut = new QPushButton(centralWidget);
        backBut->setObjectName(QStringLiteral("backBut"));
        backBut->setGeometry(QRect(950, 690, 61, 61));
        backBut->setFocusPolicy(Qt::NoFocus);
        backBut->setStyleSheet(QStringLiteral("border-image: url(:/Buttons/BackBut.png);"));
        car = new QWidget(centralWidget);
        car->setObjectName(QStringLiteral("car"));
        car->setGeometry(QRect(0, 0, 1025, 768));
        Gearchangegauge1 = new QWidget(car);
        Gearchangegauge1->setObjectName(QStringLiteral("Gearchangegauge1"));
        Gearchangegauge1->setGeometry(QRect(120, 190, 200, 40));
        Gearchangegauge1->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:reflect, x1:0.49995, y1:0, x2:1, y2:0, stop:0 rgba(85, 248, 33, 255), stop:0.212871 rgba(205, 251, 32, 255), stop:0.712871 rgba(255, 40, 40, 255));"));
        RPMline1 = new QFrame(Gearchangegauge1);
        RPMline1->setObjectName(QStringLiteral("RPMline1"));
        RPMline1->setGeometry(QRect(100, 0, 5, 40));
        RPMline1->setFrameShape(QFrame::VLine);
        RPMline1->setFrameShadow(QFrame::Sunken);
        gear1 = new QLabel(car);
        gear1->setObjectName(QStringLiteral("gear1"));
        gear1->setGeometry(QRect(210, 160, 25, 20));
        gear1->setStyleSheet(QStringLiteral(""));
        gear1->setAlignment(Qt::AlignCenter);
        gear2 = new QLabel(car);
        gear2->setObjectName(QStringLiteral("gear2"));
        gear2->setGeometry(QRect(210, 460, 25, 20));
        gear2->setStyleSheet(QStringLiteral(""));
        gear2->setAlignment(Qt::AlignCenter);
        gear4 = new QLabel(car);
        gear4->setObjectName(QStringLiteral("gear4"));
        gear4->setGeometry(QRect(507, 460, 25, 20));
        gear4->setStyleSheet(QStringLiteral(""));
        gear4->setAlignment(Qt::AlignCenter);
        Gearchangegauge2 = new QWidget(car);
        Gearchangegauge2->setObjectName(QStringLiteral("Gearchangegauge2"));
        Gearchangegauge2->setGeometry(QRect(120, 490, 200, 40));
        Gearchangegauge2->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:reflect, x1:0.49995, y1:0, x2:1, y2:0, stop:0 rgba(85, 248, 33, 255), stop:0.212871 rgba(205, 251, 32, 255), stop:0.712871 rgba(255, 40, 40, 255));"));
        RPMline2 = new QFrame(Gearchangegauge2);
        RPMline2->setObjectName(QStringLiteral("RPMline2"));
        RPMline2->setGeometry(QRect(100, 0, 5, 40));
        RPMline2->setFrameShape(QFrame::VLine);
        RPMline2->setFrameShadow(QFrame::Sunken);
        Gearchangegauge4 = new QWidget(car);
        Gearchangegauge4->setObjectName(QStringLiteral("Gearchangegauge4"));
        Gearchangegauge4->setGeometry(QRect(420, 490, 200, 40));
        Gearchangegauge4->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:reflect, x1:0.49995, y1:0, x2:1, y2:0, stop:0 rgba(85, 248, 33, 255), stop:0.212871 rgba(205, 251, 32, 255), stop:0.712871 rgba(255, 40, 40, 255));"));
        RPMline4 = new QFrame(Gearchangegauge4);
        RPMline4->setObjectName(QStringLiteral("RPMline4"));
        RPMline4->setGeometry(QRect(100, 0, 5, 40));
        RPMline4->setFrameShape(QFrame::VLine);
        RPMline4->setFrameShadow(QFrame::Sunken);
        Gearchangegauge3 = new QWidget(car);
        Gearchangegauge3->setObjectName(QStringLiteral("Gearchangegauge3"));
        Gearchangegauge3->setGeometry(QRect(420, 190, 200, 40));
        Gearchangegauge3->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:reflect, x1:0.49995, y1:0, x2:1, y2:0, stop:0 rgba(85, 248, 33, 255), stop:0.212871 rgba(205, 251, 32, 255), stop:0.712871 rgba(255, 40, 40, 255));"));
        RPMline3 = new QFrame(Gearchangegauge3);
        RPMline3->setObjectName(QStringLiteral("RPMline3"));
        RPMline3->setGeometry(QRect(100, 0, 5, 40));
        RPMline3->setFrameShape(QFrame::VLine);
        RPMline3->setFrameShadow(QFrame::Sunken);
        gear5 = new QLabel(car);
        gear5->setObjectName(QStringLiteral("gear5"));
        gear5->setGeometry(QRect(800, 160, 25, 20));
        gear5->setStyleSheet(QStringLiteral(""));
        gear5->setAlignment(Qt::AlignCenter);
        gear3 = new QLabel(car);
        gear3->setObjectName(QStringLiteral("gear3"));
        gear3->setGeometry(QRect(507, 160, 25, 20));
        gear3->setStyleSheet(QStringLiteral(""));
        gear3->setAlignment(Qt::AlignCenter);
        horizontalLayoutWidget = new QWidget(car);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(430, 320, 171, 61));
        Revs = new QHBoxLayout(horizontalLayoutWidget);
        Revs->setObjectName(QStringLiteral("Revs"));
        Revs->setContentsMargins(0, 0, 0, 0);
        l_RPM = new QLabel(horizontalLayoutWidget);
        l_RPM->setObjectName(QStringLiteral("l_RPM"));
        l_RPM->setStyleSheet(QStringLiteral(""));

        Revs->addWidget(l_RPM);

        val_RPM = new QLabel(horizontalLayoutWidget);
        val_RPM->setObjectName(QStringLiteral("val_RPM"));
        val_RPM->setStyleSheet(QStringLiteral(""));

        Revs->addWidget(val_RPM);

        Gearchangegauge5 = new QWidget(car);
        Gearchangegauge5->setObjectName(QStringLiteral("Gearchangegauge5"));
        Gearchangegauge5->setGeometry(QRect(710, 190, 200, 40));
        Gearchangegauge5->setStyleSheet(QStringLiteral("background-color: qlineargradient(spread:reflect, x1:0.49995, y1:0, x2:1, y2:0, stop:0 rgba(85, 248, 33, 255), stop:0.212871 rgba(205, 251, 32, 255), stop:0.712871 rgba(255, 40, 40, 255));"));
        RPMline5 = new QFrame(Gearchangegauge5);
        RPMline5->setObjectName(QStringLiteral("RPMline5"));
        RPMline5->setGeometry(QRect(100, 0, 5, 40));
        RPMline5->setFrameShape(QFrame::VLine);
        RPMline5->setFrameShadow(QFrame::Sunken);
        LED1 = new QGraphicsView(car);
        LED1->setObjectName(QStringLiteral("LED1"));
        LED1->setGeometry(QRect(207, 240, 31, 31));
        LED1->setStyleSheet(QStringLiteral("border-image: url(:/images/blueLED.png);"));
        LED2 = new QGraphicsView(car);
        LED2->setObjectName(QStringLiteral("LED2"));
        LED2->setGeometry(QRect(507, 240, 31, 31));
        LED2->setStyleSheet(QStringLiteral("border-image: url(:/images/blueLED.png);"));
        LED3 = new QGraphicsView(car);
        LED3->setObjectName(QStringLiteral("LED3"));
        LED3->setGeometry(QRect(797, 240, 31, 31));
        LED3->setStyleSheet(QStringLiteral("border-image: url(:/images/blueLED.png);"));
        LED4 = new QGraphicsView(car);
        LED4->setObjectName(QStringLiteral("LED4"));
        LED4->setGeometry(QRect(207, 540, 31, 31));
        LED4->setStyleSheet(QStringLiteral("border-image: url(:/images/blueLED.png);"));
        LED5 = new QGraphicsView(car);
        LED5->setObjectName(QStringLiteral("LED5"));
        LED5->setGeometry(QRect(507, 540, 31, 31));
        LED5->setStyleSheet(QStringLiteral("border-image: url(:/images/blueLED.png);"));
        REV_HMI->setCentralWidget(centralWidget);
        map->raise();
        trip->raise();
        car->raise();
        battery->raise();
        music->raise();
        log->raise();
        traf->raise();
        sleep->raise();
        home->raise();
        backBut->raise();
        QWidget::setTabOrder(pushButton_updateTrafficData, textBrowser_traffic);
        QWidget::setTabOrder(textBrowser_traffic, pushButton_moveUp);
        QWidget::setTabOrder(pushButton_moveUp, pushButton_moveDown);
        QWidget::setTabOrder(pushButton_moveDown, checkBox_repeatThis);
        QWidget::setTabOrder(checkBox_repeatThis, checkBox_repeatAll);
        QWidget::setTabOrder(checkBox_repeatAll, toolButton_mute);
        QWidget::setTabOrder(toolButton_mute, toolButton_prev);
        QWidget::setTabOrder(toolButton_prev, toolButton_play);
        QWidget::setTabOrder(toolButton_play, toolButton_stop);
        QWidget::setTabOrder(toolButton_stop, toolButton_next);
        QWidget::setTabOrder(toolButton_next, pushButton_clear_errors);
        QWidget::setTabOrder(pushButton_clear_errors, checkBox_logGpsRaw);
        QWidget::setTabOrder(checkBox_logGpsRaw, checkBox_logBmsRaw);
        QWidget::setTabOrder(checkBox_logBmsRaw, pushButton_Runsound);
        QWidget::setTabOrder(pushButton_Runsound, checkBox_BMSFile);
        QWidget::setTabOrder(checkBox_BMSFile, checkBox_GPSFile);
        QWidget::setTabOrder(checkBox_GPSFile, pushButton_defaultSettings);
        QWidget::setTabOrder(pushButton_defaultSettings, pushButton_exit);
        QWidget::setTabOrder(pushButton_exit, pushButton_NNreset);
        QWidget::setTabOrder(pushButton_NNreset, pushButton_zoomIn);
        QWidget::setTabOrder(pushButton_zoomIn, pushButton_zoomOut);
        QWidget::setTabOrder(pushButton_zoomOut, checkBox_showComments);
        QWidget::setTabOrder(checkBox_showComments, checkBox_showTestTrack);
        QWidget::setTabOrder(checkBox_showTestTrack, checkBox_autoFollow);
        QWidget::setTabOrder(checkBox_autoFollow, checkBox_showMyTrack);
        QWidget::setTabOrder(checkBox_showMyTrack, checkBox_nightMode);
        QWidget::setTabOrder(checkBox_nightMode, mapContHide);

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
        pushButton_deleteTrack->setText(QApplication::translate("REV_HMI", "Delete track", 0));
        mapContHide->setText(QApplication::translate("REV_HMI", "Hide Controls", 0));
        showButton->setText(QString());
        pushButton_updateTrafficData->setText(QApplication::translate("REV_HMI", "Update", 0));
        label_52->setText(QApplication::translate("REV_HMI", "Main Roads WA", 0));
        label_51->setText(QApplication::translate("REV_HMI", "@Perth_Traffic", 0));
        label_53->setText(QApplication::translate("REV_HMI", "For updates on traffic issues affecting main roads in Perth...", 0));
        toolButton_mute->setText(QApplication::translate("REV_HMI", "<x", 0));
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
        label_13->setText(QApplication::translate("REV_HMI", "kWh", 0));
        label_34->setText(QApplication::translate("REV_HMI", "Energy", 0));
        label_24->setText(QApplication::translate("REV_HMI", "0 .. 100", 0));
        label_9->setText(QApplication::translate("REV_HMI", "per km", 0));
        l_trip_capacityRegenerated->setText(QApplication::translate("REV_HMI", "0.00", 0));
        label_5->setText(QApplication::translate("REV_HMI", "Avg", 0));
        label_48->setText(QApplication::translate("REV_HMI", "km/h", 0));
        l_trip_speedAvgElapsed->setText(QApplication::translate("REV_HMI", "0.00", 0));
        label_29->setText(QApplication::translate("REV_HMI", "s", 0));
        l_trip_pcurrentAvg->setText(QApplication::translate("REV_HMI", "0.00", 0));
        label_43->setText(QApplication::translate("REV_HMI", "Drive", 0));
        label_14->setText(QApplication::translate("REV_HMI", "Max", 0));
        label_16->setText(QApplication::translate("REV_HMI", "A", 0));
        label_25->setText(QApplication::translate("REV_HMI", "Charge", 0));
        l_trip_ncurrentAvg->setText(QApplication::translate("REV_HMI", "0.00", 0));
        l_trip_pcurrentMax->setText(QApplication::translate("REV_HMI", "0.00", 0));
        l_trip_Accel60->setText(QApplication::translate("REV_HMI", "0.00", 0));
        label_15->setText(QApplication::translate("REV_HMI", "kWh", 0));
        label_11->setText(QApplication::translate("REV_HMI", "0 .. 50", 0));
        label_49->setText(QApplication::translate("REV_HMI", "s", 0));
        label_19->setText(QApplication::translate("REV_HMI", "Used", 0));
        label_28->setText(QApplication::translate("REV_HMI", "A", 0));
        l_trip_ncurrentMax->setText(QApplication::translate("REV_HMI", "0.00", 0));
        label_3->setText(QApplication::translate("REV_HMI", "Distance", 0));
        label_2->setText(QApplication::translate("REV_HMI", "Trip Statistics", 0));
        label_40->setText(QApplication::translate("REV_HMI", "Acceleration", 0));
        label_22->setText(QApplication::translate("REV_HMI", "Regenerated", 0));
        label_27->setText(QApplication::translate("REV_HMI", "Speed", 0));
        editname_label->setText(QApplication::translate("REV_HMI", "Name", 0));
        pushButton_stopRecording->setText(QApplication::translate("REV_HMI", "Stop", 0));
        pushButton_startRecording->setText(QApplication::translate("REV_HMI", "Start", 0));
        pushButton_changeRange->setText(QApplication::translate("REV_HMI", "Change max range", 0));
        label_10->setText(QApplication::translate("REV_HMI", "Elapsed", 0));
        label_4->setText(QApplication::translate("REV_HMI", "Driving", 0));
        pushButton_tripReset->setText(QApplication::translate("REV_HMI", "Reset Trip", 0));
        label_54->setText(QApplication::translate("REV_HMI", "Export to:", 0));
        pushButton_location->setText(QApplication::translate("REV_HMI", "Location", 0));
        pushButton_export->setText(QApplication::translate("REV_HMI", "Export", 0));
        label_exportLocation->setHtml(QApplication::translate("REV_HMI", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Arial'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt;\">Location Directory</span></p></body></html>", 0));
        label_maxVoltage->setText(QApplication::translate("REV_HMI", "Max. Voltage", 0));

        const bool __sortingEnabled = tableWidget_batteryCells_max->isSortingEnabled();
        tableWidget_batteryCells_max->setSortingEnabled(false);
        tableWidget_batteryCells_max->setSortingEnabled(__sortingEnabled);

        label_17->setText(QApplication::translate("REV_HMI", "Maximum Cell", 0));
        l_max_bat->setText(QApplication::translate("REV_HMI", "--", 0));
        l_max_volt->setText(QApplication::translate("REV_HMI", "--", 0));
        label_minVoltage->setText(QApplication::translate("REV_HMI", "Min. Voltage", 0));

        const bool __sortingEnabled1 = tableWidget_batteryCells_min->isSortingEnabled();
        tableWidget_batteryCells_min->setSortingEnabled(false);
        tableWidget_batteryCells_min->setSortingEnabled(__sortingEnabled1);

        label_12->setText(QApplication::translate("REV_HMI", "Minimum Cell", 0));
        l_min_bat->setText(QApplication::translate("REV_HMI", "--", 0));
        l_min_volt->setText(QApplication::translate("REV_HMI", "--", 0));
        pushButton_clear_errors->setText(QApplication::translate("REV_HMI", "Clear Log", 0));
        checkBox_logGpsRaw->setText(QApplication::translate("REV_HMI", "GPS raw data", 0));
        checkBox_logBmsRaw->setText(QApplication::translate("REV_HMI", "BMS raw data", 0));
        pushButton_Runsound->setText(QApplication::translate("REV_HMI", "Engine Simu", 0));
        checkBox_BMSFile->setText(QApplication::translate("REV_HMI", "BMS File", 0));
        checkBox_GPSFile->setText(QApplication::translate("REV_HMI", "GPS File", 0));
        pushButton_defaultSettings->setText(QApplication::translate("REV_HMI", "Default Settings", 0));
        pushButton_exit->setText(QApplication::translate("REV_HMI", "Exit Program", 0));
        label_speed->setText(QApplication::translate("REV_HMI", "Speed", 0));
        label_voltage->setText(QApplication::translate("REV_HMI", "Voltage", 0));
        label_KM->setText(QApplication::translate("REV_HMI", "[Km]", 0));

        const bool __sortingEnabled2 = info_battTable->isSortingEnabled();
        info_battTable->setSortingEnabled(false);
        info_battTable->setSortingEnabled(__sortingEnabled2);

        carBut->setText(QString());
        mapBut->setText(QString());
        trafBut->setText(QString());
        musicBut->setText(QString());
        battBut->setText(QString());
        tripBut->setText(QString());
        logBut->setText(QString());
        optBut->setText(QString());
        driver_label->setText(QApplication::translate("REV_HMI", "Driver:", 0));
        driver_name->setText(QApplication::translate("REV_HMI", "Name", 0));
        Dooricon->setText(QString());
        Safetyswitchicon->setText(QString());
        GPSicon->setText(QString());
        Handbrakeicon->setText(QString());
        Neticon->setText(QString());
        lowBatticon->setText(QString());
        CELicon->setText(QString());
        TBSicon->setText(QString());
        SeatBelticon->setText(QString());
        hideBatt->setText(QString());

        const bool __sortingEnabled3 = tableWidget_cellValues->isSortingEnabled();
        tableWidget_cellValues->setSortingEnabled(false);
        tableWidget_cellValues->setSortingEnabled(__sortingEnabled3);

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
        backBut->setText(QString());
        gear1->setText(QApplication::translate("REV_HMI", "1", 0));
        gear2->setText(QApplication::translate("REV_HMI", "2", 0));
        gear4->setText(QApplication::translate("REV_HMI", "4", 0));
        gear5->setText(QApplication::translate("REV_HMI", "5", 0));
        gear3->setText(QApplication::translate("REV_HMI", "3", 0));
        l_RPM->setText(QApplication::translate("REV_HMI", "RPM :", 0));
        val_RPM->setText(QApplication::translate("REV_HMI", "0", 0));
    } // retranslateUi

};

namespace Ui {
    class REV_HMI: public Ui_REV_HMI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOTUS_HMI_H
