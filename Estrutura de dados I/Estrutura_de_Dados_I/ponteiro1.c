#include<stdio.h>
#include<locale.h>

int main(){
    int *ptr; //declaração de um variável ponteiro
    int conta = 1;

	setlocale (LC_ALL, "Portuguese");
    ptr = &conta;
    printf("Valor de ptr %x\n", ptr);
    printf("Valor de conta %d\n", conta);
    printf("Endereço de conta %x\n", &conta);

}
