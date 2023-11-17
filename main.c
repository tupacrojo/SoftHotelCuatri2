#include <stdio.h>
#include <stdlib.h>
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

void crearBackupEscritorio(){
    char rutaEscritorio[1000];
    if (encontrarDireccionEscritorio(rutaEscritorio) == 0)
    {
        strcat(rutaEscritorio, "\backup\usuarios.bin");
        backupArchivos(aUsuarios, rutaEscritorio);
    }
}

int main()
{
    /*
    //existeArchivo(aUsuarios);
    nodoLD *lista = inicListaDoble();
    //agregarUsuarioArchivo();
    //crearReserva(buscarUsuarioDocumento("44860125"));
    lista = cargarListaDobleArchivo(lista,aUsuarios);
    imprimirDesdePrincipio(lista);
    printf("Hello world!\n");
    */
    crearBackupEscritorio();
    return 0;
}
