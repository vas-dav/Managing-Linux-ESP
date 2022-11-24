# Set variables with files and extra flags etc.
CC=gcc
CFLAGS=-I. -g -Wall -Wextra -Wfatal-errors -Wpedantic
DEPS = $(wildcard *.h)
SRC = $(wildcard *.c)
main: $(SRC) 
	$(CC) $(CFLAGS) -o random $(SRC) 
clean:
	rm -f *.o
