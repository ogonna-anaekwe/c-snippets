#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "dec_to_bin.h"

char *decimal_to_binary(long decimal)
{
    size_t binary_len = sizeof(long) * 8;
    char *binary = malloc(binary_len);
    assert(binary != NULL);

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