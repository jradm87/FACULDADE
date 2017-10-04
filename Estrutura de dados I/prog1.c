#include<stdio.h>

#define tam 5

struct Pilha{
	int dados[tam];
	int base;
	int topo;
};

struct Pilha pilha;

void push(int v){
	if (pilha.topo == tam){
		printf("\nEstouro de pilha.");
		exit(1);
	}else{
		pilha.dados[pilha.topo] = v;
		pilha.topo++;	
	}
	
}

int pop(){
	int v;
	if (pilha.base == pilha.topo){
		printf("\nUnderflow.");
		exit(1);
	}else{
		v = pilha.dados[pilha.topo-1];
		pilha.dados[pilha.topo-1] = 0;
		pilha.topo--;	
	}	
	return v;
}

int main(){
	int x = 40, y = 50, z = 60;
	pilha.base = 0;
	pilha.topo = 0;
	
	push(z);
	push(y);
	push(x);
	
	y = pop();
	z = pop();
	x = pop();
	
	printf("x %d, y %d, z %d", x, y, z);
	
}
