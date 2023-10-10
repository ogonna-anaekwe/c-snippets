#ifndef __print_dir_h__
#define __print_dir_h__

#include <dirent.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHECK_ERROR(ptr, dir_name)                       \
    if (ptr == NULL)                                     \
    {                                                    \
        fprintf(stderr, "couldn't open %s\n", dir_name); \
        exit(1);                                         \
    }

/**
 * Creates relative path to directory.
 * @param parent_dir
 * @param child_dir
 * @return relative path to directory.
 */
char *get_relative_path(char *parent_dir, char *child_dir);

/**
 * Prints the path of all (nested) directories/files in a directory.
 * @param dir_name
 */
void list_dir(char *dir_name);

#endif // __print_dir_h__
