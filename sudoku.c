#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, inst;
    int i, j, k, num;
    int ok; 
    int verificador[10];
    
    scanf("%d", &n);

    for (inst = 1; inst <= n; inst++) {
        
        int **matriz;
        matriz = (int **) malloc(9 * sizeof(int *));
        for (i = 0; i < 9; i++) {
            matriz[i] = (int *) malloc(9 * sizeof(int));
        }
        
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
                scanf("%d", &matriz[i][j]);
            }
        }

        ok = 1; 

        for (i = 0; i < 9; i++) {
            for (k = 1; k <= 9; k++) verificador[k] = 0;
            
            for (j = 0; j < 9; j++) {
                num = matriz[i][j];
                if (num < 1 || num > 9 || verificador[num] == 1) {
                    ok = 0;
                    break;
                }
                verificador[num] = 1;
            }
            if (ok == 0) break; 
        }

        if (ok == 1) {
            for (j = 0; j < 9; j++)
