#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CAPACITY 1000

int main()
{
    int A[CAPACITY], size = 0;
    int a,b,c;

    srand(time(NULL));

    printf("Si programa isves c - kieki skaiciu is intervalo [a,b]\n\n");
    printf("Iveskite a ir b: ");
    scanf("%d %d", &a, &b);
    while (a > b)
    {
        printf("Reiksme a negali buti didesne uz b\n");
        printf("Iveskite a ir b: ");
        scanf("%d %d",&a, &b);
    }

    printf("Iveskite c: ");
    scanf("%d", &c);
    while (c > 1000)
    {
        printf("Reiksme c negali buti didesne uz 1000!\n");
        printf("Iveskite c: ");
        scanf("%d", &c);
    }
    while (c <= 0)
    {
        printf("Reiksme c negali buti mazesne arba lygi 0!\n");
        printf("Iveskite c: ");
        scanf("%d", &c);
    }

    printf("Sugeneruoti skaiciai:\n");
    for (int i = 0; i < c; i++)
    {
        A[i] = (rand() % (b - a + 1)) + a;
        printf("%d ", A[i]);
    }
    

    return 0;
}