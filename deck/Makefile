CC = gcc
FLAGS = -Wall -Werror -Wfatal-errors -Wpedantic

all: main

clean:
	rm -rf shuffle *.o

main: main.c shuffle.*
	$(CC) -o shuffle main.c shuffle.c $(FLAGS)