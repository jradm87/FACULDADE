#include<stdio.h>
#include<locale.h>

int main(){

    int conta[10];
    float salario[5];

	setlocale (LC_ALL, "Portuguese");
    printf("O endere�o da matriz conta � %x\n", conta);
    printf("O endere�o da matriz sal�rio � %x\n", salario);

}
