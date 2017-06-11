/**********************************************+**************************
Αρχείο Επικεφαλίδας	: TStoixeioOyras.h
Συγγραφέας				: Y. Cotronis 14/03/2015
Σκοπός					: Diepafi typou stoixeiou Pelatis ths oyras
Αναθεώρηση				:  Ageliki Felimega-28/3/15
**************************************************************************/
#ifndef __TStoixeioOuras__ 
#define __TStoixeioOuras__

typedef struct {
	int XronosEisodou; /* Minute of entering queue */
	int XronosEksipiretisis;
} TPelatis;


void PelatisSetXronoEisodou(TPelatis *stoixeioPtr, int xronos);
int PelatisGetXronoEisodou(TPelatis *stoixeioPtr);

void PelatisSetXronoEksipiretisis(TPelatis *stoixeioPtr, int duration);
int PelatisGetXronoEksipiretisis(TPelatis *stoixeioPtr);

void Pelatis_setValue(TPelatis *stoixeioPtr, TPelatis testdata);

void Pelatis_printValue(TPelatis testdata);
int  Pelatis_readValue(TPelatis *testdata);

#endif
