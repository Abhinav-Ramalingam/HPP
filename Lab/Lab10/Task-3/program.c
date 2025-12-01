#include <stdio.h>
#include <omp.h>

void thread_func() {
  int thread_id = omp_get_thread_num();
  int num_threads = omp_get_num_threads();
  int max_threads = omp_get_max_threads();
  printf("You can use %d but have only %d currently in your program\n",max_threads, num_threads);

  printf("Yours Threadly,\n %d \n\n", thread_id);
}

int main(int argc, char** argv) {

#pragma omp parallel num_threads(4)
  {
    thread_func();
  }

  return 0;
}
