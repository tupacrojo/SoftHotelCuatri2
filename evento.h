#ifndef EVENTO_H_INCLUDED
#define EVENTO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>


/// ESTRUCTURAS:

typedef struct
{
    char mes[10];
    int idMes;
    int dia;
    char tipoEvento [20];
    char horaInicio[6];
    char horaFin[6];
    int cantPersonas;
    int precio;
    char nombre[20];
    char apellido[20];
    char telefono[20];
    char dni[10];

} stRegistroEvento;  /// estructura para cargar el archivo

typedef struct
{
    int dia;
    char tipoEvento [20];
    char horaInicio[6];
    char horaFin[6];
    int cantPersonas;
    int precio;
    char nombre[20];
    char apellido[20];
    char telefono[20];
    char dni[10];

} stClienteEvento;  /// datos del evento y del cliente que contrata el evento

typedef struct stEvento
{
    stClienteEvento dato;
    struct stEvento * siguiente;

} stEvento;  /// lista

typedef struct
{
    int idMes;
    char mes[10];
}stDatosMes;   /// datos del mes

typedef struct
{
    stDatosMes datoMes;
    stEvento * listaDeDias;

} celdaEvento;  /// arreglo


///PROTOTIPADO:

stEvento * inicListaEvento ();
stEvento * crearNodoEvento (stClienteEvento aux);
stEvento * agregarAlPrincipioEvento(stEvento * lista, stEvento * nuevoEvento);
stEvento * agregarEnOrdenEvento (stEvento * lista, stEvento * nuevoEvento);
void mostrarUnEvento (stClienteEvento aux);
void mostrarListaEvento (stEvento * lista);
stEvento * borrarUnEvento (stEvento * lista, int dia);
stEvento * buscarUnEvento (stEvento * lista, int dia);
stRegistroEvento cargarUnEvento();
void cargarArchivo ();
int pasarDatosDeArchivoAarregloEventos(celdaEvento eventos [],int dim, int validos);
int altaEventos(celdaEvento eventos[], int dim, int validos, stClienteEvento cliente , stDatosMes datoMes);
int buscaPosMes(celdaEvento eventos[],int idMes, int validos);
int agregarMes (celdaEvento eventos[], int dim, char mesElegido[], int validos);
void buscarMesYmostrar(celdaEvento eventos[], int validos, int idMes);
void mostrarMesyDias(celdaEvento eventos[], int validos);
void guardarProximosEventos (char archivo[], stRegistroEvento aux);
void guardarEventosEnArchivo (celdaEvento eventos[], int validos);
void buscarYmostrarFechaDisponibleEvento(celdaEvento eventos[], int validos, int idMes, int dia);
int insertarEventoOrdenado(celdaEvento eventos[], int validos, stDatosMes datoMes);
int sumarCantidadEventosDeUnMes(celdaEvento eventos[], int validos, int idMes);

#endif // EVENTO_H_INCLUDED
