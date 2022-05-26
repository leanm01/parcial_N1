/*
 * viviendas.h
 *
 *  Created on: 20 may. 2022
 *      Author: Leandro
 */

#ifndef VIVIENDAS_H_
#define VIVIENDAS_H_

#include "censista.h"

typedef struct
{

	int idVivienda;//PK(PRIMAY KEY)
    char calle[25];
	int cantidadPersonas;
	int cantidadHabitaciones;
	char tipoVivienda[50];
	int legajoCensista;//FK(FOREIGN KEY)
	int isEmpty;

}eVivienda;

/**
 * \brief indica que todas las posiciones del array estan vacias
 * \param puntero al array de vivienda
 * \param el largo del array
 * \return (-1) Error / (0) Ok
 *
 */
int initVivienda(eVivienda* arrayVivienda, int tamArray);

/**
 * \brief alta de vivienda
 * \param puntero al array de vivienda
 * \param el largo del array
 * \param un INT para el contador autoIncremental
 * \return (-1) Error / (0) Ok
 *
 */
int agregarVivienda(eVivienda* arrayVivienda, int tamArray, int contador);

/**
 * \brief muestra todas las viviendas cargadas recorriendo el array
 * \param puntero al array de vivienda
 * \param el largo del array

 * \return (-1) Error / (0) Ok
 *
 */
int mostrarViviendas(eVivienda* arrayVivienda, int tamArray, eCensista* arrayCensista, int tamArrayCensista);

/**
 * \brief muestra solo una vivienda
 * \param puntero al array de vivienda
 * \param el largo del array

 * \return (-1) Error / (0) Ok
 *
 */
int mostrarVivienda(eVivienda* arrayVivienda , eCensista* arrayCensista, int tamArrayCensista, int i);

/**
 * \brief modifica a la vivienda
 * \param puntero al array de vivienda
 * \param el largo del array

 * \return (-1) Error / (0) Ok
 *
 */
int modificacionViviendas(eVivienda* arrayVivienda, int tamArray, eCensista* arrayCensista, int tamArrayCensista);

/**
 * \brief elimina una vivienda
 * \param puntero al array de vivienda
 * \param el largo del array

 * \return (-1) Error / (0) Ok
 *
 */
int bajaVivienda(eVivienda* arrayVivienda, int tamArray, eCensista* arrayCensista, int tamArrayCensista);

/**
 * \brief ordena las viviendas por nombre o por cantidad de personas
 * \param puntero al array de vivienda
 * \param el largo del array

 * \return (-1) Error / (0) Ok
 *
 */
int ordenamientoViviendas(eVivienda* arrayVivienda, int tamArray);


//void promedioViviendas(eVivienda* arrayVivienda, int tamArray);
#endif /* VIVIENDAS_H_ */
