#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

/**
 * Mimics python's string split func.
 * @param string String to split.
 * @param delimiter Delimiter to split by.
 * @return char** - "Array" of pointers, with each pointer representing tokens from the original string.
 */
char **split(char *string, char *delimiter);

/**
 * Usage: ./<executable_name> "<string to split>" "<delimiter>"
 */
int main(int argc, char *argv[])
{
    assert(argc == 3);

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
    char **split_string = malloc(str_len);
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