CC=gcc
CFLAGS= -c -Wall -g3
SOURCES= test.o exp.o rsa.o
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE= t

all: proyecto

proyecto: $(SOURCES)
	$(CC) $(SOURCES) -o $(EXECUTABLE) -lm

test.o: test.c
	$(CC) $(CFLAGS) test.c

exp.o: exp.c
	$(CC) $(CFLAGS) exp.c

rsa.o: rsa.c
	$(CC) $(CFLAGS) rsa.c

clean:
	rm *o $(EXECUTABLE)