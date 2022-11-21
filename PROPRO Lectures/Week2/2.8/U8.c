#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void binToDec(char sk[]) // 2-taine i 10-taine
{
    int dec = 0, length, tmp, power;
    char one;
    length = strlen(sk);
    power = length - 1;
    for (int i = 0; i < length; i++)
    {
        one = sk[i];
        tmp = atoi(&one);
        if (power > 0)
            dec += tmp * pow(2, power);
        else
            dec += tmp;
        power--;
    }

    printf("10-taine: %d\n", dec);
}

void binToHex(char sk[]) // 2-taine i 16-taine
{
    int dec = 0, length, tmp, power;
    char one;
    length = strlen(sk);
    power = length - 1;

    for (int i = 0; i < length; i++)
    {
        one = sk[i];
        tmp = atoi(&one);
        if (power > 0)
            dec += tmp * pow(2, power);
        else
            dec += tmp;
        power--;
    }

    printf("16-taines: 0x%x\n", dec);
}

void decToBin(int sk) // 10-taine i 2-taine
{
    int bin[32];
    int i = 0;

    while (sk > 0)
    {
        bin[i++] = sk % 2;
        sk /= 2;
    }

    printf("2-taine: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%d", bin[j]);
    printf("\n");
}

void decToHex(int sk) // 10-taine i 16-taine
{
    printf("16-taine: 0x%x\n", sk);
}

void hexToBin(char hex[]) // 16-taine i 2-taine
{
    int length = strlen(hex);
    int tmp, dec = 0, power;
    power = length - 1;
    for (int i = 0; i < length; i++)
    {
        if (isdigit(hex[i]))
            dec += atoi(&hex[i]) * pow(16, power);
        else
        {
            hex[i] = toupper(hex[i]);
            switch (hex[i])
            {
            case 'A':
                dec += 10 * pow(16, power);
                break;
            case 'B':
                dec += 11 * pow(16, power);
                break;
            case 'C':
                dec += 12 * pow(16, power);
                break;
            case 'D':
                dec += 13 * pow(16, power);
                break;
            case 'E':
                dec += 14 * pow(16, power);
                break;
            case 'F':
                dec += 15 * pow(16, power);
                break;

            default:
                break;
            }
            power--;
        }
    }

    int bin[32];
    int i = 0;

    while (dec > 0)
    {
        bin[i++] = dec % 2;
        dec /= 2;
    }

    printf("2-taine: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%d", bin[j]);
    printf("\n");
}

void hexToDec(char hex[])
{
    int length = strlen(hex);
    int tmp, dec = 0, power;
    power = length - 1;
    for (int i = 0; i < length; i++)
    {
        if (power > 0)
        {
            if (isdigit(hex[i]))
                dec += atoi(&hex[i]) * pow(16, power);
            else
            {
                hex[i] = toupper(hex[i]);
                switch (hex[i])
                {
                case 'A':
                    dec += 10 * pow(16, power);
                    break;
                case 'B':
                    dec += 11 * pow(16, power);
                    break;
                case 'C':
                    dec += 12 * pow(16, power);
                    break;
                case 'D':
                    dec += 13 * pow(16, power);
                    break;
                case 'E':
                    dec += 14 * pow(16, power);
                    break;
                case 'F':
                    dec += 15 * pow(16, power);
                    break;

                default:
                    break;
                }
                power--;
            }
        }
        else
        {
            if (isdigit(hex[i]))
                dec += atoi(&hex[i]);
            else
            {
                hex[i] = toupper(hex[i]);
                switch (hex[i])
                {
                case 'A':
                    dec += 10;
                    break;
                case 'B':
                    dec += 11;
                    break;
                case 'C':
                    dec += 12;
                    break;
                case 'D':
                    dec += 13;
                    break;
                case 'E':
                    dec += 14;
                    break;
                case 'F':
                    dec += 15;
                    break;

                default:
                    break;
                }
            }
        }
    }

    printf("10-taine: %d\n", dec);
}

int patikra(char taipNe)
{
    int sk = 1;

    int patikra = 0;
    while (patikra != 1)
    {
        printf("Ar norite konvertuoti dar karta? (Y/N) ");
        scanf(" %c", &taipNe);
        taipNe = toupper(taipNe);
        if (taipNe == 'Y')
        {
            printf("\n\n\n\n");
            patikra = 1;
        }
        else if (taipNe == 'N')
        {
            sk = 0;
            patikra = 1;
        }
        else
            printf("Neteisinga ivestis!\n");
    }

    return sk;
}
int main()
{
    int sistema, restart = 1;
    char taipNe = 'Y';
    char dvejetainiai[32];
    char sesioliktainis[9];
    int desimtainis;
    printf("Si programa yra skirta skaiciavimo sistemu konvertavimui\n");
    while (restart != 0)
    {
        printf("1) 2-taine i 10-taine sistema\n");
        printf("2) 2-taine i 16-taine sistema\n");
        printf("3) 10-taine i 2-taine sistema\n");
        printf("4) 10-taine i 16-taine sistema\n");
        printf("5) 16-taine i 2-taine sistema\n");
        printf("6) 16-taine i 10-taine sistema\n");

        printf("Pasirinkite konvertavima (1-6): ");
        scanf("%d", &sistema);

        switch (sistema)
        {
        case 1:
            printf("Iveskite 2-taini skaiciu (32 skaitmenu limitas): ");
            scanf("%s", dvejetainiai);
            binToDec(dvejetainiai);
            restart = patikra(taipNe);
            break;
        case 2:
            printf("Iveskite 2-taini skaiciu (32 skaitmenu limitas): ");
            scanf("%s", dvejetainiai);
            binToHex(dvejetainiai);
            restart = patikra(taipNe);
            break;
        case 3:
            printf("Iveskite 10-taini skaiciu (skaiciai galimi iki INT limito): ");
            scanf("%d", &desimtainis);
            decToBin(desimtainis);
            restart = patikra(taipNe);
            break;
        case 4:
            printf("Iveskite 10-taini skaiciu (skaiciai galimi iki INT limito): ");
            scanf("%d", &desimtainis);
            decToHex(desimtainis);
            restart = patikra(taipNe);
            break;
        case 5:
            printf("Iveskite 16-taini skaiciu (iki 7FFFFFFF): ");
            scanf("%s", sesioliktainis);
            hexToBin(sesioliktainis);
            restart = patikra(taipNe);
            break;
        case 6:
            printf("Iveskite 16-taini skaiciu (iki 7FFFFFFF): ");
            scanf("%s", sesioliktainis);
            hexToDec(sesioliktainis);
            restart = patikra(taipNe);
            break;
        default:
            printf("Neteisingas pasirinkimas!\n");
            break;
        }
    }
    return 0;
}