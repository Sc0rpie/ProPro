#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "file.h"

#define SIZE 10

void fillArray(int *arr, int size)
{
    int low = 1;
    int high = 25;

    for (int i = 0; i < size; i++)
    {
        arr[i] = (rand() % (high - low + 1)) + low;
    }
}

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Element %d is: %d\n", i + 1, arr[i]);
    }
    printf("\n");
}

int main()
{
    srand(time(NULL));

    int *arr1 = malloc(sizeof(int) * SIZE);
    int *arr2 = malloc(sizeof(int) * SIZE);;
    int *arr3 = malloc(sizeof(int) * SIZE);;

    fillArray(arr1, SIZE);
    fillArray(arr2, SIZE);
    fillArray(arr3, SIZE);

    saveToFile("out1.bin", arr1, SIZE);
    saveToFile("out1.bin", arr3, SIZE);

    arr1 = loadFromFile("out1.bin", SIZE);

    saveToFile("out2.bin", arr2, SIZE);
    arr3 = loadFromFile("out2.bin", SIZE);
    arr2 = loadFromFile("out1.bin",SIZE);
    // int *arr2 = loadFromFile("out.bin", &size);
    // printArray(arr2, SIZE);

    if (saveCount == 3 && loadCount == 3)
        printf("All's good!");
    else
        printf("Something's wrong...");

    // printf("\nSave count: %d", saveCount);
    // printf("\nLoad count: %d", loadCount);

    return 0;
}