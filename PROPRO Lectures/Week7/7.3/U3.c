#include <stdio.h>
#include <stdbool.h>
int getPositiveNumber(char *msg)
{
    int num;
    bool loop = true;
    printf("%s", msg);
    while (loop)
    {
        while ((scanf("%d", &num) != 1) || (getchar() != '\n'))
        {
            printf("%s", msg);
            while (getchar() != '\n')
                ;
        }
        if (num >= 1)
            loop = false;
        else
            printf("%s", msg);
    }
    return num;
}
int main()
{
    char msg[] = "Iveskite teigiama skaiciu: ";
    int num;
    num = getPositiveNumber(msg);

    printf("Num: %d", num);

    return 0;
}