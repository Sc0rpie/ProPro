#include <stdio.h>

int main()
{
    int sk;
    printf("Iveskite skaiciu: ");
    scanf("%d", &sk);

    char *ats = sk % 2 == 0 ? "lyginis" : "nelyginis";

    printf("\n Skaicius %d yra %s", sk, ats);

    return 0;
}