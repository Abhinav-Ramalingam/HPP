#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* child_thread_func(void* arg) {
    printf("Child thread %d created by thread %lu\n", *(int*)arg, pthread_self());
    return NULL;
}

void* parent_thread_func(void* arg) {
    printf("Parent thread %d created by main thread %lu\n", *(int*)arg, pthread_self());

    pthread_t child1, child2;
    int child_id1 = (*(int*)arg) * 10 + 1;
    int child_id2 = (*(int*)arg) * 10 + 2;

    pthread_create(&child1, NULL, child_thread_func, &child_id1);
    pthread_create(&child2, NULL, child_thread_func, &child_id2);

    pthread_join(child1, NULL);
    pthread_join(child2, NULL);

    return NULL;
}

int main() {
    printf("main() function starting. Thread ID: %lu\n", pthread_self());

    pthread_t thread_A, thread_B;
    int id_A = 1, id_B = 2;

    pthread_create(&thread_A, NULL, parent_thread_func, &id_A);
    pthread_create(&thread_B, NULL, parent_thread_func, &id_B);

    pthread_join(thread_A, NULL);
    pthread_join(thread_B, NULL);

    printf("main() function ending.\n");
    return 0;
}
