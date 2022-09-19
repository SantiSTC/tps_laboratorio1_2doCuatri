/*
 * calculos.c
 *
 *  Created on: 15 sep. 2022
 *      Author: Santiago
 */

#include "calculos.h"

void CalcularPromedioConfederaciones(int* contadorUefa, int* contadorConmebol, int* contadorConcacaf, int* contadorAfc, int* contadorOfc, int* contadorCaf, float* promedioUefa, float* promedioConmebol, float* promedioConcacaf, float* promedioAfc, float* promedioOfc, float* promedioCaf)
{
	float contadorJugadoresTotales;

	contadorJugadoresTotales = *contadorUefa + *contadorConmebol + *contadorConcacaf + *contadorAfc + *contadorOfc + *contadorCaf;

	*promedioUefa = (*contadorUefa / contadorJugadoresTotales)*100;
	*promedioConmebol = (*contadorConmebol / contadorJugadoresTotales)*100;
	*promedioConcacaf = (*contadorConcacaf / contadorJugadoresTotales)*100;
	*promedioAfc = (*contadorAfc / contadorJugadoresTotales)*100;
	*promedioOfc = (*contadorOfc / contadorJugadoresTotales)*100;
	*promedioCaf = (*contadorCaf / contadorJugadoresTotales)*100;
}

void CalcularCostosMantenimiento(float* costoHospedaje, float* costoComida, float* costoTransporte, float* promedioUefa, float* costoDeMantenimientoTotal, float* aumento, float* costoDeMantenimientoBruto, float* promedioConmebol, float* promedioConcacaf, float* promedioAfc, float* promedioOfc, float* promedioCaf)
{
	*costoDeMantenimientoBruto = *costoHospedaje + *costoComida + *costoTransporte;

	if(*promedioUefa > *promedioConmebol && *promedioUefa > *promedioConcacaf && *promedioUefa > *promedioAfc && *promedioUefa > *promedioOfc && *promedioUefa > *promedioCaf)
	{
		*aumento = (*costoDeMantenimientoBruto/ 100) * 35;
		*costoDeMantenimientoTotal = *costoDeMantenimientoBruto + *aumento;
	}
}

void RealizarCalculos(float* costoHospedaje, float* costoComida, float* costoTransporte, int* contadorUefa, int* contadorConmebol, int* contadorConcacaf, int* contadorAfc, int* contadorOfc, int* contadorCaf, float* promedioUefa, float* promedioConmebol, float* promedioConcacaf, float* promedioAfc, float* promedioOfc, float* promedioCaf, float* costoDeMantenimientoTotal, float* aumento, float* costoDeMantenimientoBruto)
{
	CalcularPromedioConfederaciones(contadorUefa, contadorConmebol, contadorConcacaf, contadorAfc, contadorOfc, contadorCaf, promedioUefa, promedioConmebol, promedioConcacaf, promedioAfc, promedioOfc, promedioCaf);
	CalcularCostosMantenimiento(costoHospedaje, costoComida, costoTransporte, promedioUefa, costoDeMantenimientoTotal, aumento, costoDeMantenimientoBruto, promedioConmebol, promedioConcacaf, promedioAfc, promedioOfc, promedioCaf);
}
void InformarResultados(float* promedioUefa, float* promedioConmebol, float* promedioConcacaf, float* promedioAfc, float* promedioOfc, float* promedioCaf,float* costoDeMantenimientoTotal, float* aumento,float* costoDeMantenimientoBruto)
{
	printf("\n      Informar todos los resultados\n\n"
			"Porcentaje Uefa %.2f\n"
			"Porcentaje Conmebol %.2f\n"
			"Porcentaje Concacaf %.2f\n"
			"Porcentaje Afc %.2f\n"
			"Porcentaje Ofc %.2f\n"
			"Porcentaje Caf %.2f\n", *promedioUefa, *promedioConmebol, *promedioConcacaf, *promedioAfc, *promedioOfc, *promedioCaf);

	printf("El costo de mantenimiento es de $%.2f", *costoDeMantenimientoBruto);

	if(*promedioUefa > *promedioConmebol && *promedioUefa > *promedioConcacaf && *promedioUefa > *promedioAfc && *promedioUefa > *promedioOfc && *promedioUefa > *promedioCaf)
	{
		printf(", recibio un aumento de $%.2f, y ahora es de $%.2f", *aumento, *costoDeMantenimientoTotal);
	}

}









