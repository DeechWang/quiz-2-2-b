#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("usage: path1 [path2 ...]\n");
    }

    for (int i = 1; i < argc; ++i) {  // Start from 1 to skip the program name
        struct stat s;
        long unsigned int returnval = stat(argv[i], &s);

        if (returnval < 0) {
            printf("%s: path error\n", argv[i]);
        } else {
            switch (s.st_mode & __S_IFMT) {
                case __S_IFREG:
                    printf("%s: regular file\n", argv[i]);
                    break;
                case __S_IFDIR:
                    printf("%s: directory\n", argv[i]);
                    break;
                case __S_IFCHR:
                    printf("%s: character special file\n", argv[i]);
                    break;
                case __S_IFLNK:
                    printf("%s: symbolic link\n", argv[i]);
                    break;
                default:
                    printf("%s: path error\n", argv[i]);
                    break;
            }
        }
    }

    return 0;
}
