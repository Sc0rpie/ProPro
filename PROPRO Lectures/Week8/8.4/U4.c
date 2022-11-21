#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int splitData(int arrStart[], int size, int split, int **arrA, int **arrB)
{
    if (split <= 0)
        return -1;

    *arrA = malloc(sizeof(int) * split);
    if (*arrA == NULL)
        return -1;

    for (int i = 0; i < split; i++)
    {
        (*arrA)[i] = arrStart[i];
        // printf("i: %d || arrA: %d || ptr: %p\n", i, arrA[i], arrA+i*4);
    }
    // printf("after: %p\n\n", (void*) arrA);
    // printf("\n");

    *arrB = malloc(sizeof(int) * (size - split));
    if (*arrB == NULL)
        return -1;

    for (int i = 0; i < size - split; i++)
    {
        (*arrB)[i] = arrStart[i + split];
        // printf("i: %d || arrB: %d\n", i, arrB[i]);
    }
    // printf("\n");

    // {1, 2, 3, 4, 5, 6, 7} split 3 (i = 2)

    return 0;
}

int main()
{
    int *arrA = NULL, *arrB = NULL;
    int size, split;
    printf("Array size: ");
    scanf("%d", &size);
    int arrStart[size];

    srand(time(0)); //random numbers
    for (int i = 0; i < size; i++)
    {
        arrStart[i] = (rand() % (100 - 10 + 1)) + 10;
    }

    printf("Where to split?\n arrID: ");
    scanf("%d", &split);
    splitData(arrStart, size, split, &arrA, &arrB);

    printf("arrA: ");
    for (int i = 0; i < split; i++)
    {
        printf("%d ", *(arrA + i));
    }
    printf("\narrB: ");
    for (int i = 0; i < size - split; i++)
    {
        printf("%d ", *(arrB + i));
    }

    return 0;
}