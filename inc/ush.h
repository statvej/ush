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


//Loop Functions
void shell_loop(void);

//Read input
char *read_input();

//Parsing
char **parse_input(char *input);


//Utils
void mx_free_double_ptr(void **ptr);//use only for NULL terminated arrays

//Execution
int launch_process(char **args);
int mx_execute(char **args);






