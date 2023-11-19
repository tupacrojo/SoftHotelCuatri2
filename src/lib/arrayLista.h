#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <time.h>
#include "../config/files.h"

typedef struct
{
    int id;
    char caracteristicas[25];
    int ocupado;
    int cantCamas;
    char tipoDeCama[13]; // simple, matrimonial o combinada
} habitacion;

typedef struct
{
    habitacion DATOS;
    struct NodoPiso *siguiente;
} NodoPiso;

typedef struct
{
    int idPiso;
    NodoPiso *lista;
} stDeCelda;

typedef struct
{
    int id;
    int ocupado;              /// 1 si 0 no
    char caracteristicas[25]; /// vista al mar, balcon, Espaciosa
    int cantCamas;
    char tipoDeCama[13]; /// simple, matrimonial o combinada
    int idPiso;
} archivo;

typedef struct
{
    char caracteristica[25];
    char tipoCama[13];
    int precio;
} ArchivoPrecios;

///                                     PROTOTIPADO
NodoPiso *iniclista();
NodoPiso *crearNodo(archivo DATO);
NodoPiso *agregarALista(NodoPiso *lista, NodoPiso *DATO);
void CargarArray(stDeCelda ARRAY[]);
stDeCelda insertar(stDeCelda array[], archivo aux, int posicion);
void FuncionPrincipal();
void CargarArchi(FILE *archi);
void mostrar(FILE *archi);
void mostrarLista(NodoPiso *lista);
void mostrarArrayCompleto(stDeCelda ARRAY[]);
void iniciallizarTodo(stDeCelda ARRAY[]);
int validacionDeString(char caracteristica[]);
int validacionDeCamas(char caracteristica[]);
void CargarArchiPrecios(FILE *archi);
void funcion2();
ArchivoPrecios insertarPrecio(ArchivoPrecios ARRAY[], ArchivoPrecios aux, int posicion);
void CargarArrayPecios(ArchivoPrecios ARRAY[]);
void mostrarArrayPrecios(ArchivoPrecios ARRAY[]);
