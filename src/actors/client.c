#include "../include/header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int createTransportFile(Transport **transports)
{
    FILE *file = fopen("./data/transport.txt", "w");

    if (file == NULL)
    {
        printf("Error creating file");
        return 1;
    }

    // uuid;type_name;position;battery;state;price_base;price_per_minute
    fwrite("e8f3f3d1-12bf-47a3-8d2c-bbe50d09731e;Scooter;///sulkily.choirs.lorry;87.6;1;1.00;0.20\n", sizeof(char), strlen("e8f3f3d1-12bf-47a3-8d2c-bbe50d09731e;Scooter;///sulkily.choirs.lorry;87.6;1;1.00;0.20\n"), file);
    fwrite("6c5e9fb5-5b5f-4d01-97c2-37e4c8b1d0ad;Electric Bike;///stubbornly.revalue.secreted;68.9;0;0.80;0.25\n", sizeof(char), strlen("6c5e9fb5-5b5f-4d01-97c2-37e4c8b1d0ad;Electric Bike;///stubbornly.revalue.secreted;68.9;0;0.80;0.25\n"), file);
    fwrite("3a22c1e9-1a54-4c8b-a2d2-8684a4c99727;Skateboard;///vampires.dials.cancels;92.1;1;0.60;0.10\n", sizeof(char), strlen("3a22c1e9-1a54-4c8b-a2d2-8684a4c99727;Skateboard;///vampires.dials.cancels;92.1;1;0.60;0.10\n"), file);
    fwrite("bfe13e61-3b3f-49ee-9bfe-537b22e09dc8;Electric Scooter;///sulkily.choirs.lorry;49.2;0;1.20;0.30\n", sizeof(char), strlen("bfe13e61-3b3f-49ee-9bfe-537b22e09dc8;Electric Scooter;///sulkily.choirs.lorry;49.2;0;1.20;0.30\n"), file);
    fclose(file);

    return 0;
}

int client_main(Aux_User **user_details)
{

    Aux_User *user = *user_details;
    Transport *transports = NULL;

    free(*user_details);

    if (loadTransport(&transports) == 0)
    {
    }

    return 0;
}