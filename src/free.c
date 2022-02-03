#include "../inc/ush.h"


void mx_free_double_ptr(void **ptr) {
    for (int i = 0; ptr[i] != NULL; i++) {
        free(ptr[i]);
    }
    free(ptr);
}
 