#include "energymeter.h"

#define XSENS_ROUTINE_NAME	"Xsens MTi"
#define EMETER_ROUTINE_NAME	"EnergyMeter"

EnergyMeter::EnergyMeter(QObject *parent) : QObject(parent){
	uiXsensOversampleCounter = 0;
	uiXsensSampleCounter = 0;

	pMechanics = NULL;

	pTimerXsensRead = new QTimer(this);
	pTimerXsensRead->setInterval(XSENS_SRV_CLEARBUFFER_FQC);
	connect(pTimerXsensRead, SIGNAL(timeout()), this, SLOT(readFromXsensDevice()));
}

EnergyMeter::~EnergyMeter(){
	end();

	if(pTimerXsensRead != NULL){
		delete pTimerXsensRead;
		pTimerXsensRead = NULL;
	}

	if(pMechanics != NULL){
		delete pMechanics;
		pMechanics = NULL;
	}
}

bool EnergyMeter::init(){
    //bool bConversionSuccess = false;
	pMechanics = new LotusMechanics(CAR_TOTAL_MASS);

    QByteArray ba = oSettings.value(QString(SETTINGS_GROUP_EMETER).append("/").append(SETTINGS_KEY_XSENSPORT), XSENS_CLT_DEFAULT_PORT).toString().toLatin1();
    const char* uiPortName = ba.data();
    /*if(!bConversionSuccess){
		emit debugMsg(QtFatalMsg, XSENS_ROUTINE_NAME, "Wrong port supplied. Only COM-ports are allowed, e.g. COM5");
		return(false);
    }--------LINUX NOT WIN*/
	if (iXsensInstance == -1) iXsensInstance = cmtCreateInstance(XSENS_CLT_SERIAL);
	if (iXsensInstance == -1){
		emit debugMsg(QtFatalMsg, XSENS_ROUTINE_NAME, "Creation of CMT instance failed, probably because of an invalid serial number");
		return(false);
	}

    if(connectToXsens(uiPortName) != XRV_OK){ // open port & set settings
		return false;
	}
	emit debugMsg(QtDebugMsg, XSENS_ROUTINE_NAME, "listening for data on " +  oSettings.value("imu6dof/port").toString());
	//pData->setZeroIndexTimestamp (QDateTime::currentMSecsSinceEpoch ());
	pTimerXsensRead->start();
	return true;
}

void EnergyMeter::end(){
	if(iXsensInstance != -1) cmtClose(iXsensInstance); // Close any open COM ports
}

void EnergyMeter::setDefaultSettings(){	// only called by user to reset settings
	oSettings.beginGroup(SETTINGS_GROUP_EMETER);
	oSettings.remove("");
	oSettings.setValue(SETTINGS_KEY_XSENSPORT, XSENS_CLT_DEFAULT_PORT);
	oSettings.endGroup();

	emit debugMsg(QtDebugMsg, EMETER_ROUTINE_NAME, "default settings applied");
}

