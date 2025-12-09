#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *esq;
    struct no *dir;
} No;

No* criar_no(int valor) {
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

No* inserir(No *raiz, int valor) {
    if (raiz == NULL) {
        return criar_no(valor);
    }
    if (valor < raiz->valor) {
        raiz->esq = inserir(raiz->esq, valor);
    } else {
        raiz->dir = inserir(raiz->dir, valor);
    }
    return raiz;
}

void prefixo(No *raiz) {
    if (raiz == NULL) return;
    printf(" %d", raiz->valor);
    prefixo(raiz->esq);
    prefixo(raiz->dir);
}

void infixo(No *raiz) {
    if (raiz == NULL) return;
    infixo(raiz->esq);
    printf(" %d", raiz->valor);
    infixo(raiz->dir);
}

void posfixo(No *raiz) {
    if (raiz == NULL) return;
    posfixo(raiz->esq);
    posfixo(raiz->dir);
    printf(" %d", raiz->valor);
}

void liberar(No *raiz) {
    if (raiz == NULL) return;
    liberar(raiz->esq);
    liberar(raiz->dir);
    free(raiz);
}

int main() {
    int c, n;
    int i, j;
    int valor;
    No *raiz;

    scanf("%d", &c);

    for (i = 1; i <= c; i++) {
        scanf("%d", &n);
        raiz = NULL;

        for (j = 0; j < n; j++) {
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
        }

        printf("Case %d:\n", i);
        
        printf("Pre.:");
        prefixo(raiz);
        printf("\n");

        printf("In..:");
        infixo(raiz);
        printf("\n");

        printf("Post:");
        posfixo(raiz);
        printf("\n\n");

        liberar(raiz);
    }

    return 0;
}
