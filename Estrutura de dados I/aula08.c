#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

/*
vetor din�mico
definir o tamanho do vetor em tempo de execu��o e n�o compila��o
*/

int main(){
    int tam, i;
    int *vetor;

    setlocale(LC_ALL, "Portuguese");

    printf("Escolha o tamanho do vetor");
    scanf("%d",&tam);

    vetor = (int *)malloc(sizeof(int)*tam);

    for (i = 0; i < tam; i++){
        vetor[i] = pow(2, i);
        printf("\n\nposi��o %d:\t %d\n",i,vetor[i]);
    }

    printf("\n\n[");
    for (i = 0; i < tam; i++){
        printf("%d ",vetor[i]);
    }
    printf("]\n\n");
    system("Pause");

}






