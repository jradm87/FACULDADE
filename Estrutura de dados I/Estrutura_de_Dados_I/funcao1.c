#include<stdio.h>
#include<locale.h>

void troca_valores(int *a, int *b){
    int temp;
    temp = *a; //armazena temporariamente o valor apontado por a
    *a = *b;   //atribui o valor de b para a
    *b = temp; //atribui o valor de a para b
}

int main(){
    int num1 = 50, num2 = 68;

	setlocale (LC_ALL, "Portuguese");
    troca_valores(&num1, &num2);
    printf("Num1 cont�m %d e Num2 cont�m %d\n", num1, num2);
}
