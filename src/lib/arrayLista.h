#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <time.h>
#include "../config/files.h"
#include "habitacion.h"
#include "caracteristicas.h"
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

///                                     PROTOTIPADO
NodoPiso *iniclista();
NodoPiso *crearNodo(stRegHabitacion DATO);
NodoPiso *agregarALista(NodoPiso *lista, NodoPiso *DATO);
void CargarArray(stDeCelda ARRAY[]);
stDeCelda insertar(stDeCelda array[], stRegHabitacion aux, int posicion);
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
stCaracteristicas insertarPrecio(stCaracteristicas ARRAY[], stCaracteristicas aux, int posicion);
void CargarArrayPecios(stCaracteristicas ARRAY[]);
void mostrarArrayPrecios(stCaracteristicas ARRAY[]);
