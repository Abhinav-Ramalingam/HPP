CC = gcc
CFLAGS = -Wall
OUTPUT_NORMS = norms
OUTPUT_DENORMS = denorms

# Define optimization flags
OPT_O2 = -O2
OPT_O3 = -O3
OPT_OFAST = -Ofast

# Default target, compile both programs with a flag
all: $(OUTPUT_NORMS) $(OUTPUT_DENORMS)

# Compilation commands for norms.c and denorms.c with -O2, -O3, -Ofast optimization flags
$(OUTPUT_NORMS): norms.c
	$(CC) $(CFLAGS) $(OPT_O2) -o $(OUTPUT_NORMS) norms.c

$(OUTPUT_DENORMS): denorms.c
	$(CC) $(CFLAGS) $(OPT_O2) -o $(OUTPUT_DENORMS) denorms.c

# Targets to toggle compilation with different optimization flags
norms_o2:
	$(CC) $(CFLAGS) $(OPT_O2) -o $(OUTPUT_NORMS) norms.c

norms_o3:
	$(CC) $(CFLAGS) $(OPT_O3) -o $(OUTPUT_NORMS) norms.c

norms_ofast:
	$(CC) $(CFLAGS) $(OPT_OFAST) -o $(OUTPUT_NORMS) norms.c

denorms_o2:
	$(CC) $(CFLAGS) $(OPT_O2) -o $(OUTPUT_DENORMS) denorms.c

denorms_o3:
	$(CC) $(CFLAGS) $(OPT_O3) -o $(OUTPUT_DENORMS) denorms.c

denorms_ofast:
	$(CC) $(CFLAGS) $(OPT_OFAST) -o $(OUTPUT_DENORMS) denorms.c

# Targets to run the programs
run_norms_o2:
	./$(OUTPUT_NORMS)

run_norms_o3:
	./$(OUTPUT_NORMS)

run_norms_ofast:
	./$(OUTPUT_NORMS)

run_denorms_o2:
	./$(OUTPUT_DENORMS)

run_denorms_o3:
	./$(OUTPUT_DENORMS)

run_denorms_ofast:
	./$(OUTPUT_DENORMS)

# Clean the compiled output files
clean:
	rm -f $(OUTPUT_NORMS) $(OUTPUT_DENORMS)
