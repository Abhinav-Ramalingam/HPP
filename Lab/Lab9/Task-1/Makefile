CC = gcc
CFLAGS = -g -o
LIBS = -lpthread

all: threadtest threadtestexit

threadtest: threadtest.c
	$(CC) threadtest.c $(CFLAGS) threadtest $(LIBS)

threadtestexit: threadtestexit.c
	$(CC) threadtestexit.c $(CFLAGS) threadtestexit $(LIBS)

clean:
	rm -f threadtest threadtestexit
