typedef struct aux_address
{
    char street[150];
    char city[50];
    char country[50];
    char postal_code[10]; // 10 is the size of the biggest postal code in the world
} Aux_Address;

typedef struct aux_login
{
    char email[50];
    char password[50];

} Aux_Login;

typedef struct aux_personal_data
{
    char name[50];
    int nif;
    char phone_number[25]; // 15 is the size of the biggest phone number in the world
    float balance;         // Balance of the user
    Aux_Address address;
    Aux_Login login;
} Aux_PersonalData;

typedef struct aux_user
{
    char uuid[37]; // 36 + 1 (\0) is the size of a UUID
    int user_type; // 0 for normal user, 1 for admin
    Aux_PersonalData personal_data;
} Aux_User;