#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

/* Function to get the wall time in seconds */
double get_wall_seconds() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + (double)tv.tv_usec / 1000000;
}

/*
 * Sort an array using bubble sort algorithm.
 */

/* Swap values pointed by x and y */
void swap(int *x, int *y)
{
   int tmp;

   tmp = *x;
   *x  = *y;
   *y  = tmp;
}


void print_array(int *a, int n)
{
   for (int i = 0; i < n; i++)
   {
      printf("%d ", a[i]);
   }
   printf("\n");
}


void fill_in_array(int *a, int n)
{
   srand(time(NULL));
   for (int i = 0; i < n; ++i)
   {
      a[i] = rand() % n;
   }
}


void bubble_sort(int *a, int n)
{
   int swapped = 0;

   for (int i = 0; i < n; ++i)
   {
      swapped = 0;
      // avoid looking at the last n-1 items when running for the n-th time
      for (int k = 1; k < n-i; ++k)
      {
         if (a[k] < a[k - 1])
         {
            swap(&a[k], &a[k - 1]);
            swapped = 1;
         }
      }
      if (swapped == 0)
          break;
   }
}


int main(int argc, char const *argv[])
{
   int n;

   if (argc != 2)
   {
      printf("Usage: %s n\n", argv[0]);
      return -1;
   }
   n = atoi(argv[1]);
   int *a = malloc(n * sizeof(int));
   fill_in_array(a, n);

   printf("Array is created.\n");

   double start_time = get_wall_seconds();  // Start time

   bubble_sort(a, n);

   double end_time = get_wall_seconds();  // End time

   printf("Array is sorted!\n");

   printf("Wall time for sorting: %.6f seconds\n", end_time - start_time);

   return 0;
}
