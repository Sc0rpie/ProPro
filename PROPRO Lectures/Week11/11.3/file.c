#include <stdio.h>
#include <stdlib.h>
#include "file.h"

void saveToFile(char *fileName, int arr[], int size)
{
    FILE *inout = fopen(fileName, "wb");
    fwrite(&size, sizeof(int), 1, inout);
    for (int i = 0; i < size; i++)
    {
        fwrite(&arr[i], sizeof(int), 1, inout);
    }

    saveCount++;

    fclose(inout);
}

int *loadFromFile(char *fileName, int n)
{
    
    FILE *inout = fopen(fileName, "rb");
    
    if(fread(&n, sizeof(int), 1, inout) != 1)
        return NULL;

    int *arrFromFile = malloc(sizeof(int) * n);

    if (fread(arrFromFile, sizeof(int), n, inout) != n)
    {
        free(arrFromFile);
        return NULL;
    }

    if(fclose(inout) == EOF)
    {
        free(arrFromFile);
        return NULL;
    }

    loadCount++;

    return arrFromFile;
}