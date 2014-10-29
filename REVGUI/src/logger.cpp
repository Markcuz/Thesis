#include "logger.h"

Logger::Logger() : QObject()
{
    objName = "Logger";
    unitIMEI = settings.value("logging/unitIMEI", defaultUnitIMEI).toLongLong();
    driverName = settings.value("driver",defaultdriver).toString();

    logging = false;
    paused  = false;
    sw = true;

    logTimer = new QTimer(this);
    connect(logTimer, SIGNAL(timeout()), this, SLOT(logData()));
    zero = QTime(0,0);

/*    connectionTimer = new QTimer(this);
    connectionTimer->setInterval(10000);     // 10 seconds connection timeout
    connect(connectionTimer, SIGNAL(timeout()), this, SLOT(messageTimeout()));

    connect(&revServer, SIGNAL(readyRead()), this, SLOT(receiveMessage()));
    connect(&revServer, SIGNAL(stateChanged(QAbstractSocket::SocketState)),
            this, SLOT(connectionStateChanged(QAbstractSocket::SocketState)));
    connect(&revServer, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(connectionError(QAbstractSocket::SocketError)));
*/
}

Logger::~Logger()
{
    if (gpxFile.isOpen() || csvFile.isOpen())
        stopLogging();
}


void Logger::setDefaultSettings()
{
    stopLogging();

    settings.beginGroup("logging");
    settings.remove("");
    settings.setValue("logDir", defaultLogDir);
    settings.setValue("logName", defaultLogName);
    settings.setValue("logInterval", defaultLogInterval);
    settings.setValue("trkName", defaultTrackName);
    settings.setValue("trkNumber", 0);
    settings.setValue("unitIMEI", defaultUnitIMEI);
    settings.setValue("serverName", defaultServerName);
    settings.setValue("serverPort", defaultServerPort);
    settings.endGroup();

    emit debugMsg(QtDebugMsg, objName, "default settings applied ");
}



