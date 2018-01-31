CC=gcc
OBJ=obj/main.o obj/grille.o obj/routine.o
EXE=pong
OPT=-Wall -std=c99 -g

all : $(OBJ)
	$(CC) $(OPT) -o $(EXE) $(OBJ)

obj/%.o : src/%.c
	$(CC) $(OPT) -o $@ -c $<

clean :
	rm -f *~ obj/*.o $(EXE) $(OBJ)
