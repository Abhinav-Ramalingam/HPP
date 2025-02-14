#include <stdio.h>
#include <string.h>
#include <sys/resource.h>
#include <sys/time.h>

/*
Find all permutations of a string.

Code: http://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
*/

unsigned long count = 0; // count permutations

void swap(char *x, char *y)
{
   char tmp;
   tmp = *x;
   *x  = *y;
   *y  = tmp;
}

/* Function to print permutations of string
 * This function takes three parameters:
 * 1. String
 * 2. Starting index of the string
 * 3. Ending index of the string. */
void permute(char *a, int l, int r)
{
   if (l == r)
   {
      //printf("%s\n", a);
      count++;
      return;
   }

   for (int i = l; i <= r; i++)
   {
      swap((a + l), (a + i));
      permute(a, l + 1, r);
      swap((a + l), (a + i)); // backtrack
   }
}

/* Function to get the wall time in seconds */
double get_wall_seconds(){
    struct timeval tv;
    gettimeofday(&tv, NULL);
    double seconds = tv.tv_sec + (double)tv.tv_usec/1000000;
    return seconds;
}

/* Function to print the memory usage of the program */
void print_memory_usage() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    printf("Memory usage: %ld kilobytes\n", usage.ru_maxrss);
}

int main(int argc, char const *argv[])
{
   if (argc != 2)
   {
      printf("Usage: %s string\n", argv[0]);
      return -1;
   }

   char str[100];
   strcpy(str, argv[1]);
   int n = strlen(str);
   
   double start_time = get_wall_seconds();
   print_memory_usage();  // Memory usage before permutation calculation

   printf("Permutations of %s are:\n", str);
   permute(str, 0, n - 1);
   
   double end_time = get_wall_seconds();
   printf("In total %ld permutations\n", count);

   printf("Wall time: %f seconds\n", end_time - start_time);
   print_memory_usage();  // Memory usage after permutation calculation

   printf("\n");

   return 0;
}
