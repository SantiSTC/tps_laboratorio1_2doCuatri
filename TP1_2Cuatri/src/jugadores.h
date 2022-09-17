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

void PedirCamiseta(int* numeroCamiseta);
int PedirPosicion(int* contadorArqueros, int* contadorDefensores, int* contadorMediocampistas, int* contadorDelanteros);
int PedirConfederacion(int* contadorUefa, int* contadorConmebol, int* contadorConcacaf, int* contadorAfc, int* contadorOfc, int* contadorCaf);
int PedirJugador(int* numeroCamiseta, int* contadorArqueros, int* contadorDefensores, int* contadorMediocampistas, int* contadorDelanteros, int* contadorUefa, int* contadorConmebol, int* contadorConcacaf, int* contadorAfc, int* contadorOfc, int* contadorCaf);

#endif /* JUGADORES_H_ */
