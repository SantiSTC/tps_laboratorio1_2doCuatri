/*
 * jugador.h
 *
 *  Created on: 18 oct. 2022
 *      Author: Santiago
 */

#ifndef JUGADOR_H_
#define JUGADOR_H_

#include "confederacion.h"

typedef struct{
	int id;
	char nombre[50];
	char posicion[50];
	short numeroCamiseta;
	int idConfederacion;
	float salario;
	short aniosContrato;
	short isEmpty;
}eJugador;



#endif /* JUGADOR_H_ */
