#include <stdio.h>
#include <string.h>

#define MAX 10005

int dist[MAX];
int fila[MAX];

int inverter_valor(int n) {
    int res = 0;
    while (n > 0) {
        res = res * 10 + n % 10;
        n /= 10;
    }
    return res;
}

int main() {
    int casos;
    scanf("%d", &casos);

    while (casos > 0) {
        int a, b;
        scanf("%d %d", &a, &b);

        memset(dist, -1, sizeof(dist));

        int inicio = 0;
        int fim = 0;

        fila[fim] = a;
        fim++;
        dist[a] = 0;

        while (inicio < fim) {
            int atual = fila[inicio];
            inicio++;

            if (atual == b) {
                printf("%d\n", dist[b]);
                break;
            }

            int prox = atual + 1;
            if (prox <= 10000 && dist[prox] == -1) {
                dist[prox] = dist[atual] + 1;
                fila[fim] = prox;
                fim++;
            }

            prox = inverter_valor(atual);
            if (prox <= 10000 && dist[prox] == -1) {
                dist[prox] = dist[atual] + 1;
                fila[fim] = prox;
                fim++;
            }
        }

        casos--;
    }

    return 0;
}
