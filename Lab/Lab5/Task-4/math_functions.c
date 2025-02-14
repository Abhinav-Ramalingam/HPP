#include <stdio.h>
#include <math.h>

#define USE_METHOD 2

int main(int argc, char **argv)
{
   int i;
   float x;
   for (i=0; i<50000000; i++)
   {
#if USE_METHOD == 0
     x = pow(i, 0.5);
#elif USE_METHOD == 1
     x = sqrt(i);
#elif USE_METHOD == 2
     x = sqrtf(i);
#endif
   }
   printf("%f\n", x);
   return 0;
}
