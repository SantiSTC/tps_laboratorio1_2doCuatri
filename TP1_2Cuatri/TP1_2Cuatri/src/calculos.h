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

/// @brief
/// @param contadorUefa
/// @param contadorConmebol
/// @param contadorConcacaf
/// @param contadorAfc
/// @param contadorOfc
/// @param contadorCaf
/// @param promedioUefa
/// @param promedioConmebol
/// @param promedioConcacaf
/// @param promedioAfc
/// @param promedioOfc
/// @param promedioCaf
void CalcularPromedioConfederaciones(int* contadorUefa, int* contadorConmebol, int* contadorConcacaf, int* contadorAfc, int* contadorOfc, int* contadorCaf, float* promedioUefa, float* promedioConmebol, float* promedioConcacaf, float* promedioAfc, float* promedioOfc, float* promedioCaf);

/// @brief
/// @param costoHospedaje
/// @param costoComida
/// @param costoTransporte
/// @param promedioUefa
/// @param costoDeMantenimientoTotal
/// @param aumento
/// @param costoDeMantenimientoBruto
void CalcularCostosMantenimiento(float* costoHospedaje, float* costoComida, float* costoTransporte, float* promedioUefa, float* costoDeMantenimientoTotal, float* aumento,float* costoDeMantenimientoBruto);

/// @brief
/// @param costoHospedaje
/// @param costoComida
/// @param costoTransporte
/// @param contadorUefa
/// @param contadorConmebol
/// @param contadorConcacaf
/// @param contadorAfc
/// @param contadorOfc
/// @param contadorCaf
/// @param promedioUefa
/// @param promedioConmebol
/// @param promedioConcacaf
/// @param promedioAfc
/// @param promedioOfc
/// @param promedioCaf
/// @param costoDeMantenimientoTotal
/// @param aumento
/// @param costoDeMantenimientoBruto
void RealizarCalculos(float* costoHospedaje, float* costoComida, float* costoTransporte, int* contadorUefa, int* contadorConmebol, int* contadorConcacaf, int* contadorAfc, int* contadorOfc, int* contadorCaf, float* promedioUefa, float* promedioConmebol, float* promedioConcacaf, float* promedioAfc, float* promedioOfc, float* promedioCaf, float* costoDeMantenimientoTotal, float* aumento, float* costoDeMantenimientoBruto);

/// @brief
/// @param promedioUefa
/// @param promedioConmebol
/// @param promedioConcacaf
/// @param promedioAfc
/// @param promedioOfc
/// @param promedioCaf
/// @param costoDeMantenimientoTotal
/// @param aumento
/// @param costoDeMantenimientoBruto
void InformarResultados(float* promedioUefa, float* promedioConmebol, float* promedioConcacaf, float* promedioAfc, float* promedioOfc, float* promedioCaf,float* costoDeMantenimientoTotal, float* aumento, float* costoDeMantenimientoBruto);
#endif /* CALCULOS_H_ */
