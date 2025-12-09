#include <stdio.h>

#define MAX_TAM 1050
#define MAX_FILA 1100000

char cenario[MAX_TAM][MAX_TAM];
int linhas, colunas;

struct Ponto {
    int l, c;
};

struct Ponto fila[MAX_FILA];

void pintar(int l_inicial, int c_inicial) {
    int inicio = 0;
    int fim = 0;
    int l, c;
    struct Ponto atual;

    fila[fim].l = l_inicial;
    fila[fim].c = c_inicial;
    fim++;

    cenario[l_inicial][c_inicial] = 'o';

    while (inicio < fim) {
        atual = fila[inicio];
        inicio++;

        l = atual.l;
        c = atual.c;

        if (l + 1 < linhas && cenario[l + 1][c] == '.') {
            cenario[l + 1][c] = 'o';
            fila[fim].l = l + 1;
            fila[fim].c = c;
            fim++;
        }

        if (l - 1 >= 0 && cenario[l - 1][c] == '.') {
            cenario[l - 1][c] = 'o';
            fila[fim].l = l - 1;
            fila[fim].c = c;
            fim++;
        }

        if (c + 1 < colunas && cenario[l][c + 1] == '.') {
            cenario[l][c + 1] = 'o';
            fila[fim].l = l;
            fila[fim].c = c + 1;
            fim++;
        }

        if (c - 1 >= 0 && cenario[l][c - 1] == '.') {
            cenario[l][c - 1] = 'o';
            fila[fim].l = l;
            fila[fim].c = c - 1;
            fim++;
        }
    }
}

int main() {
    int i, j;
    int cliques = 0;

    scanf("%d %d", &linhas, &colunas);

    for (i = 0; i < linhas; i++) {
        scanf("%s", cenario[i]);
    }

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            if (cenario[i][j] == '.') {
                cliques++;
                pintar(i, j);
            }
        }
    }

    printf("%d\n", cliques);

    return 0;
}
