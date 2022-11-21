#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void generateArray(int data[], int size, int low, int high)
{
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        data[i] = (rand() % (high - low + 1)) + low;
    }
}

int main()
{
    int size;
    printf("Masyvo dydis: ");
    scanf("%d", &size);

    int data[size];
    int low, high;
    printf("Intervalas (low, high): ");
    scanf("%d %d", &low, &high);

    generateArray(data, size, low, high);

    for (int i = 0; i < size; i++)
    {
        printf("data: %d\n", data[i]);
    }
    
    return 0;
}