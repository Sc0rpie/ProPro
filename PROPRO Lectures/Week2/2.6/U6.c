#include <stdio.h>

int mazSk (int a, int b, int c) // Maziausio skaiciaus paieska
{
    int min = a;

    (b <= a && c >= b) ? (min = b) : ((c <= a && b >= c) ? (min = c) : (min = a));
    return min;
}

int didSk (int a, int b, int c) // Didziausio skaiciaus paieska
{
    int max = a;

    (b >= a && c <= b) ? (max = b) : ((c >= a && b <= c) ? (max = c) : (max = a));
    return max;
}

int main()
{
    int a, b, c;
    int min, max;

    printf("Irasykite 3 sveikuosius skaicius: ");
    scanf("%d%d%d", &a, &b, &c);

    min = mazSk(a,b,c);
    max = didSk(a,b,c);
    printf("Maziausias skaicius: %d\n Didziausias skaicius: %d", min, max);

    return 0;
}