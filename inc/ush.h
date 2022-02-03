#include "libmx.h"
#include <limits.h>
#include <errno.h>
#include <signal.h>
#include <fcntl.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <termcap.h> 
#include <time.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/wait.h>
 
#define READ_LINE_BUFFER_SIZE 1024
#define PARSE_ARGS_BUF_SIZE 64

#define PARSE_DELIMERS " \t\r\n\a"

#define ERRNO_EXIT 2



// enum Builtin{
//     pwd;

// } 

typedef struct s_input {
    char *command;
    char *flags;
    int status;
    
} t_input;

// Loop Functions
void shell_loop(void);

// Read input
char *read_input();

// Parsing
char **parse_input(char *input);

// Utils
void mx_free_double_ptr(void **ptr); // use only for NULL terminated arrays
int is_str_in_arr(char *str, char **str_arr);

// Execution
int launch_process(char **args);
int mx_execute(char **args);

// Built in funcs
int bin_pwd();
int is_builtin(char *prog_name);
int execute_builtin(char ** argv);
int bin_exit();