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

/// @brief Muestra el menu principal
/// @param costoHospedaje		Recibe un puntero a costo de hospedaje
/// @param costoComida		Recibe un puntero a costo de comida
/// @param costoTransporte		Recibe un puntero a costo de transporte
/// @param contadorArqueros		Recibe un puntero al contador arqueros
/// @param contadorDefensores		Recibe un puntero al contador defensores
/// @param contadorMediocampistas		Recibe un puntero al contador mediocampistas
/// @param contadorDelanteros		Recibe un puntero al contador delanteros
void MenuPrincipal(float* costoHospedaje, float* costoComida, float* costoTransporte, int* contadorArqueros, int* contadorDefensores, int* contadorMediocampistas, int* contadorDelanteros);

/// @brief Permite elegir una opcion del menu principal
/// @param costoHospedaje		Recibe un puntero a costo de hospedaje
/// @param costoComida		Recibe un puntero a costo de comida
/// @param costoTransporte		Recibe un puntero a costo de transporte
/// @param contadorArqueros		Recibe un puntero al contador arqueros
/// @param contadorDefensores		Recibe un puntero al contador defensores
/// @param contadorMediocampistas		Recibe un puntero al contador mediocampistas
/// @param contadorDelanteros		Recibe un puntero al contador delanteros
/// @return Retorna el numero elegido por el usuario.
int ElegirOpcion(float* costoHospedaje, float* costoComida, float* costoTransporte, int* contadorArqueros, int* contadorDefensores, int* contadorMediocampistas, int* contadorDelanteros);

#endif /* MENU_H_ */
