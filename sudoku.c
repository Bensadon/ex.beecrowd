#include <stdio.h>


//RECEBENDO A MATRIZ DE ENTRADA
void matriz_entrada(int entrada[9][9]){
int x;

for(int i = 0; i < 9; i++){
    for (int j = 0; j < 9; j++){
        scanf("%d" , &x);
        entrada[i][j] = x;  
    }
}
}


//*CHECANDO LINHAS*
int checar_linhas(int entrada[9][9]){

int num_atual;

for (int i = 0; i < 9; i++){
int vet[10] = {0};    
    for(int j = 0; j < 9; j++){
        num_atual = entrada[i][j];
        if (num_atual >= 1 && num_atual <= 9) {
            if (vet[num_atual] == 1){
                return 0;
            }
            else {
                vet[num_atual] = 1;
            }
        }
    }
}
return 1;
}

//*CHECANDO COLUNAS
int checar_colunas(int entrada[9][9]){

int num_atual;

for (int i = 0; i < 9; i++){
int vet[10] = {0};    
    for(int j = 0; j < 9; j++){
        num_atual = entrada[j][i];
        if (num_atual >= 1 && num_atual <= 9) {
            if (vet[num_atual] == 1){
                return 0;
            }
            else {
                vet[num_atual] = 1;
            }
        }
    }
}
return 1;
}

//CHECA BLOCOS
int checar_blocos (int entrada[9][9]){

    for (int bloco_i = 0; bloco_i < 9; bloco_i += 3) {
        for (int bloco_j = 0; bloco_j < 9; bloco_j += 3) {
            
            int chec[10] = {0}; 

            
            for (int i = bloco_i; i < bloco_i + 3; i++) {
                for (int j = bloco_j; j < bloco_j + 3; j++) {
                    
                    int num_atual = entrada[i][j];

                    if (num_atual >= 1 && num_atual <= 9) {
                        if (chec[num_atual] == 1) {
                            return 0; 
                        }
                        chec[num_atual] = 1;
                    }
                }
            }
        }
    }
    
    return 1;
}

int main(){

    
    
    int ninst;
    scanf("%d", &ninst);

    for (int k = 1; k <= ninst; k++) {
        int matriz[9][9];
        matriz_entrada(matriz);

        printf("Instancia %d\n", k);

        if (checar_linhas(matriz) == 1 && checar_colunas(matriz) == 1 && checar_blocos(matriz) == 1){
            printf("SIM\n");
        }
        else{
            printf("NAO\n");
        }

        printf("\n");
    }

    return 0;
}
