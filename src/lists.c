#include "./include/header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


User *listUsers(User *users)
{
    User *aux = users;
    int counter = 1;

    while (aux != NULL)
    {
        printf("\nUser ->%d", counter++);
        printf("\nUUID: %s", aux->uuid);
        printf("\nUser type: %d", aux->user_type);
        printf("\nName: %s", aux->personal_data.name);
        printf("\nNIF: %d", aux->personal_data.nif);
        printf("\nEmail: %s", aux->personal_data.email);
        printf("\nPhone number: %s", aux->personal_data.phone_number);
        printf("\nBalance: %.2f", aux->personal_data.balance);
        printf("\nStreet: %s", aux->personal_data.address.street);
        printf("\nCity: %s", aux->personal_data.address.city);
        printf("\nCountry: %s", aux->personal_data.address.country);
        printf("\nPostal code: %s\n\n", aux->personal_data.address.postal_code);
        aux = aux->next_node;
    }
    return users;
}

User *existUser(User *users, int *nif, char *email, char *phone_number)
{
    User *aux = users;
    while (aux != NULL)
    {
        if (aux->personal_data.nif == 0)
        {
            return aux;
        }
        if (strcmp(aux->personal_data.email, email) == 0)
        {
            return aux;
        }
        if (strcmp(aux->personal_data.phone_number, phone_number) == 0)
        {
            return aux;
        }
        aux = aux->next_node;
    }
    return NULL;
}

User *insertUser(User *users, Aux_User *user)
{

    if (users == NULL)
    {
      //  strcpy(user->uuid, generateUUID());

        return 0;
    }
}
