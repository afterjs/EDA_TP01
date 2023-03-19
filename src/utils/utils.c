#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "../include/header.h"

int ask_for_update(char *info)
{

    int choice = 1;

    do
    {
        cls();
        printf("\n\tUpdating informations\n");

        if (choice != 1 && choice != 2)
        {
            printf("\tInvalid option, please try again\n");
        }

        if (strcmp(info, "price_minute") == 0)
        {
            printf("\n\tDo you want to update the price per minute? (yes - 1 / No - 2): ");
        }
        else if (strcmp(info, "price_base") == 0)
        {
            printf("\n\tDo you want to update the price base? (yes - 1 / No - 2): ");
        }
        else if (strcmp(info, "dob") == 0)
        {
            printf("\n\tDo you want to update your date of birth? (yes - 1 / No - 2): ");
        }
        else
        {
            printf("\n\tDo you want to update %s? (yes - 1 / No - 2): ", info);
        }
        scanf("%d", &choice);
    } while (choice != 1 && choice != 2);

    if (choice == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char *generate_code()
{
    char *code = malloc(7); // Allocate memory for the code
    char letters[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i;

    for (i = 0; i < 3; i++)
    {
        code[i] = letters[rand() % 26];
    }

    for (i = 3; i < 6; i++)
    {
        code[i] = '0' + (rand() % 10);
    }

    code[6] = '\0';

    return code;
}

char *gen_uuid()
{
    char v[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    // 3fb17ebc-bc38-4939-bc8b-74f2443281d4
    // 8 dash 4 dash 4 dash 4 dash 12
    static char buf[37] = {0};

    // gen random for all spaces because lazy
    for (int i = 0; i < 36; ++i)
    {
        buf[i] = v[rand() % 16];
    }

    // put dashes in place
    buf[8] = '-';
    buf[13] = '-';
    buf[18] = '-';
    buf[23] = '-';

    // needs end byte
    buf[36] = '\0';

    return buf;
}

int checkEmail(char *email)
{
    int at = 0;
    int dot = 0;
    int length = strlen(email);

    for (int i = 0; i < length; i++)
    {
        if (*(email + i) == '@')
        {
            at++;
        }
        if (*(email + i) == '.')
        {
            dot++;
        }
    }

    return (at == 1 && dot == 1) ? 1 : 0;
}

int existFile(char *path, char *openMode)
{
    FILE *file = fopen(path, openMode);
    if (file)
    {
        fclose(file);
        return 1;
    }
    else
    {
        return 0;
    }
}

void cls()
{
    system("clear");
}

void flushstdin(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void press_to_continue()
{
    flushstdin();
    fflush(stdin);
    printf("\n\nPress enter to continue...");
    getchar();
}

int getAge(int day, int month, int year)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    int age = tm.tm_year + 1900 - year;

    if (tm.tm_mon + 1 < month)
    {
        age--;
    }
    else if (tm.tm_mon + 1 == month)
    {
        if (tm.tm_mday < day)
        {
            age--;
        }
    }

    return age;
}

char *timestamp_to_text(time_t timestamp)
{
    struct tm *tm = localtime(&timestamp);
    static char buf[20];
    strftime(buf, sizeof(buf), "%d/%m/%Y %H:%M:%S", tm);
    return buf;
}

int isValidLocation(char *location)
{
    int dot = 0;
    if (location[0] == '/' && location[1] == '/' && location[2] == '/')
    {
        for (int i = 0; i < strlen(location); i++)
        {
            if (location[i] == '.')
            {
                dot++;
            }
        }
        if (dot == 2)
        {
            return 1;
        }
    }
    return 0;
}