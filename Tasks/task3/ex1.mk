random: main.o prompt.o random_data.o 
	gcc -o random main.o prompt.o random_data.o

main.o: main.c prompt.h random_data.h 
	gcc -c main.c

prompt.o: prompt.c prompt.h random_data.h common.h
	gcc -c prompt.c
	
random_data.o: random_data.c random_data.h common.h

clean: 
	rm -f main.o prompt.o random_data.o
