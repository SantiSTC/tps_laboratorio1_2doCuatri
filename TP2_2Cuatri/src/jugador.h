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

void MostrarUnJugador(eJugador unJugador, eConfederacion listaConfederaciones[], int sizeConfederaciones);
void MostrarListaJugadores(eJugador listaJugadores[], int sizeJugadores, eConfederacion listaConfederaciones[], int sizeConfederacione);
void InicializarJugador(eJugador listaJugadores[], int sizeJugadores);
int ObtenerID();
int PedirNombre(char* mensaje, char* nombre);
int PedirPosicion(char* mensaje, char* posicion);
short PedirNumeroCamiseta(char* mensaje);
int PedirIdConfederacion(char* mensaje, eConfederacion listaConfederaciones[], int sizeConfederaciones);
float PedirSalario(char* mensaje);
short PedirAniosContrato(char* mensaje);
int BuscarEspacio(eJugador listaJugadores[], int sizeJugadores);
eJugador CargarJugador(eConfederacion listaConfederaciones[], int sizeConfederaciones);
int CargarListaJugadores(eJugador listaJugadores[], int sizeJugadores, eConfederacion listaConfederaciones[], int sizeConfederaciones);
int EliminarJugador(eJugador listaJugadores[], int sizeJugadores, eConfederacion listaConfederaciones[], int sizeConfederaciones);
int ModificarJugador(eJugador listaJugadores[], int sizeJugadores, eConfederacion listaConfederaciones[], int sizeConfederaciones);
void OrdenarJugadoresAlfabeticamente(eJugador listaJugadores[], int sizeJugadores, eConfederacion listaConfederaciones[], int sizeConfederaciones);
eConfederacion BuscarConfederacion(eJugador jugador, eConfederacion listaConfederaciones[], int sizeConfederaciones);
void ListarConfederacionesConSusJugadores(eJugador listaJugadores[], int sizeJugadores, eConfederacion listaConfederaciones[], int sizeConfederaciones);
void CalcularTotalYPromedioDeSalarios(eJugador listaJugadores[], int sizeJugadores, eConfederacion listaConfederaciones[], int sizeConfederaciones);
void InformarConfederacionConMasAniosDeContrato(eJugador listaJugadores[], int sizeJugadores, eConfederacion listaConfederaciones[], int sizeConfederaciones);
void InformarProcentajeDeJugadoresPorConfederacion(eJugador listaJugadores[], int sizeJugadores, eConfederacion listaConfederaciones[], int sizeConfederaciones);
void InformarRegionConMasJugadores(eJugador listaJugadores[], int sizeJugadores, eConfederacion listaConfederaciones[], int sizeConfederaciones);


#endif /* JUGADOR_H_ */
