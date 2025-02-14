# Compiler settings
CC = gcc
CFLAGS = -Wall

# Target executable names
TARGETS = mallocycode regularcode sleepycode threadedcode

# Source files
SRCS = mallocycode.c regularcode.c sleepycode.c threadedcode.c

# Default target
all: $(TARGETS)

# Compile each source file into its corresponding executable
mallocycode: mallocycode.c
	$(CC) $(CFLAGS) mallocycode.c -o mallocycode

regularcode: regularcode.c
	$(CC) $(CFLAGS) regularcode.c -o regularcode

sleepycode: sleepycode.c
	$(CC) $(CFLAGS) sleepycode.c -o sleepycode

threadedcode: threadedcode.c
	$(CC) $(CFLAGS) threadedcode.c -o threadedcode -lpthread   

# Clean all generated files
clean:
	rm -f $(TARGETS)

# Run all targets
run: $(TARGETS)
	./mallocycode
	./regularcode
	./sleepycode
	./threadedcode

# Run all targets with time (multiple runs to record lowest user time)
runtask0: $(TARGETS)
	@echo "Running mallocycode 5 times..."
	@for i in {1..5}; do \
		echo "Run $$i:"; \
		time ./mallocycode; \
	done
	@echo "Running regularcode 5 times..."
	@for i in {1..5}; do \
		echo "Run $$i:"; \
		time ./regularcode; \
	done
	@echo "Running sleepycode 5 times..."
	@for i in {1..5}; do \
		echo "Run $$i:"; \
		time ./sleepycode; \
	done
	@echo "Running threadedcode 5 times..."
	@for i in {1..5}; do \
		echo "Run $$i:"; \
		time ./threadedcode; \
	done
