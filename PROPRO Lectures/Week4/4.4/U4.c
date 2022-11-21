#include <stdio.h>

long long int readAndValidation(long long int a) // Validacija
{ 
    while((scanf("%lld", &a) != 1) || (a < 1) || (getchar() != '\n'))
    {
        printf("Netinkama ivestis! Nerasykit raidziu (skaiciai ivedami po viena)! \n");
        printf("Iveskite naturaluji skaiciu: ");
        while(getchar() != '\n')
            ;
    }
    return a;
}

int main()
{
    printf("Si programa is 3 naturaliuju skaiciu suras DBD (Didziausia bendraji dalikli) bei MBK (Maziausia bendra kartotini)\n");
    long long int a, b, c;
    long long int GCD, LCM;

    printf("Iveskite skaiciu a: ");
    a = readAndValidation(a);
    printf("Iveskite skaiciu b: ");
    b = readAndValidation(b);
    printf("Iveskite skaiciu c: ");
    c = readAndValidation(c);

    for (int i = 1; i <= a && i <= b && i <= c; i++)
    {
        if(a%i == 0 && b%i == 0 && c%i == 0)
        {
            GCD = i;
        }
    }
    if (GCD == 1)
        LCM = (a*b*c)/(GCD*2);
    else
        LCM = (a*b*c)/(GCD*GCD);
    
    printf("Atsakymai:\n\n");
    printf("DBD: %lld\n", GCD);
    printf("MBK: %lld", LCM);
    
}