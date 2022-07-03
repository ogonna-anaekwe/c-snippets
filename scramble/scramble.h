#ifndef __scramble_h__
#define __scramble_h__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * Scrambles a string: randomly repositions all characters but the first and last.
 * @param str String to be scrambled.
 * @return char* Scrambled string.
 */
char *scramble(const char *str);

/**
 * Algorithm:
 * 1. Create an array to hold the number of chars btw the first and last. e.g. for "bread", this array will be {0, 1, 2} for 'r', 'e', and 'a'
 * 2. Malloc a new string to hold the scrambled string (the first and last chars of this string matches the original string)
 * 3. Select a random char btw the first and last i.e. btw 0 and 2 (inclusive). If 0 is selected, then 0 + 1 gives 'r' in the original string. We place this value in index 1
 * of the new string. If 2, then 2 + 1 gives 'a', and we place this char in index 1 of the new string instead.
 * 4. Update the value of the selected char in the array to -1.
 * 5. Create a new array with the non-negative values (from the original array). (This ensures the next time we randomly select, we're only selecting a value that has yet to be selected.)
 * 6. Repeat this process until there is only one value left in the new array.
 *
 * Note: This program is slightly more complicated because of the need for randomness. So that given 'bread', the program could
 * scramble it to bread, braed, beard, bared, etc. Were the program non-random/deterministic, it'd be a lot easier.
 */
#endif // __scramble_h__