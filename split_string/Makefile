
CC=gcc

all: main

clean:
	rm -rf main *.o

main: main.c split_str.*
	$(CC) -o main main.c split_str.c -Wall