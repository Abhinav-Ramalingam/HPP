#include <stdio.h>

int main()
{
    double d = 5.5;
    int i = 10;
    char c = 'A';

    printf("Value of double: %f, Address: %p, Size: %zu bytes\n", d, &d, sizeof(d));
    printf("Value of int: %d, Address: %p, Size: %zu bytes\n", i, &i, sizeof(i));
    printf("Value of char: %c, Address: %p, Size: %zu bytes\n", c, &c, sizeof(c));

    return 0;
}
