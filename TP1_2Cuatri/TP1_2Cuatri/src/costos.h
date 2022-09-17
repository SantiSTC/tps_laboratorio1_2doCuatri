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

/// @brief
/// @param costoHospedaje
/// @param costoComida
/// @param costoTransporte
/// @return
int PedirCostos(float* costoHospedaje, float* costoComida, float* costoTransporte);

/// @brief
/// @param costoHospedaje
void PedirCostoHospedaje(float* costoHospedaje);

/// @brief
/// @param costoComida
void PedirCostoComida(float* costoComida);

/// @brief
/// @param costoTransporte
void PedirCostoTransporte(float* costoTransporte);

#endif /* COSTOS_H_ */
