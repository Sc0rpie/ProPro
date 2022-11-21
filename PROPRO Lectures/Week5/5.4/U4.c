#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Si programa parodys pirminius skaicius is ivesto rinkinio. Skaiciai nesikartos.\n\n");
    
    int *buffer; // masyvas su begalo daug vietos skaitmenims
    size_t buffer_size = 1024;
    buffer = malloc(sizeof(int) * buffer_size);

    size_t dataAmt = 0;
    int input;
    while (1)
    {
        printf("Iveskite skaiciu: ");
        scanf("%d", &input);

        if(input < 0) break;

        buffer[dataAmt] = input;
        dataAmt++;

        if (dataAmt >= buffer_size)
        {
            buffer_size += 1024;
            buffer = realloc(buffer, buffer_size * sizeof(int));
        }
    }

    size_t Pirm[dataAmt]; // pirminiu skaiciu masyvai
    size_t index;
    for (size_t i = 0; i < dataAmt; i++)
        Pirm[i] = -1;

    printf("\nPirminiai skaiciai is rinkinio: \n");
    for (size_t i = 0; i < dataAmt; i++)
    {
        size_t dal = 0;
        size_t pirmSk = 0;

        for (size_t j = 1; j <= buffer[i]; j++)
        {
            if (buffer[i] % j == 0)
                dal++;
        }

        if (dal == 2)
        {
            for (size_t j = 0; j < dataAmt; j++)
            {
                if (buffer[i] == Pirm[j])
                    pirmSk++;
            }

            
            if (pirmSk == 0)
            {
                printf("%d\n", buffer[i]);
                Pirm[index] = buffer[i];
                index++;
            }
        }
        
    }
    
    

    free(buffer);
    return 0;
}