#include "binary_search.h"

int binary_search(int arr[], int arr_len, int target)
{

    int left_idx = 0;
    int right_idx = arr_len - 1;

    while (left_idx <= right_idx)
    {
        int m = floor((left_idx + right_idx) / 2);
        bool below_target = arr[m] < target;
        bool beyond_target = arr[m] > target;

        if (below_target)
        {
            left_idx = m + 1;
        }
        else if (beyond_target)
        {
            right_idx = m - 1;
        }

        else
        {
            return m;
        }
    }

    return -1;
}