void Logger::startLogging()
{
    if (logging){
        if (paused)
            logTimer->start();
        else
            logTimer->stop();
        paused = !paused;
        emit isPaused(paused);
        return;         //do not initialise again
    }

    logging = true;

    startTime = QDateTime::currentDateTime();

    //increase track number with every test drive
    int trkNumber = settings.value("logging/trkNumber", 0).toInt() + 1;
    settings.setValue("logging/trkNumber", trkNumber);

    //check if directory already exists
    QDir logDir(QDir::homePath() + "/" + settings.value("logging/logDir",defaultLogDir).toString());
    if (!logDir.exists()) {
        if(!logDir.mkpath(logDir.absolutePath()))
            printf("MKPATH FAILED\n");
    }
    if(!checkDirSize(logDir.absolutePath().toUtf8().data())) {
        logging = false;
        paused = false;
        logTimer->stop();
        emit isLogging(logging);
        return;
    }

    //open the gpx file
    QString gpxFileName = startTime.toString(settings.value("logging/logName",defaultLogName).toString()) + ".gpx";
    gpxFile.setFileName(logDir.absolutePath() + "/" + gpxFileName);
    gpxWriter.setDevice(&gpxFile);

    if (gpxFile.open(QFile::WriteOnly | QFile::Text))
    {
        //init the gpx file
        gpxWriter.writeStartDocument();
        gpxWriter.setAutoFormatting(true);

        gpxWriter.writeStartElement("gpx");
        gpxWriter.writeAttribute("version", "1.1");
        gpxWriter.writeAttribute("creator", QCoreApplication::organizationName());
        gpxWriter.writeAttribute("xmlns", "http://www.topografix.com/GPX/1/1");
        gpxWriter.writeAttribute("xmlns:xsi", "http://www.w3.org/2001/XMLSchema-instance");
        gpxWriter.writeAttribute("xsi:schemaLocation", "http://www.topografix.com/GPX/1/1 http://www.topografix.com/GPX/1/1/gpx.xsd");

        gpxWriter.writeStartElement("trk");
        gpxWriter.writeTextElement("name", settings.value("logging/trkName", defaultTrackName).toString());
        gpxWriter.writeTextElement("number", settings.value("logging/trkNumber", 0).toString());

        gpxWriter.writeStartElement("trkseg");

        emit debugMsg(QtDebugMsg, objName, "logging gps data to " + gpxFile.fileName());
    }
    else
        emit debugMsg(QtWarningMsg, objName, "error writing file " + gpxFile.fileName() + " - " + gpxFile.errorString());



    //open csv file
    QString csvFileName = startTime.toString(settings.value("logging/logName",defaultLogName).toString()) + ".csv";
    csvFile.setFileName(logDir.absolutePath() + "/" + csvFileName);
    csvStream.setDevice(&csvFile);
    csvStream.setRealNumberPrecision(3);
    csvStream.setRealNumberNotation(QTextStream::FixedNotation);

    if (csvFile.open(QFile::WriteOnly | QFile::Text)){
        //init the csv file
#ifdef LOTUS
        csvStream << "name; time; distance; speed; altitude; voltage; current; energy used; energy regen; cardoor; seatbelt; handbrake; CEL; net; safety; RPM";
        //for (int i=0; i<batteryData.cellVoltage.length(); i++)
        for (int i=0; i<83; i++)    // for 83 battery cells because cellVoltage.length() may be incorrect at startup
            csvStream << "; V" << i+1;
#endif
#ifdef GETZ
        csvStream << "name; time; distance; speed; altitude; voltage; current; cardoor; seatbelt; handbrake; CEL; net; safety; RPM; fueldoor; TPS; AUX";
#endif
        csvStream << endl;
        emit debugMsg(QtDebugMsg, objName, "logging general data to " + csvFile.fileName());
    }
    else
        emit debugMsg(QtWarningMsg, objName, "error writing file " + csvFile.fileName() + " - " + csvFile.errorString());

/*
    //open server connection
    revServer.connectToHost(settings.value("logging/serverName",defaultServerName).toString(),
                            settings.value("logging/serverPort",defaultServerPort).toInt(), QIODevice::ReadWrite);
    //send initial message to server

    createMessage(reasonJourneyStart);*/

    getPrevTripData();

    startDistance = positionData.totalDistance;
#ifdef LOTUS
    startEnergyUsed = batteryData.energyUsed;
    startEnergyRegen = batteryData.energyRegenerated;
#endif

    //start timer
    logTimer->start(settings.value("logging/logInterval", defaultLogInterval).toInt());

    emit isLogging(logging);
}

void Logger::getPrevTripData()
{
    tripData.accel50=settings.value("trip/accel50",0.0).toDouble();
    tripData.accel100=settings.value("trip/accel100",0.0).toDouble();
    tripData.time=settings.value("trip/time",QTime(0,0)).toTime();
    tripData.drivingTime=settings.value("trip/drivingTime",QTime(0,0)).toTime();

    tripData.distance=settings.value("trip/distance",0.0).toDouble();

    tripData.speedAvgElapsed=settings.value("trip/speedAvgElapsed",0.0).toDouble();
    tripData.speedMax=settings.value("trip/speedMax",0.0).toDouble();

    tripData.voltageMin=settings.value("trip/voltageMin",0.0).toDouble();
    tripData.voltageMax=settings.value("trip/voltageMax",0.0).toDouble();

    tripData.currentAvg=settings.value("trip/currentAvg",0.0).toDouble();
    tripData.currentMax=settings.value("trip/currentMax",0.0).toDouble();

#ifdef LOTUS
    tripData.p_currentAvg=settings.value("trip/pcurrentAvg",0.0).toDouble();
    tripData.p_currentMax=settings.value("trip/pcurrentMax",0.0).toDouble();

    tripData.n_currentAvg=settings.value("trip/ncurrentAvg",0.0).toDouble();
    tripData.n_currentMax=settings.value("trip/ncurrentMax",0.0).toDouble();

    tripData.energyUsed=settings.value("trip/energyUsed",0.0).toDouble();
    tripData.energyRegen=settings.value("trip/energyRegen",0.0).toDouble();
    tripData.energyPerKm=settings.value("trip/energyPerKm",0.0).toDouble();
#endif
}

