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
#define T_J 3000

int main(void) {
	setbuf(stdout, NULL);

	int opcionElegida;
	int opcionInformes;
	int retorno;
	int cantidadAltas = 0;

	eConfederacion listaConfederaciones[T_C] = {{100, "CONMEBOL", "SUDAMERICA", 1916, OCUPADO},
											{101, "UEFA", "EUROPA", 1954, OCUPADO},
											{102, "AFC", "ASIA", 1954, OCUPADO},
											{103, "CAF", "AFRICA", 1957, OCUPADO},
											{104, "CONCACAF", "NORTE Y CENTRO AMERICA", 1961, OCUPADO},
											{105, "OFC", "OCEANIA", 1966, OCUPADO}};

	eJugador listaJugadores[T_J];

	InicializarJugador(listaJugadores, T_J);

	do
	{
		MenuPrincipal();
		opcionElegida = ElegirOpcion(5,1);

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
					retorno = EliminarJugador(listaJugadores, T_J, listaConfederaciones, T_C);
					if(retorno != 0)
					{
						printf("\nSe ha eliminado exitosamente el jugador a la lista.\n");
						cantidadAltas--;
					}
					else
					{
						printf("\nNo se ha podido eliminar al jugador.\n");
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
					retorno = ModificarJugador(listaJugadores, T_J, listaConfederaciones, T_C);
					if(retorno != 0)
					{
						printf("\nSe ha modificado exitosamente el jugador a la lista.\n");
					}
					else
					{
						printf("\nNo se ha podido modificar al jugador.\n");
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
					MenuInformes();
					opcionInformes = ElegirOpcion(6, 1);

					switch(opcionInformes)
					{
						case 1:
							OrdenarJugadoresAlfabeticamente(listaJugadores, T_J, listaConfederaciones, T_C);
						break;
						case 2:
							ListarConfederacionesConSusJugadores(listaJugadores, T_J, listaConfederaciones, T_C);
						break;
						case 3:
							CalcularTotalYPromedioDeSalarios(listaJugadores, T_J, listaConfederaciones, T_C);
						break;
						case 4:
							InformarConfederacionConMasAniosDeContrato(listaJugadores, T_J, listaConfederaciones, T_C);
						break;
						case 5:
							InformarProcentajeDeJugadoresPorConfederacion(listaJugadores, T_J, listaConfederaciones, T_C);
						break;
						case 6:
							InformarRegionConMasJugadores(listaJugadores, T_J, listaConfederaciones, T_C);
						break;
					}
				}
				else
				{
					printf("\nERROR - Se debera cargar al menos un jugador antes de ingresar a esta opcion.\n");
				}

			break;
		}

	}while(opcionElegida != 5);

	printf("\n< Programa Finalizado >");

	return 0;
}
