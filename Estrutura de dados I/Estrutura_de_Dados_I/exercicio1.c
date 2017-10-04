#include<stdio.h>

int main(){
    int vetor[10];

    inserir(vetor);
    percorrer(vetor);

    printf("\nFim do programa!\n");
}

void inserir(int v[]){
    int i;
    for (i = 0; i < 10; i++){
        printf("\nDigite o %do valor\n",i+1);
        scanf("%d",&v[i]);
    }
}

void percorrer(int v[]){
    int i;
    for (i = 0; i < 10; i++)
        printf("\n%do valor: %d\n",i+1, v[i]);
    printf("\nFim do vetor\n");
}
