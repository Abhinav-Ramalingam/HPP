CC = gcc
CFLAGS = -Wall

all: lookup math_functions memset strength_reduction timings

lookup: lookup.c
	$(CC) $(CFLAGS) -o lookup lookup.c

math_functions: math_functions.c
	$(CC) $(CFLAGS) -o math_functions math_functions.c

memset: memset.c
	$(CC) $(CFLAGS) -o memset memset.c

strength_reduction: strength_reduction.c
	$(CC) $(CFLAGS) -o strength_reduction strength_reduction.c

timings: timings.c
	$(CC) $(CFLAGS) -o timings timings.c

clean:
	rm -f lookup math_functions memset strength_reduction timings