XsensResultValue EnergyMeter::connectToXsens(const char* uiPortName){
	XsensResultValue eXsensStatus;
	CmtOutputMode uiXsensMode = CMT_OUTPUTMODE_CALIB | CMT_OUTPUTMODE_ORIENT | CMT_OUTPUTMODE_STATUS;
	CmtOutputSettings uiXsensSettings = CMT_OUTPUTSETTINGS_ORIENTMODE_QUATERNION | CMT_OUTPUTSETTINGS_TIMESTAMP_SAMPLECNT; // default CoSy: X north, Z up

	// uiXsensMode |= CMT_OUTPUTMODE_TEMP; // read temperature
	uiXsensSettings |= CMT_OUTPUTSETTINGS_DATAFORMAT_FLOAT; // 4 bit single precision float
	// uiXsensSettings |= CMT_OUTPUTSETTINGS_DATAFORMAT_FP1632; // 6 bit fixed point fload

	// works only with integrated gps-module
	//uiXsensMode |= CMT_OUTPUTMODE_POSITION | CMT_OUTPUTMODE_VELOCITY;
	// uiXsensSettings |= CMT_OUTPUTSETTINGS_TIMESTAMP_SAMPLEUTC; // zusätzlich zum 2bit counter (65535) auch 12 bit UTC timestamt

	if(iXsensInstance == -1) return XRV_INVALIDINSTANCE;

	cmtClose(iXsensInstance);
    eXsensStatus = cmtOpenPort(iXsensInstance,uiPortName); // optional 3rd argument: ui32Baud for baudrate
	if(eXsensStatus != XRV_OK){ // scan for other ports and try to open them
		eXsensStatus = scanForXsensDevice();
		if(eXsensStatus != XRV_OK){
			emit debugMsg(QtWarningMsg, XSENS_ROUTINE_NAME, "No Xsens-Device found.");
			return eXsensStatus;
		}
	}

	eXsensStatus = cmtGetMtDeviceId(iXsensInstance, &uiXsensDeviceId, 0);
	if(eXsensStatus != XRV_OK){
		emit debugMsg(QtWarningMsg, XSENS_ROUTINE_NAME, "Couldn't get the Xsens device ID.");
		return eXsensStatus;
	}

	eXsensStatus = cmtGotoConfig(iXsensInstance);

	eXsensStatus = cmtSetBaudrate(iXsensInstance,XSENS_CLT_BAUD_RATE,uiXsensDeviceId);
	if(eXsensStatus != XRV_OK){
		emit debugMsg(QtWarningMsg, XSENS_ROUTINE_NAME, "Couldn't set baudrate.");
		return eXsensStatus;
	}
	eXsensStatus = cmtSetDeviceMode(iXsensInstance,uiXsensMode,uiXsensSettings,XSENS_CLT_SEND_FREQUENCY,uiXsensDeviceId);
	if(eXsensStatus != XRV_OK){
		emit debugMsg(QtWarningMsg, XSENS_ROUTINE_NAME, "Couldn't set device mode.");
		return eXsensStatus;
	}
	eXsensStatus = cmtSetScenario(iXsensInstance,6,uiXsensDeviceId); // 6: machine scenario
	if(eXsensStatus != XRV_OK){
		emit debugMsg(QtWarningMsg, XSENS_ROUTINE_NAME, "Couldn't set scenario.");
		return eXsensStatus;
	}
	eXsensStatus = cmtSetQueueMode(iXsensInstance,CMT_QM_FIFO); // CMT_QM_FIFO | CMT_QM_LAST
	if(eXsensStatus != XRV_OK){
		emit debugMsg(QtWarningMsg, XSENS_ROUTINE_NAME, "Couldn't set queue mode.");
		return eXsensStatus;
	}

// heading? -pi .. pi
// setlatlonalt

	eXsensStatus = cmtGotoMeasurement(iXsensInstance);
	if(eXsensStatus != XRV_OK){
		emit debugMsg(QtWarningMsg, XSENS_ROUTINE_NAME, "Couldn't go in measurement mode.");
		return eXsensStatus;
	}

	return XRV_OK;
}

XsensResultValue EnergyMeter::scanForXsensDevice(){
	XsensResultValue eXsensStatus;
	CmtPortInfo sPortInfo[256];
	uint32_t uiPortCount = 0;

	if(iXsensInstance == -1) return XRV_INVALIDINSTANCE;

	// Scanning for connected Xsens devices
	eXsensStatus = cmtScanPorts(sPortInfo, &uiPortCount, 0);
	if(eXsensStatus != XRV_OK) return eXsensStatus; //cmtScanPorts
	if(uiPortCount == 0) return XRV_MTCOUNTZERO; //nodevices found

	// Open Ports
	for(int i=0; i < (int)uiPortCount; i++) {
        eXsensStatus = cmtOpenPort(iXsensInstance, sPortInfo[i].m_portName, sPortInfo[i].m_baudrate);
		// use the first available
		if(eXsensStatus == XRV_OK){
//WIN32            oSettings.setValue(QString(SETTINGS_GROUP_EMETER).append("/").append(SETTINGS_KEY_XSENSPORT),QString("COM" + QString::number(sPortInfo[i].m_portNr)));
            oSettings.setValue(QString(SETTINGS_GROUP_EMETER).append("/").append(SETTINGS_KEY_XSENSPORT),QString("/dev/" + QString(sPortInfo[i].m_portName)));
            return(XRV_OK);
		}
	}
	return XRV_MTCOUNTZERO;
}

