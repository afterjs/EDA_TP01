#include "../include/header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int showAllTransportInPosition(Transport **transport)
{

    char location[50];
    int exist = 0;
    int isValid = 1;
    Transport *aux = *transport;

    do
    {
        cls();
        if (isValid == 0)
        {
            printf("\tInvalid location!\n\n");
        }
        printf("\tEnter the location: ");
        scanf("%s", location);
        isValid = isValidLocation(location);
    } while (isValid == 0);

    while (aux != NULL)
    {
        if (strcmp(location, aux->position) == 0)
        {
            exist = 1;
            break;
        }
        aux = aux->next_node;
    }

    cls();

    if (exist == 0)
    {
        printf("\tThere are no transports in this location!\n");
        press_to_continue();
        return 0;
    }

    printf("\tTransports in %s:\n\n", location);

    while (aux != NULL)
    {
        if (strcmp(location, aux->position) == 0)
        {
            printf("\n\tUUID: %s", aux->uuid);
            printf("\n\tCode: %s", aux->code);
            printf("\n\tType Name: %s", aux->type_name);
            printf("\n\tBattery: %.2f", aux->battery);
            printf("\n\tState: %s", (aux->state == 0 ? "Available" : "Rented"));
            printf("\n\tPrice Base: %.2f", aux->price.price_base);
            printf("\n\tPrice Per Minute: %.2f\n\n", aux->price.price_per_minute);
        }
        aux = aux->next_node;
    }

    press_to_continue();

    return 1;
}

int showAllTransportByBattery(Transport **transport)
{

    cls();
    int count = 0;
    Transport *current = *transport;
    while (current != NULL)
    {
        count++;
        current = current->next_node;
    }

    Transport **aux = malloc(count * sizeof(Transport *));
    if (aux == NULL)
    {
        return 0;
    }

    current = *transport;
    int i = 0;
    while (current != NULL)
    {
        aux[i] = current;
        i++;
        current = current->next_node;
    }

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (aux[j]->battery < aux[j + 1]->battery)
            {
                Transport *temp = aux[j];
                aux[j] = aux[j + 1];
                aux[j + 1] = temp;
            }
        }
    }

    printf("\tTransports sorted by battery:\n\n");
    for (int i = 0; i < count; i++)
    {
        printf("\n\tUUID: %s", aux[i]->uuid);
        printf("\n\tCode: %s", aux[i]->code);
        printf("\n\tType Name: %s", aux[i]->type_name);
        printf("\n\tPosition: %s", aux[i]->position);
        printf("\n\tBattery: %.2f", aux[i]->battery);
        printf("\n\tState: %s", (aux[i]->state == 0 ? "Available" : "Rented"));
        printf("\n\tPrice Base: %.2f", aux[i]->price.price_base);
        printf("\n\tPrice Per Minute: %.2f\n\n", aux[i]->price.price_per_minute);
    }

    free(aux);

    press_to_continue();
    return 1;
}

int deleteAccount(Aux_User *user)
{

    int option = 1;
    cls();

    do
    {
        if (option < 1 || option > 2)
        {
            cls();
            printf("Invalid option! Try again!\n");
            return 0;
        }

        printf("\t[DANGER ZONE] Do you want to delete your account?");
        printf("\n\tRemember that this option will be irreversible!!!");

        printf("\n\n\t1 - DELETE ACCOUNT");
        printf("\n\t2 - Back");
        printf("\n\n\tChoose an option: ");
        scanf("%d", &option);

    } while (option < 1 || option > 2);

    if (option == 1)
    {
        char confirm[50];

        cls();

        printf("\tTo permanently delete the account, write "
               "DELETE"
               ": ");
        scanf("%s", confirm);

        if (strcmp(confirm, "DELETE") == 0)
        {
            cls();
            printf("\n\tAccount deleted with success! We hope you come back 😔");
            removeUserFromFile(user);
            press_to_continue();
            free(user);
            main();
        }
        else
        {
            cls();
            printf("\tYou're misspelling.\n\tAre you sure you really want to delete the account?");
            press_to_continue();
            deleteAccount(user);
        }
    }
    else
    {
        showAccountDetails(user);
    }
}

