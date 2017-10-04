/*lista simplesmente encadeada: lista_simples.c*/

#include<stdio.h>
#include<stdlib.h>

struct LISTA{
    char info[40];
    int numero;
    struct LISTA *NEXT;
};

int main(){
    int i;
    struct LISTA *lista;
    struct LISTA *inicio;

    lista = calloc(1, sizeof(struct LISTA));
    if (lista == NULL){
        printf("\nErro de alocação de memória!\n");
        exit(-1);
    }
    lista->NEXT = NULL;

    //guarda o início da lista
    inicio = lista;
    for (i = 0; i < 25; i++){
        lista->numero = i;
        sprintf(lista->info, "Número %02d", i);

        //aloca o próximo elemento da lista
        lista->NEXT = calloc(1, sizeof(struct LISTA));
        if (lista->NEXT == NULL){
            printf("\nErro de alocação de memória!\n");
            exit(-1);
        }

        //posiciona no próximo elemento
        lista = lista->NEXT;
        lista->NEXT = NULL;
    }

    //volta para o início da lista
    lista = inicio;
    while(lista->NEXT != NULL){
        printf("\nNúmero = %d, Nome = %s", lista->numero, lista->info);

        //caminha elemento a elemento na lista
        lista = lista->NEXT;
    }

    lista = inicio;
    while(lista->NEXT != NULL){
        struct LISTA *next;
        next = lista->NEXT;

        /*libera o espaço do endereço atual
          e limpa o endereço atribuindo NULL*/
        free(lista);
        lista = NULL;
        lista = next;
    }

    return 0;
}
