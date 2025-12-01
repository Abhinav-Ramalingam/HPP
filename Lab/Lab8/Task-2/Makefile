# Makefile for threadtest1 and threadtest1b

CC = gcc
LIBS = -lpthread

thread_data: thread_data.c
	$(CC) thread_data.c -o thread_data $(LIBS)

thread_data_b: thread_data_b.c
	$(CC) thread_data_b.c -o thread_data_b $(LIBS)

clean:
	rm -f thread_data thread_data_b
