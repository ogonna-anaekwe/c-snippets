#include "scramble.h"

char *scramble(const char *string)
{
    srand(time(NULL)); // seeding w/ current time guarantees randomness. if you used a constant seed, you can get repeatable/deterministic results
    int str_len = strlen(string),
        str_cut = 2; // for the first and last char
    char *scrambled_string = malloc(str_len);
    scrambled_string[0] = string[0];
    scrambled_string[str_len - 1] = string[str_len - 1];

    int inner_str = (str_len - str_cut),
        str_idx = 1,
        random_number,
        value,
        *tmp_arr_two,
        *tmp_arr_one = malloc(sizeof(int) * inner_str);

    if (!tmp_arr_one)
    {
        fprintf(stderr, "Malloc failed\n");
        exit(1);
    }

    for (int *i = tmp_arr_one; i < tmp_arr_one + inner_str; i++)
    {
        tmp_arr_one[i - tmp_arr_one] = (int)(i - tmp_arr_one);
    }

    while (inner_str > 1)
    {
        inner_str--;
        random_number = 1 + (rand() % inner_str); // this will be between 1 and inner_str so we can select any of the chars btw the first and last. w/o the 1, we'll always fail to select the char before the last
        value = tmp_arr_one[random_number];
        scrambled_string[str_idx] = string[value + 1];

        tmp_arr_two = malloc(sizeof(int) * inner_str);
        if (!tmp_arr_two)
        {
            fprintf(stderr, "Malloc failed\n");
            exit(1);
        }

        int idx = 0;
        tmp_arr_one[random_number] = -1;

        for (int *i = tmp_arr_one; i <= tmp_arr_one + inner_str; i++)
        {
            if (*i >= 0)
            {
                tmp_arr_two[idx] = *i;
                idx++;
            }
        }

        tmp_arr_one = realloc(tmp_arr_two, sizeof(int) * inner_str);
        str_idx++;
    }

    scrambled_string[str_idx] = string[tmp_arr_two[0] + 1];

    free(tmp_arr_one);
    return scrambled_string;
}