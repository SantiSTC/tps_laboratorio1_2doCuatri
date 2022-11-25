#include "Seleccion.h"

Seleccion* selec_new()
{
	Seleccion* unaSeleccion;

	unaSeleccion = (Seleccion*) malloc(sizeof(Seleccion));

	if(unaSeleccion != NULL)
	{
		unaSeleccion->id = 0;
		strcpy(unaSeleccion->pais, " ");
		strcpy(unaSeleccion->confederacion, " ");
		unaSeleccion->convocados = 0;
	}

	return unaSeleccion;
}

Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr)
{
	Seleccion* unaSeleccion = NULL;
	int id;
	int convocados;

	if(idStr != NULL && paisStr != NULL && confederacionStr != NULL && convocadosStr != NULL)
	{
		unaSeleccion = selec_new();

		id = atoi(idStr);
		convocados = atoi(convocadosStr);

		if(unaSeleccion != NULL)
		{
			if(!selec_setId(unaSeleccion, id) || !selec_setConfederacion(unaSeleccion, confederacionStr) || !selec_setPais(unaSeleccion, paisStr) || !selec_setConvocados(unaSeleccion, convocados))
			{
				unaSeleccion = NULL;
			}
		}
	}

	return unaSeleccion;
}

void selec_delete(Seleccion* unaSeleccion)
{
	if(unaSeleccion != NULL)
	{
		free(unaSeleccion);
		unaSeleccion = NULL;
	}
}

void MostrarUnaSeleccion(Seleccion* unaSeleccion)
{
	int id;
	char pais[50];
	char confederacion[50];
	int convocados;

	if(selec_getId(unaSeleccion, &id), selec_getPais(unaSeleccion, pais), selec_getConfederacion(unaSeleccion, confederacion), selec_getConvocados(unaSeleccion, &convocados))
	{
		printf("|%-3d | %-17s | %-13s | %-13d |\n", id, pais, confederacion, convocados);
	}
}

int MostrarListaSelecciones(LinkedList* pArraySelecciones)
{
	int retorno = 0;
	Seleccion* unaSeleccion = NULL;

	printf("==========================================================\n"
			"| ID | PAIS              | CONFEDERACION | N° CONVOCADOS |\n"
			"==========================================================\n");

	for(int i=0; i < ll_len(pArraySelecciones); i++)
	{
		unaSeleccion = (Seleccion*)ll_get(pArraySelecciones, i);

		if(unaSeleccion != NULL)
		{
			MostrarUnaSeleccion(unaSeleccion);
			retorno = 1;
		}
	}

	printf("==========================================================\n");

	return retorno;
}

int selec_getId(Seleccion* this,int* id)
{
	int retorno = 0;

	if(this != NULL)
	{
		*id = this->id;
		retorno = 1;
	}

	return retorno;
}

int selec_getPais(Seleccion* this,char* pais)
{
	int retorno = 0;

	if(this != NULL)
	{
		strcpy(pais, this->pais);
		retorno = 1;
	}

	return retorno;
}

int selec_getConfederacion(Seleccion* this,char* confederacion)
{
	int retorno = 0;

	if(this != NULL)
	{
		strcpy(confederacion, this->confederacion);
		retorno = 1;
	}

	return retorno;
}

int selec_getConvocados(Seleccion* this,int* convocados)
{
	int retorno = 0;

	if(this != NULL)
	{
		*convocados = this->convocados;
		retorno = 1;
	}

	return retorno;
}



int selec_setId(Seleccion* this,int id)
{
	int retorno = 0;

	if(this != NULL)
	{
		this->id = id;
		retorno = 1;
	}

	return retorno;
}

int selec_setPais(Seleccion* this,char* pais)
{
	int retorno = 0;

	if(this != NULL)
	{
		strcpy(this->pais, pais);
		retorno = 1;
	}

	return retorno;

}

int selec_setConfederacion(Seleccion* this,char* confederacion)
{
	int retorno = 0;

	if(this != NULL)
	{
		strcpy(this->confederacion, confederacion);
		retorno = 1;
	}

	return retorno;
}

int selec_setConvocados(Seleccion* this,int convocados)
{
	int retorno = 0;

	if(this != NULL)
	{
		this->convocados += convocados;
		retorno = 1;
	}

	return retorno;
}

//======================================================================================================

int InicializarConvocados(LinkedList* pArraySelecciones)
{
	int retorno = 0;
	Seleccion* unaSeleccion;

	for(int i=0; i<ll_len(pArraySelecciones); i++)
	{
		unaSeleccion = (Seleccion*) ll_get(pArraySelecciones, i);

		if(unaSeleccion != NULL)
		{
			selec_setConvocados(unaSeleccion, 0);
		}
	}

	return retorno;
}

int ConvocarJugadores(LinkedList* pArrayJugadores, LinkedList* pArraySelecciones)
{
	int retorno;
	int opcion;
	int idJugador;
	int idSeleccion;
	Jugador* unJugador;
	Seleccion* unaSeleccion;
	int idSeleccionAux;
	int flagConvocados;

	opcion = MenuConvocar();

	if(pArrayJugadores != NULL && pArraySelecciones != NULL)
	{
		switch(opcion)
		{
			case 1:
				if(MostrarJugadoresNoConvocados(pArrayJugadores, pArraySelecciones) && PediridJugador("Ingrese el ID del jugador a convocar: ", &idJugador))
				{
					unJugador = BuscarJugador(pArrayJugadores, idJugador);

					if(unJugador != NULL)
					{
						MostrarListaSelecciones(pArraySelecciones);
						PedirIdSeleccion("Ingrese el ID de la seleccion a la cual se convocará al jugador: ", &idSeleccion);

						unaSeleccion = BuscarSeleccion(pArraySelecciones, idSeleccion);

						if(unaSeleccion != NULL)
						{
							selec_setConvocados(unaSeleccion, 1);
							retorno = jug_setIdSeleccion(unJugador, idSeleccion);
						}
					}
				}
			break;
			case 2:
				flagConvocados = MostrarJugadoresConvocados(pArrayJugadores, pArraySelecciones);
				PediridJugador("Ingrese el ID del jugador a quitar de la convocatoria: ", &idJugador);

				if(flagConvocados != 0)
				{
					unJugador = BuscarJugador(pArrayJugadores, idJugador);

					if(unJugador != NULL)
					{
						jug_getIdSeleccion(unJugador, &idSeleccionAux);
						unaSeleccion = BuscarSeleccion(pArraySelecciones, idSeleccionAux);

						if(unaSeleccion != NULL)
						{
							retorno = jug_setIdSeleccion(unJugador, 0);
							selec_setConvocados(unaSeleccion, -1);
						}
					}
				}
			break;
		}
	}

	return retorno;
}

Seleccion* BuscarSeleccion(LinkedList* pArraySelecciones, int id)
{
	Seleccion* unaSeleccion = NULL;
	Seleccion* selecAux = NULL;
	int idAux;

	for(int i=0; i<ll_len(pArraySelecciones); i++)
	{
		selecAux = (Seleccion*) ll_get(pArraySelecciones, i);

		selec_getId(selecAux, &idAux);

		if(selecAux != NULL && idAux == id)
		{
			unaSeleccion = selecAux;
			break;
		}
	}

	return unaSeleccion;
}










