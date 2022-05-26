/*
 * viviendas.c
 *
 *  Created on: 20 may. 2022
 *      Author: Leandro
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "viviendas.h"
#include "censista.h"
#include "UTN.h"

int initVivienda(eVivienda* arrayVivienda, int tamArray)
{
    int i;
    int retorno=-1;


       if(tamArray !=0)
        {
            for (i=0;i<tamArray;i++)
            {
            	arrayVivienda[i].isEmpty=1;// 1 = SI ESTA VACIO -- 0 = NO ESTA VACIO
            	retorno=0;//RETORNO EN CERO PARA QUE NO SEA -1
            }
        }

        return retorno;
}

int agregarVivienda(eVivienda* arrayVivienda, int tamArray, int contador)
{
    int resultado=0;
    int espacioLibre=-1;
    int i;
    int opc;

    if(tamArray > 0)// SI ES MAYOR A CERO ENTRA AL RECORRER
    {
        for (i=0;i<tamArray;i++)
        {
            if(arrayVivienda[i].isEmpty==1)// COMPARA QUE ISEMPTY NO ESTE VACIO
            {

                espacioLibre=i;// EL ESPACIO LIBRE YA NO VA A SER -1

                break;
            }
        }
    }

    if(espacioLibre >=0)
    {



    	    utn_getNombre("\nIngrese el nombre de la calle: ","\nIngrese una calle correcta: ",arrayVivienda[espacioLibre].calle,2,25);

            utn_getInt("\nIngrese la cantidad de personas: ","\nIngresa un valor correcto 0-20: ",&arrayVivienda[espacioLibre].cantidadPersonas,2,20,0);

            utn_getInt("\nIngrese la cantidad de habitaciones: ","\nIngresa un valor correcto 0-20: ",&arrayVivienda[espacioLibre].cantidadHabitaciones,2,20,0);

            printf("\nIngrese opcion: \n");
			printf("1.CASA\n");
			printf("2.DEPARTAMENTO\n");
			printf("3.CASILLA\n");
			printf("4.RANCHO\n");
			scanf("%d",&opc);

			switch(opc)//UN SWITCH EN EL QUE PUEDA ELEGIR
			{
			case 1:
			strcpy(arrayVivienda[espacioLibre].tipoVivienda,"CASA");
			break;
			case 2:
			strcpy(arrayVivienda[espacioLibre].tipoVivienda,"DEPARTAMENTO");
			break;
			case 3:
			strcpy(arrayVivienda[espacioLibre].tipoVivienda,"CASILLA");
			break;
			case 4:
			strcpy(arrayVivienda[espacioLibre].tipoVivienda,"RANCHO");
			break;
			}

            arrayVivienda[espacioLibre].idVivienda=contador+1;

            arrayVivienda[espacioLibre].isEmpty=0;//VIVIENDA OCUPADA


            resultado=1;
    }



    return resultado;
}

int mostrarViviendas(eVivienda* arrayVivienda, int tamArray, eCensista* arrayCensista, int tamArrayCensista)
{

    int i;
    int resultado=-1;

    if(arrayVivienda != NULL && tamArray>=0)// TAM MAYOR A CERO PARA QUE SEPA QUE SI HAY ALGO QUE RECORRER Y MOSTRAR
    {
        for(i=0;i<tamArray;i++)
        {


        		if(arrayVivienda[i].isEmpty==0)//ISEMPTY EN CERO PARA VALIDAR QUE SI ESTE OCUPADO Y QUE HAYA ALGO
				{
        			mostrarVivienda(arrayVivienda,arrayCensista,tamArrayCensista,i);
				}



        }
       resultado=1;
    }

    return resultado;
}

int mostrarVivienda(eVivienda* arrayVivienda , eCensista* arrayCensista, int tamArrayCensista, int i)
{


   printf("\nID VIVIENDA:%d---CALLE:%s---CANTIDAD DE PERSONAS:%d---CANTIDAD DE HABITACIONES:%d---TIPO DE VIVIENDA:%s---ID CENSISTA:%d---NOMBRE DE CENSISTA:%s---EDAD:%d---TELEFONO:%d\n",      arrayVivienda[i].idVivienda,
																																															   arrayVivienda[i].calle,
																																															   arrayVivienda[i].cantidadPersonas,
																																															   arrayVivienda[i].cantidadHabitaciones,
																																															   arrayVivienda[i].tipoVivienda,
																																															   arrayCensista[i].legajoCensista,
																																															   arrayCensista[i].nombre,
																																															   arrayCensista[i].edad,
																																															   arrayCensista[i].telefono);






	return 1;
}



int modificacionViviendas(eVivienda* arrayVivienda, int tamArray, eCensista* arrayCensista, int tamArrayCensista)// LO MISMO QUE LA FUNCIO BAJA PERO EN ESTE CASO NO USAMOS EL ISEMPTY PARA ELIMINARLO
{

    int retorno=-1;
    int opcionMod;
    int i;
    int aux;
    char auxChar;
    int opc;

    mostrarViviendas(arrayVivienda,tamArray,arrayCensista,tamArrayCensista);

    utn_getInt("\nIngrese el ID  de la Vivienda que quiera modificar: ","\nIngresa un valor correcto 0-99999: ",&aux,2,99999,0);


    if(tamArray > 0 && arrayVivienda != NULL)// VALIDA SI ES MAYOR A CERO(HAY VIVIENDAS QUE RECORRER) Y NO ESTA VACIO(NULL)
    {
        for(i=0;i<tamArray;i++)
        {
            if(aux==arrayVivienda[i].idVivienda && arrayVivienda[i].isEmpty==0)//SI EL AUX Y EL ARRAY.ID TIENEN EL MISMO VALOR(INT), DEVUELVE UN TRUE(COMPARA)
            																   //SIN EL AUX LA FUNCION CUANDO INGRESES UN ID INEXISTENTE LO VA A TOMAR COMO VALIDO
            {
            	mostrarVivienda(arrayVivienda,arrayCensista,tamArrayCensista,i);
                utn_getChar("\nDesea modificar esta Vivienda(s--O--n): ","\nIngrese la opcion correcta entre(s--O--n): ",&auxChar,2);


				if(auxChar=='s')
				{


						opcionMod=modificar();
						switch(opcionMod)
						{



							case 1:
								utn_getNombre("\nIngrese el nombre de la calle: ","\nIngrese una calle correcta: ",arrayVivienda[i].calle,2,25);
								break;
							case 2:
								utn_getInt("\nIngrese la cantidad de personas: ","\nIngresa un valor correcto 0-20: ",&arrayVivienda[i].cantidadPersonas,2,20,0);
								break;
							case 3:
								utn_getInt("\nIngrese la cantidad de habitaciones: ","\nIngresa un valor correcto 0-20: ",&arrayVivienda[i].cantidadHabitaciones,2,20,0);
								break;
							case 4:
								printf("\nIngrese opcion: \n");
								printf("1.CASA\n");
								printf("2.DEPARTAMENTO\n");
								printf("3.CASILLA\n");
								printf("4.RANCHO\n");
								scanf("%d",&opc);

								switch(opc)//UN SWITCH EN EL QUE PUEDA ELEGIR
								{
								case 1:
								strcpy(arrayVivienda[i].tipoVivienda,"CASA");
								break;
								case 2:
								strcpy(arrayVivienda[i].tipoVivienda,"DEPARTAMENTO");
								break;
								case 3:
								strcpy(arrayVivienda[i].tipoVivienda,"CASILLA");
								break;
								case 4:
								strcpy(arrayVivienda[i].tipoVivienda,"RANCHO");
								break;
								}
								break;

							case 5:
								printf("SALIR\n");
								break;



						}
						retorno=1;
						break;
				}


            }
        }

    }


    return retorno;
}

int bajaVivienda(eVivienda* arrayVivienda, int tamArray, eCensista* arrayCensista, int tamArrayCensista)
{
    int aux;
    char auxChar;
    int i;
    int resultado = 0;

    mostrarViviendas(arrayVivienda,tamArray,arrayCensista,tamArrayCensista);

    utn_getInt("\nIngrese el ID de la vivienda que quiere dar de baja: ","\nIngresa un valor correcto 0-99999: ",&aux,2,99999,0);

    for(i=0;i<tamArray;i++)
    {

			if(aux==arrayVivienda[i].idVivienda && arrayVivienda[i].isEmpty==0)//SI EL AUX Y EL ARRAY.ID TIENEN EL MISMO VALOR(INT), DEVUELVE UN TRUE(COMPARA)
																			   //SIN EL AUX LA FUNCION CUANDO INGRESES UN ID INEXISTENTE LO VA A TOMAR COMO VALIDO
			{
				mostrarVivienda(arrayVivienda,arrayCensista,tamArrayCensista,i);
				utn_getChar("\nDesea elimnar esta vivienda?(s--O--n): ","\nIngrese la opcion correcta entre(s--O--n): ",&auxChar,2);

				if(auxChar=='s')
				{
					arrayVivienda[i].isEmpty=1;// SI LLEGO HASTA ACA SIGNIFICA QUE EL ESPACIO DEL DUEÑO YA ESTA VACIO ---- 1 = SI ESTA VACIO
					resultado=1;
					break;
				}
			}


    }
    return resultado;
}
int ordenamientoViviendas(eVivienda* arrayVivienda, int tamArray)
{
	eVivienda auxiliarVivienda;// ESTE AUXILIAR SE UTILIZA PARA EL BURBUJEO

	int i;
    int j;

    int retorno=0;



       if(arrayVivienda !=NULL && tamArray >= 0)
       {

    	   	   for(i=0; i<tamArray-1; i++)
    		   {

    			   for(j=i+1;j<tamArray;j++)
    			   {
    				   if((strcmp(arrayVivienda[i].calle, arrayVivienda[j].calle) > 0 && (strcmp(arrayVivienda[i].calle,arrayVivienda[j].calle) == 0 )) || (arrayVivienda[i].cantidadPersonas > arrayVivienda[j].cantidadPersonas))
    					  //STRCMP COMPARA LOS STRINGS CARACTER POR CARACTER, SI LOS STRINGS SON IGUALES, RETORNA CERO
    				   {

    					     retorno=1;//COMO LOS STRINGS NO SON IGUALES RETORNA 1

    					     //BURBUJEO
    					     auxiliarVivienda=arrayVivienda[i];
    				         arrayVivienda[i]=arrayVivienda[j];
    				         arrayVivienda[j]=auxiliarVivienda;



    				   }

    			   }



    		  }

       }



    return retorno;

}



/*int BuscarPrecioMasCaro (eProducto listaProductos[], int tam,float *precioMasCaro)
{
  int banderaMasCaro;
  eProducto productoMasCaro;
  float precioMasCaroLocal;

  banderaMasCaro = 0;

  for (int i = 0; i < tam; i++)
    {
      if (listaProductos[i].estado == CARGADO
	  && (listaProductos[i].precio > precioMasCaroLocal
	      || banderaMasCaro == 0))
	{
	  precioMasCaroLocal = listaProductos[i].precio;

	  banderaMasCaro = 1;
	}
    }

  *precioMasCaro = precioMasCaroLocal;

  return banderaMasCaro;
}*/
