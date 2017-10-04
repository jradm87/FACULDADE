#include <stdio.h>
#include <stdlib.h>


struct str_no{
    char dado;
    int esquerda;
    int direita;
    int pai;

};


struct str_no arvore[7];

void main()
{
    arvore[0].dado = 'A';
    arvore[0].pai = -1;
    arvore[0].esquerda = 1;
    arvore[0].direita = 2;

    arvore[1].dado = 'B';
    arvore[1].pai = 0;
    arvore[1].esquerda = 3;
    arvore[1].direita = 4;

    arvore[2].dado = 'C';
    arvore[2].pai = 0;
    arvore[2].esquerda = 5;
    arvore[2].direita = 6;

    arvore[3].dado = 'D';
    arvore[3].pai = 1;
    arvore[3].esquerda = -1;
    arvore[3].direita = -1;

    arvore[4].dado = 'E';
    arvore[4].pai = 1;
    arvore[4].esquerda = -1;
    arvore[4].direita = -1;

    arvore[5].dado = 'G';
    arvore[5].pai = 2;
    arvore[5].esquerda = -1;
    arvore[5].direita = -1;
int i;
    for (i =0; i < 7; i++){
        printf("Valor: %c\n",arvore[i].dado);
        printf("Pai: %c\n",arvore[i].pai);
        printf("esquerda: %c\n",arvore[i].esquerda);
        printf("Direita: %c\n",arvore[i].direita);

    }

}
