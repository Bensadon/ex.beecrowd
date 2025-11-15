#include <stdlib.h>
#include <stdio.h>

typedef struct a {
    int valor;
    struct a *proximo;
} pessoa;

pessoa* adicionar (int *entrada, int n) {
    pessoa *fila = NULL;
    pessoa *antigo = NULL;
    pessoa *cabeca = NULL;

    for (int i = 0; i < n; i++) {
        fila = (pessoa*) malloc (sizeof(pessoa));
        fila->valor = entrada[i];

        if (i != 0) {
            antigo->proximo = fila;
        } else {
            fila->proximo = NULL;
            cabeca = fila;
        }
        antigo = fila;
    }

    if (fila != NULL) {
        fila->proximo = NULL;
    }
    
    return cabeca;
}

pessoa* inatividade (pessoa *cabeca, int *num_desistentes, int m) {
    for (int k = 0; k < m; k++) {
        int id_remover = num_desistentes[k];
        
        pessoa *atual = cabeca;
        pessoa *anterior = NULL;

        while (atual != NULL && atual->valor != id_remover) {
            anterior = atual;
            atual = atual->proximo;
        }

        if (atual == NULL) {
            continue;
        }

        if (anterior == NULL) {
            cabeca = atual->proximo;
            free(atual);
        }
        else {
            anterior->proximo = atual->proximo;
            free(atual);
        }
    }
    
    return cabeca;
}

void mostrar (pessoa *cabeca) {
    pessoa *atual = cabeca;
    int primeiro = 1;

    while (atual != NULL) {
        if (primeiro) {
            printf("%d", atual->valor);
            primeiro = 0;
        } else {
            printf(" %d", atual->valor);
        }
        atual = atual->proximo;
    }
    printf("\n");
}

int main() {
    int n1;
    int n2;
    int *entrada1;
    int *entrada2;
    pessoa *cabeca;

    scanf("%d", &n1);
    entrada1 = (int*) malloc (sizeof(int) * n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &entrada1[i]);
    }
    
    cabeca = adicionar(entrada1, n1);

    scanf("%d", &n2);
    entrada2 = (int*) malloc (sizeof(int) * n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &entrada2[i]);
    }

    cabeca = inatividade(cabeca, entrada2, n2);

    mostrar(cabeca);
    
    free(entrada1);
    free(entrada2);

    return 0;
}
