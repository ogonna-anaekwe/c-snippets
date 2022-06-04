#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// uncomment to disable assert()
// #define NDEBUG
#include <assert.h>

/**
 * Checks if a string is a palindrome
 * i.e. reads same forward and backward.
 * @param str - String to check.
 * @return char * - Result showing whether the string is a palindrome.
 */
char *is_palindrome(char *str);

/**
 * Returns alphanum string.
 * Strips away special characters, punctuations, etc.
 * @param str - String to clean.
 * @return char* - Clean string containing only digits and letters
 */
char *clean_str(char *str);

int main(int argc, char *argv[])
{
    assert(argc == 2);

    char *str = argv[1], *str_is_palindrome;

    str_is_palindrome = is_palindrome(str);
    printf("\"%s\" is a palindrome: %s\n", str, str_is_palindrome);

    return 0;
}

char *clean_str(char *str)
{
    size_t str_len = strlen(str);
    int i = 0; // keeps track of str_clean's length
    char *c, *str_clean = malloc(str_len + 1);
    assert(str_clean != NULL);

    for (c = str; *c != '\0'; c++)
    {
        if (isalnum(*c))
        {
            str_clean[i] = *c;
            i++;
        }
    }

    return str_clean;
}

char *is_palindrome(char *str)
{
    bool is_palindrome;
    int i = 0;
    char *c, *str_clean = clean_str(str), c_comp;
    size_t str_len = strlen(str_clean);

    for (c = str_clean; *c != '\0'; c++, i++)
    {
        c_comp = str_clean[str_len - (i + 1)];
        is_palindrome = tolower(*c) == tolower(c_comp);

        if (!is_palindrome)
        {
            printf("Mismatch between %c and %c. Exiting...\n", *c, c_comp);
            /**
             * Exit loop after the first mis-match.
             * No point continuing as the first mis-match guarantees the str is not a palindrome.
             */
            break;
        }
    }

    /**
     * De-allocate memory space from heap.
     * De-allocating here rather than in the clean_str function.
     * If de-allocated in the clean_str function, the address
     * will no longer contain the cleaned string. And the
     * result becomes wrong and unreliable.
     */
    free(str_clean);

    return is_palindrome ? "true" : "false";
}