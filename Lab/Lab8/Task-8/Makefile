CC = gcc
CFLAGS = -o
LIBS = -lpthread

# Default target to build
all: mt mtm

# Compile mutextest.c to create mt
mt: mutextest.c
	$(CC) mutextest.c $(CFLAGS) mt $(LIBS)

# Compile mutextestmutex.c to create mtm
mtm: mutextestmutex.c
	$(CC) mutextestmutex.c $(CFLAGS) mtm $(LIBS)

# Clean the generated files
clean:
	rm -f mt mtm
