#include <stdio.h>

int ReadAndValidation(int a) // Validacija
{
    while ((scanf("%d", &a) != 1) || (getchar() != '\n'))
    {
        printf("Netinkama ivestis! Nerasykit raidziu! \n");
        printf("Iveskite skaiciu: ");
        while (getchar() != '\n')
            ;
    }
    while (a < 0)
    {
        printf("Netinkama ivestis! Skaicius turi buti teigiamas!\n");
        printf("Iveskite skaiciu: ");
        scanf("%d", &a);
        while (getchar() != '\n')
            ;
    }
    return a;
}


int main()
{
    printf("Programos tikslas: irasius skaiciu, parodyti jo faktoriala ir parasyti atsakymas i faila ir i ekrana.\n\n");

    int sk;
    FILE *fp;
    fp = fopen("out.txt", "w");
    printf("Iveskite viena teigiama skaiciu.\n");
    sk = ReadAndValidation(sk);
    long long int factorial = 1;
    //Faktorialo rasymas i ekrana ir faila
    for (int i = sk; i >= 1; i--)
    {
        factorial *= i;
    }
    printf("Gautas faktorialas: %lld", factorial);
    fprintf(fp,"%lld", factorial);
    fclose(fp);
    return 0;
}