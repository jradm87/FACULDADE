#include<stdio.h>

void soma(int a, int b, int *r){
    *r = a + b;
}

int main(){
    int num1 = 50, num2 = 68, *resultado;

    soma(num1, num2, &resultado);
    printf("%d mais %d eh %d\n", num1, num2, resultado);

    return 0;
}
