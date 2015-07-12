CC=gcc
CFLAGS= -c -Wall -g3
SOURCES= test.o exp.o rsa.o
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE= t

all: proyecto KeyGen RSACrypt

KeyGen:  generador.o  exp.o rsa.o
	$(CC) generador.o  exp.o rsa.o -o KeyGen -lm

RSACrypt:  rsacrypt.o  exp.o rsa.o
	$(CC) rsacrypt.o  exp.o rsa.o -o RSACrypt -lm

proyecto: $(SOURCES)
	$(CC) $(SOURCES) -o $(EXECUTABLE) -lm

test.o: test.c
	$(CC) $(CFLAGS) test.c

rsacrypt.o: rsacrypt.c
	$(CC) $(CFLAGS) rsacrypt.c

generador.o: generador.c
	$(CC) $(CFLAGS) generador.c

exp.o: exp.c
	$(CC) $(CFLAGS) exp.c

rsa.o: rsa.c
	$(CC) $(CFLAGS) rsa.c

clean:
	rm *o $(EXECUTABLE) RSACrypt KeyGen