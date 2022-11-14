#include "parser.h"

/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 */
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador)
{
	int retorno = 0;
	Jugador* unJugador = NULL;
	char idStr[100];
	char nombreStr[100];
	char edadStr[100];
	char posicionStr[100];
	char nacionalidadStr[100];
	char idSeleccionStr[100];
	int cantidadElementos;

	if(pFile != NULL && pArrayListJugador != NULL)
	{
		cantidadElementos = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombreStr, edadStr, posicionStr, nacionalidadStr, idSeleccionStr);

		do
		{
			cantidadElementos = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombreStr, edadStr, posicionStr, nacionalidadStr, idSeleccionStr);

			if(cantidadElementos == 6)
			{
				unJugador = jug_newParametros(idStr, nombreStr, edadStr, posicionStr, nacionalidadStr, idSeleccionStr);

				if(unJugador != NULL)
				{
					ll_add(pArrayListJugador, unJugador);
					retorno = 1;
				}
				else
				{
					jug_delete(unJugador);
				}
			}
			else
			{
				printf("HUBO UN ERROR...\n");
			}

		}while(!feof(pFile));
	}

    return retorno;
}

/** \brief Parsea los datos de los jugadores desde el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador)
{
    return 1;
}


/** \brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion)
{
	int retorno = 0;
	Seleccion* unaSeleccion = NULL;
	char idStr[100];
	char paisStr[100];
	char confederacionStr[100];
	char convocadosStr[100];
	int cantidadElementos;

	if(pFile != NULL && pArrayListSeleccion != NULL)
	{
		cantidadElementos = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idStr, paisStr, confederacionStr, convocadosStr);

		do
		{
			cantidadElementos = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idStr, paisStr, confederacionStr, convocadosStr);

			if(cantidadElementos == 4)
			{
				unaSeleccion = selec_newParametros(idStr, paisStr, confederacionStr, convocadosStr);

				if(unaSeleccion != NULL)
				{
					ll_add(pArrayListSeleccion, unaSeleccion);
					retorno = 1;
				}
				else
				{
					selec_delete(unaSeleccion);
				}
			}
			else
			{
				printf("HUBO UN ERROR...\n");
			}

		}while(!feof(pFile));
	}

    return retorno;
}

//=======================================================================================================================================

int parser_saveTextJugadores(FILE* pFile , LinkedList* pArrayListJugadores)
{
	int retorno = 0;
	Jugador* unJugador = NULL;
	int id;
	char nombreStr[100];
	int edad;
	char posicionStr[100];
	char nacionalidadStr[100];
	int idSeleccion;

	if(pFile != NULL && pArrayListJugadores != NULL)
	{
		for(int i=0; i<ll_len(pArrayListJugadores); i++)
		{
			unJugador = (Jugador*) ll_get(pArrayListJugadores, i);

			if(unJugador != NULL)
			{
				if(jug_getId(unJugador, &id) && jug_getNombreCompleto(unJugador, nombreStr) &&
					jug_getEdad(unJugador, &edad) && jug_getPosicion(unJugador, posicionStr) &&
					jug_getNacionalidad(unJugador, nacionalidadStr) && jug_getIdSeleccion(unJugador, &idSeleccion))
				{
					fprintf(pFile, "%d,%s,%d,%s,%s,%d\n", id, nombreStr, edad, posicionStr, nacionalidadStr, idSeleccion);
					retorno = 1;
				}
			}
		}
	}

	return retorno;
}

