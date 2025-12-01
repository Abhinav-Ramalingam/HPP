# Makefile for threaded_computation.c

CC = gcc
CFLAGS = -o threaded_computation
LIBS = -lpthread

threaded_computation: threaded_computation.c
	$(CC) threaded_computation.c $(CFLAGS) $(LIBS)

clean:
	rm -f threaded_computation

run: threaded_computation
	./threaded_computation
