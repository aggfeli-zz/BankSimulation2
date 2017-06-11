/*************************************************************************
tamias.c
Ageliki Felimega-28/3/15
Ylopoihsh typou tamias
**************************************************************************/
#include <stdio.h>
#include "tamias.h"


void TamiasDimiourgia(TTamias *tamias)
{
	tamias->TimeBusy = 0;
	tamias->TimeInactive = 0;
	tamias->ArithmoPelaton = 0;
	tamias->enapomenonXronos = 0;
} 				

void TamiasNewCustomer(TTamias *tamias)
{
	++(tamias->ArithmoPelaton);
}	
		
void TamiasSetXrono(TTamias *tamias, int xr_eksyphrethshs)
{
	(tamias->enapomenonXronos) = xr_eksyphrethshs ;
}

void TamiasNoWork(TTamias *tamias)
{

	++(tamias->TimeInactive);

}		

void TamiasBusy(TTamias *tamias)
{
	++(tamias->TimeBusy);
	--(tamias->enapomenonXronos);
}		
			
int TamiasFree(TTamias *tamias)
{
	return tamias->enapomenonXronos;
}				

int TamiasGetArithmosPelatwn(TTamias *tamias)
{
	return tamias->ArithmoPelaton;
}

int TamiasGetEnapomenonXronos(TTamias *tamias)
{
	return tamias->enapomenonXronos;
}	
	
int TamiasGetInactiveXronos(TTamias *tamias)
{
	return tamias->TimeInactive;
}	
		
int TamiasGetBusyXronos(TTamias *tamias)
{
	return tamias->TimeBusy;
}
