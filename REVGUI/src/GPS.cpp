#include "GPS.h"

GPS::GPS() : QObject()
{
    //Define serial port
    port = new QextSerialPort(QextSerialPort::Polling);
    devName = settings.value("gps/deviceName", defaultGpsDeviceName).toString();
	
    positionData.totalDistance = settings.value("gps/totalDistance", 0).toFloat();
    rawDisplay = false;

    updateTimer = new QTimer(this);
    connect(updateTimer, SIGNAL(timeout()), this, SLOT(update()));

    //errorTimer = new QTimer(this);
    //connect(errorTimer, SIGNAL(timeout()), this, SLOT(sendErrorSignal()));

#ifdef TEST
    positionData.UTCDateTime.setDate(QDate(2010,10,15));
    positionData.UTCDateTime.setTime(QTime(6,37,42,100));
    positionData.valid = true;
    positionData.latitude = -31.980850;
    positionData.longitude = 115.815650;
    positionData.altitude = 10;
    positionData.hdop = 1.3;
    positionData.numSat = 6;
    positionData.heading = 180;
    positionData.speed = 36;
    positionData.totalDistance = 1337;
#endif
}

GPS::~GPS()
{
    if (port->isOpen()) {
        end();
    }
}

void GPS::end()
{
    //stop the timer and close the port
    updateTimer->stop();
    port->close();
    if (!port->isOpen()) {
        emit debugMsg(QtDebugMsg, devName, "closing port successful " + port->portName());
    }
    else {
        emit debugMsg(QtWarningMsg, devName, "error closing port " + port->portName() + " - " + port->errorString());
    }
}

void GPS::setDefaultSettings()
{
    settings.beginGroup("gps");
    settings.remove("");
    settings.setValue("deviceName", defaultGpsDeviceName);
    settings.setValue("port", defaultGpsPort);
    settings.endGroup();

    emit debugMsg(QtDebugMsg, devName, "default settings applied ");
}

bool GPS::init()
{   
    //start update timer
    updateTimer->start(100);
    commandLogging = false;
    return true;
}

bool GPS::gps_connect(QString portName) {

    port->setPortName(portName);
    port->setBaudRate(BAUD115200);
    port->setFlowControl(FLOW_OFF);
    port->setParity(PAR_NONE);
    port->setDataBits(DATA_8);
    port->setStopBits(STOP_1);
    port->setTimeout(10);
    return port->open(QIODevice::ReadWrite);
}

void GPS::update()
{
    if(!port->isOpen()) {
        if(gps_connect(settings.value("gps/port", defaultGpsPort).toString())) {
            emit debugMsg(QtDebugMsg, devName, "listening for data on " + port->portName());
            emit error(false);
        }
        else {
            emit error(true);
            emit error(tr(" GPS not connected "));
            if(rawDisplay) {
                emit debugMsg(QtWarningMsg, devName, "failed to open " + port->portName() + " - " + port->errorString());
            }
        }
    }
    bool testing = false;
    #ifdef TEST
    testing = true;
    #endif
	
    QString msg;

    QDateTime oldUTCDateTime = positionData.UTCDateTime;

    if (port->isOpen() || testing){
	
        msg = port->readAll();

        #ifdef TEST
       // msg.append("$GPRMC,040302.663,A,3939.7,N,10506.6,W,0.27,358.86,200804,,*1A");
        //msg.append("$GPRMC,040302.663,A,3939.7,N,10506.6,W,0.27,358.86,200804,,*1A");
        #endif
    
        if (parseNMEA(msg)) {
            if (positionData.valid){
                //filter low speeds according to signal quality because GPS speed is inaccurate when stationary
                if (positionData.speed<5) { // && (positionData.hdop==0 || positionData.speed<positionData.hdop) )
                    positionData.speed = 0;
                }
                //distance [km] travelled
                qreal dt = oldUTCDateTime.time().msecsTo(positionData.UTCDateTime.time());
                if(dt<10000){   // prevent errors when picking up the gps signal -> faulty old time
                    qreal dx = positionData.speed/3600*dt/1000;
                    positionData.totalDistance += dx;
                }

                // store total distance every time so that it does not get lost in case of a program crash
                settings.setValue("gps/totalDistance",positionData.totalDistance);

                emit error(tr(" GPS "));
                emit updated(positionData);
            }
            else {
                emit error(true);
                emit error(tr(" No GPS signal "));
            }
        }
    }
}

