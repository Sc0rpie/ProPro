#include <stdio.h>

#define SIZE 5000 /* Masyvo maksimalus dydis */

/*int ReadAndValidate() Validacija
{
    int a;
    while ((scanf("%d", &a) != 1) || (getchar() != '\n'))  Tikrinimas ar irasyta raide 
    {
        printf("Netinkama ivestis! Nerasykit raidziu (sveikieji skaiciai ivedami po viena)! \n");
        printf("Iveskite skaiciu: ");
        while (getchar() != '\n')
            ;
    }
    return a;
}
*/

void SkaitymasRasymas(int sk[], int* n)
{
    int input, i;
    printf("Si programa suras dazniausiai pasikartojanti skaiciu is visu ivestu.\nJeigu yra daug tiek pat pasikartojanciu skaiciu, bus rodomas pirmas, kuris kartojosi tiek kartu\n\n");

    printf("Iveskite kiek skaiciu noresite ivesti (ivedimas iki 5000 skaitmenu)\n");
    /*n = ReadAndValidate();*/
    scanf("%d", n);
    while (*n <= 0 || *n > 5000) /* Vykdoma kol nebus irasytas tinkamas skaicius (nuo 1 iki 5000) */
    {
        printf("Netinkama ivestis! Virsijamas skaitmenu limitas/skaicius turi but didesnis uz 0\nIveskite skaiciu: ");
        /*n = ReadAndValidate();*/
        scanf("%d", n);
    }
    printf("\nIveskite %d skaitmenu.\n", *n);

    for (i = 0; i < *n; i++) /* Tikrinimas ir ivedimas i masyva */
    {
        /*input = ReadAndValidate();*/
        scanf("%d", &input);
        sk[i] = input;
    }

}

void RepeatingNumber(int sk[], int n, int* freqNum) /* Patikrinimas kuris skaicius pasikartojo dazniausiai */
{
    
    int count, i, j;
    int maxCount = 0;
    for (i = 0; i < n; i++)
    {
        count = 0;
        for (j = 0; j < n; j++)
        {
            if (sk[i] == sk[j])
                count++;
        }

        if (count > maxCount)
        {
            maxCount = count;
            *freqNum = sk[i];
        }
    }
}

int main()
{
    int sk[SIZE];
    int n, i, input;
    int freqNum;
    
    SkaitymasRasymas(sk, &n);
    
    RepeatingNumber(sk, n, &freqNum); /* Dazniausiai pasikartojancio skaiciaus randimas */

    printf("Dazniausiai pasikartojantis skaicius: %d", freqNum);

    return 0;
}
