#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//struct with the index
typedef struct {
    int index;  
} thread_info;

void* thread_func(void* arg) {
    thread_info* t_info = (thread_info*)arg;
    printf("Thread %d\n", t_info->index);
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <number of threads>\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);   
    pthread_t threads[N];
    thread_info t_info[N];


    for (int i = 0; i < N; i++) {
        t_info[i].index = i; 

        //pass i-th struct array element to i-th thread
        pthread_create(&threads[i], NULL, thread_func, &t_info[i]); 
    }

    for (int i = 0; i < N; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
