#include "../include/header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int updateTransport(Transport **transports)
{

    cls();
    char code[7];
    char awnser[60];
    char position[48];
    char found = 0;
    float price_aux = 0.00;

    printf("\tUpdate Transport\n\n");
    printf("\tEnter the transport code: ");
    flushstdin();
    scanf("%[^;\n]", code);

    Transport *aux = *transports;
    Aux_Transport *aux2 = NULL;

    while (aux != NULL)
    {
        if (strcmp(aux->code, code) == 0)
        {
            found = 1;
            break;
            ;
        }
        aux = aux->next_node;
    }

    if (found == 0)
    {
        cls();
        printf("\tTransport not found\n\n");
        press_to_continue();
        transportManagementMenu(transports);
    }

    cls();

    printf("\t🛹Vehicle Information🛹");

    printf("\n\n\tCode: %s 🆔", aux->code);
    printf("\n\tName: %s🏷️", aux->type_name);
    printf("\n\tPrice per minute: %.2f€⌚", aux->price.price_per_minute);
    printf("\n\tPrice base: %.2f€⌚", aux->price.price_base);
    printf("\n\tBattery: %.2f%%⚡", aux->battery);
    printf("\n\tAvailable: %s🟢", aux->state ? "Yes" : "No");
    printf("\n\tPosition: %s📍\n\n", aux->position);

    press_to_continue();

    if (ask_for_update("name"))
    {
        cls();
        printf("\t🛹Vehicle Information🛹");

        printf("\n\n\tCode: %s 🆔", aux->code);
        printf("\n\tName: %s🏷️", aux->type_name);
        printf("\n\tPrice per minute: %.2f€⌚", aux->price.price_per_minute);
        printf("\n\tPrice base: %.2f€⌚", aux->price.price_base);
        printf("\n\tBattery: %.2f%%⚡", aux->battery);
        printf("\n\tAvailable: %s🟢", aux->state ? "Yes" : "No");
        printf("\n\tPosition: %s📍\n\n", aux->position);

        printf("\tEnter the new name: ");
        flushstdin();

        scanf("%[^;\n]", awnser);
        cls();
        printf("\tUpdate Transport\n\n");
        if (strcmp(awnser, aux->type_name) != 0)
        {

            strcpy(aux->type_name, awnser);
            printf("\tTransport name updated!");
            press_to_continue();
        }
        else
        {
            printf("\tYou cannot update the name with the same name!");
            press_to_continue();
        }
    }

    if (ask_for_update("price_minute"))
    {
        cls();
        printf("\t🛹Vehicle Information🛹");

        printf("\n\n\tCode: %s 🆔", aux->code);
        printf("\n\tName: %s🏷️", aux->type_name);
        printf("\n\tPrice per minute: %.2f€⌚", aux->price.price_per_minute);
        printf("\n\tPrice base: %.2f€⌚", aux->price.price_base);
        printf("\n\tBattery: %.2f%%⚡", aux->battery);
        printf("\n\tAvailable: %s🟢", aux->state ? "Yes" : "No");
        printf("\n\tPosition: %s📍\n\n", aux->position);

        printf("\tEnter the new price per minute: ");
        flushstdin();
        scanf("%f", &price_aux);
        cls();
        printf("\tUpdate Transport\n\n");
        if (price_aux < 0)
        {
            printf("\tYou cannot update the price per minute with a negative value!");
            press_to_continue();
        }
        else if (price_aux == aux->price.price_per_minute)
        {
            printf("\tYou cannot update the price per minute with the same value!");
            press_to_continue();
        }
        else
        {
            aux->price.price_per_minute = price_aux;
            printf("\tTransport price per minute updated!");
            press_to_continue();
        }
    }

    if (ask_for_update("price_base"))
    {
        cls();
        printf("\t🛹Vehicle Information🛹");

        printf("\n\n\tCode: %s 🆔", aux->code);
        printf("\n\tName: %s🏷️", aux->type_name);
        printf("\n\tPrice per minute: %.2f€⌚", aux->price.price_per_minute);
        printf("\n\tPrice base: %.2f€⌚", aux->price.price_base);
        printf("\n\tBattery: %.2f%%⚡", aux->battery);
        printf("\n\tAvailable: %s🟢", aux->state ? "Yes" : "No");
        printf("\n\tPosition: %s📍\n\n", aux->position);

        printf("\tEnter the new base price: ");
        flushstdin();
        scanf("%f", &price_aux);
        cls();
        printf("\tUpdate Transport\n\n");
        if (price_aux < 0)
        {
            printf("\tYou cannot update the base price with a negative value!");
            press_to_continue();
        }
        else if (price_aux == aux->price.price_base)
        {
            printf("\tYou cannot update the base price with the same value!");
            press_to_continue();
        }
        else
        {
            aux->price.price_base = price_aux;
            printf("\tTransport base price updated!");
            press_to_continue();
        }
    }

    if (ask_for_update("position"))
    {
        cls();
        printf("\t🛹Vehicle Information🛹");

        printf("\n\n\tCode: %s 🆔", aux->code);
        printf("\n\tName: %s🏷️", aux->type_name);
        printf("\n\tPrice per minute: %.2f€⌚", aux->price.price_per_minute);
        printf("\n\tPrice base: %.2f€⌚", aux->price.price_base);
        printf("\n\tBattery: %.2f%%⚡", aux->battery);
        printf("\n\tAvailable: %s🟢", aux->state ? "Yes" : "No");
        printf("\n\tPosition: %s📍\n\n", aux->position);

        printf("\tEnter the new position: ");
        flushstdin();
        scanf("%[^;\n]", position);
        cls();

        if (isValidLocation(position) == 1)
        {
            printf("\tUpdate Transport\n\n");
            if (strcmp(position, aux->position) != 0)
            {
                strcpy(aux->position, position);
                printf("\tTransport position updated!");
                press_to_continue();
            }
            else
            {
                printf("\tYou cannot update the position with the same position!");
                press_to_continue();
            }
        }
        else
        {
            printf("\tInvalid location!");
            press_to_continue();
        }
    }

    // new data to file

    printf("\n\tUUID: %s ", aux->uuid);
    printf("\n\tCode: %s 🆔", aux->code);
    printf("\n\tName: %s🏷️", aux->type_name);
    printf("\n\tPrice per minute: %.2f€⌚", aux->price.price_per_minute);
    printf("\n\tPrice base: %.2f€⌚", aux->price.price_base);
    printf("\n\tBattery: %.2f%%⚡", aux->battery);
    printf("\n\tAvailable: %d🟢", aux->state );
    printf("\n\tPosition: %s📍\n\n", aux->position);

    aux2 = malloc(sizeof(Transport));

    if (aux2 == NULL)
    {
        printf("Error allocating memory");
    }

    strcpy(aux2->uuid, aux->uuid);
    strcpy(aux2->code, aux->code);
    strcpy(aux2->type_name, aux->type_name);
    aux2->price.price_per_minute = aux->price.price_per_minute;
    aux2->price.price_base = aux->price.price_base;
    aux2->battery = aux->battery;
    aux2->state = aux->state;
    strcpy(aux2->position, aux->position);

    updateTransportAtFile(aux2);
    press_to_continue();
    // transportManagementMenu(transports);
}

