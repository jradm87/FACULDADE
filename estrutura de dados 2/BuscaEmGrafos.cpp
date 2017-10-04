#include <stdio.h>
#include <stdlib.h>

#define TAM   12

int arestas[TAM];
int grafo[TAM][TAM];

int buscaProfundidade(int valor) {
    int pilha[TAM][2], ind = 0;
    int no, i, elem, novo_no;

    if (arestas[0] == valor) return 0;
	
    pilha[ind][1] = 0;  // No atual em processamento
    pilha[ind][2] = 0;  // Posicao do no atual sendo processada
    while (ind >= 0) {
        no = pilha[ind][1];
        novo_no = 0;

        for (i = pilha[ind][2]; i < TAM && grafo[no][i] > 0; i++) {
            elem = grafo[no][i];
            if (arestas[elem] == valor) return elem;

            if (grafo[elem][0] > 0) {
                pilha[ind][2] = i + 1;
                ind++;
                pilha[ind][1] = elem;
                pilha[ind][2] = 0;
                novo_no = 1;
                break;
            }
        }
        if (novo_no == 0) ind--;
    }
    return -1;
}

int buscaLargura(int valor)
{
    int fila[TAM][TAM], ind = 0;
    int no, i, j, n, elem;

    if (arestas[0] == valor)
        return 0;

    for (i = 0; i < TAM; i++)
        for (j = 0; j < TAM; j++)
            fila[i][j] = -1;

    fila[ind][0] = 0;
    while (fila[ind][0] > -1) {
        for (i = 0; i < TAM && fila[ind][i] >= 0; i++) {
            no = fila[ind][i];
            n = 0;

            for (j = 0; j < TAM && grafo[no][j] > 0; j++) {
                elem = grafo[no][j];
                if (arestas[elem] == valor)
                    return elem;
                fila[ind+1][n++] = elem;
            }
        }
        ind++;
    }
    return -1;
}

void defineGrafo()
{
    int i, j = 1;
    for (i = 0; i < TAM; i++) {
        arestas[i] = j++;
        if (j > 3) j = 1;
    }

    for (i = 0; i < TAM; i++)
        for (j = 0; j < TAM; j++)
            grafo[i][j] = 0;

    grafo[0][0] = 1;
    grafo[0][1] = 2;
    grafo[0][2] = 3;

    grafo[1][0] = 4;
    grafo[1][1] = 5;

    grafo[3][0] = 6;
    grafo[3][1] = 7;

    grafo[4][0] = 8;
    grafo[4][1] = 9;

    grafo[6][0] = 10;
    grafo[6][1] = 11;
}

int main()
{
    int valor, prof, larg;

    defineGrafo();

    printf("Digite o valor a procurar no grafo: ");
    scanf("%d", &valor);

    prof = buscaProfundidade(valor);
    larg = buscaLargura(valor);

    printf("Busca em profundidade: encontrado em %d\n", prof);
    printf("Busca em largura.....: encontrado em %d\n", larg);

    return 0;
}

