#include <stdio.h>
#include <stdlib.h>

struct No{
	int num;
	struct No *prox;
};
typedef struct No no;

void inicia(no *LISTA);
int menu(void);
void opcao(no *LISTA, int op);
no *criaNo();
void insereFim(no *LISTA);
void insereInicio(no *LISTA);
void exibe(no *LISTA);
void libera(no *LISTA);


int main(void)
{
	no *LISTA = (no *) malloc(sizeof(no));
	if(!LISTA){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	inicia(LISTA);
	int op;

	do{
		op=menu();
		opcao(LISTA,op);
	}while(op);

	free(LISTA);
	return 0;
}

void inicia(no *LISTA)
{
	LISTA->prox = NULL;
}

int menu(void)
{
	int escolha;

	printf("0. Sair\n");
	printf("1. Exibir lista\n");
	printf("2. Adicionar node no inicio\n");
	printf("3. Adicionar node no final\n");
	printf("4. Zerar lista\n");
	printf("Opcao: ");
	scanf("%d", &escolha);

	return escolha;
}

void opcao(no *LISTA, int opt)
{
	switch(opt){
		case 0:
			libera(LISTA);
			break;

		case 1:
			exibe(LISTA);
			break;

		case 2:
			insereInicio(LISTA);
			break;

		case 3:
			insereFim(LISTA);
			break;

		case 4:
			inicia(LISTA);
			break;

		default:
			printf("Comando invalido\n\n");
	}
}

int vazia(no *LISTA)
{
	if(LISTA->prox == NULL)
		return 1;
	else
		return 0;
}


void insereFim(no *LISTA)
{
	no *novo=(no *) malloc(sizeof(no));
	if(!novo){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	printf("Novo elemento: ");
	scanf("%d", &novo->num);
	novo->prox = NULL;

	if(vazia(LISTA))
		LISTA->prox=novo;
	else{
		no *tmp = LISTA->prox;

		while(tmp->prox != NULL)
			tmp = tmp->prox;

		tmp->prox = novo;
	}
}

void insereInicio(no *LISTA)
{
	no *novo=(no *) malloc(sizeof(no));
	if(!novo){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	printf("Novo elemento: ");
	scanf("%d", &novo->num);

	no *oldHead = LISTA->prox;

	LISTA->prox = novo;
	novo->prox = oldHead;
}

void exibe(no *LISTA)
{
	if(vazia(LISTA)){
		printf("Lista vazia!\n\n");
		return ;
	}

	no *tmp;
	tmp = LISTA->prox;

	while( tmp != NULL){
		printf("%5d", tmp->num);
		tmp = tmp->prox;
	}
	printf("\n\n");
}

void libera(no *LISTA)
{
	if(!vazia(LISTA)){
		no *proxNo, *atual;

		atual = LISTA->prox;
		while(atual != NULL){
			proxNo = atual->prox;
			free(atual);
			atual = proxNo;
		}
	}
}
