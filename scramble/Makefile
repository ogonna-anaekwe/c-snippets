
CC=gcc

all: main

clean:
	rm -rf main *.o *.dSYM

main: main.c scramble.*
	$(CC) -glldb -o main main.c scramble.c -Wall -Werror	