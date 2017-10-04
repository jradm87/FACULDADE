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

int vazia(Lista* l){
    if (l == NULL)
        return 1;
    else
        return 0;
}

void imprime(Lista *l){
    if (vazia(l))
        return;
    printf("Info: %d\n",l->info);
    imprime(l->proximo);
}

Lista * retira(Lista *l, int v){
    if (vazia(l))
        return l;

    if (l->info == v){
        Lista *t = l;
        l = l->proximo;
        free(t);
    }else{
        l->proximo = retira(l->proximo, v);
    }
    return l;
}

void libera(Lista *l){
    if(!vazia(l)){
        libera(l->proximo);
        free(l);
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
    printf("\n\n");
    l = retira(l, 45);
    imprime(l);
    printf("\n\n");
    libera(l);

    return 0;
}
