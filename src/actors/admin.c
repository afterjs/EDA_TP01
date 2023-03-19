#include "../include/header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * @brief Update information of a Transport
 * This function updates information of a Transport, such as name, price per minute,
 * and base price. The user is prompted to enter the transport's code, and if it's found,
 * the transport's current information is displayed, and the user can choose which
 * information to update.
 * 
 * @param transports a pointer to the linked list of Transports
 * @see transportManagementMenu()
 * @see ask_for_update()
 * @see press_to_continue()
 * @see cls()
 * @see flushstdin()
 * @return int 0 if the operation was successful
 */
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
    printf("\n\tAvailable: %d🟢", aux->state);
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
    free(aux2);
    press_to_continue();
    transportManagementMenu(transports);
}

/**
 * @brief Removes a transport record from a file based on its code.
 *
 * This function removes a transport record from a file named "transport.txt"
 * located in the "./data/" directory, based on its code (a string). It creates a
 * temporary file named "temp.txt" to write the contents of the original file
 * minus the record to delete. It then deletes the original file and renames
 * the temporary file to the original file's name.
 * @param codeToDelete The code of the transport record to delete (a string).
 * @return Returns 1 if the record was successfully removed, 0 otherwise.
 */
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

/**
 * @brief Deletes a transport record from a linked list and a file.
 *
 * This function allows the user to delete a transport record from a linked list
 * of transport records and from a file named "transport.txt" located in the
 * "./data/" directory. The user must enter the code of the transport record to
 * delete. If the record is found in the linked list, it is removed from the
 * linked list and from the file. If the record is not found, the user is
 * informed and returned to the transport management menu.
 *
 * @param transports A pointer to a pointer to the first node of the linked list
 * of transport records.
 * @return void
 */
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

/**
 * @brief Adds a new transport to the system.
 * 
 * @param transports pointer to the linked list of transports
 * @return int 1 if the transport was added successfully, 0 otherwise.
 */
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

/**
 * \brief Lists all vehicles in the system
 *
 * This function prints information about all the vehicles currently registered
 * in the system, including their UUID, code, type name, price per minute, price
 * base, battery level, availability status, and position. It also prompts the
 * user to press a key to continue and returns to the transport management menu.
 *
 * \param transports A pointer to a pointer to the head of the linked list of
 *                   Transport objects in the system
 *
 * \return This function does not return a value
 */
int listAllVehicles(Transport **transports)
{
    cls();
    Transport *aux = *transports;

    while (aux != NULL)
    {
        printf("\tUUID: %s ", aux->uuid);
        printf("\n\tCode: %s 🆔", aux->code);
        printf("\n\tName: %s🏷️", aux->type_name);
        printf("\n\tPrice per minute: %.2f€⌚", aux->price.price_per_minute);
        printf("\n\tPrice base: %.2f€⌚", aux->price.price_base);
        printf("\n\tBattery: %.2f%%⚡", aux->battery);
        printf("\n\tAvailable: %d🟢", aux->state);
        printf("\n\tPosition: %s📍\n\n", aux->position);
        aux = aux->next_node;
    }

    press_to_continue();

    transportManagementMenu(transports);
}

/**
 * @brief Displays the transport management menu with options to add, update, delete, and list all transports.
 * 
 * @param transport Pointer to the pointer of the first element in the transport linked list.
 * @return int Returns 1 upon completion of the function.
 */
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
        listAllVehicles(transport);
        break;
    case 5:
        return 1;
    }
    return 1;
}

/**
 * Deletes the admin account
 *
 * This function asks the user if they want to delete their account.
 * If the user confirms it, the account is deleted and the function returns 1.
 * If the user cancels, the function returns 0.
 *
 * @param user Pointer to the pointer of the admin account to be deleted
 * @param users Pointer to the pointer of the list of users
 *
 * @return Returns 1 if the account was successfully deleted or 0 if it was not deleted
 */
int deleteAdminAccount(Aux_User **user, User **users)
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
            removeUserFromFile(*user);
            press_to_continue();
            free(*user);
            main();
        }
        else
        {
            cls();
            printf("\tYou're misspelling.\n\tAre you sure you really want to delete the account?");
            press_to_continue();
            deleteAdminAccount(user, users);
        }
    }
    else
    {
        userManagementMenu(users, user);
    }
}

/**
 * @brief List all users registered in the system
 * 
 * @param users Pointer to the linked list of users
 * @param user_details Pointer to the user details structure
 * @return int Returns 1 after displaying the list and returning to user management menu
 */
