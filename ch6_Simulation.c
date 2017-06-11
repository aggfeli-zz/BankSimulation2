/*************************************************
Arxeio ylopoihshs	: ch6_Simulation.c
Syggrafeas			: Y. Cotronis 14/03/2015
Skopos				: Ylopoihsh ouras prosomoiwshs
Αναθεώρηση			:  Ageliki Felimega-28/3/15
**************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ch6_QArray1.h"
#include "TStoixeiouOuras.h"
#include "tamias.h"

int main(void)
{	TOuras      	oura;				 /*oura pelatwn*/
	float			pithanotita_afiksis; /*pi8anothta afikshs*/
	unsigned int	xronos_prosomoiosis; /*synolikos xronos prosomoiwshs*/
	
	unsigned int	xronos;				 /*roloi prosomoiwshs*/
	int				xronos_trapezas;
	int				max_xronos;
	int				duration;
	int 			parapanw_xronos;	 /*o parapanw xronos poy emeine anoixth h trapeza*/
	unsigned int	xronos_anamonis;	 /*synolikos xronos anamonhs*/
	TPelatis		Pelatis;		 	/* o pelaths sthn oyra*/
	TTamias			tamias;
	float			mesos_xronos;		 /*mesos xronos anamonhs tvn pelatvn*/
	float			randomAfixi;
	time_t			t;


	printf("Dwste xrono poy kleinei h trapeza, pi8anothta afikshs (0,1) kai max xrono gia na brethei o xronos eksyphrethshs\n");
	scanf("%u %f %u",  &xronos_trapezas, &pithanotita_afiksis, &max_xronos);
	getchar();
	//printf("H prosomoiwsh 8a diarkesei %4u lepta.\n",xronos_prosomoiosis);
	printf("H pi8anothta afikshs pelath se ena lepto einai: %4.2f.\n",pithanotita_afiksis);

	OuraDimiourgia(&oura);
	TamiasDimiourgia(&tamias);
	xronos = 0;
	parapanw_xronos = 0;
	xronos_anamonis =0;
	srand(time(&t));

	while( xronos <= xronos_trapezas )
	{	/* Pelatis */
		randomAfixi = (float)rand()/(float)RAND_MAX; 

		if(xronos < xronos_trapezas )      /*mono an o xronos einai mikroteros toy xronou poy kleinei h trapeza dexetai pelates*/
		{
			randomAfixi = (float)rand() / (float)RAND_MAX; 

			if ( randomAfixi < pithanotita_afiksis)
			{
				PelatisSetXronoEisodou(&Pelatis, xronos);
				duration = rand() % max_xronos + 1 ;
				PelatisSetXronoEksipiretisis(&Pelatis, duration);
				printf("H diarkeia e3yphrethshs enos pelath einai statherh %d lepta.\n", PelatisGetXronoEksipiretisis(&Pelatis));
				if (!OuraProsthesi(&oura, Pelatis))
				{
        	        printf("H oyra einai mikrh! H prosomoivsh stamataei \n");
        	        getchar();
        	        return 0;
        		};
    		};
    	}
    	
    	/* Tamias */
    	
		if ( TamiasFree(&tamias) == 0) /*eley8eros tamias*/
		{	
			if (!OuraKeni(oura))			/*yparxei pelaths*/
			{
				OuraApomakrynsh(&oura,&Pelatis);		/*phgainei sto tamio*/
				xronos_anamonis += xronos - PelatisGetXronoEisodou(&Pelatis);	/*ypologismos xronoy paramonhs*/
				TamiasNewCustomer(&tamias);
				TamiasSetXrono(&tamias, PelatisGetXronoEksipiretisis(&Pelatis)); /* kallyptei to trexon lepto */
			}
			else
				TamiasNoWork(&tamias);
		}
		else
			TamiasBusy(&tamias);		/*o tamias apasxolhmenos me pelath */
		
		if(xronos < xronos_trapezas)
			xronos++; /*o xronos prosomoivshs ay3anetai kata 1 lepto*/
		else
		{
			parapanw_xronos++;
			if(SizeOuras(oura) == 0)
			{ 
				//parapanw_xronos += TamiasGetEnapomenonXronos(&tamias) -1 ;
				while(TamiasGetEnapomenonXronos(&tamias) !=0 )TamiasBusy(&tamias);
				break;																/*h trapeza ekleise afoy eksyphreth8hke k o teleytaios pelaths ths ouras*/
			} 
		}
	} /*while( xronos < xronos_prosomoiosis )*/

	if (TamiasGetArithmosPelatwn(&tamias) == 0)
		mesos_xronos = 0.0;
	else
		mesos_xronos = ((float)xronos_anamonis)/((float)TamiasGetArithmosPelatwn(&tamias));

	printf("\nEksyphreth8hkan %d pelates\n",TamiasGetArithmosPelatwn(&tamias));
	printf("Den eksyphreth8hkan %d pelates\n", SizeOuras(oura));
	printf("O tamias htan adranhs gia %d lepta\n", TamiasGetInactiveXronos(&tamias));
	printf("O tamias htan apasxolhmenos gia %d lepta\n", TamiasGetBusyXronos(&tamias));
	printf("O mesos xronos anamonhs htan %4.2f lepta.\n",mesos_xronos);
	printf("\nO xronos leitoyrgeias ths trapezas einai %d kai xreiasthkan parapanw %d lepta.\n", TamiasGetBusyXronos(&tamias), TamiasGetBusyXronos(&tamias)-xronos_trapezas);
    getchar();
	return 0;
}
