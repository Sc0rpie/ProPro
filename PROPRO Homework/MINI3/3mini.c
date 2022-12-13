/* Funkcija sukuria dinamini masyva ir i ji patalpina i*i - i>=n*/

#include <stdio.h>
#include <stdlib.h>

void createArr(int n, int a[])
{
    int i;
    for (i = 1; i <= n; i++)
    {
        a[i-1] = i*i;
    }
}

int main()
{
    int n, i;
    int *a;
    printf("Iveskite n: ");
    scanf("%d", &n);

    a = malloc(sizeof(int) * n);
    createArr(n,a);
    

    for (i = 0; i < n; i++)
    {
        printf("A: %d\n", a[i]);
    }
    

    return 0;
}
