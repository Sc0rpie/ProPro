#include <stdio.h>
#include <math.h>

int skaiciuRikiav(int sk)
{
    int ats = 0, kiek, max, counter = 0;
    int tmp = sk; int tmp2;
    while (tmp > 9) // randama kiek skaitmenu turi skaicius
    {
        tmp /= 10;
        counter++;
    }
    counter++;

    while (sk > 9)
    {
        max = sk%10;printf("%d | ", max);
        tmp = sk/10;
        for (int i = 0; i < counter-1; i++)
        {
            tmp /= 10;printf("%d ", tmp);
            if (tmp%10 > max)
                max = tmp%10;
        }
        printf("\n max: %d\n", max);
        ats += max * pow(10,counter-1);
        counter--;
        sk /= 10;
    }
    ats+=sk;



    return ats;
}

int main()
{
    int sk, counter = 0;
    int ats;
    while (counter == 0)
    {
        printf("Iveskite teigiama skaiciu: ");
        scanf("%d", &sk);
        if (sk < 0)
            printf("Ivestas neigiamas skaicius!\n");
        else counter = 1;
    }
    printf("\n\n");
    ats = skaiciuRikiav(sk);
    printf("Skaitmenys: %d", ats);
    return 0;
}