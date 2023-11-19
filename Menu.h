#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

///LIBRERIAS DE CODEBLOCKS

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

///LIBRERIAS PARA LISTA DE LISTAS

#include "ArchivoServicios.h"
#include "ListasServicios.h"
#include "StCompuestaServicios.h"

///FUNCIONES DE MENU

void Menu();
void MenuServicios();
void MenuSubServicio(NodoP*lista);
void MenuServAdicional();

///FUNCIONES

void Funcion1(NodoP*lista);
void Funcion2(NodoP*lista);
void Funcion3(NodoP*lista);
void Funcion4(NodoP*lista);
void Funcion1B(NodoP*lista);
void Funcion2B(NodoP*lista);
void Funcion3B(NodoP*lista);
void Funcion4B(NodoP*lista);


#endif // MENU_H_INCLUDED
