#include "../inc/uls.h"

int bin_pwd() {
    char *path = getenv("PWD");
    if (!path)
        printf("%s\n", path);
    else
        return -1;
    free(path);
    return 0;
}
