#include "top16.h"

#ifdef TOP16DEBUG
void top16debug(const WCHAR* string){
	MessageBox (0, string, L"Debug", MB_ICONINFORMATION);
}
#endif

Top16Instance::Top16Instance(){
	hftdiDLL = NULL;
}

Top16Instance::~Top16Instance(){
	if(hftdiDLL != NULL){
		FreeLibrary(hftdiDLL);
		hftdiDLL = NULL;
#ifdef TOP16DEBUG
		top16debug(L"Detached from ftdi dll");
#endif
	}
}

// Called once when a process first loads this dll Link to FTDI DLL and get function pointers. Also sets the baud rate and settings of the device / API
bool Top16Instance::init(){
#ifdef TOP16DEBUG
	top16debug(L"Setup Library");
#endif

	// Load the FTD2XX.DLL
	hftdiDLL = LoadLibrary(FTDIDLL);
	if(hftdiDLL != NULL){
#ifdef TOP16DEBUG
		top16debug(L"Success. linked to FTD2XX");
#endif

		// Get pointers to the functions in the DLL
		lpfnFT_ListDevices = (FT_ListDevices)GetProcAddress(hftdiDLL, "FT_ListDevices");
		lpfnFT_CreateDeviceInfoList = (FT_CreateDeviceInfoList)GetProcAddress(hftdiDLL, "FT_CreateDeviceInfoList");
		lpfnFT_GetDeviceInfoDetail  =  (FT_GetDeviceInfoDetail)GetProcAddress(hftdiDLL, "FT_GetDeviceInfoDetail");
		lpfnFT_OpenEx = (FT_OpenEx) GetProcAddress(hftdiDLL, "FT_OpenEx");
		lpfnFT_GetBitMode = (FT_GetBitMode) GetProcAddress(hftdiDLL, "FT_GetBitMode");
		lpfnFT_SetBitMode = (FT_SetBitMode) GetProcAddress(hftdiDLL, "FT_SetBitMode");
		lpfnFT_Write = (FT_Write) GetProcAddress(hftdiDLL, "FT_Write");
		lpfnFT_Read = (FT_Read) GetProcAddress(hftdiDLL, "FT_Read");
		lpfnFT_Close = (FT_Close) GetProcAddress(hftdiDLL, "FT_Close");

		lpfnFT_SetBaudRate = (FT_SetBaudRate) GetProcAddress(hftdiDLL, "FT_SetBaudRate");
		lpfnFT_SetDataCharacteristics = (FT_SetDataCharacteristics) GetProcAddress(hftdiDLL, "FT_SetDataCharacteristics");
		lpfnFT_SetFlowControl = (FT_SetFlowControl) GetProcAddress(hftdiDLL, "FT_SetFlowControl");
		lpfnFT_Purge = (FT_Purge) GetProcAddress(hftdiDLL, "FT_Purge");
		lpfnFT_SetTimeouts = (FT_SetTimeouts) GetProcAddress(hftdiDLL, "FT_SetTimeouts");

		lpfnFT_SetUSBParameters = (FT_SetUSBParameters) GetProcAddress(hftdiDLL, "FT_SetUSBParameters");
		lpfnFT_GetStatus = (FT_GetStatus) GetProcAddress(hftdiDLL, "FT_GetStatus");

		if(!lpfnFT_ListDevices || !lpfnFT_CreateDeviceInfoList || !lpfnFT_GetDeviceInfoDetail || !lpfnFT_OpenEx || !lpfnFT_GetBitMode || !lpfnFT_SetBitMode || !lpfnFT_Write || !lpfnFT_Read || !lpfnFT_SetBaudRate || !lpfnFT_SetDataCharacteristics || !lpfnFT_SetFlowControl || !lpfnFT_SetTimeouts || !lpfnFT_Purge || !lpfnFT_SetUSBParameters || !lpfnFT_GetStatus){
			// Couldn't find the functions, so exit
			FreeLibrary(hftdiDLL);
#ifdef TOP16DEBUG
			top16debug(L"Failed. linking to functions.");
#endif
			return (false);
		}
		return(true); // success
	}else{
		return(false);
	}
}

