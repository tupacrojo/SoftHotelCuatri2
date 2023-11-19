#pragma once
#include <stdio.h>
#include <time.h>
#include "../config/files.h"
#include "habitacion.h"

typedef struct ///  "stReserva" reserva
{
    stRegHabitacion habitacion;
    int borrado;
    // entrada
    int diaEntrada;
    int mesEntrada;
    int anioEntrada;
    // salida
    int diaSalida;
    int mesSalida;
    int anioSalida;
}stReserva;

typedef struct nodoLD
{
    stReserva reserva;
    struct nodoLD *sig;
    struct nodoLD *ant;
} nodoLD;


int esFechaValida(int dia, int mes, int anio);
int esFechaPosterior(int dia, int mes, int anio);
int esFechaPosteriorA(int diaAn, int mesAn, int anioAn, int diaPos, int mesPos, int anioPos);
nodoLD *inicListaDoble();
nodoLD* crearNodoLd(stReserva dato);
nodoLD* insertarAlPrincipio(nodoLD* lista, stReserva dato);
nodoLD *insertarAlFinal(nodoLD* lista, stReserva dato);
nodoLD *cargarListaDobleArchivo(nodoLD * lista, char archivo[]);
void mostrarCaracteristicasHabitacion(stRegHabitacion h);
void mostrarReserva(stReserva r);
void imprimirDesdePrincipio(nodoLD* lista);
void imprimirDesdeFinal(nodoLD* lista);
