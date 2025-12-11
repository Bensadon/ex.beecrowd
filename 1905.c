#include <stdio.h>

int matriz[5][5];
int visitado[5][5];

int busca_profundidade(int x, int y) {
    if (x < 0 || x >= 5 || y < 0 || y >= 5) {
        return 0;
    }
    if (matriz[x][y] == 1 || visitado[x][y]) {
        return 0;
    }
    if (x == 4 && y == 4) {
        return 1;
    }

    visitado[x][y] = 1;

    int encontrou = busca_profundidade(x + 1, y) ||
                    busca_profundidade(x - 1, y) ||
                    busca_profundidade(x, y + 1) ||
                    busca_profundidade(x, y - 1);
    
    return encontrou;
}

int main() {
    int casos;
    scanf("%d", &casos);

    while (casos--) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                scanf("%d", &matriz[i][j]);
                visitado[i][j] = 0;
            }
        }

        if (busca_profundidade(0, 0)) {
            printf("COPS\n");
        } else {
            printf("ROBBERS\n");
        }
    }

    return 0;
}
