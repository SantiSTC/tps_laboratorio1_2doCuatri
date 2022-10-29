/*
 * confederacion.h
 *
 *  Created on: 18 oct. 2022
 *      Author: Santiago
 */

#ifndef CONFEDERACION_H_
#define CONFEDERACION_H_

#include "utn.h"

typedef struct{
	int id;
	char nombre[50];
	char region[50];
	int anioCreacion;
}eConfederacion;

void MostrarUnaConfederacion(eConfederacion unaConfederacion);
void MostrarConfederaciones(eConfederacion listaConfederaciones[], int sizeConfederaciones);

#endif /* CONFEDERACION_H_ */
