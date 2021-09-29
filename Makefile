CFLAGS = -Wall -Wextra -O2
CC = gcc
INCLUDE = ./include
OBJS=main.o hash_fechada.o lista.o

all: main

main: $(OBJS)
	${CC} ${CFLAGS} -I${INCLUDE} -o main.exe ${OBJS}

clean:
	-rm -f *.o 

lista.o:
	${CC} ${CFLAGS} -I${INCLUDE} -c ./src/lista.c -o lista.o

hash_fechada.o:
	${CC} ${CFLAGS} -I${INCLUDE} -c ./src/hash_fechada.c -o hash_fechada.o

main.o:
	${CC} ${CFLAGS} -I${INCLUDE} -c ./src/main.c -o main.o
