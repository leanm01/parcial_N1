/*
 ============================================================================
 Name        : PrimerParcialLaboratorio.c
 Author      : Merino Leandro
 Division    : 1J
 DNI         : 43 593 084
 Fecha   	 : 26/05/2022
 Profesor/a  : Yanina Scudero
 Copyright   : Your copyright notice
 Description :

Desarrollar en ANSI C:

Se necesita gestionar el Censo Nacional 2022 y para eso se deberá desarrollar lo siguiente:

ENTIDADES:
 VIVIENDA :
● idVivienda (comienza en 20000, autoincremental)
● calle (máximo 25 caracteres)
● cantidadPersonas
● cantidadHabitaciones
● tipoVivienda (1.CASA – 2.DEPARTAMENTO – 3.CASILLA - 4.RANCHO)
● legajoCensista (debe existir) Validar

 CENSISTA :
● legajoCensista
● nombre
● edad
● telefono
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "viviendas.h"
#include "censista.h"
#include "UTN.h"

#define TAM_VIVIENDA 4
#define TAM_CENSISTA 4

int main(void) {

	setbuf(stdout, NULL);


	eVivienda listaVivienda[TAM_VIVIENDA];
	initVivienda(listaVivienda,TAM_VIVIENDA);

	eCensista listaCensista[TAM_CENSISTA];
	initCensista(listaCensista,TAM_CENSISTA);

	int opcion;
	int contadorId=19999;//INICIALIZADO EN CERO PARA ALMACENAR LOS ID'S
	int hayVivienda=0;
	int hayCensista=1;
	int estadoAlta;
	int estadoBaja;

	initCensistaHardocodeo(listaCensista);

	do
	    {
	        opcion = menu();
	        switch(opcion)
	        {


	        case 1:///////////////////////////////////////////////////////////////////////////////////////////////////////// ALTA


						estadoAlta = agregarVivienda(listaVivienda, TAM_VIVIENDA, contadorId);/////// VIVIENDA


						 if(estadoAlta==-1)
						 {
							  printf("\nAlta vivienda erronea!!\n\n");
						 }
						 else
						 {
							   printf("\nAlta vivienda exitosa!!\n\n");
							   contadorId++;// PARA EL ID AUTOINCREMENTAL
							   hayVivienda=1;//PARA LA VALIDACION, SI ESTA EN UNO SE VA A PODER INGRESAR EN LAS DEMAS LLAMADAS A FUNCION
						 }
						 break;


	          case 2:///////////////////////////////////////////////////////////////////////////////////////////////////// MOSTRAR



						if(hayVivienda==0)
						{
								printf("\nNo hay Viviendas que mostrar!!\n\n");
						}
						else
						{
							estadoBaja=mostrarViviendas(listaVivienda, TAM_VIVIENDA,listaCensista,TAM_CENSISTA);


							if(estadoBaja==-1)
							{
								printf("\nOperacion erronea!!\n\n");

							}
							else
							{
								printf("\nOperacion exitosa!!\n\n");
							}
						}
						break;

	          case 3://///////////////////////////////////////////////////////////////////////////////////////////////////// MODIFICAR



						if(hayVivienda==0)
						{
								printf("\nNo hay Viviendas que modificar!!\n\n");
						}
						else
						{
							estadoBaja=modificacionViviendas(listaVivienda, TAM_VIVIENDA,listaCensista,TAM_CENSISTA);


							if(estadoBaja==-1)
							{
								printf("\nOperacion erronea!!\n\n");

							}
							else
							{
								printf("\nOperacion exitosa!!\n\n");
							}
						 }

					break;




			  case 4:///////////////////////////////////////////////////////////////////////////////////////////////////////// BAJA


							if(hayVivienda==0)
							{
								  printf("\nNo hay viviendas que se quieran eliminar!!\n\n");
							}
							else
							{
								 estadoBaja=bajaVivienda(listaVivienda, TAM_VIVIENDA,listaCensista,TAM_CENSISTA);

								  if(estadoBaja==-1)
								  {
									   printf("\nOperacion erronea!!\n\n");

								  }
								  else
								  {
									   printf("\nOperacion exitosa!!\n\n");
								  }
							 }
							break;

			 case 5://///////////////////////////////////////////////////////////////////////////////////////////////// LISTADO ORDENADO

							if(hayVivienda==0)
							{
								  printf("\nNo hay viviendas que ordenar!!\n\n");
							}
							else
							{
								 estadoBaja=ordenamientoViviendas(listaVivienda, TAM_VIVIENDA);

								  if(estadoBaja==-1)
								  {
									   printf("\nOperacion erronea!!\n\n");

								  }
								  else
								  {
									   printf("\nOperacion exitosa!!\n\n");
								  }
							 }
							break;



	         case 6://////////////////////////////////////////////////////////////////////////////////////////////////// LISTAR CENSISTA

								if(hayCensista==0)
								{
									  printf("\nNo hay Censistas que mostrar!!\n\n");
								}
								else
								{
									 estadoBaja=mostrarCensistas(listaCensista,TAM_CENSISTA);

									  if(estadoBaja==-1)
									  {
										   printf("\nOperacion erronea!!\n\n");

									  }
									  else
									  {
										   printf("\nOperacion exitosa!!\n\n");
									  }
								 }

								break;

	         case 7:

						 switch (informes())
						 {

						  case 1:

										if(hayVivienda==0)
										{
											  printf("\nNo hay Censistas que mostrar!!\n\n");
										}
										else
										{
											  promedioCensistas(listaCensista,TAM_CENSISTA);


										}


								 break;
						   case 2:

							   printf("\nSalir\n");
							   break;



						 }

						  break;

	            case 8:
	            	printf("\nGracias por usar el programa...\n");
	            break;
	        }


	    }while(opcion!=8);
}
