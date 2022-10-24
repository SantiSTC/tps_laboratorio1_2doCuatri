/*
 ============================================================================
 Name        : TP2_2Cuatri.c
 Author      : Santiago Iannello
 Version     : 2
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "confederacion.h"
#include "jugador.h"
#include "menu.h"

#define T_C 6
#define T_J 100

eConfederacion listaConfederaciones[T_C] = {{100, "CONMEBOL", "SUDAMERICA", 1916},
										{101, "UEFA", "EUROPA", 1954},
										{102, "AFC", "ASIA", 1954},
										{103, "CAF", "AFRICA", 1957},
										{104, "CONCACAF", "NORTE Y CENTRO AMERICA", 1961},
										{105, "OFC", "OCEANIA", 1966}};

eJugador listaJugadores[T_J];

int main(void) {
	setbuf(stdout, NULL);

	int opcionElegida;
	int retorno;
	int cantidadAltas = 0;

	InicializarJugador(listaJugadores, T_J);

	do
	{
		opcionElegida = ElegirOpcion();

		switch(opcionElegida)
		{
			case 1:
				retorno = CargarListaJugadores(listaJugadores, T_J, listaConfederaciones, T_C);
				if(retorno != -1)
				{
					printf("\nSe ha cargado exitosamente el jugador a la lista.\n");
					cantidadAltas++;
				}
				else
				{
					printf("\nNo se ha podido cargar al jugador.\n");
				}

			break;
			case 2:
				if(cantidadAltas != 0)
				{
					retorno = EliminarJugador(listaJugadores, T_J);
					if(retorno != 0)
					{
						printf("\n\n");
						cantidadAltas--;
					}
					else
					{
						printf("\n\n");
					}
				}
				else
				{
					printf("\nERROR - Se debera cargar al menos un jugador antes de ingresar a esta opcion.\n");
				}
			break;
			case 3:

				if(cantidadAltas != 0)
				{
					//retorno = ;
					if(retorno != 0)
					{
						printf("\n\n");
					}
					else
					{
						printf("\n\n");
					}
				}
				else
				{
					printf("\nERROR - Se debera cargar al menos un jugador antes de ingresar a esta opcion.\n");
				}
			break;
			case 4:
				if(cantidadAltas != 0)
				{
					//retorno = ;
					if(retorno != 0)
					{
						printf("\n\n");
					}
					else
					{
						printf("\n\n");
					}
				}
				else
				{
					printf("\nERROR - Se debera cargar al menos un jugador antes de ingresar a esta opcion.\n");
				}
			break;
		}

	}while(opcionElegida != 5);



	return 0;
}
