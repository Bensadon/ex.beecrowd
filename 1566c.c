#include <stdio.h>
#include <stdlib.h>

int comparar(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int nc, n;
    int i;
    int *alturas;

    scanf("%d", &nc);

    while (nc > 0) {
        scanf("%d", &n);

        alturas = (int*)malloc(n * sizeof(int));

        for (i = 0; i < n; i++) {
            scanf("%d", &alturas[i]);
        }

        qsort(alturas, n, sizeof(int), comparar);

        for (i = 0; i < n; i++) {
            if (i == 0) {
                printf("%d", alturas[i]);
            } else {
                printf(" %d", alturas[i]);
            }
        }
        printf("\n");

        free(alturas);
        nc--;
    }

    return 0;
}
