#include <stdio.h>
#include <stdlib.h>

typedef struct ///  "stHabitacion" habitacion
{
    int id;
    int borrado;
    int estado;  // 0 libre; 1 Ocupado;
    int piso;   // pisos
    stRegCaracteristicas *caracteristicas;// este arreglo puede almacenar 
}stRegHabitacion;

typedef struct ///  "stReserva" reserva
{
    stRegHabitacion habitacion;
    int borrado;
    // entrada
    int diaEntrada;
    int mesEntrada;
    int anioEntrada;
    // salida
    int diaSalida;
    int mesSalida;
    int anioSalida;
}stRegReserva;

typedef struct /// "stUsuario" usuario
{
    int id;   // auto incrementable
    int borrado;
    int tipo; // GodMan(), administrador(sueldos, dar de alta y baja empleado), recepcionista(Check In, Check Out), Huesped(consumos)
    char *contrasena;
    char *nombre; // lo que va antes del apellido
    char *apellido;
    char *DNI;
    float totalconsumo;
    stRegReserva reserva;
    int edad; // a�os
    char *telefono;
    char genero; // m = masculino , f = femenino, o = otros
    int hijos;
    char *estadoCivil; // 0 soltero, 1 divorciado, 2 viudo, 3 casado
}stRegUsuario;

typedef struct //este es la estructura que alamcena las caracteristicas de la habitacion 
{
    int id;
    int borrado;
    char *tipo; // "Basica, Deluxe, Suite, Suite Premium"
}stRegCaracteristicas;

int main()
{
    printf("Hello world!\n");
    return 0;
}
