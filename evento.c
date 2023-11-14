#ifndef EVENTO_C_INCLUDED
#define EVENTO_C_INCLUDED
#include "evento.h"


const char nombreArchivo[20] = {"eventos.bin"};

/// FUCNIONES DE LISTAS:

stEvento * inicListaEvento ()
{
    return NULL;
}

stEvento * crearNodoEvento (stClienteEvento aux)
{
    stEvento * nuevoEvento = (stEvento*) malloc(sizeof(stEvento));

    nuevoEvento->dato = aux;
    nuevoEvento->siguiente=NULL;

    return nuevoEvento;
}

stEvento * agregarAlPrincipioEvento(stEvento * lista, stEvento * nuevoEvento)
{
    if(lista == NULL)
    {
        lista= nuevoEvento;
    }
    else
    {
        nuevoEvento->siguiente = lista;
        lista= nuevoEvento;
    }

    return lista;
}

stEvento * agregarEnOrdenEvento (stEvento * lista, stEvento * nuevoEvento)
{
    if (lista == NULL)
    {
        lista = nuevoEvento;
    }

    else
    {
        if(lista->dato.dia > nuevoEvento->dato.dia)
        {
            lista=agregarAlPrincipioEvento(lista, nuevoEvento);
        }
        else
        {
            stEvento * ante = lista;
            stEvento * seg = lista->siguiente;

            while((seg != NULL)&& (nuevoEvento->dato.dia > lista->dato.dia))
            {
                ante = seg;
                seg = seg->siguiente;
            }

            nuevoEvento->siguiente = seg;
            ante->siguiente = nuevoEvento;
        }
    }
    return lista;
}

void mostrarUnEvento (stClienteEvento aux)
{
    printf("\n----------------------------- \n");
    printf("Dia del evento: %i \n",aux.dia);
    printf("Tipo de evento: %s \n", aux.tipoEvento);
    printf("Hora de inicio: %s \n", aux.horaInicio);
    printf("Hora de finalizacion : %s \n", aux.horaFin);
    printf("cantidad de invitados: : %i \n", aux.cantPersonas);
    printf("Precio total del evento : %i \n",aux.precio);
    printf(" | Datos del cliente: | \n");
    printf("Nombre: %s \n", aux.nombre);
    printf("Apellido: %s \n", aux.apellido);
    printf("Telefono: %s \n", aux.telefono);
    printf("DNI: %s \n", aux.dni);
    printf("\n----------------------------- \n");
}

void mostrarListaEvento (stEvento * lista)
{
    if(lista== NULL)
    {
        printf("NO HAY NINGUN EVENTO \n");
    }
    else
    {
        stEvento * seguidora = lista;

        while(seguidora != NULL)
        {
            mostrarUnEvento(seguidora->dato);
            seguidora = seguidora->siguiente;
        }
    }
}


stEvento * borrarUnEvento (stEvento * lista, int dia)
{
    stEvento * seg;
    stEvento * ante;

    if(lista != NULL)
    {
        if(lista->dato.dia == dia)
        {
            stEvento * aux = lista;
            lista = lista->siguiente;
            free(aux);
        }
        else
        {
            seg = lista;
             while((seg != NULL)&& (dia > lista->dato.dia))
            {
                ante = seg;
                seg = seg->siguiente;

            }

            if( seg != NULL)
            {
                ante->siguiente = seg->siguiente;
                free(seg);
            }
        }

    }

    return lista;
}


stEvento * buscarUnEvento (stEvento * lista, int dia)
{
    stEvento * rta = NULL;
    int flag =0;

    if(lista != NULL)
    {
        stEvento * seguidora = lista;
        while ( seguidora != NULL && flag==0 )
        {
            if(dia == seguidora->dato.dia)
            {
                rta = seguidora;
                flag=1;
            }
            else
            {
                seguidora= seguidora->siguiente;
            }
        }
    }

    return rta;

}

