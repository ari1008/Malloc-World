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

all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS) $(LDFLAGS)



main.o: src/Sources/main.c
	$(CC) -c $(CCFLAGS) src/Sources/main.c  -o main.o

clean:
	rm -f *.o $(TARGET)