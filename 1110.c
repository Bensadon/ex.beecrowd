#include <stdio.h>
#include <stdlib.h>



typedef struct a{

    int valor;
    struct a *proximo;

}carta;




carta* monta_baralho_original (int n){

  carta *point;
  carta *anterior;
  carta *cabeca;

  for (int i = 0; i < n; i++){

      point = (carta*) malloc (sizeof(carta));
    
      point->valor = (i+1);
    
      if(i == 0){
        point->proximo = NULL;
        cabeca = point;
      }

      else  {anterior->proximo = point;}

      anterior = point;
  }
  point->proximo = NULL;
  return cabeca;
}




carta* remover (carta *cabeca){

  carta *point = cabeca->proximo;

  free(cabeca);
  return (point);
}




carta *realoca (carta *cabeca){

  carta *point = cabeca;

  if(cabeca->proximo == NULL) return cabeca;

  while (point->proximo != NULL){
      point = point->proximo;
  }

  point->proximo = cabeca;
  point = cabeca->proximo;
  cabeca->proximo = NULL;

  return point;
}




carta* principal (carta *cabeca){

  printf("Discarded cards: ");
  while (cabeca->proximo != NULL){

      printf("%d" , cabeca->valor);
      cabeca = remover(cabeca);
      cabeca = realoca(cabeca);
      if(cabeca->proximo != NULL) printf(", ");
  }
  return cabeca;
}




int main(){

  int n;
  carta *point;

  scanf("%d" , &n);

  while(n != 0){


  point = monta_baralho_original(n);

  point = principal(point);

  printf("\n");

  printf("Remaining card: ");
  printf("%d\n" , point->valor);

  scanf("%d", &n);
  }
  return 0;
}
