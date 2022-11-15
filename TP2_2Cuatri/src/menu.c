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

	validar = getStringNumeros("Ingrese una opci�n: ", opcion);
	opcionElegida = atoi(opcion);
	while(validar == 0 || (opcionElegida > max || opcionElegida < min))
	{
		validar = getStringNumeros("ERROR, Ingrese una opci�n valida: ", opcion);
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
			"4. Confederacion con mayor cantidad de a�os de contrato total\n"
			"5. Porcentaje de jugadores por confederaci�n\n"
			"6. Region con mas jugadores\n"
			"====================================================================================\n");
}

int MenuDeModificacionConfederaciones()
{
	int retorno;

	printf("\n----------------------------------------\n"
			"          Modificar Confederacion\n"
			"1. Nombre\n"
			"2. Region\n"
			"3. A�o de creacion\n"
			"----------------------------------------\n");

	retorno = ElegirOpcion(3, 1);

	return retorno;
}