void Logger::resetTrip() {
    settings.setValue("trip/accel50",0.0);
    settings.setValue("trip/accel100",0.0);
    settings.setValue("trip/time",QTime(0,0));
    settings.setValue("trip/drivingTime",QTime(0,0));

    settings.setValue("trip/distance",0.0);

    settings.setValue("trip/speedAvgElapsed",0.0);
    settings.setValue("trip/speedMax",0.0);

    settings.setValue("trip/voltageMin",0.0);
    settings.setValue("trip/voltageMax",0.0);

    settings.setValue("trip/currentAvg",0.0);
    settings.setValue("trip/currentMax",0.0);

#ifdef LOTUS
    settings.setValue("trip/pcurrentAvg",0.0);
    settings.setValue("trip/pcurrentMax",0.0);

    settings.setValue("trip/ncurrentAvg",0.0);
    settings.setValue("trip/ncurrentMax",0.0);

    settings.setValue("trip/energyUsed",0.0);
    settings.setValue("trip/energyRegen",0.0);
    settings.setValue("trip/energyPerKm",0.0);
#endif
    tripData.accel50=settings.value("trip/accel50",0.0).toDouble();
    tripData.accel100=settings.value("trip/accel100",0.0).toDouble();
    tripData.time=settings.value("trip/time",QTime(0,0)).toTime();
    tripData.drivingTime=settings.value("trip/drivingTime",QTime(0,0)).toTime();

    tripData.distance=settings.value("trip/distance",0.0).toDouble();

    tripData.speedAvgElapsed=settings.value("trip/speedAvgElapsed",0.0).toDouble();
    tripData.speedMax=settings.value("trip/speedMax",0.0).toDouble();

    tripData.voltageMin=settings.value("trip/voltageMin",0.0).toDouble();
    tripData.voltageMax=settings.value("trip/voltageMax",0.0).toDouble();

    tripData.currentAvg=settings.value("trip/currentAvg",0.0).toDouble();
    tripData.currentMax=settings.value("trip/currentMax",0.0).toDouble();

#ifdef LOTUS
    tripData.p_currentAvg=settings.value("trip/pcurrentAvg",0.0).toDouble();
    tripData.p_currentMax=settings.value("trip/pcurrentMax",0.0).toDouble();

    tripData.n_currentAvg=settings.value("trip/ncurrentAvg",0.0).toDouble();
    tripData.n_currentMax=settings.value("trip/ncurrentMax",0.0).toDouble();

    tripData.energyUsed=settings.value("trip/energyUsed",0.0).toDouble();
    tripData.energyRegen=settings.value("trip/energyRegen",0.0).toDouble();
    tripData.energyPerKm=settings.value("trip/energyPerKm",0.0).toDouble();
#endif

    emit updated(tripData);
}

bool Logger::checkDirSize(char* logDir)
{
    strcat(logDir, "/");
    DIR *dir;
    struct dirent* ent;
    struct stat st;
    char buf[PATH_MAX];
    off_t total = 0LL;

    if((dir = opendir(logDir)) == NULL)
    {
        emit debugMsg(QtWarningMsg, objName, "Checking directory size failed, couldn't open dir.");
        return false;
    }
    while((ent = readdir(dir)) != NULL)
    {
        if(!strcmp(ent->d_name, ".") || !strcmp(ent->d_name, ".."))
              continue;

        sprintf(buf, "%s%s", logDir,ent->d_name);
        if(stat(buf, &st) == -1) {
            emit debugMsg(QtWarningMsg, objName, "Error checking file stat");
            printf("Couldn't stat %s: %s\n", buf, strerror(errno));
            continue;
        }
        if(S_ISREG(st.st_mode)) {
            total += st.st_size;
            if(total/1024 > 100000) { //more than 100mb?
                emit debugMsg(QtWarningMsg, objName, "Directory too large, delete oldest log files.");
                return false;
            }
        }
    }
    if(total/1024 > 90000) { //more than 100mb?
        emit debugMsg(QtWarningMsg, objName, "Directory reaching file constraint, backup and remove older log files.");
    }
    return true;

}

