#include "rev_hmi.h"

/**
 * @brief REV_HMI::REV_HMI Main Class to call sub-functions
 * @param parent
 */
REV_HMI::REV_HMI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::REV_HMI)
{

    //setup UI
    ui->setupUi(this);
    //start sound (in rev_hmi)

    init_sound();

    //start debuglogging (in rev_hmi)
    init_ui_debugLogging(); // log all the messages during initialization

    //start debuglogger (in seperate class debuglogger.cpp)
    debugLogger.init();     // start logging debug output to file
    debugLogger.logMsg("Initialization started...");

    //start gps.cpp
    gps.init();

    //start bms.cpp
    bms.init();

    //start car io.cpp
   // io.init();

    //media.init();

    //?
    soundOn = false;

    //sets max range of car (in km)
    maxRange = settings.value("car/maxrange",MAXRANGE).toInt();

    // wire up user interface with the backend modules

    //if lotus, can send data via bms (in rev_hmi)
#ifdef LOTUS
    init_ui_battery();
#endif

    //start mapping (rev_hmi)
    init_ui_map();

    //start logging (rev_hmi)
    init_ui_logger();

    //init_ui_translation();  

    //start ui (rev_hmi)
    init_ui();

    //start io (rev_hmi)
    init_io();

    init_ui_player();

    //traf.init();

    //starting the gizmod for the powermate device

#ifdef GETZ

    debugLogger.logMsg("Starting gizmo daemon...");
    gizmod = new QProcess(this);
    if(!gizmod->isOpen()) {
        gizmod->start("/usr/bin/gizmod -X");
        if(!gizmod->waitForStarted()) {
            debugLogger.logMsg("Gizmod did not start!");
            debugLogger.newLine();
        }
    }

    //turn on the shortcuts (in rev_hmi)
    init_shortcuts();

#endif

    debugLogger.logMsg("Initialization completed.");
    debugLogger.newLine();

    //start timer
    QTimer* startTimer = new QTimer(this);
    startTimer->singleShot(5000, &logger, SLOT(startLogging()));


}


/**
 * @brief REV_HMI::~REV_HMI Closing Modules/Threads on exit
 */
REV_HMI::~REV_HMI()
{
    debugLogger.newLine();
    debugLogger.logMsg("Closing modules...");

    eng.close();

    gps.end();
    bms.end();
    //io.end();
    media.stop();
    //player.saveSettings();
    ui->mapWidget->saveSettings();
    logger.stopLogging();

#ifdef GETZ
    gizmod->close();
    gizmod->terminate();
#endif

    //settings.setValue("language", ui->comboBox_language->currentText());

    debugLogger.logMsg("Modules closed. Exiting...");
    debugLogger.end();
    delete ui;
}

/**
 * @brief REV_HMI::changeEvent Language Change Event
 * @param e
 */
void REV_HMI::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}


// === INIT FUNCTIONS ==================================================================================================================

#ifdef GETZ
/**
 * @brief REV_HMI::init_shortcuts Sets up the shortcut keys for REV Eco
 */
void REV_HMI::init_shortcuts() {
    //Adding shortcuts


    playPause = new QShortcut(QKeySequence(Qt::Key_P),ui->centralWidget);
    nextTrack = new QShortcut(QKeySequence(Qt::Key_BracketRight),ui->centralWidget);
    prevTrack = new QShortcut(QKeySequence(Qt::Key_BracketLeft),ui->centralWidget);
    volUp = new QShortcut(QKeySequence(Qt::Key_Period),ui->centralWidget);
    volDown = new QShortcut(QKeySequence(Qt::Key_Comma),ui->centralWidget);

    nextTab = new QShortcut(QKeySequence(Qt::Key_W),ui->centralWidget);
    prevTab = new QShortcut(QKeySequence(Qt::Key_Q),ui->centralWidget);
    changePage = new QShortcut(QKeySequence(Qt::Key_E),ui->centralWidget);
    changeHome = new QShortcut(QKeySequence(Qt::Key_Escape),ui->centralWidget);

    connect(volUp, SIGNAL(activated()),this,SLOT(incVol()));
    connect(volDown, SIGNAL(activated()),this,SLOT(decVol()));
    connect(changePage, SIGNAL(activated()), this, SLOT(enterPage()));
    connect(changeHome, SIGNAL(activated()), this, SLOT(leavePage()));
    connect(nextTab, SIGNAL(activated()),this,SLOT(changeNextTab()));
    connect(prevTab, SIGNAL(activated()),this,SLOT(changePrevTab()));
}
#endif

/**
 * @brief REV_HMI::init_ui Initialises the UI
 */
void REV_HMI::init_ui()
{
    graphIV(ui->IVPlot);
    graphEfficiency(ui->efficiencyPlot);

    efficiencyCount = 75;
    totalRecords = 100;

    //changing display will add later
    night = QTime(18,00);
    day = QTime(07,00);
    midnight = QTime(00,00);
    isNight=settings.value("car/night",false).toBool();

    //Change display to darker tint for night, after 1800 before 0700
    /*if(QTime::currentTime().operator>(night) && !isNight)
        nightMode(true);
    else if(QTime::currentTime().operator>(day) && QTime::currentTime().operator<(night) && isNight)
        nightMode(false);
*/


#ifdef LOTUS
    ui->backBut->hide();
    ui->battery->hide(); ui->battery->setDisabled(true); ui->battInfo->hide();
    ui->hideBatt->hide();
#endif

    tabIndex = 3;
    onHome = true;

    ui->menuButt->show(); ui->menuButt->setEnabled(true);
    ui->home->show(); ui->home->setDisabled(false);
    ui->map->hide(); ui->map->setDisabled(true);
    //ui->traf->hide(); ui->traf->setDisabled(true);
    ui->music->hide(); ui->music->setDisabled(true);
    ui->trip->hide(); ui->trip->setDisabled(true);
    ui->log->hide(); ui->log->setDisabled(true);

    ui->tempBlack->hide();ui->tempBlack->setDisabled(true);

    ui->homeBut->setFocus();

    ui->driver_name->setText(settings.value("driver/name",defaultdriver).toString());

    ui->editname->setText(settings.value("driver/name",defaultdriver).toString());

    // update the user interface
    connect(ui->editname, SIGNAL(textChanged()), this, SLOT(driverChanged()));
    connect(&gps, SIGNAL(updated(PositionData)), this, SLOT(update_ui_gps(PositionData)));
    connect(&bms, SIGNAL(updated(BatteryData)), this, SLOT(update_ui_battery(BatteryData)));
    connect(&logger, SIGNAL(updated(TripData)), this, SLOT(update_ui_trip(TripData)));

}

/**
 * @brief REV_HMI::init_io Initialises the I/O Module
 */
void REV_HMI::init_io()
{
    ui->Dooricon->setVisible(false);
    ui->SeatBelticon->setVisible(false);
    ui->Handbrakeicon->setVisible(false);
    ui->CELicon->setVisible(false);
    ui->Neticon->setVisible(false);
    ui->Safetyswitchicon->setVisible(false);
    ui->lowBatticon->setVisible(false);
#ifdef GETZ
    ui->Fueldooricon->setVisible(false);
#endif

    connect(&io, SIGNAL(updated(IOData)),this, SLOT(update_ui_io(IOData)));
}

/**
 * @brief REV_HMI::init_sound Initialises the Engine Sound Replicator
 */
void REV_HMI::init_sound() {
    simuThread = new QThread;
    //Initialise volume and Engine simulation
    ui->horizontalSlider->setValue(settings.value("volume/engVol",defaultVolume).toInt());
    connect(ui->horizontalSlider, SIGNAL(sliderReleased()), this, SLOT(horizontalSlider_released()));
    (&eng)->moveToThread(simuThread);
    connect(simuThread, SIGNAL(started()), &eng, SLOT(init()));
    connect(this, SIGNAL(runEngSimu()), &eng, SLOT(runSimu()));
    connect(this, SIGNAL(click()), &eng, SLOT(click()));
    connect(this, SIGNAL(volChanged()), &eng, SLOT(volEffect()));
    connect(&eng, SIGNAL(checkRun()), this, SLOT(checkRun()));
    connect(&eng, SIGNAL(checkRPM()), this, SLOT(checkRPM()));
    connect(this,SIGNAL(lowBatt()), &eng, SLOT(lowBatt()));
    connect(&eng, SIGNAL(finished()), simuThread, SLOT(quit()));
    connect(&eng, SIGNAL(finished()), &eng, SLOT(deleteLater()));
    connect(simuThread, SIGNAL(finished()), simuThread, SLOT(deleteLater()));
    simuThread->start();
    eng.vol=(settings.value("volume/engVol",defaultVolume).toInt());
}


