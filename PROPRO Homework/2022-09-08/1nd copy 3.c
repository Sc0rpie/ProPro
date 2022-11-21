#include<stdio.h>

int main()
{
    int a = 1, counter = 0;
    int kiek = 0;

    while(a!=0) /* While ciklas iki kol nebus ivestas 0 */
    {
        printf("Iveskite skaiciu: ");
        while((scanf("%d", &a) != 1) || (getchar() != '\n')) /* Tikrinimas ar irasyta raide */
        {
            printf("Netinkama ivestis! Nerasykit raidziu (skaiciai ivedami po viena)! \n");
            printf("Iveskite skaiciu: ");
            while(getchar() != '\n')
                ;
        }
        counter++;
        if (a > 0 && counter % 2 == 0) /* Patikrinimas ar skaicius lyginis ir teigiamas */
        {
            kiek++;
        }
    }

    printf("Lyg. kiek.: %d", kiek);

    return 0;
}
