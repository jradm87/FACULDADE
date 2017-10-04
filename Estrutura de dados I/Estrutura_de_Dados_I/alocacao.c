#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include <locale.h>

int main () {
    char *s;
    int t;

	setlocale (LC_ALL, "Portuguese");
    s = malloc (80);

    if (!s) {
        printf ("Falha na solicitação de memória.\n");
        exit (1);
    }

    gets (s);
    for (t = strlen (s)-1; t>=0; t--)
        putchar (s[t]);

    free (s);
}

