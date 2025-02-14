#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(int n) {
    if (n < 2) return 1;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return 0;
    return 1;
}

int main() {
    int n, count = 0, size = 10, new_count = 0;
    int *arr = malloc(size * sizeof(int));
    int *new_arr = malloc(size * sizeof(int));
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        if (count == size) {
            size += 10;
            arr = realloc(arr, size * sizeof(int));
        }
        scanf("%d", &arr[count++]);
    }
    for (int i = 0; i < count; i++) {
        if (!is_prime(arr[i])) {
            if (new_count == size) {
                size += 10;
                new_arr = realloc(new_arr, size * sizeof(int));
            }
            new_arr[new_count++] = arr[i];
        }
    }
    for (int i = 0; i < new_count; i++)
        printf("%d ", new_arr[i]);
    printf("\n%d\n", new_count);
    free(arr);
    free(new_arr);
    return 0;
}
