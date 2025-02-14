#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void test_1() {
    // Test 1: Test what happens when a number becomes too large
    //RESULT: Overflow occured after num = 1.000000e+308
    double num = 1.0;
    while (num < INFINITY) {
        printf("num: %e\n", num);
        num *= 100;
        if (num == INFINITY) {
            printf("Overflow occurred! num = %e\n", num);
            break;
        }
    }
}

void test_2() {
    // Test 2: Test producing a “not-a-number” (NaN)
    //RESULT: NaN test prints sqrt(-1) as "nan"
    int num = -1;
    double nan_val = sqrt(num);
    printf("NaN test: sqrt(%d) = %e\n", num, nan_val);
}

void test_3() {
    //Test 3: Test operations on a “inf” or “nan” number
    //REULT: Adding anything to “inf” or “nan” produces the same thing
    double inf = INFINITY;
    double nan_val = sqrt(-1);

    printf("Adding 5 to INFINITY: %lf\n", inf + 5);
    printf("Adding 5 to NaN: %lf\n", nan_val + 5);
}

void test_4() {
    // Test 4: Test adding a very small number to 1 and check if result > 1
    //RESULT: Final epsilon where (1 + epsilon == 1) is 1.110223e-16
    double epsilon = 1.0;
    while ((1.0 + epsilon) != 1.0) {
        printf("epsilon: %e, 1 + epsilon: %e\n", epsilon, 1.0 + epsilon);
        epsilon *= 0.5;
    }

    printf("Final epsilon where (1 + epsilon) == 1: %e\n", epsilon);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <test_number>\n", argv[0]);
        return 1;
    }

    int test_choice = atoi(argv[1]);

    switch (test_choice) {
        case 1:
            test_1();
            break;
        case 2:
            test_2();
            break;
        case 3:
            test_3();
            break;
        case 4:
            test_4();
            break;
        default:
            printf("Invalid test number! Please enter 1, 2, or 3.\n");
            return 1;
    }

    return 0;
}
