#include<stdio.h>

int main(){
    int x;
    int *p1, *p2;

    p1 = &x;
    p2 = p1;

    printf("%p\n", p2);/*
    escreve o endereço de x,
    não seu valor*/
}
