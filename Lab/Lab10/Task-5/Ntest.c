#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

long int thread_func_A(long int NA) {
    long int i;
    long int sum = 0;
    for(i = 0; i < NA; i++)
        sum += 7;
    return sum;
}

long int thread_func_B(long int NB) {
    long int i;
    long int sum = 0;
    for(i = 0; i < NB; i++)
        sum += 7;
    return sum;
}

int main(int argc, char** argv) {
    if(argc != 3) {
        printf("Usage: %s <NA> <NB>\n", argv[0]);
        return -1;
    }

    // Read NA and NB from command-line arguments
    long int NA = atol(argv[1]);
    long int NB = atol(argv[2]);

    printf("This is the main() function starting.\n");

    long int result_A;
    long int result_B;

    // Start timer
    double start_time = omp_get_wtime();

    #pragma omp parallel num_threads(2)
    {
        int id = omp_get_thread_num();
        if(id == 0)
            result_A = thread_func_A(NA);
        else
            result_B = thread_func_B(NB);
    }

    // End timer
    double end_time = omp_get_wtime();

    printf("This is the main() function after the parallel block.\n");

    printf("result_A : %ld\n", result_A);
    printf("result_B : %ld\n", result_B);
    long int totalSum = result_A + result_B;
    printf("totalSum : %ld\n", totalSum);

    // Output the elapsed time
    printf("Elapsed time: %f seconds\n", end_time - start_time);

    return 0;
}
