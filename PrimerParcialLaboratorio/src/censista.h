/*
 * censista.h
 *
 *  Created on: 22 may. 2022
 *      Author: Leandro
 */

#ifndef CENSISTA_H_
#define CENSISTA_H_

typedef struct
{

	int legajoCensista;//PK(PRIMAY KEY)
    char nombre[25];
	int edad;
	int telefono;
	int isEmpty;

}eCensista;


/**
 * \brief indica que todas las posiciones del array estan vacias
 * \param puntero al array de vivienda
 * \param el largo del array

 * \return (-1) Error / (0) Ok
 *
 */
int initCensista(eCensista* arrayCensista, int tamArrayCensista);

/**
 * \brief las posiciones del array ya estan cargadas, siendo hardcodeados
 * \param puntero al array de vivienda
 * \return (-1) Error / (0) Ok
 *
 */
void initCensistaHardocodeo(eCensista* arrayCensista);

/**
 * \brief muestra todos los censistas
 * \param puntero al array de vivienda
 * \param el largo del array

 * \return (-1) Error / (0) Ok
 *
 */
int mostrarCensistas(eCensista* arrayCensista, int tamArrayCensista);

/**
 * \brief muestra un censista
 * \param puntero al array de vivienda
 * \param el largo del array

 * \return (-1) Error / (0) Ok
 *
 */
int mostrarCensista(eCensista* arrayCensista , int i);

void promedioCensistas(eCensista* arrayCensista, int tamArrayCensista);

#endif /* CENSISTA_H_ */
