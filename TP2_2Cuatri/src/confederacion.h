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

/// @brief Muestra los datos de una confederacion.
/// @param unaConfederacion Recibe la confederacion a mostrar.
void MostrarUnaConfederacion(eConfederacion unaConfederacion);

/// @brief Muesta todas las confederaciones de la lista.
/// @param listaConfederaciones Recibe la lista de confederaciones.
/// @param sizeConfederaciones Recibe el tamaño de la lista de confederaciones.
void MostrarConfederaciones(eConfederacion listaConfederaciones[], int sizeConfederaciones);

#endif /* CONFEDERACION_H_ */
