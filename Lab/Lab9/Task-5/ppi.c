#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS    4
#define INTERVALS      500000000

void* compute_pi(void* arg) {
    long id = (long)arg;
    double dx = 1.0 / INTERVALS;
    double sum = 0.0;
    int chunk_size = INTERVALS / NUM_THREADS;
    int start = id * chunk_size + 1;
    int end = (id + 1) * chunk_size;

    for (int i = start; i <= end; i++) {
        double x = dx * (i - 0.5);
        sum += dx * 4.0 / (1.0 + x * x);
    }

    double* result = malloc(sizeof(double));
    *result = sum;
    return result;
}

int main(int argc, char* argv[]) {
    pthread_t threads[NUM_THREADS];
    double total_sum = 0.0;
    double* partial_sum;

    for (long t = 0; t < NUM_THREADS; t++) {
        pthread_create(&threads[t], NULL, compute_pi, (void*)t);
    }

    for (long t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], (void**)&partial_sum);
        total_sum += *partial_sum;
        free(partial_sum);
    }

    printf("PI is approx. %.16f\n", total_sum);
    return 0;
}
