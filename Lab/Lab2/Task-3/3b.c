#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    if (fabs(a) > fabs(b) && fabs(a) > fabs(c))
        printf("%lf\n", a);
    else if (fabs(b) > fabs(c))
        printf("%lf\n", b);
    else
        printf("%lf\n", c);
    return 0;
}
