#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

int main() {
    int n;
    int m, c;
    int i, j;
    int chave, posicao;
    No *tabela[105];
    No *novo, *aux;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d %d", &m, &c);

        for (j = 0; j < m; j++) {
            tabela[j] = NULL;
        }

        for (j = 0; j < c; j++) {
            scanf("%d", &chave);
            posicao = chave % m;

            novo = (No *)malloc(sizeof(No));
            novo->valor = chave;
            novo->prox = NULL;

            if (tabela[posicao] == NULL) {
                tabela[posicao] = novo;
            } else {
                aux = tabela[posicao];
                while (aux->prox != NULL) {
                    aux = aux->prox;
                }
                aux->prox = novo;
            }
        }

        for (j = 0; j < m; j++) {
            printf("%d -> ", j);
            aux = tabela[j];
            while (aux != NULL) {
                printf("%d -> ", aux->valor);
                aux = aux->prox;
            }
            printf("\\\n");
        }

        if (i < n - 1) {
            printf("\n");
        }
    }

    return 0;
}
