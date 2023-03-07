typedef struct aux_address
{
    char street[50];
    char city[50];
    char country[50];
    char postal_code[10]; // 10 is the size of the biggest postal code in the world
} Aux_Address;

typedef struct aux_personal_data
{
    char name[50];
    int nif;
    char email[50];
    char phone_number[16]; // 15 is the size of the biggest phone number in the world
    float balance;         // Balance of the user
    Aux_Address address;
} Aux_PersonalData;

typedef struct aux_user
{
    char uuid[37]; // 36 + 1 (\0) is the size of a UUID
    int user_type; // 0 for normal user, 1 for admin
    Aux_PersonalData personal_data;
} Aux_User;