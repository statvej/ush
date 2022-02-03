#include "../inc/ush.h"


void shell_loop(void) {
    char *input;
    char **argv;
    int status;

    do {
        printf("u$h> ");

        input = read_input();
        argv = parse_input(input);
        //mx_print_strarr(argv, "\n");
        status = mx_execute(argv);
        free(input);
        free(argv);
        int exit_stat = errno;
        if (exit_stat == ERRNO_EXIT)
        {
            exit(EXIT_SUCCESS);
        }
        
    } while (status);
}
 