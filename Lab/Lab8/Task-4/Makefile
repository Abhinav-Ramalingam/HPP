# Makefile for prime and prime_parallel

CC = gcc
CFLAGS = -o
LIBS = -lpthread

all: prime pprime

prime: prime.c
	$(CC) prime.c $(CFLAGS) prime

pprime: prime_parallel.c
	$(CC) prime_parallel.c $(CFLAGS) pprime $(LIBS)

clean:
	rm -f prime pprime

