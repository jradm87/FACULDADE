#include<stdio.h>

int main(){
    int vendas[4][3] = {{1000,1200,700}, {1100,1200,1000}, {1000,1100,1150}, {1220,1200,1300}};

    total_vendas(vendas);
    vendas_vendedor(vendas);

    printf("\nFim da execução");
}

void total_vendas(int m[4][3]){
    int i, j, total = 0;
    for (i = 0; i < 4; i++){
        for (j = 0; j < 3; j++){
            total += m[i][j];
        }
    }
    printf("\O total vendido no trimestre foi %d\n", total);
}

void vendas_vendedor(int m[4][3]){
    int i, j, total = 0;
    for (i = 0; i < 4; i++){
        for (j = 0; j < 3; j++){
            total += m[i][j];
        }
        printf("\nO %do vendedor vendeu %d\n",i+1,total);
        total = 0;
    }
}
