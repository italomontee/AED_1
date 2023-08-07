#include <stdio.h>
#include <stdlib.h>
#include "10_28_07_2023.h"


void Inicializar(ArvoreB * arv){

    arv->raiz = NULL;
}

int Inserirr(Elemento ** raiz, char crct){
    if (*raiz == NULL){
        Elemento * novo_e = malloc(sizeof(Elemento));
        novo_e->crc = crct;
        novo_e->direita = novo_e->esquerda = NULL;

        *raiz = novo_e;
    }
    else{
        if ((int)crct < (int)((*raiz)->crc)){
            Inserirr(&((*raiz)->esquerda), crct);
        }
        else {
        Inserirr(&((*raiz)->direita), crct);
        }
    }
}



void imprimirArvorePre(Elemento *raiz) {
    if (raiz != NULL) {
        printf("%c ", raiz->crc);
        imprimirArvorePre(raiz->direita);
        imprimirArvorePre(raiz->esquerda);
    }
}


void imprimirArvoreIn(Elemento *raiz) {
    if (raiz != NULL) {
        imprimirArvoreIn(raiz->esquerda);
        printf("%c ", raiz->crc);
        imprimirArvoreIn(raiz->direita);
    }
}


void imprimirArvorePos(Elemento *raiz) {
    if (raiz != NULL) {
        imprimirArvorePos(raiz->esquerda);
        imprimirArvorePos(raiz->direita);
        printf("%c ", raiz->crc);
    }
}


