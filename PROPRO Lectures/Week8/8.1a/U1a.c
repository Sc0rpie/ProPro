#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *createArray(int size, int low, int high)
{
    int *buffer = malloc(sizeof(int) * size);
    if (buffer == NULL)
        return NULL;
    else if (low >= high)
        return NULL;
    else
    {
        srand(time(0));
        for (int i = 0; i < size; i++)
        {
            buffer[i] = (rand() % (high - low + 1)) + low;
        }
        return buffer;
    }
}

int main()
{
    int size, arrSize;
    int *data;
    printf("Masyvo dydis: ");
    scanf("%d", &size);

    int low, high;
    printf("Intervalas (low, high): ");
    scanf("%d %d", &low, &high);

    data = createArray(size, low, high);
    if (data == NULL)
        printf("NULL");
    else
        for (int i = 0; i < size; i++)
        {
            printf("data: %d\n", data[i]);
        }

    return 0;
}