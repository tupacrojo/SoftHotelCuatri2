#include <stdio.h>
#include <stdlib.h>

typedef struct /// "stUsuario" usuario
{
    int id;   // auto incrementable
    int borrado;
    int tipo; // GodMan(), administrador(sueldos, dar de alta y baja empleado), recepcionista(Check In, Check Out), Huesped(consumos)
    char contrasena[20];
    char nombre[50]; // lo que va antes del apellido
    char apellido[50];
    char DNI[10];
    float totalconsumo;
    stReserva reserva;
    int edad; // a�os
    char telefono[20];
    char genero; // m = masculino , f = femenino, o = otros
    int hijos;
    char estadoCivil[20]; // 0 soltero, 1 divorciado, 2 viudo, 3 casado
}stUsuario;

int main()
{
    printf("Hello world!\n");
    return 0;
}
