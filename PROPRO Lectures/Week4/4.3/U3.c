#include <stdio.h>

long long int readAndValidation(long long int a) // Validacija
{
    while((scanf("%lld", &a) != 1) || (a < 0) || (getchar() != '\n'))
    {
        printf("Netinkama ivestis! Nerasykit raidziu (skaiciai ivedami po viena)! \n");
        printf("Iveskite neneigiama skaiciu: ");
        while(getchar() != '\n')
            ;
    }
    return a;
}

int main()
{
    printf("Si programa isves fibonacio sekos skaiciu (a - pirmas sekos skaicius), (b - antras sekos skaicius), (c - n-tasis sekos skaicius)\n");
    
    long long int a, b, c;
    printf("Iveskite  neneigiama skaiciu a: ");
    a = readAndValidation(a);
    printf("Iveskite  neneigiama skaiciu b: ");
    b = readAndValidation(b);
    printf("Iveskite  neneigiama skaiciu c: ");
    c = readAndValidation(c);

    long long int fc[c+1];
    fc[0] = a;
    fc[1] = b;
    for (int i = 2; i < c+1; i++)
    {
        fc[i] = fc[i-2]+fc[i-1];
    }
    
    printf("Atsakymas: %lld\n", fc[c]);
    
    return 0;
}