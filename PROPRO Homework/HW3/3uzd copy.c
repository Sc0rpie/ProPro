#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 256

/* char a[] = "hello"
start = 0; end = 3
tmp = h;
char[start] = char[end] - oello
char[end] = tmp - oellh
start++;
end--;

start = 1; end = 2
tmp = e;
char[start] = char[end] - olllo
char[end] = tmp - olleh
start++;
end--;
*/

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
    /*printf("%s\n", inout);*/
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
    /*printf("%s\n", inout);*/
}

int main(int argc, char *argv[])
{
    FILE *read;
    FILE *write;
    char test[] = "Hello";
    char input;
    int bufferSize = 0;
    /*char inout[256]*/
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
    while (feof(read) != 1)
    {
        while (input = fgetc(read))
        {
            if (bufferSize <= 255)
            {
                if (input != '\n' || input != '\0')
                {
                    
                }
            }

            /*fputc('\n', write);*/
            /*while (fgetc(read) != '\n')
                if (feof(read)) break;*/
        }
        reverseInput(inout);
        /*printf("Kas eiluteje?\n");
        printf("%s\n", inout);*/

        fputs(inout, write);
    }

    return 0;
}
