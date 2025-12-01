# Define default value for num_threads, can be overridden in the make command
NT ?= 1

all: galsimo

galsim: galsim.c
	gcc -o galsim galsim.c -lm

galsimo: galsim.c
	gcc -O3 -march=native -ffast-math -fopt-info-vec -o galsim galsim.c -lm

galsimp: galsim.c
	gcc -o galsimp galsim.c -lm -lpthread -fopenmp

galsimpo: galsim.c
	gcc -O3 -march=native -ffast-math -o galsimp galsimp.c -lm -lpthread -fopenmp

run: galsim.c
	./galsim 3000 ./input_data/ellipse_N_03000.gal 100 1e-5 0

runp: galsim.c
	./galsimp 3000 ./input_data/ellipse_N_03000.gal 100 1e-5 0 $(NT)

compare:
	./cgf 3000 result.gal ./ref_output_data/ellipse_N_03000_after100steps.gal 

clean:
	rm -f galsim
	rm -f galsimp
