#include <QtGlobal>
#include "top16.h"

#undef TOP16DEBUG // #define TOP16DEBUG for detailled debugmessages

//----------------- Test main ------------------
int main(){
	Top16Instance* pInstance = new Top16Instance();
	char boards[10][20];
	int numBoards;
	int count;
	Top16Handle Handle;
	int loopCount;
	clock_t start, end;
	double elapsed;

	printf("Start\n");
	if (!pInstance->init()){
		printf("Failed to load FTD2XX.dll \n");
	}else{
		printf("Successfully loaded FTD2XX.dll \n");
	}

	numBoards = pInstance->ListTop16Boards(boards);
	for(count = 0;count < numBoards; count++){
		printf("found: %s\n", boards[count]);
	}

	getch();

	start = clock();
	Handle = pInstance->OpenBoard(boards[0]);
	if (Handle <= 0) exit(0);

	for (loopCount = 0; loopCount < 100; loopCount++){
		printf("count = %ld \n", (long int) pInstance->ReadPulseCount(Handle, 1));
		Sleep(2000);
		for (count = 0; count < 100; count++){
			printf("Analog input2 = %ld\n", (long int) pInstance->readAnalogInput( Handle, 2, 'Z'));
		}
	}
	pInstance->CloseBoard(Handle);
	end = clock();

	delete pInstance;
	elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Elapsed time = %f seconds.\n", elapsed);

	getch();
}