void Logger::stopLogging()
{
    logging = false;
    paused  = false;

    if (gpxFile.isOpen()){
        gpxWriter.writeEndDocument();
        gpxFile.close();
        emit debugMsg(QtDebugMsg, objName, "finished logging to " + gpxFile.fileName());
    }
    if (gpxFile.error())
        emit debugMsg(QtWarningMsg, objName, "error closing " + gpxFile.fileName()  + " - " + gpxFile.errorString());


    if (csvFile.isOpen()){
        csvFile.close();
        emit debugMsg(QtDebugMsg, objName, "finished logging to " + csvFile.fileName());
    }
    if (csvFile.error())
        emit debugMsg(QtWarningMsg, objName, "error closing " + csvFile.fileName()  + " - " + csvFile.errorString());

    /*if (revServer.state() == QAbstractSocket::ConnectedState)
    {
        //send final message to server
        createMessage(reasonJourneyEnd);

        emit debugMsg(QtDebugMsg, objName, "finished logging to " + revServer.peerName());
        //revServer.disconnectFromHost();
    }*/

    emit isLogging(logging);
}


void Logger::logData()
{
    tripData.time = tripData.time.addMSecs(logTimer->interval());
    settings.setValue("trip/time",tripData.time);
    if (positionData.speed > 0) {
        tripData.drivingTime = tripData.drivingTime.addMSecs(logTimer->interval());
        settings.setValue("trip/drivingTime",tripData.drivingTime);
    }

#ifdef TEST
    //reset values every time
    tripData.time = QTime(0,10,5);
    tripData.drivingTime = tripData.drivingTime.addMSecs(1000);
    tripData.distance = 123;
    tripData.speedMax = 65.43;
    tripData.accel50 = 5.84;
    tripData.accel100 = 0;
    tripData.voltageMin = 267.8;
    tripData.voltageMax = 292.1;
    tripData.currentMax = 116.6;
    // the other values are calculated

    startDistance = positionData.totalDistance - 12.30;
    startEnergyUsed = batteryData.energyUsed - 1.61;
    startEnergyRegen = batteryData.energyRegenerated - 0.53;
#endif

    if(logging) {
        // gpx file
        if (gpxFile.isOpen())
        {
            gpxWriter.writeStartElement("trkpt");
            gpxWriter.writeAttribute("lat", QString::number(positionData.latitude, 'f', 8));
            gpxWriter.writeAttribute("lon", QString::number(positionData.longitude, 'f', 8));
            gpxWriter.writeTextElement("ele", QString::number(positionData.altitude, 'f', 2));
            gpxWriter.writeTextElement("time", positionData.UTCDateTime.toString("yyyy-MM-dd'T'hh:mm:ss'Z'"));
            gpxWriter.writeTextElement("hdop", QString::number(positionData.hdop, 'f', 2));

            gpxWriter.writeStartElement("extensions");
            gpxWriter.writeTextElement("speed", QString::number(positionData.speed, 'f', 2));
            gpxWriter.writeTextElement("drivername", driverName);
            gpxWriter.writeEndElement();

            gpxWriter.writeEndElement();
        }

        // csv file
        if (csvFile.isOpen())
        {
            csvStream << driverName << "; " << (float)zero.msecsTo(tripData.time)/1000.0  << "; " << tripData.distance << "; " <<
                         positionData.speed << "; " << positionData.altitude << "; " <<
                         batteryData.voltage << "; " << batteryData.current;
#ifdef LOTUS
            csvStream << "; " << tripData.energyUsed << "; " << tripData.energyRegen;
#endif
            csvStream << "; " << boolString(ioData.carDoor) << "; " << boolString(ioData.seatBelt) << "; " << boolString(ioData.handBrake) << "; " <<
                         boolString(ioData.CEL) << "; " << boolString(ioData.net) << "; " << boolString(ioData.safetySwitch) << "; " <<
                         ioData.RPM;
#ifdef GETZ
            csvStream << "; " << boolString(ioData.fuelDoor) << "; " << ioData.TPS << "; " << ioData.AUX;
#endif
#ifdef LOTUS
            for (int i=0; i<batteryData.cellVoltage.length(); i++)
                csvStream << "; " << batteryData.cellVoltage.value(i);
#endif
            csvStream << endl;
        }

        // server
        //emit debugMsg(QtDebugMsg,objName,"Entering Send");
        //createMessage(reasonTimeInterval);
    }
    // update user interface
    emit updated(tripData);
    emit isLogging(logging);                // make sure the start/pause button is labeled correctly
}

