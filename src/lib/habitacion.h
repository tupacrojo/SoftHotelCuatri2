#pragma once
#include <stdio.h>
#include "../config/files.h"

/// ESTRUCTURA DE CARACTERISTICAS

typedef struct
{
    int id;
    int borrado;
    char tipo[30];

} stRegCaracteristicas;

/// ESTRUCTURA DE HABITACIONES

typedef struct
{

    int id;
    int borrado;
    int estado;
    int piso;
    stRegCaracteristicas caracteristicas[10];
} stRegHabitacion;


int obtenerUltimoIdHabitaciones();
stRegHabitacion extraerHabitacion(int id);

/*
Pila buscarHabitacionTipo(char tipo[]);
*/

void agregarHabitacion(stRegHabitacion *a);
void agregarHabitacionArchivo();
void agregarHabitacionArchivo2(stRegHabitacion a);
stRegHabitacion agregarHabitacionPorParametro(int id, int piso, int tipo);

int borrarHabitacion(int id);
void borraDatosHabitacion(stRegHabitacion *a);
/*
void mostrarHabitacionTipo(Pila p);
*/
void mostrarHabitacion(stRegHabitacion a);
void mostrarHabitaciones();

int cambiarDatosDeHabitacion(int selector, int id);
void cambiarBorradoHabitacion(int id);
int cambiarTipoHabitacion(int id, char nuevoTipo[]);
int cambiarEstadoHabitacion(int id, int nuevoEstado);
int cambiarPisoHabitacion(int id, int nuevoPiso);
