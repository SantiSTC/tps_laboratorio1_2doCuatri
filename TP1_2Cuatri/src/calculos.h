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

/// @brief Calcula el porcentaje de jugadores que juega en cada confederacion
/// @param contadorUefa		Recibe un puntero al contador de jugadores en UEFA
/// @param contadorConmebol		Recibe un puntero al contador de jugadores en CONMEBOL
/// @param contadorConcacaf		Recibe un puntero al contador de jugadores en CONCACAF
/// @param contadorAfc		Recibe un puntero al contador de jugadores en AFC
/// @param contadorOfc		Recibe un puntero al contador de jugadores en OFC
/// @param contadorCaf		Recibe un puntero al contador de jugadores en CAF
/// @param promedioUefa		Recibe un puntero al promedio de jugadores que juegan en UEFA sobre el total
/// @param promedioConmebol		Recibe un puntero al promedio de jugadores que juegan en CONMEBOL sobre el total
/// @param promedioConcacaf 	Recibe un puntero al promedio de jugadores que juegan en CONCACAF sobre el total
/// @param promedioAfc		Recibe un puntero al promedio de jugadores que juegan en AFC sobre el total
/// @param promedioOfc		Recibe un puntero al promedio de jugadores que juegan en OFC sobre el total
/// @param promedioCaf		Recibe un puntero al promedio de jugadores que juegan en CAF sobre el total
void CalcularPromedioConfederaciones(int* contadorUefa, int* contadorConmebol, int* contadorConcacaf, int* contadorAfc, int* contadorOfc, int* contadorCaf, float* promedioUefa, float* promedioConmebol, float* promedioConcacaf, float* promedioAfc, float* promedioOfc, float* promedioCaf);

/// @brief Calcula el gasto de mantenimiento total
/// @param costoHospedaje		Recibe un puntero a costo de hospedaje
/// @param costoComida		Recibe un puntero a costo de comida
/// @param costoTransporte		Recibe un puntero a costo de transporte
/// @param promedioUefa		Recibe un puntero al promedio de jugadores que juegan en UEFA sobre el total
/// @param costoDeMantenimientoTotal 	Recibe un puntero al costo de mantenimiento con el aumento aplicado
/// @param aumento		Recibe un puntero al aumento que se aplica al costo de mantenimiento bruto
/// @param costoDeMantenimientoBruto		Recibe un puntero al costo de mantenimiento en bruto
void CalcularCostosMantenimiento(float* costoHospedaje, float* costoComida, float* costoTransporte, float* promedioUefa, float* costoDeMantenimientoTotal, float* aumento,float* costoDeMantenimientoBruto);

/// @brief Realiza los calculos de gasto de mantenimiento y el porcentaje de jugadores por confederacion
/// @param costoHospedaje		Recibe un puntero a costo de hospedaje
/// @param costoComida		Recibe un puntero a costo de comida
/// @param costoTransporte		Recibe un puntero a costo de transporte
/// @param contadorUefa		Recibe un puntero al contador de jugadores en UEFA
/// @param contadorConmebol		Recibe un puntero al contador de jugadores en CONMEBOL
/// @param contadorConcacaf		Recibe un puntero al contador de jugadores en CONCACAF
/// @param contadorAfc		Recibe un puntero al contador de jugadores en AFC
/// @param contadorOfc		Recibe un puntero al contador de jugadores en OFC
/// @param contadorCaf		Recibe un puntero al contador de jugadores en CAF
/// @param promedioUefa		Recibe un puntero al promedio de jugadores que juegan en UEFA sobre el total
/// @param promedioConmebol		Recibe un puntero al promedio de jugadores que juegan en CONMEBOL sobre el total
/// @param promedioConcacaf 	Recibe un puntero al promedio de jugadores que juegan en CONCACAF sobre el total
/// @param promedioAfc		Recibe un puntero al promedio de jugadores que juegan en AFC sobre el total
/// @param promedioOfc		Recibe un puntero al promedio de jugadores que juegan en OFC sobre el total
/// @param promedioCaf		Recibe un puntero al promedio de jugadores que juegan en CAF sobre el total
/// @param costoDeMantenimientoTotal 	Recibe un puntero al costo de mantenimiento con el aumento aplicado
/// @param aumento		Recibe un puntero al aumento que se aplica al costo de mantenimiento bruto
/// @param costoDeMantenimientoBruto		Recibe un puntero al costo de mantenimiento en bruto
void RealizarCalculos(float* costoHospedaje, float* costoComida, float* costoTransporte, int* contadorUefa, int* contadorConmebol, int* contadorConcacaf, int* contadorAfc, int* contadorOfc, int* contadorCaf, float* promedioUefa, float* promedioConmebol, float* promedioConcacaf, float* promedioAfc, float* promedioOfc, float* promedioCaf, float* costoDeMantenimientoTotal, float* aumento, float* costoDeMantenimientoBruto);

/// @brief Muestra los resultados que calculó la funcion "RealizarCalculos"
/// @param promedioUefa		Recibe un puntero al promedio de jugadores que juegan en UEFA sobre el total
/// @param promedioConmebol		Recibe un puntero al promedio de jugadores que juegan en CONMEBOL sobre el total
/// @param promedioConcacaf 	Recibe un puntero al promedio de jugadores que juegan en CONCACAF sobre el total
/// @param promedioAfc		Recibe un puntero al promedio de jugadores que juegan en AFC sobre el total
/// @param promedioOfc		Recibe un puntero al promedio de jugadores que juegan en OFC sobre el total
/// @param promedioCaf		Recibe un puntero al promedio de jugadores que juegan en CAF sobre el total
/// @param costoDeMantenimientoTotal 	Recibe un puntero al costo de mantenimiento con el aumento aplicado
/// @param aumento		Recibe un puntero al aumento que se aplica al costo de mantenimiento bruto
/// @param costoDeMantenimientoBruto		Recibe un puntero al costo de mantenimiento en bruto
void InformarResultados(float* promedioUefa, float* promedioConmebol, float* promedioConcacaf, float* promedioAfc, float* promedioOfc, float* promedioCaf,float* costoDeMantenimientoTotal, float* aumento, float* costoDeMantenimientoBruto);
#endif /* CALCULOS_H_ */
