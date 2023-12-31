
#include "arrayLista.h"


NodoPiso * iniclista (){
    return NULL;
}

NodoPiso * crearNodo (stRegHabitacion DATO){
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
    FILE * archi = fopen (aCaracteristicas,"rb");
    stRegHabitacion aux;

    iniciallizarTodo(ARRAY);

    while (fread(&aux,sizeof(stRegHabitacion),1,archi)>0){
       ARRAY[aux.idPiso] = insertar(ARRAY,aux,aux.idPiso);
    }

    fclose(archi);
}

void iniciallizarTodo (stDeCelda ARRAY[]){
    int x = 0;

    while (x < 13){
        ARRAY[x].lista = iniclista();
        x++;
    }
}


stDeCelda insertar (stDeCelda array[], stRegHabitacion aux,int posicion){
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

    //archi = fopen(NOMBRE,"rb");

    //mostrar (archi);

    CargarArray(PISOS);

    mostrarArrayCompleto(PISOS);

    //funcion2();

    stCaracteristicas arrayprecio[9];

    CargarArrayPecios(arrayprecio);

    mostrarArrayPrecios(arrayprecio);





}




void CargarArchi (FILE * archi){
    char seleccoin = 's';
    int validacion=1;

    stRegHabitacion aux;

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
        fwrite (&aux,sizeof(stRegHabitacion),1,archi);



        printf ("\n\n   desea seguir cargando datos?... ");
        fflush(stdin);
        scanf ("%c", &seleccoin);
    }
}

void mostrar (FILE * archi){
    stRegHabitacion aux;
    int x = 1;
    while (fread (&aux,sizeof(stRegHabitacion),1,archi)>0){
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
    while (i < 13){
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



void funcion2(){
    FILE * archi = fopen (aPrecios,"ab");

    CargarArchiPrecios(archi);

    fclose(archi);


}

void CargarArchiPrecios (FILE * archi){ /// CARGAMOS LOS PRECIOS DE LAS HABITACIONES
    char seleccoin = 's';
    int validacion=1;

    stCaracteristicas aux;

    while (seleccoin != 'n'){
        printf("caracteristicas: ");
        do{
            fflush(stdin);
            gets(aux.caracteristica);
            validacion = validacionDeString(aux.caracteristica);
        }while (validacion !=1);



        printf("tipo de cama: ");
        do{
            fflush(stdin);
            scanf ("%s", aux.tipoCama);
            validacion = validacionDeCamas(aux.tipoCama);
        }while (validacion !=1);

        printf("ingresar precio:");
        scanf("%i", &aux.precio);

        fwrite (&aux,sizeof(stCaracteristicas),1,archi);

        printf ("\n\n   desea seguir cargando datos?... ");
        fflush(stdin);
        scanf ("%c", &seleccoin);
    }
}

void CargarArrayPecios (stCaracteristicas ARRAY[]){
    FILE * archi = fopen (aPrecios,"rb");
    stCaracteristicas aux;
    int x=0;

    while (fread(&aux,sizeof(stCaracteristicas),1,archi)>0){
       ARRAY[x] = insertarPrecio(ARRAY,aux,x);
       x++;
    }

    fclose(archi);
}

stCaracteristicas insertarPrecio (stCaracteristicas ARRAY[], stCaracteristicas aux, int posicion){
    ARRAY[posicion].precio = aux.precio;
    strcpy(ARRAY[posicion].caracteristica, aux.caracteristica);
    strcpy(ARRAY[posicion].tipoCama, aux.tipoCama);

return ARRAY[posicion];
}

void mostrarArrayPrecios (stCaracteristicas ARRAY[]){
    int i =0;

    while (i < 9){
        printf("%s\n", ARRAY[i].caracteristica);
        printf("%s\n", ARRAY[i].tipoCama);
        printf("%i\n\n", ARRAY[i].precio);
        i++;
    }
}