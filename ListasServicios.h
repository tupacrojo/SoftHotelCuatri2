#ifndef LISTASSERVICIOS_H_INCLUDED
#define LISTASSERVICIOS_H_INCLUDED

///LIBRERIAS NECESARIAS

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

///ESTRUCTURA SUB SERVICIO

typedef struct{

    int IdServicio;
    char SubServicio[25];
    float Precio;

}StSubServicio;

///ESTRUCTURAS DE SERVICIOS

typedef struct{

    int Id;
    int Piso;
    float Precio;
    char Servicio[25];

}StServicio;

///ESTRUCTURA DE LA LISTA SECUNDARIA DE SERVICIO

typedef struct NodoS{

    StSubServicio Dato;
    struct NodoS*siguiente;

}NodoS;

///ESTRUCTURA DE LA LISTA PRINCIPAL DE SERVICIO

typedef struct NodoP{

    StServicio Dato;
    NodoS * lista;
    struct NodoP*siguiente;

}NodoP;

///PROTOTIPADO DE LAS LISTAS

///LISTA PRINCIPAL

void Pause();
NodoP * InicListaPrincipal();
NodoP * CrearNodoServicio(StServicio Dato);
NodoP * AgregarAlPcpioListaServicio (NodoP* lista, NodoP* nuevo);
NodoP * InsertarOrdenadoListaServicio (NodoP* lista,NodoP* nuevo);
NodoP * BuscarServicio(NodoP * lista, char Servicio[]);
NodoP * BorrarUnNodo(NodoP*lista,char Servicio[]);
void MostrarListaCompuesta(NodoP*lista);
void MostrarUnServicio(StServicio Dato);
void MostrarListaServicio(NodoP*lista);

///LISTA SECUNDARIA

NodoS * InicListaSecundaria();
NodoS * CrearNodoSubservicio(StSubServicio Dato);
NodoS * AgregarAlPcpioListaSubservicio (NodoS* lista, NodoS* nuevo);
NodoS * BuscarServicioAdicional(NodoS*lista,char Servicio[]);
NodoS * BorrarUnNodoAdicional(NodoS*lista,char Servicio[]);
void MostrarListaSubServicio(NodoS*lista);
void MostrarUnSubServicio(StSubServicio Dato);

#endif // LISTASSERVICIOS_H_INCLUDED
