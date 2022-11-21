#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    char *data = "1010000101";
    signed char c = strtol(data, 0, 2);
    printf("%s = %c = %d = 0x%.2X\n", data, c, c, c);
    return(0);
}