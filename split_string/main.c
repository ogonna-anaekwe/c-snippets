#include <stdio.h>
#include <stdlib.h>
#include "split_str.h"

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "usage: ./main \"string\" \"delimiter\"\n");
        exit(EXIT_FAILURE);
    }

    char *string = argv[1],
         *dlm = argv[2],
         **split_string = split(string, dlm),
         **p = split_string;

    while (*p)
    {
        puts(*p);
        p++;
    }

    free(split_string);

    return 0;
}