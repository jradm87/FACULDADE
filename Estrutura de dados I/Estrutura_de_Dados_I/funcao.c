#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<locale.h>

void check(char *a, char *b,
           int (*cmp) (const char *, const char *));
int numcmp(const char *a, const char *b);


int main(){
    char s1[80], s2[80];
    int (*p)();

	setlocale (LC_ALL, "Portuguese");
    p - strcmp;

    gets(s1);
    gets(s2);

    if (isalpha(*s1))
        check(s1, s2, strcmp);
    else
        check(s1, s2, numcmp);
}

void check(char *a, char *b,
           int (*cmp) (const char *, const char *)){

    printf("Testando igualdade\n");
    if (!(*cmp) (a, b))
        printf("\nIgual\n");
    else
        printf("\nDiferente\n");
}

int numcmp(const char *a, const char *b){
    if (atoi(a)==atoi(b))
        return 0;
    else
        return 1;
}
