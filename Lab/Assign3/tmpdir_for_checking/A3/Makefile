# Makefile for compiling galsim.c into galsim executable

CC = gcc
CFLAGS = -O3 -ftree-vectorize -march=native -funroll-loops -ffast-math

# Target executable
TARGET = galsim

# Source file
SRC = galsim.c

# Default rule to build the target
all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) -lm

# Clean rule to remove generated files
clean:
	rm -f $(TARGET)
