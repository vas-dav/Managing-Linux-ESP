CC=gcc
CFLAGS=-I.
DEPS = prompt.h random_data.h common.h

main: main.c prompt.c random_data.c
	$(CC) -o random main.c prompt.c random_data.c

preproc: main.c prompt.c random_data.c
	$(CC) -E main.c prompt.c random_data.c

clean:
	rm -f *.o