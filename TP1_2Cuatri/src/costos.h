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

int PedirCostos(float* costoHospedaje, float* costoComida, float* costoTransporte);
void PedirCostoHospedaje(float* costoHospedaje);
void PedirCostoComida(float* costoComida);
void PedirCostoTransporte(float* costoTransporte);

#endif /* COSTOS_H_ */