void Logger::nameChanged()
{
    driverName = settings.value("driver",defaultdriver).toString();
}

QString Logger::boolString(bool b){ return b ? "true" : "false"; }

void Logger::updatePosition(PositionData _positionData)
{
    //emit debugMsg(QtDebugMsg,objName,"Position Data Updated");
    positionData = _positionData;

    if (logging && !paused)  // don't change the values when logging is stopped or paused
    {
        if (positionData.valid)
        {
            tripData.distance = positionData.totalDistance - startDistance;
            settings.setValue("trip/distance",tripData.distance);
            tripData.speedAvgElapsed = tripData.distance*3600000/zero.msecsTo(tripData.time);
            settings.setValue("trip/speedAvgElapsed",tripData.speedAvgElapsed);
            if (positionData.speed > tripData.speedMax){
                tripData.speedMax = positionData.speed;
                settings.setValue("trip/speedMax",tripData.speedMax);
            }
            if (positionData.speed < 5)
                accelTime.start();
            if (positionData.speed > 50 &&  (accelTime.elapsed()/1000.0 < tripData.accel50  || tripData.accel50 == 0)) {
                tripData.accel50  = accelTime.elapsed()/1000.0;
                settings.setValue("trip/accel50",tripData.accel50);
            }
            if (positionData.speed > 100 && (accelTime.elapsed()/1000.0 < tripData.accel100 || tripData.accel100 == 0)){
                tripData.accel100 = accelTime.elapsed()/1000.0;
                settings.setValue("trip/accel100",tripData.accel100);
            }
        }
    }
}


