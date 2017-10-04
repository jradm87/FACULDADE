#include<stdio.h>
#include<locale.h>

int main(){
    float x = 15.4, y;
    float *p;

    p = &x;

    y = *p;

	setlocale (LC_ALL, "Portuguese");
    printf("O valor de x é %f e seu endereço %x\n", x, &x);
    printf("O valor de p é %x\n", p);
    printf("O valor de y é %f\n", y);
}
