#include <stdio.h>
#include <string.h>

int main() {
    int casos_teste;
    scanf("%d", &casos_teste);

    while (casos_teste > 0) {
        int ponto_inicio;
        scanf("%d", &ponto_inicio);

        int vertices, arestas;
        scanf("%d %d", &vertices, &arestas);

        int matriz_adj[100][100];
        memset(matriz_adj, 0, sizeof(matriz_adj));

        int arestas_unicas = 0;

        for (int i = 0; i < arestas; i++) {
            int u, v;
            scanf("%d %d", &u, &v);

            if (matriz_adj[u][v] == 0) {
                matriz_adj[u][v] = 1;
                matriz_adj[v][u] = 1;
                arestas_unicas++;
            }
        }

        int movimentos = arestas_unicas * 2;
        printf("%d\n", movimentos);

        casos_teste--;
    }

    return 0;
}