#ifdef LOTUS
/**
 * @brief REV_HMI::init_ui_battery Initialises the BMS in the REV Racer
 * @param cellCount
 */
void REV_HMI::init_ui_battery(int cellCount)
{
    //connect(ui->pushButton_setCharged, SIGNAL(clicked()), &bms, SLOT(resetCapacity()));

    int columnCount = (int)(sqrt(cellCount)*5/4);
    int rowCount = cellCount/columnCount;
    if (rowCount*columnCount < cellCount){
        if (cellCount-rowCount*columnCount>rowCount)
            rowCount ++;
        else
            columnCount++;
    }

    ui->info_battTable->setColumnCount(columnCount);
    ui->info_battTable->setRowCount(rowCount);
    ui->tableWidget_batteryCells_min->setColumnCount(columnCount);
    ui->tableWidget_batteryCells_min->setRowCount(rowCount);
    ui->tableWidget_batteryCells_max->setColumnCount(columnCount);
    ui->tableWidget_batteryCells_max->setRowCount(rowCount);
    ui->tableWidget_cellValues->setColumnCount(columnCount);
    ui->tableWidget_cellValues->setRowCount(rowCount);

    ui->tableWidget_cellValues->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    ui->tableWidget_cellValues->verticalHeader()->setResizeMode(QHeaderView::Stretch);
    for(int i=0; i < ui->tableWidget_cellValues->rowCount(); i++) {
        for(int j=0; j<ui->tableWidget_cellValues->columnCount();j++) {
            QTableWidgetItem *batteryCell = new QTableWidgetItem();
            batteryCell->setBackground(QBrush(Qt::SolidPattern));
            batteryCell->setBackgroundColor(QColor(Qt::white));
            ui->tableWidget_cellValues->setItem(i,j,batteryCell);
        }
    }

    ui->info_battTable->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    ui->info_battTable->verticalHeader()->setResizeMode(QHeaderView::Stretch);
    for (int i=0; i<ui->info_battTable->rowCount(); i++){
        for (int j=0; j<ui->info_battTable->columnCount(); j++){
            QTableWidgetItem *batteryCell = new QTableWidgetItem();
            batteryCell->setBackground(QBrush(Qt::SolidPattern));
            batteryCell->setBackgroundColor(QColor(Qt::white));
            //batteryCell->setFont(QFont::QFont("Lucida [Console]",6,1,false));
            ui->info_battTable->setItem(i, j, batteryCell);
        }
    }

    ui->tableWidget_batteryCells_min->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    ui->tableWidget_batteryCells_min->verticalHeader()->setResizeMode(QHeaderView::Stretch);
    for (int i=0; i<ui->tableWidget_batteryCells_min->rowCount(); i++){
        for (int j=0; j<ui->tableWidget_batteryCells_min->columnCount(); j++){
            QTableWidgetItem *batteryCell = new QTableWidgetItem();
            batteryCell->setBackground(QBrush(Qt::SolidPattern));
            batteryCell->setBackgroundColor(QColor(Qt::white));
            ui->tableWidget_batteryCells_min->setItem(i, j, batteryCell);
        }
    }

    ui->tableWidget_batteryCells_max->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    ui->tableWidget_batteryCells_max->verticalHeader()->setResizeMode(QHeaderView::Stretch);
    for (int i=0; i<ui->tableWidget_batteryCells_max->rowCount(); i++){
        for (int j=0; j<ui->tableWidget_batteryCells_max->columnCount(); j++){
            QTableWidgetItem *batteryCell = new QTableWidgetItem();
            batteryCell->setBackground(QBrush(Qt::SolidPattern));
            batteryCell->setBackgroundColor(QColor(Qt::white));
            ui->tableWidget_batteryCells_max->setItem(i, j, batteryCell);
        }
    }
}
#endif

/**
 * @brief REV_HMI::init_ui_map Initialises the Map/GPS
 */
void REV_HMI::init_ui_map()
{
    ui->mapWidget->loadSettings();

    connect(ui->pushButton_zoomIn, SIGNAL(clicked()), ui->mapWidget, SLOT(zoomIn()));
    connect(ui->pushButton_zoomOut, SIGNAL(clicked()), ui->mapWidget, SLOT(zoomOut()));

    ui->checkBox_autoFollow->setChecked(ui->mapWidget->isCentered());
    connect(ui->checkBox_autoFollow, SIGNAL(toggled(bool)), ui->mapWidget, SLOT(setCentered(bool)));
    /*ui->checkBox_nightMode->setChecked(ui->mapWidget->isNightmode());
    connect(ui->checkBox_nightMode, SIGNAL(toggled(bool)), ui->mapWidget, SLOT(toggleNightMode()));*/
    ui->checkBox_showMyTrack->setChecked(ui->mapWidget->isVisibleMyTrack());
    connect(ui->checkBox_showMyTrack, SIGNAL(toggled(bool)), ui->mapWidget, SLOT(showMyTrack(bool)));
    /*ui->checkBox_showTestTrack->setChecked(ui->mapWidget->isVisibleTestTrack());
    connect(ui->checkBox_showTestTrack, SIGNAL(toggled(bool)), ui->mapWidget, SLOT(showTestTrack(bool)));
    ui->checkBox_showComments->setChecked(ui->mapWidget->isVisibleTestTrackComments());
    connect(ui->checkBox_showComments, SIGNAL(toggled(bool)), ui->mapWidget, SLOT(showTestTrackComments(bool)));
    ui->checkBox_showComments->setEnabled(ui->mapWidget->isVisibleTestTrack());
    connect(ui->checkBox_showTestTrack, SIGNAL(toggled(bool)), ui->checkBox_showComments, SLOT(setEnabled(bool)));*/
}

/**
 * @brief REV_HMI::init_ui_player Initialises the Media Player
 */
void REV_HMI::init_ui_player()
{
    //ui->seekSlider->setMediaObject(player.mediaObject);
    //ui->volumeSlider->setAudioOutput(player.audioOutput);

    connect(ui->pushButton_startPlayer, SIGNAL(clicked()), &media, SLOT(start()));

    connect(ui->pushButton_play, SIGNAL(clicked()), this, SLOT(on_pushButton_playPause()));
    connect(ui->pushButton_stop, SIGNAL(clicked()), &media, SLOT(stop()));
    connect(ui->pushButton_next, SIGNAL(clicked()), &media, SLOT(next()));
    connect(ui->pushButton_prev, SIGNAL(clicked()), &media, SLOT(prev()));

    connect(ui->pushButton_addSong, SIGNAL(clicked()), this, SLOT(addMedia()));

    // move to higher number when "Move Down" is clicked to fullfill user expectation
    connect(ui->pushButton_moveUp, SIGNAL(clicked()), &media, SLOT(moveItemDown()));
    connect(ui->pushButton_moveDown, SIGNAL(clicked()), &media, SLOT(moveItemUp()));

    connect(ui->pushButton_removeItem, SIGNAL(clicked()), this, SLOT(removeMedia()));

    connect(ui->pushButton_removeAll, SIGNAL(clicked()), this, SLOT(removeAllMedia()));

    connect(&media, SIGNAL(songChanged()), this, SLOT(songName()));
    connect(&media, SIGNAL(artistChanged()), this, SLOT(artist()));

    setupMediaTable();

    isPlaying = true;
}

/**
 * @brief REV_HMI::init_ui_logger Initialises the Logging
 */
void REV_HMI::init_ui_logger()
{
    connect(ui->pushButton_startRecording, SIGNAL(clicked()), &logger, SLOT(startLogging()));
    connect(ui->pushButton_stopRecording, SIGNAL(clicked()), &logger, SLOT(stopLogging()));
    connect(&logger, SIGNAL(isLogging(bool)), this, SLOT(changeLogButtonStart(bool)));
    connect(&logger, SIGNAL(isPaused(bool)),  this, SLOT(changeLogButtonPause(bool)));
    connect(this, SIGNAL(nameChanged()), &logger, SLOT(nameChanged()));

    connect(&gps, SIGNAL(updated(PositionData)), &logger, SLOT(updatePosition(PositionData)));
    connect(&bms, SIGNAL(updated(BatteryData)), &logger, SLOT(updateBattery(BatteryData)));
    connect(&io, SIGNAL(updated(IOData)), &logger, SLOT(updateIO(IOData)));

    connect(ui->saveEfficiencyButton, SIGNAL(clicked()), this, SLOT(saveEfficiency()));
}

