/*
 * inputs.h
 *
 *  Created on: 15 sep. 2022
 *      Author: Santiago
 */

#ifndef COSTOS_H_
#define COSTOS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

/// @brief Pide todos los costos de mantenimiento.
/// @param costoHospedaje		Recibe un puntero a costo de hospedaje.
/// @param costoComida		Recibe un puntero a costo de comida.
/// @param costoTransporte		Recibe un puntero a costo de transporte.
/// @return Retorna 1 si el costo se ingreso correctamente, 0 si no pudo hacerse
int PedirCostos(float* costoHospedaje, float* costoComida, float* costoTransporte);

/// @brief Permite al usuario ingresar el costo de hospedaje.
/// @param costoHospedaje		Recibe un puntero a costo de hospedaje.
void PedirCostoHospedaje(float* costoHospedaje);

/// @brief Permite al usuario ingresar el costo de comida.
/// @param costoComida		Recibe un puntero a costo de comida.
void PedirCostoComida(float* costoComida);

/// @brief Permite al usuario ingresar el costo de transporte.
/// @param costoTransporte		Recibe un puntero a costo de transporte.
void PedirCostoTransporte(float* costoTransporte);

#endif /* COSTOS_H_ */
