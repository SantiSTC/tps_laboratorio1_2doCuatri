/*
 * menu.h
 *
 *  Created on: 15 sep. 2022
 *      Author: Santiago
 */

#ifndef MENU_H_
#define MENU_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "costos.h"
#include "utn.h"

void MenuPrincipal(float* costoHospedaje, float* costoComida, float* costoTransporte, int* contadorArqueros, int* contadorDefensores, int* contadorMediocampistas, int* contadorDelanteros);
int ElegirOpcion(float* costoHospedaje, float* costoComida, float* costoTransporte, int* contadorArqueros, int* contadorDefensores, int* contadorMediocampistas, int* contadorDelanteros);

#endif /* MENU_H_ */