/* Search for attached TCTEC Top16Instance DIO boards. The stringArray will be filled with the names of the boards. It must point to a 2 dimensional char (8bit) array of dimensions [n][20] where n is the number of boards expected.
Returns: The number of top16 boards found or 0 if none found.
*/
qint32 Top16Instance::ListTop16Boards(char stringArray[][20]){
	qint32 numDevices;
	quint32 temp;
	quint32 Flags;
	quint32 deviceType;
	quint32 id;
	quint32 locID;
	char pcSerialNumber[100];
	char pcDescription [200];
	quint32 Handle;
	int deviceCount = 0;

	// get details of connected FTDI devices
	(lpfnFT_CreateDeviceInfoList) (&numDevices);

	// list all the devices with the correct description
	for(temp = 0; temp < (unsigned) numDevices; temp++){
		(lpfnFT_GetDeviceInfoDetail) (temp, &Flags, &deviceType, &id, &locID, pcSerialNumber, pcDescription, &Handle);
		if(strstr(pcDescription, "TCTEC TOP16DIO") != NULL){ // found one
			strncpy(stringArray[deviceCount], pcSerialNumber, 19);
			deviceCount += 1;
		}
	}
	return(deviceCount);
}

/* Close an open board.
Handle		Handle of open board.
Returns:	0 == success
*/

qint32 Top16Instance::CloseBoard(quint32 Handle){
	return( (lpfnFT_Close) (Handle) );
}

/* Initialize a top16 board, returns a Handle (uint32)to opened board if successful. Must be called before set and get commands.
Returns:	>0 = Handle of opened board.
			-1 = invalid board
*/
quint32 Top16Instance::OpenBoard(char* board) {
	quint32 tempInt;
	quint32 Handle;
	
	if(hftdiDLL == NULL) return(-1);

	// open a device 	
	tempInt = (lpfnFT_OpenEx) ((void*)board, FT_OPEN_BY_SERIAL_NUMBER, &Handle);
	if(tempInt != FT_OK) return(-1);

	// set the baud rate, data format and flow control of the FTDI chip
	tempInt = (lpfnFT_SetFlowControl) (Handle, FT_FLOW_NONE, 0, 0);
#ifdef TOP16DEBUG
	printf("returned %d\n", tempInt);
#endif
	tempInt += (lpfnFT_SetDataCharacteristics) (Handle, FT_BITS_8, FT_STOP_BITS_1, FT_PARITY_NONE);
#ifdef TOP16DEBUG
	printf("returned %d\n", tempInt);
#endif
	tempInt += (lpfnFT_SetBaudRate) (Handle, FT_BAUD_115200);
#ifdef TOP16DEBUG
	printf("returned %d\n", tempInt);
#endif
	tempInt += (lpfnFT_SetTimeouts) (Handle, 500, 500);
#ifdef TOP16DEBUG
	printf("returned %d\n", tempInt);
#endif
	tempInt += (lpfnFT_Purge) (Handle, FT_PURGE_RX | FT_PURGE_TX);
#ifdef TOP16DEBUG
	printf("returned %d\n", tempInt);
#endif

	if(tempInt != FT_OK){
		(lpfnFT_Close) (Handle);
		return (-1);
	}

	//(lpfnFT_Close) (Handle);
	return(Handle);
}

