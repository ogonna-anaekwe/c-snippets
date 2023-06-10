
CC=gcc
FLAGS= -Wall -Werror -Wpedantic

all: main

clean:
	rm -rf main *.o

main: main.c binary_search.*
	$(CC) -o main main.c binary_search.c $(FLAGS)