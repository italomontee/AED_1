#include <stdio.h>
#include <stdlib.h>
#include "AVLint.h"

int main()
{
    //Criar arvore

    AVL *arv = malloc(sizeof(AVL));
    Inicializar(arv);

    arv->raiz = InserirAVL(arv->raiz, 9);
    arv->raiz = InserirAVL(arv->raiz, 5);
    arv->raiz = InserirAVL(arv->raiz, 14);
    arv->raiz = InserirAVL(arv->raiz, 3);
    arv->raiz = InserirAVL(arv->raiz, 6);
    arv->raiz = InserirAVL(arv->raiz, 12);
    arv->raiz = InserirAVL(arv->raiz, 15);
    arv->raiz = InserirAVL(arv->raiz, 7);
    arv->raiz = InserirAVL(arv->raiz, 10);

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
