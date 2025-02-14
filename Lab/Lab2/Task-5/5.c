#include <stdio.h>
#include <math.h>

int main()
{
    double num;
    scanf("%lf", &num);

    if (num < 0)
    {
        printf("No\n");
        return 0;
    }

    double sqrt_num = sqrt(num);
    if (sqrt_num == (int)sqrt_num)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
