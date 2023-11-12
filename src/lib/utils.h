#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <shlobj.h>


#include "../config/files.h"

int existeArchivo(char archivo[]);
int backupArchivos(char nombre_original[], char nombre_copia[]);
void atras(char texto[]);
int encontrarDireccionEscritorio(char ruta[]);
int rutaArchivoEnEscritorio(char rutaArchivo[], char nombreArchivo[]);
void cambiarSlash(char ruta[], int validos);