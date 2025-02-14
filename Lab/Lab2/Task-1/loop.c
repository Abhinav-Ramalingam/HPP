#include <stdio.h>

int main(){
    int i;

    //FOR LOOP
    printf("For Loop:\n");
    for (i=100; i >= 0; i-=2){
        printf("%d ",i);
    }
    printf("\n\n");

    //WHILE LOOP
    printf("While Loop:\n");
    i=100;
    while(i>=0){
        printf("%d ",i);
        i-=2;
    }
    printf("\n\n");

    //DO WHILE LOOP
    printf("Do-While Loop:\n");
    i=100;
    do{
        printf("%d ",i);
        i-=2;
    }while(i>=0);
    printf("\n\n");

    return 0;
}