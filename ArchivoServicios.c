#include "ArchivoServicios.h"

const char Array[40] = "NombreArchivo.bin";

///FUNCION PARA MOSTRAR UN REGISTRO

void MostrarUnRegistro(StRegistroServicio Aux){

    puts("--------------------------------------");
    printf("PISO NUMERO: %d \n",Aux.Piso);
    printf("NOMBRE DEL SERVICIO: %s \n",Aux.Servicio);
    printf("PRECIO UNITARIO DEL SERVICIO: %.2f \n",Aux.PrecioUni);
    printf("NOMBRE DEL SUBSERVICIO: %s \n",Aux.SubServicio);
    printf("PRECIO: %.2f \n",Aux.Precio);
    puts("--------------------------------------");

}

///FUNCION PARA MOSTRAR UN ARCHIVO

void MostrarUnArchivo(){

    StRegistroServicio Aux;

    FILE * archi = fopen(Array,"rb");

    if(archi!=NULL){
        while(fread(&Aux,sizeof(StRegistroServicio),1,archi)>0){
            if(Aux.borrado == 1){
                MostrarUnRegistro(Aux);
            }
        }

        fclose(archi);
    }else{
        printf("El archivo se abrio incorrectamente\n");
    }
}


///FUNCION PARA CARGAR UN REGISTRO DE SERVICIOS

StRegistroServicio CargarUnRegistro(){

    StRegistroServicio Aux;

    Aux.borrado = 1;
    printf("Ingrese el numero de piso para el servicio: ");
    scanf("%d",&Aux.Piso);
    printf("Ingrese el nombre del servicio: ");
    fflush(stdin);
    gets(Aux.Servicio);
    printf("Ingrese el valor unitario del servicio: ");
    scanf("%f",&Aux.PrecioUni);
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

    FILE * archi = fopen(Array,"ab");

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

///FUNCION PARA CARGAR UN SERVICIO NUEVO

void CargarServicioNuevo(StRegistroServicio Aux){

    FILE * archi = fopen(Array,"ab");

    if(archi!=NULL){
        fwrite(&Aux,sizeof(StRegistroServicio),1,archi);
        fclose(archi);
    }else{
        printf("El archivo se abrio incorrectamente\n");
    }
}

///FUNCION PARA CAMBIAR LOS DATOS DEL ALTA

StRegistroServicio CambiarValores(StRegistroServicio Aux, StRegistroServicio Dato){

    Aux.borrado = 1;
    Aux.PrecioUni = Dato.PrecioUni;
    Aux.Precio = Dato.Precio;
    strcpy(Aux.SubServicio,Dato.SubServicio);

return Aux;

}

///FUNCION PARA DAR EL ALTA A UN SERVICIO

void DarAltaServicio(int pos,StRegistroServicio Dato){

    StRegistroServicio Aux;

    FILE * archi = fopen(Array,"r+b");

    if(archi!=NULL){

        fseek(archi,(pos)*sizeof(StRegistroServicio),SEEK_SET);
        fread(&Aux,sizeof(StRegistroServicio),1,archi);
        Aux = CambiarValores(Aux,Dato);
        fseek(archi,-1*sizeof(StRegistroServicio),SEEK_CUR);
        fwrite(&Aux,sizeof(StRegistroServicio),1,archi);

        fclose(archi);
    }else{
        printf("El archivo se abrio incorrectamente\n");
    }
}

///FUNCION PARA CARGAR UN DATO AL ARCHIVO

void CargarUnRegistroArchivo(StRegistroServicio Aux){

    int pos = BuscarDatoArchivo(Aux.Servicio);

    if(pos == -1){
        CargarServicioNuevo(Aux);
    }else{
        DarAltaServicio(pos,Aux);
    }
}

///FUNCION PARA BUSCAR UN DATO DENTRO DEL ARCHIVO

int BuscarDatoArchivo(char Servicio[]){

    StRegistroServicio Aux;
    int pos = -1;
    int i = 0;

    FILE * archi = fopen(Array,"rb");

    if(archi!=NULL){
        while(fread(&Aux,sizeof(StRegistroServicio),1,archi)>0 && strcmpi(Aux.Servicio,Servicio)!=0){
            i++;
        }

        if(strcmpi(Aux.Servicio,Servicio) == 0){
            pos = i;
        }

        fclose(archi);
    }else{
        printf("El archivo se abrio incorrectamente\n");
    }

return pos;
}


///FUNCION PARA BORRAR UN DATO DEL ARCHIVO

void BorrarUnRegistroArchivo(char Servicio[]){

    StRegistroServicio Aux;

    FILE * archi = fopen(Array,"r+b");

    if(archi!=NULL){

        int pos = BuscarDatoArchivo(Servicio);

        fseek(archi,(pos)*sizeof(StRegistroServicio),SEEK_SET);
        fread(&Aux,sizeof(StRegistroServicio),1,archi);
        if(Aux.borrado == 0){
            printf("El dato buscado no corresponde con un servicio\n");
        }else{
            Aux.borrado = 0;
            fseek(archi,-1*sizeof(StRegistroServicio),SEEK_CUR);
            fwrite(&Aux,sizeof(StRegistroServicio),1,archi);
        }

        fclose(archi);

    }else{
        printf("El archivo se abrio incorrectamente\n");
    }
}





