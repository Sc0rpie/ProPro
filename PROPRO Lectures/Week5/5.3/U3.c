#include <stdio.h>

int main()
{
    printf("Si programa parodys skaicius, ivestus i masyva (Dydis - N), kuriu sandauga yra lygi skaiciui S.\n\n");
    int s, n;

    printf("Iveskite teigiama skaiciu s (>0): ");
    scanf("%d", &s);

    while (s <= 0)
    {
        printf("Klaidinga ivestis! Iveskite teigiama skaiciu s (>0): ");
        scanf("%d", &s);
    }

    printf("Iveskite teigiama skaiciu n (>0): ");
    scanf("%d", &n);

    while (n <= 0)
    {
        printf("Klaidinga ivestis! Iveskite teigiama skaiciu n (>0): ");
        scanf("%d", &n);
    }

    int A[n];

    printf("\nIveskite %d teigiamu skaiciu:", n);
    for (int i = 0; i < n; i++)
    {
        int sk;
        scanf("%d", &sk);
        while(sk <= 0)
        {
            printf("Klaidinga ivestis! Iveskite teigiama skaiciu: ");
            scanf("%d", &sk);
        }
        A[i] = sk;
    }

    printf("\nSkaiciu poros, kuriu sandauga lygi reiksmei s: %d\n", s);
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (A[i]*A[j] == s)
                printf("%d * %d\n", A[i], A[j]);
        }
        
    }

    return 0;
}