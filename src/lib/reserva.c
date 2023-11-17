#include "reserva.h"

/** \fn void borraDatosReserva(stReserva *r)
 * \brief Recibe una estructura y coloca sus valores en 0, menos el id
 * \param *a estructura Reserva
 */
void borraDatosReserva(stReserva *r)
{
    r->borrado = 0;
    r->anioEntrada = 0;
    r->anioSalida = 0;
    r->diaEntrada = 0;
    r->diaSalida = 0;
    r->mesEntrada = 0;
    r->mesSalida = 0;
    r->habitacion.estado = 0;
    r->habitacion.piso = 0;
    strcpy(r->habitacion.tipo, "");
}

/** \fn int esFechaValida(int dia, int mes, int anio)
 * \brief Recibe una fecha por parametro y verifica existe
 * \param dia dia a verificar
 * \param mes mes a verificar
 * \param anio año a verificar
 * \return "-3" El año es invalido.
 * \return "-2" El mes es invalido.
 * \return "-1" El dia es invalido.
 * \return "0" La fecha es valida.
 */
int esFechaValida(int dia, int mes, int anio)
{
    // Verificar el rango del año
    if (anio < 0)
    {
        return -3; // Año inválido
    }

    // Verificar el rango del mes
    if (mes < 1 || mes > 12)
    {
        return -2; // Mes inválido
    }

    // Verificar el rango del día
    int diasEnMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (mes == 2 && (anio % 4 == 0 && (anio % 100 != 0 || anio % 400 == 0)))
    {
        // Ajustar febrero en años bisiestos
        diasEnMes[1] = 29;
    }
    if (dia < 1 || dia > diasEnMes[mes - 1])
    {
        return -1; // Día inválido
    }

    return 0; // La fecha es válida
}

/** \fn int esFechaPosterior(int dia, int mes, int anio)
 * \brief Recibe una fecha por parametro y verifica si es posterior a la actual
 * \param dia dia a verificar
 * \param mes mes a verificar
 * \param anio año a verificar
 * \return "-3" El año es invalido.
 * \return "-2" El mes es invalido.
 * \return "-1" El fe es invalido.
 * \return "0" La fecha es posterior a la fecha actual.
 * \return "1" la fecha es anterior a la fecha actual
 */
int esFechaPosterior(int dia, int mes, int anio)
{
    if (esFechaValida(dia, mes, anio) == 0)
    {
        time_t currentTime;
        time(&currentTime);
        struct tm *localTime = localtime(&currentTime);

        struct tm fechaRecibida;
        fechaRecibida.tm_hour = 23;
        fechaRecibida.tm_min = 59;
        fechaRecibida.tm_sec = 60;
        fechaRecibida.tm_mday = dia;    // Día del mes (1-31)
        fechaRecibida.tm_mon = mes - 1; // Mes (0-11)
        fechaRecibida.tm_year = anio - 1900;   // Año - 1900

        time_t fechaUnix = mktime(&fechaRecibida);

        if (fechaUnix >= currentTime)
        {
            return 0;
        }
        else
        {
            printf("Ingrese una fecha posterior a la actual\n");
            return 1;
        }
    }
    else
    {
        return -1;
    }
}

/** \fn int esFechaPosteriorA(int diaAn, int mesAn, int anioAn, int diaPos, int mesPos, int anioPos)
 * \brief Recibe dos fechas por parametro y verifica si la anterior es menor a la posterior
 * \param diaAn dia Anterior a verificar
 * \param mesAn mes Anterior a verificar
 * \param anioAn año Anterior a verificar
 * \param diaPos dia Posterior a verificar
 * \param mesPos mes Posterior a verificar
 * \param anioPos año Posterior a verificar
 * \return "-1" La fecha es Anterior a la fecha anterior.
 * \return "0" La fecha es posterior a la fecha anterior.
 */
