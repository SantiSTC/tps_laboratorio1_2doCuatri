#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "parser.h"
#include "funcionalidades.h"

int main()
{
	setbuf(stdout,NULL);
    int option;
    int retorno;
    int flagCargaArchivos = 0;
    int flagGuardado = 0;
    int opcionSalida;

    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaSelecciones = ll_newLinkedList();

    InicializarConvocados(listaSelecciones);

    do{
    	option = MenuPrincipal();

        switch(option)
        {
            case 1:
            	if(flagCargaArchivos == 0)
            	{
                	retorno = controller_cargarArchivosDesdeTexto("jugadores.csv", listaJugadores, "selecciones.csv", listaSelecciones);
                	if(retorno)
                	{
                		flagCargaArchivos = 1;
                		printf("\n=== Se ha cargado la lista correctamente ===\n");
                	}
                	else
                	{
                		printf("\n=== No se ha podido cargar la lista ===\n");
                	}
            	}
            	else
            	{
            		printf("\nYA SE HA CARGADO EL ARCHIVO...\n");
            	}
            break;
            case 2:
            	if(flagCargaArchivos == 1)
            	{
                	retorno = controller_agregarJugador(listaJugadores, listaSelecciones);
                	if(!retorno)
                	{
                		printf("\n=== Se ha agregado correctamente al jugador ===\n");
                	}
                	else
                	{
                		printf("\n=== No se ha podido agregar al jugador ===\n");
                	}
            	}
            	else
            	{
            		printf("Se debera cargar un archivo antes de ingresar a esta opcion...\n");
            	}
            break;
            case 3:
            	if(flagCargaArchivos == 1)
            	{
                	retorno = controller_editarJugador(listaJugadores, listaSelecciones);
                	if(retorno)
                	{
                		printf("\n=== Se ha modificado correctamente ===\n");
                	}
                	else
                	{
                		printf("\n=== No se ha podido modificar ===\n");
                	}
            	}
            	else
            	{
            		printf("Se debera cargar un archivo antes de ingresar a esta opcion...\n");
            	}
            break;
            case 4:
            	if(flagCargaArchivos == 1)
            	{
                	retorno = controller_removerJugador(listaJugadores, listaSelecciones);
                	if(!retorno)
                	{
                		printf("\n=== Se ha dado de baja correctamente ===\n");
                	}
                	else
                	{
                		printf("\n=== No se ha podido dar de baja ===\n");
                	}
            	}
            	else
            	{
            		printf("Se debera cargar un archivo antes de ingresar a esta opcion...\n");
            	}
            break;
            case 5:
            	if(flagCargaArchivos == 1)
            	{
                	retorno = controller_listarListados(listaJugadores, listaSelecciones);
                	if(retorno)
                	{
                		printf("\n=== Se ha listado correctamente ===\n");
                	}
                	else
                	{
                		printf("\n=== No se ha podido listar ===\n");
                	}
            	}
            	else
            	{
            		printf("Se debera cargar un archivo antes de ingresar a esta opcion...\n");
            	}
            break;
            case 6:
            	if(flagCargaArchivos == 1)
            	{
                	retorno = controller_convocarJugadores(listaJugadores, listaSelecciones);
                	if(retorno != 0)
                	{
                		printf("\n=== Ha funcionado correctamente ===\n");
                	}
                	else
                	{
                		printf("\n=== No ha funcionado ===\n");
                	}
            	}
            	else
            	{
            		printf("Se debera cargar un archivo antes de ingresar a esta opcion...\n");
            	}
            break;
            case 7:
            	if(flagCargaArchivos == 1)
            	{
                	retorno = controller_ordenarYListar(listaJugadores, listaSelecciones);
                	if(retorno)
                	{
                		printf("\n=== Se ha listado correctamente ===\n");
                	}
                	else
                	{
                		printf("\n=== No se ha podido listar ===\n");
                	}
            	}
            	else
            	{
            		printf("Se debera cargar un archivo antes de ingresar a esta opcion...\n");
            	}
            break;
            case 8:
            	if(flagCargaArchivos == 1)
            	{
            		retorno = controller_guardarArchivosModoBinario("jugadores.bin", listaJugadores, "selecciones.bin", listaSelecciones);
                	if(retorno)
                	{
                		printf("\n=== Se ha guardado correctamente ===\n");
                		flagGuardado = 1;
                	}
                	else
                	{
                		printf("\n=== No se han podido guardar los datos ===\n");
                	}
            	}
            	else
            	{
            		printf("Se debera cargar un archivo antes de ingresar a esta opcion...\n");
            	}
            break;
            case 9:
            	if(flagCargaArchivos == 0)
            	{
            		retorno = controller_cargarArchivosDesdeBinario("jugadores.bin", listaJugadores, "selecciones.bin", listaSelecciones);
                	if(retorno)
                	{
                		flagCargaArchivos = 1;
                		printf("\n=== Se ha cargado correctamente ===\n");
                	}
                	else
                	{
                		printf("\n=== No se ha podido cargar la lista ===\n");
                	}
            	}
            	else
            	{
            		printf("\nYA SE HA CARGADO EL ARCHIVO...\n");
            	}
            break;
            case 10:
            	if(flagCargaArchivos == 1)
            	{
                	retorno = controller_guardarJugadoresModoTexto("jugadores.csv", listaJugadores);
                	if(retorno)
                	{
                		printf("\n=== Se ha guardado correctamente ===\n");
                		flagGuardado = 1;
                	}
                	else
                	{
                		printf("\n=== No se han podido guardar los datos ===\n");
                	}
            	}
            	else
            	{
            		printf("Se debera cargar un archivo antes de ingresar a esta opcion...\n");
            	}
            break;
            case 11:
            	if(flagGuardado == 1)
            	{
            		printf("\nFinalizando programa...\n");
            		option = 12;
            	}
            	else
            	{
            		printf("�Esta seguro que desea salir sin guardar?\n"
            				"1. Si, salir sin guardar\n"
            				"2. No, deseo guardar antes de salir\n");
            		opcionSalida = ElegirOpcion(2, 1);

            		if(opcionSalida == 1)
            		{
                		printf("\nFinalizando programa...\n");
                		option = 12;
            		}
            		else
            		{
            			break;
            		}

            	}
            break;
        }

    }while(option != 12);

    printf("< PROGRAMA FINALIZADO >\n");

    return 0;
}

