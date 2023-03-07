CC=gcc

OBJ_DIR = ./object
STRUCTS_DIR = ./structs

all: start

start : clean main.o utils.o encrypt.o  lists.o functions.o $(STRUCTS_DIR)/transport.struct.h $(STRUCTS_DIR)/user.struct.h $(STRUCTS_DIR)/aux.struct.h ./include/header.h
	$(CC) -o start $(OBJ_DIR)/main.o $(OBJ_DIR)/utils.o  $(OBJ_DIR)/encrypt.o   $(OBJ_DIR)/lists.o $(OBJ_DIR)/functions.o $(STRUCTS_DIR)/transport.struct.h $(STRUCTS_DIR)/user.struct.h $(STRUCTS_DIR)/aux.struct.h ./include/header.h 

run: start
	clear
	./start

main.o : main.c
	$(CC) -c main.c
	mv main.o $(OBJ_DIR)

lists.o: lists.c
	$(CC) -c lists.c
	mv lists.o $(OBJ_DIR)

functions.o : functions.c
	$(CC) -c functions.c
	mv functions.o $(OBJ_DIR)
	
encrypt.o : ./utils/encrypt.c
	$(CC) -c ./utils/encrypt.c
	mv encrypt.o $(OBJ_DIR)

utils.o : ./utils/utils.c
	$(CC) -c ./utils/utils.c
	mv utils.o $(OBJ_DIR)	
clean : 
	rm -f $(OBJ_DIR)/*.o start