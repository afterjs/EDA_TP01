#include "./include/header.h"

#include <stdlib.h>
#include <stdio.h>


/**
 * @brief Main function of the program. It loads user data and displays the login menu.
 * 
 * @param argc The number of command-line arguments.
 * @return int The exit status of the program.
 * 
 * @see load_users()
 * @see authMenu()
 */

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