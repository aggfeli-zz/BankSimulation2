/*************************************************************************
Αρχείo Υλoπoίησης	: tamias.h
Συγγραφέας			: Ageliki Felimega-28/3/15
Σκoπός				: Diepafi typou tamias
**************************************************************************/
#ifndef __Tamias__ 
#define __Tamias__


typedef struct {
	int TimeBusy; 				/* o xronos pou htan apasxolhmenos*/
	int TimeInactive;			/*o xronos pou htan adranhs*/
    int ArithmoPelaton;			/*o arithmos pelatwn poy eksyphrethse*/
    int enapomenonXronos;		/*o xronos poy apomenei gia na oloklhrvsei thn eksyphrethsh tou pelath*/
} TTamias;



void TamiasDimiourgia(TTamias *tamias); 				/*arxikopoiei ta melh toy struct tamia*/

void TamiasNewCustomer(TTamias *tamias);				/*auksanei ton metrhth pelatwn*/
void TamiasSetXrono(TTamias *tamias, int duration);		/*arxikopoiei anepomeinanta xrono*/
void TamiasNoWork(TTamias *tamias);						/*auksanei xrono adraneias*/
void TamiasBusy(TTamias *tamias);						/*auksanei xrono apasxolhshs kai meiwnei to enapomeinanta xrono apasxolhshs*/
int TamiasFree(TTamias *tamias);						/*elegxei an einai diathesimos*/

int TamiasGetArithmosPelatwn(TTamias *tamias);			/*epistrefei arithmo pelatwn*/
int TamiasGetEnapomenonXronos(TTamias *tamias);			/*epistrefei anepomeinanta xrono*/
int TamiasGetInactiveXronos(TTamias *tamias);			/*epistrefei xrono adraneias*/
int TamiasGetBusyXronos(TTamias *tamias);				/*epistrefei xrono apasxolhshs*/


#endif
