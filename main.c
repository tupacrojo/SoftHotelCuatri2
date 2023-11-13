#include <stdio.h>
#include <stdlib.h>
#include "reserva.h"
#include <string.h>

typedef struct nodoLD
{
    stReserva reserva;
    struct nodoLD *sig;
    struct nodoLD *ant;
} nodoLD;

nodoLD *inicListaDoble()
{
    return NULL;
}

// Función para crear un nuevo nodo
nodoLD* crearNodo(stReserva dato) {
    nodoLD* nuevoNodo = (nodoLD*)malloc(sizeof(nodoLD));
    nuevoNodo->reserva = dato;
    nuevoNodo->sig = NULL;
    nuevoNodo->ant = NULL;
    return nuevoNodo;
}

// Función para insertar un nodo al principio de la lista
nodoLD* insertarAlPrincipio(nodoLD* lista, stReserva dato) {
    nodoLD* nuevoNodo = crearNodo(dato);
    nuevoNodo->sig = lista;
    if (lista != NULL) {
        (lista)->ant = nuevoNodo;
    }
    lista = nuevoNodo;
    return lista;
}

// Función para insertar un nodo al final de la lista
nodoLD *insertarAlFinal(nodoLD* lista, stReserva dato) {
    nodoLD* nuevoNodo = crearNodo(dato);
    nodoLD* ultimo = lista;
    if (lista == NULL) {
        lista = nuevoNodo;
        return;
    }
    while (ultimo->sig != NULL) {
        ultimo = ultimo->sig;
    }
    ultimo->sig = nuevoNodo;
    nuevoNodo->ant = ultimo;
    return lista;
}

void mostrarCaracteristicasHabitacion(stRegHabitacion h)
{
    int i = 0;
    while( strcmp(h.caracteristicas[i].tipo,"") == 0 )
    {
        printf("%s\n", h.caracteristicas[i].tipo);
        i++;
    }
}

void mostrarReserva(stReserva r)
{
    puts("------------------------------------------------");
    printf(" D%ca de Entrada     : %i\n", 161, r.diaEntrada);
    printf(" Mes de Entrada     : %i\n", r.mesEntrada);
    printf(" A%co de Entrada     : %i\n", 164, r.anioEntrada);
    printf(" D%ca de Salida      : %i\n", 161, r.diaSalida);
    printf(" Mes de Sal%cda      : %i\n", 161, r.mesSalida);
    printf(" A%co de Salida      : %i\n", 164, r.anioSalida);
    printf(" Caracteristicas de Habitaci%cn :\n", 162);
    mostrarCaracteristicasHabitacion(r.habitacion);
    puts("------------------------------------------------");
}


// Función para imprimir la lista desde el principio
void imprimirDesdePrincipio(nodoLD* cabeza) {
    while (cabeza != NULL) {
        printf("%d ", cabeza->reserva);
        cabeza = cabeza->sig;
    }
}

// Función para imprimir la lista desde el final
void imprimirDesdeFinal(nodoLD* lista) {
    nodoLD* ultimo = inicListaDoble();
    while (lista != NULL) {
        ultimo = lista;
        lista = lista->sig;
    }
    while (ultimo != NULL) {
        printf("%d ", ultimo->reserva);
        ultimo = ultimo->ant;
    }
}


int main()
{
    printf("Hello world!\n");
    return 0;
}
