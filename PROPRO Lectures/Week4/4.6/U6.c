#include<stdio.h>

int intReadAndValidation(int a) // Validacija
{
    while((scanf("%d", &a) != 1) || (getchar() != '\n'))
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
    int a = 1, skaitm, maxSkaitm = 0, maxSk = 0;

    printf("Si programa is visu ivestu neneigiamu skaiciu parodys kuris skaicius turejo daugiausiai skaitmenu\n");
    printf("rodomas tik pirmas skaicius (jeigu ivesta 101 202 tai rodomas 101)\n\n");
    printf("Kad uzbaigti programa, irasykite neigiama skaiciu\n");

    while(a >= 0) /* While ciklas iki kol nebus ivestas neigiamas skaicius */
    {
        skaitm = 0;
        printf("Iveskite skaiciu: ");
        a = intReadAndValidation(a);
        int tmp = a;
        while (tmp > 9)
        {
            tmp /= 10;
            skaitm++;
        }
        skaitm++;
        if (maxSkaitm < skaitm)
        {
            maxSkaitm = skaitm;
            maxSk = a;
        }
    }

    printf("Daugiausiai skaitmenu turejo skaicius %d", maxSk);

    return 0;
}