bool GPS::parseNMEA(QString gpsString)
{
    bool stringProcessed = false;
    QStringList sentences = gpsString.split("\n", QString::SkipEmptyParts);
    for (int i = 0; i < sentences.size(); ++i)
    {
        if (rawDisplay) {
            emit debugMsg(QtDebugMsg, devName, sentences.value(i));
        }

        //Log commands if performing a command log
        if (commandLogging) {
            cLog << sentences.value(i) << "\n";
        }


        QStringList words = sentences.value(i).split(",");
        if (words.value(0) == "$GPRMC" && words.size()>=10){
            positionData.UTCHour     = words.value(1).leftRef(2).toString().toInt();
            positionData.UTCMinute   = words.value(1).midRef(2, 2).toString().toInt();
            positionData.UTCSecond   = words.value(1).midRef(4, 2).toString().toInt();
            positionData.UTCMilliSec = words.value(1).midRef(7, 3).toString().toInt();
            positionData.UTCDateTime.setTime(
                    QTime(positionData.UTCHour, positionData.UTCMinute,
                          positionData.UTCSecond, positionData.UTCMilliSec));

            positionData.UTCDay      = words.value(9).leftRef(2).toString().toInt();
            positionData.UTCMonth    = words.value(9).midRef(2, 2).toString().toInt();
            positionData.UTCYear     = words.value(9).midRef(4, 2).toString().toInt()+2000;
            positionData.UTCDateTime.setDate(
                    QDate(positionData.UTCYear, positionData.UTCMonth, positionData.UTCDay));

            if (words.value(2)=="A"){
                positionData.valid =true;

                positionData.latitude    =  words.value(3).leftRef(2).toString().toInt();
                positionData.latitude    += words.value(3).midRef(2, 7).toString().toDouble()/60;
                if (words.value(4)=="S")
                    positionData.latitude = -positionData.latitude;

                positionData.longitude    =  words.value(5).leftRef(3).toString().toInt();
                positionData.longitude    += words.value(5).midRef(3, 7).toString().toDouble()/60;
                if (words.value(6)=="W")
                    positionData.longitude = -positionData.longitude;

                positionData.speed   = words.value(7).toDouble()*1.85200;
                positionData.heading = words.value(8).toDouble();
            }
            else {
                positionData.valid =false;
            }
            stringProcessed=true;
        }
        if (words.value(0) == "$GPGGA" && words.size()>=10){
            positionData.numSat = words.value(7).toInt();
            if (words.value(6).toInt()!= 0){
                positionData.valid =true;
                positionData.hdop = words.value(8).toDouble();
                positionData.altitude = words.value(9).toDouble();
            }
            else {
                positionData.valid =false;
            }
            stringProcessed=true;
        }
    }
    return stringProcessed;
}

void GPS::saveCommands(bool log)
{
    if(log) {
        QString defaultLogDir      = "log_files";
        QString defaultLogName     = "yyyy-MM-dd_hh-mm";
        QDateTime startTime = QDateTime::currentDateTime();

        QDir logDir(QDir::homePath() + "/" + settings.value("logging/logDir",defaultLogDir).toString());
        QString comfileName = "GPS-" + startTime.toString(settings.value("logging/logName",defaultLogName).toString()) + ".txt";
        QString path = logDir.absolutePath()+ "/" + comfileName;
        commandLog.setFileName(path);
        cLog.setDevice(&commandLog);
        commandLogging = true;
        if (commandLog.open(QFile::WriteOnly | QFile::Text))  {
            emit debugMsg(QtDebugMsg, devName, "Logging raw GPS commands to " + path);
        }
        else {
            emit debugMsg(QtDebugMsg, devName, "Error occurred when starting command log");
        }
    }
    else {
        commandLogging = false;
        commandLog.close();
        emit debugMsg(QtDebugMsg, devName, "Finished logging raw GPS commands");
    }
}



void GPS::displayRawData(bool log)
{
    rawDisplay = log;
}

PositionData GPS::getPositionData()
{
    return positionData;
}

