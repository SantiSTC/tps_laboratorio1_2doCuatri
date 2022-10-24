/*
 * jugador.c
 *
 *  Created on: 18 oct. 2022
 *      Author: Santiago
 */

#include "jugador.h"

void MostrarUnJugador(eJugador unJugador)
{
	printf("|%2d  | %-18s           | %16s | %11hu |%17.2f | %-13d | %15hu  |\n", unJugador.id, unJugador.nombre, unJugador.posicion, unJugador.numeroCamiseta, unJugador.salario, unJugador.idConfederacion, unJugador.aniosContrato);
}

void MostrarListaJugadores(eJugador listaJugadores[], int sizeJugadores)
{
	printf("============================================================================================================================\n"
			"| ID |           NOMBRE             |     POSICION     | N° CAMISETA |      SUELDO      | CONFEDERACION | AÑOS DE CONTRATO |\n"
			"----------------------------------------------------------------------------------------------------------------------------\n");
	for(int i=0; i<sizeJugadores; i++)
	{
		if(listaJugadores[i].isEmpty == OCUPADO)
		{
			MostrarUnJugador(listaJugadores[i]);
		}
	}

	printf("============================================================================================================================\n");
}

void InicializarJugador(eJugador listaJugadores[], int sizeJugadores)
{
	int index;

	index = BuscarEspacio(listaJugadores, sizeJugadores);
	for(int i=0; i<sizeJugadores; i++)
	{
		if(index != -1)
		{
			listaJugadores[i].isEmpty = LIBRE;
		}
	}
}

int ObtenerID()
{
	static int idAutoIncremental = 1;
	return idAutoIncremental++;
}

void PedirNombre(char* mensaje, char* nombre)
{
	char nombreAux[50];
	int validar;

	validar = getStringLetras(mensaje, nombreAux);
	while(validar == 0 || (strcmp(nombreAux, "")==0))
	{
		validar = getStringLetras(mensaje, nombreAux);
	}

	strcpy(nombre, nombreAux);
}

void PedirPosicion(char* mensaje, char* posicion)
{
	char posicionAux[50];
	int validar;

	validar = getStringLetras(mensaje, posicionAux);
	for(int i=0; i<13; i++)
	{
		posicionAux[i] = tolower(posicionAux[i]);
	}

	while(validar == 0 || (strcmp(posicionAux, "")==0 && (strcmp(posicionAux, "delantero")!=0 &&
														strcmp(posicionAux, "mediocampista")!=0 &&
														strcmp(posicionAux, "defensor")!=0 &&
														strcmp(posicionAux, "arquero")!=0)))
	{
		validar = getStringLetras(mensaje, posicionAux);
		for(int i=0; i<13; i++)
		{
			posicionAux[i] = tolower(posicionAux[i]);
		}
	}

	posicionAux[0] = toupper(posicionAux[0]);
	strcpy(posicion, posicionAux);
}

short PedirNumeroCamiseta(char* mensaje)
{
	int validar;
	char numeroCamisetaAux[50];
	int numeroCamiseta;

	validar = getStringNumeros(mensaje, numeroCamisetaAux);
	numeroCamiseta = atoi(numeroCamisetaAux);
	while(validar == 0 || (numeroCamiseta < 1 && numeroCamiseta > 99) || (strcmp(numeroCamisetaAux, "")==0))
	{
		validar = getStringLetras(mensaje, numeroCamisetaAux);
		numeroCamiseta = atoi(numeroCamisetaAux);
	}

	return numeroCamiseta;
}

int PedirIdConfederacion(char* mensaje, eConfederacion listaConfederaciones[], int sizeConfederaciones)
{
	int validar;
	char idConfederacionAux[50];
	int idConfederacion;

	MostrarConfederaciones(listaConfederaciones, sizeConfederaciones);

	validar = getStringNumeros(mensaje, idConfederacionAux);
	idConfederacion = atoi(idConfederacionAux);
	while(validar == 0 || idConfederacion < 100 || idConfederacion > 105 || strcmp(idConfederacionAux, "")==0)
	{
		validar = getStringNumeros(mensaje, idConfederacionAux);
		idConfederacion = atoi(idConfederacionAux);
	}

	return idConfederacion;
}

float PedirSalario(char* mensaje)
{
	int validar;
	float salario;
	char salarioAux[50];

	validar = getStringNumerosFlotantes(mensaje, salarioAux);
	salario = atoi(salarioAux);
	while(validar == 0 || salario < 0 || (strcmp(salarioAux, "")==0))
	{
		validar = getStringNumerosFlotantes(mensaje, salarioAux);
		salario = atoi(salarioAux);
	}

	return salario;
}

