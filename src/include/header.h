#include "../structs/transport.struct.h"
#include "../structs/user.struct.h"
#include "../structs/aux.struct.h"

void login(User **users, Aux_User **user_details);
char *encrypt(char *str);
int load_users(User **users);
User *insertUser(User *users, Aux_User *user);
int checkEmail(char *email);
User *listUsers(User *users);
void createUsersFile(User **users);
char *gen_uuid();
int existFile(char *path, char *openMode);
void cls();
int authenticate(char *email, char *password, User **users, Aux_User **user_details);
void press_to_continue();
void flushstdin(void);
