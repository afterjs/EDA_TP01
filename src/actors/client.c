#include "../include/header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int createTransportFile()
{

    Aux_Transport *t1 = malloc(sizeof(Aux_Transport));
    Aux_Transport *t2 = malloc(sizeof(Aux_Transport));
    Aux_Transport *t3 = malloc(sizeof(Aux_Transport));
    Aux_Transport *t4 = malloc(sizeof(Aux_Transport));

    strcpy(t1->uuid, "e8f3f3d1-12bf-47a3-8d2c-bbe50d09731e");
    strcpy(t1->type_name, "Scooter");
    strcpy(t1->position, "///sulkily.choirs.lorry");
    t1->battery = 87.6;
    t1->state = 1;
    t1->price.price_base = 1.00;
    t1->price.price_per_minute = 0.20;

    strcpy(t2->uuid, "6c5e9fb5-5b5f-4d01-97c2-37e4c8b1d0ad");
    strcpy(t2->type_name, "Electric Bike");
    strcpy(t2->position, "///stubbornly.revalue.secreted");
    t2->battery = 68.9;
    t2->state = 0;
    t2->price.price_base = 0.80;
    t2->price.price_per_minute = 0.25;

    strcpy(t3->uuid, "3a22c1e9-1a54-4c8b-a2d2-8684a4c99727");
    strcpy(t3->type_name, "Skateboard");
    strcpy(t3->position, "///vampires.dials.cancels");
    t3->battery = 92.1;
    t3->state = 1;
    t3->price.price_base = 0.60;
    t3->price.price_per_minute = 0.10;

    strcpy(t4->uuid, "bfe13e61-3b3f-49ee-9bfe-537b22e09dc8");
    strcpy(t4->type_name, "Electric Scooter");
    strcpy(t4->position, "///sulkily.choirs.lorry");
    t4->battery = 49.2;
    t4->state = 0;
    t4->price.price_base = 1.20;
    t4->price.price_per_minute = 0.30;

    saveTransportAtFile(t1);
    saveTransportAtFile(t2);
    saveTransportAtFile(t3);
    saveTransportAtFile(t4);

    free(t1);
    free(t2);
    free(t3);
    free(t4);

    return 0;
}

int client_main(Aux_User **user_details)
{

    Aux_User *user = *user_details;
    Transport *transports = NULL;

    free(*user_details);

    if (loadTransport(&transports))
    {

        Transport *aux = transports;

        
        while (aux != NULL)
        {
            printf("\nUUID: %s | Type: %s | Position: %s | Battery: %.2f | State: %d | Price: %.2f | Price per minute: %.2f | Next: %p | \n", aux->uuid, aux->type_name, aux->position, aux->battery, aux->state, aux->price.price_base, aux->price.price_per_minute, aux->next_node);
        }

        free(transports);

        return 0;
    }

    return 1;
}