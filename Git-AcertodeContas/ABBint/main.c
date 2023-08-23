#include <stdio.h>
#include <stdlib.h>
#include "ABBint.h"

int main()
{
    //Criar arvore

    ARVORE *arv = malloc(sizeof(ARVORE));
    Inicializar(arv);

    InserirABB(&(arv->raiz), 9);
    InserirABB(&(arv->raiz), 5);
    InserirABB(&(arv->raiz), 14);
    InserirABB(&(arv->raiz), 3);
    InserirABB(&(arv->raiz), 6);
    InserirABB(&(arv->raiz), 12);
    InserirABB(&(arv->raiz), 15);
    InserirABB(&(arv->raiz), 7);
    InserirABB(&(arv->raiz), 10);

    ImprimirInOrder(arv->raiz);
    printf("\n");
    ImprimirPreOrder(arv->raiz);
    printf("\n");
    ImprimirPosOrder(arv->raiz);
    printf("\n");
    PercorrerEmLargura(arv->raiz);
    int * c;
    (*c) = 0;

    printf("\nTotal de %d", Contar(arv->raiz, c));

    printf("\no numero 5 esta na profundidade %d", Profundidade(arv->raiz, 5, 0));

    printf("\no numero 5 esta na altura %d", Altura(arv->raiz->esquerda));

    printf("\no numero 5 esta no nivel %d", Nivel(arv->raiz, 5, 0));

    Buscar(arv->raiz, 5);

    return 0;
}
