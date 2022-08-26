#include <stdio.h>
#include "utils.h"

// 1.5.3 Line Counting
void countlines(){
    char c;
    int ncount = 0;

    while((c = getchar()) != ',')
        if(c == NEWLINE) 
            ncount++;

    printf("%d\n", ncount + 1); // +1 for the last line ending in ,
}

// 1-9
void minblanks()
{
    char c;
    int spacecount = 0;

    while((c = getchar()) != EOF){
        if(c == ' ')
            if(spacecount > 0)
                continue;
            else
                spacecount++;
        else
            spacecount = 0;

        putchar(c);
    }
}

// 1-10
void escapetb(){
    char c;

    while((c = getchar()) != EOF)
    {
        if(c != TAB && c != '\b')
            putchar(c);
        else
            if(c == TAB) 
                printf("\\t");
            else
                printf("\\b");
    }
}

// 1.5.4
void wc()
{
    int chars = 0;
    int words = 1;
    int lines = 1;
    char c, prevc;

    while((c = getchar()) != ','){
        chars++;

        if(c == NEWLINE)
            lines++;

        if(c == ' ' || c == NEWLINE || c == TAB)
            if(prevc != ' ' && prevc != NEWLINE && prevc != TAB)
                words++;

        prevc = c;
    }

    printf("%d\t%d\t%d", lines, words, chars);
}

// 1-12
void printwordperline()
{
    char c;

    while((c = getchar()) != ','){
        if(c == ' ')
            putchar(NEWLINE);
        else
            putchar(c);
    }
}

int mygetline(char str[], int limit){
    char c;
    int i;

    for(i = 0; i < limit - 1 && (c = getchar()) != ',' && c != NEWLINE; i++)
        str[i] = c;

    for(; str[i] == ' ' || str[i] == TAB; i--); // 1-18 Remove trailing white space and empty lines

    if(c == NEWLINE && i < limit - 1)
        str[i++] = c;

    str[i] = '\0';

    return i;
}

// 1-17
void print20charlines()
{
    char s[1000];
    int l;

    while((l = mygetline(s, 1000)) != 0)
        if (l > 20)
            printf("%s", s);
}

// 1-22
void foldlines(int limit){
    char c;
    int i = 0;

    while((c = getch()) != ','){
        if(++i == limit){
            i = 1;
            putchar(NEWLINE);
            putchar(c);
        }
        else
            putchar(c);
    }
}

int main (int argc, char *argv[])
{

    foldlines(10);
    return 0;
}
