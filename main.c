#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "evento.h"

const char nombreArchivo[20] = {"eventos.bin"};

int main()

{


 int validos =0;
 celdaEvento eventos[11];
 //cargarArchivo();
 validos = pasarDatosDeArchivoAarregloEventos(eventos,11,validos);
 mostrarMesyDias(eventos,validos);

 /// FUNCION PARA VER LOS EVENTOS DE UN MES:

 /* int mes=0;
  printf("Ingrese un numero de mes: \n ");
  scanf("%i",&mes);
  buscarMesYmostrar(eventos,validos,mes);
*/
  ///FUNCION PARA BUSCAR SI UNA FECHA ESTA DISPONIBLE PARA UN EVENTO:

  int dia=0; int mesB=0;
  printf("Ingrese un numero de mes: \n ");
  scanf("%i",&mesB);
  printf("Ingrese un dia: \n ");
  scanf("%i",&dia);
  buscarYmostrarFechaDisponibleEvento(eventos,validos,mesB,dia);


    return 0;
}
