/*
 * jugador.h
 *
 *  Created on: 18 oct. 2022
 *      Author: Santiago
 */

#ifndef JUGADOR_H_
#define JUGADOR_H_

#include "utn.h"
#include "menu.h"
#include "confederacion.h"


typedef struct{
	int id;
	char nombre[50];
	char posicion[50];
	short numeroCamiseta;
	int idConfederacion;
	float salario;
	short aniosContrato;
	short isEmpty;
}eJugador;

/// @brief Muestra los datos de UN jugador.
/// @param unJugador Recibe un dato de tipo eJugador con todos los datos de un jugador.
/// @param listaConfederaciones Recibe la lista de confederaciones.
/// @param sizeConfederaciones Recibe el tamaño de la lista de confederaciones.
void MostrarUnJugador(eJugador unJugador, eConfederacion listaConfederaciones[], int sizeConfederaciones);

/// @brief Muestra todos los jugadores cargados en la lista.
/// @param listaJugadores Recibe la lista de jugadores.
/// @param sizeJugadores Recibe el tamaño de la lista de jugadores.
/// @param listaConfederaciones Recibe la lista de confederaciones.
/// @param sizeConfederaciones Recibe el tamaño de la lista de confederaciones.
void MostrarListaJugadores(eJugador listaJugadores[], int sizeJugadores, eConfederacion listaConfederaciones[], int sizeConfederacione);

/// @brief Inicializa el campo isEmpty de los jugadores en LIBRE.
/// @param listaJugadores Recibe la lista de jugadores.
/// @param sizeJugadores Recibe el tamaño de la lista de jugadores.
void InicializarJugador(eJugador listaJugadores[], int sizeJugadores);

/// @brief Calcula autoincrementalmente un ID.
/// @return Retorna el ID que encontró.
int ObtenerID();

/// @brief Pide el ingreso de un nombre.
/// @param mensajeRecibe el mensaje a mostrar cuando se pida el dato.
/// @param nombre Recibe una referencia a la variable donde guardar el dato que se pide.
/// @return Retorna 1 se se pidio correctamente el dato, 0 si no pudo hacerlo.
int PedirNombre(char* mensaje, char* nombre);

/// @brief Pide el ingreso de una posicion.
/// @param mensaje Recibe el mensaje a mostrar cuando se pida el dato.
/// @param posicion Recibe una referencia a la variable donde guardar el dato que se pide.
/// @return Retorna 1 se se pidio correctamente el dato, 0 si no pudo hacerlo.
int PedirPosicion(char* mensaje, char* posicion);

/// @brief Pide el ingreso de un numero de camiseta.
/// @param mensaje Recibe el mensaje a mostrar cuando se pida el dato.
short PedirNumeroCamiseta(char* mensaje);

/// @brief Pide el ingreso de un ID de una de las confederaciones.
/// @param mensaje Recibe el mensaje a mostrar cuando se pida el dato.
/// @param listaConfederaciones Recibe la lista de confederaciones.
/// @param sizeConfederaciones Recibe el tamaño de la lista de confederaciones.
/// @return Retorna el ID de la confederacion que ingreso el usuario.
int PedirIdConfederacion(char* mensaje, eConfederacion listaConfederaciones[], int sizeConfederaciones);

/// @brief Pide el ingreso de un salario.
/// @param mensaje Recibe el mensaje a mostrar cuando se pida el dato.
/// @return Retorna el salario que ingreso el usuario.
float PedirSalario(char* mensaje);

/// @brief Pide el ingreso de los años de contrato de un jugador.
/// @param mensaje Recibe el mensaje a mostrar cuando se pida el dato.
short PedirAniosContrato(char* mensaje);

/// @brief Busca el primer lugar libre de la lista.
/// @param listaJugadores Recibe la lista de jugadores.
/// @param sizeJugadores Recibe el tamaño de la lista de jugadores.
/// @return Retorna el primer lugar libre en la lista.
int BuscarEspacio(eJugador listaJugadores[], int sizeJugadores);

/// @brief Permite cargar los datos de un jugador.
/// @param listaConfederaciones Recibe la lista de confederaciones.
/// @param sizeConfederaciones Recibe el tamaño de la lista de confederaciones.
/// @return Retorna un jugador con todos los campos cargados.
eJugador CargarJugador(eConfederacion listaConfederaciones[], int sizeConfederaciones);

/// @brief Carga un jugador a la lista.
/// @param listaJugadores Recibe la lista de jugadores.
/// @param sizeJugadores Recibe el tamaño de la lista de jugadores.
/// @param listaConfederaciones Recibe la lista de confederaciones.
/// @param sizeConfederaciones Recibe el tamaño de la lista de confederaciones.
/// @return Retorna -1 si NO pudo cargar el jugador a la lista, o el indice en el que se cargó en caso de haber podido.
int CargarListaJugadores(eJugador listaJugadores[], int sizeJugadores, eConfederacion listaConfederaciones[], int sizeConfederaciones);

