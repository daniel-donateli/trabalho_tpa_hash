CFLAGS = -Wall -Wextra -O2
CC = clang
INCLUDE = ./include
OBJS=main.o lista.o

all: main

main: $(OBJS)
	${CC} ${CFLAGS} -I${INCLUDE} -o main.exe ${OBJS}

clean:
	-rm -f *.o 

lista.o:
	${CC} ${CFLAGS} -I${INCLUDE} -c ./src/lista.c -o lista.o

main.o:
	${CC} ${CFLAGS} -I${INCLUDE} -c ./src/main.c -o main.o