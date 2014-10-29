#include "battery.h"

/**
*   Main BMS Class
*   Object Constructor pre-initiliasation
*/
BMS::BMS() : QObject()
{
    //Define Serial Port
    port = new QextSerialPort(QextSerialPort::Polling);
	
    //Set Device Name for Debugging Output
    devName = settings.value("battery/deviceName", defaultBatteryDeviceName).toString();

#ifdef LOTUS
    //Load Battery percentage points
    // ie 2.7v = 0% Capacity   - Barlow
    // ie 3.4v = 100% Capacity - Barhigh
    batteryData.barlow = settings.value("battery/barlow",batteryData.barlow).toFloat();
    batteryData.barhigh = settings.value("battery/barhigh",batteryData.barhigh).toFloat();

    // Load Battery Parameters
    QString batteryType = settings.value("battery/batteryType", defaultBatteryType).toString();
    if (batteryType == "TS_LYP60AHA") batteryData.batteryType = TS_LYP60AHA;
    if (batteryType == "TS_LYP90AHA") batteryData.batteryType = TS_LYP90AHA;
    if (batteryType == "DEFAULT") batteryData.batteryType = BATTERY_DEFAULTS;
	
    capacityPerKm = 0.5;
#endif

    rawDisplay = false;
    // Setup timer for main loop
    updateTimer = new QTimer(this);
    connect(updateTimer, SIGNAL(timeout()), this, SLOT(update()));

}

//Deconstructor
BMS::~BMS()
{
    if (port->isOpen()) {
        end();
    }
}

//Deconstructor
void BMS::end()
{
    // Stop the timer and close the port
        updateTimer->stop();
    port->close();
    if (!port->isOpen()) {
        emit debugMsg(QtDebugMsg, devName, "closing port successful " + port->portName());
    }
    else {
        emit debugMsg(QtWarningMsg, devName, "error closing port " + port->portName() + " - " + port->errorString());
    }
}


void BMS::setDefaultSettings()
{
    settings.beginGroup("battery");
    settings.remove("");
    settings.setValue("deviceName", defaultBatteryDeviceName);
    settings.setValue("port", defaultBatteryPort);
    settings.setValue("batteryType", defaultBatteryType);
    settings.endGroup();
    emit debugMsg(QtDebugMsg, devName, "default settings applied ");
}

// Default initialiser
bool BMS::init()
{
    //Start timer, calls update() every 05s
    updateTimer->start(1000);//(5000);
    commandLogging = false;

#ifdef LOTUS
    // Set defaults for min/max battery voltages
    min_v = 400;
    max_v = -1;
    min_bat = -1;
    max_bat = -1;
    global_min_v = 3.82;
    global_max_v = 0;

    // Load Battery Level Warnings from .ini file
    batteryData.batteryType.cellVoltageOverCharged = settings.value("battery/OverCharged",BATTERY_DEFAULTS.cellVoltageOverCharged).toFloat();
    batteryData.batteryType.cellVoltageFull = settings.value("battery/Full",BATTERY_DEFAULTS.cellVoltageFull).toFloat();
    batteryData.batteryType.cellVoltageNormal = settings.value("battery/Normal",BATTERY_DEFAULTS.cellVoltageNormal).toFloat();
    batteryData.batteryType.cellVoltageWarn = settings.value("battery/Warn",BATTERY_DEFAULTS.cellVoltageWarn).toFloat();
    batteryData.batteryType.cellVoltageEmpty = settings.value("battery/Empty",BATTERY_DEFAULTS.cellVoltageEmpty).toFloat();
#endif
    batteryData.alarm = settings.value("battery/alarm",batteryData.alarm).toFloat();

    return true;
}

