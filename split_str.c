#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

/**
 * Mimics python's string split func.
 * @param str String to split.
 * @param dlm Delimiter to split by.
 * @return char** - "Array" of pointers, with each pointer representing tokens from the original string.
 */
char **split_str(char *str, char *dlm);

/**
 *
 * Usage: ./<executable_name> "<string to split>" "<delimiter>"
 */
int main(int argc, char *argv[])
{
    assert(argc == 3);

    char *string = argv[1],
         *dlm = argv[2],
         **split_string = split_str(string, dlm),
         **p = split_string;

    while(*p)
    {
        puts(*p);
        p++;
    }
    
    free(split_string);

    return 0;
}

char **split_str(char *str, char *dlm)
{
    char *token = strtok(str, dlm);

    size_t str_len = strlen(str),
           /**
            * Keeps track of how many char * are needed and
            * by extension how much memory should be eventually allocated.
            */
        idx = 0;

    /**
     * Allocate memory on heap. For starters,
     * this might be way more memory than needed.
     */
    char **string_split = malloc(str_len);
    if (!string_split)
    {
        puts("Malloc failed!");
        exit(EXIT_FAILURE);
    }

    while (token)
    {
        string_split[idx] = token;
        token = strtok(NULL, dlm);
        idx++;
    }

    /**
     * Re-allocate prior allocated memory,
     * now with the correct number of bytes.
     */
    string_split = realloc(string_split, idx);
    if (!string_split)
    {
        puts("Realloc failed!");
        exit(EXIT_FAILURE);
    }

    return string_split;
}