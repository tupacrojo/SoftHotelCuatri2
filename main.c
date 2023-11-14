#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "evento.h"



int main()

{

    int validos =0;
    celdaEvento eventos[11];
//cargarArchivo();

    /// FUNCION PARA CARGAR EL ARREGLO:
    validos = pasarDatosDeArchivoAarregloEventos(eventos,11,validos);

    /// FUNCION PARA MOSTRAR EL ARREGLO COMPLETO:
    mostrarMesyDias(eventos,validos);

    /// FUNCION PARA VER LOS EVENTOS DE UN MES:

    int mes=0;
    printf("Ingrese un numero de mes: \n ");
    scanf("%i",&mes);
    buscarMesYmostrar(eventos,validos,mes);

    ///FUNCION PARA BUSCAR SI UNA FECHA ESTA DISPONIBLE PARA UN EVENTO:

    int dia=0;
    int mesB=0;
    printf("Ingrese un numero de mes: \n ");
    scanf("%i",&mesB);
    printf("Ingrese un dia: \n ");
    scanf("%i",&dia);
    buscarYmostrarFechaDisponibleEvento(eventos,validos,mesB,dia);

    /// FUNCION PARA SUMAR LA CANTIDAD DE EVENTOS DE UN MES:
    int mes2 =0;
    printf("Ingrese un numero de mes: \n ");
    scanf("%i",&mes2);
    int suma= sumarCantidadEventosDeUnMes(eventos,validos,mes2);
    printf("La cantidad de eventos del mes %i es : %i \n",mes2,suma);

/*
    /// FUNCION PARA VER LAS GANANCIAS DE UN MES:
    int ganancia=0;
    ganancia = sumarCantidadGananciasDeUnMes(eventos,validos,mesB);
    printf("La ganancia es de : %i \n",ganancia);

*/
    return 0;
}
