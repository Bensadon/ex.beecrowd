#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char c;
    struct no *prox;
} No;

void push(No **topo, char c) {
    No *novo = (No *) malloc(sizeof(No));
    if (novo) {
        novo->c = c;
        novo->prox = *topo;
        *topo = novo;
    }
}

int esta_vazia(No *topo) {
    if (topo == NULL) {
        return 1;
    } else {
        return 0;
    }
}

char pop(No **topo) {
    if (!esta_vazia(*topo)) {
        No *temp = *topo;
        char val = temp->c;
        *topo = temp->prox;
        free(temp);
        return val;
    }
    return '\0'; 
}

int main() {
    char exp[1002]; 
    
    while (fgets(exp, 1002, stdin) != NULL) {
        No *pilha = NULL;
        int i;
        int ok = 1;
        int tam = strlen(exp);

        if (exp[tam - 1] == '\n') {
            exp[tam - 1] = '\0';
            tam--;
        }

        for (i = 0; i < tam; i++) {
            if (exp[i] == '(') {
                push(&pilha, '(');
            } else if (exp[i] == ')') {
                if (esta_vazia(pilha)) {
                    ok = 0; 
                    break;
                } else {
                    pop(&pilha);
                }
            }
        }

        if (!esta_vazia(pilha)) {
            ok = 0;
        }

        if (ok) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
        
        while (!esta_vazia(pilha)) {
            pop(&pilha);
        }
    }
}
