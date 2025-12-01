#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int is_prime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <M> <num_threads>\n", argv[0]);
        return 1;
    }

    int M = atoi(argv[1]);
    int num_threads = atoi(argv[2]);

    if (M < 2 || num_threads < 1) {
        printf("Invalid input. M must be >= 2 and num_threads must be >= 1.\n");
        return 0;
    }

    int total_count = 0;
    double start_time = omp_get_wtime();
    
    #pragma omp parallel num_threads(num_threads)
    {
        int local_count = 0;
        #pragma omp for schedule(dynamic, 10)
        for (int n = 2; n <= M; n++) {
            if (is_prime(n)) local_count++;
        }
        
        #pragma omp atomic
        total_count += local_count;
    }

    double end_time = omp_get_wtime();
    
    printf("Number of primes up to %d: %d\n", M, total_count);
    printf("Execution time: %f seconds\n", end_time - start_time);

    return 0;
}
