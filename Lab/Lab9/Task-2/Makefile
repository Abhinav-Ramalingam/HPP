CC = gcc
CFLAGS = -o
LIBS = -lpthread

all: wait_test wait_test_cond

wait_test: wait_test.c
	$(CC) wait_test.c $(CFLAGS) wait_test $(LIBS)

wait_test_cond: wait_test_cond.c
	$(CC) wait_test_cond.c $(CFLAGS) wait_test_cond $(LIBS)

clean:
	rm -f wait_test wait_test_cond
