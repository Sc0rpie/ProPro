#include <stdio.h>

long long int getFactorial(int number)
{
    if (number <= 0)
        return 0;
    else
    {
        if (number <= 1)
            return 1;

        return number * getFactorial(number - 1);
    }
}

long long int getFactorialNorm(int number)
{
    if (number <= 0)
        return 0;
    else
    {
        long long int answ = 1;
        for (int i = 1; i <= number; i++)
        {
            answ *= i;
        }
        return answ;
    }
}

int main()
{
    int i;
    printf("Iveskite skaiciu: ");
    scanf("%d", &i);
    printf("%lld", getFactorialNorm(i));
    return 0;
}