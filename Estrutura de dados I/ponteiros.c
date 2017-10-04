#include <stdio.h>


int main(){

    int qtd=20;
    int *pt = &qtd;
    int **pt1 =&pt;

    printf("%d\n",qtd);
    printf("valor %d\n",*pt);
    printf("end %d\n",pt);
    printf("pt1 com asterisco %d\n",*pt1);
    printf("pt1 asterisco parenteses %d\n",*(*pt1));


return 0;}
