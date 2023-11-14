#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>



typedef struct {
    int id;
    char caracteristicas[25];
    int cantCamas;
    char tipoDeCama[13]; // simple, matrimonial o combinada
}habitacion;

typedef struct {
    habitacion DATOS;

    struct NodoPiso * siguiente;
}NodoPiso;

typedef struct {
    int idPiso;
    NodoPiso * lista;
}stDeCelda;

typedef struct {
    int id;
    char caracteristicas[25];
    int cantCamas;
    char tipoDeCama[13]; // simple, matrimonial o combinada
    int idPiso;
}archivo;





int main()
{




    return 0;
}


NodoPiso * iniclista (){
    return NULL;
}

NodoPiso * crearNodo (habitacion DATO){
    NodoPiso * aux = (NodoPiso *) malloc(sizeof (NodoPiso));

    aux->DATOS = DATO;
    aux->siguiente = NULL;
return aux;
}

NodoPiso * agregarALista(NodoPiso * lista, NodoPiso * DATO){
    if (lista == NULL){
        lista = DATO;
    }else{
        DATO->siguiente = lista;
        lista = DATO;
    }
return lista;
}


