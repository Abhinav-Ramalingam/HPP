#include <stdio.h>
#include <pthread.h>

void* the_thread_func(void* arg) {
  printf("the_thread_func() starting doing some work.\n");
  long int i;
  double sum = 0;
  for(i = 0; i < 2000000000; i++)
    sum += 1e-7;
  printf("Result of work in the_thread_func(): sum = %f\n", sum);
  return NULL;
}

void* the_thread_func_B(void* arg) {
  printf("the_thread_func_B() starting doing some work.\n");
  long int i;
  double sum = 0;
  for(i = 0; i < 6000000000; i++)
    sum += 1e-7;
  printf("Result of work in the_thread_func_B(): sum = %f\n", sum);
  return NULL;
}

int main() {
  printf("This is the main() function starting.\n");

  pthread_t thread, threadB;

  printf("the main() function now calling pthread_create() for thread A.\n");
  pthread_create(&thread, NULL, the_thread_func, NULL);

  printf("the main() function now calling pthread_create() for thread B.\n");
  pthread_create(&threadB, NULL, the_thread_func_B, NULL);

  printf("This is the main() function after pthread_create()\n");

  printf("main() starting doing some work.\n");
  long int i;
  double sum = 0;
  for(i = 0; i < 4000000000; i++)
    sum += 1e-7;
  printf("Result of work in main(): sum = %f\n", sum);

  printf("the main() function now calling pthread_join() for thread A.\n");
  pthread_join(thread, NULL);

  printf("the main() function now calling pthread_join() for thread B.\n");
  pthread_join(threadB, NULL);

  return 0;
}
