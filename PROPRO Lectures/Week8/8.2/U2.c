#include <stdio.h>

int largestFile(int arg, char* argN[])
{
    FILE *fp;
    size_t fileSize = 0, maxSize = 0;
    int fileID = 0;
    for (int i = 1; i < arg; i++)
    {
        fp = fopen(argN[i], "rb");
        if(fp != NULL)
        {
            fseek(fp, 0L, SEEK_END);
            fileSize = ftell(fp);
            if (fileSize > maxSize)
            {
                maxSize = fileSize;
                fileID = i;
            }
        }
        else
            printf("File %s does not exist!\n", argN[i]);
        fclose(fp);
    }
    
    return fileID;
}

int main(int argc, char* argv[])
{
    int id;
    if (argc == 1)
    {
        printf("No file names");
    }
    else
    {
        id = largestFile(argc, argv);
        printf("Largest file: %s", argv[id]);
    }
        

    return 0;
}