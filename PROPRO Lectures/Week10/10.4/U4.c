#include <stdio.h>

char* strchr (char in[], int search) //search - character to find
{
    int i = 0;
    while (in[i] != search && in[i] != '\0')
        i++;
    
    if (in[i] == search)
        return &in[i];
    else
        return NULL;
}

int main()
{
    char in[] = "Testas123";

    char *ats = strchr(in, 's');
    printf("%s", ats);
    return 0;
}

