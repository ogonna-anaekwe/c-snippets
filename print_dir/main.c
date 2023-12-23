#include "print_dir.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "usage: %s <directory>\n", argv[0]);
        exit(1);
    }

    extern int num_dir;
    extern int num_files;
    char *dir_name = argv[1];

    print_dir(dir_name, RECURSIVE);
    printf("%d dirs; %d files\n", num_dir, num_files);
    return 0;
}
