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
    funcionVerEventosMes(eventos,validos);
    ///FUNCION PARA BUSCAR SI UNA FECHA ESTA DISPONIBLE PARA UN EVENTO:
    funcionBuscarFechaDispo(eventos,validos);
    /// FUNCION PARA SUMAR LA CANTIDAD DE EVENTOS DE UN MES:
   funcionSumarCantEventosMes(eventos,validos);
    /// FUNCION PARA VER LAS GANANCIAS DE UN MES:
   funcionSumarGananciasMes(eventos,validos);


    return 0;
}
