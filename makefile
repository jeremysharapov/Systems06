all: linkedlist.c 
	gcc -o list linkedlist.c

run: list
	./list

clean: rm *.o
	rm *.~
