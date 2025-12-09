#include <stdio.h>
#include <stdlib.h>

#define MAX_C 10005
#define MAX_V 100005
#define INF 1000000000

typedef struct {
    int u;
    int paridade;
    int custo;
} Estado;

Estado heap[MAX_V * 4];
int tam_heap;

int cabeca[MAX_C];
int prox[MAX_V];
int destino[MAX_V];
int peso[MAX_V];
int tot_arestas;

int dist[MAX_C][2];

void adicionar_aresta(int u, int v, int p) {
    destino[tot_arestas] = v;
    peso[tot_arestas] = p;
    prox[tot_arestas] = cabeca[u];
    cabeca[u] = tot_arestas++;
}

void trocar(int i, int j) {
    Estado temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

void subir(int i) {
    while (i > 0) {
        int pai = (i - 1) / 2;
        if (heap[i].custo < heap[pai].custo) {
            trocar(i, pai);
            i = pai;
        } else {
            break;
        }
    }
}

void descer(int i) {
    int menor = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    if (esq < tam_heap && heap[esq].custo < heap[menor].custo) {
        menor = esq;
    }
    if (dir < tam_heap && heap[dir].custo < heap[menor].custo) {
        menor = dir;
    }
    if (menor != i) {
        trocar(i, menor);
        descer(menor);
    }
}

void inserir_heap(int u, int paridade, int custo) {
    heap[tam_heap].u = u;
    heap[tam_heap].paridade = paridade;
    heap[tam_heap].custo = custo;
    subir(tam_heap);
    tam_heap++;
}

Estado remover_heap() {
    Estado ret = heap[0];
    tam_heap--;
    heap[0] = heap[tam_heap];
    descer(0);
    return ret;
}

int main() {
    int c, v;
    int c1, c2, g;
    int i;

    while (scanf("%d %d", &c, &v) != EOF) {
        for (i = 0; i <= c; i++) {
            cabeca[i] = -1;
            dist[i][0] = INF;
            dist[i][1] = INF;
        }
        tot_arestas = 0;
        tam_heap = 0;

        for (i = 0; i < v; i++) {
            scanf("%d %d %d", &c1, &c2, &g);
            adicionar_aresta(c1, c2, g);
            adicionar_aresta(c2, c1, g);
        }

        dist[1][0] = 0;
        inserir_heap(1, 0, 0);

        while (tam_heap > 0) {
            Estado atual = remover_heap();
            int u = atual.u;
            int par = atual.paridade;
            int custo = atual.custo;

            if (custo > dist[u][par]) continue;

            for (i = cabeca[u]; i != -1; i = prox[i]) {
                int v_dest = destino[i];
                int custo_aresta = peso[i];
                int nova_par = 1 - par;

                if (dist[u][par] + custo_aresta < dist[v_dest][nova_par]) {
                    dist[v_dest][nova_par] = dist[u][par] + custo_aresta;
                    inserir_heap(v_dest, nova_par, dist[v_dest][nova_par]);
                }
            }
        }

        if (dist[c][0] == INF) {
            printf("-1\n");
        } else {
            printf("%d\n", dist[c][0]);
        }
    }

    return 0;
}