/**
 * @brief REV_HMI::init_ui_debugLogging Initialises the debugging for the logging
 */
void REV_HMI::init_ui_debugLogging()
{
    connect(this, SIGNAL(nameChanged()), &debugLogger, SLOT(nameChanged()));
    connect(&debugLogger, SIGNAL(displayMsg(QString)), ui->textBrowser_errors, SLOT(append(QString)));
    connect(ui->pushButton_clear_errors, SIGNAL(clicked()), ui->textBrowser_errors, SLOT(clear()));
    connect(ui->checkBox_logGpsRaw, SIGNAL(toggled(bool)), &gps, SLOT(displayRawData(bool)));
    connect(ui->checkBox_logBmsRaw, SIGNAL(toggled(bool)), &bms, SLOT(displayRawData(bool)));
    connect(ui->checkBox_BMSFile, SIGNAL(toggled(bool)), &bms, SLOT(saveCommands(bool)));
    connect(ui->checkBox_GPSFile, SIGNAL(toggled(bool)), &gps, SLOT(saveCommands(bool)));

    connect(&eng, SIGNAL(debugMsg(QtMsgType, QString, QString)), &debugLogger, SLOT(logMsg(QtMsgType, QString, QString)));
    connect(&gps, SIGNAL(debugMsg(QtMsgType, QString, QString)), &debugLogger, SLOT(logMsg(QtMsgType, QString, QString)));
    connect(&bms, SIGNAL(debugMsg(QtMsgType, QString, QString)), &debugLogger, SLOT(logMsg(QtMsgType, QString, QString)));
//    connect(&traf, SIGNAL(debugMsg(QtMsgType, QString, QString)), &debugLogger, SLOT(logMsg(QtMsgType, QString, QString)));
//    connect(&player, SIGNAL(debugMsg(QtMsgType, QString, QString)), &debugLogger, SLOT(logMsg(QtMsgType, QString, QString)));
    connect(&logger, SIGNAL(debugMsg(QtMsgType, QString, QString)), &debugLogger, SLOT(logMsg(QtMsgType, QString, QString)));
    connect(ui->mapWidget, SIGNAL(debugMsg(QtMsgType, QString, QString)), &debugLogger, SLOT(logMsg(QtMsgType, QString, QString)));

    // display errors on the main screen
    ui->TBSicon->setVisible(true);
    connect(&bms, SIGNAL(error(bool)), ui->TBSicon, SLOT(setVisible(bool)));
}


/*void REV_HMI::init_ui_translation()
{
    QStringList languageFiles = QDir().current().entryList(QStringList("*_*.qm"), QDir::Files | QDir::Readable);
    foreach (QString file, languageFiles){
        // pick country and language out of the file name
        QStringList parts = file.split("_");
        QString language = parts.value(parts.count() - 2).toLower();
        QString country  = parts.value(parts.count() - 1).toUpper();
       country.chop(3);    //remove .qm file extension
        QString languageName;
        if (language.length()==2 && country.length()==2)
            languageName = QLocale().languageToString(QLocale(language+"_"+country).language());
        if (country.length()==2){
            language = country.toLower();
            languageName = QLocale().languageToString(QLocale(language).language());
        }
        languages.insert(languageName, file);
    }

    //ui->comboBox_language->addItems(QStringList(""));
    ui->comboBox_language->addItems(languages.keys());
    ui->comboBox_language->setCurrentIndex(languages.keys().indexOf(
            settings.value("language", "English").toString()));
}*/


// === NAVIGATION ===============================================================================================================


#ifdef GETZ
/**
 * @brief REV_HMI::changeNextTab changing to the next button
 */
void REV_HMI::changeNextTab()
{
    if(onHome) {
        tabIndex++;
        if(tabIndex > 5) tabIndex = 1;
        setInfo();
    }
}
#endif

#ifdef GETZ
/**
 * @brief REV_HMI::changePrevTab changing to the previous button
 */
void REV_HMI::changePrevTab()
{
    if(onHome) {
        tabIndex--;
        if(tabIndex <= 0) tabIndex = 5;
        setInfo();
    }
}
#endif

/**
 * @brief REV_HMI::setInfo Focuses on the button, colouring in the button when focused
 */
void REV_HMI::setInfo()
{
    if(!soundOn) {
        emit click();
    }
    switch(tabIndex) {
#ifdef GETZ
    case 1: {
        ui->logBut->setFocus();
        break;
    }
    case 2: {
        ui->tripBut->setFocus();
        break;
    }
    case 3: {
        ui->homeBut->setFocus();
        break;
    }
    case 4: {
        ui->musicBut->setFocus();
        break;
    }
    case 5: {
        ui->mapBut->setFocus();
        break;
    }

#endif

#ifdef LOTUS
    case 6: {
        ui->battBut->setFocus();
        break;
    }

#endif
    }
}

/**
 * @brief REV_HMI::enterPage Entering the correct window
 */
void REV_HMI::enterPage()
{
    if(!soundOn) {
        emit click();
    }

 switch(tabIndex){
   case 1:{//log
        onHome = false;
        ui->home->hide();
        ui->map->hide();
        ui->music->hide();
        ui->trip->hide();
        ui->log->show();
        ui->logBut->setFocus();

        ui->home->setDisabled(true);
        ui->map->setDisabled(true);
        ui->music->setDisabled(true);
        ui->trip->setDisabled(true);
        ui->log->setDisabled(false);

        ui->menuButt->setDisabled(true);

#ifdef LOTUS
            ui->battery->setDisabled(true);
            ui->battery->hide();
#endif
        break;
    }

    case 2: {//trip
        onHome = false;
        ui->home->hide();
        ui->map->hide();
        ui->music->hide();
        ui->log->hide();
        ui->trip->show();
        ui->tripBut->setFocus();

        ui->home->setDisabled(true);
        ui->map->setDisabled(true);
        ui->music->setDisabled(true);
        ui->trip->setDisabled(false);
        ui->log->setDisabled(true);
        ui->menuButt->setDisabled(true);

#ifdef LOTUS
            ui->battery->setDisabled(true);
            ui->battery->hide();
#endif
        break;
    }

    case 3: {//home
        onHome = true;
        ui->home->show();
        ui->map->hide();
        ui->music->hide();
        ui->trip->hide();
        ui->log->hide();

        ui->home->setDisabled(false);
        ui->map->setDisabled(true);
        ui->music->setDisabled(true);
        ui->trip->setDisabled(true);
        ui->log->setDisabled(true);
        ui->menuButt->setDisabled(false);

#ifdef LOTUS
            ui->battery->setDisabled(true);
            ui->battery->hide();
#endif
            //tabIndex = prevtabIndex;
            setInfo();
        break;
    }

    case 4: {//music
        onHome = false;
        ui->home->hide();
        ui->map->hide();
        ui->music->show();
        ui->trip->hide();
        ui->log->hide();
        ui->musicBut->setFocus();

        ui->home->setDisabled(true);
        ui->map->setDisabled(true);
        ui->music->setDisabled(false);
        ui->trip->setDisabled(true);
        ui->log->setDisabled(true);
        ui->menuButt->setDisabled(true);

#ifdef LOTUS
        ui->battery->hide();
        ui->battery->setDisabled(true);
#endif
        break;
    }

    case 5: {//map
        onHome = false;
        ui->home->hide();
        ui->map->show();
        ui->music->hide();
        ui->trip->hide();
        ui->log->hide();
        ui->musicBut->setFocus();

        ui->home->setDisabled(true);
        ui->map->setDisabled(false);
        ui->music->setDisabled(true);
        ui->trip->setDisabled(true);
        ui->log->setDisabled(true);
        ui->menuButt->setDisabled(true);

        ui->mapControls->setEnabled(true);
        ui->mapControls->show();

#ifdef LOTUS
            ui->battery->hide();
            ui->menuButt->setDisabled(false);
#endif
        break;
    }

#ifdef LOTUS
    case 6: {//battery
        onHome = false;
        ui->home->hide();
        ui->map->hide();
        ui->music->hide();
        ui->battery->show();
        ui->trip->hide();
        ui->log->hide();

        ui->home->setDisabled(true);
        ui->map->setDisabled(true);
        ui->music->setDisabled(true);
        ui->battery->setDisabled(false);
        ui->trip->setDisabled(true);
        ui->log->setDisabled(true);
        break;
    }
#endif
    }
}

/**
 * @brief REV_HMI::leavePage Escaping to the home window
 */