/// @brief Elimina un jugador de la lista.
/// @param listaJugadores Recibe la lista de jugadores.
/// @param sizeJugadores Recibe el tamaño de la lista de jugadores.
/// @param listaConfederaciones Recibe la lista de confederaciones.
/// @param sizeConfederaciones Recibe el tamaño de la lista de confederaciones.
/// @return Retorna 1 si pudo eliminar al jugador, 0 si NO se hizo.
int EliminarJugador(eJugador listaJugadores[], int sizeJugadores, eConfederacion listaConfederaciones[], int sizeConfederaciones);

/// @brief Permite modificar los datos de un jugador.
/// @param listaJugadores Recibe la lista de jugadores.
/// @param sizeJugadores Recibe el tamaño de la lista de jugadores.
/// @param listaConfederaciones Recibe la lista de confederaciones.
/// @param sizeConfederaciones Recibe el tamaño de la lista de confederaciones.
/// @return Retorna 1 si pudo modificar al jugador, 0 si NO se hizo.
int ModificarJugador(eJugador listaJugadores[], int sizeJugadores, eConfederacion listaConfederaciones[], int sizeConfederaciones);

/// @brief Ordena los jugadores por orden alfabetico de confederacion y luego por nombre de jugador,
/// @param listaJugadores Recibe la lista de jugadores.
/// @param sizeJugadores Recibe el tamaño de la lista de jugadores.
/// @param listaConfederaciones Recibe la lista de confederaciones.
/// @param sizeConfederaciones Recibe el tamaño de la lista de confederaciones.
void OrdenarJugadoresAlfabeticamente(eJugador listaJugadores[], int sizeJugadores, eConfederacion listaConfederaciones[], int sizeConfederaciones);

/// @brief Busca la confederacion a la que pertenece un jugador y la retorna.
/// @param jugador
/// @param listaConfederaciones Recibe la lista de confederaciones.
/// @param sizeConfederaciones Recibe el tamaño de la lista de confederaciones.
/// @return Retorna la confederacion del jugador que se le ingresa por parametro.
eConfederacion BuscarConfederacion(eJugador jugador, eConfederacion listaConfederaciones[], int sizeConfederaciones);

/// @brief Muestra los jugadores de cada confederacion.
/// @param listaJugadores Recibe la lista de jugadores.
/// @param sizeJugadores Recibe el tamaño de la lista de jugadores.
/// @param listaConfederaciones Recibe la lista de confederaciones.
/// @param sizeConfederaciones Recibe el tamaño de la lista de confederaciones.
void ListarConfederacionesConSusJugadores(eJugador listaJugadores[], int sizeJugadores, eConfederacion listaConfederaciones[], int sizeConfederaciones);

/// @brief Calcula y muestra el total y el promedio de todos los salarios, ademas muestra a los jugadores que cobran mas del promedio.
/// @param listaJugadores Recibe la lista de jugadores.
/// @param sizeJugadores Recibe el tamaño de la lista de jugadores.
/// @param listaConfederaciones Recibe la lista de confederaciones.
/// @param sizeConfederaciones Recibe el tamaño de la lista de confederaciones.
void CalcularTotalYPromedioDeSalarios(eJugador listaJugadores[], int sizeJugadores, eConfederacion listaConfederaciones[], int sizeConfederaciones);

/// @brief Muestra la confederacion con mas años de contrato totales.
/// @param listaJugadores Recibe la lista de jugadores.
/// @param sizeJugadores Recibe el tamaño de la lista de jugadores.
/// @param listaConfederaciones Recibe la lista de confederaciones.
/// @param sizeConfederaciones Recibe el tamaño de la lista de confederaciones.
void InformarConfederacionConMasAniosDeContrato(eJugador listaJugadores[], int sizeJugadores, eConfederacion listaConfederaciones[], int sizeConfederaciones);

/// @brief Muestra el porcentaje de jugadores por confederacion.
/// @param listaJugadores Recibe la lista de jugadores.
/// @param sizeJugadores Recibe el tamaño de la lista de jugadores.
/// @param listaConfederaciones Recibe la lista de confederaciones.
/// @param sizeConfederaciones Recibe el tamaño de la lista de confederaciones.
void InformarProcentajeDeJugadoresPorConfederacion(eJugador listaJugadores[], int sizeJugadores, eConfederacion listaConfederaciones[], int sizeConfederaciones);

/// @brief Muestra la confederacion con mas jugadores.
/// @param listaJugadores Recibe la lista de jugadores.
/// @param sizeJugadores Recibe el tamaño de la lista de jugadores.
/// @param listaConfederaciones Recibe la lista de confederaciones.
/// @param sizeConfederaciones Recibe el tamaño de la lista de confederaciones.
void InformarRegionConMasJugadores(eJugador listaJugadores[], int sizeJugadores, eConfederacion listaConfederaciones[], int sizeConfederaciones);


#endif /* JUGADOR_H_ */
