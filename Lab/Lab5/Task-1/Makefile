# Compiler settings
CC = gcc
CFLAGS = -Wall -O3

# Target executable names
TARGETS = array_loop loop_invariants string_loop

# Source files
SRCS = array_loop.c loop_invariants.c string_loop.c

# Default target
all: $(TARGETS)

# Compile each source file into its corresponding executable
array_loop: array_loop.c
	$(CC) $(CFLAGS) array_loop.c -o array_loop

loop_invariants: loop_invariants.c
	$(CC) $(CFLAGS) loop_invariants.c -o loop_invariants

string_loop: string_loop.c
	$(CC) $(CFLAGS) string_loop.c -o string_loop

# Run each program 5 times
runtask1: $(TARGETS)
	@echo "Running array_loop 5 times..."
	@for i in {1..5}; do \
		echo "Run $$i:"; \
		time ./array_loop; \
	done
	@echo "Running loop_invariants 5 times..."
	@for i in {1..5}; do \
		echo "Run $$i:"; \
		time ./loop_invariants; \
	done
	@echo "Running string_loop 5 times..."
	@for i in {1..5}; do \
		echo "Run $$i:"; \
		time ./string_loop; \
	done

# Clean all generated files
clean:
	rm -f $(TARGETS)
