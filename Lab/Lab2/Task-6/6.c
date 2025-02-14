#include <stdio.h>

int main()
{
    int dividend, divisor;
    scanf("%d", &dividend);
    scanf("%d", &divisor);

    printf("Quotient = %d\n", dividend / divisor);
    printf("Remainder = %d\n", dividend % divisor);

    return 0;
}
