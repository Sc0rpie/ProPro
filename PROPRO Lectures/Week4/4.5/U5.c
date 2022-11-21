#include <stdio.h>

int intReadAndValidation(int a) // INT validacija
{
    while((scanf("%d", &a) != 1) || (a < 1) || (getchar() != '\n'))
    {
        printf("Netinkama ivestis! Nerasykit raidziu (skaiciai ivedami po viena)! \n");
        printf("Iveskite neneigiama skaiciu: ");
        while(getchar() != '\n')
            ;
    }
    return a;
}

int floatReadAndValidation(float b) // FLOAT validacija
{
    while ((scanf("%f", &b) != 1) || (getchar() != '\n'))
    {
        printf("Netinkama ivestis! Nerasykit raidziu (skaiciai ivedami po viena)! \n");
        printf("Iveskite teigiama realu skaiciu: ");
        while (getchar() != '\n')
            ;
    }
    return b;
}

int main()
{
    printf("Si programa parodys ivestu skaiciu suma, vidurki bei maziausia ir didziausia sekos skaiciu.\n");
    printf("n - kiek skaiciu bus sekoje. Sekos skaiciai - teigiami realus skaiciai\n\n");
    
    int n;
    double sum = 0, vid = 0, min, max;

    printf("Iveskite n: ");
    n = intReadAndValidation(n);
    double sk[100];
    for (int i = 0; i < n; i++)
    {
        sk[i] = floatReadAndValidation(sk[i]);
        sum += sk[i];
        vid += sk[i];
    }

    min = sk[0];
    max = sk[0];
    vid /= n;
    for (int i = 0; i < n; i++)
    {
        if (sk[i] > max)
            max = sk[i];

        if (sk[i] < min)
            min = sk[i];
    }

    printf("Atsakymai:\n\n");
    printf("Suma: %.2f\n", sum);
    printf("Vidurkis: %.2f\n", vid);
    printf("Maziausias skaicius: %.2f\n", min);
    printf("Didziausias skaicius: %.2f\n", max);
    return 0;
}