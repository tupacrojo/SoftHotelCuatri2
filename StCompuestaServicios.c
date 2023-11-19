#include "StCompuestaServicios.h"

///VARIABLE GLOBAL

const char Serv[40] = "Servicios.bin";
const char Adic[40] = "Adicionales.bin";

///FUNCIONES PARA CARGAR DATOS DENTRO DE LA ESTRUCTURA COMPUESTA

///FUNCION PARA CARGAR LA LISTA CON LOS DATOS DEL ARCHIVO DE SERVICIOS

NodoP* CargarListaServicioConArchivo(NodoP * lista){

    StRegistroServicio Aux;

    FILE * archi = fopen(Serv,"rb");

    if(archi!=NULL){
        while(fread(&Aux,sizeof(StRegistroServicio),1,archi)>0){
            lista = CargarListaServiciosAdicionalesConArchivo(lista,Aux);
        }

        fclose(archi);
    }else{
        printf("El archivo se abrio incorrectamente\n");
    }

return lista;
}

///FUNCION PARA CARGAR LA LISTA CON LOS DATOS DEL ARCHIVO DE SERVICIOS ADICIONALES

NodoP * CargarListaServiciosAdicionalesConArchivo(NodoP * lista,StRegistroServicio Dato){

    StRegistroAdicional Aux;

    FILE*archi = fopen(Adic,"rb");

    if(archi!=NULL){
        while (fread(&Aux,sizeof(StRegistroAdicional),1,archi)>0){
            lista = AltaDeRegistroServicio(lista,Dato,Aux);
        }

        fclose(archi);
    }else{
        printf("El archivo se abrio incorrectamente\n");
    }

return lista;
}


///FUNCION PARA DAR EL ALTA DE UN REGISTRO DE SERVICIOS

NodoP * AltaDeRegistroServicio (NodoP * lista, StRegistroServicio Aux, StRegistroAdicional Dato){

    StSubServicio Dato1;
    NodoS*SubServ;

    if(Aux.Borrado == 1){
        if(Dato.Borrado == 1){
            Dato1 = CargarUnSubservicio(Dato);
            SubServ = CrearNodoSubservicio(Dato1);
        }
        NodoP * ServBuscado = BuscarServicio(lista,Aux.Servicio);
        if(ServBuscado == NULL){
            StServicio Dato2 = CargarUnServicio(Aux);
            NodoP * Serv = CrearNodoServicio(Dato2);
            lista = InsertarOrdenadoListaServicio(lista,Serv);
            ServBuscado = BuscarServicio(lista,Aux.Servicio);
        }

        if(ServBuscado->Dato.Id == Dato1.IdServicio && Dato.Borrado == 1){
            ServBuscado->lista = AgregarAlPcpioListaSubservicio(ServBuscado->lista,SubServ);
        }
    }

return lista;
}

///FUNCION PARA CARGAR UN REGISTRO DE SUBSERVICIO

StSubServicio CargarUnSubservicio (StRegistroAdicional Aux){

    StSubServicio Dato;

    Dato.Precio = Aux.Precio;
    strcpy(Dato.SubServicio,Aux.SubServicio);
    Dato.IdServicio = Aux.IdServicio;

return Dato;
}

///FUNCION PARA CARGAR UN REGISTRO DE SERVICIO

StServicio CargarUnServicio (StRegistroServicio Aux){

    StServicio Dato;

    Dato.Piso = Aux.Piso;
    strcpy(Dato.Servicio,Aux.Servicio);
    Dato.Precio = Aux.PrecioUni;
    Dato.Id = Aux.Id;

return Dato;
}

///FUNCION PARA CARGAR UN NUEVO SERVICIO DENTRO DE LA LISTA

NodoP*CargarDatoListaServicios(NodoP*lista){

    StRegistroServicio Aux = CargarUnRegistroServicio();

    StServicio Dato = CargarUnServicio(Aux);
    NodoP * Serv = CrearNodoServicio(Dato);
    lista = InsertarOrdenadoListaServicio(lista,Serv);

    CargarUnRegistroArchivo(Aux);

return lista;
}

///FUNCION PARA BORRAR UN DATO EN LA LISTA DE SERVICIOS

NodoP*BorrarUnDatoServicio(NodoP* lista){

    char Servicio[25];
    NodoP*Buscado;

    printf("Ingrese un servicio a borrar: ");
    fflush(stdin);
    gets(Servicio);

    while(BuscarServicio(lista,Servicio) == NULL){
        printf("Ingreso un servicio que no existe, ingreselo nuevamente: ");
        fflush(stdin);
        gets(Servicio);
    }

    Buscado = BuscarServicio(lista,Servicio);
    BorrarConjuntoDeRegistros(Buscado->Dato.Id);
    lista = BorrarUnNodo(lista,Servicio);
    BorrarUnRegistroArchivo(Servicio);

return lista;
}

