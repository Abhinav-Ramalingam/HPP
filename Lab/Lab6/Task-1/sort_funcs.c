#include <stdlib.h>
#include "sort_funcs.h"

void bubble_sort(int* list, int N) {
  int i, j;
  for(i = 0; i < N-1; i++)
    for(j = 1+i; j < N; j++) {
      if(list[i] > list[j]) {
        // Swap
        int tmp = list[i];
        list[i] = list[j];
        list[j] = tmp;
      }
    }
}

void merge_sort(int* list_to_sort, int N) {
  if(N == 1) {
    return;
  }

  int n1 = N / 2;
  int n2 = N - n1;

  // CHANGE: Declare list1 and list2 as local stack-allocated arrays
  int list1[n1];  
  int list2[n2];  

  int i;
  for(i = 0; i < n1; i++)
    list1[i] = list_to_sort[i];
  for(i = 0; i < n2; i++)
    list2[i] = list_to_sort[n1 + i];

  merge_sort(list1, n1);
  merge_sort(list2, n2);

  int i1 = 0, i2 = 0;
  i = 0;
  while(i1 < n1 && i2 < n2) {
    if(list1[i1] < list2[i2]) {
      list_to_sort[i] = list1[i1];
      i1++;
    } else {
      list_to_sort[i] = list2[i2];
      i2++;
    }
    i++;
  }

  while(i1 < n1)
    list_to_sort[i++] = list1[i1++];
  while(i2 < n2)
    list_to_sort[i++] = list2[i2++];
}

void mb_sort(int* list_to_sort, int N, int n) {
  if(N <= n) {
    // Call bubble_sort if the list size is smaller than the threshold n
    bubble_sort(list_to_sort, N);
    return;
  }

  if(N == 1) {
    return;
  }

  int n1 = N / 2;
  int n2 = N - n1;

  // Declare list1 and list2 as local stack-allocated arrays
  int list1[n1];  
  int list2[n2];  

  int i;
  for(i = 0; i < n1; i++)
    list1[i] = list_to_sort[i];
  for(i = 0; i < n2; i++)
    list2[i] = list_to_sort[n1 + i];

  mb_sort(list1, n1, n);
  mb_sort(list2, n2, n);

  int i1 = 0, i2 = 0;
  i = 0;
  while(i1 < n1 && i2 < n2) {
    if(list1[i1] < list2[i2]) {
      list_to_sort[i] = list1[i1];
      i1++;
    } else {
      list_to_sort[i] = list2[i2];
      i2++;
    }
    i++;
  }

  while(i1 < n1)
    list_to_sort[i++] = list1[i1++];
  while(i2 < n2)
    list_to_sort[i++] = list2[i2++];
}

void single_merge_sort(int* list_to_sort, int index, int N) {

  if(N == 1) {

    // Only one element, no sorting needed. Just return directly in this case.

    return;

  }

  int n1 = N / 2;

  int n2 = N - n1;

  // Allocate new lists

  int* list = (int*)malloc(N*sizeof(int));

  int i;

  for(i = index; i < index +  N; i++)

    list[i] = list_to_sort[i];

  // Sort list1 and list2

  single_merge_sort(list, 0, n1);

  single_merge_sort(list, n1, n2);

  // Merge!

  int i1 = index;

  int i2 = index + n1;

  i = 0;

  while(i1 < n1 && i2 < n1 + n2) {

    if(list[i1] < list[n1 + i2]) {

      list_to_sort[i] = list[i1];

      i1++;

    }

    else {

      list_to_sort[i] = list[n1 + i2];

      i2++;

    }

    i++;

  }

  while(i1 < n1)

    list_to_sort[i++] = list[i1++];

  while(i2 < n2)

    list_to_sort[i++] = list[n1 + (i2++)];

  free(list);


}