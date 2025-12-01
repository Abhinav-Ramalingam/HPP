#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "sort_funcs.h"

typedef int intType;

#define MAX_THREADS 16

typedef struct {
    intType* list;
    int N;
    int depth;
} thread_data_t;

void* merge_sort_thread(void* arg);

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

void merge(intType* list_to_sort, intType* list1, int n1, intType* list2, int n2) {
    int i1 = 0, i2 = 0, i = 0;
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

void merge_sort(intType* list_to_sort, int N, int depth) {
    if(N <= 1) {
        return;
    }

    int n1 = N / 2;
    int n2 = N - n1;

    intType* list1 = (intType*)malloc(n1 * sizeof(intType));
    intType* list2 = (intType*)malloc(n2 * sizeof(intType));

    for(int i = 0; i < n1; i++)
        list1[i] = list_to_sort[i];
    for(int i = 0; i < n2; i++)
        list2[i] = list_to_sort[n1 + i];

    if (depth < MAX_THREADS) {
        pthread_t threads[2];
        thread_data_t data[2] = {{list1, n1, depth + 1}, {list2, n2, depth + 1}};

        for(int i = 0; i < 2; i++) {
            pthread_create(&threads[i], NULL, merge_sort_thread, &data[i]);
        }

        for(int i = 0; i < 2; i++) {
            pthread_join(threads[i], NULL);
        }
    } else {
        merge_sort(list1, n1, depth + 1);
        merge_sort(list2, n2, depth + 1);
    }

    merge(list_to_sort, list1, n1, list2, n2);

    free(list1);
    free(list2);
}

void* merge_sort_thread(void* arg) {
    thread_data_t* data = (thread_data_t*)arg;
    merge_sort(data->list, data->N, data->depth);
    return NULL;
}

int main() {
    intType list[] = {38, 27, 43, 3, 9, 82, 10};
    int N = sizeof(list) / sizeof(list[0]);

    merge_sort(list, N, 0);

    for(int i = 0; i < N; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");

    return 0;
}

Why is parallelizing prime number calculation challenging?

    