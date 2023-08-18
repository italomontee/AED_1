#include <stdio.h>
#include <stdlib.h>
#include "ABB.h"

int main()
{
    //Criar arvore

    ARVORE *arv = malloc(sizeof(ARVORE));
    Inicializar(arv);

    Inserir(&(arv->raiz), 9);
    Inserir(&(arv->raiz), 5);
    Inserir(&(arv->raiz), 14);
    Inserir(&(arv->raiz), 3);
    Inserir(&(arv->raiz), 6);
    Inserir(&(arv->raiz), 12);
    Inserir(&(arv->raiz), 15);
    Inserir(&(arv->raiz), 7);
    Inserir(&(arv->raiz), 10);

    ImprimirInOrder(arv->raiz);
    printf("\n");
    ImprimirPreOrder(arv->raiz);
    printf("\n");
    ImprimirPosOrder(arv->raiz);
    printf("\n");
    percorrerEmLargura(arv->raiz);

    printf("\nTotal de %d", Contar(arv->raiz));

    printf("\n%d", profundidade(arv->raiz, 5, 0));

    return 0;
}
