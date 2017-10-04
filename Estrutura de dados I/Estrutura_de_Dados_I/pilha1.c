#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

#define TAM 5

void push(int i);
int pop(void);

int *top, *p1, stack[TAM];

int main(){
    int valor;
    top = stack; //top contém o topo da pilha
    p1 = stack; //inicializa p1

	setlocale (LC_ALL, "Portuguese");
    do{
        printf("\nDigite o valor: ");
        scanf("%d", &valor);
        if (valor != 0)
            push(valor);
        else
            printf("\nO valor no topo é %d\n", pop());
    }while (valor != -1);
}

void push(int i){
    p1++;
    if (p1==(top+TAM)){
        printf("Estouro da pilha - overflow");
        exit(1);
    }
    *p1 = i;
}

int pop(){
    if (p1 == top){
        printf("Estouro da pilha - overflow");
        exit(1);
    }
    p1--;
    return *(p1+1);
}
