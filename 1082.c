#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int grafo[30][30];
int visitado[30];
int vertices_encontrados[30];
int qtd_encontrados;
int total_vertices;

void dfs(int u) {
    int v;
    visitado[u] = 1;
    vertices_encontrados[qtd_encontrados] = u;
    qtd_encontrados++;

    for (v = 0; v < total_vertices; v++) {
        if (grafo[u][v] == 1 && visitado[v] == 0) {
            dfs(v);
        }
    }
}

int main() {
    int n, caso = 1;
    int i, j, k;
    int arestas;
    char origem, destino;
    int u, v;
    int componentes;

    scanf("%d", &n);

    while (n > 0) {
        scanf("%d %d", &total_vertices, &arestas);

        for (i = 0; i < 30; i++) {
            visitado[i] = 0;
            for (j = 0; j < 30; j++) {
                grafo[i][j] = 0;
            }
        }

        for (i = 0; i < arestas; i++) {
            scanf(" %c %c", &origem, &destino);
            u = origem - 'a';
            v = destino - 'a';
            grafo[u][v] = 1;
            grafo[v][u] = 1;
        }

        printf("Case #%d:\n", caso);
        componentes = 0;

        for (i = 0; i < total_vertices; i++) {
            if (visitado[i] == 0) {
                componentes++;
                qtd_encontrados = 0;
                
                dfs(i);

                for (j = 0; j < qtd_encontrados; j++) {
                    for (k = j + 1; k < qtd_encontrados; k++) {
                        if (vertices_encontrados[j] > vertices_encontrados[k]) {
                            int aux = vertices_encontrados[j];
                            vertices_encontrados[j] = vertices_encontrados[k];
                            vertices_encontrados[k] = aux;
                        }
                    }
                }

                for (j = 0; j < qtd_encontrados; j++) {
                    printf("%c,", vertices_encontrados[j] + 'a');
                }
                printf("\n");
            }
        }

        printf("%d connected components\n\n", componentes);

        caso++;
        n--;
    }

    return 0;
}
