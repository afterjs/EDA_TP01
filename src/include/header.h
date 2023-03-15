#include "../structs/user.struct.h"
#include "../structs/aux.user.struct.h"
#include "../structs/aux.transport.struct.h"
#include "../structs/transport.struct.h"


int printUserDetails(Aux_User *user);
int showAccountDetails(Aux_User *user);
int updateTransportAtFile(Aux_Transport *transport);
int updateUserAtFile(Aux_User *user);
int finishRent(Aux_User *user, Transport **transport, time_t *stop_time);
char *timestamp_to_text(time_t timestamp);
Transport *checkTransportAvailable(Transport *transports, char *code);
int rentTransport(Aux_User *user, Transport **transport);
void showMenu(Aux_User *user, Transport **transports);
int client_main(Aux_User **user_details);
void login(User **users, Aux_User **user_details);
void register_user(User **users, Aux_User **user_details);
Aux_User *getUserDetails(User *users);
char *encrypt(char *str);
int load_users(User **users);
User *insertUser(User *users, Aux_User *user);
User *existUser(User *users, int *nif, char *email, char *phone_number);
int checkEmail(char *email);
User *listUsers(User *users);
int createUsersFile();
char *gen_uuid();
int existFile(char *path, char *openMode);
void cls();
int authenticate(char *email, char *password, User **users, Aux_User **user_details);
void press_to_continue();
void flushstdin(void);
int saveUserAtFile(Aux_User *user);
void authMenu(User **users, Aux_User **user_details);
int getAge(int day, int month, int year);
int loadTransport(Transport **transports);
int createTransportFile();
int saveTransportAtFile(Aux_Transport *transport);
Transport *insertTransport(Transport *transports, Aux_Transport *transport);