void REV_HMI::leavePage()
{
    if(onHome) {
        return;
    }
    onHome = true;
    prevtabIndex = tabIndex;
    tabIndex = 3;
    enterPage();
}

/**
 * @brief REV_HMI::driverChanged Changing the driver name
 */
void REV_HMI::driverChanged() {
    QString name = ui->editname->toPlainText();
    settings.setValue("driver/name", name);
    ui->driver_name->setText(name);
    emit nameChanged();
}

/**
  * Functions for the lotus clicking
  */
#ifdef LOTUS
void REV_HMI::on_mapBut_clicked()
{
    tabIndex = 5; enterPage();
}

void REV_HMI::on_musicBut_clicked()
{
    tabIndex = 4; enterPage();
}

void REV_HMI::on_tripBut_clicked()
{
    tabIndex = 2; enterPage();
}

void REV_HMI::on_logBut_clicked()
{
    tabIndex = 1; enterPage();
}

void REV_HMI::on_battBut_clicked()
{
    tabIndex = 6; enterPage();
}

void REV_HMI::on_homeBut_clicked()
{
    tabIndex = 3; enterPage();
}

void REV_HMI::on_hideBatt_clicked()
{
    ui->battInfo->hide();
    ui->hideBatt->hide();
    ui->carInfo->show();
}

#endif


// === UPDATE FUNCTIONS ==============================================================================

/**
 * @brief REV_HMI::update_ui_gps Updates the Maps/GPS data
 * @param positionData
 */
void REV_HMI::update_ui_gps(PositionData positionData)
{
    ui->l_time->setText(positionData.UTCDateTime.toLocalTime().toString(" h:mm AP "));

    if (positionData.valid)
    {
        ui->GPSicon->hide();
        QString s, lat, lon;
        s.setNum((int)positionData.speed);
        lat.setNum(positionData.latitude);
        lon.setNum(positionData.longitude);
        ui->l_speed->setText(s);
        ui->mapWidget->setMyPos(positionData.latitude, positionData.longitude, positionData.heading);

        if (speedList.size() < 3600) {
            speedList<<(int)positionData.speed;
        }
        else {
            speedList.removeFirst();
            speedList<<(int)positionData.speed;
        }

#ifdef GETZ
  /*      ui->valFix->setText("Yes");
        ui->valLat->setText(lat);
        ui->valLon->setText(lon);*/
#endif
//        ui->progressBar_gpsReception->setValue(positionData.numSat);

/*        if (positionData.hdop>1.0)
            ui->progressBar_precision->setValue((int)(100.0/positionData.hdop));
        else
            ui->progressBar_precision->setValue(100);
*/
    }
    else{
        ui->GPSicon->show();
        ui->l_speed->setText("--");
#ifdef GETZ
 /*       ui->valFix->setText("No");
        ui->valLat->setText("---.-");
        ui->valLon->setText("---.-");*/
#endif
//        ui->progressBar_precision->setValue(0);
//        ui->progressBar_gpsReception->setValue(0);
    }
}

/**
 * @brief REV_HMI::update_ui_battery Updates the battery data
 * @param batteryData
 */
