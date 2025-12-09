#include <stdio.h>

#define MAX 255
#define INFINITO 100000000

int adj[MAX][MAX];
int dist[MAX];
int visitado[MAX];

int main() {
    int n, m, c, k;
    int i, j;
    
    while (scanf("%d %d %d %d", &n, &m, &c, &k)) {
        if (n == 0 && m == 0 && c == 0 && k == 0) break;

        for (i = 0; i < n; i++) {
            dist[i] = INFINITO;
            visitado[i] = 0;
            for (j = 0; j < n; j++) {
                adj[i][j] = INFINITO;
            }
        }

        for (i = 0; i < m; i++) {
            int u, v, p;
            scanf("%d %d %d", &u, &v, &p);
            if (p < adj[u][v]) {
                adj[u][v] = p;
                adj[v][u] = p;
            }
        }

        dist[k] = 0;

        for (i = 0; i < n; i++) {
            int u = -1;
            int menor_dist = INFINITO;

            for (j = 0; j < n; j++) {
                if (!visitado[j] && dist[j] < menor_dist) {
                    menor_dist = dist[j];
                    u = j;
                }
            }

            if (u == -1) break;
            visitado[u] = 1;

            if (u < c) continue; 

            for (int v = 0; v < n; v++) {
                if (adj[u][v] != INFINITO) {
                    if (dist[u] + adj[u][v] < dist[v]) {
                        dist[v] = dist[u] + adj[u][v];
                    }
                }
            }
        }

        int resposta = INFINITO;
        
        for (i = 0; i < c; i++) {
            if (dist[i] != INFINITO) {
                int custo_rota = 0;
                for (j = i; j < c - 1; j++) {
                    custo_rota += adj[j][j+1];
                }
                
                if (dist[i] + custo_rota < resposta) {
                    resposta = dist[i] + custo_rota;
                }
            }
        }

        printf("%d\n", resposta);
    }

    return 0;
}
