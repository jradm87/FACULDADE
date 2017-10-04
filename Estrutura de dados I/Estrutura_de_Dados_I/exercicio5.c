#include<stdio.h>

int main(){
    int *p1 = 2017;
    printf("Valor de p1: %d\n", p1);

    p1++;
    printf("Valor de p1: %d\n", p1);

    p1 = 2017;
    p1--;
    printf("Valor de p1: %d\n", p1);
}
