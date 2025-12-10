#include <stdio.h>
#include <stdlib.h>

#define MAX_N 10005

typedef struct no {
    int id;
    struct no *prox;
} No;

No *lista_adj[MAX_N];
int visitado[MAX_N];
int encontrou_ciclo;

void adicionar_dependencia(int u, int v) {
    No *novo = (No*)malloc(sizeof(No));
    novo->id = v;
    novo->prox = lista_adj[u];
    lista_adj[u] = novo;
}

void limpar_lista(int n) {
    int i;
    No *atual, *temp;
    for (i = 0; i <= n; i++) {
        atual = lista_adj[i];
        while (atual != NULL) {
            temp = atual;
            atual = atual->prox;
            free(temp);
        }
        lista_adj[i] = NULL;
    }
}

void dfs(int u) {
    visitado[u] = 1; 
    
    No *atual = lista_adj[u];
    while (atual != NULL) {
        int v = atual->id;
        
        if (visitado[v] == 1) {
            encontrou_ciclo = 1;
            return;
        }
        
        if (visitado[v] == 0) {
            dfs(v);
            if (encontrou_ciclo) return;
        }
        
        atual = atual->prox;
    }
    
    visitado[u] = 2;
}

int main() {
    int t, n, m;
    int i, u, v;

    scanf("%d", &t);

    while (t > 0) {
        scanf("%d %d", &n, &m);

        for (i = 0; i <= n; i++) {
            lista_adj[i] = NULL;
            visitado[i] = 0;
        }

        for (i = 0; i < m; i++) {
            scanf("%d %d", &u, &v);
            adicionar_dependencia(u, v);
        }

        encontrou_ciclo = 0;
        for (i = 1; i <= n; i++) {
            if (visitado[i] == 0) {
                dfs(i);
                if (encontrou_ciclo) break;
            }
        }

        if (encontrou_ciclo) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }

        limpar_lista(n);
        t--;
    }

    return 0;
}
