#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define SIZE 100

ll factorial(ll n){
    if(n == 0 || n == 1)
        return 1;
    else return n * factorial(n-1);
}

ll combination(ll n, ll k){
    return factorial(n)/(factorial(k) * factorial(n-k));
}

void pascals_triangle(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++){
            printf("%lld\t", combination(i, j));
        }
        printf("\n");
    }
}

int main(int argc, char** argv){
    if (argc != 2) {
        printf("Usage: %s <number_of_rows>\n", argv[0]);
        return 1;  
    } 
    ll n = strtoll(argv[1], NULL, 10);
    if (n <= 0){
        printf("InputExecption: Can only pass a number greater than to 0 to %s\n", argv[0]);
        return 1; 
    }
    pascals_triangle(n);
    return 0;
}