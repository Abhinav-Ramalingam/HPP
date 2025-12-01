CC = gcc
CFLAGS = -o
LIBS = -lpthread

all: spinwait synch

spinwait: spinwait.c
	$(CC) spinwait.c $(CFLAGS) spinwait $(LIBS)

spinwaito3: spinwait.c
	$(CC) spinwait.c -O3 $(CFLAGS) spinwaito3 $(LIBS)

synch: synch.c
	$(CC) synch.c $(CFLAGS) synch $(LIBS)

clean:
	rm -f spinwait synch
