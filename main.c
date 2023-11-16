#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <time.h>

char NOMBRE[] = {"caracteristicasDeLasHabitaciones"};

typedef struct {
    int id;
    char caracteristicas[25];
    int ocupado;
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
    int ocupado; ///1 si 0 no
    char caracteristicas[25]; /// vista al mar, balcon, Espaciosa
    int cantCamas;
    char tipoDeCama[13]; /// simple, matrimonial o combinada
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
int validacionDeString(char caracteristica[]);
int validacionDeCamas(char caracteristica[]);





/// MAIN

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
    aux->DATOS.ocupado = DATO.ocupado;
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
       ARRAY[aux.idPiso] = insertar(ARRAY,aux,aux.idPiso);
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
    stDeCelda PISOS [14];

    FILE * archi ;
    //archi = fopen(NOMBRE,"ab");

    //CargarArchi(archi);

   // fclose(archi);

    archi = fopen(NOMBRE,"rb");

    mostrar (archi);

    CargarArray(PISOS);

    mostrarArrayCompleto(PISOS);



}




void CargarArchi (FILE * archi){
    char seleccoin = 's';
    int validacion=1;

    archivo aux;

    while (seleccoin != 'n'){
        srand(time(NULL));
        aux.id = rand()%9999;

        printf("Piso: ");
        scanf ("%i", &aux.idPiso);

        printf("cantidad de camas: ");
        scanf ("%i", &aux.cantCamas);

        aux.ocupado = 0;

        printf("caracteristicas: ");
        do{
            fflush(stdin);
            gets(aux.caracteristicas);
            validacion = validacionDeString(aux.caracteristicas);
        }while (validacion !=1);



        printf("tipo de cama: ");
        do{
            fflush(stdin);
            scanf ("%s", aux.tipoDeCama);
            validacion = validacionDeCamas(aux.tipoDeCama);
        }while (validacion !=1);
        fwrite (&aux,sizeof(archivo),1,archi);



        printf ("\n\n   desea seguir cargando datos?... ");
        fflush(stdin);
        scanf ("%c", &seleccoin);
    }
}

void mostrar (FILE * archi){
    archivo aux;
    int x = 1;
    while (fread (&aux,sizeof(archivo),1,archi)>0){
        printf ("%i", x);
        printf("\nid: %i",aux.id);
        printf("\npiso: %i ",aux.idPiso);
        printf("\ncantidad de camas: %i ",aux.cantCamas);
        printf("\ntipo de cama: %s",aux.tipoDeCama);
        printf("\ncaracteristica especial: %s",aux.caracteristicas);
        printf("\n----------------------------");
        x++;

    }
}

void  mostrarLista(NodoPiso * lista){

    while (lista != NULL){

        printf("\nid: %i",lista->DATOS.id);
        printf("\ncantidad de camas: %i ",lista->DATOS.cantCamas);
        printf("\ntipo de cama: %s",lista->DATOS.tipoDeCama);
        printf("\ncaracteristica especial: %s",lista->DATOS.caracteristicas);
        printf("\n----------------------------\n");
        lista = lista->siguiente;
    }
}



void mostrarArrayCompleto (stDeCelda ARRAY[]){
    int i =0;
    printf("\n      ACA ENTRAMOS A MOSTRAR LAS LISTAASSSSS\n\n");
    while (i < 14){
        if (ARRAY[i].lista == NULL){
            printf ("el piso %i esta vacio\n", i);
        }else{
             printf ("el piso %i\n\n", i);
            mostrarLista(ARRAY[i].lista);
        }
        i++;
    }
}




int validacionDeString(char caracteristica[]){ /// caracteristicas
    int x=0;
    if (strcmp(caracteristica,"balcon")== 0){
        x=1;
    }else{
        if (strcmp(caracteristica,"espaciosa")== 0){
            x=1;
        }else{
            if(strcmp(caracteristica,"vista al mar")== 0){
                x=1;
            }else{
                printf("esta mal...:");
            }
        }
    }
return x;
}


int validacionDeCamas(char caracteristica[]){ /// camas simple, matrimonial o combinada
    int x=0;
    if (strcmp(caracteristica,"simple")== 0){
        x=1;
    }else{
        if (strcmp(caracteristica,"matrimonial")== 0){
            x=1;
        }else{
            if(strcmp(caracteristica,"combinada")== 0){
                x=1;
            }else{
                printf("esta mal...:");
            }
        }
    }
return x;
}









