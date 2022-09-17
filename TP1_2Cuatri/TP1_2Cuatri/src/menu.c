/*
 * menu.c
 *
 *  Created on: 15 sep. 2022
 *      Author: Santiago
 */

#include "menu.h"

void MenuPrincipal(float* costoHospedaje, float* costoComida, float* costoTransporte, int* contadorArqueros, int* contadorDefensores, int* contadorMediocampistas, int* contadorDelanteros)
{
	printf("\n----------------------------------------\n"
			"            Menu Principal\n"
			"1.  Ingreso de los costos de Mantenimiento\n"
			"Costo de hospedaje -> $%.2f\n"
			"Costo de comida -> $%.2f\n"
			"Costo de transporte -> $%.2f\n"
			"2.  Carga de jugadores\n"
			"Arqueros -> %d\n"
			"Defensores -> %d\n"
			"Mediocampistas -> %d\n"
			"Delanteros -> %d\n"
			"3.  Realizar todos los calculos\n"
			"4.  Informar todos los resultados\n"
			"5. Salir\n"
			"----------------------------------------\n", *costoHospedaje, *costoComida, *costoTransporte, *contadorArqueros, *contadorDefensores, *contadorMediocampistas, *contadorDelanteros);
}

int ElegirOpcion(float* costoHospedaje, float* costoComida, float* costoTransporte, int* contadorArqueros, int* contadorDefensores, int* contadorMediocampistas, int* contadorDelanteros)
{
	char opcion[50];
	int validar;
	int opcionElegida;

	MenuPrincipal(costoHospedaje, costoComida, costoTransporte, contadorArqueros, contadorDefensores, contadorMediocampistas, contadorDelanteros);

	validar = getStringNumeros("Ingrese una opción: ", opcion);
	opcionElegida = atoi(opcion);
	while(validar == 0 || (opcionElegida > 5 || opcionElegida < 1))
	{
		validar = getStringNumeros("ERROR, Ingrese una opción: ", opcion);
		opcionElegida = atoi(opcion);
	}

	return opcionElegida;
}

