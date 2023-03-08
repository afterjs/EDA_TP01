#include "./include/header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int saveUserAtFile(Aux_User *user)
{
    FILE *fp = fopen("./data/users.bin", "ab");
    if (fp == NULL)
    {
        return 0;
    }
    fwrite(user, sizeof(Aux_User), 1, fp);
    fclose(fp);
    return 1;
}

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
    char null[5];
    while (aux != NULL)
    {
        if (aux->personal_data.nif == *nif)
        {
            *nif = -1;
            return aux;
        }
        if (strcmp(aux->personal_data.login.email, email) == 0)
        {
            strcpy(email, null);
            return aux;
        }
        if (strcmp(aux->personal_data.phone_number, phone_number) == 0)
        {
            strcpy(phone_number, null);
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

Aux_User *getUserDetails(User *users)
{

    cls();
    Aux_User *user = malloc(sizeof(Aux_User));
    char null[5];

    do
    {
        cls();
        printf("Let's start choosing your email and password for login\n\n");

        if (strcmp(user->personal_data.login.email, null) == 0)
        {
            printf("\tThis email is already in use, try again!\n\n");
        }

        if (user->personal_data.nif == -1)
        {
            printf("\tThis NIF is already in use, try again!\n\n");
        }

        if (strcmp(user->personal_data.phone_number, null) == 0)
        {
            printf("\tThis phone number is already in use, try again!\n\n");
        }

        printf("Enter your email: ");

        do
        {
            scanf("%s", user->personal_data.login.email);
            if (checkEmail(user->personal_data.login.email) == 0)
            {
                cls();
                printf("Invalid email, try again\n\n");
                printf("Enter your email: ");
            }
        } while (checkEmail(user->personal_data.login.email) == 0);

        cls();
        printf("Let's start choosing your email and password for login\n\n");
        printf("Enter your email: %s\n", user->personal_data.login.email);
        printf("\nEnter your NIF: ");
        scanf("%d", &user->personal_data.nif);
        flushstdin();
        printf("\nEnter your phone number: ");
        scanf("%[^;\n]", user->personal_data.phone_number);

    } while (existUser(users, &user->personal_data.nif, user->personal_data.login.email, user->personal_data.phone_number) != NULL);

    printf("\nEnter your password: ");
    scanf("%s", user->personal_data.login.password);

    cls();
    printf("Incredible, let's some details about you!\n\n");

    flushstdin();
    printf("Enter your name: ");
    scanf("%[^;\n]", user->personal_data.name);

    flushstdin();
    printf("\nEnter your street (Ex: Vila de Frescainha): ");
    scanf("%[^;\n]", user->personal_data.address.street);

    flushstdin();
    printf("\nEnter your city (Ex: Barcelos): ");
    scanf("%[^;\n]", user->personal_data.address.city);

    flushstdin();
    printf("\nEnter your country (Ex: Portugal): ");
    scanf("%[^;\n]", user->personal_data.address.country);

    flushstdin();
    printf("\nEnter your postal code (Ex: 4750-000): ");
    scanf("%[^;\n]", user->personal_data.address.postal_code);

    user->personal_data.balance = 0.0;
    user->user_type = 0;
    strcpy(user->uuid, gen_uuid());
    encrypt(user->personal_data.login.password);

    

    return user;
}

int authenticate(char *email, char *password, User **users, Aux_User **user_details)
{
    char *encryptedPassword = encrypt(password);

    User *aux = *users;

    while (aux != NULL)
    {
        if (strcmp(aux->personal_data.login.email, email) == 0 && strcmp(aux->personal_data.login.password, encryptedPassword) == 0)
        {
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
