#include "Jugador.h"

Jugador* jug_new()
{
	Jugador* unJugador;

	unJugador = (Jugador*)malloc(sizeof(Jugador));

	if(unJugador != NULL)
	{
		unJugador->id = 0;
		strcpy(unJugador->nombreCompleto, " ");
		unJugador->edad = 0;
		strcpy(unJugador->posicion, " ");
		strcpy(unJugador->nacionalidad, " ");
		unJugador->idSeleccion = 0;
	}

	return unJugador;
}

Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr)
{
	Jugador* unJugador = NULL;
	int id;
	int edad;
	int idSeleccion;

	if(idStr != NULL && nombreCompletoStr != NULL && edadStr != NULL && posicionStr != NULL && nacionalidadStr != NULL && idSelccionStr != NULL)
	{
		unJugador = jug_new();

		id = atoi(idStr);
		edad = atoi(edadStr);
		idSeleccion = atoi(idSelccionStr);

		if(unJugador != NULL)
		{
			if(jug_setId(unJugador, id) && jug_setNombreCompleto(unJugador, nombreCompletoStr) && jug_setEdad(unJugador, edad) && jug_setPosicion(unJugador, posicionStr) && jug_setNacionalidad(unJugador, nacionalidadStr))
			{
				jug_setIdSeleccion(unJugador, idSeleccion);
			}
			else
			{
				jug_delete(unJugador);
			}
		}
	}

	return unJugador;
}

void jug_delete(Jugador* unJugador)
{
	if(unJugador != NULL)
	{
		free(unJugador);
		unJugador = NULL;
	}
}

int jug_setId(Jugador* this,int id)
{
	int retorno = 0;

	if(this != NULL && id > 0)
	{
		this->id = id;
		retorno = 1;
	}

	return retorno;
}

int jug_getId(Jugador* this,int* id)
{
	int retorno = 0;

	if(this != NULL)
	{
		*id = this->id;
		retorno = 1;
	}

	return retorno;
}

int jug_setNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int retorno = 0;

	if(this != NULL && nombreCompleto != NULL)
	{
		strcpy(this->nombreCompleto, nombreCompleto);
		retorno = 1;
	}

	return retorno;
}

int jug_getNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int retorno = 0;

	if(this != NULL)
	{
		strcpy(nombreCompleto, this->nombreCompleto);
		retorno = 1;
	}

	return retorno;
}

int jug_setPosicion(Jugador* this,char* posicion)
{
	int retorno = 0;

	if(this != NULL && posicion != NULL)
	{
		strcpy(this->posicion, posicion);
		retorno = 1;
	}

	return retorno;
}

int jug_getPosicion(Jugador* this,char* posicion)
{
	int retorno = 0;

	if(this != NULL)
	{
		strcpy(posicion, this->posicion);
		retorno = 1;
	}

	return retorno;
}

int jug_setNacionalidad(Jugador* this,char* nacionalidad)
{
	int retorno = 0;

	if(this != NULL && nacionalidad != NULL)
	{
		strcpy(this->nacionalidad, nacionalidad);
		retorno = 1;
	}

	return retorno;
}

int jug_getNacionalidad(Jugador* this,char* nacionalidad)
{
	int retorno = 0;

	if(this != NULL)
	{
		strcpy(nacionalidad, this->nacionalidad);
		retorno = 1;
	}

	return retorno;
}

int jug_setEdad(Jugador* this,int edad)
{
	int retorno = 0;

	if(this != NULL && edad > 0)
	{
		this->edad = edad;
		retorno = 1;
	}

	return retorno;
}

int jug_getEdad(Jugador* this,int* edad)
{
	int retorno = 0;

	if(this != NULL)
	{
		*edad = this->edad;
		retorno = 1;
	}

	return retorno;
}

int jug_setIdSeleccion(Jugador* this, int idSeleccion)
{
	int retorno = 0;

	if(this != NULL && idSeleccion >= 0)
	{
		this->idSeleccion = idSeleccion;
		retorno = 1;
	}

	return retorno;
}

int jug_getIdSeleccion(Jugador* this,int* idSeleccion)
{
	int retorno = 0;

	if(this != NULL)
	{
		*idSeleccion = this->idSeleccion;
		retorno = 1;
	}

	return retorno;
}


//=================================================================================================================================================

Jugador* AltaJugador(LinkedList* pArraySelecciones)
{
	Jugador* unJugador;
	char id[30];
	char nombreCompleto[100];
	char edad[30];
	char posicion[30];
	char nacionalidad[30];
	char idSeleccion[30];

	if(PedirNombre("Ingrese el nombre de un jugador: ", nombreCompleto) &&
		PedirEdad("Ingrese la edad del jugador: ", edad) &&
		PedirPosicion("Ingrese la posicion del jugador: ", posicion) &&
		PedirNacionalidad("Ingrese la nacionalidad del jugador: ", nacionalidad, pArraySelecciones))
	{
		if(AveriguarUltimoID("UltimoID.txt", id), SumarID(id))
		{
			if(GuardarID("UltimoID.txt", id))
			{
				strcpy(idSeleccion, "0");
				unJugador = jug_newParametros(id, nombreCompleto, edad, posicion, nacionalidad, idSeleccion);
			}
		}
	}

	return unJugador;
}

