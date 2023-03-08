#include "./include/header.h"
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
            // free(*users);
            printf("Client\n");
            press_to_continue();
        }
        else
        {
            printf("Admin\n");
            press_to_continue();
        }
    }
    else
    {
        cls();
        printf("Invalid credentials, try again\n\n");
        press_to_continue();
        login(users, user_details);
    }

    cls();
    printf("Occured an error, try again later\n\n");
    exit(1);

}

void register_user(User **users, Aux_User **user_details)
{

    /* void getUserDetails() {
         printf("\n\nT3EAHGIEABGWAGWAIIGW\n\n");
     }*/

    Aux_User *user = malloc(sizeof(Aux_User));

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
        // getUserDetails();
        scanf("%d", &option);

    } while (option != 0 && option != 1);

    switch (option)
    {
    case 1:
        // user->user_type = 0;
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
        // login(&users, &user_details);
        login(users, user_details);
        break;
    case 2:
        register_user(users, user_details);
        printf("Register\n");
        press_to_continue();
        break;

    default:
        cls();
        printf("Thank you for using GoSmartCity!!!\n");
        press_to_continue();
        break;
    }
    free(*user_details);
    free(*users);
}

int createUsersFile(User **users)
{

    Aux_User *client = malloc(sizeof(Aux_User));
    Aux_User *admin = malloc(sizeof(Aux_User));

    strcpy(client->uuid, "71cf9278-cf92-4ecf-ac36-48c7c5d319d0");
    client->user_type = 0;
    strcpy(client->personal_data.name, "Ricardo Amaro");
    client->personal_data.nif = 123456789;
    strcpy(client->personal_data.login.email, "xavieramaro2@gmail.com");
    strcpy(client->personal_data.login.password, "fmkcsr879132064");

    strcpy(client->personal_data.phone_number, "912345678");
    client->personal_data.balance = 133.12;
    strcpy(client->personal_data.address.street, "Estrada Nacional 305");
    strcpy(client->personal_data.address.city, "Viana do Castelo");
    strcpy(client->personal_data.address.country, "Portugal");
    strcpy(client->personal_data.address.postal_code, "4925-366");

    strcpy(admin->uuid, "833407dd-6e8a-464d-adf9-e665451e850a");
    admin->user_type = 1;
    strcpy(admin->personal_data.name, "Ricardo Oliveira");
    admin->personal_data.nif = 934567890;
    strcpy(admin->personal_data.login.email, "joao@gmail.com");
    strcpy(admin->personal_data.login.password, "yixks879132064");
    strcpy(admin->personal_data.phone_number, "+351968912312");
    admin->personal_data.balance = 0.00;
    strcpy(admin->personal_data.address.street, "boulevard");
    strcpy(admin->personal_data.address.city, "barcelona");
    strcpy(admin->personal_data.address.country, "spain");
    strcpy(admin->personal_data.address.postal_code, "4925-366");

    saveUserAtFile(client);
    saveUserAtFile(admin);

    free(client);
    free(admin);
    return 1;
}

int load_users(User **users)
{

    if (existFile("./data/users.bin", "rb") == 0)
    {
        createUsersFile(users);
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