//Connect BMS serial port to program
bool BMS::bms_connect(QString portName) {
#ifdef LOTUS
    port->setPortName(portName);
    port->setBaudRate(BAUD9600);
    port->setFlowControl(FLOW_OFF);
    port->setParity(PAR_NONE);
    port->setDataBits(DATA_8);
    port->setStopBits(STOP_1);
    port->setTimeout(10);
#endif
#ifdef GETZ
    port->setPortName(portName);
    port->setBaudRate(BAUD2400);
    port->setFlowControl(FLOW_OFF);
    port->setParity(PAR_EVEN);
    port->setDataBits(DATA_8);
    port->setStopBits(STOP_1);
    port->setTimeout(10);
#endif
    return port->open(QIODevice::ReadWrite);
}

//Update State of BMS
void BMS::update()
{
#ifdef LOTUS
    QString msg;
#endif
#ifdef GETZ
    QByteArray msg;
#endif
	// Attempt to connect port if not connected
	if(!port->isOpen()) {
        if(bms_connect(settings.value("battery/port", defaultBatteryPort).toString())) {
			emit debugMsg(QtDebugMsg, devName, "listening for data on " + port->portName());
            emit error(false);
			emit error(tr(" BMS "));
		}
		else {
            emit error(tr(" BMS not connected "));
            emit error(true);
            if(rawDisplay) {
                emit debugMsg(QtWarningMsg, devName, "failed to open " + port->portName() + " - " + port->errorString());
            }
		}
	}

#ifdef LOTUS
	// If port is connected, continue operations
        if(port->isOpen() || msg.size() > 0) {
		
		//Get messages from serial port
		while (port->bytesAvailable() > 8){ // min msg length 9
			msg.append(port->readLine(18)); // max msg length 17
		}


		//parse messages
		if (parseBatteryString(msg)){
		
			// Energy Usage Calculations for last timer interval
			qreal dAh = batteryData.current*updateTimer->interval()/(3600000);  // capacity in [Ah]
			qreal dE = dAh * batteryData.voltage / 1000;                        // energy in [kWh]		
			if(dE > 0) {
				batteryData.energyRegenerated += dE;
			}
			else {
				batteryData.energyUsed += dE;
			}
                        if(batteryData.ampHour + dAh < 60) {
                            batteryData.ampHour = batteryData.ampHour + dAh;
                        }
                        else {
                            batteryData.ampHour = 60;
                        }


		}
		emit error(tr(" BMS "));
		emit updated(batteryData);
		
    }	
#endif
#ifdef GETZ
    else{

        msg = port->readAll();
        batteryData.temp = msg;
        if (parseBatteryString(msg)) {
            emit error(tr(" TBS "));
            emit error(false);
            emit updated(batteryData);
        }
        else {
            emit error(true);
        }

    }
#endif
}

