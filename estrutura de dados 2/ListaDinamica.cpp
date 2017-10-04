#include <stdio.h>

typedef struct no str_no;
struct no {
	int val;
	str_no *proximo;
};

void imprimeLista(str_no *item)
{
	if (item != NULL) {
		printf("%d\n", item->val);
		imprimeLista(item->proximo);
	}
}

int main(void)
{
	str_no a, b, c, d, e, f, g;
	
	a.val = 2;
	a.proximo = &e;
	
	b.val = 4;
	b.proximo = NULL;
	
	c.val = 6;
	c.proximo = &f;
	
	d.val = 8;
	d.proximo = &b;
	
	e.val = 10;
	e.proximo = &c;
	
	f.val = 12;
	f.proximo = &d;
	
	g.val = 14;
	g.proximo = NULL;
	
	imprimeLista(&a);
}
