#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double** initialization(int);
void fill_vectors(double*, int);
void print_matrix(double**, int);
double trace(double**, int);

// The main program.
int main()
{
    int i, j, n;
    double **matrix;
    double sum;
    
    printf("\nEnter the Dimension for a square matrix: ");
    scanf("%d", &n);
    
    matrix = initialization(n);
    
    // Fill vectors starting from i = 0 to n-1
    for (i = 0; i < n; i++)   // Corrected loop to include the first row
        fill_vectors(matrix[i], n);

    sum = trace(matrix, n);
    print_matrix(matrix, n);
    printf("\nSum of the diagonal elements is: %2.3f", sum);

    // Free allocated memory
    for (i = 0; i < n; i++)
        free(matrix[i]);
    free(matrix);

    return 0;
}


// The initialization routine is supposed to allocate memory for
// a n-by-n matrix and return a pointer to the allocated matrix.
double** initialization(int n)
{
    int i;
    double** matrix;
    matrix = calloc(n, sizeof(double *));
    for (i = 0; i < n; ++i)
        matrix[i] = calloc(n, sizeof(double));
    return (matrix);
}

// The fill_vectors routine is supposed to fill a given vector with
// random numbers ranging from -10 to 10.
void fill_vectors(double* vec, int n)
{
    int i;
    for (i = 0; i < n; i++)
        vec[i] = rand() % 20 - 10;
}

// The print_matrix routine is supposed to print out the elements of
// a given matrix in a nice format using printf.
void print_matrix(double** matrix, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%2.3lf ", matrix[i][j]);
        putchar('\n');
    }
}

// The trace routine is supposed to return the sum of the diagonal
// elements of a given matrix.
double trace(double** matrix, int n)
{
    int i;
    double sum = 0.0;
    for (i = 0; i < n; i++)  // Corrected loop condition to i < n
        sum += matrix[i][i];
    return sum;
}
