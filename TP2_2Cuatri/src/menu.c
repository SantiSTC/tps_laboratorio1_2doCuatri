/*
 * menu.c
 *
 *  Created on: 15 sep. 2022
 *      Author: Santiago
 */

#include "menu.h"

void MenuPrincipal()
{
	printf("\n----------------------------------------\n"
			"            Menu Principal\n"
			"1. Alta de jugador\n"
			"2. Baja de jugador\n"
			"3. Modificacion de jugador\n"
			"4. Informes\n"
			"5. Salir\n"
			"----------------------------------------\n");
}

int ElegirOpcion()
{
	char opcion[50];
	int validar;
	int opcionElegida;

	MenuPrincipal();

	validar = getStringNumeros("Ingrese una opción: ", opcion);
	opcionElegida = atoi(opcion);
	while(validar == 0 || (opcionElegida > 5 || opcionElegida < 1))
	{
		validar = getStringNumeros("ERROR, Ingrese una opción valida: ", opcion);
		opcionElegida = atoi(opcion);
	}

	return opcionElegida;
}

