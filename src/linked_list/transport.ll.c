#include "../include/header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
    @brief Updates the information of a transport in the "transport.txt" file.
    This function receives an instance of the Aux_Transport structure and updates the information
    of the transport that has the same UUID in the "transport.txt" file.
    The file is opened in read-write mode, and the function seeks the line that contains the UUID.
    When found, the function updates the line with the new information and returns 1 to indicate success.
    @param transport A pointer to an instance of the Aux_Transport structure that contains the updated information.
    @return 1 if the update was successful, or 0 if there was an error opening the file.
    @note This function assumes that the file "data/transport.txt" exists and is in the correct format.
    @note This function assumes that the UUID of the transport is unique.
*/

int updateTransportAtFile(Aux_Transport *transport)
{
    FILE *file = fopen("data/transport.txt", "r+"); // Open file in read-write mode

    if (file == NULL)
    {
        printf("Error opening file!");
        return 0;
    }

    char line[4096];
    long pos = 0; // Keep track of the file position

    while (fgets(line, sizeof(line), file))
    {

        if (strstr(line, transport->uuid) != NULL)
        {
            fseek(file, pos, SEEK_SET);
            fprintf(file, "%s;%s;%s;%s;%.2f;%d;%.2f;%.2f\n", transport->uuid, transport->type_name, transport->code, transport->position, transport->battery, transport->state, transport->price.price_base, transport->price.price_per_minute);
            break;
        }

        pos = ftell(file); 
    }

    fclose(file);
    return 1;
}

// 0 disponivel | 1 alugado

Transport *checkTransportAvailable(Transport *transports, char *code)
{

    Transport *aux = transports;
    while (aux != NULL)
    {

        if (strcmp(code, aux->code) == 0)
        {
            return aux;
        }

        aux = aux->next_node;
    }

    return NULL;
}

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

Transport *removeTransport(Transport *transports, char *code) {
    Transport *prev = NULL;
    Transport *curr = transports;

    while (curr != NULL && strcmp(curr->code, code) != 0) {
        prev = curr;
        curr = curr->next_node;
    }

    if (curr == NULL) {
        printf("Transport not found in the list.\n");
        return transports;
    }

    if (prev == NULL) {
        // The transport to be removed is the head of the list
        transports = curr->next_node;
    } else {
        prev->next_node = curr->next_node;
    }

    free(curr);

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
