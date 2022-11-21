#include <stdio.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    int a, b;
    printf("Enter a, b: ");
    scanf("%d%d", &a, &b);
    printf("Before swap: %d %d\n", a, b);
    swap(&a,&b);
    printf("After swap: %d %d", a, b);

    return 0;
}