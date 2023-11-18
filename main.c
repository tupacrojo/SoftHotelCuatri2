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

int main()
{
    ///CargarUnArchivo();
    MostrarUnArchivoServicios();
    MenuServicios();

    return 0;
}

///FUNCIONES PARA EL MENU DE SERVICIOS

void MenuServicios(){

    int op;

    NodoP*lista = InicListaPrincipal();
    lista = CargarListaServicioConArchivo(lista);

    Menu();
    printf("\nIngrese una opcion: ");
    scanf("%d",&op);
    Pause();

    switch(op){

        case 1:
            Funcion1(lista);
            break;
        case 2:
            Funcion2(lista);
            break;
        case 3:
            Funcion3(lista);
            break;
        case 4:
            Funcion4(lista);
            break;
        case 5:
            MenuSubServicio(lista);
            break;
        default:
            break;
    }
}

void Menu(){

    printf("1. Visualizar todos los servicios\n");
    printf("2. Cargar un nuevo servicio\n");
    printf("3. Borrar un servicio\n");
    printf("4. Modificar un servicio por valor unitario\n");
    printf("5. Menu de servicios adicionales\n");

}

///FUNCION 1

void Funcion1(NodoP*lista){

    MostrarListaServicio(lista);
}

///FUNCION 2

void Funcion2(NodoP*lista){

    lista = CargarDatoListaServicios(lista);
    Pause();
    MostrarListaServicio(lista);
}

///FUNCION 3

void Funcion3(NodoP*lista){

    lista = BorrarUnDatoServicio(lista);
    printf("El dato se encontro y se borro correctamente, a continuacion la lista modificada: ");
    Pause();
    MostrarListaServicio(lista);

}

///FUNCION 4

void Funcion4(NodoP*lista){

    lista = ModificarServicioPrincipal(lista);

}

///FUNCION 5

void MenuSubServicio(NodoP*lista){

    int op;

    MenuServAdicional();
    printf("\nIngrese una opcion: ");
    scanf("%d",&op);
    Pause();

    switch(op){

        case 1:
            Funcion1B(lista);
            break;
        case 2:
            Funcion2B(lista);
            break;
        case 3:
            Funcion3B(lista);
            break;
        case 4:
            Funcion4B(lista);
            break;
        default:
            break;
    }
}

///FUNCION MENU SUBSERVICIO

void MenuServAdicional(){

    printf("1. Visualizar todos los servicios adicionales\n");
    printf("2. Cargar un nuevo servicio adicional\n");
    printf("3. Borrar un servicio adicional\n");
    printf("4. Modificar un servicio adicional por valor unitario\n");

}

///FUNCION 1B

void Funcion1B(NodoP*lista){

    MostrarListaCompuesta(lista);
}

///FUNCION 2B

void Funcion2B(NodoP*lista){

    lista = CargarNuevoSubServicio(lista);
    MostrarListaCompuesta(lista);
    MostrarUnArchivoServicios();
}

///FUNCION 3B

void Funcion3B(NodoP*lista){

    lista = BorrarUnDatoServicioAdicional(lista);
    MostrarListaCompuesta(lista);
    MostrarUnArchivoServicios();
}

///FUNCION 4B

void Funcion4B(NodoP * lista){

    lista = ModificarServicioAdicional(lista);
    MostrarUnArchivoServicios();
}

