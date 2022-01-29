#include "ush.h"

// TODO Add cursor moving and displaying
int check_arrow_input(int c) {//doesnt work
    if (c == '\033') { // if the first value is esc

        switch (c) { // the real value
        case 'A':
            break;
        case 'B':
            break;
        case 'C':
            printf("\033[C"); 
            break;
        case 'D':
            printf("\033[D");
            break;
        }
        return 1;
    }
    else
        return 0;
}

char *read_input() {
    int position = 0, buf_size = READ_LINE_BUFFER_SIZE;
    char *buf = (char *)malloc(sizeof(char) * READ_LINE_BUFFER_SIZE);
    if (!buf)
        exit(EXIT_FAILURE);
    int c;
    while (true) {

        c = getchar();

        if (c == EOF)
            exit(EXIT_SUCCESS);
        else if (c == '\n') {
            buf[position] = '\n';
            return buf;
        }
        else
            buf[position] = c;
        position++;

        if (position >= buf_size) {
            buf_size += READ_LINE_BUFFER_SIZE;
            buf = (char *)realloc(buf, buf_size);
            if (!buf) {
                mx_printerr("Allocation error in buffer realloc\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}