void REV_HMI::update_ui_battery(BatteryData batteryData)
{
    /*
    //Change display to darker tint for night, after 1800 before 0700
    if(QTime::currentTime().operator>(night) && !isNight)
        nightMode(true);
    else if(QTime::currentTime().operator>(day) && QTime::currentTime().operator<(night) && isNight)
        nightMode(false);
*/
#ifdef LOTUS
    // Tab "Main"
    QString bat1;
    QString bat2;
    bat1.setNum((int)batteryData.voltage);
    QString bat3 = bat1;
    bat3 = bat3 + " V";
/*    bat2.setNum(bms.getCellVoltageTotal());
    bat2.prepend("(");
    bat2.append(")");
    bat1.append(bat2);
*/
    ui->l_voltage->setText(bat3);
    ui->l_current->setText(QString().setNum(batteryData.current, 'f', 2));

    // Trip Min/Max Cell Voltages
    QString maxb;
    QString minb;
    minb.setNum(bms.global_getMinimumBatteryCell());
    maxb.setNum(bms.global_getMaximumBatteryCell());
    minb = "(No. " + minb + ")";
    maxb = "(No. " + maxb + ")";

    ui->l_min_bat->setText(minb);
    ui->l_min_volt->setNum(bms.global_getMinimumBatteryVoltage());
    ui->l_max_bat->setText(maxb);
    ui->l_max_volt->setNum(bms.global_getMaximumBatteryVoltage());

    //Cell Tab
    QString cellAverage;
    cellAverage.sprintf("%.2f",bms.getAverageVoltage());
    ui->l_cell_ave->setText(cellAverage);
    ui->l_cell_min->setNum(bms.getMinimumBatteryVoltage());
    //Show batt table on main page if a battery cell is lower than constraint
    if(bms.getMinimumBatteryVoltage() < bms.getBarlow()) {
        ui->carInfo->hide();ui->battInfo->show(); ui->hideBatt->show();
        emit lowBatt();
    }
    ui->l_cell_max->setNum(bms.getMaximumBatteryVoltage());

    ui->est_cap->setNum(100*(batteryData.ampHour)/60);

    if (batteryData.current>0){
        ui->progressBar_amps->setStyleSheet("QProgressBar:verticall {border: 1px solid gray; border-radius: 3px;background: white;padding: 1px;text-align: right;}QProgressBar::chunk:vertical {background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #0000AA, stop: 1 #8888FF);margin-top: 2px; /* space */height: 10px;}");
        ui->progressBar_amps->setValue((int)(batteryData.current/batteryData.batteryType.maxChargeCurrent*100));
    }
    else{
        ui->progressBar_amps->setStyleSheet("QProgressBar:verticall {border: 1px solid gray; border-radius: 3px;background: white;padding: 1px;text-align: right;}QProgressBar::chunk:vertical {background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #00AA00, stop: 1 #88FF88);margin-top: 2px; /* space */height: 10px;}");
        ui->progressBar_amps->setValue((int)(-1*batteryData.current/batteryData.batteryType.maxDischargeCurrent*100));
    }

    float pcent;

    /*float bh = bms.getBarhigh();
    float bl = bms.getBarlow();
    if(bms.getCellLowAverage() >= bh) {
        pcent = 100;
    }
    else {
        int m = (int) 100/(bh-bl); //166.77
        pcent = m*(bms.getCellLowAverage()-bl);
    }*/

    pcent = (batteryData.voltage/305.5)*100;
    if (pcent > 100) pcent = 100;
    if (pcent < 0) pcent = 0;
    if (pcent >= 50) {
        ui->progressBar_battery->setStyleSheet("QProgressBar::chunk {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 rgb(0, 200, 0), stop:1 rgb(90, 255,80));}");
        ui->lowBatticon->hide();
    }
    if (pcent >= 20 && pcent < 50) {
        ui->progressBar_battery->setStyleSheet("QProgressBar::chunk {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 rgb(240, 200, 0), stop:1 rgb(255, 230, 100);}");
        ui->lowBatticon->hide();
    }
    if (pcent < 20) {
        ui->progressBar_battery->setStyleSheet("QProgressBar::chunk {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0.5 rgb(210, 0, 0), stop:1 rgb(30, 30, 30));}");
        ui->lowBatticon->show();
        printf("low\n");
        emit lowBatt();
    }
    ui->progressBar_battery->setValue(pcent);
    QString s;
    s.setNum((int) (maxRange*pcent/100));
    ui->l_remdist->setText(s);
    QColor cellColor;
    if(batteryData.cellNumber > ui->info_battTable->columnCount()*ui->info_battTable->rowCount())
        init_ui_battery(batteryData.cellNumber);
    int r = ui->info_battTable->rowCount();
    int c = ui->info_battTable->columnCount();

    //Tab "Cells"
    for (int i=0; i<batteryData.cellVoltage.length(); i++){
        if (i/c < r){ //check max number of rows
            cellColor = v2Color(batteryData.cellVoltage[i],batteryData.batteryType);
            ui->info_battTable->item(i/c,i%c)->setBackgroundColor(cellColor);
            cellColor = v2Color(batteryData.cellVoltage[i],batteryData.batteryType);
            if(batteryData.cellVoltage[i] < 2.8) {
                ui->tableWidget_cellValues->item(i/c,i%c)->setTextColor("white");
            }
            else {
                ui->tableWidget_cellValues->item(i/c,i%c)->setTextColor("black");
            }
            ui->tableWidget_cellValues->item(i/c,i%c)->setBackgroundColor(cellColor);
            QString cellVal;
            cellVal.sprintf("%.2f",batteryData.cellVoltage[i]);
            ui->tableWidget_cellValues->item(i/c,i%c)->setTextAlignment(Qt::AlignCenter	);
            ui->tableWidget_cellValues->item(i/c,i%c)->setText(cellVal);
        }
    }
    // Tab "Stats"
    for (int i=0; i<batteryData.cellVoltageMin.length(); i++){
        if (i/c < r){ //check max number of rows
            cellColor = v2Color(batteryData.cellVoltageMin[i],batteryData.batteryType);
            ui->tableWidget_batteryCells_min->item(i/c,i%c)->setBackgroundColor(cellColor);
        }
    }

    for (int i=0; i<batteryData.cellVoltageMax.length(); i++){
        if (i/c < r){ //check max number of rows
            cellColor = v2Color(batteryData.cellVoltageMax[i],batteryData.batteryType);
            ui->tableWidget_batteryCells_max->item(i/c,i%c)->setBackgroundColor(cellColor);
        }
    }
    QColor empty_cell = v2Color((qreal) bms.getAverageVoltage(),batteryData.batteryType);
    for(int i=batteryData.cellNumber; i < r*c  ;i++) {
        ui->tableWidget_cellValues->item(i/c,i%c)->setBackgroundColor(empty_cell);
        ui->tableWidget_batteryCells_max->item(i/c,i%c)->setBackgroundColor(empty_cell);
        ui->tableWidget_batteryCells_min->item(i/c,i%c)->setBackgroundColor(empty_cell);
        ui->tableWidget_cellValues->item(i/c,i%c)->setBackgroundColor(empty_cell);
    }
#endif

#ifdef GETZ
    QString v;
    v.setNum((int)batteryData.voltage);
    ui->l_voltage->setText(v);

    //adding voltage lsits
    if (voltageList.size() < 3600) {
        voltageList<<(int)batteryData.voltage;
    }
    else {
        voltageList.removeFirst();
        voltageList<<(int)batteryData.voltage;
    }

    ui->l_current->setText(QString().setNum(batteryData.current*-1, 'f', 1));

    totalRecords++;

    if(batteryData.current<150) {
        efficiencyCount++;
    }

    float efficiency = 0.00;

    efficiency = efficiencyCount/totalRecords*100;

    ui->efficiencyLabel->setText(QString().setNum(efficiency)+" %");

    if(efficiency<50) {
        ui->efficiencyBar->setStyleSheet("QProgressBar::chunk {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0.5 rgb(210, 0, 0), stop:1 rgb(30, 30, 30));}");
        ui->efficiencyBar->setValue((int)efficiency);
    }
    else {
        ui->efficiencyBar->setStyleSheet("QProgressBar::chunk {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 rgb(0, 200, 0), stop:1 rgb(90, 255,80));}");
        ui->efficiencyBar->setValue((int)efficiency);
    }


    if (batteryData.current < 0) {
        ui->progressBar_amps->setStyleSheet("QProgressBar:verticall {border: 1px solid gray;border-radius: 3px;background: white;padding: 1px;text-align: right;} QProgressBar::chunk:vertical {background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #00AA00, stop: 1 #66FF66);margin-top: 2px; height: 10px;}");
        ui->progressBar_amps->setValue(batteryData.current/batteryData.maxCurrent*-100);
    }

    if (batteryData.current>0){
        ui->progressBar_ampsCharge->setStyleSheet("QProgressBar:verticall {border: 1px solid gray;border-radius: 3px;background: white;padding: 1px;text-align: right;} QProgressBar::chunk:vertical {background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #00AA00, stop: 1 #66FF66);margin-top: 2px; height: 10px;}");
        ui->progressBar_ampsCharge->setValue(batteryData.current/batteryData.maxCurrent*100);
    }

    //adding current list
    if (currentList.size()<3600) {
        currentList<<(int)(batteryData.current*-1);
    }
    else {
        currentList.removeFirst();
        currentList<<(int)(batteryData.current*-1);
    }

    //battery capacity
    float pcent = batteryData.soc;
    if (pcent >= 50) {
        ui->progressBar_battery->setStyleSheet("QProgressBar::chunk {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 rgb(0, 200, 0), stop:1 rgb(90, 255,80));}");
        ui->lowBatticon->hide();
    }
    if (pcent >= 20 && pcent < 50) {
        ui->progressBar_battery->setStyleSheet("QProgressBar::chunk {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 rgb(240, 200, 0), stop:1 rgb(255, 230, 100));}");
        ui->lowBatticon->hide();
    }
    if (pcent < 20) {
        ui->progressBar_battery->setStyleSheet("QProgressBar::chunk {background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0.5 rgb(210, 0, 0), stop:1 rgb(30, 30, 30));}");
        ui->lowBatticon->show();
        emit lowBatt();
    }

    ui->progressBar_battery->setValue((int)pcent);

    currentUse = (float)batteryData.ampHours*(float)batteryData.voltage/-1000;
    debugLogger.logMsg("Charge = "+ QString().setNum(currentUse, 'f', 1));

    ui->energyUse->setText(QString().setNum(currentUse, 'f', 1));

    QString distText = ui->l_trip_distance->text();

    distance = distText.toFloat();

    float econ = currentUse/distance;

    ui->val_economy->setText(QString().setNum(econ, 'f', 2) + " kWh/km");

    ui->l_remdist->setNum((int) (maxRange*pcent/100));
#endif
}


/**
 * @brief REV_HMI::update_ui_trip Updates the trip data
 * @param tripData
 */
void REV_HMI::update_ui_trip(TripData tripData)
{

    ui->l_trip_time->setText(tripData.time.toString("hh:mm:ss"));
    ui->l_drive_time->setText(tripData.drivingTime.toString("hh:mm:ss"));

    ui->l_trip_distance->setText(QString().setNum(tripData.distance, 'f', 2));

    ui->l_trip_speedMax->setText(QString().setNum(tripData.speedMax, 'f', 1));
    ui->l_trip_speedAvgElapsed->setText(QString().setNum(tripData.speedAvgElapsed, 'f', 1));

    ui->l_trip_Accel60->setText(QString().setNum(tripData.accel50, 'f', 1));
    //ui->l_trip_Accel100->setText(QString().setNum(tripData.accel100, 'f', 1));
#ifdef LOTUS
    ui->l_trip_capacityUsed->setText(QString().setNum(fabs(tripData.energyUsed), 'f', 1));
    ui->l_trip_capacityRegenerated->setText(QString().setNum(fabs(tripData.energyRegen), 'f', 1));
    ui->l_trip_capacityPerKm->setText(QString().setNum(fabs(tripData.energyPerKm), 'f', 1));

    ui->l_trip_pcurrentAvg->setText(QString().setNum(fabs(tripData.p_currentAvg), 'f', 1));
    ui->l_trip_pcurrentMax->setText(QString().setNum(fabs(tripData.p_currentMax), 'f', 1));

    ui->l_trip_voltageMax->setNum((int)tripData.voltageMax);
    ui->l_trip_voltageMin->setNum((int)tripData.voltageMin);

    ui->l_trip_ncurrentAvg->setText(QString().setNum(fabs(tripData.n_currentAvg), 'f', 1));
    ui->l_trip_ncurrentMax->setText(QString().setNum(fabs(tripData.n_currentMax), 'f', 1));
#endif
#ifdef GETZ
    ui->l_trip_ncurrentAvg->setText(QString().setNum(fabs(tripData.currentAvg), 'f', 1));
    ui->l_trip_ncurrentMax->setText(QString().setNum(fabs(tripData.currentMax), 'f', 1));
    ui->val_tripDist->setText(QString().setNum(tripData.distance, 'f', 2) + " Km");
    ui->val_tripTime->setText(tripData.time.toString("hh:mm:ss"));
#endif

}

/**
 * @brief REV_HMI::update_ui_io Updates the I/O Data and Displays correspinding icons
 * @param ioData
 */
void REV_HMI::update_ui_io(IOData ioData) {
    ui->Dooricon->setVisible(ioData.carDoor);
    ui->SeatBelticon->setVisible(ioData.seatBelt);
    ui->Handbrakeicon->setVisible(ioData.handBrake);
    ui->CELicon->setVisible(ioData.CEL);
    ui->Neticon->setVisible(ioData.net);
    ui->Safetyswitchicon->setVisible(ioData.safetySwitch);
#ifdef GETZ
    ui->Fueldooricon->setVisible(ioData.fuelDoor);
#endif
//    ui->val_RPM->setText(QString().setNum(ioData.RPM));
    //update_ui_gears(ioData);
}

