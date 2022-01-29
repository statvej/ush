#include "../inc/ush.h"

char **parse_input(char *input) {
    int bufsize = PARSE_ARGS_BUF_SIZE, position = 0;
    char **argv = malloc(bufsize * sizeof(char *));
    char *s_arg, **argv_backup;

    if (!argv) {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
    }

    s_arg = strtok(input, PARSE_DELIMERS);
    while (s_arg != NULL) {
        argv[position] = s_arg;
        position++;

        if (position >= bufsize) {
            bufsize += PARSE_ARGS_BUF_SIZE;
            argv_backup = argv;
            argv = realloc(argv, bufsize * sizeof(char *));
            if (!argv) {
                free(argv_backup);
                fprintf(stderr, "lsh: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }

        s_arg = strtok(NULL, PARSE_DELIMERS);
    }
    argv[position] = NULL;
    return argv;
}
