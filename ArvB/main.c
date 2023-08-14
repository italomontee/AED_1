#include "arvb.h"
#include <stdio.h>
#include <stdlib.h>


int main() {
    int item;

    Arvore *t = (Arvore *)malloc(sizeof(Arvore));
    inicializarArvore(t);
    inserir(t, 1);
    inserir(t, 2);
    inserir(t, 3);
    inserir(t, 12);
    inserir(t, 13);
    inserir(t, 15);
    inserir(t, 11);
    inserir(t, 28);
    inserir(t, 21);
    inserir(t, 7);
    imprimir(t->raiz);
    printf("\n");
    int num = 8;
    int chave = busca(t, num);
    if(chave == 1) printf("Valor %d encontrado.", num);
    else printf("Valor %d nao encontrado.", num);

    return 0;
}



    // printf("\n %d ", i);

    //delete(20, t->raiz);
    //printf("\n");
    //traversal(t->raiz);
