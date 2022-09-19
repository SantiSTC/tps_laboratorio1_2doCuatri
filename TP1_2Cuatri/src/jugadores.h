/*
 * jugadores.h
 *
 *  Created on: 15 sep. 2022
 *      Author: Santiago
 */

#ifndef JUGADORES_H_
#define JUGADORES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

/// @brief Permite al usuario ingresar el numero de camiseta del jugador.
/// @param numeroCamiseta		Recibe un puntero al numero de camiseta del jugador
void PedirCamiseta(int* numeroCamiseta);

/// @brief Permite al usuario ingresar la posicion del jugador.
/// @param contadorArqueros		Recibe un puntero al contador arqueros
/// @param contadorDefensores		Recibe un puntero al contador defensores
/// @param contadorMediocampistas		Recibe un puntero al contador mediocampistas
/// @param contadorDelanteros		Recibe un puntero al contador delanteros
/// @return Retorna: 1 si se sumó correctamente el jugador al contador de posiciones o 0 si no pudo hacerse.
int PedirPosicion(int* contadorArqueros, int* contadorDefensores, int* contadorMediocampistas, int* contadorDelanteros);

/// @brief Permite al usuario ingresar la confederacion del jugador.
/// @param contadorUefa		Recibe un puntero al contador de jugadores en UEFA
/// @param contadorConmebol		Recibe un puntero al contador de jugadores en CONMEBOL
/// @param contadorConcacaf		Recibe un puntero al contador de jugadores en CONCACAF
/// @param contadorAfc		Recibe un puntero al contador de jugadores en AFC
/// @param contadorOfc		Recibe un puntero al contador de jugadores en OFC
/// @param contadorCaf		Recibe un puntero al contador de jugadores en CAF
/// @return Retorna: 1 si se sumó correctamente el jugador al contador de confederaciones o 0 si no pudo hacerse.
int PedirConfederacion(int* contadorUefa, int* contadorConmebol, int* contadorConcacaf, int* contadorAfc, int* contadorOfc, int* contadorCaf);

/// @brief Pide camiseta, posicion y confederacion de un jugador.
/// @param numeroCamiseta		Recibe un puntero al numero de camiseta del jugador
/// @param contadorArqueros		Recibe un puntero al contador arqueros
/// @param contadorDefensores		Recibe un puntero al contador defensores
/// @param contadorMediocampistas		Recibe un puntero al contador mediocampistas
/// @param contadorDelanteros		Recibe un puntero al contador delanteros
/// @param contadorUefa		Recibe un puntero al contador de jugadores en UEFA
/// @param contadorConmebol		Recibe un puntero al contador de jugadores en CONMEBOL
/// @param contadorConcacaf		Recibe un puntero al contador de jugadores en CONCACAF
/// @param contadorAfc		Recibe un puntero al contador de jugadores en AFC
/// @param contadorOfc		Recibe un puntero al contador de jugadores en OFC
/// @param contadorCaf		Recibe un puntero al contador de jugadores en CAF
/// @return Retorna: 1 si se pidió correctamente al jugador o 0 si no pudo hacerse.
int PedirJugador(int* numeroCamiseta, int* contadorArqueros, int* contadorDefensores, int* contadorMediocampistas, int* contadorDelanteros, int* contadorUefa, int* contadorConmebol, int* contadorConcacaf, int* contadorAfc, int* contadorOfc, int* contadorCaf);

#endif /* JUGADORES_H_ */
