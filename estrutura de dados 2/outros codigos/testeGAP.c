//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Constantes
#define TAMANHO 10


int ordenado[TAMANHO];
int qtd;

int shellSort(int vec[], int tam)
{
    int i, j, valor, qtd = 0;
    int gap = 1;

    do {
        gap = 3 * gap + 1;
    } while (gap < tam);

    do {
        gap /= 3;
        for (i = gap; i < tam; i++) {
            valor = vec[i];
            j = i - gap;
            while (j >= 0 && valor < vec[j]) {
                vec[j + gap] = vec[j];
                j -= gap;
                qtd++;
            }
            vec[j + gap] = valor;
        }
    } while (gap > 1);

    return qtd;
}

int main(void){
    qtd = shellSort(ordenado, TAMANHO);
}

