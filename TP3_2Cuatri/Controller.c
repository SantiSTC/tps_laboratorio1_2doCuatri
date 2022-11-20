#include "Controller.h"

/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador)
{
	int retorno = 0;
	FILE* pArchivo;

	pArchivo = fopen(path, "r");

	retorno = parser_JugadorFromText(pArchivo, pArrayListJugador);

	fclose(pArchivo);

    return retorno;
}

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador)
{
	int retorno = 0;
	FILE* pArchivo;

	pArchivo = fopen(path, "rb");

	retorno =  parser_JugadorFromBinary(pArchivo, pArrayListJugador);

	fclose(pArchivo);

    return retorno;
}

int controller_cargarArchivosDesdeBinario(char* pathJug , LinkedList* pArrayListJugador, char* pathSel, LinkedList* pArraySelecciones)
{
	int retorno = 0;

	if(controller_cargarJugadoresDesdeBinario(pathJug, pArrayListJugador) && controller_cargarSeleccionesDesdeBinario(pathSel, pArraySelecciones))
	{
		retorno = 1;
	}

	return retorno;
}

/** \brief Alta de jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_agregarJugador(LinkedList* pArrayListJugador)
{
	int retorno = 0;

	Jugador* unJugador = AltaJugador();

	if(pArrayListJugador != NULL && unJugador != NULL)
	{
		retorno = ll_add(pArrayListJugador, unJugador);
	}

    return retorno;
}

/** \brief Modificar datos del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_editarJugador(LinkedList* pArrayListJugador, LinkedList* pArraySeleciones)
{
	int retorno = 0;

	if(pArrayListJugador != NULL && pArraySeleciones != NULL)
	{
		retorno = ModificarJugador(pArrayListJugador, pArraySeleciones);
	}

    return retorno;
}

/** \brief Baja del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_removerJugador(LinkedList* pArrayListJugador, LinkedList* pArraySeleciones)
{
	int retorno = 0;

	if(pArrayListJugador != NULL && pArraySeleciones != NULL)
	{
		retorno = BajaDeJugador(pArrayListJugador, pArraySeleciones);
	}

    return retorno;
}

/** \brief Listar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_listarJugadores(LinkedList* pArrayListJugador, LinkedList* pArraySeleciones)
{
	int retorno;

	if(pArrayListJugador != NULL && pArraySeleciones != NULL)
	{
		retorno = MostrarListaJugadores(pArrayListJugador, pArraySeleciones);
	}

    return retorno;
}

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador)
{
	int retorno;
	FILE* pFile;

	pFile = fopen(path, "w");

	retorno = parser_saveTextJugadores(pFile, pArrayListJugador);

	fclose(pFile);

    return retorno;
}

/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador)
{
	int retorno = 0;
	FILE* pArchivo;

	if(path != NULL && pArrayListJugador != NULL)
	{
		pArchivo = fopen(path, "wb");

		retorno = parser_saveJugadoresBinary(pArchivo, pArrayListJugador);

		fclose(pArchivo);
	}

    return retorno;
}

int controller_guardarSeleccionesModoBinario(char* path , LinkedList* pArrayListSelecciones)
{
	int retorno = 0;
	FILE* pArchivo;

	if(path != NULL && pArrayListSelecciones != NULL)
	{
		pArchivo = fopen(path, "wb");

		retorno = parser_saveSeleccionesBinary(pArchivo, pArrayListSelecciones);

		fclose(pArchivo);
	}

    return retorno;
}

int controller_guardarArchivosModoBinario(char* pathJug , LinkedList* pArrayListJugador, char* pathSel, LinkedList* pArraySelecciones)
{
	int retorno = 0;

	if(controller_guardarJugadoresModoBinario(pathJug, pArrayListJugador) && controller_guardarSeleccionesModoBinario(pathSel, pArraySelecciones))
	{
		retorno = 1;
	}

	return retorno;
}

/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion)
{
	int retorno = 0;
	FILE* pArchivo;

	pArchivo = fopen(path, "r");

	retorno = parser_SeleccionFromText(pArchivo, pArrayListSeleccion);

	fclose(pArchivo);

    return retorno;
}

int controller_cargarSeleccionesDesdeBinario(char* path , LinkedList* pArrayListSeleccion)
{
	int retorno = 0;
	FILE* pArchivo;

	pArchivo = fopen(path, "rb");

	retorno = parser_SeleccionFromBinary(pArchivo, pArrayListSeleccion);

	fclose(pArchivo);

    return retorno;
}

/** \brief Listar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_listarSelecciones(LinkedList* pArrayListSeleccion)
{
	int retorno;

	if(pArrayListSeleccion != NULL)
	{
		retorno = MostrarListaSelecciones(pArrayListSeleccion);
	}

    return retorno;
}

int controller_cargarArchivosDesdeTexto(char* path , LinkedList* pArrayListJugadores, char* path2 , LinkedList* pArrayListSelecciones)
{
	int retorno = 0;
	int retorno1;
	int retorno2;

	retorno1 = controller_cargarJugadoresDesdeTexto(path, pArrayListJugadores);
	retorno2 = controller_cargarSeleccionesDesdeTexto(path2, pArrayListSelecciones);

	if(retorno1 == 1 && retorno2 == 1)
	{
		retorno = 1;
	}

	return retorno;
}

int controller_convocarJugadores(LinkedList* pArrayListJugador, LinkedList* pArraySeleciones)
{
	int retorno;

	retorno = ConvocarJugadores(pArrayListJugador, pArraySeleciones);

	return retorno;
}

int controller_listarListados(LinkedList* pArrayListJugador, LinkedList* pArraySeleciones)
{
	int retorno;

	retorno = ListarListados(pArrayListJugador, pArraySeleciones);

	return retorno;
}

int controller_ordenarYListar(LinkedList* pArrayListJugador, LinkedList* pArraySeleciones)
{
	int retorno = 0;
	LinkedList* cloneJugadores = NULL;
	LinkedList* cloneSelecciones = NULL;

	if(pArrayListJugador != NULL && pArraySeleciones)
	{
		cloneJugadores = ll_clone(pArrayListJugador);
		cloneSelecciones = ll_clone(pArraySeleciones);

		if(cloneJugadores != NULL && cloneSelecciones != NULL)
		{
			retorno = OrdenarYListar(cloneJugadores, cloneSelecciones);
		}
	}

	ll_clear(cloneJugadores);
	ll_clear(cloneSelecciones);

	if(ll_isEmpty(cloneJugadores) && ll_isEmpty(cloneSelecciones))
	{
		ll_deleteLinkedList(cloneJugadores);
		ll_deleteLinkedList(cloneSelecciones);
	}

	return retorno;
}

