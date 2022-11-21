#include <stdio.h>
#include <stdlib.h>

const int BIT = 16;

void binary(int);
void bin(char*, int);


int main(int argc, char* argv[]) {

    int x ;

    x = atoi(argv[1]);

    char arr[BIT+1];

    //binary(16);

    bin(arr, x);   // functions overwrites array arr

    arr[BIT] = '\0';   // strings have to be null-terminated in C

    printf("%s \n", arr);

    return 0;
}

void bin(char *arr1,int x) {


    if (x >= 0 && x <= 65535)
      {
        for (int i = BIT-1; i >= 0; i--) 
              {
            if (x % 2 == 0) 
                  {
                    arr1[i] = '0';
                  } else 
                  {
                    arr1[i] = '1';
                  }
            x = x / 2;
               }

      }

}