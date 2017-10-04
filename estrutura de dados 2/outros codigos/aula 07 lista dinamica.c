#include <stdio.h>

typedef struct no str_no;
struct no{
    int val;
    str_no *proximo;
};

void imprimelista(str_no *item)
{
    if ( item != NULL){
        printf("%d\n",item->val);
        imprimelista(item->proximo);
    }
}

int main(void)
{
 str_no a, b, c, d, e, f, g;
 a.val = 2;
 a.proximo = &b;
 b.val = 4;
 b.proximo = &c;
 c.val = 6;
 c.proximo = &d;
 d.val= 8;
 d.proximo = &e;
 e.val = 10;
 e.proximo = &f;
 f.val = 12;
 f.proximo = &g;
 g.val = 14;
 g.proximo = NULL;

 imprimelista(&a);

}
