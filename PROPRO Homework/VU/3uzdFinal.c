#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverseString(char inout[], int start, int end)
{
    char tmp; /* naudojamas char'o saugojimui */
    while (end > start)
    {
        tmp = inout[start];
        inout[start] = inout[end];
        inout[end] = tmp;
        start++;
        end--;
    }
}

void reverseInput(char inout[], int charCount)
{
    int i, start = 0, end = 0; /* start - zodzio pradzia, end - zodzio pabaiga*/
    for (i = 0; i < charCount+1; i++)
    {
        if (inout[i] == ' ' || inout[i] == '\0')
        {
            end = i - 1;
            reverseString(inout, start, end);
            start = end + 2;
        }
        else if (inout[i] == '\n')
        {
            end = i - 2;
            reverseString(inout, start, end);
            break;
        }
    }
}

int main(int argc, char *argv[])
{
    FILE *read;
    FILE *write;
    int charCount; /* simboliu counter */
    size_t buffSize = 256;
    char *inout = malloc(sizeof(char) * 256);

    read = fopen(argv[1], "r");
    if (read == NULL) /* tikrinimas ar atidaromas failas */
    {
        printf("Failas skaitymui nebuvo rastas. Programos pabaiga!");
        exit(0);
    }

    write = fopen(argv[2], "w");
    if (write == NULL) /* tikrinimas ar atidaromas/sukuriamas failas failas */
    {
        printf("Ivyko klaida sukuriant/skaitant rezultato faila. Programos pabaiga!");
        exit(0);
    }

    /*Skaitymas*/

    while ((charCount = getline(&inout, &buffSize, read)) > 0)
    {
        printf("%lu\n", buffSize);
            reverseInput(inout,charCount);
            fputs(inout, write);
    }
    fclose(read);
    fclose(write);
    free(inout);

    return 0;
}