#ifdef LOTUS
bool BMS::parseBatteryString(QString batteryString)
{
    bool stringProcessed = false;
	
    //Get a list of all commands sent in the bms msg string
    QStringList sentences = batteryString.split("\r\n", QString::SkipEmptyParts);

    //Format each and process each sentence
    for (int i=0; i<sentences.size(); i++)
    {
        //trim data
        sentences.value(i).remove('\r');
        sentences.value(i).remove('\n');
		
        //Emit incoming raw data before processing if selected
        if (rawDisplay) {
            emit debugMsg(QtDebugMsg, devName, sentences.value(i));
        }

        //Log commands if performing a command log
        if (commandLogging) {
            cLog << sentences.value(i) << "\n";

            capLog << batteryData.voltage << ",";
            capLog << batteryData.current << ",";
            capLog << this->getMinimumBatteryVoltage() << ",";
            capLog << this->getMaximumBatteryVoltage() << ",";
            capLog << this->getAverageVoltage() << ",";
            float cap = 100*(batteryData.ampHour)/60;
            capLog << cap << "\n";
        }
	
        // Split each command into parts for processing
        QStringList command = sentences.value(i).split(",");
		
        // Process Singular commands
        if (command.size()==4 && command.value(0).length()==1){
            
            stringProcessed = true;
            switch (command.value(0).toLatin1()[0]){

            case 'A': {// battery current
                    // Current value of battery - smoothed
                    batteryData.current = command.value(2).toFloat()/100;
					
                    // Instantaneous current value
                    batteryData.o_current = batteryData.current;
					
                    // negative current - drive
                    if (command.value(1) == "0" ) {
                        batteryData.current = -batteryData.current;
                        batteryData.o_current = -batteryData.current;
                        batteryData.n_current = batteryData.current;
                        batteryData.p_current = 0;
                        batteryData.n_points++;
                    }
                    else { // positive current - charge/regen
                        batteryData.p_current = batteryData.current;
                        batteryData.n_current = 0;
                        batteryData.p_points++;
                    }
					
                    // smooth out current values
                    lastCurrent.append(batteryData.current);
                    int numLast = 10;
                    if (lastCurrent.length() > numLast) {
                        lastCurrent.removeFirst();
                    }				
                    batteryData.current = 0;

                    for (int i=0; i<lastCurrent.length(); i++) {
                        batteryData.current += lastCurrent.at(i);
                    }
                    batteryData.current /= numLast;
                   
                } break;

            case 'B': { // battery voltage
                    if  (command.value(1).toInt() == 1)   //pack voltage
                        batteryData.voltage = command.value(2).toFloat()/100;
                        cellVoltageTotal = batteryData.voltage/batteryData.cellNumber;
                        //batteryData.voltage = command.value(2).toFloat()/100; // should be changed in the bms
                    if  (command.value(1).toInt() == 2)   //auxiliary voltage
                        auxVoltage = command.value(2).toFloat()/100;
                } break;

            case 'C': { // charging mode
                    switch (command.value(1).toInt()){
                    case 0: {
                            //batteryData.charging = true;
                            emit debugMsg(QtDebugMsg, devName, "charging started");
                        } break;
                    case 1: {
                            //resetCapacity();
                            emit debugMsg(QtDebugMsg, devName, "charging condition 1 set");
                        } break;
                    case 2: {
                            //resetCapacity();
                            emit debugMsg(QtDebugMsg, devName, "charging condition 2 set");
                        } break;
                    default: {
                            emit debugMsg(QtDebugMsg, devName, "unknown charging condition");
                        }
                    }
                } break;

            case 'I': { // cell number
                    if (command.value(1).toInt()!=0){
                        batteryData.cellNumber = command.value(1).toInt();
                        emit debugMsg(QtDebugMsg, devName, QString("%1 battery cells detected").arg(batteryData.cellNumber));
                    }
                } break;

            case 'M': { // min and max cell voltages - actual data not used
					//actual use is for pinging a min/max cell calculation
                    //int cell = command.value(1).toInt();
          
                    //Why originally here?
                    /*min_v = temp_min_v;
                    max_v = temp_max_v;
                    min_bat = temp_min_bat;
                    max_bat = temp_max_bat;

                    temp_min_v = 400;
                    temp_max_v = 0;
                    cellVoltageTotal = 0;
                    for(int j=0; j < batteryData.cellNumber; j++) {
                        cellVoltageTotal = cellVoltageTotal + batteryData.cellVoltage[j];
                    }
                    averageVoltage = cellVoltageTotal/batteryData.cellNumber;*/

                } break;
            case 'H': {
                    batteryData.barhigh=command.value(1).toFloat()/10;
                }
                break;
            case 'L': {
                    batteryData.barlow=command.value(1).toFloat()/10;
                }
                break;
            case 'V': { // cell voltages and more
                    int cell = command.value(1).toInt();


                    /////////////////////////////////////////////////////
                    // This section adjusts the cell value arrays so   //
                    // that they are of the correct size               //
                    // Do not remove this as they will cause           //
                    // array overflow errors. This is the most likely  //
                    // cause of errors in the program                  //
                    /////////////////////////////////////////////////////
                    for(int j=batteryData.cellVoltage.length(); j<cell; j++) {
                        batteryData.cellVoltage.append(0);
                    }
                    for(int j=batteryData.cellVoltageMin.length(); j<cell; j++){
                        batteryData.cellVoltageMin.append(4);
                    }
                    for(int j=batteryData.cellVoltageMax.length(); j<cell; j++){
                        batteryData.cellVoltageMax.append(0);
                    }
                    if (batteryData.cellNumber<cell) {
                        batteryData.cellNumber=cell;
                    }

                    /////////////////////////////////////////////////////


                    if (cell==0){   // V0 is the sum of all cell voltages
                        //batteryData.voltage = words.value(2).toFloat()/100;
                        batteryData.cellNumber = command.value(3).toInt();
                    }
                    if (cell>0 && cell<=batteryData.cellVoltage.length()
                        && cell<=batteryData.cellVoltageMin.length()) {
                        batteryData.cellVoltage[cell-1] = command.value(2).toFloat()/100;
						
                    }
                    if(cell != 0) {
                        //Processing for local/global Minimum's and Maximum's
                        if(batteryData.cellVoltage[cell-1] < temp_min_v )
                        {
                            temp_min_v = batteryData.cellVoltage[cell-1];
                            temp_min_bat = cell;
                        }
                        if(batteryData.cellVoltage[cell-1] > temp_max_v) {
                            temp_max_v = batteryData.cellVoltage[cell-1];
                            temp_max_bat = cell;
                        }
                        if(batteryData.cellVoltage[cell-1] < global_min_v )
                        {
                            global_min_v = batteryData.cellVoltage[cell-1];
                            global_min_bat = cell;
                        }
                        if(batteryData.cellVoltage[cell-1] > global_max_v )
                        {
                            global_max_v = batteryData.cellVoltage[cell-1];
                            global_max_bat = cell;
                        }

                        //Processing Battery Min and Maximums
                        if(batteryData.cellVoltage[cell-1] < batteryData.cellVoltageMin[cell-1]) {
                             batteryData.cellVoltageMin[cell-1] = batteryData.cellVoltage[cell-1];
                        }
                        if(batteryData.cellVoltage[cell-1] > batteryData.cellVoltageMax[cell-1]) {
                             batteryData.cellVoltageMax[cell-1] = batteryData.cellVoltage[cell-1];
                        }

                        //Battery indication processing
                        if(batteryData.cellVoltage[cell-1] < global_min_v) {
                            v_ind.append(batteryData.cellVoltage[cell-1]);
                        }
                        else {
                            v_ind.append(global_min_v);
                        }
                        if(v_ind.length() > 30) {
                            v_ind.removeFirst();
                        }
                        batteryData.cell_low_average = 0;
                        for (int i=0; i<v_ind.length(); i++) {
                            batteryData.cell_low_average += v_ind.at(i);
                        }
                        batteryData.cell_low_average = batteryData.cell_low_average/30;
                    }

                    min_v = temp_min_v;
                    max_v = temp_max_v;
                    min_bat = temp_min_bat;
                    max_bat = temp_max_bat;

                    temp_min_v = 400;
                    temp_max_v = 0;
                    cellVoltageTotal = 0;
                    for(int j=0; j < batteryData.cellVoltage.length(); j++) {//was batteryData.cellNumber but would give index out of bounds error sometimes
                        cellVoltageTotal = cellVoltageTotal + batteryData.cellVoltage[j];
                    }
                    averageVoltage = cellVoltageTotal/batteryData.cellNumber;
                } break;
            default: {
                    if (!rawDisplay) // do not emit the same message twice
                        emit debugMsg(QtDebugMsg, devName, "unknown message: " + sentences.value(i));
                }
            }
        }
    }
    return stringProcessed;
}
#endif

