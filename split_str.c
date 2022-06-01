#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

/**
 * Mimics the split func in python.
 * Usage: ./<executable_name> "<string to split>" "<delimiter>".
 * Returns the original string if it doesn't contain the delimiter.
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char *argv[])
{
    assert(argc == 3);

    char *string = argv[1],
         *dlm = argv[2],
         *token = strtok(string, dlm);

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

    // for (char **p = string_split; *p; p++)
    // {
    //     puts(*p);
    // }

    free(string_split);

    return 0;
}