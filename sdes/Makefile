CC=gcc
CFLAGS= -c -g3
PFLAGS= -o libraries/
SOURCES= MyPGP.o byte.o sdes.o llave.o
PSOURCES= MyPGP.o libraries/byte.o libraries/sdes.o libraries/llave.o
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE= mypgp

all: mypgp 


mypgp: $(SOURCES)
	$(CC) $(PSOURCES) -o $(EXECUTABLE)

MyPGP.o: MyPGP.c
	$(CC) $(CFLAGS) MyPGP.c

byte.o: libraries/byte.c
	$(CC) $(CFLAGS) libraries/byte.c $(PFLAGS)byte.o

llave.o: libraries/llave.c
	$(CC) $(CFLAGS) libraries/llave.c $(PFLAGS)llave.o

OpMode.o: libraries/OpMode.c
	$(CC) $(CFLAGS) libraries/OpMode.c $(PFLAGS)OpMode.o

sdes.o: libraries/sdes.c
	$(CC) $(CFLAGS) libraries/sdes.c $(PFLAGS)sdes.o


clean:
	rm libraries/*o $(EXECUTABLE)