/// CARGAR ARCHIVO

stRegistroEvento cargarUnEvento()
{
    stRegistroEvento aux;

    printf("Ingrese mes del evento: \n");
    fflush(stdin);
    gets(aux.mes);
    printf("Ingrese numero del mes: \n");
    scanf("%i",&aux.idMes);
    printf("Ingrese un dia: \n ");
    scanf("%i", &aux.dia);
    printf("Ingrese tipo de vento: \n");
    fflush(stdin);
    gets(aux.tipoEvento);
    printf("Ingrese hora de inicio: \n");
    fflush(stdin);
    gets(aux.horaInicio);
    printf("Ingrese hora de finalizacion: \n");
    fflush(stdin);
    gets(aux.horaFin);
    printf("Ingrese cantidad de invitados: : \n");
    scanf("%i",&aux.cantPersonas);
    printf("Ingrese costo total del evento: \n");
    scanf("%i", &aux.precio);
    printf("Ingrese nombre del cliente: \n");
    fflush(stdin);
    gets(aux.nombre);
    printf("Ingrese apellido del cliente: \n");
    fflush(stdin);
    gets(aux.apellido);
    printf("Ingrese telefono del cliente: \n");
    fflush(stdin);
    gets(aux.telefono);
    printf("Ingrese DNI del cliente: \n");
    fflush(stdin);
    gets(aux.dni);


    return aux;
}


void cargarArchivo ()
{
    stRegistroEvento aux;
    char control = 's';
    FILE * archi = fopen(nombreArchivo, "ab");

    if(archi)
    {
        while(control == 's')
        {
            aux = cargarUnEvento();
            fwrite(&aux, sizeof(stRegistroEvento),1,archi);
            printf("Desea continuar? \n");
            fflush(stdin);
            scanf("%c", &control);
        }

        fclose(archi);
    }


}

/// CARGAR ARREGLO

int pasarDatosDeArchivoAarregloEventos(celdaEvento eventos [],int dim, int validos)
{
    FILE * archi = fopen(nombreArchivo, "rb");
    stRegistroEvento aux;
    stClienteEvento cliente;
    stDatosMes datoMes;


    if(archi)
    {
        while (fread(&aux, sizeof(stRegistroEvento),1,archi) >0)
        {
            strcpy(datoMes.mes,aux.mes);
            datoMes.idMes = aux.idMes;
            cliente.dia = aux.dia;
            strcpy(cliente.tipoEvento,aux.tipoEvento);
            strcpy(cliente.horaInicio, aux.horaInicio);
            strcpy(cliente.horaFin, aux.horaFin);
            cliente.cantPersonas = aux.cantPersonas;
            cliente.precio = aux.precio;
            strcpy(cliente.nombre, aux.nombre);
            strcpy(cliente.apellido, aux.apellido);
            strcpy(cliente.telefono, aux.telefono);
            strcpy(cliente.dni, aux.dni);


            validos = altaEventos(eventos, dim, validos, cliente,datoMes);
        }

        fclose(archi);
    }

    return validos;
}

/// FUNCION DE CARGA:

int altaEventos(celdaEvento eventos[], int dim, int validos, stClienteEvento cliente , stDatosMes datoMes)
{
    stEvento * aux = crearNodoEvento(cliente);
    int pos = buscaPosMes (eventos,datoMes.idMes, validos);

    if(pos==-1)
    {
        validos =insertarEventoOrdenado(eventos,validos,datoMes);
        pos = buscaPosMes(eventos,datoMes.idMes,validos);

    }

    eventos[pos].listaDeDias = agregarEnOrdenEvento(eventos[pos].listaDeDias,aux);

    return validos;
}

int buscaPosMes(celdaEvento eventos[],int idMes, int validos)
{
    int rta =-1;
    int i =0;

    while((i<validos) && (rta ==-1))
    {
        if(idMes == eventos[i].datoMes.idMes)
        {
            rta =i;
        }

        i++;
    }

    return rta;
}

