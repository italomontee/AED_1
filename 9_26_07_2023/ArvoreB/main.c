#include <stdio.h>
#include <stdlib.h>
#include "ArvoreB.h"

int main()
{
    ArvoreB arvore;
    Inicializar(&arvore);

    Inserir(&arvore, 24);
    Inserir(&arvore, 10);
    Inserir(&arvore, 32);
    Inserir(&arvore, 5);
    Inserir(&arvore, 12);
    Inserir(&arvore, 29);
    Inserir(&arvore, 35);


    printf("Pre Ordem:\n");
    imprimirArvorePre(arvore.raiz);
    printf("\n");

    printf("In Ordem:\n");
    imprimirArvoreIn(arvore.raiz);
    printf("\n");

    printf("Pos Ordem:\n");
    imprimirArvorePos(arvore.raiz);

    int c = Contador(arvore.raiz);
    printf("\nN de elementos: %d", c);

    return 0;
}
