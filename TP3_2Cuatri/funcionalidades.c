/*
 * funcionalidades.c
 *
 *  Created on: 1 nov. 2022
 *      Author: Santiago
 */

#include "funcionalidades.h"

int MenuPrincipal()
{
	int opcion;

	printf("==============================\n"
			"       Menu Principal\n\n"
			" 1. Carga de archivos\n"
			" 2. Alta de Jugador\n"
			" 3. Modificacion de Jugador\n"
			" 4. Baja de Jugador\n"
			" 5. Listados\n"
			" 6. Convocar Jugadores\n"
			" 7. Ordenar y listar\n"
			" 8. Generar archivo binario\n"
			" 9. Cargar archivo binario\n"
			" 10. Guardar archivos .CSV\n"
			" 11. Salir\n"
			"==============================\n");

	opcion = ElegirOpcion(11, 1);

	return opcion;
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

int MenuListados()
{
	int opcion;

	printf("===========================\n"
			"      Menu Listados\n\n"
			" 1. Todos los jugadores\n"
			" 2. Todas las selecciones\n"
			" 3. Jugadores convocados\n"
			"===========================\n");

	opcion = ElegirOpcion(3, 1);

	return opcion;
}

int MenuConvocar()
{
	int opcion;

	printf("============================\n"
			"     Convocar Jugadores\n\n"
			" 1. Convocar\n"
			" 2. Quitar de la seleccion\n"
			"============================\n");

	opcion = ElegirOpcion(2, 1);

	return opcion;
}

int MenuOrdenYListado()
{
	int opcion;

	printf("===================================\n"
			"         Ordenar y listar\n\n"
			" 1. Jugadores por nacionalidad\n"
			" 2. Selecciones por confederacion\n"
			" 3. Jugadores por edad\n"
			" 4. Jugadores por nombre\n"
			"===================================\n");

	opcion = ElegirOpcion(4, 1);

	return opcion;
}

int MenuModificacion()
{
	int opcion;

	printf("===============================\n"
			"          Modificar\n\n"
			" 1. Nombre\n"
			" 2. Edad\n"
			" 3. Posicion\n"
			" 4. Nacionalidad\n"
			"===============================\n");


	opcion = ElegirOpcion(4, 1);

	return opcion;
}

int ListarListados(LinkedList* pArrayJugadores, LinkedList* pArraySelecciones)
{
	int retorno = 0;
	int opcion;

	opcion = MenuListados();

	switch(opcion)
	{
		case 1:
			retorno = MostrarListaJugadores(pArrayJugadores, pArraySelecciones);
		break;
		case 2:
			retorno = MostrarListaSelecciones(pArraySelecciones);
		break;
		case 3:
			retorno = MostrarJugadoresConvocados(pArrayJugadores, pArraySelecciones);
		break;
	}

	return retorno;
}

int MostrarJugadoresConvocados(LinkedList* pArrayJugadores, LinkedList* pArraySelecciones)
{
	int retorno = 0;
	Jugador* unJugador;
	int idSeleccion;

	if(pArrayJugadores != NULL)
	{
		for(int i=0; i<ll_len(pArrayJugadores); i++)
		{
			unJugador = ll_get(pArrayJugadores, i);

			if(unJugador != NULL && jug_getIdSeleccion(unJugador, &idSeleccion))
			{
				if(idSeleccion != 0)
				{
					retorno = MostrarUnJugador(unJugador, pArraySelecciones);
				}
			}
		}
	}

	return retorno;
}

int OrdenarYListar(LinkedList* pArrayJugadores, LinkedList* pArraySelecciones)
{
	int retorno = 0;
	int opcion;

	opcion = MenuOrdenYListado();

	if(pArrayJugadores != NULL && pArraySelecciones != NULL)
	{
		switch(opcion)
		{
			case 1:
				retorno = OrdenarJugadoresPorCriterio(pArrayJugadores, CompararNacionalidades);
			break;
			case 2:
				retorno= OrdenarSeleccionesPorConfederacion(pArraySelecciones);
			break;
			case 3:
				retorno = OrdenarJugadoresPorCriterio(pArrayJugadores, CompararEdades);
			break;
			case 4:
				retorno = OrdenarJugadoresPorCriterio(pArrayJugadores, CompararNombres);
			break;
		}

		if(opcion != 2)
		{
			MostrarListaJugadores(pArrayJugadores, pArraySelecciones);
		}
		else
		{
			MostrarListaSelecciones(pArraySelecciones);
		}
	}


	return retorno;
}

int OrdenarJugadoresPorCriterio(LinkedList* pArrayJugadores, int pFunc(void* jug1, void* jug2))
{
	int retorno;

	retorno = ll_sort(pArrayJugadores, pFunc, 1);

	return retorno;
}

int OrdenarSeleccionesPorConfederacion(LinkedList* pArraySelecciones)
{
	int retorno;

	retorno = ll_sort(pArraySelecciones, CompararConfederaciones, 1);

	return retorno;
}

int CompararNacionalidades(void* jug1, void* jug2)
{
	int retorno = 0;
	char nac1[50];
	char nac2[50];

	jug_getNacionalidad(jug1, nac1);
	jug_getNacionalidad(jug2, nac2);

	if(strcmp(nac1,nac2)>0)
	{
		retorno = 1;
	}
	else
	{
		if(strcmp(nac1,nac2)<0)
		{
			retorno = -1;
		}
	}

	return retorno;
}

int CompararEdades(void* jug1, void* jug2)
{
	int retorno = 0;
	int edad1;
	int edad2;

	jug_getEdad(jug1, &edad1);
	jug_getEdad(jug2, &edad2);

	if(edad1 > edad2)
	{
		retorno = 1;
	}
	else
	{
		if(edad1 < edad2)
		{
			retorno = -1;
		}
	}

	return retorno;
}

int CompararNombres(void* jug1, void* jug2)
{
	int retorno = 0;
	char nombre1[50];
	char nombre2[50];

	jug_getNombreCompleto(jug1, nombre1);
	jug_getNombreCompleto(jug2, nombre2);

	if(strcmpi(nombre1,nombre2)>0)
	{
		retorno = 1;
	}
	else
	{
		if(strcmpi(nombre1,nombre2)<0)
		{
			retorno = -1;
		}
	}

	return retorno;
}

int CompararConfederaciones(void* selec1, void* selec2)
{
	int retorno = 0;
	char conf1[50];
	char conf2[50];

	selec_getConfederacion(selec1, conf1);
	selec_getConfederacion(selec2, conf2);

	if(strcmpi(conf1,conf2)>0)
	{
		retorno = 1;
	}
	else
	{
		if(strcmpi(conf1,conf2)<0)
		{
			retorno = -1;
		}
	}

	return retorno;
}




