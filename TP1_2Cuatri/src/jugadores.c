/*
 * jugadores.c
 *
 *  Created on: 15 sep. 2022
 *      Author: Santiago
 */

#include "jugadores.h"

void PedirCamiseta(int* numeroCamiseta)
{
	int validar;
	char numeroCamisetaStr[50];
	int numeroCamisetaAux;

	validar = getStringNumeros("Ingrese el numero de camiseta del jugador (Del 1 al 99): ", numeroCamisetaStr);
	numeroCamisetaAux = atoi(numeroCamisetaStr);
	while(validar == 0 || (numeroCamisetaAux > 99 || numeroCamisetaAux < 1))
	{
		validar = getStringNumeros("ERROR, Ingrese el numero de camiseta del jugador (Del 1 al 99): ", numeroCamisetaStr);
		numeroCamisetaAux = atoi(numeroCamisetaStr);
	}

	*numeroCamiseta = numeroCamisetaAux;
}

int PedirPosicion(int* contadorArqueros, int* contadorDefensores, int* contadorMediocampistas, int* contadorDelanteros)
{
	int validar;
	char posicionStr[50];
	int posicionAux;
	int retorno = 0;

	validar = getStringNumeros("\n"
								"1. Arquero\n"
								"2. Defensor\n"
								"3. Mediocampista\n"
								"4. Delantero\n"
								"Ingrese la posicion del jugador: ", posicionStr);
	posicionAux = atoi(posicionStr);
	while(validar == 0 || (posicionAux > 4 || posicionAux < 1))
	{
		validar = getStringNumeros("\n"
									"1. Arquero\n"
									"2. Defensor\n"
									"3. Mediocampista\n"
									"4. Delantero\n"
									"ERROR, Ingrese la posicion del jugador: ", posicionStr);
		posicionAux = atoi(posicionStr);
	}

	switch(posicionAux)
	{
		case 1:
			*contadorArqueros += 1;
			retorno = 1;
		break;
		case 2:
			*contadorDefensores += 1;
			retorno = 1;
		break;
		case 3:
			*contadorMediocampistas += 1;
			retorno = 1;
		break;
		case 4:
			*contadorDelanteros += 1;
			retorno = 1;
		break;
	}

	return retorno;
}

int PedirConfederacion(int* contadorUefa, int* contadorConmebol, int* contadorConcacaf, int* contadorAfc, int* contadorOfc, int* contadorCaf)
{
	int validar;
	char confederacionStr[50];
	int confederacionAux;
	int retorno = 0;

	validar = getStringNumeros("\n"
								"1. UEFA\n"
								"2. Conmebol\n"
								"3. Concacaf\n"
								"4. AFC\n"
								"5. OFC\n"
								"6. CAF\n"
								"Ingrese la confederacion del jugador: ", confederacionStr);
	confederacionAux = atoi(confederacionStr);
	while(validar == 0 || (confederacionAux > 6 || confederacionAux < 1))
	{
		validar = getStringNumeros("\n"
									"1. UEFA\n"
									"2. Conmebol\n"
									"3. Concacaf\n"
									"4. AFC\n"
									"5. OFC\n"
									"6. CAF\n"
									"ERROR, Ingrese la confederacion del jugador: ", confederacionStr);
		confederacionAux = atoi(confederacionStr);
	}

	switch(confederacionAux)
	{
		case 1:
			*contadorUefa += 1;
			retorno = 1;
		break;
		case 2:
			*contadorConmebol += 1;
			retorno = 1;
		break;
		case 3:
			*contadorConcacaf += 1;
			retorno = 1;
		break;
		case 4:
			*contadorAfc += 1;
			retorno = 1;
		break;
		case 5:
			*contadorOfc += 1;
			retorno = 1;
		break;
		case 6:
			*contadorCaf += 1;
			retorno = 1;
		break;
	}

	return retorno;
}

int PedirJugador(int* numeroCamiseta, int* contadorArqueros, int* contadorDefensores, int* contadorMediocampistas, int* contadorDelanteros, int* contadorUefa, int* contadorConmebol, int* contadorConcacaf, int* contadorAfc, int* contadorOfc, int* contadorCaf)
{
	int retorno = 0;
	int jugadoresTotales;

	jugadoresTotales = *contadorArqueros + *contadorDefensores + *contadorMediocampistas + *contadorDelanteros;

	if(jugadoresTotales < 22)
	{
		PedirCamiseta(numeroCamiseta);
		if(PedirPosicion(contadorArqueros, contadorDefensores, contadorMediocampistas, contadorDelanteros) && PedirConfederacion(contadorUefa, contadorConmebol, contadorConcacaf, contadorAfc, contadorOfc, contadorCaf))
		{
			retorno = 1;
		}
	}
	else
	{
		printf("\nSe ha alcanzado el maximo de 22 jugadores.\n");
	}

	return retorno;
}

