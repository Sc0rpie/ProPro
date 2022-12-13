#include <stdio.h>

void Skaiciavimas(int a, int b, int* sum)
{
    // printf("A: %d\nB: %d\n", a, b);
    *sum = a+b;
}

int main()
{
    int a, b, sum;
    printf("Ivesk 2 skaicius: ");
    scanf("%d%d", &a, &b);

    Skaiciavimas(a,b,&sum);
    printf("sum: %d", sum);
    return 0;
}