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