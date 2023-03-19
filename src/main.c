#include "./include/header.h"

#include <stdlib.h>
#include <stdio.h>

int main(int argc)
{
    User *users = NULL;
    Aux_User *user_details = malloc(sizeof(Aux_User));

    if (load_users(&users))
    {
         authMenu(&users, &user_details);
      
    }

    return 0;
}