#include "ArchivoServicios.h"

const char Servicios[40] = "Servicios.bin";
const char Adicionales[40] = "Adicionales.bin";

///FUNCION PARA CARGAR UN REGISTRO DE SERVICIOS

StRegistroServicio CargarUnRegistroServicio(){

    StRegistroServicio Aux;
    int valor,pos,num;

    Aux.Borrado = 1;

    do{
        printf("Ingrese el nombre del servicio: ");
        fflush(stdin);
        gets(Aux.Servicio);

        pos = BuscarDatoArchivo(Aux.Servicio);

        if(pos != -1){
            valor = ValidarEstadoServicio(Aux.Servicio,pos);
        }

        if(pos != -1 && valor == 1){
            printf("El servicio ingresado ya existe, vuelva a ingresarlo. \n");
        }

    }while(pos != -1 && valor == 1);

    do{
        printf("Ingrese el id del servicio nuevo: ");
        scanf("%d",&Aux.Id);

        num = BuscarIdServicio(Aux.Id);

    }while(num == 1);

    do{
        printf("Ingrese el numero de piso para el servicio: ");
        scanf("%d",&Aux.Piso);
    }while(Aux.Piso < 0 || Aux.Piso > 2);

    printf("Ingrese el valor unitario del servicio: ");
    scanf("%f",&Aux.PrecioUni);

return Aux;
}

///FUNCION PARA CARGAR UN REGISTRO DE SERVICIO ADICIONAL

StRegistroAdicional CargarRegistroAdicional(int Id){

    StRegistroAdicional Aux;
    int pos,valor;

    Aux.Borrado = 1;
    Aux.IdServicio = Id;

    do{
        printf("Ingrese el nombre del subservicio: ");
        fflush(stdin);
        gets(Aux.SubServicio);

        pos = BuscarDatoArchivoAdicional(Aux.SubServicio,Aux.IdServicio);

        if(pos != -1){
            valor = ValidarEstadoServicioAdicional(Aux.SubServicio,pos);
        }

        if(pos != -1 && valor == 1){
            printf("El servicio ingresado ya existe, vuelva a ingresarlo. \n");
        }

    }while(pos != -1 && valor == 1);

    printf("Ingrese el costo del subservicio: ");
    scanf("%f",&Aux.Precio);

return Aux;
}

///FUNCION PARA CARGAR VARIOS DATOS DENTRO DEL ARCHIVO

void CargarUnArchivo(){

    char control = 's';

    while(control == 's'){
        CargarUnArchivoServicio();
        printf("Quiere seguir cargando datos?? ");
        fflush(stdin);
        scanf("%c",&control);

        while(control != 's' && control != 'n'){
            printf("Opcion incorrecta, ingrese nuevamente su opcion: ");
            fflush(stdin);
            scanf("%c",&control);
        }
    }
}

///FUNCION PARA CARGAR UN ARCHIVO

void CargarUnArchivoServicio(){

    char Op;

    FILE * archi = fopen(Servicios,"ab");

    if(archi!=NULL){

        StRegistroServicio Aux = CargarUnRegistroServicio();
        if(Aux.Borrado == 1){
            fwrite(&Aux,sizeof(StRegistroServicio),1,archi);
        }else{
            DarAltaServicio(Aux);
        }
        printf("Quiere cargar un servicio adicional al servicio primario?? ");
        fflush(stdin);
        scanf("%c",&Op);

        while(Op != 's' && Op != 'n'){
            printf("Opcion incorrecta, ingrese nuevamente su opcion: ");
            fflush(stdin);
            scanf("%c",&Op);
        }

        if(Op == 's'){
            CargarUnArchivoAdicional(Aux.Id);
        }
    fclose(archi);

    }else{
        printf("El archivo se abrio incorrectamente\n");
    }
}

///FUNCION PARA CARGAR UN ARCHIVO DE SERVICIOS ADICIONALES

