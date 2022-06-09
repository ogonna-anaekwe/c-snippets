#include <stdio.h>
#include <stdlib.h>
#include "is_palindrome.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "usage: ./main \"string or sentence\"\n");
        exit(EXIT_FAILURE);
    }

    char *str = argv[1], *str_is_palindrome;

    str_is_palindrome = is_palindrome(str);
    printf("\"%s\" is a palindrome: %s\n", str, str_is_palindrome);

    return 0;
}