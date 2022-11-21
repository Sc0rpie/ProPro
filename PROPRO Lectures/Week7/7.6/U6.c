#include <stdio.h>
#include <stdbool.h>
int showMenu(char *menuTitle, char *menuOptions[], int menuSize, char *inputMsg)
{
    char term;
    bool loop = true;
    int answ;
    while (loop)
    {
        printf("%s\n", menuTitle);
        printf("------------------\n");
        for (int i = 0; i < menuSize; i++)
        {
            printf("%d. %s\n", i + 1, (char *)(menuOptions) + i * 50);
        }
        printf("------------------\n");
        printf("%s\n", inputMsg);
        if(scanf("%d", &answ) && (answ > 0 && answ <= menuSize))
            loop = false;
        else
        {
            printf("\n\n");
            getchar();
        }
            
    }
    return answ;
}

int main()
{
    char menuTitle[] = "Secret hacker menu",
         menuOptions[][50] = {"Hack computer", "Hack smarphone", "Brick device"},
         inputMsg[] = "Please select the option";
    int menuSize = 3;
    printf("%d", showMenu(menuTitle, (char **)menuOptions, menuSize, inputMsg));
    return 0;
}