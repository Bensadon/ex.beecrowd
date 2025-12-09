#include <stdio.h>
#include <stdlib.h>

#define MAX_CIDADES 40005
#define MAX_ESTRADAS 50005

typedef struct {
    int u, v, peso;
} Aresta;

Aresta arestas[MAX_ESTRADAS];
int pai[MAX_CIDADES];

int comparar(const void *a, const void *b) {
    return ((Aresta*)a)->peso - ((Aresta*)b)->peso;
}

int buscar(int i) {
    if (pai[i] == i)
        return i;
    return pai[i] = buscar(pai[i]);
}

void unir(int i, int j) {
    int raiz_i = buscar(i);
    int raiz_j = buscar(j);
    if (raiz_i != raiz_j) {
        pai[raiz_i] = raiz_j;
    }
}

int main() {
    int m, n;
    int i;
    int soma;

    while (scanf("%d %d", &m, &n) && (m != 0 || n != 0)) {
        for (i = 0; i < n; i++) {
            scanf("%d %d %d", &arestas[i].u, &arestas[i].v, &arestas[i].peso);
        }

        for (i = 0; i < m; i++) {
            pai[i] = i;
        }

        qsort(arestas, n, sizeof(Aresta), comparar);

        soma = 0;
        for (i = 0; i < n; i++) {
            if (buscar(arestas[i].u) != buscar(arestas[i].v)) {
                unir(arestas[i].u, arestas[i].v);
                soma += arestas[i].peso;
            }
        }

        printf("%d\n", soma);
    }

    return 0;
}
