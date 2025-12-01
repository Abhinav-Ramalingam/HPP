#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>
#include <pthread.h>

#define G(N) (100.0 / (N))
#define EPSILON_0 1e-3


typedef struct
{
    double *x, *y;
    double *mass;
    double *vx, *vy;
    double *brightness;
} particle_t;

typedef struct
{
    int start, end, N;
    double delta_t, G_const;
    particle_t *particles;
    double *net_ax, *net_ay;
    pthread_mutex_t *mutex;
} thread_data_t;

void read_input(char *filename, particle_t *particles, int *N);
void write_output(char *filename, particle_t particles, int N);
static double get_wall_seconds();
void *compute_forces(void *arg);

int main(int argc, char *argv[])
{
    if (argc != 7)
    {
        fprintf(stderr, "Usage: %s N filename nsteps delta_t graphics n_threads\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);
    char *input_file = argv[2];
    int num_steps = atoi(argv[3]);
    double delta_t = atof(argv[4]);
    int graphics_flag = atoi(argv[5]);
    int n_threads = atoi(argv[6]);

    particle_t particles;
    particles.x = (double *)malloc(N * sizeof(double));
    particles.y = (double *)malloc(N * sizeof(double));
    particles.mass = (double *)malloc(N * sizeof(double));
    particles.vx = (double *)malloc(N * sizeof(double));
    particles.vy = (double *)malloc(N * sizeof(double));
    particles.brightness = (double *)malloc(N * sizeof(double));

    if (!particles.x || !particles.y || !particles.mass || !particles.vx || !particles.vy || !particles.brightness)
    {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    read_input(input_file, &particles, &N);

    double start_time = get_wall_seconds();
    const double G_const = G(N);

    pthread_t threads[n_threads];
    thread_data_t thread_data[n_threads];
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

    for (int t = 0; t < num_steps; t++)
    {
        double *net_ax = (double *)calloc(N, sizeof(double));
        double *net_ay = (double *)calloc(N, sizeof(double));

        int chunk_size = N / n_threads;
        for (int i = 0; i < n_threads; i++)
        {
            thread_data[i].start = i * chunk_size;
            thread_data[i].end = (i == n_threads - 1) ? N : (i + 1) * chunk_size;
            thread_data[i].N = N;
            thread_data[i].delta_t = delta_t;
            thread_data[i].G_const = G_const;
            thread_data[i].particles = &particles;
            thread_data[i].net_ax = net_ax;
            thread_data[i].net_ay = net_ay;
            thread_data[i].mutex = &mutex;

            pthread_create(&threads[i], NULL, compute_forces, &thread_data[i]);
        }

        for (int i = 0; i < n_threads; i++)
            pthread_join(threads[i], NULL);

        for (int i = 0; i < N; i++)
        {
            particles.vx[i] += net_ax[i] * delta_t;
            particles.vy[i] += net_ay[i] * delta_t;
            particles.x[i] += particles.vx[i] * delta_t;
            particles.y[i] += particles.vy[i] * delta_t;
        }

        free(net_ax);
        free(net_ay);
    }

    double end_time = get_wall_seconds();
    printf("Elapsed time: %f seconds\n", end_time - start_time);

    write_output("result.gal", particles, N);

    free(particles.x);
    free(particles.y);
    free(particles.mass);
    free(particles.vx);
    free(particles.vy);
    free(particles.brightness);

    return 0;
}

void *compute_forces(void *arg)
{
    thread_data_t *data = (thread_data_t *)arg;
    int start = data->start, end = data->end, N = data->N;
    double G_const = data->G_const, delta_t = data->delta_t;
    particle_t *particles = data->particles;
    double *net_ax = data->net_ax, *net_ay = data->net_ay;

    for (int i = start; i < end; i++)
    {
        double pmi = particles->mass[i];
        double temp_ax = 0.0, temp_ay = 0.0;

        for (int j = i + 1; j < N; j++)
        {
            double dx = particles->x[j] - particles->x[i];
            double dy = particles->y[j] - particles->y[i];
            double r2 = dx * dx + dy * dy;
            double r = sqrt(r2);

            double r_plusE0 = r + EPSILON_0;
            double denom_inv = 1.0 / (r_plusE0 * r_plusE0 * r_plusE0);
            double force_magnitude = G_const * denom_inv;
            double fx = force_magnitude * dx;
            double fy = force_magnitude * dy;

            double pmj = particles->mass[j];

            temp_ax += fx * pmj;
            temp_ay += fy * pmj;

            pthread_mutex_lock(data->mutex);
            net_ax[j] -= fx * pmi;
            net_ay[j] -= fy * pmi;
            pthread_mutex_unlock(data->mutex);
        }

        net_ax[i] += temp_ax;
        net_ay[i] += temp_ay;
    }

    return NULL;
}

void read_input(char *filename, particle_t *particles, int *N)
{
    FILE *file = fopen(filename, "rb");
    if (file == NULL)
    {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(1);
    }

    for (int i = 0; i < *N; i++)
    {
        fread(&particles->x[i], sizeof(double), 1, file);
        fread(&particles->y[i], sizeof(double), 1, file);
        fread(&particles->mass[i], sizeof(double), 1, file);
        fread(&particles->vx[i], sizeof(double), 1, file);
        fread(&particles->vy[i], sizeof(double), 1, file);
        fread(&particles->brightness[i], sizeof(double), 1, file);
    }

    fclose(file);
}

void write_output(char *filename, particle_t particles, int N)
{
    FILE *file = fopen(filename, "wb");
    if (file == NULL)
    {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(1);
    }

    for (int i = 0; i < N; i++)
    {
        fwrite(&particles.x[i], sizeof(double), 1, file);
        fwrite(&particles.y[i], sizeof(double), 1, file);
        fwrite(&particles.mass[i], sizeof(double), 1, file);
        fwrite(&particles.vx[i], sizeof(double), 1, file);
        fwrite(&particles.vy[i], sizeof(double), 1, file);
        fwrite(&particles.brightness[i], sizeof(double), 1, file);
    }

    fclose(file);
}

static double get_wall_seconds()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + (double)tv.tv_usec / 1000000;
}
