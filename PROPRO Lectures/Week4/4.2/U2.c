#include <stdio.h>
#include <stdbool.h>

int intReadAndValidation(int a) // Validacija
{
    while ((scanf("%d", &a) != 1) || (getchar() != '\n'))
    {
        printf("Netinkama ivestis! Nerasykit raidziu (skaiciai ivedami po viena)! \n");
        printf("Iveskite skaiciu: ");
        while (getchar() != '\n')
            ;
    }
    return a;
}

int main()
{
    printf("Si programa is intervalo (a,b] isves skaicius, kuriu liekana = 1 dalinant is c\n");
    int a, b, c;
    bool isRight = false;

    printf("Iveskite skaiciu a: ");
    a = intReadAndValidation(a);
    printf("Iveskite skaiciu b: ");
    b = intReadAndValidation(b);
    printf("Iveskite skaiciu c: ");
    c = intReadAndValidation(c);

    while (isRight != true)
    {
        if (a > b || a == b)
        {
            printf("Ivestas neteisingas intervalas (a turi buti daugiau uz b)\n");
            printf("Iveskite skaiciu a: ");
            a = intReadAndValidation(a);
            printf("Iveskite skaiciu b: ");
            b = intReadAndValidation(b);
        }
        else
            isRight = true;
    }

    printf("Skaiciai atitinkantis salyga: ");
    for (int i = a + 1; i <= b; i++)
    {
        if (i > 0)
            if (i % c == 1)
                printf("%d ", i);
    }

    return 0;
}