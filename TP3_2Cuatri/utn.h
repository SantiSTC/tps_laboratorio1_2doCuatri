/*
 * utn.h
 *
 *  Created on: 8 ago. 2022
 *      Author: Santiago
 */

#ifndef UTN_H_
#define UTN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LIBRE 0
#define OCUPADO 1

float getFloat(char mensaje[]);
int getInt(char mensaje[]);
char getChar(char mensaje[]);
char getNumeroAleatorio(int desde , int hasta, int iniciar);
int esNumericoFlotante(char str[]);
int esNumerico(char str[]);
int esSoloLetras(char str[]);
int esAlfaNumerico(char str[]);
int esTelefono(char str[]);
void getString(char mensaje[],char input[]);
int getStringLetras(char mensaje[],char input[]);
int getStringNumeros(char mensaje[],char input[]);
int getStringNumerosFlotantes(char mensaje[],char input[]);

#endif /* UTN_H_ */
