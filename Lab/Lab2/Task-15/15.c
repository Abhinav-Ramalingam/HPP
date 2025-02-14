#include <stdio.h>
#include <string.h>

typedef struct product
{
    char name[50];
    double price;
} product_t;

int main(int argc, char **argv)
{
    FILE *file;
    char product[50];
    double price;
    product_t arr_of_prod[100];

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    int n;
    fscanf(file, "%d", &n);

    if (n > 100)
    {
        printf("This program only allows 100 products. Please limit the number of products to 100.\n");
        fclose(file);
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        fscanf(file, "%s %lf", product, &price);
        arr_of_prod[i].price = price;
        strcpy(arr_of_prod[i].name, product);
    }

    printf("Data copied to structure successfully. Now printing...\n");

    printf("Product\t\tPrice\n");
    for (int i = 0; i < n; i++)
    {
        printf("%-10s\t%.2lf\n", arr_of_prod[i].name, arr_of_prod[i].price);
    }

    fclose(file);
    return 0;
}
