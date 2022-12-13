#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main()
{
    int a, i, count = 0;
    int kiek = 0;
    int length;
    char input[50];
    printf("Enter a digit: ");

    fgets(input,50,stdin);

    length = strlen(input); /* ivesties ilgis (naudojamas patikrinimui ar skaicius) */

    while (count != 1)
    {
        count = 1;
        length = strlen(input);
        for(i = 0; i < length-1; i++)
        {
            if(!isdigit(input[i]))
            {
                printf("%s", "Input is not an integer");
                printf("\n");
                count = 0;
                break;
            }
        }

        if (count == 0)
        {
            printf("Enter a digit: ");
            fgets(input,50,stdin);
        }
                 
    }
    

    while(a!=0) /* While ciklas iki kol nebus ivestas 0 */
    {
        if (a > 0 && a % 2 == 0) /* Patikrinimas ar skaicius lyginis ir teigiamas */
        {
            kiek++;
        }
        scanf("%d", &a);
    }

    printf("Lyg. kiek.: %d", kiek);

    return 0;
}
