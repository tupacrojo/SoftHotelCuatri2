#pragma once
#include <stdio.h>
#include <string.h>

#include "../config/files.h"

int existeArchivo(char archivo[]);
int backupArchivos(char nombre_original[], char nombre_copia[]);
void atras(char texto[]);