#include <stdio.h>
#include <stdlib.h>

int main(void){
/*n�o esquecer de usar casting*/

    int *p = (int *) malloc(sizeof(int));

    if (p == NULL){
        printf("Estouro de buffer, sem mem�ria disponivel");
    }
    //size_t � um tipo de dado inteiro positivo.

    printf("%i", *p);


    return 0;
}
