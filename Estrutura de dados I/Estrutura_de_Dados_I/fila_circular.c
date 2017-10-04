/*fila circular (cíclica): fila_circular.c*/

#include<stdio.h>
#include<stdlib.h>

#define TAM 10

struct queue{
    int itens[TAM];
    int front, rear;
};

int empty(struct queue *pq){
    if (pq->front == pq->rear){
        return 1;
    }
    return 0;
}

void enqueue(struct queue *pq, int x){
    if (pq->rear == TAM-1){
        pq->rear = 0;
    }else{
        pq->rear++;
    }
    if (pq->rear == pq->front){
        printf("\nEstouro da fila");
        exit(1);
    }
    pq->itens[pq->rear] = x;
    return;
}

int size(struct queue *pq){
    if (pq->front <= pq->rear){
        return pq->rear - pq->front;
        /*o tamanho da fila é o final da fila
          menos o início da fila*/
    }
    return pq->rear + pq->front;
    /*senão, o ponteiro de final da fila já acançou
      o final do vetor e foi posicionado para o início
      do vetor, então, o tamanho da fila é a quantidade
      de itens que ainda restam até chegar ao final do
      vetor somando itens que estão no início do vetor
    */
}

int front(struct queue *pq){
    return pq->itens[pq->front+1];
}

int dequeue(struct queue *pq){
    int x, i;
    if (empty(pq)){
        printf("\nFila vazia");
        exit(1);
    }

    if (pq->front == TAM){
        pq->front=0;
    }
    else{
        pq->front++;
    }
    return (pq->itens[pq->front]);
}

void display(struct queue *pq){
    int i;
    if (empty(pq)){
        printf("\nA fila está vazia\n");
    }else{
        printf("\nA fila é: \n");
        for (i = pq->front+1; i <= pq->rear; i++)
            printf("%d ", pq->itens[i]);
        printf("\n");
    }
}

int main(){
    struct queue q;
    q.front = -1;
    q.rear = -1;
    int escolha, valor;

    while (1){
        printf("\n1.Insere um elemento na fila\n");
        printf("2.Remove um elemento da fila\n");
        printf("3.Exibe todos os elementos da fila\n");
        printf("4.Exibe o tamanho da fila\n");
        printf("5.Exibe o elemento da frente\n");
        printf("6.Sai\n");
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
                getchar();
                break;

            case 4:
                printf("\nA fila tem %d elementos\n",size(&q));
                getchar();
                break;

            case 5:
                printf("\n%d é o primeiro elemento\n",front(&q));
                getchar();
                break;

            case 6:
                exit(1);

            default:

                printf("Escolha errada\n");

        }
     }
}
