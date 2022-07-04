#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "split_str.h"

char **split(char *string, char *delimiter)
{
    char *token = strtok(string, delimiter);

    size_t str_len = strlen(string),
           /**
            * Keeps track of how many char * are needed and
            * by extension how much memory should be eventually allocated.
            */
        idx = 0;

    /**
     * Allocate memory on heap. For starters,
     * this might be way more memory than needed.
     */
    char **split_string = (char **)malloc(str_len);
    assert(split_string != NULL);

    while (token)
    {
        split_string[idx] = token;
        token = strtok(NULL, delimiter);
        idx++;
    }

    /**
     * Re-allocate prior allocated memory,
     * now with the correct number of bytes.
     */
    split_string = realloc(split_string, idx);
    assert(split_string != NULL);

    return split_string;
}