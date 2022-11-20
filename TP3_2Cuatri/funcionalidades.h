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

int MenuPrincipal();
int ElegirOpcion(int max, int min);
int MenuListados();
int MenuConvocar();
int MenuOrdenYListado();
int MenuModificacion();
int ListarListados(LinkedList* pArrayJugadores, LinkedList* pArraySelecciones);
int MostrarJugadoresConvocados(LinkedList* pArrayJugadores, LinkedList* pArraySelecciones);
int OrdenarYListar(LinkedList* pArrayJugadores, LinkedList* pArraySelecciones);
int CompararNacionalidades(void* jug1, void* jug2);
int CompararEdades(void* jug1, void* jug2);
int CompararNombres(void* jug1, void* jug2);
int OrdenarSeleccionesPorConfederacion(LinkedList* pArraySelecciones);
int CompararConfederaciones(void* selec1, void* selec2);
int OrdenarJugadoresPorCriterio(LinkedList* pArrayJugadores, int pFunc(void* jug1, void* jug2));
int MostrarJugadoresNoConvocados(LinkedList* pArrayJugadores, LinkedList* pArraySelecciones);

#endif /* FUNCIONALIDADES_H_ */
