#ifndef ARCHIVOSERVICIOS_H_INCLUDED
#define ARCHIVOSERVICIOS_H_INCLUDED

///LIBRERIAS NECESARIAS

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

///ESTRUCTURA DE REGISTRO DE SERVICIOS

typedef struct{

    int Piso;
    int Id;
    int Borrado;
    char Servicio[25];
    float PrecioUni;

}StRegistroServicio;

typedef struct {

    int IdServicio;
    int Borrado;
    char SubServicio[25];
    float Precio;

}StRegistroAdicional;

///PROTOTIPADO

///FUNCIONES PARA EL ARCHIVO

StRegistroServicio CargarUnRegistroServicio();
StRegistroServicio CambiarValores(StRegistroServicio Aux, StRegistroServicio Dato);
StRegistroAdicional CargarRegistroAdicional(int Id);
StRegistroAdicional CambiarValoresAdicionales(StRegistroAdicional Aux, StRegistroAdicional Dato);
void CargarUnArchivo();
void CargarUnArchivoServicio();
void CargarUnArchivoAdicional(int Id);
void DarAltaServicio(StRegistroServicio Dato);
void DarAltaServicioAdicional(StRegistroAdicional Dato);
void MostrarUnArchivoAdicional(int Id);
void MostrarUnArchivoServicios();
void CargarUnRegistroArchivo(StRegistroServicio Aux);
void CargarUnServicioAdicionalArchivo(StRegistroAdicional Aux);
void CargarServicioNuevo(StRegistroServicio Aux);
void CargarServicioAdicionalNuevo(StRegistroAdicional Aux);
void BorrarUnRegistroArchivo(char Servicio[]);
void BorrarUnRegistroAdicionalArchivo(char Servicio[],int Id);
void BorrarConjuntoDeRegistros (int Id);
void ModificarServicioArchivo(char Servicio[],float nuevo);
void ModificarServicioAdicionalArchivo(char Servicio[],float nuevo,int Id);
void MostrarUnRegistroServicio(StRegistroServicio Aux);
void MostrarUnRegistroServicioAdicional(StRegistroAdicional Aux);
int BuscarDatoArchivo(char Servicio[]);
int BuscarIdServicio(int Id);
int BuscarDatoArchivoAdicional(char Servicio[],int Id);
int ValidarEstadoServicio(char Servicio[],int pos);
int ValidarEstadoServicioAdicional(char Servicio[],int pos);


#endif // ARCHIVOSERVICIOS_H_INCLUDED
