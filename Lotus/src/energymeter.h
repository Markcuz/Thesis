#ifndef ENERGYMETER_H
#define ENERGYMETER_H

/**********************************************************************************************************************
**	Convetion on data names: Put abbrevation for data type in front of the name, eg. int iMyInt
**		int				i
**		unsigned int	ui
**		bool			b
**		double			d
**		char			c
**		enum			e
**		QString			str
**		(*)				p
**		(obj)			o
**		(struct)		s
**********************************************************************************************************************/

#include <QtGlobal>
#include <QtCore>
#include <QObject>
#include <QTime>
#include "xsens_cmt.h"
#include "quaternions.h"
#include "lotusmechanics.h"


//#########################################################################################
//##### THIS KEY IS PRIVATE -- NEVER SHARE THIS KEY IN PUBLICATIONS OR AS OPEN SOURCE #####
#define		XSENS_CLT_SERIAL					"1a53a-5bce0-a220e-b5be0"
//#########################################################################################

#define  	XSENS_CLT_SEND_FREQUENCY			200					//  5ms		Xsens sends Data ever 5ms
#define  	XSENS_CLT_BAUD_RATE					CMT_BAUD_RATE_921K6
//#define		XSENS_CLT_DEFAULT_PORT				"COM7"
#define     XSENS_CLT_DEFAULT_PORT              "/dev/ttsUSB0"      //NEED TO CHECK
#define  	XSENS_SRV_DIGITAL_OVERSAMPLING		  5					//			5 Xsens-datasets are taken for one internal dataset
#define  	XSENS_SRV_CLEARBUFFER_FQC			 50					// 50ms
#define  	XSENS_SRV_BUFFER_SIZE_TOTAL			100

#define		CAR_TOTAL_MASS						1200

#define  	SETTINGS_GROUP_EMETER				"EnergyMeter"
#define		SETTINGS_KEY_XSENSPORT				"Xsens Port"

struct DataSet_6DOFSensor{
	double dXpp;
	double dYpp;
	double dZpp;
	double dSinPhiY;
	double dPhiX;
	double dPhiY;
	double dPhiZ;

	DataSet_6DOFSensor(){
		dXpp		= 0.0;
		dYpp		= 0.0;
		dZpp		= 0.0;
		dSinPhiY	= 0.0;
		dPhiX		= 0.0;
		dPhiY		= 0.0;
		dPhiZ		= 0.0;
	}
};

class EnergyMeter : public QObject{ Q_OBJECT
/******************************************************************************************************************************
  **					Imu6dof Class
  ****************************************************************************************************************************/
public:
	explicit EnergyMeter(QObject *parent = 0);
	~EnergyMeter();

private:
	QSettings oSettings;
	CmtDeviceId uiXsensDeviceId;
	qint32 iXsensInstance;
	DataSet_6DOFSensor oIMUOversamplingData;
	CmtQuat sOrientationOversamplingData;
	quint8 uiXsensOversampleCounter;
	quint16 uiXsensSampleCounter;
	LotusMechanics* pMechanics;

	QTimer *pTimerXsensRead;

	/*
		include in rev_hmi.h/cpp

		readFromXsensDevice, readIsBraking and velocity (gps, can, �c) --> synced save (ringbuffer sends internal_update -> start processing)
										add ringbuffer, add top16
		call pMechanics->cmpEffort, send updated(Data)
		update Gui (every 500ms) & write log (every call).

		design GUI
	*/

signals:
	void updated(DataSet_6DOFSensor); // raw logging & processing
	void debugMsg(QtMsgType, QString, QString);

public slots:
	bool init();
	void end();
	void setDefaultSettings();

private slots:
	XsensResultValue scanForXsensDevice();
    XsensResultValue connectToXsens(const char *uiPortNr);
	void readFromXsensDevice();
	qint8 tryToSaveOversampledXsensData();
	double computeGCompensation(const CmtQuat* const sQuat, quint8 uiMode=0) const;

};

#endif // ENERGYMETER_H
