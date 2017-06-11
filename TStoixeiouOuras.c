/*************************************************************************
Αρχείo Υλoπoίησης	: TStoixeioOyras.c
Συγγραφέας			: Y. Cotronis 14/03/2015
Σκoπός				: Ylopoihsh typou stoixeiou Pelati ths oyras
Αναθεώρηση			:  Ageliki Felimega-28/3/15
**************************************************************************/
#include <stdio.h>
#include "TStoixeiouOuras.h"

void PelatisSetXronoEisodou(TPelatis *stoixeioPtr, int xronos)
{
	stoixeioPtr->XronosEisodou=xronos;
}

int PelatisGetXronoEisodou(TPelatis *stoixeioPtr)
{
	return stoixeioPtr->XronosEisodou;
}

void Pelatis_setValue(TPelatis *stoixeioPtr, TPelatis testdata)
{   
	stoixeioPtr->XronosEisodou = testdata.XronosEisodou;  /* basic type assignment */
	stoixeioPtr->XronosEksipiretisis = testdata.XronosEksipiretisis;
}

void Pelatis_printValue(TPelatis testdata)
{ 
	printf("|Xronos Eisodou = %d|", testdata.XronosEisodou);
}

int Pelatis_readValue(TPelatis *testdata)
{ 
	if (scanf("%d", &(testdata->XronosEisodou))!= 1)
		return 0;
	else return 1;
}

void PelatisSetXronoEksipiretisis(TPelatis *stoixeioPtr, int duration)
{
	stoixeioPtr->XronosEksipiretisis = duration;
}

int PelatisGetXronoEksipiretisis(TPelatis *stoixeioPtr)
{
	return stoixeioPtr->XronosEksipiretisis;	
}
