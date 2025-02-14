#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

/* Function to get wall clock time in seconds and microseconds since the Epoch */
static double get_wall_seconds() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    double seconds = tv.tv_sec + (double)tv.tv_usec / 1000000;
    return seconds;
}

int main(int argc, const char** argv) {
    int N = 100000000;  // Number of iterations
    int i;

    // Addition operation timing
    double startTimeAdd = get_wall_seconds();
    volatile double addResult = 0;
    for(i = 0; i < N; i++) {
        addResult += 1.0 + 0.000001*i;  // Addition operation
    }
    double secondsTakenAdd = get_wall_seconds() - startTimeAdd;
    printf("Addition time: %f seconds\n", secondsTakenAdd);

    // Subtraction operation timing
    double startTimeSub = get_wall_seconds();
    volatile double subResult = 0;
    for(i = 0; i < N; i++) {
        subResult -= 1.0 + 0.000001*i;  // Subtraction operation
    }
    double secondsTakenSub = get_wall_seconds() - startTimeSub;
    printf("Subtraction time: %f seconds\n", secondsTakenSub);

    // Multiplication operation timing
    double startTimeMul = get_wall_seconds();
    volatile double mulResult = 1.0;
    for(i = 0; i < N; i++) {
        mulResult *= 1.0 + 0.000001*i;  // Multiplication operation
    }
    double secondsTakenMul = get_wall_seconds() - startTimeMul;
    printf("Multiplication time: %f seconds\n", secondsTakenMul);

    // Division operation timing
    double startTimeDiv = get_wall_seconds();
    volatile double divResult = 1.0;
    for(i = 0; i < N; i++) {
        divResult /= 1.0 + 0.000001*i;  // Division operation
    }
    double secondsTakenDiv = get_wall_seconds() - startTimeDiv;
    printf("Division time: %f seconds\n", secondsTakenDiv);

    // Print relative speeds
    printf("\nRelative speeds of arithmetic operations:\n");
    printf("Addition: %f\n", secondsTakenAdd);
    printf("Subtraction: %f\n", secondsTakenSub);
    printf("Multiplication: %f\n", secondsTakenMul);
    printf("Division: %f\n", secondsTakenDiv);

    return 0;
}
