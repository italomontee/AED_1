#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main()
{
    ArvoreB arvore;
    Inicializar(&arvore);

    Inserir(&arvore, 5);
    Inserir(&arvore, 7);
    Inserir(&arvore, 3);
    Inserir(&arvore, 4);

    imprimirArvore(arvore.raiz);

    return 0;
}
