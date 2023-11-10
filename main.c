#include <stdio.h>
#include <stdlib.h>

typedef struct {
int piso;
int cantidadHabitaciones;
int idHabitacion;
int cantidadHuesped;
int ocupado;
int habilitada;
}pisoRegistro;

typedef struct {
    int idHabitacion;
    int cantidadHuesped;
    int ocupado;
    int habilitada;
}stHabitacion;

typedef struct nodoListaHabitacion {
struct nodoListaHabitacion * sig;
stHabitacion dato;
}nodoListaHabitacion;

int main()
{
    int arregloDePisos[15] =cargarArregloDePisos();

    return 0;
}



