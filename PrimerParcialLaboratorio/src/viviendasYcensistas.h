/*
 * viviendasYcensistas.h
 *
 *  Created on: 26 may. 2022
 *      Author: Leandro
 */

#ifndef VIVIENDASYCENSISTAS_H_
#define VIVIENDASYCENSISTAS_H_

typedef struct
{

	int legajoCensista;//PK(PRIMAY KEY)
    char nombre[25];
	int edad;
	int telefono;
	int isEmpty;

}eCensistaYvivienda;


#endif /* VIVIENDASYCENSISTAS_H_ */
