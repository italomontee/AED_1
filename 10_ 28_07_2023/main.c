#include <stdio.h>
#include <stdlib.h>
#include "ArvoreB.h"

int main() {
    ArvoreB arvore;
    Inicializar(&arvore);

    Inserirr(&(arvore.raiz), '(');
    Inserirr(&(arvore.raiz), 'a');
    Inserirr(&(arvore.raiz), '*');
    Inserirr(&(arvore.raiz), '(');
    Inserirr(&(arvore.raiz), '(');
    Inserirr(&(arvore.raiz), 'b');
    Inserirr(&(arvore.raiz), '-');
    Inserirr(&(arvore.raiz), 'c');
    Inserirr(&(arvore.raiz), ')');
    Inserirr(&(arvore.raiz), '/');
    Inserirr(&(arvore.raiz), 'd');
    Inserirr(&(arvore.raiz), ')');
    Inserirr(&(arvore.raiz), ')');

    imprimirArvoreIn(arvore.raiz);
    printf("\n");
    imprimirArvorePre(arvore.raiz);
    printf("\n");
    imprimirArvorePos(arvore.raiz);
    printf("\n");

    return 0;
}
