#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "viviendas.h"
#include "censista.h"
#include "UTN.h"


int initCensista(eCensista* arrayCensista, int tamArrayCensista)
{
    int i;
    int retorno=-1;


       if (tamArrayCensista !=0)
        {
            for (i=0;i<tamArrayCensista;i++)
            {
            	arrayCensista[i].isEmpty=1;// 1 = SI ESTA VACIO -- 0 = NO ESTA VACIO
            	retorno=0;//RETORNO EN CERO PARA QUE NO SEA -1
            }
        }

        return retorno;
}



void initCensistaHardocodeo(eCensista* arrayCensista)
{
		eCensista auxCensista[4] =  {{100,"Ana",34,12032345},
									{101,"Juan",24,430154678},
									{102,"Sol",47,590237487},
									{102,"Sol",47,590237487}};


	    int i;
	    for (i=0; i<4; i++)
	    {

	    	arrayCensista[i]=auxCensista[i];

	        arrayCensista[i].isEmpty = 0; // OCUPADO. // VALIDA QUE EL EXISTA EL CENSISTA
	    }
}

int mostrarCensistas(eCensista* arrayCensista, int tamArrayCensista)
{

    int i;
    int resultado=-1;

    if(arrayCensista != NULL && tamArrayCensista>=0)
    {
        for(i=0;i<tamArrayCensista;i++)
        {


        		if(arrayCensista[i].isEmpty==0)
				{
        			mostrarCensista(arrayCensista,i);
				}



        }
       resultado=1;
    }

    return resultado;
}

int mostrarCensista(eCensista* arrayCensista , int i)
{


   printf("\nLEGAJO CENSISTA:%d---NOMBRE:%s---EDAD:%d---TELEFONO:%d\n",        arrayCensista[i].legajoCensista,
																			   arrayCensista[i].nombre,
																			   arrayCensista[i].edad,
																			   arrayCensista[i].telefono);






	return 1;
}
void promedioCensistas(eCensista* arrayCensista, int tamArrayCensista)
{
    int contador=0;
    float viviendas=0;


    for (int i=0;i<tamArrayCensista;i++)
        {
            if (arrayCensista[i].isEmpty==0)
            {
            	viviendas = viviendas + arrayCensista[i].legajoCensista;
                contador++;

            }

        }



    printf("\nEl censista con mas casas visitadas:%d\n",contador);


}
