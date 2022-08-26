#include <stdio.h>
#include "utils.h"

// 5-3
void mystrcat(char *s, char *t)
{
    for(; *s; s++);
    for(; (*s = *t); s++, t++);
}

// 5-4
int mystrend(char *s, char *t){

    char *p = t;

    for(; *s; s++);
    for(; *t; t++);
    for(; *s == *t; s--, t-- );

    return ++t == p ? 1: 0;
}

int main (int argc, char* argv[])
{
    printf("%d\n", argc);
    for(; argc; argc--, argv++)
        printf("%s\t", *argv);
    return 0;
}
