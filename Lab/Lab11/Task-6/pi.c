/**********************************************************************
 * This program calculates pi using C
 *
 **********************************************************************/
 #include <stdio.h>
 #include <omp.h>
 
 int main(int argc, char *argv[]) {
   int i;
   const int intervals = 500000000;
   double sum = 0.0, dx = 1.0 / intervals;
   
   double start_time = omp_get_wtime();
 
   for (i = 1; i <= intervals; i++) { 
     double x = dx * (i - 0.5);
     sum += dx * 4.0 / (1.0 + x * x);
   }
 
   double end_time = omp_get_wtime();
   
   printf("PI is approx. %.16f\n", sum);
   printf("Time taken: %lf seconds\n", end_time - start_time);
 
   return 0;
 }
 