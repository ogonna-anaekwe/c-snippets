#ifndef __split_str_h__
#define __split_str_h__

/**
 * Mimics python's string split func.
 * @param string String to split.
 * @param delimiter Delimiter to split by.
 * @return char** - "Array" of pointers, with each pointer representing tokens from the original string.
 */
char **split(char *string, char *delimiter);

#endif // __split_str_h__