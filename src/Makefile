CC=gcc

OBJ_DIR = ./object
STRUCTS_DIR = ./structs
LL_DIR = ./linked_list

all: start

start : clean main.o utils.o encrypt.o users.ll.o transport.ll.o auth.o client.o admin.o $(STRUCTS_DIR)/transport.struct.h $(STRUCTS_DIR)/user.struct.h $(STRUCTS_DIR)/aux.transport.struct.h $(STRUCTS_DIR)/aux.user.struct.h ./include/header.h
	$(CC) -o start $(OBJ_DIR)/main.o $(OBJ_DIR)/utils.o $(OBJ_DIR)/encrypt.o $(OBJ_DIR)/users.ll.o $(OBJ_DIR)/transport.ll.o $(OBJ_DIR)/auth.o $(OBJ_DIR)/client.o $(OBJ_DIR)/admin.o $(STRUCTS_DIR)/transport.struct.h $(STRUCTS_DIR)/user.struct.h $(STRUCTS_DIR)/aux.transport.struct.h $(STRUCTS_DIR)/aux.user.struct.h ./include/header.h 

run: start
	clear
	./start

main.o : main.c
	$(CC) -c main.c
	mv main.o $(OBJ_DIR)

users.ll.o: ./linked_list/users.ll.c
	$(CC) -c ./linked_list/users.ll.c
	mv users.ll.o $(OBJ_DIR)

transport.ll.o: ./linked_list/transport.ll.c
	$(CC) -c ./linked_list/transport.ll.c
	mv transport.ll.o $(OBJ_DIR)


auth.o : ./auth/auth.c
	$(CC) -c ./auth/auth.c
	mv auth.o $(OBJ_DIR)
	
encrypt.o : ./utils/encrypt.c
	$(CC) -c ./utils/encrypt.c
	mv encrypt.o $(OBJ_DIR)

utils.o : ./utils/utils.c
	$(CC) -c ./utils/utils.c
	mv utils.o $(OBJ_DIR)	

client.o: ./actors/client.c
	$(CC) -c ./actors/client.c
	mv client.o $(OBJ_DIR)	

admin.o : ./actors/admin.c
	$(CC) -c ./actors/admin.c
	mv admin.o $(OBJ_DIR)	
clean : 
	rm -f $(OBJ_DIR)/*.o start