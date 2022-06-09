#include <stdio.h>
#include <stdlib.h>
#include "dec_to_bin.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "usage: ./main \"number\"\n");
        exit(EXIT_FAILURE);
    }

    long decimal = atol(argv[1]);

    char *binary_str = decimal_to_binary(decimal);
    printf("Dec: %ld <--> Bin: %s\n", decimal, binary_str);
    free(binary_str);

    return 0;
}