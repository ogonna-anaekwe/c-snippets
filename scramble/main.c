#include "scramble.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./main \"string\"\n");
        exit(1);
    }

    char *string = argv[1],
         *scrambled_string;

    printf("String: %s\nScrambled:", string);
    char *token = strtok(string, " ");
    int token_len;

    while (token)
    {
        token_len = strlen(token);
        scrambled_string = token_len > 3 ? scramble(token) : token;
        printf(" %s", scrambled_string);

        if (token_len > 3)
        {
            free(scrambled_string);
        }

        token = strtok(NULL, " ");
    }
    printf("\n");

    return 0;
}