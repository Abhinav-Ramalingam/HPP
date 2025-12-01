#include <omp.h>
#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40};
    int result = 0; 

    #pragma omp parallel for num_threads(4) lastprivate(result)
    for (int id = 0; id < 4; id++) {
        result = arr[id];  
        printf("Thread %d: result = %d\n", id, result);
    }

    printf("Final result = %d\n", result); 

    return 0;
}
