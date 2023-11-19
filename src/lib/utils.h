#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <shlobj.h>
#include "../config/files.h"
#include "usuario.h"
#include "habitacion.h"

typedef struct
{
    float idPrecio[2][100];
    int cantidad;
    char arrayCategoria[100][50];
    char arrayNombre[100][50];
    int arrayID[100];
}stUtils;

int existeArchivo(char archivo[]);
int backupArchivos(char nombre_original[], char nombre_copia[]);
void atras(char texto[]);
int encontrarDireccionEscritorio(char ruta[]);
int rutaArchivoEnEscritorio(char rutaArchivo[], char nombreArchivo[]);
void cambiarSlash(char ruta[], int validos);

stUtils crearMatrizConsumibles();
stUtils crearArregloDePalabraConsumibles();

void checkIn(stUsuario u);
void checkOut(stUsuario u);
int verificarCaracter();