void CargarUnArchivoAdicional(int Id){

    char Op = 's';

    FILE *archi = fopen(Adicionales,"ab");

    if(archi!=NULL){
        while(Op == 's'){

            StRegistroAdicional Aux = CargarRegistroAdicional(Id);
            if(Aux.Borrado == 1){
                fwrite(&Aux,sizeof(StRegistroAdicional),1,archi);
            }else{
                DarAltaServicioAdicional(Aux);
            }

            printf("Quiere seguir cargando servicios adicionales?? ");
            fflush(stdin);
            scanf("%c",&Op);

            while(Op != 's' && Op != 'n'){
                printf("Opcion incorrecta, ingrese nuevamente su opcion: ");
                fflush(stdin);
                scanf("%c",&Op);
            }
        }
        fclose(archi);
    }else{
        printf("El archivo se abrio incorrectamente\n");
    }

}

///FUNCION PARA BUSCAR UN SERVICIO DENTRO DEL ARCHIVO

int BuscarDatoArchivo(char Servicio[]){

    StRegistroServicio Aux;
    int pos = -1;
    int i = 0;

    FILE * archi = fopen(Servicios,"rb");

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

///FUNCION PARA BUSCAR UN SERVICIO ADICIONAL DENTRO DEL ARCHIVO

int BuscarDatoArchivoAdicional(char Servicio[],int Id){

    StRegistroAdicional Aux;
    int pos = -1;
    int i = 0;

    FILE * archi = fopen(Adicionales,"rb");

    if(archi!=NULL){
        while(fread(&Aux,sizeof(StRegistroAdicional),1,archi)>0 && strcmpi(Aux.SubServicio,Servicio)!=0){
            i++;
        }

        if(strcmpi(Aux.SubServicio,Servicio) == 0 && Aux.IdServicio == Id){
            pos = i;
        }

        fclose(archi);
    }else{
        printf("El archivo se abrio incorrectamente\n");
    }

return pos;
}

///FUNCION PARA VALIDAR ESTADO DEL SERVICIO

int ValidarEstadoServicio(char Servicio[],int pos){

    StRegistroServicio Aux;
    int valor;

    FILE*archi = fopen(Servicios,"rb");

    if(archi!=NULL){
        fseek(archi,pos*sizeof(StRegistroServicio),SEEK_SET);
        fread(&Aux,sizeof(StRegistroServicio),1,archi);
        valor = Aux.Borrado;

        fclose(archi);
    }else{
        printf("El archivo se abrio incorrectamente\n");
    }
return valor;
}

///FUNCION PARA VALIDAR ESTADO DEL SERVICIO ADICIONAL

int ValidarEstadoServicioAdicional(char Servicio[],int pos){

    StRegistroAdicional Aux;
    int valor;

    FILE*archi = fopen(Adicionales,"rb");

    if(archi!=NULL){
        fseek(archi,pos*sizeof(StRegistroAdicional),SEEK_SET);
        fread(&Aux,sizeof(StRegistroAdicional),1,archi);
        valor = Aux.Borrado;

        fclose(archi);
    }else{
        printf("El archivo se abrio incorrectamente\n");
    }
return valor;
}

///FUNCION PARA BUSCAR ID DENTRO DEL ARCHIVO DE SERVICIOS

int BuscarIdServicio(int Id){

    StRegistroServicio Aux;
    int flag =0;

    FILE * archi = fopen(Servicios,"rb");

    if(archi!=NULL){
        while(flag == 0 && fread(&Aux,sizeof(StRegistroServicio),1,archi)>0){
            if(Aux.Id == Id && Aux.Borrado == 1){
                flag = 1;
            }
        }
        fclose(archi);
    }else{
        printf("El archivo se abrio incorrectamente\n");
    }

return flag;
}

///FUNCION PARA CAMBIAR LOS DATOS DEL ALTA

StRegistroServicio CambiarValores(StRegistroServicio Aux, StRegistroServicio Dato){

    Aux.Borrado = 1;
    Aux.PrecioUni = Dato.PrecioUni;
    Aux.Id = Dato.Id;
    Aux.Piso = Dato.Piso;

return Aux;

}

///FUNCION PARA DAR EL ALTA A UN SERVICIO

void DarAltaServicio(StRegistroServicio Dato){

    int pos = BuscarDatoArchivo(Dato.Servicio);

    StRegistroServicio Aux;

    FILE * archi = fopen(Servicios,"r+b");

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

///FUNCION PARA CAMBIAR LOS DATOS DEL ALTA

StRegistroAdicional CambiarValoresAdicionales(StRegistroAdicional Aux, StRegistroAdicional Dato){

    Aux.Borrado = 1;
    Aux.Precio = Dato.Precio;
    Aux.IdServicio = Dato.IdServicio;

return Aux;

}

///FUNCION PARA DAR EL ALTA A UN SERVICIO ADICIONAL

void DarAltaServicioAdicional(StRegistroAdicional Dato){

    int pos = BuscarDatoArchivoAdicional(Dato.SubServicio,Dato.IdServicio);

    StRegistroAdicional Aux;

    FILE * archi = fopen(Adicionales,"r+b");

    if(archi!=NULL){

        fseek(archi,(pos)*sizeof(StRegistroAdicional),SEEK_SET);
        fread(&Aux,sizeof(StRegistroAdicional),1,archi);
        Aux = CambiarValoresAdicionales(Aux,Dato);
        fseek(archi,-1*sizeof(StRegistroAdicional),SEEK_CUR);
        fwrite(&Aux,sizeof(StRegistroAdicional),1,archi);

        fclose(archi);
    }else{
        printf("El archivo se abrio incorrectamente\n");
    }
}

///FUNCION PARA MOSTRAR UN REGISTRO DE SERVICIO

void MostrarUnRegistroServicio(StRegistroServicio Aux){

    puts("--------------------------------------");
    printf("NOMBRE DEL SERVICIO: %s \n",Aux.Servicio);
    printf("PISO NUMERO: %d \n",Aux.Piso);
    printf("PRECIO UNITARIO DEL SERVICIO: %.2f \n",Aux.PrecioUni);
    puts("--------------------------------------");

}

///FUNCION PARA MOSTRAR UN REGISTRO DE SERVICIO ADICIONAL

void MostrarUnRegistroServicioAdicional(StRegistroAdicional Aux){

    puts("--------------------------------------");
    printf("NOMBRE DEL SUBSERVICIO: %s \n",Aux.SubServicio);
    printf("PRECIO: %.2f \n",Aux.Precio);
    puts("--------------------------------------");

}

///FUNCION PARA MOSTRAR UN ARCHIVO DE SERVICIOS

void MostrarUnArchivoServicios(){

    StRegistroServicio Aux;

    FILE * archi = fopen(Servicios,"rb");

    if(archi!=NULL){
        while(fread(&Aux,sizeof(StRegistroServicio),1,archi)>0){
            if(Aux.Borrado == 1){
                MostrarUnRegistroServicio(Aux);
                MostrarUnArchivoAdicional(Aux.Id);
            }
        }

        fclose(archi);
    }else{
        printf("El archivo se abrio incorrectamente\n");
    }
}

///FUNCION PARA MOSTRAR UN ARCHIVO DE SERVICIOS ADICIONALES

void MostrarUnArchivoAdicional(int Id){

    StRegistroAdicional Aux;

    FILE*archi = fopen(Adicionales,"rb");

    if(archi!=NULL){
        while(fread(&Aux,sizeof(StRegistroAdicional),1,archi)>0){
            if(Aux.IdServicio == Id && Aux.Borrado == 1){
                MostrarUnRegistroServicioAdicional(Aux);
            }
        }

        fclose(archi);
    }else{
        printf("El archivo se abrio incorrectamente\n");
    }
}

///FUNCION PARA CARGAR UN SERVICIO NUEVO

void CargarServicioNuevo(StRegistroServicio Aux){

    FILE * archi = fopen(Servicios,"ab");

    if(archi!=NULL){
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
        DarAltaServicio(Aux);
    }
}

///FUNCION PARA BORRAR UN DATO DEL ARCHIVO

void BorrarUnRegistroArchivo(char Servicio[]){

    StRegistroServicio Aux;

    FILE * archi = fopen(Servicios,"r+b");

    if(archi!=NULL){

        int pos = BuscarDatoArchivo(Servicio);

        fseek(archi,(pos)*sizeof(StRegistroServicio),SEEK_SET);
        fread(&Aux,sizeof(StRegistroServicio),1,archi);
        Aux.Borrado = 0;
        fseek(archi,-1*sizeof(StRegistroServicio),SEEK_CUR);
        fwrite(&Aux,sizeof(StRegistroServicio),1,archi);

        fclose(archi);

    }else{
        printf("El archivo se abrio incorrectamente\n");
    }
}

///FUNCION PARA MODIFICAR UN REGISTRO DEL ARCHIVO

void ModificarServicioArchivo(char Servicio[],float nuevo){

    StRegistroServicio Aux;

    FILE*archi = fopen(Servicios,"r+b");

    if(archi!=NULL){
        int pos = BuscarDatoArchivo(Servicio);
        fseek(archi,pos*sizeof(StRegistroServicio),SEEK_SET);
        fread(&Aux,sizeof(StRegistroServicio),1,archi);
        Aux.PrecioUni = nuevo;
        fseek(archi,-1*sizeof(StRegistroServicio),SEEK_CUR);
        fwrite(&Aux,sizeof(StRegistroServicio),1,archi);

        fclose(archi);
    }else{
        printf("El archivo se abrio incorrectamente\n");
    }

}

///FUNCION PARA CARGAR UN SERVICIO ADICIONAL NUEVO

void CargarServicioAdicionalNuevo(StRegistroAdicional Aux){

    FILE*archi = fopen(Adicionales,"ab");

    if(archi!=NULL){
        fwrite(&Aux,sizeof(StRegistroAdicional),1,archi);
        fclose(archi);
    }else{
        printf("El archivo se abrio incorrectamente\n");
    }

}

///FUNCION PARA CARGAR UN SERVICIO ADICIONAL AL ARCHIVO

void CargarUnServicioAdicionalArchivo(StRegistroAdicional Aux){

    int pos = BuscarDatoArchivoAdicional(Aux.SubServicio,Aux.IdServicio);

    if(pos == -1){
        CargarServicioAdicionalNuevo(Aux);
    }else{
        DarAltaServicioAdicional(Aux);
    }

}

///FUNCION PARA BORRAR UN DATO DEL ARCHIVO

void BorrarUnRegistroAdicionalArchivo(char Servicio[],int Id){

    StRegistroAdicional Aux;

    FILE * archi = fopen(Adicionales,"r+b");

    if(archi!=NULL){

        int pos = BuscarDatoArchivoAdicional(Servicio,Id);

        fseek(archi,(pos)*sizeof(StRegistroAdicional),SEEK_SET);
        fread(&Aux,sizeof(StRegistroAdicional),1,archi);
        Aux.Borrado = 0;
        fseek(archi,-1*sizeof(StRegistroAdicional),SEEK_CUR);
        fwrite(&Aux,sizeof(StRegistroAdicional),1,archi);

        fclose(archi);

    }else{
        printf("El archivo se abrio incorrectamente\n");
    }
}

///FUNCION PARA MODIFICAR UN REGISTRO DEL ARCHIVO

void ModificarServicioAdicionalArchivo(char Servicio[],float nuevo,int Id){

    StRegistroAdicional Aux;

    FILE*archi = fopen(Adicionales,"r+b");

    if(archi!=NULL){
        int pos = BuscarDatoArchivoAdicional(Servicio,Id);
        fseek(archi,pos*sizeof(StRegistroAdicional),SEEK_SET);
        fread(&Aux,sizeof(StRegistroAdicional),1,archi);
        Aux.Precio = nuevo;
        fseek(archi,-1*sizeof(StRegistroAdicional),SEEK_CUR);
        fwrite(&Aux,sizeof(StRegistroAdicional),1,archi);

        fclose(archi);
    }else{
        printf("El archivo se abrio incorrectamente\n");
    }

}