/**
 * @brief REV_HMI::nightMode Checks for night mode
 * @param night
 */
void REV_HMI::nightMode(bool night) {
    if(night) {
        ui->centralWidget->setStyleSheet("#centralWidget{border-image: url(:/images/bgn.png);}QLabel{font: 75 20pt \"Arial\";color: rgb(255, 255, 255);}QToolButton{color:rgb(255,255,255);}QCheckBox{color:rgb(255,255,255);font: 75 17pt \"Arial\";}QPushButton{font: 75 17pt \"Arial\";}");
  //      ui->checkBox_nightMode->setChecked(true);
        isNight = true;
        settings.setValue("car/night",true);
    } else{
        ui->centralWidget->setStyleSheet("#centralWidget{border-image: url(:/images/bg.png);}QLabel{font: 75 20pt \"Arial\";color: rgb(0, 0, 0);}QToolButton{color:rgb(0,0,0);}QCheckBox{color:rgb(0,0,0);font: 75 17pt \"Arial\";}QPushButton{font: 75 17pt \"Arial\";}");
    //    ui->checkBox_nightMode->setChecked(false);
        isNight = false;
        settings.setValue("car/night",false);
    }
}

/**
 * @brief REV_HMI::songName Displays the song name when changed
 */
void REV_HMI::songName() {
    ui->songName->setText(media.songName);
}

/**
 * @brief REV_HMI::artist Displays the artist when changed
 */
void REV_HMI::artist() {
    ui->artist->setText(media.artist);
}

/**
 * @brief REV_HMI::initial_charge Checks for the current energy used
 * @param batteryData
 */
void REV_HMI::initial_charge(BatteryData batteryData) {
    startCharge = (float)batteryData.ampHours*(float)batteryData.voltage/-1000;
}

/**
 * @brief REV_HMI::setupMediaTable Sets up the Media Table
 */
void REV_HMI::setupMediaTable() {
    QStringList list = media.mediaList();

    while(ui->tableWidget_mediaList->rowCount() != 0) {
        ui->tableWidget_mediaList->removeRow(0);
    }
    qDebug() << list.size();

    tableIndex = 0;
    while(tableIndex<list.size()) {
        ui->tableWidget_mediaList->insertRow(tableIndex);
        qDebug() << list.at(tableIndex);
        ui->tableWidget_mediaList->setItem(tableIndex,0,new QTableWidgetItem(list.at(tableIndex)));
        tableIndex++;
    }
}



// === BUTTONS ==================================================================


/**
 * @brief REV_HMI::changeLogButtonStart Changed the text on the logging button
 * @param isLogging
 */
void REV_HMI::changeLogButtonStart(bool isLogging)
{

    if (isLogging)
        ui->pushButton_startRecording->setText(tr("Pause"));
    else
        ui->pushButton_startRecording->setText(tr("Start"));

}

/**
 * @brief REV_HMI::changeLogButtonPause Changes the Logging button
 * @param isPaused
 */
void REV_HMI::changeLogButtonPause(bool isPaused)
{

    if (isPaused)
        ui->pushButton_startRecording->setText(tr("Resume"));
    else
        ui->pushButton_startRecording->setText(tr("Pause"));
}

/**
 * @brief REV_HMI::on_pushButton_loadTrack_clicked Opens a File dialog to add a track
 */
void REV_HMI::on_pushButton_loadTrack_clicked()
{
    QString trackFile = QFileDialog::getOpenFileName(this, tr("Load Track"), QDir::homePath(), tr("GPS Track Files (*.gpx)"));
    ui->mapWidget->loadTrack(trackFile);
    emit debugMsg(QtDebugMsg, "track", "Loaded: "+trackFile);
}

/**
 * @brief REV_HMI::on_pushButton_deleteTrack_clicked Deletes stored tracks
 */
void REV_HMI::on_pushButton_deleteTrack_clicked()
{
    QString trackFile = ui->mapWidget->getTrackFile();
    QFile tFile(trackFile);
    QMessageBox msgBox;
    msgBox.setText("Are you sure you want to delete this track?");
    msgBox.setInformativeText(trackFile);
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    int rec = msgBox.exec();
    switch(rec){
    case QMessageBox::Yes:
        if(tFile.remove())
            emit debugMsg(QtDebugMsg,"track",trackFile+" removed.");
        else
            emit debugMsg(QtDebugMsg,"track","Failed to remove "+trackFile);
        break;
    case QMessageBox::No:
        break;
    default:
        break;
    }
}

/**
 * @brief REV_HMI::on_pushButton_playPause Changes the play/pause button depending on current state
 */
void REV_HMI::on_pushButton_playPause() {
    if(isPlaying) {
        media.pause();
        ui->pushButton_play->setStyleSheet("border-image: url(:/images/play.png);");
        isPlaying = false;
    }
    else {
        media.play();
        ui->pushButton_play->setStyleSheet("border-image: url(:/images/pause.png);");
        isPlaying = true;
    }
}

/**
 * @brief REV_HMI::on_pushButton_addDirectory_clicked Adds a directory of songs to the playlist
 */
void REV_HMI::on_pushButton_addDirectory_clicked()
{
    QString musicDir = QFileDialog::getExistingDirectory(
            this, tr("Add Directory"), QDesktopServices::storageLocation(QDesktopServices::MusicLocation));
    //media.add(QDir(musicDir));
}

/*void REV_HMI::on_pushButton_addWebradio_clicked()
{
    bool ok;
    QString pw = QInputDialog::getText(this, tr("Enter Password"), tr("Password:"),
                                       QLineEdit::Password, "", &ok);
    if (!ok)
        return;
    if (pw != revPassword){
        QMessageBox::warning(this, tr("Error"), tr("Wrong password!"), QMessageBox::Ok);
        return;
    }

    settings.beginGroup("webstreams");
    QStringList webStreams = settings.allKeys();
    settings.endGroup();

    QString webStream = QInputDialog::getItem(this, tr("Select Webstream"),
                                              tr("Webstream:"), webStreams, 0, false, &ok);
    if (ok && !webStream.isEmpty())
        player.addSources(settings.value("webstreams/"+webStream).toString());
}


void REV_HMI::on_comboBox_language_currentIndexChanged(QString language)
{
    translator.load(languages.value(language));
    QApplication::installTranslator(&translator);
}*/

/**
 * @brief REV_HMI::on_pushButton_tripReset_clicked Resets the trip data
 */
void REV_HMI::on_pushButton_tripReset_clicked() {
    //Need to test with Getz's Powermate
    QMessageBox msgBox;
    msgBox.setText("Are you sure you want to reset the Trip values?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    int rec = msgBox.exec();
    switch(rec){
    case QMessageBox::Yes:
        logger.resetTrip();
        break;
    case QMessageBox::No:
        break;
    default:
        break;
    }
}

/**
 * @brief REV_HMI::addMedia Adds media to the playlist using a File dialog
 */
void REV_HMI::addMedia() {
    qDebug() << "got to add Media";
    QString songPath;
    songPath = QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "",
                tr("MP3 (*.mp3);; WAV (*.wav)" )
                );
    media.add(songPath);
    setupMediaTable();

}

/**
 * @brief REV_HMI::removeMedia Removes media from the playlist
 */
void REV_HMI::removeMedia() {
    int position = ui->tableWidget_mediaList->currentRow();
    media.remove(position);
    setupMediaTable();
}

/**
 * @brief REV_HMI::removeAllMedia Removes all the media from the playlist
 */
void REV_HMI::removeAllMedia() {
    media.removeAll();
    setupMediaTable();
}

/**
 * @brief REV_HMI::on_pushButton_defaultSettings_clicked Resets settings to default values
 */
void REV_HMI::on_pushButton_defaultSettings_clicked()
{

    gps.setDefaultSettings();
    bms.setDefaultSettings();
//    player.setDefaultSettings();
    logger.setDefaultSettings();
    ui->mapWidget->setDefaultSettings();

    settings.beginGroup("webstreams");
    settings.remove("");
    settings.setValue("96FM", "http://streaming.amnet.net.au/96fm");
    settings.setValue("SWR1","http://swr.ic.llnwd.net/stream/swr_mp3_m_swr1bwa");
    settings.setValue("SWR3","http://swr.ic.llnwd.net/stream/swr_mp3_m_swr3b");
    settings.endGroup();

    settings.beginGroup("volume");
    settings.remove("");
    settings.setValue("engVol",50);
    settings.endGroup();

    settings.beginGroup("driver");
    settings.remove("");
    settings.setValue("name","Default Driver");
    settings.endGroup();

    settings.beginGroup("car");
    settings.remove("");
    settings.setValue("maxrange",MAXRANGE);
    settings.setValue("night",false);
    settings.endGroup();
}

