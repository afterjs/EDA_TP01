#include "./include/header.h"

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

int main(int argc)
{
    User *users = NULL;
    Aux_User *user_details = malloc(sizeof(Aux_User));

    if (load_users(&users))
    {
        login(&users, &user_details);
    }

    return 0;
}