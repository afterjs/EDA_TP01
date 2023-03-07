#include "./include/header.h"

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

int main(int argc)
{
    User *users = NULL;
    Transport *transports = NULL;

    load_users(&users);
    //listUsers(users);

    //   printf("%s | ", encrypt("ricardo1996"));

    // users = listUsers(users);

    /*  User *aux = malloc(sizeof(User));
      aux->personal_data = malloc(sizeof(PersonalData));
      aux->personal_data->address = malloc(sizeof(Address));

      aux->personal_data->nif = 123456789;

      strcpy(aux->personal_data->email, "joao@gmail.com");
      strcpy(aux->personal_data->phone_number, "912345678");
      strcpy(aux->personal_data->name, "joao da silva");
      strcpy(aux->personal_data->address->street, "rua da Alegria");
      strcpy(aux->personal_data->address->city, "nem sei");
      strcpy(aux->personal_data->address->country, "portugal");
      strcpy(aux->personal_data->address->postal_code, "4000-000");
      aux->personal_data->balance = 0;
      aux->user_type = 0;
      strcpy(aux->uuid, "123456789-123456789-123456789-123456789");

      FILE *fp;
      fp = fopen("./data/users.bin", "wb");
      fwrite(aux, sizeof(User), 1, fp);
      fclose(fp);

      free(aux->personal_data->address);
      free(aux->personal_data);
      free(aux);

      load_users(&users);
      listUsers(users);
  */
    /*   users = insertUser(users, aux);

       aux = malloc(sizeof(User));
       aux->personal_data = malloc(sizeof(PersonalData));
       aux->personal_data->address = malloc(sizeof(Address));
       aux->personal_data->nif = 999999999;
       strcpy(aux->personal_data->email, "teste@gmail.com");
       strcpy(aux->personal_data->phone_number, "912345678");
       strcpy(aux->personal_data->name, "Joao");
       strcpy(aux->personal_data->address->street, "Rua da Alegria");
       strcpy(aux->personal_data->address->city, "Porto");
       strcpy(aux->personal_data->address->country, "Portugal");
       strcpy(aux->personal_data->address->postal_code, "4000-000");
       aux->personal_data->balance = 0;
       aux->user_type = 0;
       strcpy(aux->uuid, "123456789-123456789-123456789-123456789");

       if (existUser(users, &aux->personal_data->nif, aux->personal_data->email, aux->personal_data->phone_number) != NULL)
       {
           printf("User already exists\n\n");
       }
       else
       {
           users = insertUser(users, aux);
       }

       listUsers(users);
   */
    return 0;
}