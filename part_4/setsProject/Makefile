all: sets_client

sets_client: sets_client.o sets.o
	gcc sets_client.o sets.o -o sets_client

sets_client.o: sets_client.c sets.h
	gcc -ansi -Wall -pedantic-errors -Werror -c sets_client.c

sets.o: sets.c sets.h
	gcc -ansi -Wall -pedantic-errors -Werror -c sets.c
