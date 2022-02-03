#include "../inc/ush.h"

int bin_pwd() {
    char *path = mx_strdup(getenv("PWD"));
    if (path != NULL) {
        printf("%s\n", path);
    }
    else
        return -1;
    free(path);
    return 0;
}
int bin_exit(){
    printf("EXIT ENTEREDn");
    errno = 2;
    return 0;
}


int is_builtin(char *prog_name) {
    char *builtin_avial[20] = {"pwd", "cd", "exit", NULL};
    return is_str_in_arr(prog_name, builtin_avial);
}

int execute_builtin(char **argv) {
    pid_t pid;
    int status;
    pid = fork();
    if (pid == 0) {
        if (!strcmp(argv[0], "pwd")) {
            exit(bin_pwd());
        }
        // if (!strcmp(argv[0], "exit")) {
            
        //     exit(bin_exit());
        // }

        exit(EXIT_FAILURE);
    }
    if (pid < 0)
        perror("fork");
    if (pid > 0) {
        do {

            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    return 1;
}
