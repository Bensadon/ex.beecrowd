#include <stdio.h>
#include <stdlib.h>




typedef struct a{
    int valor;
    struct a *proximo;
}vagao;



vagao* adicionar (vagao *cabeca , int num){

vagao *novo;

novo = (vagao*) malloc(sizeof(vagao));

novo->proximo = cabeca;
novo->valor = num;

return novo;
}



vagao* remover (vagao *cabeca){

vagao *v;

v = cabeca->proximo;
free(cabeca);

return v;
}


//recebe um vetor e qnt de elementos do vet
int verificacao (int *saida, int n){

int prox_a = 1;
vagao *cabeca = NULL;
int alvo;
int c = 0;


while (c < n){
alvo = saida[c];

if(alvo == prox_a){
    prox_a++;
    c++;
}

else if(alvo < prox_a){
    if(cabeca == NULL || cabeca->valor != alvo){return 1;}
    cabeca = remover(cabeca);
    c++;
}

else if (alvo > prox_a){
while(alvo != prox_a){
cabeca = adicionar(cabeca, prox_a);
prox_a++;
}
prox_a++;
c++;
}
}
return 0;
}



int main(){

int n = -1;
int result;
int *saida;

scanf("%d" , &n);

while(n != 0){

saida = (int*) malloc (sizeof(int) * n);

for (int i = 0; i < n; i++){
scanf("%d" , &saida[i]);
}

while (saida[0] != 0){
result = verificacao(saida , n);

    if(result == 1){printf("No\n");}
    else{printf("Yes\n");}

for(int i = 0; i < n; i++){
scanf("%d" , &saida[i]);
if (saida[0] == 0){
break;
}
}
}
scanf("%d", &n);
printf("\n");
free(saida);
}
}