int esFechaPosteriorA(int diaAn, int mesAn, int anioAn, int diaPos, int mesPos, int anioPos)
{
    if (esFechaValida(diaAn, mesAn, anioAn) == 0 && esFechaValida(diaAn, mesAn, anioAn) == 0)
    {
        struct tm fechaAnterior;
        fechaAnterior.tm_hour = 23;
        fechaAnterior.tm_min = 59;
        fechaAnterior.tm_sec = 60;
        fechaAnterior.tm_mday = diaAn;    // Día del mes (1-31)
        fechaAnterior.tm_mon = mesAn - 1; // Mes (0-11)
        fechaAnterior.tm_year = anioAn - 1900;   // Año - 1900

        struct tm fechaPosterior;
        fechaPosterior.tm_hour = 23;
        fechaPosterior.tm_min = 59;
        fechaPosterior.tm_sec = 60;
        fechaPosterior.tm_mday = diaPos;    // Día del mes (1-31)
        fechaPosterior.tm_mon = mesPos - 1; // Mes (0-11)
        fechaPosterior.tm_year = anioPos - 1900;   // Año - 1900

        time_t fechaUnixAn = mktime(&fechaAnterior);
        time_t fechaUnixPos = mktime(&fechaPosterior);

        if (fechaUnixPos > fechaUnixAn)
        {
            return 0;
        }
        else
        {
            printf("Ingrese una fecha posterior a la actual\n");
            return 1;
        }
    }
    else
    {
        return -1;
    }
}

/**
 *\fn nodoLD *inicListaDoble()
 *\brief inicia lista doble
 *\return NULL
*/
nodoLD *inicListaDoble()
{
    return NULL;
}

/**
 * \fn nodoLD* crearNodo(stReserva dato)
 * \param dato estrucutra con datos cargados
 * \brief recibe un dato de tipo reserva para almacenarlo en la lista doble y poner sus ramas en NULL
 * \return retorna el nodo creado con la informacion
*/
// Función para crear un nuevo nodo
nodoLD* crearNodo(stReserva dato)
{
    nodoLD* nuevoNodo = (nodoLD*)malloc(sizeof(nodoLD));
    nuevoNodo->reserva = dato;
    nuevoNodo->sig = NULL;
    nuevoNodo->ant = NULL;
    return nuevoNodo;
}

// Función para insertar un nodo al principio de la lista
nodoLD* insertarAlPrincipio(nodoLD* lista, stReserva dato)
{
    nodoLD* nuevoNodo = crearNodo(dato);
    nuevoNodo->sig = lista;
    if (lista)
    {
        lista->ant = nuevoNodo;
    }
    lista = nuevoNodo;
    return lista;
}

// Función para insertar un nodo al final de la lista
nodoLD *insertarAlFinal(nodoLD* lista, stReserva dato)
{
    nodoLD* nuevoNodo = crearNodo(dato);
    nodoLD* ultimo = lista;
    if (lista == NULL)
    {
        lista = nuevoNodo;
        return lista;
    }
    while (ultimo->sig != NULL)
    {
        ultimo = ultimo->sig;
    }
    ultimo->sig = nuevoNodo;
    nuevoNodo->ant = ultimo;
    return lista;
}

#include "usuario.h"
nodoLD *cargarListaDobleArchivo(nodoLD * lista, char archivo[])
{
    if(existeArchivo(archivo) == 0)
    {
        FILE * archi = fopen(archivo, "rb");
        stUsuario aux;
        while (fread(&aux,sizeof(stUsuario),1,archi) > 0)
        {
            if(esFechaPosterior(aux.reserva.diaEntrada,aux.reserva.mesEntrada,aux.reserva.anioEntrada)==0)
            {
                lista = insertarAlPrincipio(lista,aux.reserva);
            }
        }

    }
    return lista;
}

void mostrarReserva(stReserva r)
{
    puts("------------------------------------------------");
    printf(" D%ca de Entrada                : %i\n", 161, r.diaEntrada);
    printf(" Mes de Entrada                : %i\n", r.mesEntrada);
    printf(" A%co de Entrada                : %i\n", 164, r.anioEntrada);
    printf(" D%ca de Salida                 : %i\n", 161, r.diaSalida);
    printf(" Mes de Sal%cda                 : %i\n", 161, r.mesSalida);
    printf(" A%co de Salida                 : %i\n", 164, r.anioSalida);
    printf(" Caracteristicas de Habitaci%cn : %s\n", 162,r.habitacion.tipo);
    puts("------------------------------------------------");
}

// Función para imprimir la lista desde el principio
void imprimirDesdePrincipio(nodoLD* lista)
{
    while (lista != NULL)
    {
        mostrarReserva(lista->reserva);
        lista = lista->sig;
    }
}

// Función para imprimir la lista desde el final
void imprimirDesdeFinal(nodoLD* lista)
{
    nodoLD* ultimo = inicListaDoble();
    while (lista)
    {
        ultimo = lista;
        lista = lista->sig;
    }
    while (ultimo)
    {
        mostrarReserva(ultimo->reserva);
        ultimo = ultimo->ant;
    }
}
