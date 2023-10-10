#include "print_dir.h"

extern int num_dir;
extern int num_files;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "usage: %s <directory>\n", argv[0]);
        exit(1);
    }
    char *dir_name = argv[argc - 1];
    list_dir(dir_name);
    printf("%d dirs; %d files\n", num_dir, num_files);
    return 0;
}
