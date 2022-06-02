#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Converts decimal to binary using bitwise operators.
 * Max decimal for reliable results: 9223372036854775807.
 * This is the max for a 64-bit signed int type.
 * @param decimal Number to be converted to binary.
 * @return char* - Binary representation of decimal number.
 */
char *decimal_to_binary(long decimal);

int main(int argc, char *argv[])
{
    assert(argc == 2);
    long decimal = atol(argv[1]);

    char *binary_str = decimal_to_binary(decimal);
    printf("Dec: %ld <--> Bin: %s\n", decimal, binary_str);
    free(binary_str);

    return 0;
}

char *decimal_to_binary(long decimal)
{
    size_t binary_len = sizeof(long) * 8;
    char *binary = malloc(binary_len);

    if (!binary)
    {
        puts("Malloc failed!");
        exit(EXIT_FAILURE);
    }

    char *pbinary = &binary[binary_len - 1];

    while (pbinary >= binary)
    {
        /**
         * + '0' converts (decimal & 1) to the ascii char that corresponds to its value.
         * i.e 1 + '0' = '1' because '0' is dec 48 and 1 + 48 = 49 which is dec for ascii '1'.
         */
        binary[pbinary - binary] = (decimal & 1) + '0';
        decimal >>= 1;
        pbinary--;
    }

    return binary;
}