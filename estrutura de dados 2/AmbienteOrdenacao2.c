//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Constantes
#define TAMANHO 9

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
void troca(int* a, int* b);

int bubbleSort(int vec[], int tam);
int selectionSort(int vec[], int tam);
int mergeSort(int vec[], int tam, int qtd);
void junta(int vec[], int tam);
int quickSort(int vec[], int left, int right, int qtd);
int particiona(int vec[], int left, int right);
int insertionSort(int vec[], int tam);
int shellSort(int vec[], int tam);

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
			case 6:
				lista_limpar();
				qtd = quickSort(ordenado, 0, TAMANHO - 1, 0);
				break;
			case 7:
				lista_limpar();
				qtd = insertionSort(ordenado, TAMANHO);
				break;
			case 8:
				lista_limpar();
				qtd = shellSort(ordenado, TAMANHO);
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
	printf("6 - Ordenacao por QuickSort\n");
	printf("7 - Ordenacao por InsertionSort\n");
	printf("8 - Ordenacao por ShellSort\n");
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

//Função genérica de troca de valores
void troca(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// Aplica o método da bolha
int bubbleSort(int vec[], int tam)
{
    int qtd, i, j;
    qtd = 0;
    for (i = 0; i < tam - 1; i++) {
            // i = 0
        for (j = i + 1; j < tam; j++) {
            // j =
            if (vec[i] > vec[j]) {
				troca(&vec[i], &vec[j]);
            }
            qtd++;
        }
    }
    return qtd;
}

//Aplica o modo selectionSort
int selectionSort(int vec[], int tam)
{
    int i, j, min, qtd = 0;
    for (i = 0; i < tam - 1; i++) {
        min = i;
        for (j = i + 1; j < tam; j++) {
            if (vec[j] < vec[min]) {
                min = j;
            }
            qtd++;
        }
        if (i != min) {
			troca(&vec[i], &vec[min]);
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
        printf("#######junior######\n");
        printf("Meio: %d\n",meio);
        printf("Valor vec: %d\n",&vec);
        printf("Valor qtd: %d\n",qtd);
        system("pause");

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

//Aplica o modo QuickSort
int quickSort(int vec[], int left, int right, int qtd)
{
    int pivo;
    if (right > left) {
        pivo = particiona(vec, left, right);
        printf("%d",pivo);
        qtd = quickSort(vec, left, pivo - 1, qtd);
        qtd = quickSort(vec, pivo + 1, right, qtd);
    }
    return qtd + 1;
}

int particiona(int vec[], int left, int right)
{
    int i, j;
    i = left;
    for (j = left + 1; j <= right; j++) {
        if (vec[j] < vec[left]) {
            i++;
            troca(&vec[i], &vec[j]);
        }
    }
    troca(&vec[left], &vec[i]);
    return i;
}

//Aplicando o InsetionSort
int insertionSort(int vec[], int tam)
{
   int i, j, qtd = 0;

   for(i = 1; i < tam; i++) {
      j = i;
      while (j != 0 && vec[j] < vec[j-1]) {
         troca(&vec[j], &vec[j-1]);
         j--;
         qtd++;
      }
   }

   return qtd;
}

//Aplica o shellSort
int shellSort(int vec[], int tam)
{
    int i, j, valor, qtd = 0;
    int gap = 1;

    do {
        gap = 3 * gap + 1;
    } while (gap < tam);

    do {
        gap /= 3;
        for (i = gap; i < tam; i++) {
            valor = vec[i];
            j = i - gap;
            while (j >= 0 && valor < vec[j]) {
                vec[j + gap] = vec[j];
                j -= gap;
                qtd++;
            }
            vec[j + gap] = valor;
        }
    } while (gap > 1);

    return qtd;
}
