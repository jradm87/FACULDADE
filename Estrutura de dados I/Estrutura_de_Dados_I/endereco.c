#include<stdio.h>
#include<locale.h>

int main(){

    int conta = 1;
    float salario = 4000.00;

	setlocale (LC_ALL, "Portuguese");
    printf("O endere�o de conta � %x\n", &conta);
    printf("O endere�o de sal�rio � %x\n", &salario);

}
