#include<stdio.h>
#include<locale.h>

int main(){
    int *ptr; //declara��o de um vari�vel ponteiro
    int conta = 1;

	setlocale (LC_ALL, "Portuguese");
    ptr = &conta;
    printf("Valor de ptr %x\n", ptr);
    printf("Valor de conta %d\n", conta);
    printf("Endere�o de conta %x\n", &conta);

}
