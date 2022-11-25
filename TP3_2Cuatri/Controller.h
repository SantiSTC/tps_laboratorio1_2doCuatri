#include <stdio.h>
#include <stdlib.h>
#include "Jugador.h"
#include "Seleccion.h"
#include "LinkedList.h"
#include "parser.h"

int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador);
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador);
int controller_agregarJugador(LinkedList* pArrayListJugador, LinkedList* pArraySeleciones);
int controller_editarJugador(LinkedList* pArrayListJugador, LinkedList* pArraySeleciones);
int controller_removerJugador(LinkedList* pArrayListJugador, LinkedList* pArraySeleciones);
int controller_listarJugadores(LinkedList* pArrayListJugador, LinkedList* pArraySeleciones);
int controller_ordenarJugadores(LinkedList* pArrayListJugador);
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador);
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador);
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion);
int controller_editarSeleccion(LinkedList* pArrayListSeleccion);
int controller_listarSelecciones(LinkedList* pArrayListSeleccion);
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion);
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion);
int controller_cargarArchivosDesdeTexto(char* path , LinkedList* pArrayListJugadores, char* path2 , LinkedList* pArrayListSelecciones);
int controller_listarListados(LinkedList* pArrayListJugador, LinkedList* pArraySeleciones);
int controller_convocarJugadores(LinkedList* pArrayListJugador, LinkedList* pArraySeleciones);
int controller_ordenarYListar(LinkedList* pArrayListJugador, LinkedList* pArraySeleciones);
int controller_cargarArchivosDesdeBinario(char* pathJug , LinkedList* pArrayListJugador, char* pathSel, LinkedList* pArraySelecciones);
int controller_cargarSeleccionesDesdeBinario(char* path , LinkedList* pArrayListSeleccion);
int controller_guardarArchivosModoBinario(char* pathJug , LinkedList* pArrayListJugador, char* pathSel, LinkedList* pArraySelecciones);
