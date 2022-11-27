#include "LinkedList.h"
#include "utn.h"
#include "Jugador.h"
#include "funcionalidades.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef selec_H_INCLUDED
#define selec_H_INCLUDED

typedef struct
{
	int id;
	char pais[30];
	char confederacion[30];
	int convocados;
}Seleccion;

Seleccion* selec_new();
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr);
void selec_delete(Seleccion* unaSeleccion);

int selec_getId(Seleccion* this,int* id);
int selec_getPais(Seleccion* this,char* pais);
int selec_getConfederacion(Seleccion* this,char* confederacion);

int selec_setConvocados(Seleccion* this,int convocados);
int selec_getConvocados(Seleccion* this,int* convocados);

//=======================================================================================================

/// @brief Muestra los datos de una seleccion.
/// @param unaSeleccion Recibe los datos de un UNA seleccion.
void MostrarUnaSeleccion(Seleccion* unaSeleccion);

/// @brief Muestra la lista de seleccciones.
/// @param pArraySelecciones Recibe la lista de selecciones.
/// @return 1 si pudo hacerlo, 0 si no pudo.
int MostrarListaSelecciones(LinkedList* pArraySelecciones);

/// @brief Inicializa el contador de convocados en 0.
/// @param pArraySelecciones Recibe la lista de selecciones.
/// @return 1 si pudo hacerlo, 0 si no pudo.
int InicializarConvocados(LinkedList* pArraySelecciones);

/// @brief Permite convocar a un jugador a la seleccion que se desee.
/// @param pArrayJugadores Recibe la lista de jugadores.
/// @param pArraySelecciones Recibe la lista de selecciones.
/// @return 1 si pudo hacerlo, 0 si no pudo.
int ConvocarJugadores(LinkedList* pArrayJugadores, LinkedList* pArraySelecciones);

/// @brief Busca una seleccion segun el ID indicado.
/// @param pArraySelecciones Recibe la lista de selecciones.
/// @param id Recibe el id de la seleccion a buscar.
/// @return Retorna un puntero a la seleccion que se buscaba.
Seleccion* BuscarSeleccion(LinkedList* pArraySelecciones, int id);

#endif // selec_H_INCLUDED
