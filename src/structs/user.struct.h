typedef struct address
{
    char street[50];
    char city[50];
    char country[50];
    char postal_code[10]; // 10 is the size of the biggest postal code in the world
} Address;

typedef struct personal_data
{
    char name[50];
    int nif; 
    char email[50];
    char phone_number[16]; // 15 is the size of the biggest phone number in the world
    float balance; // Balance of the user
    Address address;
} PersonalData;

typedef struct user_node
{
    char uuid[37]; // 36 + 1 (\0) is the size of a UUID
    int user_type; // 0 for normal user, 1 for admin
    PersonalData personal_data;
    struct user_node* next_node; // Pointer to the next node
} User;