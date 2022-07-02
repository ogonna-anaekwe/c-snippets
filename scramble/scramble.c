#include "scramble.h"

char *scramble(const char *str)
{
    srand(time(NULL)); // seeding w/ current time guarantees randomness. if you used a constant seed, you can get repeatable/deterministic results
    int str_len = strlen(str),
        str_cut = 2; // for the first and last char
    char *scrambled_str = malloc(str_len);
    scrambled_str[0] = str[0];
    scrambled_str[str_len - 1] = str[str_len - 1];

    int substr_len = str_len - str_cut,
        int_bytes = sizeof(int),
        scrambled_str_idx = 1,
        random_number,
        value,
        *tmp_arr_two,
        *tmp_arr_one = malloc(int_bytes * substr_len);

    if (!tmp_arr_one)
    {
        fprintf(stderr, "Malloc failed\n");
        exit(1);
    }

    for (int *i = tmp_arr_one; i < tmp_arr_one + substr_len; i++)
    {
        tmp_arr_one[i - tmp_arr_one] = (int)(i - tmp_arr_one);
    }

    while (substr_len > 1)
    {
        random_number = rand() % substr_len;
        value = tmp_arr_one[random_number];
        scrambled_str[scrambled_str_idx] = str[value + 1];

        tmp_arr_two = malloc(int_bytes * substr_len);
        if (!tmp_arr_two)
        {
            fprintf(stderr, "Malloc failed\n");
            exit(1);
        }

        int idx = 0;
        tmp_arr_one[random_number] = -1;

        for (int *i = tmp_arr_one; i <= tmp_arr_one + substr_len; i++)
        {
            if (*i >= 0)
            {
                tmp_arr_two[idx] = *i;
                idx++;
            }
        }

        scrambled_str_idx++;
        substr_len--;
        tmp_arr_one = realloc(tmp_arr_two, int_bytes * substr_len);
    }

    scrambled_str[scrambled_str_idx] = str[tmp_arr_two[0] + 1];

    free(tmp_arr_one);
    return scrambled_str;
}