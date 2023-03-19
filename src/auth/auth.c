#include "../include/header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void login(User **users, Aux_User **user_details)
{

    char email[50];
    char password[50];

    cls();
    printf("Enter your email: ");
    do
    {
        scanf("%s", email);
        if (checkEmail(email) == 0)
        {
            cls();
            printf("Invalid email, try again\n\n");
            printf("Enter your email: ");
        }
    } while (checkEmail(email) == 0);

    printf("\nEnter your password: ");
    scanf("%s", password);

    if (authenticate(email, password, users, user_details) == 1)
    {
        if ((*user_details)->user_type == 0)
        {
            free(*users);
            client_main(user_details);
        }
        else
        {
            admin_main(users, user_details);
        }
    }
    else
    {
        cls();
        printf("Invalid credentials, try again\n\n");
        press_to_continue();
        login(users, user_details);
        printf("\n NOTAUTH");
    }

    press_to_continue();
}

void register_user(User **users, Aux_User **user_details)
{
    int option = 0;

    do
    {
        cls();

        if (option != 0 && option != 1)
        {
            cls();

            printf("Invalid option, try again\n\n");
        }
        printf("\t Create your account and start using our services\n\n");
        printf("\t1 - Create Account\n");
        printf("\t0 - Login\n\n");
        printf("What do you want to do? Choose an option: ");
        scanf("%d", &option);

    } while (option != 0 && option != 1);

    switch (option)
    {
    case 1:
        Aux_User *aux = malloc(sizeof(Aux_User));
        aux = getUserDetails(*users, 0);

        if (aux == NULL)
        {
            authMenu(users, user_details);
        }

        saveUserAtFile(aux);
        *user_details = aux;
        free(aux);
        break;
    case 0:
        login(users, user_details);
        return;
    default:
        break;
    }

    cls();
}

void authMenu(User **users, Aux_User **user_details)
{

    int option = 0;

    do
    {
        cls();

        if (option < 0 || option > 2)
        {
            cls();

            printf("Invalid option, try again\n\n");
        }

        printf("\tWelcome to the GoSmartCity\n\n");
        printf("\t1 - Login\n");
        printf("\t2 - Register\n");
        printf("\t0 - Exit\n\n");
        printf("What do you want to do? Choose an option: ");
        scanf("%d", &option);
    } while (option < 0 || option > 2);

    switch (option)
    {
    case 1:
        login(users, user_details);
        break;
    case 2:
        register_user(users, user_details);
        printf("User registered successfully\n");
        press_to_continue();
        authMenu(users, user_details);
        break;
    default:
        cls();
        printf("Thank you for using GoSmartCity!!!\n");
        press_to_continue();
        free(*user_details);
        free(*users);
        break;
    }
}

int createUsersFile()
{

    Aux_User *client = malloc(sizeof(Aux_User));
    Aux_User *admin = malloc(sizeof(Aux_User));

    strcpy(client->uuid, "71cf9278-cf92-4ecf-ac36-48c7c5d319d0");
    client->user_type = 0;
    strcpy(client->personal_data.name, "Ricardo Amaro");
    client->personal_data.nif = 123456789;
    client->personal_data.dob.day = 14;
    client->personal_data.dob.month = 12;
    client->personal_data.dob.year = 2001;
    strcpy(client->personal_data.login.email, "xavieramaro2@gmail.com");
    strcpy(client->personal_data.login.password, "fmkcsr879132064");
    strcpy(client->personal_data.phone_number, "912345678");
    client->personal_data.balance = 5.00;
    strcpy(client->personal_data.address.street, "Estrada Nacional 305");
    strcpy(client->personal_data.address.city, "Viana do Castelo");
    strcpy(client->personal_data.address.country, "Portugal");
    strcpy(client->personal_data.address.postal_code, "4925-366");

    strcpy(client->rented_transport.rented_transport_code, "XXX000");

    strcpy(admin->uuid, "833407dd-6e8a-464d-adf9-e665451e850a");
    admin->user_type = 1;
    strcpy(admin->personal_data.name, "Ricardo Oliveira");
    admin->personal_data.nif = 934567890;
    admin->personal_data.dob.day = 12;
    admin->personal_data.dob.month = 12;
    admin->personal_data.dob.year = 1999;
    strcpy(admin->personal_data.login.email, "joao@gmail.com");
    strcpy(admin->personal_data.login.password, "yixks879132064");
    strcpy(admin->personal_data.phone_number, "+351968912312");
    admin->personal_data.balance = 0.00;
    strcpy(admin->personal_data.address.street, "boulevard");
    strcpy(admin->personal_data.address.city, "barcelona");
    strcpy(admin->personal_data.address.country, "spain");
    strcpy(admin->personal_data.address.postal_code, "4925-366");

    strcpy(admin->rented_transport.rented_transport_code, "XXX000");

    saveUserAtFile(admin);
    saveUserAtFile(client);

    free(client);
    free(admin);
    return 1;
}

int authenticate(char *email, char *password, User **users, Aux_User **user_details)
{

    char *encryptedPassword = encrypt(password);
    int counter = 0;
    User *current_user = *users;

    while (current_user != NULL)
    {

        if (strcmp(current_user->personal_data.login.email, email) == 0 &&
            strcmp(current_user->personal_data.login.password, encryptedPassword) == 0)
        {

            (*user_details)->user_type = current_user->user_type;
            strcpy((*user_details)->uuid, current_user->uuid);
            strcpy((*user_details)->personal_data.name, current_user->personal_data.name);
            (*user_details)->personal_data.nif = current_user->personal_data.nif;
            strcpy((*user_details)->personal_data.login.email, current_user->personal_data.login.email);
            strcpy((*user_details)->personal_data.login.password, current_user->personal_data.login.password);
            strcpy((*user_details)->personal_data.phone_number, current_user->personal_data.phone_number);
            (*user_details)->personal_data.balance = current_user->personal_data.balance;
            strcpy((*user_details)->personal_data.address.street, current_user->personal_data.address.street);
            strcpy((*user_details)->personal_data.address.city, current_user->personal_data.address.city);
            strcpy((*user_details)->personal_data.address.country, current_user->personal_data.address.country);
            strcpy((*user_details)->personal_data.address.postal_code, current_user->personal_data.address.postal_code);
            strcpy((*user_details)->rented_transport.rented_transport_code, current_user->rented_transport.rented_transport_code);
            strcpy((*user_details)->rented_transport.rented_transport_type, current_user->rented_transport.rented_transport_type);
            (*user_details)->rented_transport.rented_at = current_user->rented_transport.rented_at;
            strcpy((*user_details)->rented_transport.uuid, current_user->rented_transport.uuid);
            (*user_details)->personal_data.dob.day = current_user->personal_data.dob.day;
            (*user_details)->personal_data.dob.month = current_user->personal_data.dob.month;
            (*user_details)->personal_data.dob.year = current_user->personal_data.dob.year;

            return 1;
        }
        current_user = current_user->next_node;
    }

    return 0;
}