#include <stdio.h>
#include <stdlib.h>

typedef struct data
{
    int mes, ano;
}TP_DATA;

typedef struct livros{
    char    nome[30];
    char    autor[30];
    int     id;
    TP_DATA data_pub;
}T_LIVRO;

void cadastraLivro(T_LIVRO *LIVRO){
    int i;
    for (i = 0; i < 5; i++){
        LIVRO[i].id =  i;

        printf("Informe os dados do Livro %d\n",LIVRO[i].id);

        printf("Autor:");
        scanf("%s",&LIVRO[i].autor);

        printf("Nome do livro:");
        scanf("%s",&LIVRO[i].nome);

        printf("Data Public:");
        scanf("%d",&LIVRO[i].data_pub.ano);

        printf("#####Livro %d cadastrado######\n\n",i);
        getchar();

    }
}

void consultaLivro(T_LIVRO *LIVRO){
    int i;

    for ( i = 0; i < 5; i++){
        printf("id: %d\n######Nome Livro:%s\n###### Autor: %s\n######Data Pub: %d\n",LIVRO[i].id, LIVRO[i].nome, LIVRO[i].autor, LIVRO[i].data_pub.ano);
    }
}

void main(){
    T_LIVRO LIVRO[5];

    cadastraLivro(&LIVRO);
    consultaLivro(&LIVRO);

}
