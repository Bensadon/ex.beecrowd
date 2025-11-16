#include <stdio.h>
#include<stdlib.h>
#include <string.h>


typedef struct a {
    struct a *direita;
    struct a *esquerda;
    char cont;
} No;


No* adicionarArv(No *raiz, char letra){

    if (raiz == NULL) {
        No *novo = (No*) malloc (sizeof(No));
        novo->cont = letra;
        novo->direita = NULL;
        novo->esquerda = NULL;
        return novo;
    }
    else {
        if (letra < raiz->cont){
            raiz->esquerda =  adicionarArv(raiz->esquerda, letra);
            return raiz;
        }
        else{
            raiz->direita =  adicionarArv(raiz->direita, letra);
            return raiz;
        }
    }
}


void imprimeIN (No *raiz, int *primeiro){

    if(raiz != NULL){
        imprimeIN(raiz->esquerda, primeiro);
        if(*primeiro == 1){
            printf("%c", raiz->cont);
            *primeiro = 0;
        }
        else{
            printf(" %c", raiz->cont);
        }
        imprimeIN(raiz->direita, primeiro);
    }
}


void imprimePRE (No *raiz, int *primeiro){

    if (raiz != NULL){
        if (*primeiro == 1){
            printf("%c" , raiz->cont);
            *primeiro = 0;
        }
        else{
        printf(" %c" , raiz->cont);
        }
        imprimePRE(raiz->esquerda, primeiro);
        imprimePRE(raiz->direita, primeiro);
    }
}


void imprimePOS(No *raiz, int *primeiro){

    if (raiz != NULL){
        imprimePOS(raiz->esquerda, primeiro);
        imprimePOS(raiz->direita, primeiro);
        if (*primeiro == 1){
            printf("%c" , raiz->cont);
            *primeiro = 0;
        }
        else{
            printf(" %c" , raiz->cont);
        }
    }
}


void pesquisa (No *raiz, char l){

    if (raiz == NULL){
        printf("%c nao existe\n" , l);
        return;
    }
    if(l == raiz->cont){
        printf("%c existe\n", l);
        return;
    }
    if(l < raiz->cont){
        pesquisa(raiz->esquerda, l);
    }
    else{
        pesquisa(raiz->direita, l);
    }
}




int main(){

    No *raiz = NULL;
    char comando [20];
    char letra;

    while (scanf("%s" , comando) != EOF){

        if (strcmp(comando, "I") == 0){
            scanf(" %c" , &letra);
            raiz = adicionarArv(raiz, letra);
        }
        else if(strcmp(comando , "P") == 0){
            scanf(" %c" , &letra);
            pesquisa(raiz, letra);
        }
        else if(strcmp(comando , "INFIXA") == 0){
            int primeiro = 1;
            imprimeIN(raiz , &primeiro);
            printf("\n");
        }
        else if(strcmp(comando, "POSFIXA") == 0){
            int primeiro = 1;
            imprimePOS(raiz , &primeiro);
            printf("\n");
        }
        else if(strcmp(comando, "PREFIXA") == 0){
            int primeiro = 1;
            imprimePRE(raiz , &primeiro);
            printf("\n");
        }
    }
}
