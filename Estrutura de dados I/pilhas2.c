#include <stdio.h>

#define tam 5

struct Pilha{
    int dados[tam];
    int base,topo;
};

struct Pilha pilha;

void push(int v){
    pilha.dados[pilha.topo];
    pilha.topo++;
}

void pop(){
    int     v;
    v = pilha.dados[pilha.topo-1];
    pilha.dados[pilha.topo-1] = 0;
    return v;
}

int main(){
    int x = 40, y = 50, z =60;
    pilha.base = 0;
    pilha.topo = 0;

    push(z);
    push(y);
    push(x);

    pop(y);

}