void Logger::updateBattery(BatteryData _batteryData)
{
    batteryData = _batteryData;

    if (logging && !paused)  // don't change the values when logging is stopped or paused
    {
#ifdef LOTUS
        if ((batteryData.voltage < tripData.voltageMin && batteryData.voltage > 0) || tripData.voltageMin == 0){
                tripData.voltageMin = batteryData.voltage;
                settings.setValue("trip/voltageMin",tripData.voltageMin);
        }
        if (batteryData.voltage > tripData.voltageMax && batteryData.voltage < 500){
                tripData.voltageMax = batteryData.voltage;
                settings.setValue("trip/voltageMax",tripData.voltageMax);
        }

        tripData.energyUsed = batteryData.energyUsed - startEnergyUsed;
        tripData.energyRegen = batteryData.energyRegenerated - startEnergyRegen;
        settings.setValue("trip/energyUsed",tripData.energyUsed);
        settings.setValue("trip/energyRegen",tripData.energyRegen);
        if (tripData.distance > 0.1){
            tripData.energyPerKm = (tripData.energyUsed+tripData.energyRegen)/tripData.distance;
            settings.setValue("trip/energyPerKm",tripData.energyPerKm);
        }

        if (fabs(batteryData.o_current) > tripData.currentMax){
            tripData.currentMax = fabs(batteryData.o_current);
            settings.setValue("trip/currentMax",tripData.currentMax);
        }

        if(batteryData.n_current < tripData.n_currentMax) {
            tripData.n_currentMax = batteryData.n_current;
            settings.setValue("trip/ncurrentMax",tripData.n_currentMax);
        }

        if(batteryData.p_current > tripData.p_currentMax) {
            tripData.p_currentMax = batteryData.p_current;
            settings.setValue("trip/pcurrentMax",tripData.p_currentMax);
        }

        if (tripData.time.operator >(zero)) {
            tripData.currentAvg = (tripData.currentAvg*zero.msecsTo(tripData.time) + 500*batteryData.o_current)/(zero.msecsTo(tripData.time) + 500);
            tripData.n_currentAvg = (tripData.n_currentAvg*batteryData.n_points + batteryData.n_current)/(batteryData.n_points + 1);
            tripData.p_currentAvg = (tripData.p_currentAvg*batteryData.p_points + batteryData.p_current)/(batteryData.p_points + 1);
            settings.setValue("trip/currentAvg",tripData.currentAvg);
            settings.setValue("trip/ncurrentAvg",tripData.n_currentAvg);
            settings.setValue("trip/pcurrentAvg",tripData.p_currentAvg);
        }
            //tripData.currentAvg = fabs(startCapacity-batteryData.capacityRemaining) * 3600000 / tripData.time;
        else{
            startDistance = positionData.totalDistance;
            startEnergyUsed = batteryData.energyUsed;
            startEnergyRegen = batteryData.energyRegenerated;
        }
#endif
#ifdef GETZ
        if ((batteryData.voltage < tripData.voltageMin && batteryData.voltage > 0) || tripData.voltageMin == 0){
            tripData.voltageMin = batteryData.voltage;
            settings.setValue("trip/voltageMin",tripData.voltageMin);
        }
        if (batteryData.voltage > tripData.voltageMax && batteryData.voltage < 500){
            tripData.voltageMax = batteryData.voltage;
            settings.setValue("trip/voltageMax",tripData.voltageMax);
        }

        if (fabs(batteryData.current) > tripData.currentMax){
            tripData.currentMax = fabs(batteryData.current);
            settings.setValue("trip/currentMax",tripData.currentMax);
        }

        if (tripData.time.operator >(zero)) {
            tripData.currentAvg = (tripData.currentAvg*zero.msecsTo(tripData.time) + 500*batteryData.current)/(zero.msecsTo(tripData.time) + 500);
            settings.setValue("trip/currentAvg",tripData.currentAvg);
        }
        else{
            startDistance = positionData.totalDistance;
        }
#endif
    }
}

