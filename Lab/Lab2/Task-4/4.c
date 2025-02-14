#include <stdio.h>

int main()
{
    double num1, num2, result;
    char op;
    scanf("%lf %c %lf", &num1, &op, &num2);

    switch (op)
    {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0)
                result = num1 / num2;
            else
            {
                printf("Error: Division by zero\n");
                return 1;
            }
            break;
        default:
            printf("Error: Invalid operator\n");
            return 1;
    }

    printf("%lf\n", result);
    return 0;
}