/**
 * @brief REV_HMI::on_pushButton_exit_clicked Exits the program
 */
void REV_HMI::on_pushButton_exit_clicked()
{QMessageBox msgBox;
    msgBox.setText("Are you sure you want to quit?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    int rec = msgBox.exec();
    switch(rec){
    case QMessageBox::Yes:
        QApplication::quit();
        break;
    case QMessageBox::No:
        break;
    default:
        break;
    }
}

/**
 * @brief REV_HMI::on_pushButton_Runsound_clicked Starts the egine audio replicating system
 */
void REV_HMI::on_pushButton_Runsound_clicked()
{
    if(!soundOn) {
        soundOn = true;
        checkRPM();
        emit runEngSimu();
    } else {//wrong logic
        soundOn = false;
    }
}

/**
 * @brief REV_HMI::on_pushButton_changeRange_clicked Changes the max range of the vehicle
 */
void REV_HMI::on_pushButton_changeRange_clicked()
{
    bool ok;
    int newmax;
    QString pw = QInputDialog::getText(this, tr("Enter Password"), tr("Password:"),
                                       QLineEdit::Password, "", &ok);
    if (!ok) {
        emit debugMsg(QtDebugMsg, "changeRange", "Getting password failed");
        return;
    }
    if (pw.compare(revPassword) != 0){
        QMessageBox::warning(this, tr("Error"), tr("Wrong password!"), QMessageBox::Ok);
        return;
    }
    QString nm = QInputDialog::getText(this, tr("Enter new maximum range"), tr("Range:"),
                                       QLineEdit::Normal, "", &ok);
    if (!ok) {
        emit debugMsg(QtDebugMsg, "changeRange", "Getting new range failed");
        return;
    }
    newmax = nm.toInt(&ok);
    if (!ok) {
        emit debugMsg(QtDebugMsg, "changeRange", "New range not integer");
        return;
    }
    settings.setValue("car/maxrange",newmax);
    maxRange = newmax;
}

/**
 * @brief REV_HMI::checkRun Checked to enable engine sound
 */
void REV_HMI::checkRun() {
    eng.run = soundOn;
}

/**
 * @brief REV_HMI::checkRPM Checks for engine speed
 */
void REV_HMI::checkRPM() {
    /*int rpm = icons.getRPM();
    eng.RPM=rpm;
    char cRPM[5];
    sprintf(cRPM, "%d",rpm);
    strcpy(eng.cRPM,cRPM);
    Remove when there is serial data for RPM from motor controller
    */

    float cur = bms.getDischargeCurrent();
    float max;
    float g;
    if(cur < 130) {
        max = 150;
        g = 3500/max;
    }
    else {
        max = 200;
        g = 8000/max;
    }
    int t = int(g*cur + 1800);
    eng.RPM=t;
    char cRPM[5];
    int tmp = t%1000;
    int rpm;
    if(tmp < 500)
        rpm = t-tmp; //Remove when able to modify frequency of playback
    else
        rpm = t+(1000-tmp);
    sprintf(cRPM, "%d",rpm);
    strcpy(eng.cRPM,cRPM);
}

/**
 * @brief REV_HMI::incVol Increases the volume of the E.A.R.S
 */
void REV_HMI::incVol() {
    int curVol = settings.value("volume/engVol",defaultVolume).toInt();
    if(curVol>100) return;
    ui->horizontalSlider->setValue(curVol+2);
}

/**
 * @brief REV_HMI::decVol Decreases the volume of E.A.R.S
 */
void REV_HMI::decVol() {
    int curVol = settings.value("volume/engVol",defaultVolume).toInt();
    if(curVol < 0) return;
    ui->horizontalSlider->setValue(curVol-2);
}

/**
 * @brief REV_HMI::on_horizontalSlider_valueChanged Chnages the volume
 * @param value
 */
void REV_HMI::on_horizontalSlider_valueChanged(int value)
{
    settings.setValue("volume/engVol",value);
    if(ui->horizontalSlider->isSliderDown())
        return;
    if(!soundOn)
        emit volChanged();
}

#ifdef LOTUS
void REV_HMI::horizontalSlider_released()
{
    int value = ui->horizontalSlider->value();
    settings.setValue("volume/engVol",value);
    if(!soundOn)
        emit volChanged();
}

// === OTHER FUNCTIONS ===

QColor REV_HMI::v2Color(double voltage, BatteryType batteryType) {
    int shade = 0;

    if(voltage <=0)
        return QColor(Qt::white);
    if(voltage<=batteryType.cellVoltageEmpty)
        return QColor(Qt::darkRed);
    if(voltage<=batteryType.cellVoltageWarn && voltage>batteryType.cellVoltageEmpty) {
        shade = 100*(voltage-batteryType.cellVoltageEmpty)/
                (batteryType.cellVoltageWarn-batteryType.cellVoltageEmpty)+155;
        return QColor(shade,0,0);
    }
    if(voltage<=batteryType.cellVoltageNormal && voltage>batteryType.cellVoltageWarn) {
        shade = 255*(voltage-batteryType.cellVoltageWarn)/
                (batteryType.cellVoltageNormal-batteryType.cellVoltageWarn);
        return QColor(255,shade,0);
    }
    if(voltage<=batteryType.cellVoltageFull && voltage>batteryType.cellVoltageNormal) {
        shade = 255*(batteryType.cellVoltageFull-voltage)/
                (batteryType.cellVoltageFull-batteryType.cellVoltageNormal);
        return QColor(shade,255,0);
    }
    if(voltage<=batteryType.cellVoltageOverCharged && voltage>batteryType.cellVoltageFull) {
        return QColor(0,255,0);
    }

    //if voltage is out of bounds
    return QColor(255,0,255);
}
#endif

/*void REV_HMI::    n_updateTrafficData_clicked()
{
    QRegExp pattern = QRegExp("#[0-9A-Za-z]+:");
    QRegExp dateOnly = QRegExp("[A-Za-z]{3} [A-za-z]{3} [0-9]{2}");
    QRegExp timeOnly = QRegExp("[0-9]{2}:[0-9]{2}");
    QRegExp split = QRegExp(":");
    ui->textBrowser_traffic->clear();
    QDomNodeList t = traf.status();

    for(int i = 0; i < t.count(); i++) {
        QDomElement el = t.at(i).toElement();
        QDomNode entries = el.firstChild();
        QString text = "";
        QString date = "";
        while(! entries.isNull() ) {
            QDomElement data = entries.toElement();
            QString tagName = data.tagName();

            if(tagName == "text") {
                text = data.text();
            }
            if(tagName == "created_at") {
                date = data.text();
            }
            entries = entries.nextSibling();
        }
        text = text.remove(pattern);

        QStringList matches;
        int pos;

        pos = dateOnly.indexIn(date);
        matches = dateOnly.capturedTexts();
        QString date2 = matches.at(0);

        pos = timeOnly.indexIn(date);
        matches = timeOnly.capturedTexts();
        QString time = matches.at(0);

        QStringList timeList = time.split(split);
        QString hr = timeList.at(0);
        QString mn = timeList.at(1);

        int hour = hr.toInt();
        int min = mn.toInt();

        QTime t =  QTime(hour,min);
        t = t.addSecs(28800); // add 8 hours for +8GMT
        time = t.toString("h:mm ap");

        text = text + "<p>" + date2 + " " + time + "</p>";
        ui->textBrowser_traffic->append(text);

        QTextCursor cursor = ui->textBrowser_traffic->textCursor();
        cursor.setPosition(0);
        ui->textBrowser_traffic->setTextCursor(cursor);
    }


}*/

/**
 * @brief REV_HMI::on_saveGraph Saves the current/speed graph to csv
 */
void REV_HMI::on_saveGraph() {
    QFile file;
    QDir::setCurrent("/home/pi/");
    file.setFileName("graph.txt");
    file.open(QIODevice::WriteOnly|QIODevice::Text);
        QString temp;
        QTextStream out(&file);
    qDebug() << currentList.size();
        for(int i = 0; i<currentList.length(); i++) {
            temp.append(QString().setNum(currentList.at(i)));
            temp.append(',');
            temp.append(QString().setNum(speedList.at(i)));
            temp.append('\n');
        }
        out<<temp;
    file.close();
    qDebug() << "wrote to graph";
}

/**
 * @brief REV_HMI::on_readGraph Reads in the current/speed graph data
 * @return
 */
QStringList REV_HMI::on_readGraph() {
    QFile file;
    QDir::setCurrent("/home/pi/");
    file.setFileName("graph.txt");
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream in(&file);
    QStringList temp;

    while(!in.atEnd()) {
        QString line = in.readLine();
        temp.append(line);
    }

    return temp;
}

/**
 * @brief REV_HMI::on_mapContHide_clicked Changes the button of the hide controls dependant on state
 */
void REV_HMI::on_mapContHide_clicked() {

    if(ui->mapControls->isHidden()) {
        ui->mapControls->setEnabled(true);
        ui->mapControls->show();
        ui->mapContHide->setText("Hide Controls");
    } else {
        ui->mapControls->setDisabled(true);
        ui->mapControls->hide();
        ui->mapContHide->setText("Show Controls");
    }

}

/**
 * @brief REV_HMI::on_pushButton_location_clicked Allows user to select the directory to save logging files
 */
void REV_HMI::on_pushButton_location_clicked()
{
    QFileDialog dialog(this);
    dialog.setDirectory("::{20D04FE0-3AEA-1069-A2D8-08002B30309D}");
    dialog.setFileMode(QFileDialog::Directory);
    dialog.setViewMode(QFileDialog::List);
    QStringList fileNames;
    if (dialog.exec()) {
        fileNames = dialog.selectedFiles();
    }
    if(fileNames.size() > 0) {
        ui->label_exportLocation->setText(fileNames.at(0));
        export_path = fileNames.at(0);
    }
}

/**
 * @brief REV_HMI::on_pushButton_export_clicked Exports the trip data
 */
void REV_HMI::on_pushButton_export_clicked()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::ExistingFiles);
    dialog.setViewMode(QFileDialog::List);
    dialog.setNameFilter(tr("REV Log Files (*.csv *.log *.gpx)"));

    QDir logDir(QDir::homePath() + "/" + settings.value("logging/logDir",defaultLogDir).toString());
    dialog.setDirectory(logDir);

    QStringList fileNames;
    if (dialog.exec()) {
        fileNames = dialog.selectedFiles();
    }

    QRegExp pattern = QRegExp("/");

    for(int i = 0; i < fileNames.count(); i++) {
        debugLogger.logMsg(fileNames.at(i));

        QStringList fileSplit = fileNames.at(i).split(pattern);
        QString copyTo = export_path + "/" + fileSplit.at(fileSplit.count()-1);

        //debugLogger.logMsg(copyTo);
        QFile::copy(fileNames.at(i),copyTo);
    }
}

