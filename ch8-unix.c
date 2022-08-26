#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utils.h"

int newgetchar(int fd){
    static char buf[BUFSIZ];
    static char *bufp = buf;
    static int n;

    if(n == 0)
        n = read(fd, buf, BUFSIZ);

    return --n >= 0 ? *bufp++: EOF;
}

void newcat(char filename[]){
    int fd = open(filename, 0100, 0);
    int fw = creat("test.c", 0755);
    int c;
    while((c = newgetchar(fd)) != EOF)
        write(fw, &c, 1);
    close(fd);
    close(fw);
}

int main (int argc, char *argv[])
{
    newcat(*(argv + 1));
}

