#include <stdio.h>
#include <math.h>

int intReadAndValidation(int a) // Validacija
{
    while((scanf("%d", &a) != 1) || (getchar() != '\n'))
    {
        printf("Netinkama ivestis! Nerasykit raidziu (skaiciai ivedami po viena)! \n");
        printf("Iveskite skaiciu: ");
        while(getchar() != '\n')
            ;
    }
    return a;
}

int main()
{
    printf("Si programa is 3 skaiciu a, b ir c isves kvadratines lygties ax^2 + bx + c sprendinius\n\n");
    int a, b, c;

    printf("Iveskite skaiciu a: ");
    a = intReadAndValidation(a);
    printf("Iveskite skaiciu b: ");
    b = intReadAndValidation(b);
    printf("Iveskite skaiciu c: ");
    c = intReadAndValidation(c);

    int D = pow(b,2) - 4 * a * c;

    float x1, x2;
    if (D < 0)
        printf("Diskriminantas gaunamas neigiamas, sprendiniu nera");
    
    else if (D == 0)
    {
        x1 = (-1*b) / (2*a);
        printf("1 sprendinys\n");
        printf("Atsakymas (x1): %.1f", x1);
    }
    else if (D > 0)
    {
        x1 = ((-1*b)+sqrt(D)) / (2*a);
        x2 = ((-1*b)-sqrt(D)) / (2*a);
        printf("2 sprendiniai\n");
        printf("Atsakymas (X1): %.1f\n", x1);
        printf("Atsakymas (X2): %.1f\n", x2);
    }

    return 0;
}