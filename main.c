/// LIBRERIAS DE CODEBLOCKS

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

/// LIBRERIAS PARA LISTA DE LISTAS

#include "ArchivoServicios.h"
#include "ListasServicios.h"
#include "StCompuestaServicios.h"
#include "src/lib/habitacion.h"

/// ESTRUCTURA DE CARACTERISTICAS
typedef struct
{
    int id;
    int borrado;
    char tipo[30];
} stRegCaracteristicas;
/// ESTRUCTURA DE HABITACIONES

typedef struct
{

    int id;
    int borrado;
    int estado;
    int piso;
    stRegCaracteristicas caracteristicas[10];
} stRegHabitacion;

/// ESTRUCTURA DE LA RESERVA

typedef struct
{
    stRegHabitacion habitacion;
    int borrado;
    /// ENTRADA
    int diaEntrada;
    int mesEntrada;
    int anioEntrada;
    /// SALIDA
    int diaSalida;
    int mesSalida;
    int anioSalida;
} stReserva;

/// ESTRUCTURA DE USUARIO

typedef struct
{
    int id;
    int borrado; /// PREGUNTAR
    int tipo;
    char contrasena[20];
    char nombre[50];
    char apellido[50];
    char DNI[10];
    float totalconsumo;
    stReserva reserva;
    int edad;
    char telefono[20];
    char genero;
    int hijos;
    char estadoCivil[20];
} stUsuario;

/// FUNCIONES DE MENU

void Menu();
void MenuServicios();
void MenuSubServicio();
void MenuServAdicional();

/// FUNCIONES

void Funcion1(NodoP *lista);
void Funcion2(NodoP *lista);
void Funcion3(NodoP *lista);
#include <string.h>
#include "src/lib/reserva.h"
#include "src/lib/utils.h"
#include "src/lib/usuario.h"

/** \fn void registro()
 * \brief Si ninguno de los tres archivos esta creado, los crea y los rellena con datos iniciales
 */
void registro()
{
    if (existeArchivo(aUsuarios) == -1 &&
        existeArchivo(aConsumibles) == -1 &&
        existeArchivo(aHabitaciones) == -1)
    {
        system("mkdir data"); // crea la carpeta data dentro del proyecto
        /* Datos iniciales, que ahora se comentan por la funcion pedida por mail
        agregarConsumibleArchivo2(agregarConsumiblePorParametro(0, "Agua", "Bebible", 0));
        agregarHabitacionArchivo2(agregarHabitacionPorParametro(0, 0, 0));
        agregarUsuarioArchivo2(agregarUsuarioPorParametro(0, 2, "Admin", "Admin", "admin", "1234", 0, "0", 'o', 0, "0"));
        cargaDeDatosDePrueba();
        */
    }
}

void crearBackupEscritorio()
{
    char rutaEscritorio[1000];
    if (encontrarDireccionEscritorio(rutaEscritorio) == 0)
    {
        strcat(rutaEscritorio, "\\backup\\usuarios.bin");
        backupArchivos(aUsuarios, rutaEscritorio);
    }
}
#include <string.h>
#include "evento.h"

typedef struct
{
    int piso;
    int cantidadHabitaciones;
    int idHabitacion;
    int cantidadHuesped;
    int ocupado;
    int habilitada;
} pisoRegistro;

typedef struct
{
    int idHabitacion;
    int cantidadHuesped;
    int ocupado;
    int habilitada;
} stHabitacion;

typedef struct nodoListaHabitacion
{
    struct nodoListaHabitacion *sig;
    stHabitacion dato;
} nodoListaHabitacion;

int main()
{
 printf("Hello World");
    return 0;
}

/// FUNCIONES PARA EL MENU DE SERVICIOS

void MenuServicios()
{

    int op;

    NodoP *lista = InicListaPrincipal();
    lista = CargarListaServicioConArchivo(lista);

    Menu();
    printf("\nIngrese una opcion: ");
    scanf("%d", &op);
    Pause();

    switch (op)
    {

    case 1:
    {
        Funcion1(lista);
        break;
    }
    case 2:
    {
        Funcion2(lista);
        break;
    }
    case 3:
    {
        Funcion3(lista);
        break;
    }
    case 4:
    {
        break;
    }
    case 5:
    {
        MenuSubServicio();
        break;
    }
    default:
    {

        break;
    }
    }
}

void Menu()
{

    printf("1. Visualizar todos los servicios\n");
    printf("2. Cargar un nuevo servicio\n");
    printf("3. Borrar un servicio\n");
    printf("4. Modificar un servicio por valor unitario\n");
    printf("5. Menu de servicios adicionales\n");
}

/// FUNCION 1

void Funcion1(NodoP *lista)
{

    MostrarListaServicio(lista);
}

/// FUNCION 2

void Funcion2(NodoP *lista)
{

    lista = CargarDatoListaServicios(lista);
    Pause();
    MostrarListaServicio(lista);
}

/// FUNCION 3

void Funcion3(NodoP *lista)
{

    char Servicio[25];

    printf("Ingrese un servicio a borrar: ");
    fflush(stdin);
    gets(Servicio);
    lista = BorrarUnDatoServicio(lista, Servicio);
    MostrarListaServicio(lista);
}
/**
///FUNCION 4

void Funcion4(NodoP*lista){





}
**/
/// FUNCION 5

void MenuSubServicio()
{

    int op;

    MenuServAdicional();
    printf("\nIngrese una opcion: ");
    scanf("%d", &op);
    Pause();

    switch (op)
    {

    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    default:
        break;
    }
}

/// FUNCION MENU SUBSERVICIO

void MenuServAdicional()
{
    printf("1. Visualizar todos los servicios adicionales\n");
    printf("2. Cargar un nuevo servicio adicional\n");
    printf("3. Borrar un servicio adicional\n");
    printf("4. Modificar un servicio adicional por valor unitario\n");
}

/// verificar Caracter

int verificarCaracter()
{
    int entrada;
    printf("Ingresa un caracter: ");
    while ((entrada = _getch()) != 42) // Espera hasta que se presione Esc (código ASCII 27)
    {
        if ((entrada >= 'a' && entrada <= 'z') || (entrada >= 'A' && entrada <= 'Z'))
        {
            printf("%c\n", entrada);
            return entrada;
        }
        else if (entrada == '\r')
        {
            printf("\n");
        }
        else
        {
            printf("Entrada Incorrecta\n");
            printf("Ingresa un caracter: ");
        }
    }
    printf("\nOperacion cancelada.\n");
    return -1;
}