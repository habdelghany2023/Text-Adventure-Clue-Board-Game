SRC = adventure.c items.c characters.c rooms.c
OBJ = adventure.o items.o characters.o rooms.o
PROG = clue

$(PROG): $(OBJ)
	gcc -std=c99 $(OBJ) -o $(PROG)
$(OBJ):$(SRC)
	gcc -c $(SRC)
