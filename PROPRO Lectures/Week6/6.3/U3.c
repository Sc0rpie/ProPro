#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
bool Validation(char input[])
{
    bool letter = false;
    for (int i = 0; i < strlen(input); i++)
    {
        if (isdigit(input[i]) == 0 && input[i] != 45 && input[i] != 46)
            letter = true;
    }
    if (letter == true)
        return true;
    else
        return false;
}

int main()
{
    // setlocale(LC_ALL, "lt_LT.utf8");
    FILE *fp;
    char fileName[255] = "";
    char input[1024];
    char delim[] = " ;";
    double x[10], min, mid, max;
    int i, counter;
    bool loop = true, valid;

    while (loop)
    {
        counter = 0;
        i = 0;
        printf("Iveskite 3 skaicius vienoje eiluteje, be tarpu, teigiamus arba neigiamus, kuriuos skiria kabliataskiai\n\n");
        scanf("%s", input);
        char *ptr = strtok(input, delim);
        while (ptr != NULL)
        {
            counter++;
            valid = Validation(ptr);
            if (valid == 0)
            {
                x[i] = atof(ptr);
                i++;
                printf("%lf\n", x[i - 1]);
                printf("COUNTER: %d\n", counter);
                ptr = strtok(NULL, delim);
            }
            else
            {
                printf("NOT VALID\n");
                break;
            }
        }
        if (valid == 1)
            printf("Netinkama ivestis! Raidziu ivedimas negalimas (realieji skaiciai rasomi su tasku, ne su kableliu)!\n\n");
        else if (counter != 3)
            printf("Netinkama ivestis! Ivedimo formatas: skaicius1;skaicius2;skaicius3\n\n");
        else if (counter == 3)
        {
            min = x[0], max = x[0];
            for (int i = 1; i < 3; i++)
            {
                if (x[i] > max)
                    max = x[i];
                if (x[i] < min)
                    min = x[i];
            }
            for (int i = 0; i < 3; i++)
                if (x[i] != max && x[i] != min)
                    mid = x[i];
            // printf("MAX: %lf\n", max);
            // printf("MIN: %lf\n", min);
            // printf("MID: %lf\n", mid);
            loop = false;
        }
    }

    bool fileLoop = true;
    bool correctName;
    int chars;
    while (fileLoop)
    {
        chars = 0;
        printf("Iveskite failo pavadinima.\nFormatas: <pavadinimas>.txt\n\n");
        scanf("%s", fileName);
        // fgets(fileName, sizeof(fileName), stdin);
        for (int i = 0; i < sizeof(fileName); i++)
        {
            if (fileName[i] != 0)
                chars++;
        }
        // Validacija
        if (chars <= 3)
        {
            correctName = false;
            printf("Bloga ivestis! Per trumpas failo pavadinimas.");
        }
        else
        {
            // for (int i = 0; i < chars; i++)
            // {
            // printf("%d\n", fileName[i]);
            // }
            

            // printf("%c\n", fileName[chars-1]);
            // printf("%c\n", fileName[chars-2]);
            // printf("%c\n", fileName[chars-3]);
            // printf("%c\n", fileName[chars-4]);
            
            if (fileName[chars-1] == 't' && fileName[chars-2] == 'x' && fileName[chars-3] == 't' && fileName[chars-4] == '.')
                correctName = true;
        }

        if (correctName)
        {
            printf("\nTinkama ivestis, generuojamas failas...");
            fp = fopen(fileName, "w");
            fprintf(fp, "%.2f", mid);
            fclose(fp);
            fileLoop = false;
        }
        else
        {
            printf("Truksta pletinio .txt (rasoma mazosiomis)\n");
        }
        
    }

    return 0;
}