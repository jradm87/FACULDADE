#include <stdio.h>
#include <stdlib.h>
#define TAM 12

int arestas[TAM];

int main(){
    int i, j = 1;
    for (i = 0; i < TAM; i++) {
        printf("posicao\n");
        printf("i=%d, j=%d\n",i,j);
        arestas[i] = -1;
        printf("arestas[%d] = %d\n",i,arestas[i]);

        if (j > 3) j = 1;
        printf("i=%d, j=%d\n\n\n",i,j);
    }
}
