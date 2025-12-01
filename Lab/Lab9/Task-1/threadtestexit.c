#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* the_thread_func(void* arg) {
  int* p = malloc(3 * sizeof(int));
  if (p == NULL) pthread_exit(NULL);  // Exit thread if memory allocation fails

  p[0] = 10;
  p[1] = 20;
  p[2] = 30;

  pthread_exit(p);  // Return the pointer using pthread_exit
}

int main() {
  printf("This is the main() function starting.\n");

  /* Start thread. */
  pthread_t thread;
  int* result;

  printf("the main() function now calling pthread_create().\n");
  if(pthread_create(&thread, NULL, the_thread_func, NULL) != 0) {
    printf("ERROR: pthread_create failed.\n");
    return -1;
  }

  printf("This is the main() function after pthread_create()\n");

  /* Wait for thread to finish. */
  printf("the main() function now calling pthread_join().\n");
  if(pthread_join(thread, (void**)&result) != 0) {
    printf("ERROR: pthread_join failed.\n");
    return -1;
  }

  /* Access the returned values */
  if (result != NULL) {
    printf("Values returned from the thread: %d, %d, %d\n", result[0], result[1], result[2]);
    free(result);
  }

  return 0;
}
