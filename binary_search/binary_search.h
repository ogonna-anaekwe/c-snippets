#pragma once

#include <math.h>
#include <stdbool.h>

/**
 * REF: https://en.wikipedia.org/wiki/Binary_search_algorithm
 * @param arr Sorted array in which to search for target value.
 * @param arr_len Length of sorted array.
 * @param target Value to be searched for in array.
 * @return int - Index of value in array. -1 if not in array.
 */
int binary_search(int arr[], int arr_len, int target);
