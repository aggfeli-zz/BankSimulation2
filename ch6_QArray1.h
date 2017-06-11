/**********************************************+**************************
������ ������������	: QArray.h
����������				: Y. Cotronis 14/03/2015
������					: ��������� �� ������ ���������� ����� ��������� ����
����������				:  Ageliki Felimega-28/3/15
**************************************************************************/
#ifndef __CH2_QARRAY__ 
#define __CH2_QARRAY__
#include "TStoixeiouOuras.h"

/*�������� �����*/

#define PLITHOS 1000

typedef struct {
	int embros;		/*���� ��� ������ ��������� ��� �����*/
	int piso;		/*���� ��� ���������� ��������� ��� �����*/
	int metritis;
	TPelatis pinakas[PLITHOS];	/*� ������� ���������*/
} TOuras;	   /*� ����� ��� �����*/

/*�������� �����������*/

/*����������*/  
void OuraDimiourgia(TOuras *oura);

/*������� �������*/
int	OuraKeni	(TOuras oura);

/*������� ���������/������������*/
int OuraProsthesi	(TOuras *oura, TPelatis stoixeio);
int OuraApomakrynsh(TOuras *oura, TPelatis *stoixeio);

int SizeOuras(TOuras oura);

#endif /*#ifndef __CH2_QARRAY__ */