/* Set the digital output states.
	8 bits of the 'mask' determines which outputs will be affected:
		1 = output will be affected
		0 = leave alone (don't change)
	'set' determines whether the outputs in mask will be switched on or switched off. set can only be '1' or '0'
		1 = output on (pulled low)
		0 = output off (not pulled low).
Returns: The state of the outputs after the action. 0 to FF:
			1 = output is on (pulled low).
			0 = output is off (not pulled low)
		 A negative number indicates an error:
			-1 invalid board handle (board not found)
			-2 DLL function not loaded (FTD2XX.DLL not found)
			-3 Invalid bit mask (must be 0 to FF)
			-4 Undefined error
*/
qint32 Top16Instance::SetOutputs(quint32 Handle, quint8 mask, quint8 set){
	quint32 tempInt;
	quint32 byteCount;
	quint32 outputState;
	BOOL retry = TRUE;
	int retryCount = 3;
	char rxCommand[10];
	char txCommand[10];

	// Send command
	if(set){
		sprintf(txCommand, "#FF%1X%1X\r", ((mask & 0xF0)>>4), (mask & 0x0F));
	}else{
		sprintf(txCommand, "#00%1X%1X\r", ((mask & 0xF0)>>4), (mask & 0x0F));
	}

	// ---------------- send loop -------------------
	while (retry && (retryCount > 0)){
		retry = FALSE;
		retryCount--;

		tempInt = (lpfnFT_Write) (Handle, (void*) &txCommand, 6, &byteCount);
		if(tempInt != FT_OK){
			// (lpfnFT_Close) (Handle);
			return (-4);
		}

		tempInt = (lpfnFT_Read) (Handle, (void*) &rxCommand, 6, &byteCount);
		if(tempInt != FT_OK){
			//(lpfnFT_Close) (Handle);
			return (-4);
		}
		if(byteCount >= 6){ // returned data is in the format >IIOO[CR]
			if(rxCommand[0] != '>'){ // validate response
				retry = true;
			}else{ // decode response
				outputState = hexcharToNibble(rxCommand[3]);
				outputState <<= 4;
				outputState |= hexcharToNibble(rxCommand[4]);
				if((outputState > 0xFF) || (outputState < 0)){
					retry = true;
				}
			}
		}else{
			retry = true;
		}
		if(retry == true){ // purge the RX and TX buffer
			(lpfnFT_Purge) (Handle, (FT_PURGE_RX | FT_PURGE_TX));
		}
	} // --------------------- end send loop -----------------------
	//(lpfnFT_Close) (Handle);

	if(retry == true){// tried too many times
		return (-4);
	}
	return(outputState);
}

/* Set the digital output states.
	8 bits of the 'mask' determines which outputs will be affected:
		1 = output will be affected
		0 = leave alone (don't change)
	8 bits of 'set' determines whether the output will be switched on or switched off.
		1 = output on (pulled low)
		0 = output off (not pulled low).
Returns: The state of the outputs after the action. 0 to FF:
			1 = output is on (pulled low).
			0 = output is off (not pulled low)
		 A negative number indicates an error:
			-1 invalid board handle (board not found)
			-2 DLL function not loaded (FTD2XX.DLL not found)
			-3 Invalid bit mask (must be 0 to FF)
			-4 Undefined error
*/
qint32 Top16Instance::SetOutputsB(quint32 Handle, quint8 mask, quint8 set){
	quint32 tempInt;
	quint32 byteCount;
	quint32 outputState;
	BOOL retry = TRUE;
	int retryCount = 3;
	char rxCommand[10];
	char txCommand[10];

	// Send command
	sprintf(txCommand, "#%1X%1X%1X%1X\r", ((set & 0xF0)>>4), (set & 0x0F), ((mask & 0xF0)>>4), (mask & 0x0F));

	// ---------------- send loop -------------------
	while (retry && (retryCount > 0)){
		retry = FALSE;
		retryCount--;

		tempInt = (lpfnFT_Write) (Handle, (void*) &txCommand, 6, &byteCount);
		if(tempInt != FT_OK) {
			// (lpfnFT_Close) (Handle);
			return (-4);
		}
		tempInt = (lpfnFT_Read) (Handle, (void*) &rxCommand, 6, &byteCount);

		if(tempInt != FT_OK){
			//(lpfnFT_Close) (Handle);
			return (-4);
		}

		if(byteCount >= 6){ // returned data is in the format >IIOO[CR]
			if(rxCommand[0] != '>'){ // validate response
				retry = true;
			}else{ // decode response
				outputState = hexcharToNibble(rxCommand[3]);
				outputState <<= 4;
				outputState |= hexcharToNibble(rxCommand[4]);  
				if((outputState > 0xFF) || (outputState < 0)){
					retry = true;
				}
			}
		}else{
			retry = true;
		}

		if(retry == true){ // purge the RX and TX buffer
			(lpfnFT_Purge) (Handle, (FT_PURGE_RX | FT_PURGE_TX));
		}
	} // --------------------- end send loop -----------------------
	//(lpfnFT_Close) (Handle);

	if(retry == true){ // tried too many times
		return (-4);
	}
	return(outputState);
}

