/*
 * jugador.h
 *
 *  Created on: 18 oct. 2022
 *      Author: Santiago
 */

#ifndef JUGADOR_H_
#define JUGADOR_H_


#include "confederacion.h"
#include "inputs.h"

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

void MostrarUnJugador(eJugador unJugador);
void MostrarListaJugadores(eJugador listaJugadores[], int sizeJugadores);
void InicializarJugador(eJugador listaJugadores[], int sizeJugadores);
int ObtenerID();
void PedirNombre(char* mensaje, char* nombre);
void PedirPosicion(char* mensaje, char* posicion);
short PedirNumeroCamiseta(char* mensaje);
int PedirIdConfederacion(char* mensaje, eConfederacion listaConfederaciones[], int sizeConfederaciones);
float PedirSalario(char* mensaje);
short PedirAniosContrato(char* mensaje);
int BuscarEspacio(eJugador listaJugadores[], int sizeJugadores);
eJugador CargarJugador(eConfederacion listaConfederaciones[], int sizeConfederaciones);
int CargarListaJugadores(eJugador listaJugadores[], int sizeJugadores, eConfederacion listaConfederaciones[], int sizeConfederaciones);
int EliminarJugador(eJugador listaJugadores[], int sizeJugadores);

#endif /* JUGADOR_H_ */
