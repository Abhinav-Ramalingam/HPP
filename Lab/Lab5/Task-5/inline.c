#include <stdio.h>
#include <math.h>

#define INLINE_FUNCTION 1

// Smaller function to test inlining benefits
#if INLINE_FUNCTION
static inline int square(int x) {
    return x * x;
}
#else
int square(int x) {
    return x * x;
}
#endif

int main() {
    int i;
    int result;

    // Test the inlining of a simple square function
    for (i = 0; i < 100000000; i++) {
        result = square(i);
    }

    printf("Final result: %d\n", result);
    return 0;
}
