#include <stdio.h>
#include <stdlib.h>
#include "ArvoreB.h"

int main() {
    ArvoreB arvore;
    Inicializar(&arvore);

    Inserirr(&(arvore.raiz), 'a');
    Inserirr(&(arvore.raiz), 'b');
    Inserirr(&(arvore.raiz), 'c');

    imprimirArvoreIn(arvore.raiz);
    printf("\n");

    return 0;
}
