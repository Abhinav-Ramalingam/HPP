#include <stdio.h>
#include <omp.h>

int main() {
    omp_set_nested(1);
#pragma omp parallel num_threads(4)
  {
    printf("Outer: Thread %d says hello!\n", omp_get_thread_num());

#pragma omp parallel num_threads(3)
    {
      printf("Inner: Thread %d says hello world!\n", omp_get_thread_num());
    }
  }
  return 0;
}
