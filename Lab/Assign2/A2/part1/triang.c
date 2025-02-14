#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define SIZE 100

void pascals_triangle(int n){
    ll arr[n][n];   
    for (int i = 0; i < n; i++){  
        arr[i][0] = 1;
        arr[i][i] = 1;
        for (int j = 1; j < i; j++){
            arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= i; j++){
            printf("%lld\t", arr[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: %s <number_of_rows>\n", argv[0]);
        return 1;
    }
    ll n = strtoll(argv[1], NULL, 10);
    if (n <= 0)
    {
        printf("InputException: Can only pass a number greater than 0 to %s\n", argv[0]);
        return 1;
    }
    pascals_triangle(n);
    return 0;
}
