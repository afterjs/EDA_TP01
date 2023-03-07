#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
