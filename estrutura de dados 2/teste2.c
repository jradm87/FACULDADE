#include <stdio.h>
#define TAM   12

char arestas[TAM];

typedef struct ponto
{
    int x, y; // coordenada (x, y)
    struct ponto * proximo; // ponteiro para o próximo
} t_ponto;


int main(){

    t_ponto *ini_ponto; // ponteiro para a struct ponto
    t_ponto *proximo_ponto; // ponteiro para o próximo

    int i;
 for (i = 0; i < TAM; i++) {
        arestas[i] = "ABC";
    }
}
