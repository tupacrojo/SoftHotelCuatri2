#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

char nombre[] = {"habitaciones.bin"}


typedef struct //este es la estructura que alamcena las caracteristicas de la habitacion
{
    char tipo[30]; // vista al mar, cama matrinomial, perroincluido
}stRegCaracteristicas;


typedef struct ///  "stRegHabitacion" habitacion
{
    int estado;  // 0 libre; 1 Ocupado;
    int piso;   // pisos
    char tipoDeHabitacion [8];
    struct NodoPiso * lista;
    stRegCaracteristicas caracteristicas[10];// este arreglo puede almacenar


}stRegHabitacion;





typedef struct {
    stRegHabitacion DATOS;

    struct NodoPiso * siguiente;
}NodoPiso;



int main()
{
    stRegHabitacion ARREGLO[12];
    int x = 0;
    FILE * archi = fopen(nombre,"rb");
    while (x < 12){
        ARREGLO [x] = CargarElArreglo(ARREGLO[],x,archi);
        x++;
    }

    fclose(archi);



    return 0;
}


NodoPiso * iniclista (){
    return NULL;
}

NodoPiso * crearNodo (stRegHabitacion DATO){
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


stRegHabitacion CargarElArreglo(stRegHabitacion array[], int posArray, FILE * archi) { /// el array de los pisos y le paso el dato del archivo
    int i = 0;
    stRegHabitacion  ayudin;
    array[posArray].lista = iniclista();
    while (i < 5){ /// insertamos 5 habitaciones en la posision del arreglo determinada
        fread(&ayudin,sizeof(stRegHabitacion),1,archi); /// leo la habitacion

        NodoPiso * aux = crearNodo (ayudin);
        array[posArray].lista = agregarALista (array[posArray].lista,aux); /// inserto en la lista del array [posArray]

        i++;
    }

return array[posArray]; /// aca quiero retornar la el arreglo en la posArray
}
