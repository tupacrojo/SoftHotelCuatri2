#include "array.h"

char **cargarArrayDeStrings(int dimensionX, int dimensionY)
{
    char **matriz = malloc(sizeof(char *) * dimensionX);
    for (int i = 0; i < dimensionX; i++)
    {
        matriz[i] = malloc(sizeof(char) * dimensionY);
    }

    return matriz;
}

void borrarArrayDeStrings(char **matriz, int dimensionX)
{
    for (int i = 0; i < dimensionX; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}