int listAllUsers(User **users, Aux_User **user_details)
{

    cls();
    User *aux = *users;

    printf("\tList of users: \n\n");

    while (aux != NULL)
    {

        printf("UUID: %s \U0001F510", aux->uuid);
        printf("\nUser type: %d \U0001F3E2", aux->user_type);
        printf("\nName: %s \U0001F464", aux->personal_data.name);
        printf("\nNIF: %d \U0001F4C3", aux->personal_data.nif);
        printf("\nDate of birth: %d/%d/%d \U0001F4C5", aux->personal_data.dob.day, aux->personal_data.dob.month, aux->personal_data.dob.year);
        printf("\nEmail: %s \U0001F4E7", aux->personal_data.login.email);
        printf("\nPassword: %s \U0001F510", aux->personal_data.login.password);
        printf("\nPhone number: %s \U0001F4DE", aux->personal_data.phone_number);
        printf("\nBalance: %.2f \U0001F4B5", aux->personal_data.balance);
        printf("\nStreet: %s \U0001F3E0", aux->personal_data.address.street);
        printf("\nCity: %s \U0001F306", aux->personal_data.address.city);
        printf("\nCountry: %s \U0001F30D", aux->personal_data.address.country);
        printf("\nPostal code: %s \U0001F4E6\n\n", aux->personal_data.address.postal_code);

        aux = aux->next_node;
    }

    press_to_continue();
    userManagementMenu(users, user_details);
}

/**
 * @brief Allows an administrator to update the account details of a user.
 * 
 * The function asks the administrator which information they want to update (username, password, and/or date of birth)
 * and then calls the appropriate function to update the information. After that, the function updates the information 
 * of the user in the file and displays a success message.
 * 
 * @param users A pointer to the linked list of users.
 * @param user_details A pointer to the structure that holds the user details.
 * 
 * @see ask_for_update()
 * @see update_info()
 * @see updateUserAtFile()
 * @see press_to_continue()
 * @see userManagementMenu()
 */
int updateAccountAdminDetails(User **users, Aux_User **user_details)
{

    if (ask_for_update("username"))
    {
        update_info("username", *user_details);
    }
    if (ask_for_update("password"))
    {
        update_info("password", *user_details);
    }
    if (ask_for_update("dob"))
    {
        update_info("dob", *user_details);
    }

    cls();
    printf("\tUpdating informations\n\n");
    printf("\tAccount details updated with success!\n");

    updateUserAtFile(*user_details);

    press_to_continue();

    userManagementMenu(users, user_details);
}

/**
 * @brief Displays the User Management Menu and handles the options
 * 
 * @param users Pointer to the array of User pointers
 * @param user_details Pointer to the array of Aux_User pointers
 * @return int 1 if the user selects the "Back" option, 0 otherwise
 * 
 * @see getUserDetails()
 * @see saveUserAtFile()
 * @see updateAccountAdminDetails()
 * @see deleteAdminAccount()
 * @see listAllUsers()
 */
int userManagementMenu(User **users, Aux_User **user_details)
{
    cls();
    int option = 1;

    do
    {
        if (option < 1 || option > 5)
        {
            cls();
            printf("Invalid option! Try again!\n");
            return 0;
        }
        printf("\tUser Management Menu\n\n");

        printf("\t1 - Add new admin");
        printf("\n\t2 - Update details");
        printf("\n\t3 - Delete Account");
        printf("\n\t4 - List all users");
        printf("\n\t5 - Back");
        printf("\n\n\tChoose an option: ");
        scanf("%d", &option);
    } while (option < 1 || option > 5);

    switch (option)
    {
    case 1:
        Aux_User *aux = malloc(sizeof(Aux_User));
        aux = getUserDetails(*users, 1);
        saveUserAtFile(aux);
        free(aux);
        cls();
        printf("\tUser Registration with success!\n\n");
        press_to_continue();
        userManagementMenu(users, user_details);
        break;
    case 2:
        updateAccountAdminDetails(users, user_details);
        break;
    case 3:
        deleteAdminAccount(user_details, users);
        break;
    case 4:
        listAllUsers(users, user_details);
        break;
    case 5:
        return 1;
    }
    return 1;
}

/**
 * @brief Displays the admin menu with options to manage transports, users, and logout.
 * 
 * @param users A pointer to an array of User structs.
 * @param user_details A pointer to an array of Aux_User structs.
 * @param transports A pointer to an array of Transport structs.
 * 
 * @see transportManagementMenu()
 * @see userManagementMenu()
 * @see cls()
 * @see press_to_continue()
 * @see main()
 */
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
            userManagementMenu(users, user_details);
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

/**
 * @brief Main function for the administrator menu.
 *
 * @param users a pointer to a pointer to the list of users.
 * @param user_details a pointer to a pointer to the auxiliary user details.
 * @return int returns 1.
 *
 * This function loads the list of transports from the file and displays the administrator menu. The administrator menu provides the following options:
 * - Transport management
 * - User management
 * - Logout
 *
 * The user can choose an option by entering a number. Invalid options will be rejected and the user will be prompted to try again. After selecting an option, the corresponding submenu will be displayed.
 *
 * @see loadTransport()
 * @see showAdminMenu()
 * @see transportManagementMenu()
 * @see userManagementMenu()
 */
int admin_main(User **users, Aux_User **user_details)
{

    Transport *transports = NULL;

    if (loadTransport(&transports))
    {
        showAdminMenu(users, user_details, &transports);
        return 1;
    }
}