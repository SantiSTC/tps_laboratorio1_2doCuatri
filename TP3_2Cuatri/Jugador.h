#ifndef jug_H_INCLUDED
#define jug_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "utn.h"
#include "funcionalidades.h"
#include "Seleccion.h"

#define LIBRE 0
#define OCUPADO 1

typedef struct
{
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;
}Jugador;

Jugador* jug_new();
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr);

void jug_delete(Jugador* unJugador);

int jug_setId(Jugador* this,int id);
int jug_getId(Jugador* this,int* id);

int jug_setNombreCompleto(Jugador* this,char* nombreCompleto);
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto);

int jug_setPosicion(Jugador* this,char* posicion);
int jug_getPosicion(Jugador* this,char* posicion);

int jug_setNacionalidad(Jugador* this,char* nacionalidad);
int jug_getNacionalidad(Jugador* this,char* nacionalidad);

int jug_setEdad(Jugador* this,int edad);
int jug_getEdad(Jugador* this,int* edad);

int jug_setIdSeleccion(Jugador* this, int idSeleccion);
int jug_getIdSeleccion(Jugador* this,int* idSeleccion);

/*
=================================================================================================================================================  */

Jugador* AltaJugador();
int AveriguarUltimoID(char* path, char* id);
int SumarID(char* idStr);
int GuardarID(char* path, char* id);
int PedirNombre(char* mensaje, char* nombre);
int PedirPosicion(char* mensaje, char* posicion);
int PedirEdad(char* mensaje, char* edad);
int PedirNacionalidad(char* mensaje, char* nacionalidad);
int PedirIdSeleccion(char* mensaje, int* idSeleccion);
int PediridJugador(char* mensaje, int* idJugador);
int MostrarUnJugador(Jugador* unJugador, LinkedList* pArraySelecciones);
int MostrarListaJugadores(LinkedList* pArrayJugadores, LinkedList* pArraySeleciones);
int ModificarNombre(Jugador* unJugador);
int ModificarEdad(Jugador* unJugador);
int ModificarPosicion(Jugador* unJugador);
int ModificarNacionalidad(Jugador* unJugador);
int ModificarJugador(LinkedList* pArrayJugadores, LinkedList* pArraySeleciones);
int BajaDeJugador(LinkedList* pArrayJugadores, LinkedList* pArraySeleciones);
Jugador* BuscarJugador(LinkedList* pArrayJugador, int id);

#endif // jug_H_INCLUDED
