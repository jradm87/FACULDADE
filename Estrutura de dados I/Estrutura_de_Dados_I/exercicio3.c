#include<stdio.h>

#define tam 10

struct Pilha{
    int dados[tam];
    int ini;
    int topo;
};

struct Pilha pilha;

void push(int valor){
    if (pilha.topo == tam){
        printf("\Pilha cheia.\n");
        exit(1);
    }else{
        pilha.dados[pilha.topo] = valor;
        pilha.topo++;
    }
}

int pop(){
    int valor;
    if(pilha.ini == pilha.topo){
        printf("\nPilha vazia");
        exit(1);
    }else{
        valor = pilha.dados[pilha.topo-1];
        pilha.dados[pilha.topo-1] = 0;
        pilha.topo--;
        return valor;
    }
}

void display(){
    int i;
    printf("[ ");
    for (i = 0; i < tam; i++){
        printf("%d ", pilha.dados[i]);
    }
    printf("]\n\n");
}

int main(){
    int x = 40, y = 50, z = 60;
    push(z);
    push(y);
    push(x);
    display();
    y = pop();
    z = pop();
    x = pop();
    printf("O valores de x %d, y %d e z %d\n", x, y, z);
}
