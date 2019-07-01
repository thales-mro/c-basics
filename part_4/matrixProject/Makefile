all: matrix_client

matrix_client: matrix_client.o matrix.o
	gcc matrix_client.o matrix.o -lm -o matrix_client

matrix_client.o: matrix_client.c matrix.h
	gcc -ansi -Wall -pedantic-errors -Werror -c matrix_client.c

matrix.o: matrix.c matrix.h
	gcc -ansi -Wall -pedantic-errors -Werror -c matrix.c
