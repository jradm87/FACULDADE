#include <stdio.h>
#define TAM   12

char arestas[TAM];

typedef struct ponto
{
    int x, y; // coordenada (x, y)
    struct ponto * proximo; // ponteiro para o pr�ximo
} t_ponto;


int main(){

    t_ponto *ini_ponto; // ponteiro para a struct ponto
    t_ponto *proximo_ponto; // ponteiro para o pr�ximo

    int i;
 for (i = 0; i < TAM; i++) {
        arestas[i] = "ABC";
    }
}
