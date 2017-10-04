#include<stdio.h>
#include<locale.h>

int main(){

    int conta = 1;
    float salario = 4000.00;

	setlocale (LC_ALL, "Portuguese");
    printf("O endereço de conta é %x\n", &conta);
    printf("O endereço de salário é %x\n", &salario);

}
