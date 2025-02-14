#include <stdio.h>
#include <stdlib.h>

// Particle structure
typedef struct {
    double x, y;
    double mass;
    double vx, vy;
    double brightness;
} Particle;

// Function prototype
void read_input(char *filename, Particle **particles, int N);

// Main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s N filename\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);   // Number of particles
    char *input_file = argv[2];  // File containing particle data
    Particle *particles;

    // Read input file (particle data)
    read_input(input_file, &particles, N);

    // Print the particles read from input file
    printf("Particles in %s:\n", input_file);
    for (int i = 0; i < N; i++) {
        printf("Particle %d: x = %lf, y = %lf, mass = %lf, vx = %lf, vy = %lf, brightness = %lf\n",
               i, particles[i].x, particles[i].y, particles[i].mass,
               particles[i].vx, particles[i].vy, particles[i].brightness);
    }

    // Free allocated memory
    free(particles);
    return 0;
}

// FUNCTION: Read the Particle data from the input file (binary)
void read_input(char *filename, Particle **particles, int N) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(1);
    }

    // Allocate memory for the particles
    *particles = (Particle *)malloc(N * sizeof(Particle));
    if (*particles == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }

    // Read the particles' data from the file
    fread(*particles, sizeof(Particle), N, file);

    fclose(file);
}
