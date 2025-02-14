#include <stdio.h>

int main()
{
    int num, original_num, reversed_num = 0, remainder;
    scanf("%d", &num);
    original_num = num;

    while (num != 0)
    {
        remainder = num % 10;
        reversed_num = reversed_num * 10 + remainder;
        num /= 10;
    }

    if (original_num == reversed_num)
        printf("it is a palindrome\n");
    else
        printf("it is not a palindrome\n");

    return 0;
}
