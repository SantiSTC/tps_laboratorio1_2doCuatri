/*
 * confederacion.c
 *
 *  Created on: 18 oct. 2022
 *      Author: Santiago
 */

#include "confederacion.h"

void MostrarUnaConfederacion(eConfederacion unaConfederacion)
{
	printf("| %d  |%-10s |%-30s |      %4d      |\n", unaConfederacion.id, unaConfederacion.nombre, unaConfederacion.region, unaConfederacion.anioCreacion);
}

void MostrarConfederaciones(eConfederacion listaConfederaciones[], int sizeConfederaciones)
{

	printf("=====================================================================\n"
			"| ID   |  NOMBRE   |         REGION                |  AÑO CREACION  |\n"
			"---------------------------------------------------------------------\n");
	for(int i=0; i<sizeConfederaciones; i++)
	{
		MostrarUnaConfederacion(listaConfederaciones[i]);
	}
	printf("=====================================================================\n");

}


