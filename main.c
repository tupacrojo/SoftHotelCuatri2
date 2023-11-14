#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

char NOMBRE[] = {"caracteristicasDeLasHabitaciones"};

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

///                                     PROTOTIPADO
stDeCelda insertar (stDeCelda array[], archivo aux,int posicion);




int main()
{

    return 0;
}


NodoPiso * iniclista (){
    return NULL;
}

NodoPiso * crearNodo (archivo DATO){
    NodoPiso * aux = (NodoPiso *) malloc(sizeof (NodoPiso));

    aux->DATOS.cantCamas = DATO.cantCamas;
    strcpy (aux->DATOS.caracteristicas , DATO.caracteristicas);
    aux->DATOS.id = DATO.id;
    strcpy (aux->DATOS.tipoDeCama,DATO.tipoDeCama);

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


void CargarArray (stDeCelda ARRAY[]){
    FILE * archi = fopen (NOMBRE,"rb");
    archivo aux;

    while (fread(&aux,sizeof(archivo),1,archi)>0){
       ARRAY[aux.idPiso-1] = insertar(ARRAY,aux,aux.idPiso-1);
    }

    fclose(archi);
}


stDeCelda insertar (stDeCelda array[], archivo aux,int posicion){
    if (array[posicion].lista == NULL){
        array[posicion].lista = crearNodo(aux);
    }else{
        NodoPiso * NuevoNodo = crearNodo(aux);

        NuevoNodo ->siguiente = array[posicion].lista;
        array[posicion].lista = NuevoNodo;
    }
return array[posicion];
}


void FuncionPrincipal (){
    stDeCelda PISOS [12];

    CargarArray(PISOS);

}

