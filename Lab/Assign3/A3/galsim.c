#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>

#define G(N) (100.0 / (N))
#define EPSILON_0 1e-3

typedef struct
{
    double x, y;
    double mass;
    double vx, vy;
    double brightness;
} particle_t;

void read_input(char *filename, particle_t **particles, int *N);
void write_output(char *filename, particle_t *particles, int N);
static double get_wall_seconds();

int main(int argc, char *argv[])
{
    if (argc != 6)
    {
        fprintf(stderr, "Usage: %s N filename nsteps delta_t graphics\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);
    char *input_file = argv[2];
    int num_steps = atoi(argv[3]);
    double delta_t = atof(argv[4]);
    int graphics_flag = atoi(argv[5]);

    particle_t *particles = (particle_t *)malloc(N * sizeof(particle_t));
    particle_t *new_particles = (particle_t *)malloc(N * sizeof(particle_t));
    if (particles == NULL || new_particles == NULL)
    {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    read_input(input_file, &particles, &N);

    double start_time = get_wall_seconds();

    const double G_const = G(N);
    for (int t = 0; t < num_steps; t++)
    {
        double *net_fx = (double *)calloc(N, sizeof(double));
        double *net_fy = (double *)calloc(N, sizeof(double));

        for (int i = 0; i < N; i++)
        {
            double Gm_i = G_const * particles[i].mass;
            for (int j = i + 1; j < N; j++)
            {
                double dx = particles[j].x - particles[i].x;
                double dy = particles[j].y - particles[i].y;
                double r2 = dx * dx + dy * dy;
                double r = sqrt(r2);

                double r_plusE0 = r + EPSILON_0;
                double denominator = r_plusE0 * r_plusE0 * r_plusE0;
                double force_magnitude = Gm_i * particles[j].mass / denominator;

                double fx = force_magnitude * dx;
                double fy = force_magnitude * dy;

                net_fx[i] += fx;
                net_fy[i] += fy;
                net_fx[j] -= fx;
                net_fy[j] -= fy;
            }
        }

        for (int i = 0; i < N; i++)
        {
            double inv_mass = 1.0 / particles[i].mass;
            double ax = net_fx[i] * inv_mass;
            double ay = net_fy[i] * inv_mass;

            double vx = particles[i].vx + ax * delta_t;
            double vy = particles[i].vy + ay * delta_t;
            double x = particles[i].x + vx * delta_t;
            double y = particles[i].y + vy * delta_t;

            new_particles[i].vx = vx;
            new_particles[i].vy = vy;
            new_particles[i].x = x;
            new_particles[i].y = y;
        }

        for (int i = 0; i < N; i++)
        {
            particles[i].vx = new_particles[i].vx;
            particles[i].vy = new_particles[i].vy;
            particles[i].x = new_particles[i].x;
            particles[i].y = new_particles[i].y;
        }

        free(net_fx);
        free(net_fy);
    }

    double end_time = get_wall_seconds();
    printf("Elapsed time: %f seconds\n", end_time - start_time);

    write_output("result.gal", particles, N);

    free(particles);
    free(new_particles);

    return 0;
}

void read_input(char *filename, particle_t **particles, int *N)
{
    FILE *file = fopen(filename, "rb");
    if (file == NULL)
    {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(1);
    }
    fread(*particles, sizeof(particle_t), *N, file);
    fclose(file);
}

void write_output(char *filename, particle_t *particles, int N)
{
    FILE *file = fopen(filename, "wb");
    if (file == NULL)
    {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(1);
    }
    fwrite(particles, sizeof(particle_t), N, file);
    fclose(file);
}

static double get_wall_seconds()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + (double)tv.tv_usec / 1000000;
}
