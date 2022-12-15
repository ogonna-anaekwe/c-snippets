CC=gcc
FLAGS=-Wall -Werror -fsanitize=thread

all: fzbuzz

clean:
	rm -rf main *.o

fzbuzz: main.c fizzbuzz.*
	$(CC) -o pfzbuzz main.c fizzbuzz.c $(FLAGS)