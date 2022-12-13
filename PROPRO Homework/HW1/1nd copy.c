#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main()
{
    int a = 1, i, count = 0;
    int kiek = 0;
    int length;
    char input[11];
    printf("Iveskite skaiciu: ");

    fgets(input,11,stdin);

    length = strlen(input); /* ivesties ilgis (naudojamas patikrinimui ar skaicius) */

    while (count != 1) /* patikrinimas ar skaicius */
    {
        count = 1;
        length = strlen(input);
        for(i = 0; i < length-1; i++)
        {
            if(input[i] == '-')
                ;
            else if(!isdigit(input[i]))
            {
                
                printf("%s", "Netinkama ivestis! Iveskite skaiciu: ");
                printf("\n");
                count = 0;
                break;
            }
        }

        if (count == 0)
        {
            printf("Iveskite skaiciu: ");
            fgets(input,50,stdin);
        }   
    }
    
    a = atoi(input);

    while(a!=0) /* While ciklas iki kol nebus ivestas 0 */
    {
        count = 0;

        if (a > 0 && a % 2 == 0) /* Patikrinimas ar skaicius lyginis ir teigiamas */
        {
            kiek++;
        }
        fgets(input,11,stdin);

        while (count != 1)
        {
            count = 1;
            length = strlen(input);
            for(i = 0; i < length-1; i++)
            {
                if(input[i] == '-')
                    ;
                else if(!isdigit(input[i]))
                {
                    printf("%s", "Netinkama ivestis! Iveskite skaiciu: ");
                    printf("\n");
                    count = 0;
                    break;
                }
            }

            if (count == 0)
            {
                printf("Iveskite skaiciu: ");
                fgets(input,50,stdin);
            }   
        }
        a = atoi(input);
        printf("%d\n", a);
    }

    printf("Lyg. kiek.: %d", kiek);

    return 0;
}
