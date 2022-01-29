#include "../inc/ush.h"


void shell_loop(void) {
    char *input;
    char **argv;
    int status;

    do {
        printf("u$h> ");

        input = read_input();
        argv = parse_input(input);
        mx_print_strarr(argv, "\n");
        status = mx_execute(argv);
        free(input);
        free(argv);
    } while (status);
}
