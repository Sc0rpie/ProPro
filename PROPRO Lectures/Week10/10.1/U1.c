#include <stdio.h>
#include <assert.h>

size_t strlen(char arr[])
{
    int i = 0;
    size_t length = 0;
    while (arr[i] != '\0')
    {
        length++;
        i++;
    }

    return length;
}

int main()
{
    assert(strlen("abc") == 3);
    assert(strlen("213abcdef") == 9);
    assert(strlen("") == 0);

    return 0;
}