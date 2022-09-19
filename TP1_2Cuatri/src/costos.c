/*
 * inputs.c
 *
 *  Created on: 15 sep. 2022
 *      Author: Santiago
 */

#include "costos.h"

int PedirCostos(float* costoHospedaje, float* costoComida, float* costoTransporte)
{
	char opcion[50];
	int validar;
	int opcionElegida;
	int retorno = 0;

	printf("Elija que costo desea ingresar\n"
			" 1. Costo de hospedaje -> $%.2f\n"
			" 2. Costo de comida -> $%.2f\n"
			" 3. Costo de transporte -> $%.2f\n", *costoHospedaje, *costoComida, *costoTransporte);

	validar = getStringNumeros("Ingrese una opción: ", opcion);
	opcionElegida = atoi(opcion);
	while(validar == 0 || (opcionElegida > 3 || opcionElegida < 1))
	{
		validar = getStringNumeros("ERROR, Ingrese una opción valida: ", opcion);
		opcionElegida = atoi(opcion);
	}

	switch(opcionElegida)
	{
		case 1:
			PedirCostoHospedaje(costoHospedaje);
			retorno = 1;
		break;
		case 2:
			PedirCostoComida(costoComida);
			retorno = 1;
		break;
		case 3:
			PedirCostoTransporte(costoTransporte);
			retorno = 1;
		break;
	}

	return retorno;
}

void PedirCostoHospedaje(float* costoHospedaje)
{
	char costoHospedajeAux[50];
	int validar;

	validar = getStringNumerosFlotantes("\nIngrese el costo de hospedaje: ", costoHospedajeAux);
	while(validar == 0)
	{
		validar = getStringNumerosFlotantes("\nIngrese el costo de hospedaje: ", costoHospedajeAux);
	}

	*costoHospedaje += atof(costoHospedajeAux);

}

void PedirCostoComida(float* costoComida)
{
	char costoComidaAux[50];
	int validar;

	validar = getStringNumerosFlotantes("\nIngrese el costo de comida: ", costoComidaAux);
	while(validar == 0)
	{
		validar = getStringNumerosFlotantes("\nIngrese el costo de comida: ", costoComidaAux);
	}

	*costoComida += atof(costoComidaAux);

}

void PedirCostoTransporte(float* costoTransporte)
{
	char costoTransporteAux[50];
	int validar;

	validar = getStringNumerosFlotantes("\nIngrese el costo de transporte: ", costoTransporteAux);
	while(validar == 0)
	{
		validar = getStringNumerosFlotantes("\nIngrese el costo de transporte: ", costoTransporteAux);
	}

	*costoTransporte += atof(costoTransporteAux);

}



