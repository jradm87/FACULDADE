#include<stdio.h>
#include<locale.h>

int main(){

    int conta[10];
    float salario[5];

	setlocale (LC_ALL, "Portuguese");
    printf("O endereço da matriz conta é %x\n", conta);
    printf("O endereço da matriz salário é %x\n", salario);

}