#ifdef GETZ
bool BMS::parseBatteryString(QByteArray tbsArray) {
    bool ok;

    QByteArray hexArray = tbsArray.toHex();
    if(rawDisplay)
        emit debugMsg(QtDebugMsg, devName, hexArray.data());

    //Log commands if performing a command log
    if (commandLogging) {
        cLog << hexArray << "\n";
    }

    while(!hexArray.isEmpty()) {
        hexArray.remove(0,6);

        // remove first three bytes - destination, source address, and device ID
        //msg.remove(0,2);

        // Get the data type
        QByteArray type = hexArray.mid(0,2);
        hexArray.remove(0,2);

        // get the data
        QByteArray data = hexArray.mid(0,6);
        hexArray.remove(0,6);

        // remove trailing byte and validate msg
        hexArray.remove(0,2);
        if(hexArray.isEmpty()) {
            //emit debugMsg(QtDebugMsg, devName, "Valid TBS Message");
            //return false;
        }

        switch (type.toInt(&ok,16)){

        case 0x60: { // Main Pack Voltage
            batteryData.voltage =  rawToFloat(data,0);
        } break;

        case 0x61: { // Main Pack Current
            batteryData.current = rawToFloat(data,1);
        } break;

        case 0x62: { // Amp Hours
            batteryData.ampHours = rawToFloat(data,2);
        } break;

        case 0x64: { // State of Charge
            batteryData.soc = rawToFloat(data,4);
            break;
        }
        case 0x65: { // Time Remaining
            batteryData.timeRemaining = rawToFloat(data,5);
        } break;

        case 0x66: { // Temperature
            batteryData.temperature = rawToFloat(data,6);
        } break;
        }
    }

    return true;

}
#endif

