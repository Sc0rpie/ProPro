#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 256

int sizeOfArray(char inout[])
{
    int size = 0;
    int i = 0;
    while (inout[i] != '\0')
    {
        size++;
        i++;
    }
    return size;
}
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

void reverseInput(char inout[])
{
    int i, start = 0, end = 0; /* start - zodzio pradzia, end - zodzio pabaiga*/
    for (i = 0; i < 255; i++)
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
    char test[] = "Hello";
    /*char inout[256]*/
    size_t buffSize = 256;
    size_t charCount;
    char *inout = malloc(sizeof(char) * SIZE);

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

    while (fgets(inout, SIZE, read))
    {
        printf("%d\n", sizeOfArray(inout));
        if (sizeOfArray(inout) == 255)
        {
            if (inout[255] != '\n')
            {
                while (getc(read) != '\n' || feof(read))
                    ;
                reverseInput(inout);
                fputs(inout, write);
                fputc('\n', write);
            }
        }
        else
        {
            printf("Original: %s\n", inout);
            reverseInput(inout);
            printf("Reversed: %s\n", inout);
            fputs(inout, write);
        }
    }

    return 0;
}
