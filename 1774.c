#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int origem;
    int destino;
    int preco;
} Cabo;

int comparar_precos(const void *a, const void *b) {
    Cabo *caboA = (Cabo *)a;
    Cabo *caboB = (Cabo *)b;
    return caboA->preco - caboB->preco;
}

int buscar_pai(int i, int pais[]) {
    if (pais[i] == i)
        return i;
    return pais[i] = buscar_pai(pais[i], pais);
}

void unir_conjuntos(int i, int j, int pais[]) {
    int raiz_i = buscar_pai(i, pais);
    int raiz_j = buscar_pai(j, pais);
    pais[raiz_i] = raiz_j;
}

int main() {
    int qtd_roteadores, qtd_cabos;
    
    if (scanf("%d %d", &qtd_roteadores, &qtd_cabos) != 2) return 0;

    Cabo lista_cabos[qtd_cabos];

    for (int i = 0; i < qtd_cabos; i++) {
        scanf("%d %d %d", &lista_cabos[i].origem, &lista_cabos[i].destino, &lista_cabos[i].preco);
    }

    qsort(lista_cabos, qtd_cabos, sizeof(Cabo), comparar_precos);

    int pais[qtd_roteadores + 1];
    for (int i = 1; i <= qtd_roteadores; i++) {
        pais[i] = i;
    }

    int custo_total = 0;
    int arestas_usadas = 0;

    for (int i = 0; i < qtd_cabos; i++) {
        if (buscar_pai(lista_cabos[i].origem, pais) != buscar_pai(lista_cabos[i].destino, pais)) {
            unir_conjuntos(lista_cabos[i].origem, lista_cabos[i].destino, pais);
            custo_total += lista_cabos[i].preco;
            arestas_usadas++;
        }
    }

    printf("%d\n", custo_total);

    return 0;
}
