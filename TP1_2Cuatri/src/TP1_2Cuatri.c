/*
 ============================================================================
 Name        : TP1_2Cuatri.c
 Author      : Santiago Iannello
 Version     : 2
 Copyright   :
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "jugadores.h"
#include "calculos.h"

int main(void) {
	setbuf(stdout, NULL);

	int opcionElegida;
	int validar;
	float costoHospedaje = 0;
	float costoComida = 0;
	float costoTransporte = 0;
	int numeroCamiseta;
	int contadorArqueros = 0;
	int contadorDefensores = 0;
	int contadorMediocampistas = 0;
	int contadorDelanteros = 0;
	int contadorUefa = 0;
	int contadorConmebol = 0;
	int contadorConcacaf = 0;
	int contadorAfc = 0;
	int contadorOfc = 0;
	int contadorCaf = 0;
	float promedioUefa;
	float promedioConmebol;
	float promedioConcacaf;
	float promedioAfc;
	float promedioOfc;
	float promedioCaf;
	float costoDeMantenimientoTotal;
	float aumento;
	float costoDeMantenimientoBruto;
	int flag1 = 0;
	int flag2 = 0;
	int flag3 = 0;

	do
	{
		opcionElegida = ElegirOpcion(&costoHospedaje, &costoComida, &costoTransporte, &contadorArqueros, &contadorDefensores, &contadorMediocampistas, &contadorDelanteros);

		switch(opcionElegida)
			{
				case 1:
					validar = PedirCostos(&costoHospedaje, &costoComida, &costoTransporte);
					if(validar == 1)
					{
						printf("Funcionó correctamente.\n");
						flag1 = 1;
					}
					else
					{
						printf("Hubo un error...\n");
					}
				break;
				case 2:
					validar = PedirJugador(&numeroCamiseta, &contadorArqueros, &contadorDefensores, &contadorMediocampistas, &contadorDelanteros, &contadorUefa, &contadorConmebol, &contadorConcacaf, &contadorAfc, &contadorOfc, &contadorCaf);
					if(validar == 1)
					{
						printf("Funcionó correctamente.\n");
						flag2 = 1;
					}
					else
					{
						printf("Hubo un error...\n");
					}
				break;
				case 3:
					if(flag1 == 1 && flag2 == 1)
					{
						RealizarCalculos(&costoHospedaje, &costoComida, &costoTransporte, &contadorUefa, &contadorConmebol, &contadorConcacaf, &contadorAfc, &contadorOfc, &contadorCaf, &promedioUefa, &promedioConmebol, &promedioConcacaf, &promedioAfc, &promedioOfc, &promedioCaf, &costoDeMantenimientoTotal, &aumento, &costoDeMantenimientoBruto);
						flag3 = 1;
						printf("Se han realizado los calculos.\n");
					}
					else
					{
						printf("Se debera primero entrar a las opciones 1 y 2 para poder ingresar a la opcion 3.\n");
					}
				break;
				case 4:
					if(flag3 == 1)
					{
						InformarResultados(&promedioUefa, &promedioConmebol, &promedioConcacaf, &promedioAfc, &promedioOfc, &promedioCaf, &costoDeMantenimientoTotal, &aumento, &costoDeMantenimientoBruto);
					}
					else
					{
						printf("Se debera primero entrar a las opciones 1, 2 y 3 para poder ingresar a la opcion 4\n");
					}
				break;
			}

	}while(opcionElegida != 5);

	return 0;
}


