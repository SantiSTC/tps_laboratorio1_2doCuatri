/*
 * jugador.c
 *
 *  Created on: 18 oct. 2022
 *      Author: Santiago
 */

#include "jugador.h"

void MostrarUnJugador(eJugador unJugador, eConfederacion listaConfederaciones[], int sizeConfederaciones)
{
	for(int i=0; i<sizeConfederaciones; i++)
	{
		if(unJugador.idConfederacion == listaConfederaciones[i].id)
		{
			printf("|%2d  | %-18s           | %-16s | %-11hu |%-17.2f | %-13s | %15hu  |\n", unJugador.id, unJugador.nombre, unJugador.posicion, unJugador.numeroCamiseta, unJugador.salario, listaConfederaciones[i].nombre, unJugador.aniosContrato);

		}
	}
}

void MostrarListaJugadores(eJugador listaJugadores[], int sizeJugadores, eConfederacion listaConfederaciones[], int sizeConfederacione)
{
	printf("============================================================================================================================\n"
			"| ID |           NOMBRE             |     POSICION     | N° CAMISETA |      SUELDO      | CONFEDERACION | AÑOS DE CONTRATO |\n"
			"----------------------------------------------------------------------------------------------------------------------------\n");
	for(int i=0; i<sizeJugadores; i++)
	{
		if(listaJugadores[i].isEmpty == OCUPADO)
		{
			MostrarUnJugador(listaJugadores[i], listaConfederaciones, sizeConfederacione);
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

int PedirNombre(char* mensaje, char* nombre)
{
	char nombreAux[50];
	int validar;

	validar = getStringLetras(mensaje, nombreAux);
	while(validar == 0 || (strcmp(nombreAux, "")==0))
	{
		validar = getStringLetras(mensaje, nombreAux);
	}

	strcpy(nombre, nombreAux);

	return validar;
}

int PedirPosicion(char* mensaje, char* posicion)
{
	char posicionAux[50];
	int validar;

	validar = getStringLetras(mensaje, posicionAux);
	for(int i=0; i<13; i++)
	{
		posicionAux[i] = tolower(posicionAux[i]);
	}
	while(validar == 0 || (strcmp(posicionAux, "")==0 || (strcmp(posicionAux, "delantero")!=0 &&
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

	return validar;
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

int EliminarJugador(eJugador listaJugadores[], int sizeJugadores, eConfederacion listaConfederaciones[], int sizeConfederaciones)
{
	int validar1;
	int validar2;
	int retorno = 0;
	char idAEliminarAux[10];
	int idAEliminar;
	char preguntaAux[10];
	int pregunta;

	MostrarListaJugadores(listaJugadores, sizeJugadores, listaConfederaciones, sizeConfederaciones);

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
			MostrarUnJugador(listaJugadores[i], listaConfederaciones, sizeConfederaciones);

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
				break;
			}
			else
			{
				printf("\nSe ha cancelado la baja del jugador \n");
				break;
			}
		}
	}

	return retorno;
}

int MenuDeModificacion()
{
	int retorno;

	printf("\n----------------------------------------\n"
			"            Modificar Jugador\n"
			"1. Nombre\n"
			"2. Posición\n"
			"3. Numero de camiseta\n"
			"4. Confederación\n"
			"5. Salario\n"
			"6. Años de contrato\n"
			"----------------------------------------\n");

	retorno = ElegirOpcion(6, 1);

	return retorno;
}

int ModificarJugador(eJugador listaJugadores[], int sizeJugadores, eConfederacion listaConfederaciones[], int sizeConfederaciones)
{
	int retorno = 0;
	int validar;
	int opcionElegida;

	char idAux[20];
	int idAModificar;

	short numeroCamisetaAux;
	int confederacionAux;
	float salarioAux;
	short aniosContratoAux;

	MostrarListaJugadores(listaJugadores, sizeJugadores, listaConfederaciones, sizeConfederaciones);

	validar = getStringNumeros("Ingrese el ID del jugador a modificar: ", idAux);
	idAModificar = atoi(idAux);
	while(validar == 0)
	{
		validar = getStringNumeros("ERROR, Ingrese el ID del jugador a modificar: ", idAux);
		idAModificar = atoi(idAux);
	}

	opcionElegida = MenuDeModificacion();

	for(int i=0; i<sizeJugadores; i++)
	{
		if(idAModificar == listaJugadores[i].id)
		{
			switch(opcionElegida)
			{
				case 1:
					printf("< Modificar Nombre >\n");
					retorno = PedirNombre("Ingrese el nuevo nombre del jugador: ", listaJugadores[i].nombre);
				break;
				case 2:
					printf("< Modificar Posición >\n");
					retorno = PedirPosicion("Ingrese la nueva posición del jugador: ", listaJugadores[i].posicion);
				break;
				case 3:
					printf("< Modificar Numero de Camiseta >\n");
					numeroCamisetaAux = PedirNumeroCamiseta("Ingrese el nuevo numero de camiseta del jugador: ");
					if(numeroCamisetaAux != 0)
					{
						listaJugadores[i].numeroCamiseta = numeroCamisetaAux;
						retorno = numeroCamisetaAux;
					}
				break;
				case 4:
					printf("< Modificar Confederación >\n");
					confederacionAux = PedirIdConfederacion("Ingrese la nueva confederacion del jugador: ", listaConfederaciones, sizeConfederaciones);
					if(confederacionAux != 0)
					{
						listaJugadores[i].idConfederacion = confederacionAux;
						retorno = confederacionAux;
					}
				break;
				case 5:
					printf("< Modificar Salario >\n");
					salarioAux = PedirSalario("Ingrese el nuevo salario del jugador: ");
					if(salarioAux != 0)
					{
						listaJugadores[i].salario = salarioAux;
						retorno = salarioAux;
					}
				break;
				case 6:
					printf("< Modificar Años de Contrato >\n");
					aniosContratoAux = PedirAniosContrato("Ingrese la nueva cantidad de años de contrato del jugador: ");
					if(aniosContratoAux != 0)
					{
						listaJugadores[i].aniosContrato = aniosContratoAux;
						retorno = aniosContratoAux;
					};
				break;
			}
		}
	}

	return retorno;
}


void OrdenarJugadoresAlfabeticamente(eJugador listaJugadores[], int sizeJugadores, eConfederacion listaConfederaciones[], int sizeConfederaciones)
{

	eJugador jugadorAux;
	eConfederacion aux1;
	eConfederacion aux2;

	for(int i=0; i<sizeJugadores; i++)
	{
		for(int j=i+1; j<sizeJugadores; j++)
		{
			aux1 = BuscarConfederacion(listaJugadores[i], listaConfederaciones, sizeConfederaciones);
			aux2 = BuscarConfederacion(listaJugadores[j], listaConfederaciones, sizeConfederaciones);

			if(strcmp(aux1.nombre, aux2.nombre)>0)
			{
				jugadorAux = listaJugadores[i];
				listaJugadores[i] = listaJugadores[j];
				listaJugadores[j] = jugadorAux;
			}
			else
			{
				if(strcmp(aux1.nombre, aux2.nombre)==0)
				{
					if(strcmp(listaJugadores[i].nombre, listaJugadores[j].nombre))
					{
						jugadorAux = listaJugadores[i];
						listaJugadores[i] = listaJugadores[j];
						listaJugadores[j] = jugadorAux;
					}
				}
			}
		}
	}

	MostrarListaJugadores(listaJugadores, sizeJugadores, listaConfederaciones, sizeConfederaciones);
}

eConfederacion BuscarConfederacion(eJugador jugador, eConfederacion listaConfederaciones[], int sizeConfederaciones)
{
	eConfederacion confederacion;

	for(int i = 0; i < sizeConfederaciones; i++)
	{
		if(listaConfederaciones[i].id == jugador.idConfederacion)
		{
			confederacion = listaConfederaciones[i];
			break;
		}
	}

	return confederacion;
}

void ListarConfederacionesConSusJugadores(eJugador listaJugadores[], int sizeJugadores, eConfederacion listaConfederaciones[], int sizeConfederaciones)
{
	int flag;

	for(int i=0; i<sizeConfederaciones; i++)
	{
		flag = 0;
		printf("===== %s =====\n", listaConfederaciones[i].nombre);

		for(int j=0; j<sizeJugadores; j++)
		{
			if(listaJugadores[j].idConfederacion == listaConfederaciones[i].id)
			{
				MostrarUnJugador(listaJugadores[j], listaConfederaciones, sizeConfederaciones);
				flag = 1;
			}
		}

		if(flag == 0)
		{
			printf("< No se encontraron jugadores de esta confederacion >\n");
		}
	}
}

void CalcularTotalYPromedioDeSalarios(eJugador listaJugadores[], int sizeJugadores, eConfederacion listaConfederaciones[], int sizeConfederaciones)
{
	float promedio;
	float totalSalarios = 0;
	int contador = 0;

	for(int i=0;i<sizeJugadores; i++)
	{
		if(listaJugadores[i].isEmpty == OCUPADO)
		{
			totalSalarios += listaJugadores[i].salario;
			contador++;
		}
	}

	promedio = totalSalarios / contador;

	printf("EL PROMEDIO DE SALARIOS ES: %.2f\n"
			"LOS JUGADORES QUE TIENEN UN SALARIO MAYOR AL PROMEDIO SON: \n", promedio);

	printf("============================================================================================================================\n"
				"| ID |           NOMBRE             |     POSICION     | N° CAMISETA |      SUELDO      | CONFEDERACION | AÑOS DE CONTRATO |\n"
				"----------------------------------------------------------------------------------------------------------------------------\n");

	for(int i=0;i<sizeJugadores; i++)
	{
		if(listaJugadores[i].isEmpty == OCUPADO && listaJugadores[i].salario > promedio)
		{
			MostrarUnJugador(listaJugadores[i], listaConfederaciones, sizeConfederaciones);
		}
	}

	printf("============================================================================================================================\n");
}

void InformarConfederacionConMasAniosDeContrato(eJugador listaJugadores[], int sizeJugadores, eConfederacion listaConfederaciones[], int sizeConfederaciones)
{
	eConfederacion confMaxAnios;
	int contadorAnios;
	int maxAnios = 0;

	for(int i=0; i<sizeConfederaciones; i++)
	{
		contadorAnios = 0;

		for(int j=0; j<sizeJugadores; j++)
		{
			if(listaJugadores[j].isEmpty == OCUPADO && listaJugadores[j].idConfederacion == listaConfederaciones[i].id)
			{
				contadorAnios += listaJugadores[j].aniosContrato;
			}
		}

		if(contadorAnios > maxAnios)
		{
			maxAnios = contadorAnios;
			confMaxAnios = listaConfederaciones[i];
		}
	}

	printf("La confederacion con mayor cantidad de años de contrato es: \n");

	printf("=====================================================================\n"
			"| ID   |  NOMBRE   |         REGION                |  AÑO CREACION  |\n"
			"---------------------------------------------------------------------\n");
		MostrarUnaConfederacion(confMaxAnios);
	printf("=====================================================================\n");
}

void InformarProcentajeDeJugadoresPorConfederacion(eJugador listaJugadores[], int sizeJugadores, eConfederacion listaConfederaciones[], int sizeConfederaciones)
{
	float porcentaje;
	int jugadoresTotales = 0;
	float jugadoresPorConf;

	for(int i=0; i<sizeJugadores; i++)
	{
		if(listaJugadores[i].isEmpty == OCUPADO)
		{
			jugadoresTotales++;
		}
	}

	for(int i=0; i<sizeConfederaciones; i++)
	{
		jugadoresPorConf = 0;

		printf("=== %s ===\n", listaConfederaciones[i].nombre);

		for(int j=0; j<sizeJugadores; j++)
		{
			if(listaJugadores[j].isEmpty == OCUPADO && listaJugadores[j].idConfederacion == listaConfederaciones[i].id)
			{
				jugadoresPorConf++;
			}
		}

		porcentaje = (jugadoresPorConf / jugadoresTotales)*100;
		printf("- Porcentaje: %.2f\n", porcentaje);
	}
}

void InformarRegionConMasJugadores(eJugador listaJugadores[], int sizeJugadores, eConfederacion listaConfederaciones[], int sizeConfederaciones)
{
	int contador;
	int mayor = 0;
	eConfederacion aux;

	for(int i=0; i<sizeConfederaciones; i++)
	{
		contador = 0;

		for(int j=0; j<sizeJugadores; j++)
		{
			if(listaJugadores[j].isEmpty == OCUPADO && listaJugadores[j].idConfederacion == listaConfederaciones[i].id)
			{
				contador++;
			}
		}

		if(contador > mayor)
		{
			mayor = contador;
			aux = listaConfederaciones[i];
		}
	}

	printf("=== La region con mas jugadores es: %s ===\n"
			" Sus jugadores son ->\n", aux.nombre);

	printf("============================================================================================================================\n"
			"| ID |           NOMBRE             |     POSICION     | N° CAMISETA |      SUELDO      | CONFEDERACION | AÑOS DE CONTRATO |\n"
			"----------------------------------------------------------------------------------------------------------------------------\n");

	for(int i=0; i<sizeJugadores; i++)
	{
		if(listaJugadores[i].idConfederacion == aux.id)
		{
			MostrarUnJugador(listaJugadores[i], listaConfederaciones, sizeConfederaciones);
		}
	}

	printf("============================================================================================================================\n");



}








