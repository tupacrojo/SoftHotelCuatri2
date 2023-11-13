#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "src/lib/reserva.h"
#include "src/lib/utils.h"
#include "src/lib/usuario.h"


int main()
{
    //existeArchivo(aUsuarios);
    nodoLD *lista = inicListaDoble();
    //agregarUsuarioArchivo();
    //crearReserva(buscarUsuarioDocumento("44860125"));
    lista = cargarListaDobleArchivo(lista,aUsuarios);
    imprimirDesdePrincipio(lista);
    printf("Hello world!\n");
    return 0;
}
