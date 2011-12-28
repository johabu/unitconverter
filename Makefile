SHELL=/bin/bash
CC=gcc
CFLAGS=-W -Wall -O2
OUTPUT=unitconv

all : objects
	gcc -o unitconv *.o

objects : 
	$(CC) $(CFLAGS) -c *.c

clean :
	rm *.o
