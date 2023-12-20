#ifndef __print_dir_h__
#define __print_dir_h__

#include <dirent.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Creates relative path to directory.
 * @param parent_dir
 * @param child_dir
 * @return relative path to directory.
 */
char *get_relative_path(char *parent_dir, char *child_dir);

/**
 * Prints the path of all (nested) directories/files in a directory.
 * This is a bare-bones implementation of the unix util 'ls'
 * @param dir_name
 */
void print_dir(char *dir_name);

#endif // __print_dir_h__
