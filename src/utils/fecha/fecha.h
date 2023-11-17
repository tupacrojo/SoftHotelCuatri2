#pragma once

#include "time.h"

void leerFecha(struct tm *fecha);
void fechaNow(struct tm *fecha);
void fechaToString(struct tm *fecha, char *fecha_str);
void stringToFecha(char *fechaString, struct tm *fecha);
void asignarFecha(struct tm *fecha, int dia, int mes, int anio);