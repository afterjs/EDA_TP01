#include "../include/header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int removeUserFromFile(Aux_User *user)
{
    FILE *fp;
    FILE *temp;
    int found = 0;
    Aux_User temp_user;

    fp = fopen("./data/users.bin", "rb");
    temp = fopen("./data/temp.bin", "wb");

    if (fp == NULL || temp == NULL)
    {
        return 0;
    }

    while (fread(&temp_user, sizeof(Aux_User), 1, fp))
    {
        if (strcmp(temp_user.uuid, user->uuid) == 0)
        {
            found = 1;
            continue;
        }
        fwrite(&temp_user, sizeof(Aux_User), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    if (found == 0)
    {
        remove("./data/temp.bin");
        return 0;
    }

    remove("./data/users.bin");
    rename("./data/temp.bin", "./data/users.bin");
    return 1;
}

int updateUserAtFile(Aux_User *user)
{
    FILE *fp = fopen("./data/users.bin", "rb+");
    if (fp == NULL)
    {
        return 0;
    }
    Aux_User aux;
    while (fread(&aux, sizeof(Aux_User), 1, fp))
    {
        if (strcmp(aux.uuid, user->uuid) == 0)
        {
            fseek(fp, -sizeof(Aux_User), SEEK_CUR);
            fwrite(user, sizeof(Aux_User), 1, fp);
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

int saveUserAtFile(Aux_User *user)
{

    printf("\nsaving new user at file with email -> %s", user->personal_data.login.email);

    FILE *fp = fopen("./data/users.bin", "ab");
    if (fp == NULL)
    {
        return 0;
    }

    fwrite(user, sizeof(Aux_User), 1, fp);
    fclose(fp);

    press_to_continue();
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
        printf("\nDate of birth: %d/%d/%d", aux->personal_data.dob.day, aux->personal_data.dob.month, aux->personal_data.dob.year);
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
        if (aux->personal_data.nif == *nif)
        {
            *nif = -1;
            return aux;
        }
        if (strcmp(aux->personal_data.login.email, email) == 0)
        {
            strcpy(email, "-----------");
            return aux;
        }

        if (strcmp(aux->personal_data.phone_number, phone_number) == 0)
        {
            strcpy(phone_number, "-----------");
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
        users->personal_data.dob.day = user->personal_data.dob.day;
        users->personal_data.dob.month = user->personal_data.dob.month;
        users->personal_data.dob.year = user->personal_data.dob.year;
        strcpy(users->personal_data.login.email, user->personal_data.login.email);
        strcpy(users->personal_data.login.password, user->personal_data.login.password);
        strcpy(users->personal_data.phone_number, user->personal_data.phone_number);
        users->personal_data.balance = user->personal_data.balance;
        strcpy(users->personal_data.address.street, user->personal_data.address.street);
        strcpy(users->personal_data.address.city, user->personal_data.address.city);
        strcpy(users->personal_data.address.country, user->personal_data.address.country);
        strcpy(users->personal_data.address.postal_code, user->personal_data.address.postal_code);
        strcpy(users->rented_transport.uuid, user->rented_transport.uuid);
        strcpy(users->rented_transport.rented_transport_type, user->rented_transport.rented_transport_type);
        strcpy(users->rented_transport.rented_transport_code, user->rented_transport.rented_transport_code);
        users->rented_transport.rented_at = user->rented_transport.rented_at;
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
    aux->next_node->personal_data.dob.day = user->personal_data.dob.day;
    aux->next_node->personal_data.dob.month = user->personal_data.dob.month;
    aux->next_node->personal_data.dob.year = user->personal_data.dob.year;
    strcpy(aux->next_node->personal_data.login.email, user->personal_data.login.email);
    strcpy(aux->next_node->personal_data.login.password, user->personal_data.login.password);
    strcpy(aux->next_node->personal_data.phone_number, user->personal_data.phone_number);
    aux->next_node->personal_data.balance = user->personal_data.balance;
    strcpy(aux->next_node->personal_data.address.street, user->personal_data.address.street);
    strcpy(aux->next_node->personal_data.address.city, user->personal_data.address.city);
    strcpy(aux->next_node->personal_data.address.country, user->personal_data.address.country);
    strcpy(aux->next_node->personal_data.address.postal_code, user->personal_data.address.postal_code);

    strcpy(aux->next_node->rented_transport.uuid, user->rented_transport.uuid);
    strcpy(aux->next_node->rented_transport.rented_transport_type, user->rented_transport.rented_transport_type);
    strcpy(aux->next_node->rented_transport.rented_transport_code, user->rented_transport.rented_transport_code);
    aux->next_node->rented_transport.rented_at = user->rented_transport.rented_at;

    aux->next_node->next_node = NULL;

    return users;
}

Aux_User *getUserDetails(User *users)
{

    cls();
    Aux_User *user = malloc(sizeof(Aux_User));
    int age = 0;

    printf("Before we start, we need to know when its your birthday!\n\n");

    printf("Enter your day of birth (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &user->personal_data.dob.day, &user->personal_data.dob.month, &user->personal_data.dob.year);
    age = getAge(user->personal_data.dob.day, user->personal_data.dob.month, user->personal_data.dob.year);

    if (age < 18)
    {
        cls();
        printf("You are not old enough to use this app! 😟.\n");
        press_to_continue();
        return NULL;
    }

    do
    {
        cls();

        printf("Let's start choosing your email and password for login\n\n");

        flushstdin();

        if (strcmp(user->personal_data.login.email, "-----------") == 0)
        {
            printf("\tThis email is already in use, try again!\n\n");
        }

        if (user->personal_data.nif == -1)
        {
            printf("\tThis NIF is already in use, try again!\n\n");
        }

        if (strcmp(user->personal_data.phone_number, "-----------") == 0)
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
    strcpy(user->rented_transport.rented_transport_code, "XXX000");
    strcpy(user->uuid, gen_uuid());

    char *password = encrypt(user->personal_data.login.password);

    strcpy(user->personal_data.login.password, password);

    users = insertUser(users, user);

    return user;
}

int load_users(User **users)
{

    if (existFile("./data/users.bin", "rb") == 0)
    {
        createUsersFile();
    }

    FILE *fp;
    fp = fopen("./data/users.bin", "rb");

    if (fp == NULL)
    {
        printf("Error opening file\n");
        return 0;
    }

    Aux_User *aux = malloc(sizeof(Aux_User));
    int counter = 1;

    while (fread(aux, sizeof(Aux_User), 1, fp) == 1)
    {
        *users = insertUser(*users, aux);
    }

    free(aux);
    fclose(fp);

    return 1;
}