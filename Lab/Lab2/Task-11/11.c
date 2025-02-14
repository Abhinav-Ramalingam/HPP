#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = malloc(10 * sizeof(int));
    int capacity = 10, count = 0, num, sum = 0;
    
    printf("Input: ");
    while (scanf("%d", &num) == 1) {
        if (count == capacity) {
            capacity += 10;
            arr = realloc(arr, capacity * sizeof(int));
        }
        arr[count++] = num;
        sum += num;
    }

    for (int i = 0; i < count; i++)
        printf("%d ", arr[i]);
    printf("\nSum: %d\n", sum);

    free(arr);
    return 0;
}
