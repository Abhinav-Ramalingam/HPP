#include <stdio.h>
#include <stdlib.h>
#ifdef _OPENMP
#include <omp.h>
#endif


int is_prime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
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

    int total_count = 0;
    double start_time = omp_get_wtime();
    int myID;
    
    #pragma omp parallel
    {
        #ifdef _OPENMP
        myID = omp_get_thread_num();
        #else
        myID = 0;
        #endif
        int local_count = 0;
        #pragma omp for
        for (int n = 2; n <= M; n++) {
            if (is_prime(n)) local_count++;
        }
        
        #pragma omp atomic
        total_count += local_count;  // avoid race condition
    }

    double end_time = omp_get_wtime();
    
    printf("Number of primes up to %d: %d\n", M, total_count);
    printf("Execution time: %f seconds\n", end_time - start_time);

    return 0;
}