int AveriguarUltimoID(char* path, char* id)
{
	int valido = -1;
	FILE* pFile;

	pFile = fopen(path, "r");

	if(pFile != NULL && id != NULL)
	{
		fscanf(pFile, "%[^\n]\n", id);
		valido = 1;
	}

	fclose(pFile);

	return valido;
}

int SumarID(char* idStr)
{
	int valido = -1;
	int id;

	if(idStr != NULL)
	{
		id = atoi(idStr);
		id++;

		itoa(id, idStr, 10);

		valido = 1;
	}

	return valido;
}

int GuardarID(char* path, char* id)
{
	int valido = -1;
	FILE* pFile;

	pFile = fopen(path, "w");

	if(pFile != NULL)
	{
		fprintf(pFile, "%s\n", id);
		valido = 1;
	}

	fclose(pFile);

	return valido;
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
	for(int i=0; i<22; i++)
	{
		posicionAux[i] = tolower(posicionAux[i]);
	}
	while(validar == 0 || strcmp(posicionAux, "")==0 || (strcmp(posicionAux, "portero")!=0 &&
														strcmp(posicionAux, "defensa central")!=0 &&
														strcmp(posicionAux, "lateral izquierdo")!=0 &&
														strcmp(posicionAux, "lateral derecho")!=0 &&
														strcmp(posicionAux, "pivote")!=0 &&
														strcmp(posicionAux, "mediocentro")!=0 &&
														strcmp(posicionAux, "mediocentro ofensivo")!=0 &&
														strcmp(posicionAux, "mediocentro defensivo")!=0 &&
														strcmp(posicionAux, "extremo izquierdo")!=0 &&
														strcmp(posicionAux, "extremo derecho")!=0 &&
														strcmp(posicionAux, "mediapunta")!=0 &&
														strcmp(posicionAux, "delantero centro")!=0))

	{
		validar = getStringLetras(mensaje, posicionAux);
		for(int i=0; i<22; i++)
		{
			posicionAux[i] = tolower(posicionAux[i]);
		}
	}

	posicionAux[0] = toupper(posicionAux[0]);
	strcpy(posicion, posicionAux);

	return validar;
}

int PedirEdad(char* mensaje, char* edad)
{
	char edadAux[50];
	int validar;
	int edadValidar;

	validar = getStringNumeros(mensaje, edadAux);
	edadValidar = atoi(edadAux);
	while(validar == 0 || (strcmp(edadAux, "")==0) || edadValidar < 16)
	{
		validar = getStringNumeros(mensaje, edadAux);
		edadValidar = atoi(edadAux);
	}

	strcpy(edad, edadAux);

	return validar;
}

int PedirNacionalidad(char* mensaje, char* nacionalidad, LinkedList* pArraySelecciones)
{
	int validar;
	int nacionalidadAux;
	int idNacAux;
	char nacionalidadStr[50];
	Seleccion* SelecAux;

	MostrarListaSelecciones(pArraySelecciones);
	validar = PedirIdSeleccion(mensaje, &nacionalidadAux);
	while(validar == 0)
	{
		validar = PedirIdSeleccion(mensaje, &nacionalidadAux);
	}

	for(int i=0; i<ll_len(pArraySelecciones); i++)
	{
		SelecAux = ll_get(pArraySelecciones, i);
		selec_getId(SelecAux, &idNacAux);

		if(nacionalidadAux == idNacAux)
		{
			selec_getPais(SelecAux, nacionalidadStr);
			strcpy(nacionalidad, nacionalidadStr);
			break;
		}
	}

	return validar;
}

int PedirIdSeleccion(char* mensaje, int* idSeleccion)
{
	char idSeleccionAux[50];
	int validar;

	validar = getStringNumeros(mensaje, idSeleccionAux);
	while(validar == 0 || (strcmp(idSeleccionAux, "")==0))
	{
		validar = getStringNumeros(mensaje, idSeleccionAux);
	}

	*idSeleccion = atoi(idSeleccionAux);

	return validar;
}

int PediridJugador(char* mensaje, int* idJugador)
{
	char idJugadorAux[50];
	int validar;

	validar = getStringNumeros(mensaje, idJugadorAux);
	while(validar == 0 || (strcmp(idJugadorAux, "")==0))
	{
		validar = getStringNumeros(mensaje, idJugadorAux);
	}

	*idJugador = atoi(idJugadorAux);

	return validar;
}