void Logger::updateIO(IOData _ioData)
{
    ioData = _ioData;
}
/*
void Logger::createMessage(int reason)
{


    unitIMEI = 000000000000001;
    QBitArray digitalInputValues;           // put in values here
    QVector<quint16> analogInputValues;     // put in values here

    // calculations
    int messageLength = 33 + analogInputValues.size()*2 + (digitalInputValues.size()+7)/8;

    QString t;
    //emit debugMsg(QtDebugMsg, objName, t.setNum(reason));
    /*
    emit debugMsg(QtDebugMsg, objName, t.setNum((quint16)messageLength));
    emit debugMsg(QtDebugMsg, objName, t.setNum(unitIMEI));
    emit debugMsg(QtDebugMsg, objName, t.setNum((qint32) (positionData.latitude*1000000)));
    emit debugMsg(QtDebugMsg, objName, t.setNum((qint32) (positionData.longitude*1000000)));
    emit debugMsg(QtDebugMsg, objName, t.setNum((quint32)(positionData.UTCDateTime.secsTo(QDateTime(QDate(1980,1,6))))));
    emit debugMsg(QtDebugMsg, objName, t.setNum((quint8) (positionData.speed)));
    emit debugMsg(QtDebugMsg, objName, t.setNum((quint8) (positionData.heading/2)));
    emit debugMsg(QtDebugMsg, objName, t.setNum((quint8) (positionData.altitude/20)));
    /
    QBitArray reasonCode = QBitArray(16,false);
    QBitArray statusCode = QBitArray(8,false);
    //QByteArray imei = QByteArray(unitIMEI,7);

    if (reason < reasonCode.size()) {
        reasonCode.setBit(reason);
    }
    statusCode.setBit(statusIgnition, true);
    statusCode.setBit(statusGpsTimeout, !positionData.valid);

    uint rcode = 0;
    for(int i = 0; i < reasonCode.size(); i++)
    {
            rcode <<= 1;
            rcode += (int)reasonCode.at(i);
    }
    //emit debugMsg(QtDebugMsg, objName, t.setNum(rcode));
    uint scode = 0;
    for(int i = 0; i < statusCode.size(); i++)
    {
            scode <<= 1;
            scode += (int)statusCode.at(i);
    }
    //emit debugMsg(QtDebugMsg, objName, t.setNum((quint16) rcode));
    //emit debugMsg(QtDebugMsg, objName, t.setNum((quint8) scode));
    //emit debugMsg(QtDebugMsg, objName, t.setNum((quint8) digitalInputValues.size()));
    //emit debugMsg(QtDebugMsg, objName, t.setNum((quint8) analogInputValues.size()));

    QFile file("file.dat");
    file.open(QIODevice::ReadWrite);
    // creating the data array
    QByteArray data, buffer;
    QDataStream dataStream(&buffer,QIODevice::ReadWrite);
    dataStream.setByteOrder(QDataStream::BigEndian); //msb first

    dataStream << (quint8) 'R';
    dataStream << ((quint16) messageLength);
    dataStream << unitIMEI;

    dataStream << (qint32) (positionData.latitude*1000000);
    dataStream << (qint32) (positionData.longitude*1000000);
    dataStream << (quint32)(positionData.UTCDateTime.secsTo(QDateTime(QDate(1980,1,6))));
    dataStream << (quint8) (positionData.speed);
    dataStream << (quint8) (positionData.heading/2);
    dataStream << (quint8) (positionData.altitude/20);

    dataStream << (quint16) rcode;//reasonCode;
    dataStream << (quint8) scode;//statusCode;

    dataStream << (quint8) digitalInputValues.size();
    for (int i = 0; i < digitalInputValues.size() ;i++) {
        //dataStream << digitalInputValues;
    }

    dataStream << (quint8) analogInputValues.size();
    for (int i = 0; i < analogInputValues.size(); i++) {
        //dataStream << analogInputValues;
    }

    dataStream << (quint8) 50;//batteryData.capacityPercent;

    data = buffer;
    data.remove(3,1);                                   //only 7 bytes for imei number -> remove first byte
    //data.remove(25,4);                                  //remove quint32 size for reasonCode
    //data.remove(27,4);                                  //remove quint32 size for statusCode
    //data.remove(29,4);                                  //remove quint32 size for digital inputs
    //data.remove(30+(digitalInputValues.size()+7)/8,4);  //remove quint32 size for analog inputs

    dataStream << (quint16) crc16Checksum(data);
    data.append(buffer.right(2));

    messageList.append(data);
    /*
    for(int i = 0; i < data.size();i++) {
        QString p;
        QByteArray temp = messageList.first();
        char c = temp.at(i);
        int n = (int) c;
        emit debugMsg(QtDebugMsg, objName, p.setNum(i,10) + " " + t.setNum(n,10));
    }
    /
    //emit debugMsg(QtDebugMsg, objName,  t.setNum(messageList.count()));
    //if(sw) {
    sendMessage();
    //sw=false;
    //}
    //else {
    //receiveMessage();
    //}
}

void Logger::sendMessage() {
    if (revServer.state()==QAbstractSocket::ConnectedState){
        if(!connectionTimer->isActive() && !messageList.isEmpty()){

            //emit debugMsg(QtDebugMsg, objName, "Sending Message");
            revServer.write(messageList.first());
            connectionTimer->start();
        }
        else if (messageList.isEmpty() && logging == false) {
            revServer.disconnectFromHost();
        }
        else {
            receiveMessage();
        }
    }
//    else{
//        emit debugMsg(QtWarningMsg, objName, "awaiting server connection...");
//    }
}

void Logger::receiveMessage()
{
   // emit debugMsg(QtDebugMsg, objName, "Entered Recieve Message");
    QByteArray answer;
    if (revServer.bytesAvailable()>0) {
        answer = revServer.readAll();
    }
    if (!answer.isEmpty()){
        emit debugMsg(QtDebugMsg, objName, "Answer Recieved");
        if (answer.endsWith(0x06) && !messageList.isEmpty()){  // 0x06 is <ACK>
            messageList.removeFirst();
            emit debugMsg(QtDebugMsg, objName, "transmission successful - server answered <ACK>");
        }
        else if (answer.endsWith(0x15) ) {
            emit debugMsg(QtWarningMsg, objName, "transmission error - server answered <NAK>");
        }
        else {
            emit debugMsg(QtWarningMsg, objName, "transmission error - unknown server answer");
        }

        connectionTimer->stop();    //next message can be send
        sendMessage();              //send next message if more messages in list
    }
   // emit debugMsg(QtDebugMsg, objName, "Exit Recieve Message");
}

void Logger::messageTimeout()
{
    emit debugMsg(QtWarningMsg, objName, "connection error - message timed out");
    connectionTimer->stop();        //next message can be send
    sendMessage();                  //send next message if more messages in list
}

void Logger::connectionStateChanged(QAbstractSocket::SocketState state)
{
    switch(state){
    case QAbstractSocket::UnconnectedState:
        emit debugMsg(QtDebugMsg, objName, "disconnected");
        if (logging){
            //reopen server connection
//            revServer.connectToHost(
//                    settings.value("logging/serverName",defaultServerName).toString(),
//                    settings.value("logging/serverPort",defaultServerPort).toInt(), QIODevice::ReadWrite);
            QTimer* reconnectTimer = new QTimer(this);
            reconnectTimer->singleShot(3000, &revServer, SLOT(connectToHost(
                    settings.value("logging/serverName",defaultServerName).toString(),
                    settings.value("logging/serverPort",defaultServerPort).toInt(),
                    QIODevice::ReadWrite)));
        }
        break;
    case QAbstractSocket::HostLookupState:
        emit debugMsg(QtDebugMsg, objName, "looking up hostname");
        break;
    case QAbstractSocket::ConnectingState:
        emit debugMsg(QtDebugMsg, objName, "connecting to server...");
        break;
    case QAbstractSocket::ConnectedState:
        emit debugMsg(QtDebugMsg, objName, "connected to " + revServer.peerName());
        sendMessage();
        break;
    case QAbstractSocket::ClosingState:
        emit debugMsg(QtDebugMsg, objName, "closing connection");
        break;
    default:
        emit debugMsg(QtDebugMsg, objName, "unknown socket state");
        break;
    }
}

void Logger::connectionError(QAbstractSocket::SocketError)
{
    emit debugMsg(QtCriticalMsg, objName, revServer.errorString());
}
*/


TripData Logger::getTripData()
{
    return tripData;
}


quint16 Logger::crc16Checksum(QByteArray data)
{
    quint16 crctemp;
    register quint16 crc = 0xffff;
    for (int i=0; i<data.length(); i++)
    {
        crctemp = (data[i] ^ crc) & quint16(0x00ff);
        crctemp = crc_tbl[quint8(crctemp)];
        crc = (crc >> 8) ^ crctemp;
    }
    return crc;
}

