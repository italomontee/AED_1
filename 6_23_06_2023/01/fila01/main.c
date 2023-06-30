#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char * nome;
    int cod;
} AVIAO;

typedef struct aux {
    AVIAO strc_aviao;
    struct aux * proximo;
} ELEMENTO;

typedef struct {
    ELEMENTO *inicio;
    ELEMENTO *fim;
} PISTADEVOO;

void inicializar(PISTADEVOO* p){
    p->fim = NULL;
    p->inicio = NULL;
}

int reinicializar(PISTADEVOO * p) {
    ELEMENTO* i = p->inicio;
    ELEMENTO* apagar;

    while (i!= NULL){
        apagar = i;
        i = i -> proximo;
        free(apagar);
    }
    if (i == NULL) {
        return 0;
    }
    return 0;
}

int NumeroDeAvioes (PISTADEVOO * p) {
    int n=0;
    if (p ->inicio == NULL){
        return 0;
   }
   else {
        ELEMENTO * i = p->inicio;

        while (i != NULL){
            n++;
            i = i->proximo;
        }

   }
    return n;
}

int main() {
    printf("oi");
    return 0;
}
