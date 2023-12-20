
CC=gcc
FLAGS= -Wall -Werror -Wpedantic

all: print_dir

clean:
	rm -rf print_dir *.o

print_dir: main.c print_dir.* 
	$(CC) -o print_dir main.c print_dir.c $(FLAGS)