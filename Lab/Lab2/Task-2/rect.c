#include <stdio.h>

int main(){
    int a,b,i,j;
    printf("Enter A and B: ");
    scanf("%d",&a);
    scanf("%d",&b);
    for(i=0;i<b;i++){
        printf("*");
    }
    printf("\n");
    for(i=0;i<a-2;i++){
        printf("*");
        for(j=0;j<b-2;j++){
            printf(".");
        }
        printf("*");
        printf("\n");
    }
    for(i=0;i<b;i++){
        printf("*");
    }
    printf("\n");
    return 0;
}