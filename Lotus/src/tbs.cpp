#include "tbs.h"

TBS::TBS() : QObject()
{
    //Define serial port
    port = new QextSerialPort(QextSerialPort::Polling);
    devName = settings.value("tbs/deviceName", defaultTbsDeviceName).toString();
    rawLogging = false;

    updateTimer = new QTimer(this);
    connect(updateTimer, SIGNAL(timeout()), this, SLOT(update()));
}

TBS::~TBS()
{
    if (port->isOpen()) {
        end();
    }
}

void TBS::end()
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

void TBS::setDefaultSettings()
{
    settings.beginGroup("tbs");
    settings.remove("");
    settings.setValue("deviceName", defaultTbsDeviceName);
    settings.setValue("port", defaultTbsPort);
    settings.endGroup();

    emit debugMsg(QtDebugMsg, devName, "default settings applied ");
}

bool TBS::init()
{
    //start update timer
    updateTimer->start(100);
    commandLogging = false;
    return true;
}

bool TBS::tbs_connect(QString portName) {

    port->setPortName(portName);
    port->setBaudRate(BAUD115200);
    port->setFlowControl(FLOW_OFF);
    port->setParity(PAR_NONE);
    port->setDataBits(DATA_8);
    port->setStopBits(STOP_1);
    port->setTimeout(10);
    return port->open(QIODevice::ReadWrite);
}

void TBS::update()
{
    if(!port->isOpen()) {
        if(tbs_connect(settings.value("tbs/port", defaultTbsPort).toString())) {
            emit debugMsg(QtDebugMsg, devName, "listening for data on " + port->portName());
        }
        else {
            emit error(tr(" TBS not connected "));
            if(rawLogging) {
                emit debugMsg(QtWarningMsg, devName, "failed to open " + port->portName() + " - " + port->errorString());
            }
        }
    }

    bool testing = false;
    #ifdef TEST
    testing = true;
    #endif

    QByteArray msg;
    if (port->isOpen() || testing){

        msg = port->readAll();
        if (parseMsg(msg)) {
            emit error(tr(" TBS "));
            emit updated(tbsData);
        }
        else {

        }

    }
}

bool TBS::parseMsg(QByteArray tbsArray) {
	//bool arrayProcessed = false;

    QByteArray hexArray = tbsArray.toHex();


    while(!hexArray.isEmpty()) {
        QByteArray msg = hexArray.remove(0,3);

        // remove first three bytes - destination, source address, and device ID
        msg.remove(0,2);

        // Get the data type
        QByteArray type = msg.remove(0,1);

        // get the data
        QByteArray data = msg.remove(0,3);

        // remove trailing byte and validate msg
        msg.remove(0,1);
        if(msg.isEmpty()) {
         //   emit debugMsg(QtDebugMsg, devName, "Valid TBS Message");
            return false;
        }

        switch (type.toInt()){

        case 0x60: { // Main Pack Voltage
            tbsData.packVoltage = (float) data.toInt();
            } break;

        case 0x61: { // Main Pack Current
            tbsData.packCurrent = (float) data.toInt();
            } break;

        case 0x62: { // Amp Hours
            tbsData.ampHours = (float) data.toInt();
            } break;

        case 0x64: { // State of Charge
            tbsData.soc = (float) data.toInt();
            } break;

        case 0x65: { // Time Remaining
            tbsData.timeRemaining = (float) data.toInt();
            } break;

        case 0x66: { // Temperature
            tbsData.temperature = (float) data.toInt();
            } break;

        case 0x67: { // Monitor Status
            tbsData.monitorStatus = (float) data.toInt();
            } break;

        case 0x69: { // Auxillary Voltage
            tbsData.auxVoltage = (float) data.toInt();
            } break;

        }
    }

    return true;
}

void TBS::logRawData(bool log)
{
    rawLogging = log;
}

TbsData TBS::getTBSData()
{
    return tbsData;
}
