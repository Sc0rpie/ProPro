#include <stdio.h>
#include <math.h>

void decToBin(int sk) // 10-taines i 2-taines konvertavimas ir rasymas
{
    int bin[32];
    int i = 0;

    while (sk > 0)
    {
        bin[i++] = sk % 2;
        sk /= 2;
    }

    for (int j = i-1; j>=0; j--)
        printf("%d", bin[j]);
}

int main()
{
    int a1,a2,a3;
    int b1,b2,b3;
    int c1,c2,c3;
    int d1,d2,d3;

    // 2-taine i 10-taine
    a1 = 1 * pow(2,4) + 1 * pow(2,3) + 1 * pow(2,1) + 1;
    a2 = 1 * pow(2,7) + 1 * pow(2,4) + 1 * pow(2,2);
    a3 = 1 * pow(2,13) + 1 * pow(2,12) + 1 * pow(2,9) + 1 * pow(2,7) + 1 * pow(2,6) + 1 * pow(2,4) + 1 * pow(2,2) + 1;

    printf("2-taine i 10-taine: %d || %d || %d\n", a1, a2, a3);

    b1 = 37; b2 = 241; b3 = 2487;
    printf("10-taine i 2-taine: ");
    decToBin(b1); printf(" || ");
    decToBin(b2); printf(" || ");
    decToBin(b3);

    printf("\n");

    c1 = 6 * pow(16, 2) + 14 * pow(16, 1) + 2;
    c2 = 14 * pow(16,3) + 13 * pow(16, 2) + 3 * pow(16, 1) + 3;
    c3 = 1 * pow(16,5) + 2 * pow(16,4) + 3 * pow(16,3) + 4 * pow(16, 2) + 5 * pow(16, 1) + 6;
    printf("16-taine i 10-taine: %d || %d || %d\n", c1, c2, c3);
    

    d1 = 243; d2 = 2483; d3 = 4612;
    printf("10-taine i 16-taine: 0x%x || 0x%x || 0x%x", d1, d2, d3);

    return 0;
}