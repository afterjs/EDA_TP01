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

    printf("\nEmail -> %s", email);
    printf("\nPassword -> %s", password);

    if (authenticate(email, password, users, user_details) == 1)
    {

            printf("\nMENU USER\n");
        /*if ((*user_details)->user_type == 0)
        {
            free(*users);
            client_main(user_details);
        }
        else
        {
            printf("MENU ADMIN\n");
            press_to_continue();
        }*/
    }
    else
    {
        cls();
        printf("Invalid credentials, try again\n\n");
        press_to_continue();
        login(users, user_details);
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
        aux = getUserDetails(*users);

        if (aux == NULL)
        {
            authMenu(users, user_details);
        }

        saveUserAtFile(aux);
        *user_details = aux;
        free(aux);
        free(*users);
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
        login(users, user_details);
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

    saveUserAtFile(client);
    saveUserAtFile(admin);

    free(client);
    free(admin);
    return 1;
}

int authenticate(char *email, char *password, User **users, Aux_User **user_details)
{


    


   /* char *encryptedPassword = encrypt(password);

    User *aux = *users;

   
    while (aux != NULL)
    {
        printf("\nEmail -> %s | Password %s", aux->personal_data.login.email, aux->personal_data.login.password);

        /*  if (strcmp(aux->personal_data.login.email, email) == 0 && strcmp(aux->personal_data.login.password, encryptedPassword) == 0)
          {
              (*user_details)->user_type = aux->user_type;
              strcpy((*user_details)->uuid, aux->uuid);
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
              strcpy((*user_details)->rented_transport.rented_transport_code, aux->rented_transport.rented_transport_code);
              strcpy((*user_details)->rented_transport.rented_transport_type, aux->rented_transport.rented_transport_type);
              (*user_details)->rented_transport.rented_at = aux->rented_transport.rented_at;
              strcpy((*user_details)->rented_transport.uuid, aux->rented_transport.uuid);
              (*user_details)->personal_data.dob.day = aux->personal_data.dob.day;
              (*user_details)->personal_data.dob.month = aux->personal_data.dob.month;
              (*user_details)->personal_data.dob.year = aux->personal_data.dob.year;

              return 1;
          }

          
        aux = aux->next_node;
    }

    press_to_continue();*/

    return 1;
}