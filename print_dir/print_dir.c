#include "print_dir.h"

int num_dir = 0;   /* total number of directories */
int num_files = 0; /* total number of regular files */

char *get_relative_path(char *parent_dir, char *child_dir)
{
    size_t parent_dir_len = strlen(parent_dir);
    size_t child_dir_len = strlen(child_dir);
    char *relative_path = malloc(parent_dir_len + child_dir_len + 2); /* 2: 1 for / in path and 1 for NULL byte */

    strncpy(relative_path, parent_dir, parent_dir_len);
    strncat(relative_path, "/", 1);
    strncat(relative_path, child_dir, child_dir_len);

    return relative_path;
}

void list_dir(char *dir_name)
{
    DIR *dirp = opendir(dir_name);
    CHECK_ERROR(dirp, dir_name);
    struct dirent *dp;

    do
    {
        dp = readdir(dirp);
        if (dp != NULL)
        {
            char *dirent_name = dp->d_name;
            char *relative_path = get_relative_path(dir_name, dirent_name);
            bool is_dir = dp->d_type == DT_DIR;
            bool is_curr_dir = strcmp(dirent_name, ".") == 0;
            bool is_parent_dir = strcmp(dirent_name, "..") == 0;
            bool ignore_dot = is_curr_dir || is_parent_dir;

            if (is_curr_dir)
                num_dir++;

            if (ignore_dot)
                continue;

            if (is_dir)
                list_dir(relative_path);
            else
                num_files++;

            free(relative_path);
            printf("%s/%s \n", dir_name, dirent_name);
        }
    } while (dp != NULL);

    closedir(dirp); /* be a good citizen; close what you open */
}
