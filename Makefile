pg: pg.c
	clang -o pg pg.c && ./pg

ch1: ch1-tutorial.c utils.h
	clang -o ch1 ch1-tutorial.c getch.c && ./ch1

ch2: ch2-toe.c utils.h
	clang -o ch2 ch2-toe.c && ./ch2

ch4: ch4-funcs.c utils.h
	clang -o ch4 ch4-funcs.c && ./ch4

ch5: ch5-pointers.c getch.c utils.h
	clang -o ch5 ch5-pointers.c getch.c && ./ch5

ch6: ch6-structs.c getch.c utils.h
	clang -o ch6 ch6-structs.c getch.c && ./ch6

ch7: ch7-io.c getch.c utils.h
	clang -o ch7 ch7-io.c getch.c && ./ch7

ch8: ch8-unix.c utils.h
	clang -o ch8 ch8-unix.c && ./ch8
