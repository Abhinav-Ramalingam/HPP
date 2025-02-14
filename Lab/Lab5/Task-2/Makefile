CC = gcc
CFLAGS = -Wall -O3

# Targets
TARGETS = short-circuit bounds

# Default target
all: $(TARGETS)

# Compile short_circuit.c
short_circuit: short-circuit.c
	$(CC) $(CFLAGS) -DFAST=1 -o $@ $<

# Compile bounds.c
bounds: bounds.c
	$(CC) $(CFLAGS) -DFAST=1 -o $@ $<

# Clean up build files
clean:
	rm -f $(TARGETS)
