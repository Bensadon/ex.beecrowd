#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *joias[1000005];

int comparar(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main() {
    char buffer[1000005];
    int n = 0;
    int i;
    int distintas = 0;

    while (scanf("%s", buffer) != EOF) {
        joias[n] = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(joias[n], buffer);
        n++;
    }

    if (n > 0) {
        qsort(joias, n, sizeof(char *), comparar);

        distintas = 1;
        for (i = 1; i < n; i++) {
            if (strcmp(joias[i], joias[i - 1]) != 0) {
                distintas++;
            }
        }
    }

    printf("%d\n", distintas);

    return 0;
}
