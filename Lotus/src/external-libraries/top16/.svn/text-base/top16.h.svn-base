#ifndef _TOP16DLL_H_
#define _TOP16DLL_H_

/*
	based on top16aindllmain.c v1.6
	http://www.freewebs.com/tctec/forum.htm?forumID=2434016&page=1&topicID=1769457

	ported to cpp for (QTCreator & MinGW) by Valentin Falkenhahn (July 25, 2011)
	FTD2XX.dll needed during runtime, does NOT have to be included during build (see top16 homepage http://www.emx.net.au/top16dio.htm)
	just include top16.h and top16.cpp to your project (see example file main.cpp) and place FTD2XX.dll in the working directory of your app

	Project: top16_dll with analog input  [top16.dll]
	18-06-2008            Version 1.0            Created (c) TCTEC Pty Ltd, all rights reserved
	05-07-2008            Version 1.3            Added SetPWM function
	08-07-2008            Version 1.4            RVW changed all calls to _stdcall
	01-12-2008            Version 1.5            RVW added function SetOutputsB
	20-10-2010            Version 1.6            RVW added function ReadPulseCount
*/

#include <QtGlobal>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <conio.h>

#define FTDIDLL L"FTD2XX"

typedef qint32 (CALLBACK *FT_ListDevices) (void*, void*, int) ;
typedef void (CALLBACK *FT_CreateDeviceInfoList) ( qint32 *numDevices) ;
typedef void (CALLBACK *FT_GetDeviceInfoDetail) (quint32 temp, quint32 *Flags, quint32 *deviceType, quint32 *id, quint32 *locID, char *pcSerialNumber, char *pcDescription, quint32 *Handle);
typedef qint32 (CALLBACK *FT_OpenEx) (void* serialNumber, quint32 mode, quint32 *Handle) ;
typedef qint32 (CALLBACK *FT_GetBitMode) (quint32 Handle, quint8 *bitMode) ;
typedef qint32 (CALLBACK *FT_SetBitMode) (quint32 Handle, quint8 mask, quint8 mode) ;
typedef qint32 (CALLBACK *FT_Write) (quint32 Handle, void* Buffer, quint32 buflength, quint32 *tempInt);
typedef qint32 (CALLBACK *FT_Close) (quint32 Handle) ;
typedef qint32 (CALLBACK *FT_Read) (quint32 Handle, void* buffer, quint32 bytesToRead, quint32 *bytesRead) ;
typedef qint32 (CALLBACK *FT_SetBaudRate) (quint32 Handle, quint32 BaudRate) ;
typedef qint32 (CALLBACK *FT_SetDataCharacteristics) (quint32 Handle, quint8 WordLength, quint8 StopBits, quint8 Parity) ;
typedef qint32 (CALLBACK *FT_SetFlowControl) (quint32 Handle, quint16 FlowControl, quint8 Xon, quint8 Xoff) ;
typedef qint32 (CALLBACK *FT_Purge) (quint32 Handle, quint32 Mask) ;
typedef qint32 (CALLBACK *FT_SetTimeouts) (quint32 Handle, quint32 ReadTimeout, quint32 WriteTimeout) ;
typedef qint32 (CALLBACK *FT_SetUSBParameters) (quint32 Handle, quint32 InTransferSize, quint32 OutTransferSize);
typedef qint32 (CALLBACK *FT_GetStatus) (quint32 Handle, qint32 *AmountInRxQueue, qint32 *AmountInTxQueue, qint32 *EventStatus);

// FTDI constants
const quint32 FT_LIST_NUMBER_ONLY		= 0x80000000 ;
const quint32 FT_LIST_BY_INDEX			= 0x40000000 ;
const quint32 FT_LIST_ALL				= 0x20000000 ;
const quint32 FT_OPEN_BY_SERIAL_NUMBER	= 1 ;
const quint32 FT_OPEN_BY_DESCRIPTION	= 2 ;
const quint32 FT_OPEN_BY_LOCATION		= 4 ;
const quint32 FT_OK						= 0 ;
const quint8  FT_BITS_8					= 8 ;
const quint8  FT_STOP_BITS_1			= 0 ;
const quint8  FT_PARITY_NONE			= 0 ;
const quint16 FT_FLOW_NONE				= 0x0000 ;
const quint32 FT_BAUD_115200			= 115200;
const quint32 FT_BAUD_230400			= 230400 ;
const quint32 FT_PURGE_RX				= 1 ;
const quint32 FT_PURGE_TX				= 1 ;

typedef quint32 Top16Handle;

class Top16Instance {
public:
	Top16Instance();
	~Top16Instance();
	bool init();

	qint32 ListTop16Boards(char stringArray[][20]);
	quint32 OpenBoard(char* board);
	qint32 CloseBoard(quint32 Handle);
	qint32 SetOutputs(quint32 Handle, quint8 mask, quint8 set) ;
	qint32 SetOutputsB(quint32 Handle, quint8 mask, quint8 set) ;
	qint32 SetPWM(quint32 Handle, quint8 pwm, quint8 output) ;
	qint32 ReadInputs(quint32 Handle) ;
	qint32 readAnalogInput(quint32 Handle, qint16 input, quint8 gain) ;
	qint32 ReadPulseCount(quint32 Handle, qint16 input);

private:
	HINSTANCE hftdiDLL ;
	
	FT_ListDevices lpfnFT_ListDevices; // Function pointer to FT_ListDevices
	FT_CreateDeviceInfoList lpfnFT_CreateDeviceInfoList;
	FT_GetDeviceInfoDetail lpfnFT_GetDeviceInfoDetail ;
	FT_OpenEx lpfnFT_OpenEx ;
	FT_GetBitMode lpfnFT_GetBitMode ;
	FT_SetBitMode lpfnFT_SetBitMode ;
	FT_Write lpfnFT_Write ;
	FT_Read lpfnFT_Read ;
	FT_Close lpfnFT_Close ;
	FT_SetBaudRate lpfnFT_SetBaudRate ;
	FT_SetDataCharacteristics lpfnFT_SetDataCharacteristics ;
	FT_SetFlowControl lpfnFT_SetFlowControl ;
	FT_Purge lpfnFT_Purge ;
	FT_SetTimeouts lpfnFT_SetTimeouts ;
	FT_SetUSBParameters lpfnFT_SetUSBParameters ;
	FT_GetStatus lpfnFT_GetStatus ;
};

int hexcharToNibble(char hex);

#endif /* _TOP16DLL_H_ */
