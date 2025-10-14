#include <stdio.h>

void push_p(int *p, int *topo, int x) {
    (*topo)++;
    p[*topo] = x;
}

int pop_p(int *p, int *topo) {
    int val = p[*topo];
    (*topo)--;
    return val;
}

void push_f(int *f, int *fim, int x) {
    f[*fim] = x;
    (*fim)++;
}

int pop_f(int *f, int *ini) {
    int val = f[*ini];
    (*ini)++;
    return val;
}

void push_fp(int *fp, int *tam, int x) {
    fp[*tam] = x;
    (*tam)++;
}

int pop_fp(int *fp, int *tam) {
    int i;
    int max_val = -1;
    int max_idx = -1;
    
    for (i = 0; i < *tam; i++) {
        if (fp[i] > max_val) {
            max_val = fp[i];
            max_idx = i;
        }
    }
    
    for (i = max_idx; i < *tam - 1; i++) {
        fp[i] = fp[i+1];
    }
    
    (*tam)--;
    return max_val;
}

int main() {

    int n, i, op, x;
    
    while (scanf("%d", &n) != EOF) {
        
        int pilha[1000], fila[1000], fp[1000];
        
        int topo = -1;
        int ini = 0;
        int fim = 0;
        int tam_fp = 0;
        
        int ok_p = 1;
        int ok_f = 1;
        int ok_fp = 1;
        
        for (i = 0; i < n; i++) {
            scanf("%d %d", &op, &x);
            
            if (op == 1) {
                push_p(pilha, &topo, x);
                push_f(fila, &fim, x);
                push_fp(fp, &tam_fp, x);
            } else {
                if (ok_p == 1) {
                    if (topo < 0 || pop_p(pilha, &topo) != x) {
                        ok_p = 0;
                    }
                }
                
                if (ok_f == 1) {
                    if (ini == fim || pop_f(fila, &ini) != x) {
                        ok_f = 0;
                    }
                }
                
                if (ok_fp == 1) {
                    if (tam_fp == 0 || pop_fp(fp, &tam_fp) != x) {
                        ok_fp = 0;
                    }
                }
            }
        }
        
        int soma = ok_p + ok_f + ok_fp;
        
        if (soma == 0) {
            printf("impossible\n");
        } else if (soma > 1) {
            printf("not sure\n");
        } else { 
            if (ok_p == 1) printf("stack\n");
            if (ok_f == 1) printf("queue\n");
            if (ok_fp == 1) printf("priority queue\n");
        }
    }
}
