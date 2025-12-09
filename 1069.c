 #include <stdio.h>
#include <string.h>

int main() {
    int n, i, j, diamantes;
    char expressao[1001];
    int pilha_tamanho;

    scanf("%d", &n);
    getchar(); 

    for (i = 0; i < n; i++) {
        fgets(expressao, 1001, stdin);
        
        diamantes = 0;
        pilha_tamanho = 0;

        for (j = 0; j < strlen(expressao); j++) {
            if (expressao[j] == '<') {
                pilha_tamanho++;
            } else if (expressao[j] == '>') {
                if (pilha_tamanho > 0) {
                    diamantes++;
                    pilha_tamanho--;
                }
            }
        }
        printf("%d\n", diamantes);
    }

}
