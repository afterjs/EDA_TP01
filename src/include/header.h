#include "../structs/transport.struct.h"
#include "../structs/user.struct.h"
#include "../structs/aux.struct.h"

void login();
char *encrypt(char *str);
char *decrypt(char *str);
int load_users(User **users);
User *insertUser(User *users, Aux_User *user);
int checkEmail(char *email);
User *listUsers(User *users);
void createUsersFile(User **users);
char *gen_uuid();
int existFile(char *path, char *openMode);