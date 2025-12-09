#include <stdio.h>
#include <string.h>

#define MAX_N 10005
#define MAX_M 30005

int cabeca[MAX_N];
int proximo[MAX_M];
int destino[MAX_M];
int indice_aresta;

int visitado[MAX_N];
int encontrou_ciclo;

void adicionar_aresta(int u, int v) {
    destino[indice_aresta] = v;
    proximo[indice_aresta] = cabeca[u];
    cabeca[u] = indice_aresta;
    indice_aresta++;
}

void dfs(int u) {
    visitado[u] = 1;

    int aresta = cabeca[u];
    while (aresta != -1) {
        int v = destino[aresta];

        if (visitado[v] == 1) {
            encontrou_ciclo = 1;
            return;
        }

        if (visitado[v] == 0) {
            dfs(v);
            if (encontrou_ciclo) return;
        }

        aresta = proximo[aresta];
    }

    visitado[u] = 2;
}

int main() {
    int t;
    int n, m;
    int i, u, v;

    scanf("%d", &t);

    while (t > 0) {
        scanf("%d %d", &n, &m);

        indice_aresta = 0;
        for (i = 0; i <= n; i++) {
            cabeca[i] = -1;
            visitado[i] = 0;
        }

        for (i = 0; i < m; i++) {
            scanf("%d %d", &u, &v);
            adicionar_aresta(u, v);
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

        t--;
    }

    return 0;
}
