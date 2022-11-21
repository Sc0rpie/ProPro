#include <stdio.h>

#define CAPACITY 10

int main()
{
    // ----------A----------
    int A[CAPACITY] = {0};
    int size = CAPACITY;

    // ----------B----------
    for (int i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    // ----------C----------
    A[0] = 1;
    A[2] = 2;
    A[3] = 2;
    A[9] = 3;

    // ----------D----------
    for (int i = 2; i < size - 1; i++)
    {
        A[i] = A[i + 1];
    }
    size--;

    // ----------E----------
    for (int i = size; i > 7; i--)
    {
        A[i] = A[i - 1];
    }
    A[6] = 4;
    size++;

    // ----------F----------
    for (int i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    // ----------G----------
    int x, y;
    printf("Iveskite skaiciu x [0, 9] (masyvo indeksa): ");
    scanf("%d", &x);

    while (x > 9 || x < 0)
    {
        printf("Ivesta x reiksme neatitinka reikalavimu!\n");
        printf("Iveskite skaiciu x [0, 9] (masyvo indeksa): ");
        scanf(" %d", &x);
    }

    printf("Iveskite skaiciu y: ");
    scanf("%d", &y);
    A[x] = y;

    // ----------H----------
    printf("Iveskite skaiciu x [0, 9] (masyvo indeksa): ");
    scanf("%d", &x);

    while (x > 9 || x < 0)
    {
        printf("Ivesta x reiksme neatitinka reikalavimu!\n");
        printf("Iveskite skaiciu x [0, 9] (masyvo indeksa): ");
        scanf(" %d", &x);
    }

    for (int i = x; i < size; i++)
    {
        A[i] = A[i+1];
    }
    size--;
    
    // ----------I----------
    printf("Iveskite skaiciu x [0, 9] (masyvo indeksa): ");
    scanf("%d", &x);

    while (x > 9 || x < 0)
    {
        printf("Ivesta x reiksme neatitinka reikalavimu!\n");
        printf("Iveskite skaiciu x [0, 9] (masyvo indeksa): ");
        scanf(" %d", &x);
    }

    printf("Iveskite skaiciu y: ");
    scanf("%d", &y);
    
    for (int i = size; i > x-1; i--)
    {
        A[i] = A[i-1];
    }
    A[x] = y;
    size++;
    
    // ----------J----------
    for (int i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }
    
    return 0;
}