#include <stdio.h>

typedef struct cadastro{
    char nome[20];
    int idade;
}cadastro;

void preencher(cadastro *cliente){
    printf("Nome: ");
    gets(cliente->nome);
    printf("Idade: ");
    scanf("%d",&cliente->idade);
}

void imprimir(cadastro *cliente){
    printf("Nome: %s, idade: %d", cliente->nome,cliente->idade);
}

int main(){
    cadastro cliente;
    preencher(&cliente);
    imprimir(&cliente);
return 0;}


