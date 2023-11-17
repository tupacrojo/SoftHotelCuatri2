#include "StCompuestaServicios.h"

/// VARIABLE GLOBAL

const char Arreglo[40] = "NombreArchivo.bin";

/// FUNCIONES PARA CARGAR DATOS DENTRO DE LA ESTRUCTURA COMPUESTA

/// FUNCION PARA CARGAR LA LISTA CON LOS DATOS DEL ARCHIVO

NodoP *CargarListaServicioConArchivo(NodoP *lista)
{

    StRegistroServicio Aux;

    FILE *archi = fopen(Arreglo, "rb");

    if (archi != NULL)
    {
        while (fread(&Aux, sizeof(StRegistroServicio), 1, archi) > 0)
        {
            lista = AltaDeRegistroServicio(lista, Aux);
        }

        fclose(archi);
    }
    else
    {
        printf("El archivo se abrio incorrectamente\n");
    }

    return lista;
}

/// FUNCION PARA CARGAR UN SERVICIO

StRegistroServicio CargarUnServicioManual()
{

    StRegistroServicio Dato;

    printf("Ingrese el servicio: ");
    fflush(stdin);
    gets(Dato.Servicio);
    printf("Ingrese el numero de piso: ");
    scanf("%d", &Dato.Piso);
    printf("Ingrese el valor unitario del servicio: ");
    scanf("%f", &Dato.PrecioUni);
    Dato.Precio = -1;
    strcpy(Dato.SubServicio, "VACIO");
    Dato.borrado = 1;

    return Dato;
}

/// FUNCION PARA CARGAR UN NUEVO SERVICIO DENTRO DE LA LISTA

NodoP *CargarDatoListaServicios(NodoP *lista)
{

    StRegistroServicio Aux = CargarUnServicioManual();

    NodoP *ServBuscado = BuscarServicio(lista, Aux.Servicio);
    if (ServBuscado == NULL)
    {
        StServicio Dato = CargarUnServicio(Aux);
        NodoP *Serv = CrearNodoServicio(Dato);
        lista = InsertarOrdenadoListaServicio(lista, Serv);
    }
    CargarUnRegistroArchivo(Aux);

    return lista;
}

/// FUNCION PARA CARGAR UN REGISTRO DE SERVICIO

StServicio CargarUnServicio(StRegistroServicio Aux)
{

    StServicio Dato;

    Dato.Piso = Aux.Piso;
    strcpy(Dato.Servicio, Aux.Servicio);
    Dato.Precio = Aux.PrecioUni;

    return Dato;
}

/// FUNCION PARA CARGAR UN REGISTRO DE SUBSERVICIO

StSubServicio CargarUnSubservicio(StRegistroServicio Aux)
{

    StSubServicio Dato;

    Dato.Precio = Aux.Precio;
    strcpy(Dato.SubServicio, Aux.SubServicio);

    return Dato;
}

/// FUNCION PARA DAR EL ALTA DE UN REGISTRO DE SERVICIOS

NodoP *AltaDeRegistroServicio(NodoP *lista, StRegistroServicio Aux)
{

    if (Aux.borrado == 1)
    {
        StSubServicio Dato = CargarUnSubservicio(Aux);
        NodoS *SubServ = CrearNodoSubservicio(Dato);

        NodoP *ServBuscado = BuscarServicio(lista, Aux.Servicio);
        if (ServBuscado == NULL)
        {
            StServicio Dato2 = CargarUnServicio(Aux);
            NodoP *Serv = CrearNodoServicio(Dato2);
            lista = InsertarOrdenadoListaServicio(lista, Serv);
            ServBuscado = BuscarServicio(lista, Aux.Servicio);
        }

        if (strcmpi(SubServ->Dato.SubServicio, "VACIO") != 0)
        {
            ServBuscado->lista = AgregarAlPcpioListaSubservicio(ServBuscado->lista, SubServ);
        }
    }

    return lista;
}

/// FUNCION PARA BORRAR UN DATO EN LA LISTA DE SERVICIOS

NodoP *BorrarUnDatoServicio(NodoP *lista, char Servicio[])
{

    NodoP *Buscado = BuscarServicio(lista, Servicio);

    if (Buscado != NULL)
    {
        lista = BorrarUnNodo(lista, Servicio);
        BorrarUnRegistroArchivo(Servicio);
    }
    else
    {
        printf("El dato buscado no se encontro en la lista\n");
    }

    return lista;
}