#ifdef LOTUS
void REV_HMI::on_pushButton_NNreset_clicked()
{
    bms.NNreset();
}
#endif

/**
 * @brief REV_HMI::saveEfficiency Saves the current distance/energy usage statistics
 */
void REV_HMI::saveEfficiency() {

    QDir::setCurrent("/home/pi/");
    efficiencyFile.setFileName("efficiency.txt");
    efficiencyFile.open(QIODevice::WriteOnly|QIODevice::Text);

    QString temp;
    QTextStream out(&efficiencyFile);

    temp.append(QString().setNum(currentUse, 'f', 1));
    temp.append(",");
    temp.append(QString().setNum(distance, 'f', 1));

    out<<temp;
}

/**
 * @brief REV_HMI::readEfficiency Reads in the distance/energy statistics
 * @return
 */
QStringList REV_HMI::readEfficiency() {
    QDir::setCurrent("/home/pi/logging/");
    efficiencyFile.setFileName("efficiency.txt");
    efficiencyFile.open(QIODevice::ReadOnly|QIODevice::Text);

    QStringList temp;
    QTextStream in(&efficiencyFile);

     temp.clear();

     while(!in.atEnd()) {
         QString line = in.readLine();
         temp.append(line);
     }

     return temp;
}

// === GRAPHS ==================================================================

/**
 * @brief REV_HMI::graphEfficiency Graphs the efficiency of previous trips
 * @param customPlot
 */
void REV_HMI::graphEfficiency(QCustomPlot *customPlot) {

    customPlot->legend->setVisible(true);
    customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignLeft);

    customPlot->addGraph(customPlot->xAxis, customPlot->yAxis);
    customPlot->graph(0)->setPen(QPen(Qt::blue)); // line color blue for first graph
    customPlot->graph(0)->setName("Distance");

    customPlot->addGraph(customPlot->xAxis, customPlot->yAxis2);
    customPlot->graph(1)->setPen(QPen(Qt::red)); // line color red for second graph
    customPlot->graph(1)->setName("Energy Use");

    customPlot->plotLayout()->insertRow(0);
    customPlot->plotLayout()->addElement(0, 0, new QCPPlotTitle(customPlot, "Distance/Energy Use"));

    customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 5));
    customPlot->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssSquare, 5));

    //configure axes
    customPlot->xAxis->setVisible(true);
    customPlot->xAxis->setTicks(false);
    customPlot->xAxis ->setLabel("Trip");
    customPlot->yAxis->setVisible(true);
    customPlot->yAxis->setLabel("Distance (km)");
    customPlot->yAxis->setTickLabels(true);
    customPlot->yAxis2->setVisible(true);
    customPlot->yAxis2->setLabel("Energy Use (kWh)");
    customPlot->yAxis2->setTickLabels(true);

    QStringList data = readEfficiency();

    int i=0;

    if(!data.isEmpty()) {
    while(i<data.size()) {
        QString temp = data.at(i);

        QStringList splitted = temp.split(",");
        ui->efficiencyPlot->graph(0)->addData(i, splitted.at(1).toFloat());
        ui->efficiencyPlot->graph(1)->addData(i, splitted.at(0).toFloat());
        i++;
    }
    }

}

/**
 * @brief REV_HMI::graphIV Sets up the current/speed graph
 * @param customPlot
 */
void REV_HMI::graphIV(QCustomPlot *customPlot) {

    customPlot->legend->setVisible(true);
    customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignLeft);

    customPlot->addGraph(customPlot->xAxis, customPlot->yAxis);
    customPlot->graph(0)->setPen(QPen(Qt::blue)); // line color blue for first graph
    customPlot->graph(0)->setName("Current");

    customPlot->addGraph(customPlot->xAxis, customPlot->yAxis2);
    customPlot->graph(1)->setPen(QPen(Qt::red)); // line color red for second graph
    customPlot->graph(1)->setName("Speed");

    customPlot->plotLayout()->insertRow(0);
    customPlot->plotLayout()->addElement(0, 0, new QCPPlotTitle(customPlot, "Current/Speed"));

    //configure axes
    customPlot->xAxis->setVisible(true);
    customPlot->xAxis->setTicks(false);
    customPlot->xAxis ->setLabel("Time");
    customPlot->yAxis->setVisible(true);
    customPlot->yAxis->setLabel("Current (A)");
    customPlot->yAxis->setTickLabels(true);
    customPlot->yAxis2->setVisible(true);
    customPlot->yAxis2->setLabel("Speed (km/h)");
    customPlot->yAxis2->setTickLabels(true);


    // make left and bottom axes always transfer their ranges to right and top axes:
    connect(customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->xAxis, SLOT(setRange(QCPRange)));
    connect(customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->yAxis, SLOT(setRange(QCPRange)));
    connect(customPlot->yAxis2, SIGNAL(rangeChanged(QCPRange)), customPlot->yAxis2, SLOT(setRange(QCPRange)));

    connect(&bms, SIGNAL(updated(BatteryData)), this, SLOT(graphIVSlot()));
}

/**
 * @brief REV_HMI::graphIVSlot Uses data to graph current/speed graph
 */
void REV_HMI::graphIVSlot() {

    double key = QDateTime::currentDateTime().toMSecsSinceEpoch()/1000.0;

    if(!currentList.isEmpty()) {
        ui->IVPlot->graph(0)->addData(key, currentList.last());
    }

    if(!speedList.isEmpty()) {
            ui->IVPlot->graph(1)->addData(key,speedList.last());
    }

    // let the ranges scale themselves so graph 0 fits perfectly in the visible area:
    ui->IVPlot->graph(0)->rescaleAxes();
    ui->IVPlot->graph(1)->rescaleValueAxis();
    ui->IVPlot->replot();
}
