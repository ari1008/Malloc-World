# change application name here (executable output name)
TARGET=MALLOC_WORLD

# compiler
CC=gcc
# debug
DEBUG=-g
# optimisation
OPT=-O6
# warnings
WARN=-Wall

WEXTRA=-Wextra

PTHREAD=-pthread



CCFLAGS=$(DEBUG) $(OPT) $(WARN) $(WEXTRA)  $(PTHREAD) -pipe

# linker
LD=gcc
LDFLAGS=$(PTHREAD)

OBJS=    main.o

#all: $(OBJS)
	#$(LD) -o $(TARGET) $(OBJS) $(LDFLAGS)



#main.o: src/Sources/main.c
	#$(CC) -c $(CCFLAGS) src/Sources/main.c   -o main.o

all:MALLOC-WORLD



MALLOC-WORLD: item.o monster.o npc.o player.o recipe.o item.o resources.o world.o main.o
	$(LD) -o $(TARGET) src/objets/items.o src/objets/monster.o src/objets/npc.o src/objets/player.o  src/objets/recipe.o src/objets/ressources.o src/objets/items.o src/objets/world.o src/objets/main.o

item.o: src/Sources/items.c
	$(CC) -o src/objets/items.o  -c src/Sources/items.c  $(CCFLAGS)

monster.o: src/Sources/monster.c
	$(CC) -o src/objets/monster.o  -c src/Sources/monster.c  $(CCFLAGS)

npc.o: src/Sources/npc.c
	$(CC) -o src/objets/npc.o  -c src/Sources/npc.c  $(CCFLAGS)

player.o: src/Sources/player.c
	$(CC) -o src/objets/player.o  -c src/Sources/player.c  $(CCFLAGS)

#receipt.o: src/Sources/rec.c
	#$(CC) -o src/headers/receipt.o  -c src/Sources/receipt.c  $(CCFLAGS)

recipe.o: src/Sources/recipe.c
	$(CC) -o src/objets/recipe.o  -c src/Sources/recipe.c  $(CCFLAGS)

resources.o: src/Sources/resources.c
	$(CC) -o src/objets/ressources.o  -c src/Sources/resources.c $(CCFLAGS)

world.o: src/Sources/world.c
	$(CC) -o src/objets/world.o  -c src/Sources/world.c $(CCFLAGS)

main.o:  src/Sources/main.c src/headers/items.h  src/headers/monster.h src/headers/npc.h src/headers/player.h src/headers/recipe.h src/headers/resources.h
	$(CC) -o src/objets/main.o -c src/Sources/main.c $(CCFLAGS)
clean:
	rm -f src/objets/*.o $(TARGET)