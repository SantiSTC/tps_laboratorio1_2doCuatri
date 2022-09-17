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

/// @brief
/// @param numeroCamiseta
void PedirCamiseta(int* numeroCamiseta);

/// @brief
/// @param contadorArqueros
/// @param contadorDefensores
/// @param contadorMediocampistas
/// @param contadorDelanteros
/// @return
int PedirPosicion(int* contadorArqueros, int* contadorDefensores, int* contadorMediocampistas, int* contadorDelanteros);

/// @brief
/// @param contadorUefa
/// @param contadorConmebol
/// @param contadorConcacaf
/// @param contadorAfc
/// @param contadorOfc
/// @param contadorCaf
/// @return
int PedirConfederacion(int* contadorUefa, int* contadorConmebol, int* contadorConcacaf, int* contadorAfc, int* contadorOfc, int* contadorCaf);

/// @brief
/// @param numeroCamiseta
/// @param contadorArqueros
/// @param contadorDefensores
/// @param contadorMediocampistas
/// @param contadorDelanteros
/// @param contadorUefa
/// @param contadorConmebol
/// @param contadorConcacaf
/// @param contadorAfc
/// @param contadorOfc
/// @param contadorCaf
/// @return
int PedirJugador(int* numeroCamiseta, int* contadorArqueros, int* contadorDefensores, int* contadorMediocampistas, int* contadorDelanteros, int* contadorUefa, int* contadorConmebol, int* contadorConcacaf, int* contadorAfc, int* contadorOfc, int* contadorCaf);

#endif /* JUGADORES_H_ */
