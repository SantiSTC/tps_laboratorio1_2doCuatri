/*
 * confederacion.h
 *
 *  Created on: 18 oct. 2022
 *      Author: Santiago
 */

#ifndef CONFEDERACION_H_
#define CONFEDERACION_H_

#include "utn.h"
#include "menu.h"

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
/// @param sizeConfederaciones Recibe el tamaño de la lista de confederaciones.
void MostrarConfederaciones(eConfederacion listaConfederaciones[], int sizeConfederaciones);

/// @brief Permite cargar los datos de una confederacion.
/// @return Retorna una confederacion con todos los campos cargados.
eConfederacion CargarConfederacion();

/// @brief Carga una confederacion a la lista.
/// @param listaConfederaciones Recibe la lista de confederaciones.
/// @param sizeConfederaciones Recibe el tamaño de la lista de confederaciones.
/// @return Retorna -1 si NO pudo cargar la confederacion a la lista, o el indice en el que se cargó en caso de haber podido.
int CargarListaConfederaciones(eConfederacion listaConfederaciones[], int sizeConfederaciones);

/// @brief Elimina una confederacion de la lista.
/// @param listaConfederaciones Recibe la lista de confederaciones.
/// @param sizeConfederaciones Recibe el tamaño de la lista de confederaciones.
/// @return Retorna 0 si NO pudo eliminar la confederacion de la lista, o 1 en caso de haber podido.
int EliminarConfederacion(eConfederacion listaConfederaciones[], int sizeConfederaciones);

/// @brief Modifica cualquiera de los campos de una confederacion.
/// @param listaConfederaciones Recibe la lista de confederaciones.
/// @param sizeConfederaciones Recibe el tamaño de la lista de confederaciones.
/// @return Retorna 0 si NO pudo modificar a la confederacion, o 1 en caso de haber podido.
int ModificarConfederacion(eConfederacion listaConfederaciones[], int sizeConfederaciones);

/// @brief Pide un ID al usuario y lo retorna.
/// @param mensaje Recibe el mensaje a mostrar cuando se pida el dato.
/// @return Retorna el ID ingresado por el usuario.
int PedirId(char* mensaje);

/// @brief Pide una region al usuario.
/// @param mensaje Recibe el mensaje a mostrar cuando se pida el dato.
/// @param region
/// @return Retorna 1 si pudo pedir la region, 0 si no se pudo.
int PedirRegion(char* mensaje, char* region);

/// @brief Pide el año de creacion de una confederacion y lo retorna.
/// @param mensaje Recibe el mensaje a mostrar cuando se pida el dato.
/// @return Retorna el año ingresado por el usuario.
int PedirAnioCreacion(char* mensaje);

/// @brief Pide el nombre de una confederacion al usuario.
/// @param mensaje Recibe el mensaje a mostrar cuando se pida el dato.
/// @param nombre
/// @return Retorna 1 si pudo pedir la region, 0 si no se pudo.
int PedirNombreConfederacion(char* mensaje, char* nombre);

/// @brief Pide un ID de la lista de confederaciones.
/// @param mensaje Recibe el mensaje a mostrar cuando se pida el dato.
/// @param listaConfederaciones Recibe la lista de confederaciones.
/// @param sizeConfederaciones Recibe el tamaño de la lista de confederaciones.
/// @return Retorna el ID ingresado por el usuario.
int PedirIdMostrandoLista(char* mensaje, eConfederacion listaConfederaciones[], int sizeConfederaciones);

/// @brief Busca el primer lugar libre de la lista de confederaciones.
/// @param listaConfederaciones Recibe la lista de confederaciones.
/// @param sizeConfederaciones Recibe el tamaño de la lista de confederaciones.
/// @return Retorna el primer lugar libre en la lista.
int BuscarEspacioConfederaciones(eConfederacion listaConfederaciones[], int sizeJugadores);

#endif /* CONFEDERACION_H_ */
