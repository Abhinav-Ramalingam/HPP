#include <stdio.h>

int main() {
    int n;

    printf("Enter the dimension of the matrix: ");
    scanf("%d", &n);

    int matrix[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                matrix[i][j] = 0;
            } else if (i < j) {
                matrix[i][j] = 1;
            } else {
                matrix[i][j] = -1;
            }
        }
    }

    printf("Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
