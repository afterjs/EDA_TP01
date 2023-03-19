#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 62

struct KeyValue
{
    char *key;
    char *value;
};

struct KeyValue arr[MAX] = {
    {"a", "y"},
    {"b", "n"},
    {"c", "f"},
    {"d", "i"},
    {"e", "c"},
    {"f", "w"},
    {"g", "l"},
    {"h", "b"},
    {"i", "k"},
    {"j", "u"},
    {"k", "o"},
    {"l", "m"},
    {"m", "x"},
    {"n", "s"},
    {"o", "e"},
    {"p", "v"},
    {"q", "z"},
    {"r", "p"},
    {"s", "d"},
    {"t", "r"},
    {"u", "j"},
    {"v", "g"},
    {"w", "t"},
    {"x", "h"},
    {"y", "a"},
    {"z", "q"},
    {"0", "5"},
    {"1", "8"},
    {"2", "7"},
    {"3", "9"},
    {"4", "1"},
    {"5", "3"},
    {"6", "2"},
    {"7", "0"},
    {"8", "6"},
    {"9", "4"},
    {"A", "M"},
    {"B", "Q"},
    {"C", "T"},
    {"D", "W"},
    {"E", "Z"},
    {"F", "D"},
    {"G", "G"},
    {"H", "J"},
    {"I", "N"},
    {"J", "R"},
    {"K", "U"},
    {"L", "X"},
    {"M", "A"},
    {"N", "E"},
    {"O", "I"},
    {"P", "L"},
    {"Q", "O"},
    {"R", "S"},
    {"S", "V"},
    {"T", "Y"},
    {"U", "B"},
    {"V", "F"},
    {"W", "H"},
    {"X", "K"},
    {"Y", "P"},
    {"Z", "C"},
};

/**
 * @brief Encrypts a string using a substitution cipher.
 *
 * This function takes a string and replaces each character with a corresponding
 * character from a substitution table. The substitution table is defined in a 
 * global array `arr`.
 *
 * @param str The string to encrypt.
 *
 * @return The encrypted string.
 *
 * @see arr
 */
char *encrypt(char *str)
{
    int i, j;
    for (i = 0; i < strlen(str); i++)
    {
        for (j = 0; j < MAX; j++)
        {
            if (str[i] == arr[j].key[0])
            {
                str[i] = arr[j].value[0];
                break;
            }
        }
    }

    return str;
}

