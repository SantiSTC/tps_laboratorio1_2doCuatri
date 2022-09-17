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

/// @brief
/// @param costoHospedaje
/// @param costoComida
/// @param costoTransporte
/// @param contadorArqueros
/// @param contadorDefensores
/// @param contadorMediocampistas
/// @param contadorDelanteros
void MenuPrincipal(float* costoHospedaje, float* costoComida, float* costoTransporte, int* contadorArqueros, int* contadorDefensores, int* contadorMediocampistas, int* contadorDelanteros);

/// @brief
/// @param costoHospedaje
/// @param costoComida
/// @param costoTransporte
/// @param contadorArqueros
/// @param contadorDefensores
/// @param contadorMediocampistas
/// @param contadorDelanteros
/// @return
int ElegirOpcion(float* costoHospedaje, float* costoComida, float* costoTransporte, int* contadorArqueros, int* contadorDefensores, int* contadorMediocampistas, int* contadorDelanteros);

#endif /* MENU_H_ */
