#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  if(argc != 2) {
    printf("Please give 1 arg: number of threads to use.\n");
    return -1;
  }
  int nThreads = atoi(argv[1]);

  int i;
  const int n = 1000000;
  double sum = 0.0;
  double* A;
  A = (double*)malloc(n*sizeof(double));

  for (i = 0; i < n ; i++) { 
    A[i] = (double)i;
  }
  
  int repeat;
  
  // Start the timer before the repeat loop
  double start_time = omp_get_wtime();

  for(repeat = 0; repeat < 400; repeat++) {

    #pragma omp parallel  for reduction(+:sum) num_threads(nThreads) 

  
      for (i = 0; i < n; i++) { 
        sum += A[i];
      }

    
  }

  // Stop the timer after the repeat loop
  double end_time = omp_get_wtime();
  printf("Global sum is: %f\n", sum);
  printf("Time: %lf\n", end_time - start_time);

  free(A);

  return 0;
}
