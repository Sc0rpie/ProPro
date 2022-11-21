#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void ErrorMsg(int ID)
{
    switch (ID)
    {
    case 1:
        printf("Bloga ivestis! Ivestas per mazas skaicius.\n");
        printf("Sekmingai irasius duomenys i faila paspauskite enter klavisa.\n\n");
        break;
    case 2:
        printf("Bloga ivestis! Ivestas per didelis skaicius.\n");
        printf("Sekmingai irasius duomenys i faila paspauskite enter klavisa.\n\n");
        break;
    case 3:
        printf("Bloga ivestis! Trupmenine dali nuo sveikosios turi skirti kablelis!.\n");
        printf("Sekmingai irasius duomenys i faila paspauskite enter klavisa.\n\n");
        break;
    case 4:
        printf("Bloga ivestis! Skaitmuo turetu but ne mazesnis uz 10 ir ne didesnis uz 1000!.\n");
        printf("Sekmingai irasius duomenys i faila paspauskite enter klavisa.\n\n");
        break;
    case 5:
        printf("Bloga ivestis! Skaitmenu po kableliu turetu but ne daugiau nei 3!.\n");
        printf("Sekmingai irasius duomenys i faila paspauskite enter klavisa.\n\n");
        break;
    default:
        break;
    }
}

bool Validation(char input[])
{
    bool letter = false;
    for (int i = 0; i < strlen(input); i++)
    {
        //printf("INPUT:> %d\n", input[i]);
        if (input[i] == 1 || input[i] == 2 || input[i] == 4)
            input[i] = 48;
        else if (input[i] != 1)
        {
            if (isdigit(input[i]) == 0)
            {
                letter = true;
            }
        }
    }

    if (letter == true)
        return true;
    else
        return false;
}

double digitConversion(char input[], bool decimalP, double answer)
{
    int multiplier = strlen(input);
    char in;
    int digit;
    digit = atoi(input);
    if (decimalP == false)
    {
        // digit = atoi(&input[0]);
        answer = digit;
    }
    else
    {
        int size = strlen(input);
        //printf("Size: %d", size);
        //printf("DIGIT: %d", digit);
        if (size <= 3)
        {
            size *= -1;
            ////printf("input: %d\n", size);
            answer += digit * pow(10, size);
        }
        else
            answer = 0;
    }
    //printf("FUNC ANSW: %f\n", answer);
    return answer;
}

int main()
{
    printf("Programos tikslas: irasius i duomenu faila in.txt, atspausdinti skaiciaus ilgi.\n");
    printf("Galimi duomenys: realus skaicius x kuris atitinka salyga - 10 <= x <= 1000\nSkaitmenu limitas po kablelio: 3\n");
    printf("Sekmingai irasius duomenys i faila in.txt paspauskite enter klavisa.\n\n");

    getchar();
    char file[255];
    char fileName[255];

    bool correctSep, validate, loop = true; // tikrinimas ar yra kablelis
    double in, tmp, answer = 0;
    int counter, counterKab, i;             // simboliu kiekis faile
    char input[10] = {0}, c, delim[] = ","; // delim - Delimiter
    FILE *fp = NULL, *makeF;

    fp = fopen("in.txt", "r");

    while(fp == NULL)
    {
        printf("Failas nebuvo rastas, iveskite failo pavadinima be .txt\n");
        scanf("%s", fileName);

        snprintf(file, sizeof(file), "%s.txt", fileName);
        fp = fopen(file, "r");
    }

    int validStep = 1;
    // Validacija ir kitos operacijos
    while (loop)
    {
        for (int i = 0; i < 10; i++)
        {
            input[i] = 0;
        }

        correctSep = false;
        counter = 0;
        counterKab = 0;
        i = 0;
        validStep = 1;
        validate = 0;

        for (c = getc(fp); c != EOF; c = getc(fp))
        {
            if (!(c <= 32))
                counter++;
            if (c == 44)
                counterKab++;
            if (i <= 8)
            {
                input[i] = c;
                i++;
            }
            //printf("C: %d | ascii: %d | SEP: %d\n", counter, c, correctSep);
        }

        if (counterKab == 1)
            correctSep = true;

        if (correctSep == 1)
        {
            //printf("IF1: %d\n", counter);
            if (counter >= 4 && counter <= 8)
            {
                char *ptr = strtok(input, delim);
                while (ptr != NULL && validate == 0)
                {
                    validate = Validation(ptr);

                    tmp = atoi(ptr);
                    //printf("POINTER: %s\n", ptr);
                    //printf("VALIDATE: %d\n", validate);
                    if ((validStep == 1 && tmp < 10) || (validStep == 1 && tmp > 1000))
                    {
                        ErrorMsg(4);
                        fclose(fp);
                        getchar();
                        getchar();
                        fp = fopen(file, "r");
                        break;
                    }
                    // if ((validStep == 2 && strlen(ptr)) || (validStep == 2 && strlen(ptr)))
                    // {
                    //     ErrorMsg(4);
                    //     fclose(fp);
                    //     getchar();
                    //     fp = fopen("in.txt", "r");
                    //     break;
                    // }
                    //printf("VALIDSTEPL %d\n", validStep);
                    if ((validate == 1 && validStep == 1))
                    {
                        ErrorMsg(4);
                        fclose(fp);
                        getchar();
                        getchar();
                        fp = fopen(file, "r");
                        break;
                    }
                    if (validate == 0 && validStep == 1)
                    {
                        //printf("IFAS\n");
                        answer = digitConversion(ptr, false, answer);
                    }
                    else if (validate == 0 && validStep == 2)
                    {
                        //printf("IFAS2\n");
                        // answer = atoi(input);
                        answer = digitConversion(ptr, true, answer);
                        if (answer == 0)
                        {
                            // ErrorMsg(5);
                            // fclose(fp);
                            // getchar();
                            // fp = fopen("in.txt", "r");
                            break;
                        }
                        //printf("Answer: %f", answer);
                    }
                    //printf("VALIDATE: %d\n", validate);
                    ptr = strtok(NULL, delim);
                    if (validStep == 1 && ptr == NULL)
                    {
                        //printf("VALID1 IDK\n");
                        ErrorMsg(5);
                        fclose(fp);
                        getchar();
                        getchar();
                        fp = fopen(file, "r");
                        break;
                    }
                    validStep++;
                }

                if (validStep == 2)
                {
                    ErrorMsg(5);
                    fclose(fp);
                    getchar();
                    getchar();
                    fp = fopen(file, "r");
                }
                if (validStep == 3)
                    loop = false;
            }
            else if (counter < 4)
            {
                ErrorMsg(1);
                fclose(fp);
                getchar();
                getchar();
                fp = fopen(file, "r");
            }
            else if (counter > 8)
            {
                ErrorMsg(2);
                fclose(fp);
                getchar();
                getchar();
                fp = fopen(file, "r");
            }
            //printf("WHILE PABAIGA\n\n");
        }

        else if (correctSep == 0)
        {
            ErrorMsg(3);
            getchar();
            getchar();
            fclose(fp);
            fp = fopen(file, "r");
        }
    }

    // printf("ANSW: %f", answer);
    printf("\nSimboliu kiekis: %d", counter - 1);

    fclose(fp);
    return 0;
}