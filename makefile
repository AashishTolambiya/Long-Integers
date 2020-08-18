a.out : 1_main.o 1_impl.o
	gcc 1_main.o 1_impl.o -lncurses

1_main.o: 1_main.c 2_header.h
	gcc -c 1_main.c -lncurses

1_impl.o : 1_impl.c 2_header.h
	gcc -c 1_impl.c -lncurses

