#ifndef FILE_H
#define FILE_H

int saveCount;
int loadCount;

void saveToFile(char *fileName, int *arr, int size);
int *loadFromFile(char *fileName, int n);


#endif