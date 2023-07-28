#include <stdio.h>
#include <stdlib.h>
#include "AB.h"

//Funções Arvores
void InicializarArvore(ArvoreB * arvore){
    arvore->raiz = NULL;
}

void InserirArvore(ElementoA** raiz, ElementoA novo_elemento){
    if(raiz == NULL){
       //Alocar memoria
        ElementoA * novo = malloc(sizeof(ElementoA));
        novo->caracter = novo_elemento.caracter;
        novo->direita = NULL;
        novo->esquerda = NULL;
        *raiz = novo;
    } else {
        InserirArvore(&(*raiz)->esquerda, novo_elemento);
        InserirArvore(&(*raiz)->direita, novo_elemento);
    }
}


void ImprimirArvoreIn(ElementoA * raiz) {
    if (raiz != NULL) {
        ImprimirArvoreIn(raiz->esquerda);
        printf("%c", raiz->caracter);
        ImprimirArvoreIn(raiz->direita);
    }
}


