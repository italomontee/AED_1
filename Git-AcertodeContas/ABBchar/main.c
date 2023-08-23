#include <stdio.h>
#include <stdlib.h>
#include "ABBchar.h"

int main()
{
    //Criar arvore

    ARVORE *arv = malloc(sizeof(ARVORE));
    Inicializar(arv);

    InserirABB(&(arv->raiz), 'j');
    InserirABB(&(arv->raiz), 'g');
    InserirABB(&(arv->raiz), 'd');
    InserirABB(&(arv->raiz), 'q');
    InserirABB(&(arv->raiz), 'z');
    InserirABB(&(arv->raiz), 't');
    InserirABB(&(arv->raiz), 'e');
    InserirABB(&(arv->raiz), 'c');
    InserirABB(&(arv->raiz), 's');

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

    printf("\na letra 'q'esta na altura %d", Altura(arv->raiz->esquerda));

    printf("\na letra 'q' esta no nivel %d", Nivel(arv->raiz, 'q', 0));

    Buscar(arv->raiz, 5);

    return 0;


}
