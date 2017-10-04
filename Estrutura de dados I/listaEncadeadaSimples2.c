#include <stdio.h>
#include <stdlib.h>


struct lista{
    int info;
    struct lista *proximo;
};

typedef struct lista Lista;


Lista* inicializa(void){
    return NULL;
}

Lista* cria(int v){
    Lista * p = (Lista *)malloc(sizeof(Lista));
    p->info = v;
    return p;
}

//inserir ordenado
Lista* insere(Lista *l, int i){
    Lista* novo = cria(i);
    Lista* ant = NULL;
    Lista* p = l;

    while(p != NULL && p->info < i){
        ant = p;
        p = p->proximo;
    }

    if (ant == NULL){
        novo->proximo = l;
        l = novo;
    }else{
        novo->proximo = ant->proximo;
        ant->proximo = novo;
    }

    return l;
}

void imprime(Lista *l){
    Lista *p;
    for (p =l; p != NULL; p = p->proximo)
        printf("Info = %d\n", p->info);
        printf("\n\n");

}

Lista * retira(Lista *l, int v){
    Lista *ant = NULL;
    Lista *p = l;
    while(p != NULL && p->info != v){
        ant = p;
        p = p->proximo;
    }

    if (p == NULL){
        return 1;
    }
    if (ant == NULL){
        l = p->proximo;
    }else{
        ant->proximo = p->proximo;
    }
    free(p);
    return l;
}

void libera(Lista *l){
    Lista *p = l;
    while (p != NULL){
            Lista *t = p->proximo;
            free(p);
            p = t;
    }
}
int main(){
    Lista *l;
    //l = inicializa();
    l = NULL;
    l = insere(l, 23);
    l = insere(l, 45);
    l = insere(l, 13);
    l = insere(l, 70);
    imprime(l);
    l = retira(l, 45);
    imprime(l);
    libera(l);

    return 0;
}
