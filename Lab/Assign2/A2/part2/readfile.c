#include <stdio.h>

int main() {
    int integer;
    double doubleprecision;
    char character;
    float floatingpoint;

    FILE *file = fopen("little_bin_file", "rb");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    fread(&integer, sizeof(integer), 1, file);   
    fread(&doubleprecision, sizeof(doubleprecision), 1, file);   
    fread(&character, sizeof(character), 1, file);   
    fread(&floatingpoint, sizeof(floatingpoint), 1, file);   
    fclose(file);

    printf("%d\n%lf\n%c\n%f\n",integer, doubleprecision, character, floatingpoint);

    return 0;
}
