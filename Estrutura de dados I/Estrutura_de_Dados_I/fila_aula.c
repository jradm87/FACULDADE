/*fila usando ponteiro: fila_aula.c*/

#include <stdio.h>
#include <stdlib.h>

#define TAM 10

struct queue
{
    int itens[TAM];
    int front,rear;
};

int empty(struct queue * pq){
    if( pq->front == pq->rear )
        return 1;
    else
        return 0;
}

void enqueue(struct queue *pq, int x){
    if (pq->rear + 1 >= TAM){
        printf("\nEstouro da capacidade da fila");
        exit(1);
    }
    pq->itens[ pq->rear++ ] = x;
    return;
}

int size(struct queue *pq){
    return (pq->rear + 1);
}

int front(struct queue *pq){
    /* o primeiro elemento
       sempre está no início do vetor */
    return pq->itens[0];
}

int dequeue(struct queue *pq){
    int x, i;
    if (empty(pq)){
        printf("\nFila vazia");
        exit(1);
    }
    /* Salva o primeiro elemento e refaz o arranjo dos itens,
        puxando o segundo elemento para o primeiro, o terceiro
        para o segundo e assim sucessivamente. */
    x = pq->itens[0];
    for( i=0; i < pq->rear; i++){
        pq->itens[i] = pq->itens[i+1];
    }
    pq->rear--;
    return x;
}

void display(struct queue *pq){
    int i;
    if (empty(pq)){
        printf("\nA fila está vazia\n");
    }else{
        printf("\nA fila é: \n");
        for (i = pq->front; i < pq->rear; i++)
            printf("%d ", pq->itens[i]);
        printf("\n");
    }
}

int main(void){
    struct queue q;
    int escolha, valor;
    q.front = 0; q.rear = 0;

    while (1){
        printf("\n1.Insere um elemento na fila\n");
        printf("2.Remove um elemento da fila\n");
        printf("3.Exibe todos os elementos da fila\n");
        printf("4.Sai\n");
        printf("\nDigite uma opção: ");

        scanf("%d", &escolha);

        switch (escolha){

            case 1:
                printf("Informe o valor: ");
                scanf("%d", &valor);
                enqueue(&q, valor);
                break;

            case 2:
                dequeue(&q);
                break;

            case 3:
                display(&q);
                break;

            case 4:
                exit(1);

            default:

                printf("Escolha errada\n");

        }
     }
}
