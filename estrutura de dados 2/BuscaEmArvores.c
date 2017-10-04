#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 20

int vec[TAMANHO];
int qtd;

void mostra_vetor();
void alimenta_vetor();
void busca_arvore();
int buscaArvoreBinaria(int vec[], int arg, int tam);

int main(void)
{
	int i, opcao;

	for (i = 0; i < TAMANHO; i++)
		vec[i] = -1;

	do {
		mostra_vetor(vec);
		printf("\n1 - Alimentar vetor de nos indexados");
		printf("\n2 - Fazer busca na arvore binaria");
		printf("\n0 - Sair...\n\n");
		scanf("%d", &opcao);

		switch (opcao)
		{
			case 1:
				alimenta_vetor();
				break;
			case 2:
				busca_arvore();
				break;
		}
	} while (opcao != 0);

	return 0;
}

void mostra_vetor(void)
{
	int i;
	system("cls");
	printf("vec = [ ");

	for (i = 0; i < TAMANHO; i++) {
		if (vec[i] == -1)
			printf("-- ");
		else
			printf("%d ", vec[i]);
	}

	printf("]\n");
}

void alimenta_vetor(void)
{
	int no, valor;
	do {
		mostra_vetor();
		printf("\nInforme o no (-1 volta): ");
		scanf("%d", &no);

		if (no > -1 && no < TAMANHO) {
			printf("Valor do no: ");
			scanf("%d", &valor);
			vec[no] = valor;
		}
	} while (no != -1);
}

void busca_arvore(void)
{
	int valor, no;
	printf("Valor a procurar: ");
	scanf("%d", &valor);

	no = buscaArvoreBinaria(vec, valor, TAMANHO);
	if (no != -1) {
		printf("Encontrado no noh %d", no);
	} else {
		printf("Nao encontrado");
	}
	printf(" em %d iteracoes\n", qtd);
	system("pause");
}

//Função de árvore binária de busca
int buscaArvoreBinaria(int vec[], int arg, int tam)
{
	int no, achou, fim;
	qtd = 0;
	fim = 0;
	no = 0;
	achou = -1;
	while (achou == -1 && fim <= tam && no < tam) {
		qtd++;
		if (arg == vec[no]) {
			achou = no;
		} else if (arg < vec[no]) {
			no = (2 * no) + 1;
		} else {
			no = (2 * no) + 2;
		}
		fim++;
	}
	return achou;
}
