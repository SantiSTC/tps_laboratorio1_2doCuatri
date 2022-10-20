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

#define T_C
#define T_J

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

	opcionElegida = ElegirOpcion();

	return 0;
}
