#include <stdio.h>

void memset(void* ptr, int c, size_t size)
{
    int i = 0;
    char *ptr_chr = ptr;
    if (*ptr_chr == 0) 
        return;
    while (size > 0)
    {
        *ptr_chr = c;
        ptr_chr++;
        size--;
    }

}

int main()
{
    char in[] = "Testas123";
    memset(in, '?', 15);
    printf("%s", in);
    return 0;
}