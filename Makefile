CFLAGS = -Wall -Wextra -O2
CC = gcc
INCLUDE = ./include
SRC = ./src
OBJS=main.o file_reader.o hash_fechada.o lista.o

all: main

main: $(OBJS)
	${CC} ${CFLAGS} -I${INCLUDE} -o main.exe ${OBJS}

clean:
	-rm -f *.o 

lista.o:
	${CC} ${CFLAGS} -I${INCLUDE} -c ${SRC}/lista.c -o lista.o

hash_fechada.o:
	${CC} ${CFLAGS} -I${INCLUDE} -c ${SRC}/hash_fechada.c -o hash_fechada.o

file_reader.o:
	${CC} ${CFLAGS} -I${INCLUDE} -c ${SRC}/file_reader.c -o file_reader.o

main.o:
	${CC} ${CFLAGS} -I${INCLUDE} -c .${SRC}/main.c -o main.o
