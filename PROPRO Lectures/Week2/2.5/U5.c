#include <stdio.h>
#include <math.h>

int main()
{
    double x, y, z;
    double a, b;

    printf("Iveskite x, y ir z: ");
    scanf("%lf%lf%lf", &x, &y, &z);

    // Skaiciavimai
    a = x + 4*y + pow(z,3);
    b = (x + sqrt(y)) * (pow(z,4) - fabs(z) + 46.3);

    printf("\n Atsakymai:\n");
    printf("A) %.2f\n", a);
    printf("B) %.2f", b);

    return 0;
}