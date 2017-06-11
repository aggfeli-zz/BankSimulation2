/*************************************************************************
Αρχείo Υλoπoίησης	: QArray.c
Συγγραφέας			: Y. Cotronis
Σκoπός				: Υλoπoίηση με πίνακα Αφηρημένoυ Τύπoυ Δεδoμένων, Ουρά
Αναθεώρηση			:  Ageliki Felimega-28/3/15
**************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "ch6_QArray1.h"

/*oρισμός συναρτήσεων*/

void OuraDimiourgia(TOuras *oura )
{
	oura->embros =  0;
	oura->piso = 0;
	oura->metritis = 0;
}

int OuraKeni(TOuras oura)
{
	return ( oura.metritis == 0 );
}

int OuraGemati(TOuras oura) /* OXI sthn diepafi-edv bohthitikh */
{
	/*int neo_piso = (oura.piso+1) % PLITHOS;
	if (neo_piso == oura.embros )
		return 1;
	else 
		return 0;*/
	return (oura.metritis == PLITHOS);
}

int OuraProsthesi(TOuras *oura, TPelatis stoixeio)
{
	int full;
	if (OuraGemati(*oura))
		full = 0;
	else
	{
		++(oura->metritis);
		Pelatis_setValue(&(oura->pinakas[oura->piso]),stoixeio); /* abstraction of = for any type */
		oura->piso = ( oura->piso + 1 )% PLITHOS;
		full = 1;
	}
	return full;
}

int OuraApomakrynsh(TOuras *oura, TPelatis *stoixeio)
{
	int empty;
	if (OuraKeni(*oura))
		empty = 0;
	else
	{
		--(oura->metritis);
		Pelatis_setValue(stoixeio, oura->pinakas[oura->embros]); /* abstraction of = for any type */
		oura->embros = ( oura->embros + 1 )% PLITHOS;
		empty = 1;
	}
	return empty;
}

int SizeOuras(TOuras oura)
{
	return oura.metritis;
}
