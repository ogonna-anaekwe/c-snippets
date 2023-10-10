
CC=gcc
FLAGS= -Wall -Werror -Wpedantic

all: main

clean:
	rm -rf main *.o

main: main.c print_dir.* 
	$(CC) -o main main.c print_dir.c $(FLAGS)