int MostrarUnJugador(Jugador* unJugador, LinkedList* pArraySelecciones)
{
	int retorno = 0;
	int id;
	char nombre[50];
	int edad;
	char posicion[50];
	char nacionalidad[50];
	int idSeleccion;
	char seleccion[50];
	Seleccion* unaSeleccion;

	if(unJugador != NULL)
	{
		if(jug_getId(unJugador, &id) && jug_getNombreCompleto(unJugador, nombre) && jug_getEdad(unJugador, &edad) && jug_getPosicion(unJugador, posicion) && jug_getNacionalidad(unJugador, nacionalidad) && jug_getIdSeleccion(unJugador, &idSeleccion))
		{
			if(idSeleccion == 0)
			{
				strcpy(seleccion, "No Convocado");
				printf("|%-3d | %-24s | %-4d | %-20s | %-15s | %-15s |\n", id, nombre, edad, posicion, nacionalidad, seleccion);
				retorno = 1;
			}
			else
			{
				unaSeleccion = BuscarSeleccion(pArraySelecciones, idSeleccion);
				selec_getPais(unaSeleccion, seleccion);

				printf("|%-3d | %-24s | %-4d | %-20s | %-15s | %-15s |\n", id, nombre, edad, posicion, nacionalidad, seleccion);
				retorno = 1;
			}
		}
	}

	return retorno;
}

int MostrarListaJugadores(LinkedList* pArrayJugadores, LinkedList* pArraySelecciones)
{
	int retorno = 0;
	Jugador* unJugador = NULL;

	if(pArrayJugadores != NULL)
	{
		printf("===================================================================================================\n"
				"| ID | NOMBRE                   | EDAD | POSICION             | NACIONALIDAD    | SELECCION       |\n"
				"===================================================================================================\n");

		for(int i=0; i<ll_len(pArrayJugadores); i++)
		{
			unJugador = ll_get(pArrayJugadores, i);
			retorno = MostrarUnJugador(unJugador, pArraySelecciones);
		}

		printf("===================================================================================================\n");
	}

	return retorno;
}

int ModificarJugador(LinkedList* pArrayJugadores, LinkedList* pArraySelecciones)
{
	int retorno = 0;
	int opcion;
	int idJugador;
	Jugador* unJugador;

	MostrarListaJugadores(pArrayJugadores, pArraySelecciones);

	PediridJugador("Ingrese el ID del jugador a modificar: ", &idJugador);
	unJugador = BuscarJugador(pArrayJugadores, idJugador);

	if(unJugador != NULL)
	{
		opcion = MenuModificacion();

		switch(opcion)
		{
			case 1:
				retorno = ModificarNombre(unJugador);
			break;
			case 2:
				retorno = ModificarEdad(unJugador);
			break;
			case 3:
				retorno = ModificarPosicion(unJugador);
			break;
			case 4:
				retorno = ModificarNacionalidad(unJugador);
			break;
		}
	}

	return retorno;
}

int ModificarNombre(Jugador* unJugador)
{
	char nombre[50];
	int retorno;

	if(unJugador != NULL)
	{
		PedirNombre("Ingrese el nuevo nombre del jugador: ", nombre);
		retorno = jug_setNombreCompleto(unJugador, nombre);
	}

	return retorno;
}

int ModificarEdad(Jugador* unJugador)
{
	int edad;
	char edadAux[30];
	int retorno;

	if(unJugador != NULL)
	{
		PedirEdad("Ingrese la nueva edad del jugador: ", edadAux);
		edad = atoi(edadAux);
		retorno = jug_setEdad(unJugador, edad);
	}

	return retorno;
}

int ModificarPosicion(Jugador* unJugador)
{
	char posicion[50];
	int retorno;

	if(unJugador != NULL)
	{
		PedirPosicion("Ingrese la nueva posicion del jugador: ", posicion);
		retorno = jug_setPosicion(unJugador, posicion);
	}

	return retorno;
}

int ModificarNacionalidad(Jugador* unJugador)
{
	char nacionalidad[50];
	int retorno;

	if(unJugador != NULL)
	{
		PedirPosicion("Ingrese la nueva nacionalidad del jugador: ", nacionalidad);
		retorno = jug_setNacionalidad(unJugador, nacionalidad);
	}

	return retorno;
}

int BajaDeJugador(LinkedList* pArrayJugadores, LinkedList* pArraySelecciones)
{
	int retorno = 0;
	int idJugador;
	Jugador* unJugador = NULL;
	int index;

	MostrarListaJugadores(pArrayJugadores, pArraySelecciones);
	PediridJugador("Ingrese el ID del jugador a dar de baja: ", &idJugador);

	unJugador = BuscarJugador(pArrayJugadores, idJugador);

	if(unJugador != NULL)
	{
		index = ll_indexOf(pArrayJugadores, unJugador);

		if(index > -1)
		{
			retorno = ll_remove(pArrayJugadores, index);
		}
	}

	return retorno;
}

Jugador* BuscarJugador(LinkedList* pArrayJugador, int id)
{
	Jugador* unJugador = NULL;
	Jugador* jugAux = NULL;
	int idAux;

	for(int i=0; i<ll_len(pArrayJugador); i++)
	{
		jugAux = (Jugador*) ll_get(pArrayJugador, i);

		jug_getId(jugAux, &idAux);

		if(jugAux != NULL && idAux == id)
		{
			unJugador = jugAux;
			break;
		}
	}

	return unJugador;
}









