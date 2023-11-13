#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

///ESTRUCTURA DE CARACTERISTICAS

typedef struct{

    int id;
    int borrado;
    char tipo[30];

}stRegCaracteristicas;

///ESTRUCTURA DE HABITACIONES

typedef struct{

    int id;
    int borrado;
    int estado;
    int piso;
    stRegCaracteristicas caracteristicas[10];

}stRegHabitacion;

///ESTRUCTURA DE LA RESERVA

typedef struct{

    stRegHabitacion habitacion;
    int borrado;
    /// ENTRADA
    int diaEntrada;
    int mesEntrada;
    int anioEntrada;
    /// SALIDA
    int diaSalida;
    int mesSalida;
    int anioSalida;

}stReserva;

///ESTRUCTURA DE USUARIO

typedef struct{

    int id;
    int borrado; ///PREGUNTAR
    int tipo;
    char contrasena[20];
    char nombre[50];
    char apellido[50];
    char DNI[10];
    float totalconsumo;
    stReserva reserva;
    int edad;
    char telefono[20];
    char genero;
    int hijos;
    char estadoCivil[20];

}stUsuario;

///ESTRUCTURA DE REGISTRO DE SERVICIOS

typedef struct{

    int IdServicio;
    char Servicio[25];
    char SubServicio[25];
    float Precio;

}StRegistroServicio;

///ESTRUCTURA SUB SERVICIO

typedef struct{

    int Borrado;
    char SubServicio[25];
    float Precio;

}StSubServicio;

///ESTRUCTURAS DE SERVICIOS

typedef struct{

    int IdServicio;
    int Borrado;
    char Servicio[25];

}StServicio;

///ESTRUCTURA DE LA LISTA SECUNDARIA DE SERVICIO

typedef struct NodoS{

    StSubServicio Dato;
    struct NodoS*siguiente;

}NodoS;

///ESTRUCTURA DE LA LISTA PRINCIPAL DE SERVICIO

typedef struct NodoP{

    StServicio Dato;
    NodoS * lista;
    struct NodoP*siguiente;

}NodoP;

///PROTOTIPADO DE LAS LISTAS

///LISTA PRINCIPAL

NodoP * InicListaPrincipal();
NodoP * CrearNodoServicio(StServicio Dato);
NodoP * AgregarAlPcpioListaServicio (NodoP* lista, NodoP* nuevo);

///LISTA SECUNDARIA

NodoS * InicListaSecundaria();
NodoS * CrearNodoSubservicio(StSubServicio Dato);
NodoS * AgregarAlPcpioListaSubservicio (NodoS* lista, NodoS* nuevo);

///FUNCIONES DE ESTRUCTURA COMPUESTA

NodoP* CargarListaServicioConArchivo(NodoP * lista);
NodoP* BuscarServicio(NodoP * lista, char Servicio[]);


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

NodoP * CrearNodoServicio(StServicio Dato){

    NodoP*nuevo = (NodoP*)malloc(sizeof(NodoP));

    nuevo->lista = InicListaSecundaria();
    nuevo->Dato =  Dato;
    nuevo->siguiente = NULL;

return nuevo;
}

///FUNCION PARA CREAR UN NODO DE LA LISTA SECUNDARIA

NodoS * CrearNodoSubservicio(StSubServicio Dato){

    NodoS*nuevo = (NodoS*)malloc(sizeof(NodoS));

    nuevo->siguiente = NULL;
    nuevo->Dato = Dato;

return nuevo;
}

///FUNCION PARA AGREGAR UN SERVICIO AL INICIO DE LA LISTA

NodoP * AgregarAlPcpioListaServicio (NodoP* lista, NodoP* nuevo){

    if(lista == NULL){
        lista = nuevo;
    }else{
        nuevo->siguiente = lista;
        lista = nuevo;
    }
return lista;
}

///FUNCION PARA AGREGAR UN SUB SERVICIO AL INICIO DE LA LISTA

NodoS * AgregarAlPcpioListaSubservicio (NodoS* lista, NodoS* nuevo){

    if(lista == NULL){
        lista = nuevo;
    }else{
        nuevo->siguiente = lista;
        lista = nuevo;
    }
return lista;
}

///FUNCIONES PARA CARGAR DATOS DENTRO DE LA ESTRUCTURA COMPUESTA

///FUNCION PARA CARGAR LA LISTA CON LOS DATOS DEL ARCHIVO

NodoP* CargarListaServicioConArchivo(NodoP * lista){

    StRegistroServicio Aux;

    FILE * archi = fopen(Arreglo,"rb");

    if(archi!=NULL){
        while(fread(&Aux,sizeof(StRegistroServicio),1,archi)>0){
            lista = AltaDeRegistroServicio(lista,Aux);
        }

        fclose(archi);
    }else{
        printf("El archivo se abrio incorrectamente\n");
    }

return lista;
}


///FUNCION PARA DAR EL ALTA DE UN REGISTRO DE SERVICIOS

///FUNCION PARA BUSCAR UN SERVICIO

NodoP* BuscarServicio(NodoP * lista, char Servicio[]){

    NodoP*Aux = NULL;
    NodoP*seg = lista;

    while(seg != NULL && Aux == NULL){
        if(strcmpi(seg->Servicio,Servicio) == 0){
            Aux = seg;
        }
        seg = seg->siguiente;
    }

return Aux;
}


