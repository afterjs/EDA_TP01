#include "../include/header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Transport *insertTransport(Transport *transports, Aux_Transport *transport)
{
    if (transports == NULL)
    {

        transports = malloc(sizeof(Transport));

        if (transports == NULL)
        {
            printf("Error allocating memory!");
            return NULL;
        }

        strcpy(transports->uuid, transport->uuid);
        strcpy(transports->type_name, transport->type_name);
        strcpy(transports->code, transport->code);
        strcpy(transports->position, transport->position);
        transports->battery = transport->battery;
        transports->state = transport->state;
        transports->price.price_base = transport->price.price_base;
        transports->price.price_per_minute = transport->price.price_per_minute;
        transports->next_node = NULL;

        return transports;
    }

    Transport *aux = transports;

    while (aux->next_node != NULL)
    {
        aux = aux->next_node;
    }

    aux->next_node = malloc(sizeof(Transport));

    if (aux->next_node == NULL)
    {
        printf("Error allocating memory!");
        return NULL;
    }

    strcpy(aux->next_node->uuid, transport->uuid);
    strcpy(aux->next_node->type_name, transport->type_name);
    strcpy(aux->next_node->code, transport->code);
    strcpy(aux->next_node->position, transport->position);
    aux->next_node->battery = transport->battery;
    aux->next_node->state = transport->state;
    aux->next_node->price.price_base = transport->price.price_base;
    aux->next_node->price.price_per_minute = transport->price.price_per_minute;
    aux->next_node->next_node = NULL;

    return transports;
}

int saveTransportAtFile(Aux_Transport *transport)
{
    FILE *file = fopen("./data/transport.txt", "a");

    if (file == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    // fprintf(file, "%s;%s;%s;%s;%.2f;%d;%.2f;%.2f\n", transport->uuid, transport->type_name, transport->code, transport->position, transport->battery, transport->state, transport->price.price_base, transport->price.price_per_minute);

    fprintf(file, "%s;%s;%s;%s;%.2f;%d;%.2f;%.2f\n", transport->uuid, transport->type_name, transport->code, transport->position, transport->battery, transport->state, transport->price.price_base, transport->price.price_per_minute);

    fclose(file);
}

int loadTransport(Transport **transports)
{

    if (existFile("./data/transport.txt", "r") == 0)
    {
        createTransportFile();
    }

    FILE *file = fopen("./data/transport.txt", "r");

    if (file == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    Aux_Transport *aux = malloc(sizeof(Aux_Transport));

    while (fscanf(file, "%[^;];%[^;];%[^;];%[^;];%f;%d;%f;%f\n", aux->uuid, aux->type_name, aux->code, aux->position, &aux->battery, &aux->state, &aux->price.price_base, &aux->price.price_per_minute) != EOF)
    {
        *transports = insertTransport(*transports, aux);
    }

    free(aux);
    fclose(file);

    return 1;
}
