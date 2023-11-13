#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

///ESTRUCTURA DE LA LISTA SECUNDARIA DE SERVICIO

typedef struct NodoS{

    char Subservicio[25];
    struct NodoS*siguiente;

}NodoS;

///ESTRUCTURA DE LA LISTA PRINCIPAL DE SERVICIO

typedef struct NodoP{

    char Servicio[25];
    NodoS * lista;
    struct NodoP*siguiente;

}NodoP;

///PROTOTIPADO DE LAS LISTAS

///LISTA PRINCIPAL

NodoP * InicListaPrincipal();
NodoP * CrearNodoServicio(char Servicio[]);

///LISTA SECUNDARIA

NodoS * InicListaSecundaria();
NodoS * CrearNodoSubservicio(char Subservicio[]);


int main()
{


    return 0;
}

///FUNCION PARA INICIALIZAR LA LISTA PRINCIPAL

NodoP * InicListaPrincipal(){

return NULL;
}

///FUNCION PARA INICIALIZAR LA LISTA SECUNDARIA

NodoS * InicListaSecundaria(){

return NULL;
}

///FUNCION PARA CREAR UN NODO DE LA LISTA PRINCIPAL

NodoP * CrearNodoServicio(char Servicio[]){

    NodoP*nuevo = (NodoP*)malloc(sizeof(NodoP));

    nuevo->lista = InicListaSecundaria();
    strcpy(nuevo->Servicio,Servicio);
    nuevo->siguiente = NULL;

return nuevo;
}

///FUNCION PARA CREAR UN NODO DE LA LISTA SECUNDARIA

NodoS * CrearNodoSubservicio(char Subservicio[]){

    NodoS*nuevo = (NodoS*)malloc(sizeof(NodoS));

    nuevo->siguiente = NULL;
    strcpy(nuevo->Subservicio,Subservicio);

return nuevo;
}

///FUNCION PARA AGREGAR UN SERVICIO AL INICIO DE LA LISTA


