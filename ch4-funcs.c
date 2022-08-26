#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include "utils.h"

int mygetline(char s[]){
    char c;
    int i = 0;

    while((c = getchar()) != NEWLINE && c != EOF)
        s[i++] = c;

    s[i] = '\0';

    return c == '\n' ? i > 0? i : 1: 0;
}

int strindex(char a[], char b[]){
    int i, j, k;

    for(i = 0; a[i] != NULL_CHAR; i++){
        for(j = i, k = 0; b[k] != NULL_CHAR && a[j] == b[k]; j++, k++);

        if(b[k] == NULL_CHAR)
            return i;
    }

    return -1;
}

// 4-1
int strrindex(char a[], char b[]){
    int i, j, k;

    for(i = strlen(a) - 1; i >= 0; i--){
        for(j = i, k = strlen(b) - 1; k >= 0 && a[j] == b[k]; j--, k--);

        if(k == -1)
            return j + 1;
    }

    return -1;
}

// 4.1
void mygrep(){
    char s[MAX_LINE_LENGTH]; 
    char word[] = "test";

    while(mygetline(s))
        if(strindex(s, word) != -1)
            printf("%s\n", s);
}

// 4-2 buggy too bored to fix
double myatof(char s[]){
    int i = 0;
    int sign = 1;
    double num, power;

    while(s[i] == ' ') // Remove leading whitespace
        i++;

    if(s[i] == '-')
        sign = -1;

    for(num = 0; isdigit(s[i]); i++)
        num = 10 * num + s[i] - '0';

    if(s[i] == '.')
        i++;

    for(power = 1; isdigit(s[i]); i++, power *= 10)
        num = 10 * num + s[i] - '0';

    if(s[i] == 'e'){
        if(s[++i] == '-')
            power *= pow(10, s[i] - '0');
        else
            power /= pow(10, s[i] - '0');
    }

    return sign * ( num/ power );
}

// 4-13
void recreverse(char s[], int i, int len){
    if(i == len)
        return;

    char c = s[i];
    s[i] = s[len - 1 - i];
    s[len - 1 - i] = c;
    printf("%s\n", s);
    recreverse(s, i + 1, len);
}

int main (int argc, char *argv[])
{
    char s[] = "this is a test";
    recreverse(s, 0, strlen(s));
    printf("%s", s);
    return 0;
}
