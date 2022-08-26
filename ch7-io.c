#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utils.h"

void mycat(char *mode, int argc, char *argv[]) {
    FILE *f;
    FILE *write = fopen("testout.c", "w");
    signed char c;

    while(--argc > 0) 
        if((f = fopen(*++argv, mode)) != NULL)
            while(( c=getc(f) ) != EOF)
                putc(c, write);
        else
            fprintf(stderr, "mycat failed with file %s", *argv);

    fclose(f);
    fclose(write);
}

int main (int argc, char *argv[])
{
    mycat("r",argc, argv);
}

