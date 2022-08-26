#include <stdio.h>
#include "utils.h"

static char buffer[MAX_LINE_LENGTH];
static int index = 0;

char getch(){
    return index > 0? buffer[index--]: getchar();
}

void ungetch(char c){
    buffer[++index] = c;
}
