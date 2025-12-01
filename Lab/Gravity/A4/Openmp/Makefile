CC = gcc
CFLAGS = -Wall -Wextra -O3 -march=native -ffast-math -fopenmp -lm
TARGET = galsim
SRC = galsim.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) 

clean:
	rm -f $(TARGET)
