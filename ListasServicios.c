#include "ListasServicios.h"

///FUNCION DE PAUSA

void Pause(){

    printf("\n\n");
    system("Pause");
    system("cls");

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
        if(nuevo->Dato.Piso < lista->Dato.Piso){
            lista = AgregarAlPcpioListaServicio(lista,nuevo);
        }else{
            NodoP*ante = lista;
            NodoP*seg = lista->siguiente;

            while(seg!=NULL && seg->Dato.Piso < nuevo->Dato.Piso){
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

///MOSTRAR UN REGISTRO DE SERVICIO

void MostrarUnServicio(StServicio Dato){

    puts("--------------------------------------");
    printf("PISO NUMERO: %d \n",Dato.Piso);
    printf("SERVICIO: %s \n",Dato.Servicio);
    printf("PRECIO UNITARIO DEL SERVICIO: %.2f \n",Dato.Precio);
    puts("--------------------------------------");

}

///MOSTRAR UN REGISTRO DE SUBSERVICIO

void MostrarUnSubServicio(StSubServicio Dato){

    puts("--------------------------------------");
    printf("SERVICIO ADICIONAL: %s \n",Dato.SubServicio);
    printf("PRECIO: %.2f \n",Dato.Precio);
    puts("--------------------------------------");

}

///FUNCION PARA MOSTRAR LOS DATOS DENTRO DE LA ESTRUCTURA COMPUESTA

void MostrarListaServicio(NodoP*lista){

    NodoP*seg = lista;

    while(seg!=NULL){
        MostrarUnServicio(seg->Dato);
        MostrarListaSubServicio(seg->lista);
        seg = seg->siguiente;
        Pause();
    }
}

void MostrarListaSubServicio(NodoS*lista){

    NodoS*seg = lista;

    while(seg!=NULL){
        MostrarUnSubServicio(seg->Dato);
        seg = seg->siguiente;
    }
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

///FUNCION BORRAR UN NODO

NodoP*BorrarUnNodo(NodoP*lista,char Servicio[]){

    if(lista!=NULL && strcmpi(lista->Dato.Servicio,Servicio)==0){
        NodoP*Aux = lista;
        lista = lista->siguiente;
        free(Aux);
    }else{
        NodoP*ante = lista;
        NodoP*seg = lista->siguiente;

        while(seg!=NULL && strcmpi(seg->Dato.Servicio,Servicio)!=0){
            ante = seg;
            seg = seg->siguiente;
        }

        ante->siguiente = seg->siguiente;
        free(seg);
    }

return lista;
}




