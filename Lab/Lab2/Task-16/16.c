#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    product_t *arr_of_prod = malloc(10 * sizeof(product_t)); // Initial allocation for 10 elements
    if (arr_of_prod == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Error opening file\n");
        free(arr_of_prod);
        return 1;
    }

    int n;
    fscanf(file, "%d", &n);

    if (n > 100)
    {
        printf("This program only allows 100 products. Please limit the number of products to 100.\n");
        fclose(file);
        free(arr_of_prod);
        return 1;
    }

    int allocated = 10;
    int i;
    for (i = 0; i < n; i++)
    {
        if (i >= allocated)
        {
            allocated += 10;
            arr_of_prod = realloc(arr_of_prod, allocated * sizeof(product_t));
            if (arr_of_prod == NULL)
            {
                printf("Memory allocation failed\n");
                fclose(file);
                return 1;
            }
        }

        fscanf(file, "%s %lf", product, &price);
        arr_of_prod[i].price = price;
        strcpy(arr_of_prod[i].name, product);
    }

    printf("Data copied to structure successfully. Now printing...\n");

    printf("Product\t\tPrice\n");
    for (i = 0; i < n; i++)
    {
        printf("%-10s\t%.2lf\n", arr_of_prod[i].name, arr_of_prod[i].price);
    }

    fclose(file);
    free(arr_of_prod);  // Free the dynamically allocated memory
    return 0;
}
