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

NodoPiso * iniclista ();
NodoPiso * crearNodo (archivo DATO);
NodoPiso * agregarALista(NodoPiso * lista, NodoPiso * DATO);
void CargarArray (stDeCelda ARRAY[]);
stDeCelda insertar (stDeCelda array[], archivo aux,int posicion);
void FuncionPrincipal ();

void CargarArchi (FILE * archi);
void mostrar (FILE * archi);
void  mostrarLista(NodoPiso * lista);

void mostrarArrayCompleto (stDeCelda ARRAY[]);

void iniciallizarTodo (stDeCelda ARRAY[]);






int main()
{
     FuncionPrincipal ();

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

    iniciallizarTodo(ARRAY);

    while (fread(&aux,sizeof(archivo),1,archi)>0){
       ARRAY[aux.idPiso-1] = insertar(ARRAY,aux,aux.idPiso-1);
    }

    fclose(archi);
}

void iniciallizarTodo (stDeCelda ARRAY[]){
    int x = 0;

    while (x < 12){
        ARRAY[x].lista = iniclista();
        x++;
    }
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

    FILE * archi ;
    //archi = fopen(NOMBRE,"ab");

    //CargarArchi(archi);

    //fclose(archi);

    archi = fopen(NOMBRE,"rb");

    mostrar (archi);

    CargarArray(PISOS);

    mostrarArrayCompleto(PISOS);



}




void CargarArchi (FILE * archi){
    char seleccoin = 's';

    archivo aux;

    while (seleccoin != 'n'){
        printf("\nid de la habitacion: ");
        scanf ("%i", &aux.id);

        printf("Piso: ");
        scanf ("%i", &aux.idPiso);

        printf("cantidad de camas: ");
        scanf ("%i", &aux.cantCamas);

        printf("caracteristicas: ");
        fflush(stdin);
        scanf ("%s", aux.caracteristicas);

        printf("tipo de cama: ");
        fflush(stdin);
        scanf ("%s", aux.tipoDeCama);

        fwrite (&aux,sizeof(archivo),1,archi);

        printf ("       desea seguir cargando datos?... ");
        fflush(stdin);
        scanf ("%c", &seleccoin);
    }
}

void mostrar (FILE * archi){
    archivo aux;
    while (fread (&aux,sizeof(archivo),1,archi)>0){
        printf("\nid: %i",aux.id);
        printf("\npiso: %i ",aux.idPiso);
        printf("\ncantidad de camas: %i ",aux.cantCamas);
        printf("\ntipo de cama: %s",aux.tipoDeCama);
        printf("\ncaracteristica especial: %s",aux.caracteristicas);
        printf("\n----------------------------");


    }
}

void  mostrarLista(NodoPiso * lista){

    while (lista != NULL){

        printf("\nid: %i",lista->DATOS.id);
        printf("\ncantidad de camas: %i ",lista->DATOS.cantCamas);
        printf("\ntipo de cama: %s",lista->DATOS.tipoDeCama);
        printf("\ncaracteristica especial: %s",lista->DATOS.caracteristicas);
        printf("\n----------------------------");
        lista = lista->siguiente;
    }
}



void mostrarArrayCompleto (stDeCelda ARRAY[]){
    int i =0;
    printf("\nACA ENTRAMOS A MOSTRAR LAS LISTAASSSSS\n\n");
    while (i < 12){
        if (ARRAY[i].lista == NULL){
            printf ("el piso %i esta vacio\n", i+1);
        }else{
             printf ("el piso %i\n\n", i+1);
            mostrarLista(ARRAY[i].lista);
        }
        i++;
    }
}
















