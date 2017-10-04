#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 10

int i,lista[TAMANHO];


void lista_gerar(void);
void imprime(void);


void imprime(void) {
	for (i = 1; i <= 10; i++) {
		printf("numero: %d\n",i);
        sleep(3);
	}
}
void lista_gerar(void)
{
	int i;
	srand(time(NULL));
	for (i = 0;	i < TAMANHO; i++){
		lista[i] = rand()	% 50;
		printf("%d\n",lista[i]);
	}
}

void menu_mostrar(void)
{
	printf("1 - gerar numeros aleatorios\n");
	printf("2 - Sair...\n\n");
}

int main(void)
{
    	int opt = -1;
    	menu_mostrar();
	do {
		scanf("%d",opt);

		switch (opt){
			case 1:
				lista_gerar();
				break;
				}
	} while(opt != 0);
	system("pause");
	return 0;
}