void EnergyMeter::readFromXsensDevice(){
	XsensResultValue eXsensStatus;
	CmtCalData sCalibratedData;
	CmtQuat sOrientationQuaternions;
	quint8 uiTmpCtr;

	if(tryToSaveOversampledXsensData() < 0){
		emit debugMsg(QtFatalMsg, XSENS_ROUTINE_NAME, "Pushbuffer is full, cannot read any data from Xsens-Device");
	}else{
		while(XRV_OK == cmtGetNextDataBundle(iXsensInstance)){
			eXsensStatus = cmtDataGetSampleCounter(iXsensInstance, &uiXsensSampleCounter, uiXsensDeviceId ,NULL);
			eXsensStatus = cmtDataGetCalData(iXsensInstance, &sCalibratedData, uiXsensDeviceId);
			eXsensStatus = cmtDataGetOriQuat(iXsensInstance, &sOrientationQuaternions, uiXsensDeviceId);

			oIMUOversamplingData.dXpp += sCalibratedData.m_acc.m_data[0];
			oIMUOversamplingData.dYpp += sCalibratedData.m_acc.m_data[1];
			oIMUOversamplingData.dZpp += sCalibratedData.m_acc.m_data[2];

			for(uiTmpCtr = 0; uiTmpCtr < 4; uiTmpCtr++){
				sOrientationOversamplingData.m_data[uiTmpCtr] += sOrientationQuaternions.m_data[uiTmpCtr];
			}

			uiXsensOversampleCounter++;
			if(tryToSaveOversampledXsensData() < 0) continue;
		}

	}
}

double EnergyMeter::computeGCompensation(const CmtQuat* const sQuat, quint8 uiMode) const{
	switch(uiMode){
	case 0: // Xpp Compensation
		return pMechanics->getLocalG()*quat2sinEuY(sQuat->m_data);
	case 1: // Ypp Compensation
		return pMechanics->getLocalG()*quat2sinEuX(sQuat->m_data);
	case 2: // Zpp Compensation
		return pMechanics->getLocalG()*(quat2cosEuX(sQuat->m_data)*quat2cosEuY(sQuat->m_data));
	default:
		return 0.0;
	}
}

qint8 EnergyMeter::tryToSaveOversampledXsensData(){
	//MechanicsLogData oDataLog;
	quint8 uiTmpCtr;
	qint8 iStatus = -2;
	if(uiXsensOversampleCounter == XSENS_SRV_DIGITAL_OVERSAMPLING){
		for(uiTmpCtr = 0; uiTmpCtr < 4; uiTmpCtr++){
			sOrientationOversamplingData.m_data[uiTmpCtr] /= XSENS_SRV_DIGITAL_OVERSAMPLING;
		}
		oIMUOversamplingData.dSinPhiY += quat2sinEuY(sOrientationOversamplingData.m_data);
		oIMUOversamplingData.dPhiX += quat2euX(sOrientationOversamplingData.m_data);
		oIMUOversamplingData.dPhiY += asin(oIMUOversamplingData.dSinPhiY);
		oIMUOversamplingData.dPhiZ += quat2euZ(sOrientationOversamplingData.m_data);

		oIMUOversamplingData.dXpp = oIMUOversamplingData.dXpp/XSENS_SRV_DIGITAL_OVERSAMPLING - computeGCompensation(&sOrientationOversamplingData);
		oIMUOversamplingData.dYpp = oIMUOversamplingData.dYpp/XSENS_SRV_DIGITAL_OVERSAMPLING - computeGCompensation(&sOrientationOversamplingData,1);
		oIMUOversamplingData.dZpp = oIMUOversamplingData.dZpp/XSENS_SRV_DIGITAL_OVERSAMPLING - computeGCompensation(&sOrientationOversamplingData,2);

		// save oIMUOversamplingData, send update signal
		// call computation
		/*
		#ifdef IMU_STORE_EFFORT_LOG
		pLotus->cmpEffortAtEngine (oNextDataset.dXpp, oNextDataset.dXp, oNextDataset.dSinPhiY, &(oDataLog.sEnergyLogData));
		#else
		pLotus->cmpEffortAtEngine (oNextDataset.dXpp, oNextDataset.dXp, oNextDataset.dSinPhiY);
		#endif
		*/

		/*if(!pData->push(oNextDataset)){
			emit debugMsg(QtWarningMsg, XSENS_ROUTINE_NAME, "Pushbuffer is full, try to improve read speed");
			iStatus = -1;
		}else{
			emit updated(oDataLog); */
			uiXsensOversampleCounter = 0;
			oIMUOversamplingData.dXpp = 0.0;
			oIMUOversamplingData.dYpp = 0.0;
			oIMUOversamplingData.dZpp = 0.0; // the rest of oIMUOversamplingData is not resettet as there is no incremental update during reading

			for(uiTmpCtr = 0; uiTmpCtr < 4; uiTmpCtr++){
				sOrientationOversamplingData.m_data[uiTmpCtr] = 0.0;
			}
			iStatus = 1;
		//}
	}else{
		iStatus = 0;
	}
	return iStatus;
}

