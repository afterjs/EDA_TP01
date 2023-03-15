#include <time.h>

typedef struct dob
{
    int day;
    int month;
    int year;
} Dob;

typedef struct address
{
    char street[150];
    char city[50];
    char country[50];
    char postal_code[10]; // 10 is the size of the biggest postal code in the world
} Address;

typedef struct login
{
    char email[50];
    char password[50];
} Login;

typedef struct personal_data
{
    char name[50];
    Dob dob;
    int nif;
    char phone_number[25]; // 15 is the size of the biggest phone number in the world
    float balance;         // Balance of the user
    Address address;
    Login login;
} PersonalData;

typedef struct rented_transport
{
    char uuid[37];                  // 36 + 1 (\0) is the size of a UUID
    char rented_transport_code[7];  // Code of the transport
    char rented_transport_type[50]; // Type of the transport
    time_t rented_at;
} RentedTransport;

typedef struct user_node
{
    char uuid[37];                 // 36 + 1 (\0) is the size of a UUID
    int user_type;                 // 0 for normal user, 1 for admin
    PersonalData personal_data;
    RentedTransport rented_transport;
    struct user_node *next_node; // Pointer to the next node
} User;