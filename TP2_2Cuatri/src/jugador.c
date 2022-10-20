/*
 * jugador.c
 *
 *  Created on: 18 oct. 2022
 *      Author: Santiago
 */

#include "jugador.h"

int ObtenerID()
{
	static int idAutoIncremental = 1;
	return idAutoIncremental++;
}

void PedirNombre(char* mensaje, char* nombre)
{
	char nombreAux[50];
	int validar;

	validar = getStringLetras(mensaje, nombreAux);
	while(validar == 0)
	{
		validar = getStringLetras(mensaje, nombreAux);
	}

	strcpy(nombre, nombreAux);
}

int PedirPosicion(char* mensaje)
{
	char posicionAux[50];
	int validar;

	validar = getStringNumeros(mensaje, posicionAux);
	while(validar == 0 || (posicionAux < 1 && posicionAux > 4 ))
	{
		validar = getStringNumeros(mensaje, posicionAux);
	}

	return atoi(posicionAux);
}

short PedirNumeroCamiseta(char* mensaje)
{
	int validar;
	char numeroCamisetaAux[50];

	validar = getStringNumeros(mensaje, numeroCamisetaAux);
	while(validar == 0 || (numeroCamisetaAux < 1 && numeroCamisetaAux > 99))
	{
		validar = getStringLetras(mensaje, numeroCamisetaAux);
	}

	return atoi(numeroCamisetaAux);
}

int PedirIdConfederacion(char* mensaje, eConfederacion listaConfederaciones[], int sizeConfederaciones)
{
	int validar;
	char idConfederacionAux[50];



	validar = getStringNumeros(mensaje, idConfederacionAux);
	while(validar == 0 || (idConfederacionAux < 100 && idConfederacionAux > 105))
	{
		validar = getStringLetras(mensaje, idConfederacionAux);
	}

	return atoi(idConfederacionAux);
}




