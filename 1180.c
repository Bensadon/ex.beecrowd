#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int v[1000];
    int i;
    
    for (i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    
    int menor = v[0];
    int pos = 0;
    
    for (i = 1; i < n; i++) {
        if (v[i] < menor) {
            menor = v[i];
            pos = i;
        }
    }
    
    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", pos);

}