int removeTransportFromFile(char *codeToDelete)
{
    FILE *fp, *temp;
    Transport *aux = NULL;
    int found = 0;

    fp = fopen("./data/transport.txt", "r");
    temp = fopen("./data/temp.txt", "w");

    if (fp == NULL || temp == NULL)
    {
        printf("Error opening file\n");
        return 0;
    }

    char line[256];

    while (fgets(line, sizeof(line), fp))
    {
        if (strstr(line, codeToDelete) == NULL)
        {
            fprintf(temp, "%s", line);
        }
        else
        {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    if (!found)
    {
        printf("Code not found\n");
        remove("./data/temp.txt");
        return 0;
    }

    remove("./data/transport.txt");
    rename("./data/temp.txt", "./data/transport.txt");

    return 1;
}

int deleteTransport(Transport **transports)
{

    char code[50];
    int found = 0;
    cls();

    printf("\tDelete Transport\n\n");
    printf("\tEnter the transport code: ");
    scanf("%s", code);

    Transport *aux = *transports;

    while (aux != NULL)
    {
        if (strcmp(aux->code, code) == 0)
        {
            found = 1;
            break;
        }
        aux = aux->next_node;
    }

    if (found == 0)
    {
        cls();
        printf("\tTransport not found\n\n");
        press_to_continue();
        transportManagementMenu(transports);
    }

    removeTransportFromFile(code);
    *transports = removeTransport(*transports, code);

    cls();

    printf("\tTransport [%s] with code [%s] was deleted successfully", aux->type_name, aux->code);

    press_to_continue();

    transportManagementMenu(transports);
}

int addNewTransport(Transport **transports)
{

    Aux_Transport *aux_transport = malloc(sizeof(Aux_Transport));
    float battery = 1.00;
    char position[50];
    int validPosition = 1;

    cls();
    flushstdin();
    printf("\tTransport Registration\n\n");
    printf("\tEnter the transport name: ");
    scanf("%[^;\n]", aux_transport->type_name);
    flushstdin();

    do
    {
        if (battery < 0 || battery > 100)
        {
            cls();
            printf("\tInvalid battery, try again (Max - 100.00)\n\n");
        }

        printf("\n\tEnter the transport battery: ");
        scanf("%f", &battery);
    } while (battery < 0 || battery > 100);
    aux_transport->battery = battery;
    cls();
    printf("\tTransport Registration\n\n");
    printf("\tEnter the transport name: %s", aux_transport->type_name);
    printf("\n\tEnter the transport battery: %.2f", aux_transport->battery);

    do
    {
        if (validPosition == 0)
        {
            cls();
            printf("\n\tInvalid position, try again (Format ///xxx.yyy.zzz)\n\n");
        }

        printf("\n\tEnter the transport position: ");
        flushstdin();
        scanf("%[^;\n]", position);
        validPosition = isValidLocation(position);
    } while (validPosition == 0);
    cls();
    printf("\tTransport Registration\n\n");
    printf("\tEnter the transport name: %s", aux_transport->type_name);
    printf("\n\tEnter the transport battery: %.2f", aux_transport->battery);
    printf("\n\tEnter the transport position: %s", position);

    strcpy(aux_transport->position, position);

    printf("\n\tEnter the transport price base (Ex: 0.20): ");
    flushstdin();
    scanf("%f", &aux_transport->price.price_base);
    printf("\n\tEnter the transport price per minute (Ex: 0.40): ");
    flushstdin();
    scanf("%f", &aux_transport->price.price_per_minute);

    strcpy(aux_transport->uuid, gen_uuid());

    aux_transport->state = 0;

    srand(time(NULL));
    strcpy(aux_transport->code, generate_code());

    cls();

    printf("\tTransport Registration with success!\n\n");

    printf("\tUUID -> %s", aux_transport->uuid);
    printf("\n\tCode -> %s", aux_transport->code);
    printf("\n\tType -> %s", aux_transport->type_name);
    printf("\n\tPosition -> %s", aux_transport->position);
    printf("\n\tBattery -> %.2f", aux_transport->battery);
    printf("\n\tState -> %d", aux_transport->state);
    printf("\n\tPrice Base -> %.2f", aux_transport->price.price_base);
    printf("\n\tPrice per minute -> %.2f", aux_transport->price.price_per_minute);

    saveTransportAtFile(aux_transport);
    *transports = insertTransport(*transports, aux_transport);
    free(aux_transport);
    press_to_continue();
    transportManagementMenu(transports);
}

int transportManagementMenu(Transport **transport)
{

    int option = 1;
    cls();

    do
    {
        if (option < 1 || option > 5)
        {
            cls();
            printf("Invalid option! Try again!\n");
            return 0;
        }

        printf("\n\n\t1 - Add new transport");
        printf("\n\t2 - Update transport");
        printf("\n\t3 - Delete transport");
        printf("\n\t4 - List all transports");
        printf("\n\t5 - Back");
        printf("\n\n\tChoose an option: ");
        scanf("%d", &option);
    } while (option < 1 || option > 5);

    switch (option)
    {
    case 1:
        addNewTransport(transport);
        break;
    case 2:
        updateTransport(transport);
        break;
    case 3:
        deleteTransport(transport);
        break;
    case 4:

        break;
    case 5:
        return 1;
    }
    return 1;
}

void showAdminMenu(User **users, Aux_User **user_details, Transport **transports)
{
    int option = 1;

    while (1)
    {

        do
        {
            cls();
            if (option < 1 || option > 3)
            {
                cls();
                printf("Invalid option, try again\n\n");
                press_to_continue();
            }
            printf("\n\tHello *%s*. Welcome to GoSmartCity\n", (*user_details)->personal_data.name);
            printf("\n\t 1 - Transport Management.");
            printf("\n\t 2 - Users Management.");
            printf("\n\t 3 - Logout.");
            printf("\n\tChoose an option: ");
            scanf("%d", &option);

        } while (option < 1 || option > 3);

        switch (option)
        {
        case 1:
            transportManagementMenu(transports);
            break;
        case 2:

            break;
        case 3:

            free(*users);
            free(*user_details);
            free(*transports);
            main();
            break;
        }
    }
}

int admin_main(User **users, Aux_User **user_details)
{

    Transport *transports = NULL;

    if (loadTransport(&transports))
    {
        showAdminMenu(users, user_details, &transports);
        return 1;
    }
}