#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

double** allocate_matrix(int n);
void deallocate_matrix(double** theMatrix, int n);
void fill_matrix(double** theMatrix, int n);
double get_min_value(double** theMatrix, int n);
double get_max_value(double** theMatrix, int n);
double get_wall_seconds();

int main()
{
  int n;
  printf("\nEnter the dimension for a square matrix:");
  scanf("%d",&n);
  printf("n = %d\n", n);

  double start_time = get_wall_seconds();
  double** matrixA = allocate_matrix(n);
  double** matrixB = allocate_matrix(n);
  double allocation_time = get_wall_seconds() - start_time;

  start_time = get_wall_seconds();
  deallocate_matrix(matrixB, n);
  double deallocation_time = get_wall_seconds() - start_time;

  start_time = get_wall_seconds();
  fill_matrix(matrixA, n);
  double fill_time = get_wall_seconds() - start_time;

  start_time = get_wall_seconds();
  double minValue = get_min_value(matrixA, n);
  double maxValue = get_max_value(matrixA, n);
  double minmax_time = get_wall_seconds() - start_time;

  printf("Min value: %14.9f  Max value: %14.9f\n", minValue, maxValue);

  start_time = get_wall_seconds();
  deallocate_matrix(matrixA, n);
  double total_deallocation_time = get_wall_seconds() - start_time;

  printf("\nTime for allocating memory: %.6f seconds\n", allocation_time);
  printf("Time for deallocating matrixB: %.6f seconds\n", deallocation_time);
  printf("Time for filling matrixA: %.6f seconds\n", fill_time);
  printf("Time for min/max calculation: %.6f seconds\n", minmax_time);
  printf("Time for deallocating matrixA: %.6f seconds\n", total_deallocation_time);

  return 0;
}

double get_wall_seconds(){
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return tv.tv_sec + (double)tv.tv_usec / 1000000;
}

double** allocate_matrix(int n)
{
  double** theMatrix = calloc(n, sizeof(double *));
  for(int i = 0; i < n; i++)
    theMatrix[i] = calloc(n, sizeof(double));
  return theMatrix;
}

void deallocate_matrix(double** theMatrix, int n)
{
  for(int i = 0; i < n; i++)
    free(theMatrix[i]);
  free(theMatrix);
}

void fill_matrix(double** theMatrix, int n)
{
  for(int j = 0; j < n; j++)
    for(int i = 0; i < n; i++)
      theMatrix[i][j] = 10 * (double)rand() / RAND_MAX;
}

double get_max_value(double** theMatrix, int n)
{
  double max = theMatrix[0][0];
  for(int j = 0; j < n; j++)
    for(int i = 0; i < n; i++)
      if(max < theMatrix[i][j])
        max = theMatrix[i][j];
  return max;
}

double get_min_value(double** theMatrix, int n)
{
  double min = theMatrix[0][0];
  for(int j = 0; j < n; j++)
    for(int i = 0; i < n; i++)
      if(min > theMatrix[i][j])
        min = theMatrix[i][j];
  return min;
}
