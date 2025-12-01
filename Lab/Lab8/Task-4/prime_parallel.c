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
    if (argc != 2) {
        printf("Usage: %s <M>\n", argv[0]);
        return 1;
    }

    int M = atoi(argv[1]);
    if (M < 2) {
        printf("No primes in the given range.\n");
        return 0;
    }

    pthread_t thread_A, thread_B;
    int half = M * 0.5;
    int range_A[2] = {2, half};
    int range_B[2] = {half + 1, M};

    double start_time = get_wall_seconds();
    
    pthread_create(&thread_A, NULL, the_thread_func, range_A);
    pthread_create(&thread_B, NULL, the_thread_func, range_B);

    int *count_A, *count_B;
    pthread_join(thread_A, (void**)&count_A);
    pthread_join(thread_B, (void**)&count_B);

    int total_count = *count_A + *count_B;
    free(count_A);
    free(count_B);

    double end_time = get_wall_seconds();
    
    printf("Number of primes up to %d: %d\n", M, total_count);
    printf("Execution time: %f seconds\n", end_time - start_time);

    return 0;
}