//Return Functions
void BMS::displayRawData(bool log)
{
    rawDisplay = log;
}

#ifdef LOTUS
void BMS::saveCommands(bool log)
{
    if(log) {
        batteryData.ampHour = 60;
        QString defaultLogDir      = "log_files";
        QString defaultLogName     = "yyyy-MM-dd_hh-mm";
        QDateTime startTime = QDateTime::currentDateTime();

        QDir logDir(QDir::homePath() + "/" + settings.value("logging/logDir",defaultLogDir).toString());
        QString comfileName = "BAT-" + startTime.toString(settings.value("logging/logName",defaultLogName).toString()) + ".txt";
        QString capFileName = "CAP-" + startTime.toString(settings.value("logging/logName",defaultLogName).toString()) + ".txt";

        QString path = logDir.absolutePath()+ "/" + comfileName;
        QString path_cap = logDir.absolutePath() + "/" + capFileName;

        commandLog.setFileName(path);
        capacityLog.setFileName(path_cap);

        cLog.setDevice(&commandLog);
        capLog.setDevice(&capacityLog);

        commandLogging = true;
        if (commandLog.open(QFile::WriteOnly | QFile::Text))  {
            emit debugMsg(QtDebugMsg, devName, "Logging raw battery commands to " + path);
        }
        else {
            emit debugMsg(QtDebugMsg, devName, "Error occurred when starting command log");
        }

        if (capacityLog.open(QFile::WriteOnly | QFile::Text))  {
            emit debugMsg(QtDebugMsg, devName,"Logging capacity information");
        }
        else {
            emit debugMsg(QtDebugMsg, devName, "Error occurred when starting capacity log");
        }


    }
    else {
        commandLogging = false;
        commandLog.close();
        capacityLog.close();
        emit debugMsg(QtDebugMsg, devName, "Finished logging raw battery commands");
    }

}
#endif

#ifdef GETZ
void BMS::saveCommands(bool log)
{
    if(log) {
        QString defaultLogDir      = "log_files";
        QString defaultLogName     = "yyyy-MM-dd_hh-mm";
        QDateTime startTime = QDateTime::currentDateTime();

        QDir logDir(QDir::homePath() + "/" + settings.value("logging/logDir",defaultLogDir).toString());
        QString tbsfilename = "TBS"+ startTime.toString(settings.value("logging/logName",defaultLogName).toString()) + ".hex";;
        QString path = logDir.absolutePath()+ "/" + tbsfilename;
        commandLog.setFileName(logDir.absolutePath() + "/" + tbsfilename);
        cLog.setDevice(&commandLog);

        commandLogging = true;
        if (commandLog.open(QFile::WriteOnly | QFile::Text))  {
            emit debugMsg(QtDebugMsg, devName, "Logging raw battery commands to " + path);
        }
        else {
            emit debugMsg(QtDebugMsg, devName, "Error occurred when starting command log");
        }
    }
    else {
        commandLogging = false;
        commandLog.close();
        emit debugMsg(QtDebugMsg, devName, "Finished logging raw battery commands");
    }
}
#endif

