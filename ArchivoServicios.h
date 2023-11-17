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
    int borrado;
    char Servicio[25];
    float PrecioUni;
    char SubServicio[25];
    float Precio;

}StRegistroServicio;

///PROTOTIPADO

///FUNCIONES PARA EL ARCHIVO

void CargarUnArchivo();
void CargarUnRegistroArchivo(StRegistroServicio Aux);
void MostrarUnArchivo();
void DarAltaServicio(int pos,StRegistroServicio Dato);
void CargarServicioNuevo(StRegistroServicio Aux);
void MostrarUnRegistro(StRegistroServicio Aux);
void BorrarUnRegistroArchivo(char Servicio[]);
int BuscarDatoArchivo(char Servicio[]);
StRegistroServicio CargarUnRegistro();
StRegistroServicio CambiarValores(StRegistroServicio Aux, StRegistroServicio Dato);

#endif // ARCHIVOSERVICIOS_H_INCLUDED
