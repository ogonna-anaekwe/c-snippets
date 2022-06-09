CC=gcc

all: main

clean:
	rm -rf main *.o

main: main.c is_palindrome.*
	$(CC) -o main main.c is_palindrome.c -Wall