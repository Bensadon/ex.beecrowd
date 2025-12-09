#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int altura;
    int quantidade;
    struct no *esq;
    struct no *dir;
} No;

No* criar_no(int h) {
    No *novo = (No*)malloc(sizeof(No));
    novo->altura = h;
    novo->quantidade = 1;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

No* inserir(No *raiz, int h) {
    if (raiz == NULL) {
        return criar_no(h);
    }
    
    if (h == raiz->altura) {
        raiz->quantidade++;
    } else if (h < raiz->altura) {
        raiz->esq = inserir(raiz->esq, h);
    } else {
        raiz->dir = inserir(raiz->dir, h);
    }
    
    return raiz;
}

int primeiro_impresso;

void em_ordem(No *raiz) {
    int i;
    if (raiz != NULL) {
        em_ordem(raiz->esq);
        
        for (i = 0; i < raiz->quantidade; i++) {
            if (primeiro_impresso) {
                printf(" %d", raiz->altura);
            } else {
                printf("%d", raiz->altura);
                primeiro_impresso = 1;
            }
        }
        
        em_ordem(raiz->dir);
    }
}

void liberar(No *raiz) {
    if (raiz != NULL) {
        liberar(raiz->esq);
        liberar(raiz->dir);
        free(raiz);
    }
}

int main() {
    int nc, n, h;
    int i;
    No *raiz = NULL;

    scanf("%d", &nc);

    while (nc > 0) {
        scanf("%d", &n);
        
        raiz = NULL;
        for (i = 0; i < n; i++) {
            scanf("%d", &h);
            raiz = inserir(raiz, h);
        }

        primeiro_impresso = 0;
        em_ordem(raiz);
        printf("\n");

        liberar(raiz);
        nc--;
    }

    return 0;
}
