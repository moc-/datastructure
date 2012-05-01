CC = gcc
CFLAGS = -g -Wall -o 

EXEC = test

OBJ = init.o
OBJ += btree.o

SRC = init.c
SRC += btree.c

$(EXEC) : $(OBJ)
	$(CC) $(CFLAGS) $(EXEC) $(OBJ)
$(OBJ) : $(SRC)
