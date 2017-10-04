#include <stdio.h>

#define MAX 5

int queue_array[MAX];
int rear = - 1;
int front = - 1;

int main(){
    int escolha;
    while (1){
        printf("\n1.Insere um elemento na fila\n");
        printf("2.Remove um elemento da fila\n");
        printf("3.Exibe todos os elementos da fila\n");
        printf("4.Sai\n");
        printf("\nDigite uma opção: ");

        scanf("%d", &escolha);

        switch (escolha){

            case 1:
                enqueue();
                break;

            case 2:

                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(1);

            default:

                printf("Escolha errada\n");

        }
    }
}

enqueue(){
    int item;
    if (rear == MAX - 1)
        printf("Overflow \n");
    else{
        if (front == - 1)
            front = 0;

        printf("\nInsere elemento na fila: ");
        scanf("%d", &item);
        rear++;

        queue_array[rear] = item;
    }
}

dequeue(){
    int i;
    if (front == - 1 || front > rear){
        printf("\nUnderflow\n");
        return ;
    }else{
        printf("\nO item removido da fila é: %d\n", queue_array[front]);
        for(i = 0; i < MAX; i++)
            queue_array[i] = queue_array[i+1];
        rear--;
    }
}

display(){
    int i;
    if (front == - 1)
        printf("\nA fila está vazia\n");
    else{
        printf("\nA fila é: \n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue_array[i]);
        printf("\n");
    }
}
