#include <stdio.h>
#include <assert.h>

void strncpy(char in[], char out[], size_t size)
{
    int i = 0;
    if (out == NULL)
        return;             // Baigiam darba jeigu nera masyvui vietos

    while (size > 0)
    {
        if (in[i] == '\0') break;   // Jeigu str pabaiga
        out[i] = in[i];
        i++; size--;
    }

    out[i] = '\0';
}

int main()
{
    size_t size;
    char in[] = "Testas123";
    char out[25];

    if(scanf("%lu", &size) > 0)
        strncpy(in,out,size);

    printf("%s", out);

    return 0;
}