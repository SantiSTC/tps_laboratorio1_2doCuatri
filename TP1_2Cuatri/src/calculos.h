/*
 * calculos.h
 *
 *  Created on: 15 sep. 2022
 *      Author: Santiago
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

#include "jugadores.h"
#include "costos.h"

void CalcularPromedioConfederaciones(int* contadorUefa, int* contadorConmebol, int* contadorConcacaf, int* contadorAfc, int* contadorOfc, int* contadorCaf, float* promedioUefa, float* promedioConmebol, float* promedioConcacaf, float* promedioAfc, float* promedioOfc, float* promedioCaf);
void CalcularCostosMantenimiento(float* costoHospedaje, float* costoComida, float* costoTransporte, float* promedioUefa, float* costoDeMantenimientoTotal, float* aumento,float* costoDeMantenimientoBruto);
void RealizarCalculos(float* costoHospedaje, float* costoComida, float* costoTransporte, int* contadorUefa, int* contadorConmebol, int* contadorConcacaf, int* contadorAfc, int* contadorOfc, int* contadorCaf, float* promedioUefa, float* promedioConmebol, float* promedioConcacaf, float* promedioAfc, float* promedioOfc, float* promedioCaf, float* costoDeMantenimientoTotal, float* aumento, float* costoDeMantenimientoBruto);
void InformarResultados(float* promedioUefa, float* promedioConmebol, float* promedioConcacaf, float* promedioAfc, float* promedioOfc, float* promedioCaf,float* costoDeMantenimientoTotal, float* aumento, float* costoDeMantenimientoBruto);
#endif /* CALCULOS_H_ */
