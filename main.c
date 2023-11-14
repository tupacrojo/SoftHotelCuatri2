#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

///VARIABLE GLOBAL

const char Arreglo[40] = "NombreArchivo.bin";

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
NodoP * InsertarOrdenadoListaServicio (NodoP* lista,NodoP* nuevo);
void MostrarListaServicio(NodoP*lista);
void MostrarUnServicio(StServicio Dato);

///LISTA SECUNDARIA

NodoS * InicListaSecundaria();
NodoS * CrearNodoSubservicio(StSubServicio Dato);
NodoS * AgregarAlPcpioListaSubservicio (NodoS* lista, NodoS* nuevo);
void MostrarListaSubServicio(NodoS*lista);
void MostrarUnSubServicio(StSubServicio Dato);

///FUNCIONES DE ESTRUCTURA COMPUESTA

NodoP* CargarListaServicioConArchivo(NodoP * lista);
NodoP* BuscarServicio(NodoP * lista, char Servicio[]);
NodoP * AltaDeRegistroServicio (NodoP * lista, StRegistroServicio Aux);
StServicio CargarUnServicio (StRegistroServicio Aux);
StSubServicio CargarUnSubservicio (StRegistroServicio Aux);

///FUNCIONES PARA EL ARCHIVO

void CargarUnArchivo();
void MostrarUnArchivo();
void MostrarUnRegistro(StRegistroServicio Aux);
StRegistroServicio CargarUnRegistro();



