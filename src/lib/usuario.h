#pragma once

#include <stdlib.h>
#include <stdio.h>
#include "../config/files.h"
#include "reserva.h"

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
    int edad; // años
    char telefono[20];
    char genero; // m = masculino , f = femenino, o = otros
    int hijos;
    char estadoCivil[20]; // 0 soltero, 1 divorciado, 2 viudo, 3 casado
}stUsuario;


void cambiarBorradoReserva(int id);
int borrarReserva(char documento[]);
int crearReserva(int id);
void mostrarReserva(stReserva r);
void mostrarReservaEnArchivo();
void agregarUsuario(stUsuario *u);
stUsuario agregarUsuarioPorParametro(int id, int tipo, char nombre[], char apellido[], char dni[], char contrasena[], int edad, char telefono[], char genero, int hijos, char estadoCivil[]);
void agregarUsuarioArchivo();
void agregarUsuarioArchivo2(stUsuario u);
float extraerConsumoUsuario(int id);
int buscarUsuarioDocumento(char documento[]);
int buscarUsuarioCelular(char celular[]);

void cambiarBorradoUsuario(int id);
int cambiarConsumoUsuario(int id, float consumo);
int cambiarContrasenaUsuario(int id, char nuevaContrasena[]);
int cambiarNombreUsuario(int id, char nuevoNombre[]);
int cambiarApellidoUsuario(int id, char nuevoApellido[]);
int cambiarDNIUsuario(int id, char nuevoDNI[]);
int cambiarEstadoCivilUsuario(int id, char nuevoEstadoCivil[]);
int cambiarGeneroUsuario(int id, char nuevoGenero);
int cambiarTelefonoUsuario(int id, char nuevoTelefono[]);
int cambiarHijosUsuario(int id, int nuevaCantHijos);
int cambiarTipoUsuario(int id, int nuevoTipo);
int cambiarDatosDeUsuario(int selector, int id);

void mostrarUsuario(stUsuario u);
void mostrarUsuarios();
stUsuario iniciarSesion();
int obtenerTipoUsuario(int id);
stUsuario extraerUsuario(int id);
int verificarContrasena(int id, char contrasena[]);
int borrarUsuario(int id);
void borraDatosUsuario(stUsuario *u);
