#include <stdio.h>
#include <limits.h>

#define INF 9999999
#define MAX_N 105

int dijkstra_maximo(int n, int matriz[MAX_N][MAX_N], int origem) {
    int dist[MAX_N];
    int visitado[MAX_N];

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visitado[i] = 0;
    }
    dist[origem] = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;
        int menor_dist = INF;

        for (int j = 0; j < n; j++) {
            if (!visitado[j] && dist[j] < menor_dist) {
                menor_dist = dist[j];
                u = j;
            }
        }

        if (u == -1) break;
        visitado[u] = 1;

        for (int v = 0; v < n; v++) {
            if (matriz[u][v] < INF) {
                if (dist[u] + matriz[u][v] < dist[v]) {
                    dist[v] = dist[u] + matriz[u][v];
                }
            }
        }
    }

    int maior_distancia = 0;
    for (int i = 0; i < n; i++) {
        if (dist[i] > maior_distancia && dist[i] != INF) {
            maior_distancia = dist[i];
        }
    }

    return maior_distancia;
}

int main() {
    int n, m;
    int matriz[MAX_N][MAX_N];

    if (scanf("%d %d", &n, &m) != 2) return 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) matriz[i][j] = 0;
            else matriz[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        if (w < matriz[u][v]) {
            matriz[u][v] = w;
            matriz[v][u] = w;
        }
    }

    int menor_das_maiores = INF;

    for (int i = 0; i < n; i++) {
        int tempo_maximo = dijkstra_maximo(n, matriz, i);
        if (tempo_maximo < menor_das_maiores) {
            menor_das_maiores = tempo_maximo;
        }
    }

    printf("%d\n", menor_das_maiores);

    return 0;
}
