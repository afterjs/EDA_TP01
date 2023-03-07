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
        printf("\nEmail: %s", aux->personal_data.login.email);
        printf("\nPassword: %s", aux->personal_data.login.password);
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
        if (strcmp(aux->personal_data.login.email, email) == 0)
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
        users = malloc(sizeof(User));

        if (users == NULL)
        {
            printf("Error allocating memory");
            return NULL;
        }

        strcpy(users->uuid, user->uuid);
        users->user_type = user->user_type;
        strcpy(users->personal_data.name, user->personal_data.name);
        users->personal_data.nif = user->personal_data.nif;
        strcpy(users->personal_data.login.email, user->personal_data.login.email);
        strcpy(users->personal_data.login.password, user->personal_data.login.password);
        strcpy(users->personal_data.phone_number, user->personal_data.phone_number);
        users->personal_data.balance = user->personal_data.balance;
        strcpy(users->personal_data.address.street, user->personal_data.address.street);
        strcpy(users->personal_data.address.city, user->personal_data.address.city);
        strcpy(users->personal_data.address.country, user->personal_data.address.country);
        strcpy(users->personal_data.address.postal_code, user->personal_data.address.postal_code);
        users->next_node = NULL;

        return users;
    }

    User *aux = users;

    while (aux->next_node != NULL)
    {
        aux = aux->next_node;
    }

    aux->next_node = malloc(sizeof(User));

    if (aux->next_node == NULL)
    {
        // Handle error - could not allocate memory
        printf("Error allocating memory");
        return NULL;
    }

    strcpy(aux->next_node->uuid, user->uuid);
    aux->next_node->user_type = user->user_type;
    strcpy(aux->next_node->personal_data.name, user->personal_data.name);
    aux->next_node->personal_data.nif = user->personal_data.nif;
    strcpy(aux->next_node->personal_data.login.email, user->personal_data.login.email);
    strcpy(aux->next_node->personal_data.login.password, user->personal_data.login.password);
    strcpy(aux->next_node->personal_data.phone_number, user->personal_data.phone_number);
    aux->next_node->personal_data.balance = user->personal_data.balance;
    strcpy(aux->next_node->personal_data.address.street, user->personal_data.address.street);
    strcpy(aux->next_node->personal_data.address.city, user->personal_data.address.city);
    strcpy(aux->next_node->personal_data.address.country, user->personal_data.address.country);
    strcpy(aux->next_node->personal_data.address.postal_code, user->personal_data.address.postal_code);
    aux->next_node->next_node = NULL;

    return users;
}

int authenticate(char *email, char *password, User **users, Aux_User **user_details)
{
    char *encryptedPassword = encrypt(password);

    User *aux = *users;

    while (aux != NULL)
    {

        if (strcmp(aux->personal_data.login.email, email) == 0 && strcmp(aux->personal_data.login.password, encryptedPassword) == 0)
        {
            // dereference user_details pointer twice to update it with new user's details
            (*user_details)->user_type = aux->user_type;
            strcpy((*user_details)->personal_data.name, aux->personal_data.name);
            (*user_details)->personal_data.nif = aux->personal_data.nif;
            strcpy((*user_details)->personal_data.login.email, aux->personal_data.login.email);
            strcpy((*user_details)->personal_data.login.password, aux->personal_data.login.password);
            strcpy((*user_details)->personal_data.phone_number, aux->personal_data.phone_number);
            (*user_details)->personal_data.balance = aux->personal_data.balance;
            strcpy((*user_details)->personal_data.address.street, aux->personal_data.address.street);
            strcpy((*user_details)->personal_data.address.city, aux->personal_data.address.city);
            strcpy((*user_details)->personal_data.address.country, aux->personal_data.address.country);
            strcpy((*user_details)->personal_data.address.postal_code, aux->personal_data.address.postal_code);

            return 1;
        }
        aux = aux->next_node;
    }

    return 0;
}
