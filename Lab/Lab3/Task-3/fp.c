#include <stdio.h>

void print_int_1(int x)
{
    printf("Here is the number: %d\n", x);
}

void print_int_2(int x)
{
    printf("Wow, %d is really an impressive number!\n", x);
}

int main()
{
    void (*print_fn)(int);

    print_fn = print_int_1;
    print_fn(5);

    print_fn = print_int_2;
    print_fn(10);

    return 0;
}