/* Set a PWM value on an output
pwm			0x00 to 0xFF pwm width
output		the output to set (1 to 8)
Returns:	0 success
			-1 invalid pwm value
			-2 invalid output
			-4 undefined error
*/
qint32 Top16Instance::SetPWM(quint32 Handle, quint8 pwm, quint8 output){
	quint32 tempInt;
	quint32 byteCount;
	BOOL retry = TRUE;
	int retryCount = 3;
	char rxCommand[10];
	char txCommand[10];

	if((output == 0) || (output > 8)) return(-2);

	// Send command
	if(pwm <= 0x0F){
		sprintf(txCommand, "#P%1X0%1X\r", (output), (pwm));
	}else{
		sprintf(txCommand, "#P%1X%2X\r", (output), (pwm));
	}
	printf("%s\n", txCommand);

	// ---------------- send loop -------------------
	while (retry && (retryCount > 0)){
		retry = FALSE;
		retryCount--;
		tempInt = (lpfnFT_Write) (Handle, (void*) &txCommand, 6, &byteCount);

		if(tempInt != FT_OK)    {
			// (lpfnFT_Close) (Handle);
			return (-4);
		}
		tempInt = (lpfnFT_Read) (Handle, (void*) &rxCommand, 4, &byteCount);

		if(tempInt != FT_OK){
			//(lpfnFT_Close) (Handle);
			return (-4);
		}

		if(byteCount >= 4){ // returned data is in the format >OK[CR]
			if(rxCommand[0] != '>'){ // validate response
				retry = true;
			} // else: do nothing
		}else{
			retry = true;
		}
		if(retry == true){ // purge the RX and TX buffer
			(lpfnFT_Purge) (Handle, (FT_PURGE_RX | FT_PURGE_TX));
		}
	}// --------------------- end send loop -----------------------

	//(lpfnFT_Close) (Handle);
	if(retry == true){ // tried too many times
		return (-4);
	}
	return(0); // success
}


/* Read the digital inputs.
Returns: The state of the digital inputs 0 to FF:
			1 = input is high
			0 = input is low
		 A negative number indicates an error:
			-1 invalid board handle (board not found)
			-2 DLL function not loaded (FTD2XX.DLL not found)
			-4 Undefined error
*/
qint32 Top16Instance::ReadInputs(quint32 Handle){
	quint32 tempInt;
	quint32 inputState;
	BOOL retry = TRUE;
	int retryCount = 3;
	quint32 byteCount;
	char rxCommand[10];
	char txCommand[10];

	sprintf(txCommand, "#SSSS\r"); // Send dummy set command

	// ---------------- send loop -------------------
	while (retry && (retryCount > 0)){
		retry = FALSE;
		retryCount--;

		tempInt = (lpfnFT_Write) (Handle, (void*) &txCommand, 6, &byteCount);
		if(tempInt != FT_OK)    {
			// (lpfnFT_Close) (Handle);
			return (-4);
		}

		tempInt = (lpfnFT_Read) (Handle, (void*) &rxCommand, 6, &byteCount);
		if(tempInt != FT_OK){
			//(lpfnFT_Close) (Handle);
			return (-4);
		}

		if(byteCount >= 6){// returned data is in the format >IIOO[CR]
			if(rxCommand[0] != '>'){   // validate response
				retry = true;
			}else{// decode response
				inputState = hexcharToNibble(rxCommand[1]);
				inputState <<= 4;
				inputState |= hexcharToNibble(rxCommand[2]);
				if((inputState > 0xFF) || (inputState < 0)){ // the value is invalid, something went wrong
					retry = true;
				}
			}
		}else{
			retry = true;
		}

		if(retry == true){ // purge the RX and TX buffer
			(lpfnFT_Purge) (Handle, (FT_PURGE_RX | FT_PURGE_TX));
		}
	}// --------------------- end send loop -----------------------
	//(lpfnFT_Close) (Handle);

	if(retry == true){ // tried too many times
		return (-4);
	}
	return(inputState);
}

