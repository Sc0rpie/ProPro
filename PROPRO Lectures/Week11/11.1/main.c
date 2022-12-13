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

    int arr[SIZE];
    int size = *(&arr + 1) - arr;
    int size2 = 0;

    fillArray(arr, SIZE);
    printArray(arr, SIZE);

    saveToFile("out.bin", arr, size);
    int *arr2 = loadFromFile("out.bin", &size);
    printArray(arr2, SIZE);

    bool sameArr = true;
    for (int i = 0; i < SIZE; i++)
    {
        if (arr[i] != arr2[i])
            sameArr = false;
    }

    if (sameArr)
        printf("All's good!");
    else
        printf("Something's wrong...");


    return 0;
}