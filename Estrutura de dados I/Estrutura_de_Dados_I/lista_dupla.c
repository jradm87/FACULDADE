/*lista duplamente encadeada: lista_dupla.c*/

#include<stdio.h>
#include<stdlib.h>

struct LISTA{
    char info[40];
    int numero;
    struct LISTA *NEXT;
    struct LISTA *PRIOR;
};

int main(void){
    int i;
    struct LISTA *lista;

    lista = calloc(1, sizeof(struct LISTA));
    if (lista == NULL){
        printf("\nErro de alocação de memória!\n");
        exit(1);
    }
    lista->NEXT = NULL;
    lista->PRIOR = NULL;

    for (i = 0; i < 25; i++){
        struct LISTA *atual;
        lista->numero = i;

        sprintf(lista->info, "Numero %02d", i);

        //aloca o próximo elemento da lista
        lista ->NEXT = calloc(1, sizeof(struct LISTA));
        if (lista->NEXT == NULL){
            printf("\nErro de alocação de memória!\n");
            exit(1);
        }

        //pega o endereço do elemento atual
        atual = lista;
        lista = lista->NEXT;
        lista->NEXT = NULL;

        //guarda o endereco do elemento anterior
        lista->PRIOR = atual;
    }

    lista = lista->PRIOR;
    free(lista->NEXT);
    lista->NEXT = NULL;

    while(1){
        printf("\nNúmero = %d, Informação = %s", lista->numero, lista->info);
        if(lista->PRIOR == NULL){
            break;
        }
        lista=lista->PRIOR;
    }

    while(lista != NULL){
        struct LISTA *next;
        next = lista->NEXT;

        //liberar o endereço
        free(lista);
        lista = NULL;
        lista = next;
    }

    return 0;
}
