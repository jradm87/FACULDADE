//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Constantes
#define TAMANHO 10

//Variáveis
int lista[TAMANHO];
int ordenado[TAMANHO];
int qtd;

//Prototipação
void menu_mostrar(void);
void lista_mostrar(void);
void lista_gerar(void);
void lista_ler(void);
void lista_limpar(void);
void lista_mostrar_ordenado(void);

int bubbleSort(int vec[], int tam);
int selectionSort(int vec[], int tam);
int mergeSort(int vec[], int tam, int qtd);
void junta(int vec[], int tam);

//Função Principal
int main(void)
{
	int opt = -1;
	srand(time(NULL));
	do {
		system("cls");
		lista_mostrar();
		lista_mostrar_ordenado();
		menu_mostrar();
		scanf("%d",&opt);

		switch (opt){
			case 1:
				lista_gerar();
				break;
			case 2:
				lista_ler();
				break;
			case 3:
				lista_limpar();
				qtd = bubbleSort(ordenado, TAMANHO);
				break;
			case 4:
				lista_limpar();
				qtd = selectionSort(ordenado, TAMANHO);
				break;
			case 5:
				lista_limpar();
				qtd = mergeSort(ordenado, TAMANHO, 0);
				break;
		}
	} while(opt != 0);
	system("pause");
	return 0;
}

void lista_mostrar(void)
{
	printf("[ ");
	for (int i = 0; i < TAMANHO; i++ ){
		printf("%d ",lista[i]);
	}
	printf("]\n\n");
}

//Mostra o menu
void menu_mostrar(void)
{
	printf("1 - Gerar lista aleatoriamente\n");
	printf("2 - Criar lista manualmente\n");
	printf("3 - Ordenacao por BubbleSort\n");
	printf("4 - Ordenacao por SelectionSort\n");
	printf("5 - Ordenacao por MergeSort\n");
	printf("0 - Sair...\n\n");
}

//Gera uma lista aleatória
void lista_gerar(void)
{
	for (int i = 0; i < TAMANHO; i++) {
		lista[i] = rand() % 50;
	}
}

//Mostra o conteúdo da lista
//Permite que o usuário entre com os valores da lista
void lista_ler(void)
{
	for (int i = 0; i < TAMANHO; i++) {
		system("cls");
		lista_mostrar();
		printf("\nDigite o valor para a posicao %d: ", i);
		scanf("%d", &lista[i]);
	}
}

//Preparar a lista para ordenação
void lista_limpar(void) {
	for (int i = 0; i < TAMANHO; i++) {
		ordenado[i] = lista[i];
	}
}

//Mostra o conteúdo da lista ordenada
void lista_mostrar_ordenado(void)
{
	printf("[ ");
	for (int i = 0; i < TAMANHO; i++ ) {
		printf("%d ",ordenado[i]);
	}
	printf("] Tempo = %d iteracoes\n\n", qtd);
}

// Aplica o método da bolha
int bubbleSort(int vec[], int tam)
{
    int qtd, i, j, tmp;
    qtd = 0;
    for (i = 0; i < tam - 1; i++) {
        for (j = i + 1; j < tam; j++) {
            if (vec[i] > vec[j]) {
                tmp = vec[i];
                vec[i] = vec[j];
                vec[j] = tmp;
            }
            qtd++;
        }
    }
    return qtd;
}

//Aplica o modo selectionSort
int selectionSort(int vec[], int tam)
{
    int i, j, tmp, min, qtd = 0;
    for (i = 0; i < tam - 1; i++) {
        min = i;
        for (j = i + 1; j < tam; j++) {
            if (vec[j] < vec[min]) {
                min = j;
            }
            qtd++;
        }
        if (i != min) {
            tmp = vec[i];
            vec[i] = vec[min];
            vec[min] = tmp;        
        }
    }
    return qtd;
}

//Aplica o modo MergeSort
int mergeSort(int vec[], int tam, int qtd)
{
    int meio;

    if (tam > 1) {
        meio = tam / 2;
        qtd = mergeSort(vec, meio, qtd);
        qtd = mergeSort(vec + meio, tam - meio, qtd);
        junta(vec, tam);
    }

    return qtd + 1;
}

void junta(int vec[], int tam) {
    int i, j, k;
    int meio;
    int* tmp;
    tmp = (int*) malloc(tam * sizeof(int));
    if (tmp == NULL) {
        exit(1);
	}
    meio = tam / 2;
    i = 0;
    j = meio;
    k = 0;
    while (i < meio && j < tam) {
        if (vec[i] < vec[j]) {
           tmp[k] = vec[i];
           i++;
        } else {
           tmp[k] = vec[j];
           j++;
        }
        k++;
    }
    if (i == meio) {
        while (j < tam) {
            tmp[k] = vec[j];
            j++;
            k++;
        }
    }
    else {
        while (i < meio) {
            tmp[k] = vec[i];
            i++;
            k++;
        }
    }
    for (i = 0; i < tam; ++i) {
        vec[i] = tmp[i];
    }
    free(tmp);
}
