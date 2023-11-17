#ifndef LISTASSERVICIOS_H_INCLUDED
#define LISTASSERVICIOS_H_INCLUDED

/// LIBRERIAS NECESARIAS

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

/// ESTRUCTURA SUB SERVICIO

typedef struct
{

    char SubServicio[25];
    float Precio;

} StSubServicio;

/// ESTRUCTURAS DE SERVICIOS

typedef struct
{

    int Piso;
    float Precio;
    char Servicio[25];

} StServicio;

/// ESTRUCTURA DE LA LISTA SECUNDARIA DE SERVICIO

typedef struct NodoS
{

    StSubServicio Dato;
    struct NodoS *siguiente;

} NodoS;

/// ESTRUCTURA DE LA LISTA PRINCIPAL DE SERVICIO

typedef struct NodoP
{

    StServicio Dato;
    NodoS *lista;
    struct NodoP *siguiente;

} NodoP;

/// PROTOTIPADO DE LAS LISTAS

/// LISTA PRINCIPAL

void Pause();
NodoP *InicListaPrincipal();
NodoP *CrearNodoServicio(StServicio Dato);
NodoP *AgregarAlPcpioListaServicio(NodoP *lista, NodoP *nuevo);
NodoP *InsertarOrdenadoListaServicio(NodoP *lista, NodoP *nuevo);
NodoP *BuscarServicio(NodoP *lista, char Servicio[]);
void MostrarListaServicio(NodoP *lista);
void MostrarUnServicio(StServicio Dato);
NodoP *BorrarUnNodo(NodoP *lista, char Servicio[]);

/// LISTA SECUNDARIA

NodoS *InicListaSecundaria();
NodoS *CrearNodoSubservicio(StSubServicio Dato);
NodoS *AgregarAlPcpioListaSubservicio(NodoS *lista, NodoS *nuevo);
void MostrarListaSubServicio(NodoS *lista);
void MostrarUnSubServicio(StSubServicio Dato);

#endif // LISTASSERVICIOS_H_INCLUDED
