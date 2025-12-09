#include <stdio.h>

int main() {
    int velocidade, tempo;

    while (scanf("%d %d", &velocidade, &tempo) != EOF) {
        int deslocamento = 2 * velocidade * tempo;
        printf("%d\n", deslocamento);
    }

    return 0;
}
