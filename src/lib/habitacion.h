#pragma once
#include <stdio.h>
#include "../config/files.h"

/// ESTRUCTURA DE HABITACIONES

typedef struct
{
    int id;
    int ocupado;              /// 1 si 0 no
    char caracteristicas[25]; /// vista al mar, balcon, Espaciosa
    int cantCamas;
    char tipoDeCama[13]; /// simple, matrimonial o combinada
    int idPiso;
} stRegHabitacion;



int obtenerUltimoIdHabitaciones();
stRegHabitacion extraerHabitacion(int id);
void agregarHabitacion(stRegHabitacion *a);
void agregarHabitacionArchivo();
void agregarHabitacionArchivo2(stRegHabitacion a);
stRegHabitacion agregarHabitacionPorParametro(int id, int piso, int tipo);
int borrarHabitacion(int id);
void borraDatosHabitacion(stRegHabitacion *a);
void mostrarHabitacion(stRegHabitacion a);
void mostrarHabitaciones();
int cambiarDatosDeHabitacion(int selector, int id);
void cambiarBorradoHabitacion(int id);
int cambiarTipoHabitacion(int id, char nuevoTipo[]);
int cambiarEstadoHabitacion(int id, int nuevoEstado);
int cambiarPisoHabitacion(int id, int nuevoPiso);
