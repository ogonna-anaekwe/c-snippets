#include <stdio.h>
#include "binary_search.h"

int main(void)
{
    int arr[] = {11, 21, 31, 44, 55, 67, 68, 88, 90};
    int arr_len = sizeof(arr) / sizeof(arr[0]);
    int target = 21;

    printf("%d\n", binary_search(arr, arr_len, target));

    return 0;
}