//return battery data structure
BatteryData BMS::getBatteryData()
{
    return batteryData;
}

//return the battery type
BatteryType BMS::getBatteryType()
{
    return batteryData.batteryType;
}

#ifdef LOTUS
//return the minimum cell number in the last cycle
int  BMS::getMinimumBatteryCell()
{
    return min_bat;
}

//return the maximum cell number in the last cycle
int BMS::getMaximumBatteryCell()
{
    return max_bat;
}

//return the minimum cell voltage in the last cycle
float BMS::getMinimumBatteryVoltage()
{
    return min_v;
}

//return the maximum cell voltage in the last cycle
float BMS::getMaximumBatteryVoltage()
{
    return max_v;
}

//return the minimum cell number over the entire program life
int  BMS::global_getMinimumBatteryCell()
{
    return global_min_bat;
}

//return the maximum cell number over the entire program life
int BMS::global_getMaximumBatteryCell()
{
    return global_max_bat;
}

//return the minimum battery voltage over the entire program life
float BMS::global_getMinimumBatteryVoltage()
{
    return global_min_v;
}

//return the maximum battery voltage over the entire program life
float BMS::global_getMaximumBatteryVoltage()
{
    return global_max_v;
}

float BMS::getCellVoltageTotal()
{
    return cellVoltageTotal;
}

float BMS::getAverageVoltage()
{
    return averageVoltage;
}

float BMS::getBarlow()
{
    return batteryData.barlow;
}

float BMS::getBarhigh()
{
    return batteryData.barhigh;
}

float BMS::getCellLowAverage()
{
    return batteryData.cell_low_average;
}

void BMS::NNreset() {
    batteryData.ampHour = 60;
    emit debugMsg(QtDebugMsg, devName, "Neural Network SOC trainer data reset");
}
#endif

float BMS::getDischargeCurrent() {
    float cur = batteryData.current;
    float result = fabs(cur);
    return result;
}

#ifdef GETZ

float BMS::rawToFloat(QByteArray raw, int type) {
    bool ok;
    int a,b,c;
    a = raw.mid(0,2).toInt(&ok, 16);
    b = raw.mid(2,2).toInt(&ok, 16);
    c = raw.mid(4,2).toInt(&ok, 16);
    switch(type) {

    case 0: {
        int volt = (float)((a << 14) + (b << 7) + (c))/100;
        return volt; //volt should be float?
    }
    case 1: {
        int _cur = (a << 14) + (b << 7) + (c);
        float cur = ((float)(_cur & 0xFFFFF)/100);
        if(_cur & 0x100000) { // If 20th bit is 1 then negative current
            return -cur;
        } else {
            return cur;
        }
    }
    case 2: {
        int _aH = (a << 14) + (b << 7) + (c);
        float aH = ((float)(_aH & 0xFFFFF)/10);
        if(_aH & 0x100000) { // If 20th bit is 1 then negative amhours
            return -aH;
        } else {
            return aH;
        }
    }
    case 4: {
        int soc = (float)((a << 14) + (b << 7) + (c))/10;
        return soc;

    }
    case 5: {
        int _tR = (a << 14) + (b << 7) + (c);
        float tR = ((float)(_tR & 0xFFFFF));
        if(_tR & 0x100000) { // If 20th bit is 1 then negative time remaining
            return -1.0; //Charging
        } else {
            return tR;
        }

    }
    case 6: {
        int _cel = (a << 14) + (b << 7) + (c);
        float cel = ((float)(_cel & 0xFFFFF)/10);
        if(_cel & 0x100000) { // If 20th bit is 1 then negative temperature
            return -cel;
        } else {
            return cel;
        }
    }
    default: {
        return 0.0f;
    }
    }
}
#endif
	

