#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <sys/time.h>

double get_wall_seconds() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + (double)tv.tv_usec / 1000000;
}

void do_some_work(long int iterations) {
    printf("Now I am going to do some work...\n");
    long int i;
    long int j = 0;
    for(i = 0; i < iterations; i++) {
        j += 3;
    }
    printf("Work done! My result j = %ld\n", j);
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <iterations> <num_threads>\n", argv[0]);
        return 1;
    } 

    long int iterations = atol(argv[1]);  
    int n = atoi(argv[2]);

    double start_time = get_wall_seconds();

    #pragma omp parallel num_threads(n)
    {
        do_some_work(iterations);
    }

    double end_time = get_wall_seconds();

    printf("Elapsed time: %f seconds\n", end_time - start_time);

    return 0;
}
