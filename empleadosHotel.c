#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleadosEstruct.h"

const char nombreArchivo [30]="archivoEmpleados.bin";

int main()
{

    return 0;
}


nodoArbol* inicArbol()
{
    return NULL;
}


nodoArbol*crearNodoArbol (stEmpleado aux)
{
    nodoArbol * nuevo= (nodoArbol*)malloc(sizeof(nodoArbol));
    nuevo->dato.id=aux.id;
    nuevo->dato.borrado=aux.borrado;
    nuevo->dato.tipo=aux.tipo;
    strcpy(nuevo->dato.contrasena,aux.contrasena);
    strcpy(nuevo->dato.apellido,aux.apellido);
    strcpy(nuevo->dato.nombre,aux.nombre);
    strcpy(nuevo->dato.dni,aux.dni);
    strcpy(nuevo->dato.telefono,aux.telefono);
    nuevo->dato.genero=aux.genero;
    strcpy(nuevo->dato.estadoCivil,aux.estadoCivil);
    nuevo->der=inicArbol();
    nuevo->izq=inicArbol();

    return nuevo;
}

nodoArbol*insertarNodoArbol (nodoArbol*arbol, nodoArbol*nuevo)
{
    if(arbol==NULL)
    {
        arbol=nuevo;
    }else{
    if(arbol->dato.id>nuevo->dato.id)
    {
        arbol->der=insertarNodoArbol(arbol,nuevo);
    }else{
        arbol->izq=insertarNodoArbol(arbol,nuevo);
    }

    }

return arbol;
}


int alta(stCeldas celdas[],int validos,stEmpleado auxEmpleado,stCeldas tipo)
{
    nodoArbol*aux=crearNodoArbol(auxEmpleado);
    int pos=buscarPosTipoEmpleado(celdas,tipo.tipoDeEmpleado,validos);
    if(pos==-1)
    {
        validos=agregarTipoDeEmpleado(celdas,tipo.tipoDeEmpleado,validos);
        pos=validos-1;
    }
    celdas[pos].arbol=insertarNodoArbol(celdas[pos].arbol,aux);
    return validos;
}

int buscarPosTipoEmpleado(stCeldas celdas[],int tipo,int validos)
{
    int rta=-1;
    int i=0;
    while((i<validos)&&(rta=-1))
    {
        if(celdas[i].tipoDeEmpleado==tipo)
        {
            rta=i;
        }
        i++;
    }

    return validos;
}

int agregarTipoDeEmpleado(stCeldas celdas[],int tipo,int validos)
{
    celdas[validos].tipoDeEmpleado=tipo;
    celdas[validos].arbol=inicArbol();
    validos++;
    return validos;
}

int cargarDatosEmpleadosDesdeArchivo(stCeldas celdas[],int validos, int dim)
{
    FILE * archivo=fopen(nombreArchivo,"rb");
    if(archivo)
    {
        stEmpleado aux;
        stCeldas auxCeldas;
        while((fread(&aux,sizeof(stEmpleado),1,archivo)>0)&&(validos<dim))
        {
            auxCeldas.tipoDeEmpleado=aux.tipo;
            validos=alta(celdas,validos,aux,auxCeldas);
        }

        fclose(archivo);
    }

    return validos;
}

void recorrerYmostrar(stCeldas celdas[],int validos)
{
    for(int i=0;i<validos;i++)
    {
        printf("El tipo de empleado es %i \n",celdas[i].tipoDeEmpleado);
        mostrarArbolEmpleados(celdas[i].arbol);
    }
}



void mostrarArbolEmpleados(nodoArbol*arbol)
{
    mostrarArbolEmpleados(arbol->izq);
    mostrarUnEmpleado(arbol->dato);
    mostrarArbolEmpleados(arbol->der);
}

void mostrarUnEmpleado(stEmpleado dato)
{
    printf("id:%i \n",dato.id);
    printf("apellido y nombre:%s %s\n",dato.apellido,dato.nombre);
    printf("DNI: %s \n",dato.dni);
    printf("telefono:%s \n",dato.telefono);
    printf("genero: %s \n",dato.genero);
    printf("estado civil: %c \n",dato.genero);

}

void mostrarSoloEmpleadosValidos(stEmpleado dato)
{
    if(dato.borrado==0)
    {
    printf("id:%i \n",dato.id);
    printf("apellido y nombre:%s %s\n",dato.apellido,dato.nombre);
    printf("DNI: %s \n",dato.dni);
    printf("telefono:%s \n",dato.telefono);
    printf("genero: %s \n",dato.genero);
    printf("estado civil: %c \n",dato.genero);
    }
}


nodoArbol*buscarUnEmpleadoPorDni(nodoArbol*arbol,char buscado[])
{
    nodoArbol*aux=NULL;
  if(arbol!=NULL)
  {
      if(arbol->dato.dni==buscado)
      {
          aux=arbol;
      }else{
          if(strcmp(buscado,arbol->dato.dni)>=0)
      {
          aux=buscarUnEmpleadoPorDni(arbol->der,buscado);
      }else{
      aux=buscarUnEmpleadoPorDni(arbol->izq,buscado);
      }

      }

  }
    return aux;
}

nodoArbol*modificarUnEmpleado(nodoArbol*arbol)
{
    char dniAbuscar[10];
    printf("ingrese el dni del empleado a modificar: ");
    fflush(stdin);
    gets(dniAbuscar);
    nodoArbol*empleadoAmodificar=buscarUnEmpleadoPorDni(arbol,dniAbuscar);

    //hay q modificar un dato o varios aqui

return arbol;
}

int subirEmpleadoManual(stCeldas celdas[],int validos)
{
    stEmpleado aux;
    stCeldas auxTipo;
    printf("ingrese id del empleado \n");
    fflush(stdin);
    scanf(aux.id);
    printf("ingrese tipo de empleado \n");
    fflush(stdin);
    scanf(aux.tipo);
    auxTipo.tipoDeEmpleado=aux.tipo;
    printf("ingrese la contraseña empleado \n");
    fflush(stdin);
    gets(aux.contrasena);
    printf("ingrese nombre del empleado \n");
    fflush(stdin);
    gets(aux.nombre);
    printf("ingrese apellido del empleado \n");
    fflush(stdin);
    gets(aux.apellido);
    printf("ingrese el telefono del empleado \n");
    fflush(stdin);
    gets(aux.telefono);
    printf("ingrese el genero del empleado \n");
    fflush(stdin);
    getc(aux.genero);
    aux.borrado=0;

    validos=alta(celdas,validos,aux,auxTipo);
    return validos;
}
