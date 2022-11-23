# Set variables with files and extra flags etc.
CC=gcc
CFLAGS=-I. -g -Wall -Wextra -Wfatalerros -Wpedantic
DEPS = $(wildcard *.h)
main: main.c prompt.c random_data.c 
	$(CC) $(CFLAGS) -o random main.c prompt.c random_data.c 
clean:
	rm -f *.o
