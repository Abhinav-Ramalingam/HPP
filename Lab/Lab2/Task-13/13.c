#include <stdio.h>

int main()
{
    FILE *file;
    char product[50];
    double price;

    file = fopen("data.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    int n;
    fscanf(file, "%d", &n);

    for (int i = 0; i < n; i++)
    {
        fscanf(file, "%s %lf", product, &price);
        printf("%-10s\t%.2lf\n", product, price);
    }

    fclose(file);
    return 0;
}