short PedirAniosContrato(char* mensaje)
{
	int validar;
	int aniosContrato;
	char aniosContratoAux[50];

	validar = getStringNumeros(mensaje, aniosContratoAux);
	aniosContrato = atoi(aniosContratoAux);
	while(validar == 0 || aniosContrato <= 0 || (strcmp(aniosContratoAux, "")==0))
	{
		validar = getStringNumeros(mensaje, aniosContratoAux);
		aniosContrato = atoi(aniosContratoAux);
	}

	return aniosContrato;
}

int BuscarEspacio(eJugador listaJugadores[], int sizeJugadores)
{
	int index = -1;

	for(int i = 0; i < sizeJugadores; i++)
	{
		if(listaJugadores[i].isEmpty == LIBRE)
	    {
			index = i;
	        break;
	    }
	}

	return index;
}

eJugador CargarJugador(eConfederacion listaConfederaciones[], int sizeConfederaciones)
{
	eJugador unJugador;

	unJugador.id = ObtenerID();
	PedirNombre("Ingrese el nombre del jugador: ", unJugador.nombre);
	PedirPosicion("Ingrese la posicion del jugador: ", unJugador.posicion);
	unJugador.numeroCamiseta = PedirNumeroCamiseta("Ingrese el numero de camiseta: ");
	unJugador.idConfederacion = PedirIdConfederacion("Ingrese el ID de la confederacion del jugador: ", listaConfederaciones, sizeConfederaciones);
	unJugador.salario = PedirSalario("Ingrese el salario del jugador: ");
	unJugador.aniosContrato = PedirAniosContrato("Ingrese los años de contrato del jugador: ");

	unJugador.isEmpty = OCUPADO;

	return unJugador;
}

int CargarListaJugadores(eJugador listaJugadores[], int sizeJugadores, eConfederacion listaConfederaciones[], int sizeConfederaciones)
{
	int index;

	printf("< Alta de Jugador >\n");

	index = BuscarEspacio(listaJugadores, sizeJugadores);

	if(index != -1)
	{
		listaJugadores[index] = CargarJugador(listaConfederaciones, sizeConfederaciones);
	}

	return index;
}

int EliminarJugador(eJugador listaJugadores[], int sizeJugadores)
{
	int validar1;
	int validar2;
	int retorno = 0;
	char idAEliminarAux[10];
	int idAEliminar;
	char preguntaAux[10];
	int pregunta;

	MostrarListaJugadores(listaJugadores, sizeJugadores);

	validar1 = getStringNumeros("Ingrese el ID del jugador a eliminar: ", idAEliminarAux);
	idAEliminar = atoi(idAEliminarAux);
	while(validar1 == 0)
	{
		validar1 = getStringNumeros("ERROR, Ingrese el ID del jugador a eliminar: ", idAEliminarAux);
		idAEliminar = atoi(idAEliminarAux);
	}

	for(int i=0; i<sizeJugadores; i++)
	{
		if(idAEliminar == listaJugadores[i].id)
		{
			printf("============================================================================================================================\n"
					"| ID |           NOMBRE             |     POSICION     | N° CAMISETA |      SUELDO      | CONFEDERACION | AÑOS DE CONTRATO |\n"
					"----------------------------------------------------------------------------------------------------------------------------\n");
			MostrarUnJugador(listaJugadores[i]);

			printf("============================================================================================================================\n");

			validar2 = getStringNumeros("¿Esta seguro que desea eliminar a este jugador? \n"
							"1- Si\n"
							"2- No\n"
							"Ingrese una opcion: ", preguntaAux);
			pregunta = atoi(preguntaAux);
			while(validar2 == 0 || (pregunta != 1 && pregunta != 2))
			{
				validar2 = getStringNumeros("ERROR, ¿Esta seguro que desea eliminar a este jugador? \n"
								"1- Si\n"
								"2- No\n"
								"Ingrese una opcion: ", preguntaAux);
				pregunta = atoi(preguntaAux);
			}

			if(pregunta == 1)
			{
				listaJugadores[i].isEmpty = LIBRE;
				retorno = 1;
			}
			else
			{
				printf("\nSe ha cancelado la baja del jugador \n");
			}
		}
	}

	return retorno;
}




