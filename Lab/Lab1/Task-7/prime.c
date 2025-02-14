#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(int n);

int main()
{
    int n, nprimes;
    int *prime;

    do {
        printf("Give a number (>= 2): ");
        scanf("%d", &n);
        if (n < 2) {
            printf("Please enter a number greater than or equal to 2.\n");
        }
    } while (n < 2);

    prime = (int *)malloc(n * sizeof(int));

    int nprime = 0;
    for (int number = 2; number <= n; number++) 
    {
        if (is_prime(number))
        {
            prime[nprime++] = number; 
        }
    }

    for (int i = 0; i < nprime; i++)
        printf("%d\n", prime[i]);

    printf("Total number of primes: %d\n", nprime);

    free(prime);
    return 0;
}

int is_prime(int n)
{
    if (n < 2)
        return 0;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
