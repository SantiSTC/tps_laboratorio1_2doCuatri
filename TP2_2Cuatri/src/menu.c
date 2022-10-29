/*
 * menu.c
 *
 *  Created on: 15 sep. 2022
 *      Author: Santiago
 */

#include "menu.h"

void MenuPrincipal()
{
	printf("\n========================================\n"
			"            Menu Principal\n"
			"1. Alta de jugador\n"
			"2. Baja de jugador\n"
			"3. Modificacion de jugador\n"
			"4. Informes\n"
			"5. Salir\n"
			"========================================\n");
}

int ElegirOpcion(int max, int min)
{
	char opcion[50];
	int validar;
	int opcionElegida;

	validar = getStringNumeros("Ingrese una opción: ", opcion);
	opcionElegida = atoi(opcion);
	while(validar == 0 || (opcionElegida > max || opcionElegida < min))
	{
		validar = getStringNumeros("ERROR, Ingrese una opción valida: ", opcion);
		opcionElegida = atoi(opcion);
	}

	return opcionElegida;
}

void MenuInformes()
{
	printf("\n====================================================================================\n"
			"                                  Menu Informes\n\n"
			"1. Listado jugadores ordenados alfabaticamente\n"
			"2. Listado de confederaciones con sus jugadores\n"
			"3. Total y promedio de todos los salarios | Jugadores que cobran mas del promedio\n"
			"4. Confederacion con mayor cantidad de años de contrato total\n"
			"5. Porcentaje de jugadores por confederación\n"
			"6. Region con mas jugadores\n"
			"====================================================================================\n");
}
