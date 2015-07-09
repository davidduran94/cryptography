CC=gcc
CFLAGS= -c -Wall -g3
SOURCES= test.o 
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE= t

all: rsa 

rsa: $(SOURCES)
	$(CC) $(SOURCES) -o $(EXECUTABLE) -lm

test.o: test.c
	$(CC) $(CFLAGS) test.c

clean:
	rm *o $(EXECUTABLE)