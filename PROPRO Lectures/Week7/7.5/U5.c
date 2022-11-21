#include <stdio.h>

long getFileSize(char *fileName)
{
    FILE *fp;
    long size;
    fp = fopen(fileName, "rb");
    if (fp == NULL)
        return -1;
    else
    {
        fseek(fp, 0L, SEEK_END);
        size = ftell(fp);
        return size;
    }
}

int main()
{
    char fileName[255];
    long size;
    printf("File: ");
    scanf("%s", fileName);
    size = getFileSize(fileName);
    printf("Size: %ld", size);
    return 0;
}