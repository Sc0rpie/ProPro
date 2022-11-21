#include <stdio.h>
#include <stdbool.h>

int isInRange(int number, int low, int high)
{
    if (low < high)
    {
        if (number >= low && number <= high)
            return true;
        else
            return false;
    }
    else
        return false;
}

int main()
{
    int number, low, high;
    bool answer;
    printf("Iveskite 3 skaicius (number, low, high): ");
    scanf("%d %d %d", &number, &low, &high);

    answer = isInRange(number, low, high);

    if (answer == 1)
        printf("Answer: true");
    else
        printf("Answer: false");
    return 0;
}