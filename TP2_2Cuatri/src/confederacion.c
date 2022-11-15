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
		if(listaConfederaciones[i].isEmpty == OCUPADO)
		{
			MostrarUnaConfederacion(listaConfederaciones[i]);
		}
	}
	printf("=====================================================================\n");
}

eConfederacion CargarConfederacion()
{
	eConfederacion unaConfederacion;

	unaConfederacion.id = PedirId("Ingrese un ID para la confederacion: ");
	PedirNombre("Ingrese el nombre de la confederacion: ", unaConfederacion.nombre);
	PedirRegion("Ingrese la region de la confederacion: ", unaConfederacion.region);
	unaConfederacion.anioCreacion = PedirAnioCreacion("Ingrese el año de creacion de la confederacion: ");

	unaConfederacion.isEmpty = OCUPADO;

	return unaConfederacion;
}

int CargarListaConfederaciones(eConfederacion listaConfederaciones[], int sizeConfederaciones)
{
	int index;

	index = BuscarEspacio(listaConfederaciones, sizeConfederaciones);

	if(index > -1)
	{
		listaConfederaciones[index] = CargarConfederacion();
	}

	return index;
}

int EliminarConfederacion(eConfederacion listaConfederaciones[], int sizeConfederaciones)
{
	int retorno = 0;
	int idAEliminar;
	int validar;
	int pregunta;
	char preguntaAux[10];

	MostrarConfederaciones(listaConfederaciones, sizeConfederaciones);

	idAEliminar = PedirId("Ingrese el ID de la confederacion a eliminar: ");

	for(int i=0; i<sizeConfederaciones; i++)
	{
		if(idAEliminar == listaConfederaciones[i].id)
		{
			printf("=====================================================================\n"
					"| ID   |  NOMBRE   |         REGION                |  AÑO CREACION  |\n"
					"---------------------------------------------------------------------\n");

			MostrarUnaConfederacion(listaConfederaciones[i]);

			printf("=====================================================================\n");

			validar = getStringNumeros("¿Esta seguro que desea eliminar a esta confederacion? \n"
							"1- Si\n"
							"2- No\n"
							"Ingrese una opcion: ", preguntaAux);
			pregunta = atoi(preguntaAux);
			while(validar == 0 || (pregunta != 1 && pregunta != 2))
			{
				validar = getStringNumeros("¿Esta seguro que desea eliminar a esta confederacion? \n"
								"1- Si\n"
								"2- No\n"
								"Ingrese una opcion: ", preguntaAux);
				pregunta = atoi(preguntaAux);
			}

			if(pregunta == 1)
			{
				listaConfederaciones[i].isEmpty = LIBRE;
				retorno = 1;
				break;
			}
			else
			{
				printf("\nSe ha cancelado la baja de la confederacion \n");
				break;
			}
		}
	}

	return retorno;
}

int ModificarConfederacion(eConfederacion listaConfederaciones[], int sizeConfederaciones)
{
	int retorno = 0;
	int opcion;
	int idAModificar;

	MostrarConfederaciones(listaConfederaciones, sizeConfederaciones);

	idAModificar = PedirIdConfederacion("Ingrese el ID de la confederacion a modificar: ", listaConfederaciones, sizeConfederaciones);

	for(int i=0; i<sizeConfederaciones; i++)
	{
		if(idAModificar == listaConfederaciones[i].id)
		{
			opcion = MenuDeModificacionConfederaciones();

			switch(opcion)
			{
				case 1:
					printf("< Modificar Nombre >\n");

					retorno = PedirNombre("Ingrese el nuevo nombre de la confederacion: ", listaConfederaciones[i].nombre);
				break;
				case 2:
					printf("< Modificar Region >\n");

					retorno = PedirRegion("Ingrese la nueva region de la confederacion: ", listaConfederaciones[i].region);
				break;
				case 3:
					printf("< Modificar Año de creacion >\n");

					listaConfederaciones[i].anioCreacion = PedirAnioCreacion("Ingrese el nuevo año de creacion de la confederacion: ");
					retorno = 1;
				break;
			}
		}
	}

	return retorno;
}


int PedirId(char* mensaje)
{
	int validar;
	int id;
	char idAux[50];

	validar = getStringNumeros(mensaje, idAux);
	id = atoi(idAux);
	while(validar == 0 || id < 0 || (strcmp(idAux, "")==0))
	{
		validar = getStringNumeros(mensaje, idAux);
		id = atoi(idAux);
	}

	return id;
}

int PedirRegion(char* mensaje, char* region)
{
	char regionAux[50];
	int validar;

	validar = getStringLetras(mensaje, regionAux);
	while(validar == 0 || (strcmp(regionAux, "")==0))
	{
		validar = getStringLetras(mensaje, regionAux);
	}

	strcpy(region, regionAux);

	return validar;
}

int PedirAnioCreacion(char* mensaje)
{
	int validar;
	int anioCreacion;
	char anioCreacionAux[50];

	validar = getStringNumeros(mensaje, anioCreacionAux);
	anioCreacion = atoi(anioCreacionAux);
	while(validar == 0 || anioCreacion <= 0 || (strcmp(anioCreacionAux, "")==0))
	{
		validar = getStringNumeros(mensaje, anioCreacionAux);
		anioCreacion = atoi(anioCreacionAux);
	}

	return anioCreacion;
}

int MenuDeModificacionConfederaciones()
{
	int retorno;

	printf("\n----------------------------------------\n"
			"          Modificar Confederacion\n"
			"1. Nombre\n"
			"2. Region\n"
			"3. Año de creacion\n"
			"----------------------------------------\n");

	retorno = ElegirOpcion(3, 1);

	return retorno;
}










