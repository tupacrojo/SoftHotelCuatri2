#pragma once
#include <stdio.h>
#include "config/files.h"
#include "caracteristicas.h"


typedef struct ///  "stRegHabitacion" habitacion
{
    int id;
    int borrado;
    int estado;  // 0 libre; 1 Ocupado;
    int piso;   // pisos
    stRegCaracteristicas caracteristicas[10];// este arreglo puede almacenar
}stRegHabitacion;

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