int depositMoney(Aux_User *user)
{

    float amount = 0.00;

    do
    {
        cls();

        printf("\tGoSmartCity [Balance %.2f€]", user->personal_data.balance);

        if (amount < 0 || amount > 50)
        {
            printf("\n\tInvalid amount of money. (Max - 50€)");
        }
        printf("\n\n\tWhat amount of money do you want to deposit? (Max - 50€): ");
        scanf("%f", &amount);
    } while (amount < 0 || amount > 50);

    cls();
    user->personal_data.balance += amount;
    updateUserAtFile(user);

    printf("\tGoSmartCity [Balance %.2f€]", user->personal_data.balance);
    printf("\n\n\tAmount deposited with success!");
    printf("\n\tBalance: %.2f", user->personal_data.balance);
    press_to_continue();

    return 1;
}

int ask_for_update(char *info)
{

    int choice = 1;

    do
    {
        cls();
        printf("\n\tUpdating informations\n");

        if (choice != 1 && choice != 2)
        {
            printf("\tInvalid option, please try again\n");
        }

        if (strcmp(info, "dob") != 0)
        {
            printf("\n\tDo you want to update %s? (yes - 1 / No - 2): ", info);
        }
        else
        {
            printf("\n\tDo you want to update your date of birth? (yes - 1 / No - 2): ");
        }
        scanf("%d", &choice);
    } while (choice != 1 && choice != 2);

    if (choice == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void update_info(char *info, Aux_User *user)
{
    cls();
    printf("\tUpdating informations\n\n");

    char choice[50];
    if (strcmp(info, "username") == 0)
    {

        printf("\tEnter new username: ");
        flushstdin();
        scanf("%[^;\n]", choice);

        cls();
        printf("\tUpdating informations\n\n");

        if (strcmp(choice, user->personal_data.name) == 0)
        {
            printf("\tUsername is the same as the old one");
            press_to_continue();
        }
        else
        {
            printf("\tUsername was updated with success");
            strcpy(user->personal_data.name, choice);
            press_to_continue();
        }
    }
    else if (strcmp(info, "password") == 0)
    {

        printf("\tEnter new password: ");
        flushstdin();
        scanf("%[^;\n]", choice);

        char *encryptedPassword = encrypt(choice);
        cls();
        printf("\tUpdating informations\n\n");
        if (strcmp(encryptedPassword, user->personal_data.login.password) == 0)
        {
            printf("\tPassword is the same as the old one");
            press_to_continue();
        }
        else
        {
            printf("\tPassword was updated with success");
            strcpy(user->personal_data.login.password, encryptedPassword);
            press_to_continue();
        }
    }
    else if (strcmp(info, "dob") == 0)
    {
        int day, month, year;
        char dob_struct[20];
        char dob[20];

        printf("\tEnter your date of birth (dd/mm/yyyy): ");
        flushstdin();
        scanf("%d/%d/%d", &day, &month, &year);

        cls();
        printf("\tUpdating informations\n\n");

        if (getAge(day, month, year) < 18)
        {

            cls();
            printf("\tOops, seems like you don't have more than 18 years");
            press_to_continue();
        }
        else
        {

            sprintf(dob_struct, "%d/%d/%d", user->personal_data.dob.day, user->personal_data.dob.month, user->personal_data.dob.year);
            sprintf(dob, "%d/%d/%d", day, month, year);

            if (strcmp(dob_struct, dob) == 0)
            {
                printf("\tDate of birthday is the same as the old one");
                press_to_continue();
            }
            else
            {
                printf("\tDate of birthday was updated with success");
                user->personal_data.dob.day = day;
                user->personal_data.dob.month = month;
                user->personal_data.dob.year = year;
                press_to_continue();
            }
        }
    }
}

int updateAccountDetails(Aux_User *user)
{

    if (ask_for_update("username"))
    {
        update_info("username", user);
    }
    if (ask_for_update("password"))
    {
        update_info("password", user);
    }
    if (ask_for_update("dob"))
    {
        update_info("dob", user);
    }

    cls();
    printf("\tUpdating informations\n\n");
    printf("\tAccount details updated with success!\n");

    updateUserAtFile(user);

    press_to_continue();

    showAccountDetails(user);
}

int printUserDetails(Aux_User *user)
{

    cls();

    printf("\t*GoSmartCity*\n");

    printf("\n\tAuthentication details\n");
    printf("\n\tEmail: %s", user->personal_data.login.email);
    printf("\n\tNIF: %d", user->personal_data.nif);
    printf("\n\tPhone number: %s", user->personal_data.phone_number);

    printf("\n\n\tPersonal details\n");
    printf("\n\tName: %s", user->personal_data.name);
    printf("\n\tDate of birth: %d/%d/%d", user->personal_data.dob.day, user->personal_data.dob.month, user->personal_data.dob.year);
    printf("\n\tAddress: %s, %s, %s, %s", user->personal_data.address.street, user->personal_data.address.city, user->personal_data.address.country, user->personal_data.address.postal_code);
    printf("\n\tBalance: %.2f€", user->personal_data.balance);

    press_to_continue();

    showAccountDetails(user);

    return 1;
}

int showAccountDetails(Aux_User *user)
{

    int option = 1;
    cls();

    do
    {
        if (option < 1 || option > 4)
        {
            cls();
            printf("Invalid option! Try again!\n");
            return 0;
        }

        printf("\tGoSmartCity [Balance %.2f€]", user->personal_data.balance);
        printf("\n\n\t1 - Show account details");
        printf("\n\t2 - Update account details");
        printf("\n\t3 - Deposit money to account");
        printf("\n\t4 - Delete Account");
        printf("\n\t4 - Back");
        printf("\n\n\tChoose an option: ");
        scanf("%d", &option);
    } while (option < 1 || option > 4);

    switch (option)
    {
    case 1:
        printUserDetails(user);
        break;
    case 2:
        updateAccountDetails(user);
        break;

    case 3:
        depositMoney(user);
        break;
    case 4:

        if (user->personal_data.balance < 0)
        {
            printf("You can't delete your account because you have a negative balance!");
            press_to_continue();
            showAccountDetails(user);
        }
        else
        {
            deleteAccount(user);
        }
        return 1;
    }
    return 1;
}

int finishRent(Aux_User *user, Transport **transport, time_t *stop_time)
{

    cls();
    float time_in_minutes = difftime(*stop_time, user->rented_transport.rented_at) / 60;

    Transport *aux = *transport;

    while (aux != NULL)
    {
        if (strcmp(aux->uuid, user->rented_transport.uuid) == 0)
        {
            aux->state = 0;
            break;
        }
        aux = aux->next_node;
    }

    float price;
    float battery = time_in_minutes * 0.4;

    price = (time_in_minutes * aux->price.price_per_minute) + aux->price.price_base;
    printf("\t*GoSmartCity*\n");

    printf("\n\tRented at: %s", timestamp_to_text(user->rented_transport.rented_at));
    printf("\n\tReturned at: %s", timestamp_to_text(*stop_time));
    printf("\n\tRented transport: %s", user->rented_transport.rented_transport_type);
    printf("\n\tBattery used: %.2f%%\n", battery);

    if (time_in_minutes < 1)
    {
        printf("\n\tThis ride cost %.2f€ (Time: %d seconds)", price, (int)(time_in_minutes / 60));
    }
    else
    {
        printf("\n\tThis ride cost %.2f€ (Time: %.2f minutes)", price, time_in_minutes);
    }

    if (price > user->personal_data.balance)
    {
        printf("\nYou don't have enough balance to finish the rent!Your account balance will be negative!");
        printf("\nYour account balance is less than the price to pay!. Plz, add money to your account!");
        user->personal_data.balance -= price;
    }
    else
    {
        printf("\n\tPayment successful! You have %.2f€ left in your balance!", user->personal_data.balance - price);
        user->personal_data.balance -= price;
    }

    while ((*transport) != NULL)
    {
        if (strcmp((*transport)->uuid, aux->uuid) == 0)
        {
            (*transport)->state = 0;
            (*transport)->battery -= battery;
            break;
        }
        (*transport) = (*transport)->next_node;
    }

    strcpy(user->rented_transport.uuid, "");
    strcpy(user->rented_transport.rented_transport_code, "XXX000");
    strcpy(user->rented_transport.rented_transport_type, "XXX000");
    user->rented_transport.rented_at = 0;

    aux->state = 0;

    Aux_Transport *aux_transport = malloc(sizeof(Aux_Transport));

    aux_transport->battery = aux->battery - battery;
    aux_transport->price.price_base = aux->price.price_base;
    aux_transport->price.price_per_minute = aux->price.price_per_minute;
    aux_transport->state = aux->state;
    strcpy(aux_transport->type_name, aux->type_name);
    strcpy(aux_transport->uuid, aux->uuid);
    strcpy(aux_transport->position, aux->position);
    strcpy(aux_transport->code, aux->code);

    updateUserAtFile(user);
    updateTransportAtFile(aux_transport);

    free(aux_transport);
    press_to_continue();

    return 1;
}

int rentTransport(Aux_User *user, Transport **transport)
{
    cls();

    if (user->personal_data.balance < 2.00)
    {
        printf("You don't have enough balance to rent a transport! (Minimum balance: 2.00)");
        printf("\nBalance: %.2f€", user->personal_data.balance);
        press_to_continue();
        return 0;
    }

    char transport_code[15];

    printf("Enter the transport code: ");
    scanf("%s", transport_code);

    Transport *aux = checkTransportAvailable(*transport, transport_code);

    if (aux == NULL)
    {
        printf("Transport not found!");
        press_to_continue();
        return 0;
    }

    if (aux->state == 1)
    {
        printf("Transport not available!");
        press_to_continue();
        return 0;
    }

    if (aux->battery < 10)
    {
        printf("Transport with low battery!");
        press_to_continue();
        return 0;
    }

    int option = 1;

    do
    {

        cls();

        if (option != 1 && option != 2)
        {
            printf("\n\tInvalid option!\n\n");
        }

        printf("\t🛹Vehicle Information🛹");
        printf("\n\n\tPrice per minute: %.2f€⌚", aux->price.price_per_minute);
        printf("\n\tPrice base: %.2f€⌚", aux->price.price_base);
        printf("\n\tBattery: %.2f%%⚡", aux->battery);

        printf("\n\nDo you want to rent this transport?");
        printf("\n 1 - Yes");
        printf("\n 2 - No");
        printf("\nEnter your option: ");
        scanf("%d", &option);
    } while (option != 1 && option != 2);

    switch (option)
    {
    case 1:

        // change the transport state to 1

        strcpy(user->rented_transport.uuid, aux->uuid);
        strcpy(user->rented_transport.rented_transport_code, aux->code);
        strcpy(user->rented_transport.rented_transport_type, aux->type_name);
        user->rented_transport.rented_at = time(NULL);

        while ((*transport) != NULL)
        {
            if (strcmp((*transport)->uuid, aux->uuid) == 0)
            {
                (*transport)->state = 1;
                break;
            }
            (*transport) = (*transport)->next_node;
        }

        aux->state = 1;

        Aux_Transport *aux_transport = malloc(sizeof(Aux_Transport));

        aux_transport->battery = aux->battery;
        strcpy(aux_transport->code, aux->code);
        strcpy(aux_transport->position, aux->position);
        aux_transport->price.price_base = aux->price.price_base;
        aux_transport->price.price_per_minute = aux->price.price_per_minute;
        aux_transport->state = aux->state;
        strcpy(aux_transport->type_name, aux->type_name);
        strcpy(aux_transport->uuid, aux->uuid);

        updateUserAtFile(user);
        updateTransportAtFile(aux_transport);

        free(aux_transport);

        printf("\n\nYou rented a %s with code %s! Good ride!", aux->type_name, aux->code);
        break;
    case 2:
        printf("\n\tRent canceled!");
        break;
    }

    press_to_continue();

    return 1;
}

int createTransportFile()
{

    Aux_Transport *t1 = malloc(sizeof(Aux_Transport));
    Aux_Transport *t2 = malloc(sizeof(Aux_Transport));
    Aux_Transport *t3 = malloc(sizeof(Aux_Transport));
    Aux_Transport *t4 = malloc(sizeof(Aux_Transport));
    Aux_Transport *t5 = malloc(sizeof(Aux_Transport));
    Aux_Transport *t6 = malloc(sizeof(Aux_Transport));
    Aux_Transport *t7 = malloc(sizeof(Aux_Transport));

    strcpy(t1->uuid, "e8f3f3d1-12bf-47a3-8d2c-bbe50d09731e");
    strcpy(t1->type_name, "Scooter");
    strcpy(t1->code, "MTP412");
    strcpy(t1->position, "///sulkily.choirs.lorry");
    t1->battery = 87.6;
    t1->state = 1;
    t1->price.price_base = 1.00;
    t1->price.price_per_minute = 0.20;

    strcpy(t2->uuid, "6c5e9fb5-5b5f-4d01-97c2-37e4c8b1d0ad");
    strcpy(t2->type_name, "Electric Bike");
    strcpy(t2->code, "XMN123");
    strcpy(t2->position, "///stubbornly.revalue.secreted");
    t2->battery = 68.9;
    t2->state = 0;
    t2->price.price_base = 0.80;
    t2->price.price_per_minute = 0.25;

    strcpy(t3->uuid, "3a22c1e9-1a54-4c8b-a2d2-8684a4c99727");
    strcpy(t3->type_name, "Skateboard");
    strcpy(t3->code, "LEN321");
    strcpy(t3->position, "///vampires.dials.cancels");
    t3->battery = 92.1;
    t3->state = 1;
    t3->price.price_base = 0.60;
    t3->price.price_per_minute = 0.10;

    strcpy(t4->uuid, "bfe13e61-3b3f-49ee-9bfe-537b22e09dc8");
    strcpy(t4->type_name, "Electric Scooter");
    strcpy(t4->code, "FTN416");
    strcpy(t4->position, "///sulkily.choirs.lorry");
    t4->battery = 49.2;
    t4->state = 0;
    t4->price.price_base = 1.20;
    t4->price.price_per_minute = 0.30;

    strcpy(t5->uuid, "9e9e8a8c-2c56-46d5-a7c8-8106a4d8344b");
    strcpy(t5->type_name, "Electric Bike");
    strcpy(t5->code, "BCD789");
    strcpy(t5->position, "///sulkily.choirs.lorry");
    t5->battery = 78.3;
    t5->state = 1;
    t5->price.price_base = 0.75;
    t5->price.price_per_minute = 0.20;

    strcpy(t6->uuid, "e55fb7d4-06f7-4c37-aa12-347de8d11dbd");
    strcpy(t6->type_name, "Electric Scooter");
    strcpy(t6->code, "XYZ345");
    strcpy(t6->position, "///sulkily.choirs.lorry");
    t6->battery = 33.7;
    t6->state = 0;
    t6->price.price_base = 1.30;
    t6->price.price_per_minute = 0.35;

    strcpy(t7->uuid, "3a3d2a7f-b05e-481d-a3f3-98b0a9bb3445");
    strcpy(t7->type_name, "Skateboard");
    strcpy(t7->code, "JKL901");
    strcpy(t7->position, "///vampires.dials.cancels");
    t7->battery = 95.2;
    t7->state = 1;
    t7->price.price_base = 0.65;
    t7->price.price_per_minute = 0.15;

    saveTransportAtFile(t1);
    saveTransportAtFile(t2);
    saveTransportAtFile(t3);
    saveTransportAtFile(t4);
    saveTransportAtFile(t5);
    saveTransportAtFile(t6);
    saveTransportAtFile(t7);

    free(t1);
    free(t2);
    free(t3);
    free(t4);
    free(t5);
    free(t6);
    free(t7);

    return 0;
}

void showMenu(Aux_User *user, Transport **transports)

{
    int option = 1;

    while (1)
    {

        if (strcmp(user->rented_transport.rented_transport_code, "XXX000") == 0)
        {

            do
            {
                cls();
                if (option < 1 || option > 7)
                {
                    cls();
                    printf("Invalid option, try again\n\n");
                    press_to_continue();
                }
                printf("\n\tHello *%s*. Welcome to GoSmartCity\n", user->personal_data.name);
                printf("\n\t 1 - Rent a transport.");
                printf("\n\t 2 - Account Details.");
                printf("\n\t 3 - Show all transport by battery (DESC).");
                printf("\n\t 4 - Show all transport in certain position.");
                printf("\n\t 5 - Logout.");
                printf("\n\tChoose an option: ");
                scanf("%d", &option);

            } while (option < 1 || option > 7);

            switch (option)
            {
            case 1:
                rentTransport(user, transports);
                break;
            case 2:
                showAccountDetails(user);
                break;
            case 3:
                showAllTransportByBattery(transports);
                break;
            case 4:
                showAllTransportInPosition(transports);
                break;
            case 5:

                free(user);
                free(*transports);
                main();
                break;
            }
        }
        else
        {
            do
            {
                cls();
                if (option != 1 && option != 2)
                {
                    cls();
                    printf("Invalid option, try again\n\n");
                }

                printf("\n\tGoSmartCity\n");

                printf("\n\tYou are renting a %s[%s] from %s, do you wish to finish?", user->rented_transport.rented_transport_type, user->rented_transport.rented_transport_code, timestamp_to_text(user->rented_transport.rented_at));
                printf("\n\n\t 1 - Yes");
                printf("\n\t 2 - No");
                printf("\n\n\tChoose an option: ");
                scanf("%d", &option);
            } while (option != 1);

            time_t now = time(NULL);
            finishRent(user, transports, &now);
        }
    }

    // printf("\nTransport UUID %s", )
}

int client_main(Aux_User **user_details)
{

    Transport *transports = NULL;

    if (loadTransport(&transports))
    {
        showMenu(*user_details, &transports);
        return 1;
    }
}