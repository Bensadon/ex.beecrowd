#include <stdio.h>

#define MAX 505
#define INFINITO 100000000

int distancias[MAX][MAX];
int n, e;

int min(int a, int b) {
    if (a < b) return a;
    return b;
}

int main() {
    int x, y, h;
    int k, o, d;
    int i, j, l;

    while (scanf("%d %d", &n, &e) && (n != 0 || e != 0)) {
        
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (i == j) {
                    distancias[i][j] = 0;
                } else {
                    distancias[i][j] = INFINITO;
                }
            }
        }

        for (i = 0; i < e; i++) {
            scanf("%d %d %d", &x, &y, &h);
            if (distancias[x][y] > h) {
                distancias[x][y] = h;
            }
        }

        for (l = 1; l <= n; l++) {
            for (i = 1; i <= n; i++) {
                for (j = 1; j <= n; j++) {
                    distancias[i][j] = min(distancias[i][j], distancias[i][l] + distancias[l][j]);
                }
            }
        }

        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (distancias[i][j] != INFINITO && distancias[j][i] != INFINITO) {
                    distancias[i][j] = 0;
                }
            }
        }

        for (l = 1; l <= n; l++) {
            for (i = 1; i <= n; i++) {
                for (j = 1; j <= n; j++) {
                    distancias[i][j] = min(distancias[i][j], distancias[i][l] + distancias[l][j]);
                }
            }
        }

        scanf("%d", &k);

        while (k > 0) {
            scanf("%d %d", &o, &d);
            if (distancias[o][d] == INFINITO) {
                printf("Nao e possivel entregar a carta\n");
            } else {
                printf("%d\n", distancias[o][d]);
            }
            k--;
        }
        printf("\n");
    }

    return 0;
}
