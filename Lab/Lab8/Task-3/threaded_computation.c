#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>

static double get_wall_seconds() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + (double)tv.tv_usec / 1000000;
}

const long int MAIN = 800000000;
const long int THREAD = 0;

void* the_thread_func(void* arg) {
  long int i;
  long int sum = 0;
  
  // Start timing for thread
  double start_time = get_wall_seconds();
  
  for(i = 0; i < THREAD; i++)
    sum += 7;

  // OK, now we have computed sum. Now copy the result to the location given by arg.
  long int * resultPtr;
  resultPtr = (long int *)arg;
  *resultPtr = sum;
  
  // End timing for thread
  double end_time = get_wall_seconds();
  printf("Time taken by thread to compute sum: %f seconds\n", end_time - start_time);
  
  return NULL;
}

int main() {
  printf("This is the main() function starting.\n");

  long int thread_result_value = 0;

  // Start timing for main
  double main_start_time = get_wall_seconds();
  
  /* Start thread. */
  pthread_t thread;
  printf("the main() function now calling pthread_create().\n");
  pthread_create(&thread, NULL, the_thread_func, &thread_result_value);

  printf("This is the main() function after pthread_create()\n");

  long int i;
  long int sum = 0;
  for(i = 0; i < MAIN; i++)
    sum += 7;

  /* Wait for thread to finish. */
  printf("the main() function now calling pthread_join().\n");
  pthread_join(thread, NULL);

  // End timing for main
  double main_end_time = get_wall_seconds();
  printf("Time taken by main to compute sum: %f seconds\n", main_end_time - main_start_time);

  printf("sum computed by main() : %ld\n", sum);
  printf("sum computed by thread : %ld\n", thread_result_value);
  
  long int totalSum = sum + thread_result_value;
  printf("totalSum : %ld\n", totalSum);

  return 0;
}
