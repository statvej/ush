#include "../inc/ush.h"

int is_str_in_arr(char *str, char **str_arr) {
    for (int i = 0; str_arr[i] != NULL; i++) {
        if (!strcmp(str_arr[i], str))
            return 1;
    }
    return 0;
}
 