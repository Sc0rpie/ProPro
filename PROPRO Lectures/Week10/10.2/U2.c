#include <stdio.h>
#include <assert.h>

void strcpy(char in[], char out[])
{
    int i = 0;
    if (out == NULL)
        return;             // Baigiam darba jeigu nera masyvui vietos

    while (in[i] != '\0')
    {
        out[i] = in[i];
        i++;
    }

    out[i] = '\0';
}

int main()
{
    char in[] = "Testas123";
    char out[25];
    strcpy(in,out);

    printf("%s", out);

    return 0;
}