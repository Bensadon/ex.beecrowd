#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *esq;
    struct no *dir;
} No;

No* inserir(No *raiz, int valor) {
    if (raiz == NULL) {
        No *novo = (No*)malloc(sizeof(No));
        novo->valor = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    }
    if (valor < raiz->valor) {
        raiz->esq = inserir(raiz->esq, valor);
    } else {
        raiz->dir = inserir(raiz->dir, valor);
    }
    return raiz;
}

void bfs(No *raiz) {
    No *fila[1000];
    int inicio = 0;
    int fim = 0;
    int primeiro = 1;

    if (raiz == NULL) return;

    fila[fim] = raiz;
    fim++;

    while (inicio < fim) {
        No *atual = fila[inicio];
        inicio++;

        if (primeiro) {
            printf("%d", atual->valor);
            primeiro = 0;
        } else {
            printf(" %d", atual->valor);
        }

        if (atual->esq != NULL) {
            fila[fim] = atual->esq;
            fim++;
        }
        if (atual->dir != NULL) {
            fila[fim] = atual->dir;
            fim++;
        }
    }
}

void liberar(No *raiz) {
    if (raiz == NULL) return;
    liberar(raiz->esq);
    liberar(raiz->dir);
    free(raiz);
}

int main() {
    int c, n;
    int j, valor;
    int caso = 1;
    No *raiz;

    scanf("%d", &c);

    while (c > 0) {
        scanf("%d", &n);
        raiz = NULL;

        for (j = 0; j < n; j++) {
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
        }

        printf("Case %d:\n", caso);
        bfs(raiz);
        printf("\n\n");

        liberar(raiz);
        caso++;
        c--;
    }

    return 0;
}
