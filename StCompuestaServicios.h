#ifndef STCOMPUESTASERVICIOS_H_INCLUDED
#define STCOMPUESTASERVICIOS_H_INCLUDED

///LIBRERIAS NECESARIAS

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

///LIBRERIAS ADICIONALES

#include "ArchivoServicios.h"
#include "ListasServicios.h"

///FUNCIONES DE ESTRUCTURA COMPUESTA

NodoP* CargarListaServicioConArchivo(NodoP * lista);
NodoP* CargarDatoListaServicios(NodoP*lista);
NodoP* AltaDeRegistroServicio (NodoP * lista, StRegistroServicio Aux);
NodoP* BorrarUnDatoServicio(NodoP* lista, char Servicio[]);
StServicio CargarUnServicio (StRegistroServicio Aux);
StRegistroServicio CargarUnServicioManual();
StSubServicio CargarUnSubservicio (StRegistroServicio Aux);

#endif // STCOMPUESTASERVICIOS_H_INCLUDED