/* Read an analog input. The internal analog amplifier is set to the gain specified, then the input is sampled.
Handle	A Handle of an open Top16Instance board.
input	1 to 8
gain	'Z' = 1
		'Y' = 2
		'X' = 4
		'W' = 8
		'V' = 16
		'U' = 32
		'T' = 64
Returns: The raw analog input value (12 bit : 0 to 4096) at the gain specified. A negative number indicates an error:
		-1 invalid board handle (board not found)
		-2 DLL function not loaded (FTD2XX.DLL not found)
		-3 invalid gain
		-4 Undefined error
*/
qint32 Top16Instance::readAnalogInput(quint32 Handle, qint16 input, quint8 gain){
	quint32 tempInt;
	quint32 inputState = -4;
	BOOL retry = TRUE;
	int retryCount = 3;
	quint32 byteCount;
	char rxCommand[10];
	char txCommand[10];

	if((input < 1) || (input > 8)) return (-4);
	if((gain > 'Z') || (gain < 'T')) return (-3); // invalid gain


	// Send command
	sprintf(txCommand, "#%c%1XZZ\r", gain, input);

	// ---------------- send loop -------------------
	while (retry && (retryCount > 0)){
		retry = FALSE;
		retryCount--;

		tempInt = (lpfnFT_Write) (Handle, (void*) &txCommand, 6, &byteCount);

		if(tempInt != FT_OK)    {
			// (lpfnFT_Close) (Handle);
			return (-4);
		}

		tempInt = (lpfnFT_Read) (Handle, (void*) &rxCommand, 6, &byteCount);
		if(tempInt != FT_OK){
			//(lpfnFT_Close) (Handle);
			return (-4);
		}

		if(byteCount >= 6){ // returned data is in the format >nnnn[CR]
			if(rxCommand[0] != '>'){ // validate response
				retry = true;
			}else{ // decode response
				inputState = hexcharToNibble(rxCommand[1]);
				inputState <<= 4;
				inputState |= hexcharToNibble(rxCommand[2]);
				inputState <<= 4;
				inputState |= hexcharToNibble(rxCommand[3]);
				inputState <<= 4;
				inputState |= hexcharToNibble(rxCommand[4]);
			}
		}else{
			retry = true;
		}

		if(retry == true){ // purge the RX and TX buffer
			(lpfnFT_Purge) (Handle, (FT_PURGE_RX | FT_PURGE_TX));
		}
	}// --------------------- end send loop -----------------------

	//(lpfnFT_Close) (Handle);
	if(retry == true){ // tried too many times
		return (-4);
	}
	return(inputState);
}

/* Read the pulse count of an input
Handle	A Handle of an open Top16Instance board.
input	1 to 8
Returns: The pulse count (negative edges) 0 to 32767. A negative number indicates an error:
			-1 invalid board handle (board not found)
			-2 DLL function not loaded (FTD2XX.DLL not found)
			-3 invalid gain
			-4 Undefined error
*/
qint32 Top16Instance::ReadPulseCount(quint32 Handle, qint16 input){
	quint32 tempInt;
	quint32 inputState = -4;
	BOOL retry = TRUE;
	int retryCount = 3;
	quint32 byteCount;
	char rxCommand[10];
	char txCommand[10];

	if((input < 1) || (input > 8)) return (-4);

	// Send command
	sprintf(txCommand, "#I%1X\r", input);
	// ---------------- send loop -------------------
	while (retry && (retryCount > 0)){
		retry = FALSE;
		retryCount--;

		tempInt = (lpfnFT_Write) (Handle, (void*) &txCommand, 4, &byteCount);
		if(tempInt != FT_OK){
			// (lpfnFT_Close) (Handle);
			return (-4);
		}

		tempInt = (lpfnFT_Read) (Handle, (void*) &rxCommand, 6, &byteCount);
		if(tempInt != FT_OK){
			//(lpfnFT_Close) (Handle);
			return (-4);
		}

		if(byteCount >= 6){ // returned data is in the format >nnnn[CR]
			if(rxCommand[0] != '>'){ // validate response
				retry = true;
			}else{ // decode response
				inputState = hexcharToNibble(rxCommand[1]);
				inputState <<= 4;
				inputState |= hexcharToNibble(rxCommand[2]);
				inputState <<= 4;
				inputState |= hexcharToNibble(rxCommand[3]);
				inputState <<= 4;
				inputState |= hexcharToNibble(rxCommand[4]);
			}
		}else{
			retry = true;
		}

		if(retry == true){ // purge the RX and TX buffer
			(lpfnFT_Purge) (Handle, (FT_PURGE_RX | FT_PURGE_TX));
		}
	} // --------------------- end send loop -----------------------
	//(lpfnFT_Close) (Handle);

	if(retry == true){ // tried too many times
		return (-4);
	}
	return(inputState); // the pulse count
}

// Converts a human readable character to a number representation. Returns <0 if error
int hexcharToNibble(char hex){
	int output = 0;
	if((hex >= '0') && (hex <= '9')){
		output |= (hex - '0');
	}else if((hex >= 'A') && (hex <= 'F')){
		output = 0x0A + (hex - 'A');
	}else{
		output = -1;
	}
	return(output);
}