///FUNCION PARA MODIFICAR UN SERVICIO

NodoP*ModificarServicioPrincipal(NodoP*lista){

    char Servicio[25];
    NodoP*Buscado;

    printf("Ingrese el servicio a modificar: ");
    fflush(stdin);
    gets(Servicio);

    while(BuscarServicio(lista,Servicio) == NULL){
        printf("Ingreso un servicio que no existe, ingreselo nuevamente: ");
        fflush(stdin);
        gets(Servicio);
    }

    Buscado = BuscarServicio(lista,Servicio);
    printf("Ingrese el nuevo valor del servicio elegido: ");
    scanf("%f",&Buscado->Dato.Precio);
    ModificarServicioArchivo(Buscado->Dato.Servicio,Buscado->Dato.Precio);
    printf("El servicio se modifico correctamente y quedo de la siguiente manera: \n\n");
    MostrarUnServicio(Buscado->Dato);

return lista;
}

///FUNCION PARA CARGAR UN NUEVO SUBSERVICIO

NodoP*CargarNuevoSubServicio(NodoP*lista){

    char Servicio[25];
    NodoP*Buscado;

    do{
        printf("Ingrese el servicio principal al cual quiere agregarle un servicio adicional: ");
        fflush(stdin);
        gets(Servicio);

        Buscado = BuscarServicio(lista,Servicio);
        if(Buscado == NULL){
            printf("El servicio ingresado no existe, por favor vuelva a ingresar el dato. \n");
        }
    }while(Buscado == NULL);

    StRegistroAdicional Dato = CargarRegistroAdicional(Buscado->Dato.Id);

    StSubServicio Aux = CargarUnSubservicio(Dato);
    NodoS * nuevo = CrearNodoSubservicio(Aux);
    Buscado->lista = AgregarAlPcpioListaSubservicio(Buscado->lista,nuevo);

    CargarUnServicioAdicionalArchivo(Dato);

return lista;
}

///FUNCION PARA BORRAR UN DATO DE LA LISTA DE SERVICIOS ADICIONALES

NodoP*BorrarUnDatoServicioAdicional(NodoP* lista){

    char Servicio[25];
    char SubServicio[25];
    NodoP*Buscado;
    NodoS*Encontrado;

    do{
        printf("Ingrese el servicio principal al cual quiere borrar un servicio adicional: ");
        fflush(stdin);
        gets(Servicio);

        Buscado = BuscarServicio(lista,Servicio);
        if(Buscado == NULL){
            printf("El servicio ingresado no existe, por favor vuelva a ingresar el dato. \n");
        }
    }while(Buscado == NULL);

    do{
        printf("Ingrese el servicio adicional el cual quiere borrar: ");
        fflush(stdin);
        gets(SubServicio);

        Encontrado = BuscarServicioAdicional(Buscado->lista,SubServicio);
        if(Encontrado == NULL){
            printf("El servicio adicional no existe, por favor vuelva a ingresar el dato. \n");
        }
    }while(Encontrado == NULL);

    int num = Encontrado->Dato.IdServicio;
    Buscado->lista = BorrarUnNodoAdicional(Buscado->lista,SubServicio);
    BorrarUnRegistroAdicionalArchivo(SubServicio,num);

return lista;
}

///FUNCION PARA MODIFICAR UN SERVICIO ADICIONAL

NodoP*ModificarServicioAdicional(NodoP*lista){

    char Servicio[25];
    char SubServicio[25];
    NodoP*Buscado;
    NodoS*Encontrado;

    do{
        printf("Ingrese el servicio principal al cual quiere modificar un servicio adicional: ");
        fflush(stdin);
        gets(Servicio);

        Buscado = BuscarServicio(lista,Servicio);
        if(Buscado == NULL){
            printf("El servicio ingresado no existe, por favor vuelva a ingresar el dato. \n");
        }
    }while(Buscado == NULL);

    do{
        printf("Ingrese el servicio adicional el cual quiere modificar: ");
        fflush(stdin);
        gets(SubServicio);

        Encontrado = BuscarServicioAdicional(Buscado->lista,SubServicio);
        if(Encontrado == NULL){
            printf("El servicio adicional no existe, por favor vuelva a ingresar el dato. \n");
        }
    }while(Encontrado == NULL);

    printf("Ingrese el nuevo valor del servicio elegido: ");
    scanf("%f",&Encontrado->Dato.Precio);
    ModificarServicioAdicionalArchivo(Encontrado->Dato.SubServicio,Encontrado->Dato.Precio,Encontrado->Dato.IdServicio);
    printf("El servicio se modifico correctamente y quedo de la siguiente manera: \n\n");
    MostrarUnSubServicio(Encontrado->Dato);

return lista;
}








