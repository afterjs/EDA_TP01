#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "../include/header.h"

/**
 * @brief Asks the user if they want to update certain information.
 *
 * @param info The information to be updated.
 * @return 1 if the user wants to update the information, 0 if not.
 *
 * @see updatePricePerMinute(), updatePriceBase(), updateUserDOB()
 */
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

/**
 * @brief Generates a 6-character code consisting of 3 random uppercase letters and 3 random digits.
 *
 * @return char* Pointer to the generated code.
 * @see rand()
 */
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

/**
 * @brief Generates a random UUID string.
 *
 * The UUID is generated in the format 8-4-4-4-12, with hexadecimal digits and
 * dashes separating each block of digits. The string is stored in a static buffer.
 *
 * @return A pointer to the generated UUID string.
 */
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

/**
 * @brief Check if an email address is valid.
 *
 * This function checks if an email address is valid by counting the number of "@" and "." characters in the address.
 * A valid email address has exactly one "@" character and exactly one "." character.
 *
 * @param email The email address to check.
 * @return Returns 1 if the email address is valid, 0 otherwise.
 *
 */
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

/**
 * @brief Check if a file exists.
 *
 * @param path The path to the file.
 * @param openMode The file opening mode to use.
 * @return 1 if the file exists, 0 otherwise.
 *
 * This function checks if a file exists at the specified path by trying to
 * open it with the specified mode. If the file can be opened, it is closed
 * and the function returns 1, indicating that the file exists. Otherwise,
 * the function returns 0, indicating that the file does not exist.
 *
 * @see fopen()
 * @see fclose()
 */
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

/**
 * @brief Clears the console screen.
 *
 * Uses the "clear" command to clear the console screen.
 *
 * @see system()
 */
void cls()
{
    system("clear");
}

/**
 * @brief Flushes standard input (stdin) stream by clearing any remaining input.
 * @details This function is useful when we need to clear the input buffer after reading some input, for example to prevent the leftover input from being read by the next input function call.
 *
 * @see getchar()
 *
 */
void flushstdin(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

/**
 * @brief Flushes standard input, displays a message to press enter to continue, and waits for the user to press enter.
 *
 * This function is used to pause the execution of a program and wait for the user to press enter. It first flushes the standard input
 * to clear any existing input. It then displays a message to the user to press enter to continue. Finally, it waits for the user to
 * press enter before returning.
 *
 * @see flushstdin()
 */
void press_to_continue()
{
    flushstdin();
    fflush(stdin);
    printf("\n\nPress enter to continue...");
    getchar();
}

/**
 * @brief Calculates the age based on the provided date of birth.
 *
 * @param day The day of birth.
 * @param month The month of birth.
 * @param year The year of birth.
 * @return The calculated age in years.
 *
 * This function calculates the age of a person based on their date of birth, using the current date.
 * The calculation is done in years, and takes into account the month and day of birth.
 *
 * @see time, localtime
 */
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

/**
 * @brief Converts a timestamp to a formatted text string.
 *
 * This function takes a timestamp and converts it to a formatted text string
 * with the format "dd/mm/yyyy hh:mm:ss". The resulting string is stored in a
 * static buffer, so subsequent calls to this function will overwrite the
 * previous result. Use the result immediately or copy it to another buffer
 * before calling this function again.
 *
 * @param timestamp The timestamp to convert.
 * @return A pointer to a static buffer containing the formatted text string.
 * @see localtime(), strftime()
 */
char *timestamp_to_text(time_t timestamp)
{
    struct tm *tm = localtime(&timestamp);
    static char buf[20];
    strftime(buf, sizeof(buf), "%d/%m/%Y %H:%M:%S", tm);
    return buf;
}

/**
 * @brief Checks whether the given location is valid.
 *
 * @param location The location to be checked.
 * @return 1 if the location is valid, 0 otherwise.
 *
 * A valid location is a string that starts with '///' and contains exactly two dots.
 *
 * @see strlen()
 */
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