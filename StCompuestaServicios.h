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
NodoP* CargarListaServiciosAdicionalesConArchivo(NodoP * lista,StRegistroServicio Dato);
NodoP* CargarDatoListaServicios(NodoP*lista);
NodoP* AltaDeRegistroServicio (NodoP * lista, StRegistroServicio Aux,StRegistroAdicional Dato);
NodoP* BorrarUnDatoServicio(NodoP* lista);
NodoP* ModificarServicioPrincipal(NodoP*lista);
NodoP* ModificarServicioAdicional(NodoP*lista);
NodoP* CargarNuevoSubServicio(NodoP*lista);
NodoP* BorrarUnDatoServicioAdicional(NodoP* lista);
StServicio CargarUnServicio (StRegistroServicio Aux);
StSubServicio CargarUnSubservicio (StRegistroAdicional Aux);

#endif // STCOMPUESTASERVICIOS_H_INCLUDED