int insertarEventoOrdenado(celdaEvento eventos[], int validos, stDatosMes datoMes)
{
    int ult = validos-1;
     while (ult >= 0 && datoMes.idMes < eventos[ult].datoMes.idMes)
    {
        eventos[ult+1]=eventos[ult];
        eventos[ult+1].listaDeDias = eventos[ult].listaDeDias;
        ult --;
    }
    eventos[ult+1].datoMes = datoMes;
    eventos[ult+1].listaDeDias = inicListaEvento();

    return validos+1;
}

///MOSTRAR

void buscarMesYmostrar(celdaEvento eventos[], int validos, int idMes)
{
    int pos=0;
    pos=buscaPosMes(eventos, idMes, validos);

    mostrarListaEvento(eventos[pos].listaDeDias);
}


void mostrarMesyDias(celdaEvento eventos[], int validos)
{
 for (int i = 0; i<validos; i++)
 {
     printf("\n %i \n", eventos[i].datoMes.idMes);
     printf("\n %s \n", eventos[i].datoMes.mes);
    mostrarListaEvento(eventos[i].listaDeDias);
 }
}

/// PASAR DEL ARREGLO AL ARCHIVO:

void guardarEventosEnArchivo (celdaEvento eventos[], int validos)
{
    stRegistroEvento aux;

    for(int i =0; i<validos; i++)
    {
        aux.idMes = eventos[i].datoMes.idMes;
        strcpy(aux.mes, eventos[i].datoMes.mes);

        stEvento * seg = eventos[i].listaDeDias;

        while(seg)
        {
            aux.dia = seg->dato.dia;
            strcpy(aux.tipoEvento, seg->dato.tipoEvento);
            strcpy( aux.horaInicio, seg->dato.horaInicio);
            strcpy(aux.horaFin,seg->dato.horaFin);
            aux.cantPersonas = seg->dato.cantPersonas;
            aux.precio = seg->dato.precio;
            strcpy(aux.nombre, seg->dato.nombre);
            strcpy(aux.apellido, seg->dato.apellido);
            strcpy(aux.telefono, seg->dato.telefono);
            strcpy(aux.dni, seg->dato.dni);

           guardarProximosEventos("proximosEventos",aux);

            seg = seg->siguiente;
        }
    }
}


void guardarProximosEventos (char archivo[], stRegistroEvento aux)
{
    FILE * archi = fopen(archivo, "ab");

    if(archi)
    {
        fwrite(&aux, sizeof(stRegistroEvento),1,archi);
        fclose(archi);
    }
}


/// FUNCIONALIDADES

void buscarYmostrarFechaDisponibleEvento(celdaEvento eventos[], int validos, int idMes, int dia)
{
    int pos = buscaPosMes(eventos,idMes,validos);
    if(pos>=0)
    {
        stEvento * rta = buscarUnEvento(eventos[pos].listaDeDias, dia);
        if(rta !=NULL)
        {
            printf(" \n EL DIA YA ESTA OCUPADO \n");
        } else
        {
            printf("\n EL DIA ESTA DISPONIBLE \n");
        }
    }
    else
    {
        printf(" \nNO HAY EVENTOS EL MES ELEGIDO \n");
    }
}
int sumarCantidadEventosDeUnMes(celdaEvento eventos[], int validos, int idMes)
{
    int suma=0;
    int pos= buscaPosMes(eventos,idMes,validos);
    if(pos == -1)
    {
        printf("\n NO HAY EVENTOS ESE MES \n");
    }
    else
    {
        if(eventos[pos].listaDeDias != NULL)
        {
            stEvento * seg = eventos[pos].listaDeDias;
            while (seg != NULL)
            {
                suma ++;
                seg = seg->siguiente;
            }
        }
    }

    return suma;
}




#endif // EVENTO_C_INCLUDED

