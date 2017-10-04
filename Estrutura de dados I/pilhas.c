#include<stdio.h>

    int pilha[20];
    int pos=0;

void push (int valor){
    pilha[pos] =  valor;
    pos++;
    return;
}



//#remove o ultimo valor de uma pilha
int  pop(){
    return (pilha[--pos]);
}

//#toopo da pilha
int stacktop (){
        return pilha[pos];
}

//#tamahho da pilha
int size(){
    return pos;
}

int main(){
    printf("\nColocar dados na pilha");
    push(10);
    push(20);
    push(35);

    printf("\n\nTamanho da pilha %d\n", size());
}

