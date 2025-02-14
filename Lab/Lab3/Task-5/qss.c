#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int CmpString(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    char *arrStr[] = {"daa", "cbab", "bbbb", "bababa", "ccccc", "aaaa"};
    int arrStrLen = sizeof(arrStr) / sizeof(char *);

    qsort(arrStr, arrStrLen, sizeof(char *), CmpString);

    for (int i = 0; i < arrStrLen; i++) {
        printf("%s\n", arrStr[i]);
    }

    return 0;
}
