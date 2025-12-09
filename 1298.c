#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOS 400000
#define MAX_ARESTAS 400000

typedef struct {
    int u, v;
    int peso;
} Aresta;

Aresta lista_arestas[MAX_ARESTAS];
int pai[MAX_NOS];
int altura[MAX_NOS];
int qtd_arestas;

int encontrar(int i) {
    if (pai[i] == i)
        return i;
    return pai[i] = encontrar(pai[i]);
}

void unir(int i, int j) {
    int raiz_i = encontrar(i);
    int raiz_j = encontrar(j);
    
    if (raiz_i != raiz_j) {
        if (altura[raiz_i] > altura[raiz_j]) {
            pai[raiz_j] = raiz_i;
        } else {
            pai[raiz_i] = raiz_j;
            if (altura[raiz_i] == altura[raiz_j]) {
                altura[raiz_j]++;
            }
        }
    }
}

int comparar(const void *a, const void *b) {
    return ((Aresta*)a)->peso - ((Aresta*)b)->peso;
}

int obter_id(int l, int c, int n, int largura) {
    if (l <= 0 || l >= 2 * n || c <= 0 || c >= 2 * n + 1) {
        return 0;
    }
    return l * largura + c;
}

int main() {
    int n;
    int i, j;
    int r, c;
    char buffer[605];
    int largura_mapa;
    int resultado;

    while (scanf("%d", &n) != EOF) {
        if (n == 0) break;

        largura_mapa = 2 * n + 5;
        int total_nos = largura_mapa * (2 * n + 2);

        for (i = 0; i <= total_nos; i++) {
            pai[i] = i;
            altura[i] = 0;
        }

        qtd_arestas = 0;

        for (i = 1; i < 2 * n; i++) {
            scanf("%s", buffer);
            for (j = 0; j < n; j++) {
                r = i;
                if (i % 2 != 0) {
                    c = 2 * (j + 1) - 1;
                } else {
                    c = 2 * (j + 1);
                }

                int u_horiz = obter_id(r, c - 1, n, largura_mapa);
                int v_horiz = obter_id(r, c + 1, n, largura_mapa);
                
                int u_vert = obter_id(r - 1, c, n, largura_mapa);
                int v_vert = obter_id(r + 1, c, n, largura_mapa);

                int peso_h, peso_v;

                if (buffer[j] == 'H') {
                    peso_h = 0;
                    peso_v = 1;
                } else {
                    peso_h = 1;
                    peso_v = 0;
                }

                lista_arestas[qtd_arestas].u = u_horiz;
                lista_arestas[qtd_arestas].v = v_horiz;
                lista_arestas[qtd_arestas].peso = peso_h;
                qtd_arestas++;

                lista_arestas[qtd_arestas].u = u_vert;
                lista_arestas[qtd_arestas].v = v_vert;
                lista_arestas[qtd_arestas].peso = peso_v;
                qtd_arestas++;
            }
        }

        qsort(lista_arestas, qtd_arestas, sizeof(Aresta), comparar);

        resultado = 0;
        for (i = 0; i < qtd_arestas; i++) {
            if (encontrar(lista_arestas[i].u) != encontrar(lista_arestas[i].v)) {
                unir(lista_arestas[i].u, lista_arestas[i].v);
                resultado += lista_arestas[i].peso;
            }
        }

        printf("%d\n", resultado);
    }

    return 0;
}
