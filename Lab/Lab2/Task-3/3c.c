#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    if ((fabs(a) > fabs(b) && fabs(a) < fabs(c)) || (fabs(a) > fabs(c) && fabs(a) < fabs(b)))
        printf("%lf\n", a);
    else if ((fabs(b) > fabs(a) && fabs(b) < fabs(c)) || (fabs(b) > fabs(c) && fabs(b) < fabs(a)))
        printf("%lf\n", b);
    else
        printf("%lf\n", c);
    return 0;
}
