#include "./include/header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



void login()

{
    char email[15];
    char password[15];

    printf("Enter your email: ");
    do
    {
        scanf("%s", email);
        if (checkEmail(email) == 0)
        {
            printf("Invalid email, try again: ");
        }
    } while (checkEmail(email) == 0);

    printf("Enter your password: ");
    scanf("%s", password);

    encrypt(password);
}

void createUsersFile(User **users)
{

    FILE *fp;
    fp = fopen("./data/users.bin", "wb");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    Aux_User *client = malloc(sizeof(Aux_User));
    Aux_User *admin = malloc(sizeof(Aux_User));



    strcpy(client->uuid, gen_uuid());
    client->user_type = 0;
    strcpy(client->personal_data.name, "a");
    client->personal_data.nif = 123456789;
    strcpy(client->personal_data.email, "xavieramaro2@gmail.com");
    strcpy(client->personal_data.phone_number, "912345678");
    client->personal_data.balance = 133.12;
    strcpy(client->personal_data.address.street, "rua");
    strcpy(client->personal_data.address.city, "cidade");
    strcpy(client->personal_data.address.country, "pais");
    strcpy(client->personal_data.address.postal_code, "1234-123");

    strcpy(admin->uuid, gen_uuid());
    admin->user_type = 1;
    strcpy(admin->personal_data.name, "amaro");
    admin->personal_data.nif = 934567890;
    strcpy(admin->personal_data.email, "ricardo@gmail.com");
    strcpy(admin->personal_data.phone_number, "927617597");
    admin->personal_data.balance = 0.00;
    strcpy(admin->personal_data.address.street, "boulevard");
    strcpy(admin->personal_data.address.city, "barcelona");
    strcpy(admin->personal_data.address.country, "spain");
    strcpy(admin->personal_data.address.postal_code, "4925-366");

    fwrite(client, sizeof(Aux_User), 1, fp);
    fseek(fp, 0, SEEK_END);
    fwrite(admin, sizeof(Aux_User), 1, fp);

    free(client);
    free(admin);

    fclose(fp);

    load_users(users);
}

int load_users(User **users)
{

    if (existFile("./data/users.bin", "rb") == 0)
    {
        printf("Creating users file..");
        createUsersFile(users);
        return 0;
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

        *users = insertUser(*users, aux);
    }

    free(aux);

    fclose(fp);
    return 1;
}
