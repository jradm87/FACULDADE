#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<locale.h>

//estrutura da fila
struct Fila{
	int dado;
	struct Fila *proximo;
};

//declara��o de vari�veis globais
typedef struct Fila *pt_fila;
pt_fila fila;
int op;

//prototipa��o
void menu_mostrar();
void menu_selecionar(int op);
void inserir(pt_fila fila, int valor);
int remover(pt_fila fila);
void mostrar(pt_fila fila);

//fun��o principal
int main(){
	op = 1;
	
	setlocale(LC_ALL, "Portuguese");
		
	fila = (pt_fila) malloc(sizeof(struct Fila));
	fila->dado = 0;
	fila->proximo = NULL;
	
	while (op != 0){
		system("cls");
		menu_mostrar();
		scanf("%d", &op);
		menu_selecionar(op);
	}
	system("Pause");
	return(0);
}

//fun��o para mostrar o menu de op��es
void menu_mostrar(){
	mostrar(fila);
	system("Pause");
	printf("\n\nEscolha uma das op��es\n\n");
	printf("1) Inserir na fila\n");
	printf("2) Remover da fila\n");
	printf("3) Mostrar fila\n");
	printf("0) Sair\n\n");
}

//fun��o para executar a op��o escolhida no menu
void menu_selecionar(int op){
	int valor;
	switch(op){
		case 1:
			printf("\nDigite um valor: ");
			scanf("%d", &valor);
			inserir(fila, valor);
			break;
		case 2:
			printf("\nO valor %d foi removido.\n",remover(fila));
			break;
		case 3:
			mostrar(fila);
			break;
	}
}

void inserir(pt_fila fila, int dado){
	while(fila->proximo != NULL){
		fila = fila->proximo;
	}
	fila->proximo = (pt_fila) malloc(sizeof(struct Fila));
	fila = fila->proximo;
	fila->dado = dado;
	fila->proximo = NULL;
}

int remover(pt_fila fila){
	int valor;
	pt_fila atual;
	atual = (pt_fila) malloc(sizeof(struct Fila));
	atual = fila;
	if (fila->proximo != NULL){
		fila = fila->proximo;
		atual->proximo = fila->proximo;
	}
	return atual->dado;		
}

//fun��o para exibir o conte�do da fila na tela
void mostrar(pt_fila fila){
	system("cls");
	while (fila->proximo != NULL){
		printf("%d, ", fila->dado);
		fila = fila->proximo;
	}
	printf("%d, ", fila->dado);
}

