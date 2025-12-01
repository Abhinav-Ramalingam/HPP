#include <stdlib.h>
#include "sort_funcs.h"
#include <omp.h>

typedef int intType;


void bubble_sort(intType* list, int N) {
  int i, j;
  for(i = 0; i < N-1; i++)
    for(j = 1+i; j < N; j++) {
      if(list[i] > list[j]) {
	// Swap
	intType tmp = list[i];
	list[i] = list[j];
	list[j] = tmp;
      }
    }
}

void merge_sort(intType* list_to_sort, int N, int nThreads) {
    if (N <= 1) {
        return; // Base case: single element, no need to sort
    }

    // Split the array into two halves
    int n1 = N / 2;
    int n2 = N - n1;

    intType* list1 = (intType*)malloc(n1 * sizeof(intType));
    intType* list2 = (intType*)malloc(n2 * sizeof(intType));

    for (int i = 0; i < n1; i++) {
        list1[i] = list_to_sort[i];
    }
    for (int i = 0; i < n2; i++) {
        list2[i] = list_to_sort[n1 + i];
    }

    if (nThreads > 1) {
        // Parallelize the recursive calls if there are more than 1 thread available
        #pragma omp parallel
        {
            #pragma omp single
            {
                #pragma omp task if(nThreads > 1)
                merge_sort(list1, n1, nThreads / 2);

                #pragma omp task if(nThreads > 1)
                merge_sort(list2, n2, nThreads / 2);

                #pragma omp taskwait // Ensure both tasks finish before merging
            }
        }

    } else {
        // When only 1 thread is available, do the sorting sequentially
        merge_sort(list1, n1, 1);
        merge_sort(list2, n2, 1);
    }

    // Merge the two sorted halves
    int i1 = 0, i2 = 0, i = 0;
    while (i1 < n1 && i2 < n2) {
        if (list1[i1] < list2[i2]) {
            list_to_sort[i++] = list1[i1++];
        } else {
            list_to_sort[i++] = list2[i2++];
        }
    }
    while (i1 < n1) list_to_sort[i++] = list1[i1++];
    while (i2 < n2) list_to_sort[i++] = list2[i2++];

    // Free the temporary arrays
    free(list1);
    free(list2);
}
