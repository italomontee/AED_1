#include <stdio.h>
#include <stdlib.h>
#include "AVLchar.h"

int main()
{
    //Criar arvore

    AVL *arv = malloc(sizeof(AVL));
    Inicializar(arv);



    arv->raiz = inserir(arv->raiz, 'a');
    arv->raiz = inserir(arv->raiz, 'b');
    arv->raiz = inserir(arv->raiz, 'c');
    arv->raiz = inserir(arv->raiz, 'd');
    arv->raiz = inserir(arv->raiz, 'e');



    ImprimirInOrder(arv->raiz);
    printf("\n");
    ImprimirPreOrder(arv->raiz);
    printf("\n");
    ImprimirPosOrder(arv->raiz);
    printf("\n");

    int  c=0;


    printf("\nTotal de %d", Contar(arv->raiz, &c));

    printf("\na letra b esta na profundidade %d", Profundidade(arv->raiz, 'b', 0));

    printf("\na letra  esta na altura %d", Altura(arv->raiz->esquerda));

    printf("\na letra c esta no nivel %d", Nivel(arv->raiz, 'c', 0));

    Buscar(arv->raiz, 'e');

    return 0;
}


