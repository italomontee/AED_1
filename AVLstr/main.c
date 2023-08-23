#include <stdio.h>
#include <stdlib.h>
#include "AVLstr.h"

int main()
{
    //Criar arvore

    AVL *arv = malloc(sizeof(AVL));
    Inicializar(arv);



    arv->raiz = inserir(arv->raiz, "apple");
    arv->raiz = inserir(arv->raiz,  "banana");
    arv->raiz = inserir(arv->raiz,  "cherry");
    arv->raiz = inserir(arv->raiz, "date");
    arv->raiz = inserir(arv->raiz, "fig");



    ImprimirInOrder(arv->raiz);
    printf("\n");
    ImprimirPreOrder(arv->raiz);
    printf("\n");
    ImprimirPosOrder(arv->raiz);
    printf("\n");
    PercorrerEmLargura(arv->raiz);

    int  c=0;
    printf("\n");
    char char1[50] = "banana";
    char char2[50] = "cherry";
    printf("%s, %s",char1, char2);

    printf("\n\nTotal de %d\n", Contar(arv->raiz, &c));


    printf("\na palavra apple esta na profundidade %d\n", Profundidade(arv->raiz, "apple", 0));


    printf("\na palavra %s esta na altura %d\n", Altura(noencontrado));


    printf("\na letra c esta no nivel %d", Nivel(arv->raiz, 'c', 0));

    Buscar(arv->raiz, 'e');

    return 0;
}


