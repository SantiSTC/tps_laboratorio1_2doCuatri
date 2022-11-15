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
	int isEmpty;
}eConfederacion;

/// @brief Muestra los datos de una confederacion.
/// @param unaConfederacion Recibe la confederacion a mostrar.
void MostrarUnaConfederacion(eConfederacion unaConfederacion);

/// @brief Muesta todas las confederaciones de la lista.
/// @param listaConfederaciones Recibe la lista de confederaciones.
/// @param sizeConfederaciones Recibe el tama�o de la lista de confederaciones.
void MostrarConfederaciones(eConfederacion listaConfederaciones[], int sizeConfederaciones);

int EliminarConfederacion(eConfederacion listaConfederaciones[], int sizeConfederaciones);
int ModificarConfederacion(eConfederacion listaConfederaciones[], int sizeConfederaciones);
int PedirId(char* mensaje);
int PedirRegion(char* mensaje, char* region);
int PedirAnioCreacion(char* mensaje);
int MenuDeModificacionConfederaciones();

#endif /* CONFEDERACION_H_ */
