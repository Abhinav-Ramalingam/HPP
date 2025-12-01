CC = gcc
CFLAGS = -Wall -O3
LIBS = -lm -lpthread

all: join joind

join: join.c
	$(CC) $(CFLAGS) -o join join.c $(LIBS)

joind: joind.c
	$(CC) $(CFLAGS) -o joind joind.c $(LIBS)

clean:
	rm -f join joind
