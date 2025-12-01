#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

static double get_wall_seconds() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + (double)tv.tv_usec / 1000000;
}

int is_prime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

void* the_thread_func(void* arg) {
    int* range = (int*)arg;
    int start = range[0], end = range[1];
    int* count = malloc(sizeof(int));
    *count = 0;

    for (int n = start; n <= end; n++) {
        if (is_prime(n)) (*count)++;
    }

    return count;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <M> <N>\n", argv[0]);
        return 1;
    }

    int M = atoi(argv[1]);
    int N = atoi(argv[2]);

    if (M < 2 || N < 1) {
        printf("Invalid input. M must be >= 2 and N must be >= 1.\n");
        return 1;
    }

    pthread_t* threads = malloc(N * sizeof(pthread_t));
    int range_per_thread = M / N;
    int remaining = M % N;

    double start_time = get_wall_seconds();

    // Range Index Assignment
    for (int i = 0; i < N; i++) {
        // range[0] = start, range[1] = end
        int* range = malloc(2 * sizeof(int)); 
        range[0] = i * range_per_thread + 2;
        range[1] = (i == N - 1) ? M : range[0] + range_per_thread - 1;
        if (i == N - 1) {
            range[1] += remaining;
        }

        pthread_create(&threads[i], NULL, the_thread_func, range);
    }

    int total_count = 0;
    for (int i = 0; i < N; i++) {
        int* count;
        pthread_join(threads[i], (void**)&count);
        total_count += *count;
        free(count);  
    }

    free(threads);  

    double end_time = get_wall_seconds();

    printf("Number of primes up to %d: %d\n", M, total_count);
    printf("Execution time: %f seconds\n", end_time - start_time);

    return 0;
}
