#include <stdio.h>

int main() {   
    
    int num = 0;
    int i, sum = 0;
    printf("Enter number:");
    scanf("%d", &num);

    for (i = 1; i < num+1; i++)
    {
        sum += i*i;
    }

    printf("%d", sum);
    
    return 0;
}
