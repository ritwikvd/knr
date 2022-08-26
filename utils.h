#define MAX_LINE_LENGTH 1000

enum escapes {NULL_CHAR = '\0', TAB = '\t', NEWLINE = '\n'};

char getch(void);

void ungetch(char);
