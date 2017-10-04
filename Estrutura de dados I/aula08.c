#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

/*
vetor dinâmico
definir o tamanho do vetor em tempo de execução e não compilação
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
        printf("\n\nposição %d:\t %d\n",i,vetor[i]);
    }

    printf("\n\n[");
    for (i = 0; i < tam; i++){
        printf("%d ",vetor[i]);
    }
    printf("]\n\n");
    system("Pause");

}






