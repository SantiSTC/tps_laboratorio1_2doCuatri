/*
 * funcionalidades.h
 *
 *  Created on: 1 nov. 2022
 *      Author: Santiago
 */

#ifndef FUNCIONALIDADES_H_
#define FUNCIONALIDADES_H_

#include "LinkedList.h"
#include "Jugador.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "LinkedList.h"
#include "Seleccion.h"

/// @brief Muestra el menu principal y pide el ingreso de una opcion.
/// @return Retorna la opcion elegida por el usuario.
int MenuPrincipal();

/// @brief Pide una opcion de un menu.
/// @param max opcion maxima a elegir.
/// @param min opcion minima a elegir.
/// @return Retorna la opcion elegida por el usuario.
int ElegirOpcion(int max, int min);

/// @brief Muestra el menu de listados (opcion 5) y pide el ingreso de una opcion.
/// @return Retorna la opcion elegida por el usuario.
int MenuListados();

/// @brief Muestra el menu de convocaiones (opcion 6) y pide el ingreso de una opcion.
/// @return Retorna la opcion elegida por el usuario.
int MenuConvocar();

/// @brief Muestra el menu de ordenamientos (opcion 7) y pide el ingreso de una opcion.
/// @return Retorna la opcion elegida por el usuario.
int MenuOrdenYListado();

/// @brief Muestra el menu de modificacion (opcion 3) y pide el ingreso de una opcion.
/// @return Retorna la opcion elegida por el usuario.
int MenuModificacion();

/// @brief Muestra varias listas.
/// @param pArrayJugadores Recibe la lista de jugadores.
/// @param pArraySelecciones Recibe la lista de selecciones.
/// @return Retorna 1 si pudo hacerlo, 0 si no pudo.
int ListarListados(LinkedList* pArrayJugadores, LinkedList* pArraySelecciones);

/// @brief Muestras los jugadores conocados a a alguna seleccion.
/// @param pArrayJugadores Recibe la lista de jugadores.
/// @param pArraySelecciones Recibe la lista de selecciones.
/// @return Retorna 1 si pudo hacerlo, 0 si no pudo.
int MostrarJugadoresConvocados(LinkedList* pArrayJugadores, LinkedList* pArraySelecciones);

/// @brief Ordena y muestra las listas segun varios criterios.
/// @param pArrayJugadores Recibe la lista de jugadores.
/// @param pArraySelecciones Recibe la lista de selecciones.
/// @return Retorna 1 si pudo hacerlo, 0 si no pudo.
int OrdenarYListar(LinkedList* pArrayJugadores, LinkedList* pArraySelecciones);

/// @brief Compara nacionalidades de jugadores.
/// @param jug1 Recibe un puntero al primer jugador de al comparacion.
/// @param jug2 Recibe un puntero al segundo jugador de al comparacion.
/// @return Retorna 1 el primer elemento es mayor al segundo, -1 si es menor, 0 si son iguales.
int CompararNacionalidades(void* jug1, void* jug2);

/// @brief Compara edades de jugadores.
/// @param jug1 Recibe un puntero al primer jugador de al comparacion.
/// @param jug2 Recibe un puntero al segundo jugador de al comparacion.
/// @return Retorna 1 el primer elemento es mayor al segundo, -1 si es menor, 0 si son iguales.
int CompararEdades(void* jug1, void* jug2);

/// @brief Compara nombres de jugadores.
/// @param jug1 Recibe un puntero al primer jugador de al comparacion.
/// @param jug2 Recibe un puntero al segundo jugador de al comparacion.
/// @return Retorna 1 el primer elemento es mayor al segundo, -1 si es menor, 0 si son iguales.
int CompararNombres(void* jug1, void* jug2);

/// @brief Ordena las seleccion alfabeticamente segun la confederacion.
/// @param pArraySelecciones Recibe la lista de selecciones.
/// @return Retorna 0 si pudo hacerlo, -1 si no pudo.
int OrdenarSeleccionesPorConfederacion(LinkedList* pArraySelecciones);

/// @brief Compara confederacion de selecciones.
/// @param selec1 Recibe un puntero a la primer seleccion de la comparacion.
/// @param selec2 Recibe un puntero a la segunda seleccion de la comparacion.
/// @return Retorna 1 el primer elemento es mayor al segundo, -1 si es menor, 0 si son iguales.
int CompararConfederaciones(void* selec1, void* selec2);

/// @brief Ordena los jugadores segun el criterio de la funcion pasada por parametro.
/// @param pArrayJugadores Recibe la lista de jugadores.
/// @param pFunc Recibe un puntero a funcion para hacer la comparacion.
/// @return Retorna 0 si pudo hacerlo, -1 si no pudo.
int OrdenarJugadoresPorCriterio(LinkedList* pArrayJugadores, int pFunc(void* jug1, void* jug2));

/// @brief Muestra los jugadores que no estan convocados a ninguna confederacion.
/// @param pArrayJugadores Recibe la lista de jugadores.
/// @param pArraySelecciones Recibe la lista de selecciones.
/// @return Retorna 1 si pudo hacerlo, 0 si no pudo.
int MostrarJugadoresNoConvocados(LinkedList* pArrayJugadores, LinkedList* pArraySelecciones);

#endif /* FUNCIONALIDADES_H_ */
