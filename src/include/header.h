#include "../structs/transport.struct.h"
#include "../structs/user.struct.h"
#include "../structs/aux.struct.h"

int main();
void login(User **users, Aux_User **user_details);
void register_user(User **users, Aux_User **user_details);
Aux_User *getUserDetails(User *users);
char *encrypt(char *str);
int load_users(User **users);
User *insertUser(User *users, Aux_User *user);
User *existUser(User *users, int *nif, char *email, char *phone_number);
int checkEmail(char *email);
User *listUsers(User *users);
int createUsersFile(User **users);
char *gen_uuid();
int existFile(char *path, char *openMode);
void cls();
int authenticate(char *email, char *password, User **users, Aux_User **user_details);
void press_to_continue();
void flushstdin(void);
int saveUserAtFile(Aux_User *user);
void authMenu(User **users, Aux_User **user_details);
