#include "scramble.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./main \"string\"\n");
        exit(1);
    }

    char *string = argv[1],
         *scrambled_string,
         *delimiter = " ";

    printf("String: %s\n\n\nScrambled:", string);
    char *token = strtok(string, delimiter);
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

        token = strtok(NULL, delimiter);
    }
    printf("\n");

    return 0;
}