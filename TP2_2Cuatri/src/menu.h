/*
 * menu.h
 *
 *  Created on: 15 sep. 2022
 *      Author: Santiago
 */

#ifndef MENU_H_
#define MENU_H_

#include "utn.h"

/// @brief Muestra el menu principal.
void MenuPrincipal();

/// @brief Permite al usuario ingresar una opcion del menu.
/// @param max Recibe el numero maximo que se puede ingresar para luego validar lo que se ingresó.
/// @param min Recibe el numero minimo que se puede ingresar para luego validar lo que se ingresó.
/// @return Retorna la opcion ingresada por el usuario.
int ElegirOpcion(int max, int min);

/// @brief Muestra el menu de informes.
void MenuInformes();

#endif /* MENU_H_ */
