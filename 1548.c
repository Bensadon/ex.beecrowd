#include <stdio.h>
#include <stdlib.h>



int compara (const void *a, const void *b){

  int va = *(int*) a;
  int vb = *(int*) b;

  return (vb - va);
}








int main(){

  int ntestes;
  int nalunos;
  int *entrada;
  int *ordenado;
  int cont;


  scanf("%d" , &ntestes);

  for (int i = 0; i < ntestes; i++){
      cont = 0;
      scanf("%d" , &nalunos);

      entrada = (int*) malloc (sizeof(int) * nalunos);
      ordenado = (int*) malloc (sizeof(int) * nalunos);

      for (int i = 0; i < nalunos; i++){
          scanf("%d" , &entrada[i]);
          ordenado [i] = entrada[i];
      }

      qsort(ordenado, nalunos, sizeof(int) , compara);

      for (int i = 0; i < nalunos; i++){
          if(ordenado[i] == entrada[i]){
            cont++;
          }
      }
      
      printf("%d\n" , cont);
      free(entrada);
      free(ordenado);
  }

  return 0;
  }
