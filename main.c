#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

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

typedef struct /// "stUsuario" usuario
{
    int id;   // auto incrementable
    int borrado;
    int tipo; // GodMan(), administrador(sueldos, dar de alta y baja empleado), recepcionista(Check In, Check Out), Huesped(consumos)
    char contrasena[20];
    char nombre[50]; // lo que va antes del apellido
    char apellido[50];
    char DNI[10];
    float totalconsumo;
    stReserva reserva;
    int edad; // a os
    char telefono[20];
    char genero; // m = masculino , f = femenino, o = otros
    int hijos;
    char estadoCivil[20]; // 0 soltero, 1 divorciado, 2 viudo, 3 casado
}stUsuario;

typedef struct //este es la estructura que alamcena las caracteristicas de la habitacion
{
    int id;
    int borrado;
    char tipo[30]; // vista al mar, cama matrinomial, perroincluido
}stRegCaracteristicas;

typedef struct ///  "stRegHabitacion" habitacion
{
    int id;
    int borrado;
    int estado;  // 0 libre; 1 Ocupado;
    int piso;   // pisos
    stRegCaracteristicas caracteristicas[10];// este arreglo puede almacenar
}stRegHabitacion;

typedef struct ///  "stConsumibles" elementos disponibles para consumo
{
    int id;
    int borrado;
    char nombre[50];
    char categoria[50]; // Bebible, Comestible, Servicios
    float precio;
}stConsumibles;

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


