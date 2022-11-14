
#ifndef PARSER_H_
#define PARSER_H_

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"

int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador);
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador);
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion);
int parser_saveTextJugadores(FILE* pFile , LinkedList* pArrayListJugadores);

#endif /* PARSER_H_ */
