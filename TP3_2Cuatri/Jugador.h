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

/// @brief Permite dar de alta un jugador.
/// @return Retorna un puntero al jugador.
Jugador* AltaJugador(LinkedList* pArraySelecciones);

/// @brief Permite saber cual es el ultimo ID de los cargados a mano.
/// @param path nombre del archivo donde esta guardado el ID.
/// @param id puntero al ID a averiguar.
/// @return 1 si pudo averiguarlo, -1 si no pudo.
int AveriguarUltimoID(char* path, char* id);

/// @brief Actualiza el numero del ultimo ID.
/// @param idStr Recibe el ultimo ID como parametro.
/// @return 1 si pudo hacerlo, -1 si no pudo.
int SumarID(char* idStr);

/// @brief Guarda el ultimo de la lista.
/// @param path nombre del archivo donde esta guardado el ID.
/// @param id puntero al ID.
/// @return 1 si pudo hacerlo, -1 si no pudo.
int GuardarID(char* path, char* id);

/// @brief Pide el ingreso del nombre de un jugador.
/// @param mensaje Recibe el mensaje a mostrar a la hora de pedir el dato.
/// @param nombre Recibe un puntero a donde se guardara el nombre.
/// @return 1 si pudo hacerlo, 0 si no pudo.
int PedirNombre(char* mensaje, char* nombre);

/// @brief Pide el ingreso de la posicion de un jugador.
/// @param mensaje Recibe el mensaje a mostrar a la hora de pedir el dato.
/// @param posicion Recibe un puntero a donde se guardara la posicion.
/// @return 1 si pudo hacerlo, 0 si no pudo.
int PedirPosicion(char* mensaje, char* posicion);

/// @brief Pide el ingreso de la edad de un jugador.
/// @param mensaje Recibe el mensaje a mostrar a la hora de pedir el dato.
/// @param edad Recibe un puntero a donde se guardara el edad.
/// @return 1 si pudo hacerlo, 0 si no pudo.
int PedirEdad(char* mensaje, char* edad);

/// @brief Pide el ingreso de la nacionalidad de un jugador.
/// @param mensaje Recibe el mensaje a mostrar a la hora de pedir el dato.
/// @param nacionalidad Recibe un puntero a donde se guardara la nacionalidad.
/// @return 1 si pudo hacerlo, 0 si no pudo.
int PedirNacionalidad(char* mensaje, char* nacionalidad, LinkedList* pArraySelecciones);

/// @brief Pide el ingreso del id de Seleccion de un jugador.
/// @param mensaje Recibe el mensaje a mostrar a la hora de pedir el dato.
/// @param idSeleccion Recibe un puntero a donde se guardara el id de la seleccion.
/// @return 1 si pudo hacerlo, 0 si no pudo.
int PedirIdSeleccion(char* mensaje, int* idSeleccion);

/// @brief Pide el ingreso del id de un jugador.
/// @param mensaje Recibe el mensaje a mostrar a la hora de pedir el dato.
/// @param idJugador Recibe un puntero a donde se guardara el id del jugador.
/// @return 1 si pudo hacerlo, 0 si no pudo.
int PediridJugador(char* mensaje, int* idJugador);

/// @brief Muestra los datos de UN jugador.
/// @param unJugador Recibe los datos de UN jugador.
/// @param pArraySelecciones Recibe la lista de selecciones.
/// @return 1 si pudo hacerlo, 0 si no pudo.
int MostrarUnJugador(Jugador* unJugador, LinkedList* pArraySelecciones);

/// @brief Muestra la lista de jugadores.
/// @param pArrayJugadores Recibe la lista de jugadores.
/// @param pArraySelecciones Recibe la lista de selecciones.
/// @return 1 si pudo hacerlo, 0 si no pudo.
int MostrarListaJugadores(LinkedList* pArrayJugadores, LinkedList* pArraySeleciones);

/// @brief Permite modificar el nombre de un jugador.
/// @param unJugador Recibe los datos de UN jugador.
/// @return 1 si pudo hacerlo, 0 si no pudo.
int ModificarNombre(Jugador* unJugador);

/// @brief Permite modificar la edad de un jugador.
/// @param unJugador Recibe los datos de UN jugador.
/// @return 1 si pudo hacerlo, 0 si no pudo.
int ModificarEdad(Jugador* unJugador);

/// @brief Permite modificar la posicion de un jugador.
/// @param unJugador Recibe los datos de UN jugador.
/// @return 1 si pudo hacerlo, 0 si no pudo.
int ModificarPosicion(Jugador* unJugador);

/// @brief Permite modificar la nacionalidad de un jugador.
/// @param unJugador Recibe los datos de UN jugador.
/// @return 1 si pudo hacerlo, 0 si no pudo.
int ModificarNacionalidad(Jugador* unJugador);

/// @brief Permite modificar cualquiera de los campos de un jugador.
/// @param pArrayJugadores Recibe la lista de jugadores.
/// @param pArraySelecciones Recibe la lista de selecciones.
/// @return 1 si pudo hacerlo, 0 si no pudo.
int ModificarJugador(LinkedList* pArrayJugadores, LinkedList* pArraySeleciones);

/// @brief Elimina un jugador de la lista.
/// @param pArrayJugadores Recibe la lista de jugadores.
/// @param pArraySelecciones Recibe la lista de selecciones.
/// @return -1 si no pudo hacerlo, 0 si pudo.
int BajaDeJugador(LinkedList* pArrayJugadores, LinkedList* pArraySeleciones);

/// @brief Busca un jugador en la lista segun su ID.
/// @param pArrayJugador Recibe la lista de jugadores.
/// @param id Recibe el id del jugador a buscar.
/// @return puntero al jugador que se buscó.
Jugador* BuscarJugador(LinkedList* pArrayJugador, int id);

#endif // jug_H_INCLUDED
