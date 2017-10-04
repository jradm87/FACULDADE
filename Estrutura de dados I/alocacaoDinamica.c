#include <stdio.h>
#include <stdlib.h>

int main(void){
/*não esquecer de usar casting*/

    int *p = (int *) malloc(sizeof(int));

    if (p == NULL){
        printf("Estouro de buffer, sem memória disponivel");
    }
    //size_t é um tipo de dado inteiro positivo.

    printf("%i", *p);


    return 0;
}