int main()
{
    ///CargarUnArchivo();
    ///MostrarUnArchivo();
    NodoP*lista = InicListaPrincipal();

    lista = CargarListaServicioConArchivo(lista);
    MostrarListaServicio(lista);

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

///FUNCION PARA INSERTAR ORDENADO UN SERVICIO

NodoP * InsertarOrdenadoListaServicio (NodoP* lista,NodoP* nuevo){

    if(lista == NULL){
        lista = nuevo;
    }else{
        if(nuevo->Dato.IdServicio < lista->Dato.IdServicio){
            lista = AgregarAlPcpioListaServicio(lista,nuevo);
        }else{
            NodoP*ante = lista;
            NodoP*seg = lista->siguiente;

            while(seg!=NULL && seg->Dato.IdServicio < nuevo->Dato.IdServicio){
                ante = seg;
                seg = seg->siguiente;
            }
            nuevo->siguiente = seg;
            ante->siguiente = nuevo;
        }
    }

return lista;
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

///FUNCION PARA CARGAR UN REGISTRO DE SERVICIO

StServicio CargarUnServicio (StRegistroServicio Aux){

    StServicio Dato;

    Dato.IdServicio = Aux.IdServicio;
    Dato.Borrado = 1;
    strcpy(Dato.Servicio,Aux.Servicio);

return Dato;
}

///FUNCION PARA CARGAR UN REGISTRO DE SUBSERVICIO

StSubServicio CargarUnSubservicio (StRegistroServicio Aux){

    StSubServicio Dato;

    Dato.Precio = Aux.Precio;
    strcpy(Dato.SubServicio,Aux.SubServicio);
    Dato.Borrado = 1;

return Dato;
}

///FUNCION PARA DAR EL ALTA DE UN REGISTRO DE SERVICIOS

NodoP * AltaDeRegistroServicio (NodoP * lista, StRegistroServicio Aux){

    StSubServicio Dato = CargarUnSubservicio(Aux);
    NodoS * SubServ = CrearNodoSubservicio(Dato);

    NodoP * ServBuscado = BuscarServicio(lista,Aux.Servicio);
    if(ServBuscado == NULL){
        StServicio Dato2 = CargarUnServicio(Aux);
        NodoP * Serv = CrearNodoServicio(Dato2);
        lista = InsertarOrdenadoListaServicio(lista,Serv);
        ServBuscado = BuscarServicio(lista,Aux.Servicio);
    }
    ServBuscado->lista = AgregarAlPcpioListaSubservicio(ServBuscado->lista,SubServ);

return lista;
}

///FUNCION PARA BUSCAR UN SERVICIO

NodoP* BuscarServicio(NodoP * lista, char Servicio[]){

    NodoP*Aux = NULL;
    NodoP*seg = lista;

    while(seg != NULL && Aux == NULL){
        if(strcmpi(seg->Dato.Servicio,Servicio) == 0){
            Aux = seg;
        }
        seg = seg->siguiente;
    }

return Aux;
}

///MOSTRAR UN REGISTRO DE SERVICIO

void MostrarUnServicio(StServicio Dato){

    puts("--------------------------------------");
    printf("ID SERVICIO: %d \n",Dato.IdServicio);
    printf("NOMBRE DEL SERVICIO: %s \n",Dato.Servicio);
    puts("--------------------------------------");

}

///MOSTRAR UN REGISTRO DE SUBSERVICIO

void MostrarUnSubServicio(StSubServicio Dato){

    puts("--------------------------------------");
    printf("NOMBRE DEL SUBSERVICIO: %s \n",Dato.SubServicio);
    printf("PRECIO: %.2f \n",Dato.Precio);
    puts("--------------------------------------");

}

///FUNCION PARA MOSTRAR LOS DATOS DENTRO DE LA ESTRUCTURA COMPUESTA

void MostrarListaServicio(NodoP*lista){

    NodoP*seg = lista;

    while(seg!=NULL){
        MostrarUnServicio(seg->Dato);
        MostrarListaSubServicio(lista->lista);
        seg = seg->siguiente;
    }
}

void MostrarListaSubServicio(NodoS*lista){

    NodoS*seg = lista;

    while(seg!=NULL){
        MostrarUnSubServicio(seg->Dato);
        seg = seg->siguiente;
    }
}

///FUNCION PARA MOSTRAR UN REGISTRO

void MostrarUnRegistro(StRegistroServicio Aux){

    puts("--------------------------------------");
    printf("ID SERVICIO: %d \n",Aux.IdServicio);
    printf("NOMBRE DEL SERVICIO: %s \n",Aux.Servicio);
    printf("NOMBRE DEL SUBSERVICIO: %s \n",Aux.SubServicio);
    printf("PRECIO: %.2f \n",Aux.Precio);
    puts("--------------------------------------");

}

///FUNCION PARA MOSTRAR UN ARCHIVO

void MostrarUnArchivo(){

    StRegistroServicio Aux;

    FILE * archi = fopen(Arreglo,"rb");

    if(archi!=NULL){
        while(fread(&Aux,sizeof(StRegistroServicio),1,archi)>0){
            MostrarUnRegistro(Aux);
        }

        fclose(archi);
    }else{
        printf("El archivo se abrio incorrectamente\n");
    }
}


///FUNCION PARA CARGAR UN REGISTRO DE SERVICIOS

StRegistroServicio CargarUnRegistro(){

    StRegistroServicio Aux;

    printf("Ingrese el id del servicio: ");
    scanf("%d",&Aux.IdServicio);
    printf("Ingrese el nombre del servicio: ");
    fflush(stdin);
    gets(Aux.Servicio);
    printf("Ingrese el nombre del subservicio: ");
    fflush(stdin);
    gets(Aux.SubServicio);
    printf("Ingrese el costo del subservicio: ");
    scanf("%f",&Aux.Precio);

return Aux;
}

///FUNCION PARA CARGAR UN ARCHIVO

void CargarUnArchivo(){

    char control = 's';

    FILE * archi = fopen(Arreglo,"ab");

    if(archi!=NULL){
        while(control == 's'){
            StRegistroServicio Aux = CargarUnRegistro();
            fwrite(&Aux,sizeof(StRegistroServicio),1,archi);
            printf("Quiere seguir cargando datos?? ");
            fflush(stdin);
            scanf("%c",&control);
        }

        fclose(archi);
    }else{
        printf("El archivo se abrio incorrectamente\n");
    }
}


