#include <stdio.h>
#include <pthread.h>

void* the_thread_func(void* arg) {
  double* double_data = (double*) arg;
  printf("The array elements are:\n");
  printf("%lf, %lf, %lf\n", double_data[0], double_data[1], double_data[2]);
  return NULL;
}

int main() {
  printf("This is the main() function starting.\n");

  double data_for_thread[3];
  data_for_thread[0] = 5.7;
  data_for_thread[1] = 9.2;
  data_for_thread[2] = 1.6;

  double data_for_thread_B[3];
  data_for_thread_B[0] = 3.1;
  data_for_thread_B[1] = 7.4;
  data_for_thread_B[2] = 8.8;

  /* Start first thread. */
  pthread_t thread;
  printf("The main() function now calling pthread_create() for the first thread.\n");
  pthread_create(&thread, NULL, the_thread_func, data_for_thread);

  /* Start second thread. */
  pthread_t threadB;
  printf("The main() function now calling pthread_create() for the second thread.\n");
  pthread_create(&threadB, NULL, the_thread_func, data_for_thread_B);

  printf("This is the main() function after both threads are created.\n");

  /* Wait for both threads to finish. */
  printf("The main() function now calling pthread_join() for the first thread.\n");
  pthread_join(thread, NULL);

  printf("The main() function now calling pthread_join() for the second thread.\n");
  pthread_join(threadB, NULL);

  return 0;
}
