#include "../inc/ush.h"
// TODO Add cursor moving and displaying

char *read_input() {
    char *buf = (char *)malloc(sizeof(char) * READ_LINE_BUFFER_SIZE);
    int c;
    int i = 0;
    do {
        c = getchar();
        if (c == -1)
        {
            exit(EXIT_SUCCESS);
        }
        
        buf[i] = c;
        i++;
        if (i >= READ_LINE_BUFFER_SIZE) {
            buf = (char *)realloc(buf, sizeof(char) * (i + READ_LINE_BUFFER_SIZE));
        }
    } while (c != '\n');
    buf[i] = '\0';

    return buf;
}
