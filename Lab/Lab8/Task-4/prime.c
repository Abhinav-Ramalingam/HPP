#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

static double get_wall_seconds() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + (double)tv.tv_usec / 1000000;
}

int is_prime(int n);
int no_of_primes(int M);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <M>\n", argv[0]);
        return 1;
    }

    int M = atoi(argv[1]);
    if (M < 2) {
        printf("No primes in the given range.\n");
        return 0;
    }

    double start_time = get_wall_seconds();
    int count = no_of_primes(M);
    double end_time = get_wall_seconds();

    printf("Number of primes up to %d: %d\n", M, count);
    printf("Execution time: %f seconds\n", end_time - start_time);

    return 0;
}

int is_prime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int no_of_primes(int M) {
    int count = 0;
    for (int n = 2; n <= M; n++) {
        if (is_prime(n)) count++;
    }
    return count;
}
