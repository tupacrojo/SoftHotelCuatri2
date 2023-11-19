#include "utils.h"

/** \fn int existeArchivo(char archivo[])
 * \brief Verifica que exista un archivo enviado por parametro
 * \param archivo string que indica la ruta de acceso del archivo
 * \return Devuelve -1 si se creo el archivo, 0 si el archivo ya existe
 */
int existeArchivo(char archivo[])
{
    int flag = 0;
    FILE *archi = fopen(archivo, "r+b"); // si el archivo existe lo abre y devuelve 0
    if (archi == NULL)
    {
        fopen(archivo, "wb");
        flag = -1; // si el archivo no existe lo crea, abre y devuelve -1
    }
    fclose(archi); // cerramos el archivo
    return flag;
}

/** \fn int backupArchivos(char nombre_original[],char nombre_copia[])
 * \brief Recibe dos archivos, uno con datos y el otro vacio o a formatear, pasa los datos del original al nuevo
 * \param nombre_original archivo con datos a copiar
 * \param nombre_copia archivo donde van a ser copiados los datos
 * \return -1 No se pudo abrir el archivo original.
 * \return 0 No se pudo crear el archivo de copia.
 * \return 1 copia creada
 */
int backupArchivos(char nombre_original[], char nombre_copia[])
{
    existeArchivo(nombre_original);
    existeArchivo(nombre_copia);
    FILE *archivo_original, *archivo_copia;
    char buffer[1024];
    size_t bytes_leidos;

    archivo_original = fopen(nombre_original, "rb");
    if (archivo_original == NULL)
    {
        return -1;
    }

    archivo_copia = fopen(nombre_copia, "wb");
    if (archivo_copia == NULL)
    {
        fclose(archivo_original);
        return 0;
    }

    while ((bytes_leidos = fread(buffer, 1, sizeof(buffer), archivo_original)) > 0)
    {
        fwrite(buffer, 1, bytes_leidos, archivo_copia);
    }

    fclose(archivo_original);
    fclose(archivo_copia);

    return 1;
}

/** \fn void atras(char texto[])
 * \brief Muestra por pantalla una animacion de "..."
 * \param texto string a mostrar antes de los "..."
*/
void atras(char texto[])
{
    system("clear || cls");
    printf("%s", texto);
    Sleep(300);
    printf(".");
    Sleep(300);
    printf(".");
    Sleep(300);
    printf(".");
}



int encontrarDireccionEscritorio(char ruta[])/*** "ruta[]" recibe una cadena de caracteres vacia y le carga la direccion de escritorio "C:\Users\Tupac\Desktop"
Se usa la macro "SUCCEEDED" esta devuelve "0" o "-1", dependiendo de la funcion "SHGetFolderPathA"
"SHGetFolderPathA" :
El primer parámetro de SHGetFolderPathA es un identificador de la carpeta especial que se desea obtener. En este caso, se utiliza CSIDL_DESKTOPDIRECTORY, que representa el identificador para el directorio del escritorio.
El segundo parámetro es un puntero a una estructura de identificador de seguridad (security identifier, SID). Pasar NULL indica que no se necesita una SID.
El tercer parámetro es un puntero a una cadena de caracteres que recibirá la ruta del directorio del escritorio.
El cuarto parámetro es un conjunto de flags para controlar el comportamiento de la función. En este caso, se pasa 0 para indicar que no se requieren flags adicionales.
El quinto parámetro es la cadena donde se almacena el resultado
*/
{
    int flag = -1;
    if (SUCCEEDED(SHGetFolderPathA(NULL, CSIDL_DESKTOPDIRECTORY, NULL, 0, ruta)))
    {
        printf("%s",ruta);
        flag = 0;
    }
    return flag;
}
int rutaArchivoEnEscritorio(char rutaArchivo[], char nombreArchivo[])/*** rutaArchivoEnEscritorio devuelve "0" si todo esta bien, "-1" error
 *** rutaArchivo = almacena al final del codigo la ruta con este formato "C:/Users/Tupac/Desktop/archivo.bin"
 *** nombreArchivo = nombre archivo es definido con el nombre del archivo "/archivo.bin"

    Se Utiliza "encontrarDireccionEscritorio" para obtener la direccion del escritorio en cualquier computadora.
    En "direccionEscritorio" se guarda el siguiente valor "C:\Users\Tupac\Desktop"
    "cambiarSlash" lo modifica devolviendo "C:/Users/Tupac/Desktop" guardando este valor en "direccionEscritorio"
    Usando la libreria "<string.h>" unimos las cadenas de caracteres "direccionEscritorio" y "nombreArchivo"

    La cadena resultante es "rutaArchivo", variable enviada a la funcion.
*/
{
    char direccionEscritorio[256];
    int flag = 0;
    if (encontrarDireccionEscritorio(direccionEscritorio) != -1)
    {
        int longitudruta = strlen(direccionEscritorio);
        cambiarSlash(direccionEscritorio, longitudruta);
        strcpy(rutaArchivo, strcat(direccionEscritorio, nombreArchivo));
    }
    else{
        flag = -1;
    }
return flag;
}

void cambiarSlash(char ruta[], int validos) /*** cambiarSlash recibe "C:\Users\Tupac\Desktop" y lo transforma a "C:/Users/Tupac/Desktop"
    ruta[] = "C:\Users\Tupac\Desktop"
    validos = cantidad de letras cargadas en la cadena de caracteres se obtiene con "strlen()"
*/
{
    for (int i = validos - 1; i >= 0; i--)
    {
        if (ruta[i] == '\\')
        {
            ruta[i] = '/';
        }
    }
}

void checkIn(stUsuario u)
{
    stRegHabitacion a;
    FILE *archi = fopen(aHabitaciones, "r+b");
    if (archi != NULL)
    {
        while (!feof(archi) && fread(&a, sizeof(stRegHabitacion), 1, archi))
        {
            fread(&a, sizeof(stRegHabitacion), 1, archi);
            if (strcmp(u.reserva.habitacion.caracteristicas, a.caracteristicas) == 0 && a.ocupado == 0)
            {
                u.reserva.habitacion.idPiso = a.idPiso;
                u.reserva.habitacion.id = a.id;
                a.ocupado = 1;
                fseek(archi, -sizeof(stRegHabitacion), SEEK_CUR);
                fwrite(&a, sizeof(stRegHabitacion), 1, archi);
                break;
            }
        }
        printf("Su habitacion es la del ID: %i en el piso: %i\n", u.reserva.habitacion.id, u.reserva.habitacion.idPiso);
        fclose(archi);
    }
}

void checkOut(stUsuario u)
{
    cambiarEstadoHabitacion(u.reserva.habitacion.id, 0);
    borrarReserva(u.DNI);
}


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