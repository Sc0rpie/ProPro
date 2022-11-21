#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a, kiek = 0, counter = 0;

    while (counter == 0)
    {
        printf("Iveskite skaiciu: ");
        if((scanf("%d", &a) == 1) && (getchar() == '\n'))
        {
            if((a >= 0) && (a <= 2147483647));
                /*counter = 1;*/
            else
                printf("Virsitas int kintamojo limitas. \n");
        }
        else
        {
            printf("Neatitinka ivestis! Iveskite sveika, neneigiama skaiciu: ");
            while (getchar() != "\n")
            ;
        }
            
    }




    while(a!=0) /* While ciklas iki kol nebus ivestas 0 */
    {
        counter = 0;

        if (a > 0 && a % 2 == 0) /* Patikrinimas ar skaicius lyginis ir teigiamas */
        {
            kiek++;
        }
        
        while (counter != 1)
        {
            counter = 1;
            printf("Iveskite skaiciu: ");
            if((scanf("%d", &a) == 1) && (getchar() == '\n'))
            {
                if((a >= 0) && (a <= 2147483647))
                    counter = 1;
                else
                {
                    counter = 0;
                    printf("Virsitas int kintamojo limitas. \n");
                }
            }        
            else
            {
                printf("Neatitinka ivestis! Iveskite sveika, neneigiama skaiciu: ");
                while(getchar() != '\n')
                counter = 0;
            }
        }
    }

    printf("Lyg. kiek.: %d", kiek);

    return 0;
}
