CC = gcc
CFLAGS = -Wall
OPT_LEVEL = -O0

all: inline

inline: inline.c
	$(CC) $(CFLAGS) $(OPT_LEVEL) -o inline inline.c

clean:
	rm -f inline

O0:
	$(MAKE) OPT_LEVEL=-O0

O2:
	$(MAKE) OPT_LEVEL=-O2

O3:
	$(MAKE) OPT_LEVEL=-O3
