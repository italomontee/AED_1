#include <stdio.h>
#include <stdlib.h>
#include "ArvoreB.h"


void Inicializar(ArvoreB * arv){

    arv->raiz = NULL;
}

int Inserir(ArvoreB * arv, int num){
    if(arv->raiz == NULL){
        Elemento * e = malloc(sizeof(Elemento));
        e->num = num;
        e->direita = NULL;
        e->esquerda = NULL;
        arv->raiz = e;
        return 1;
    }
    else {
        Elemento * anterior = malloc(sizeof(Elemento));
        Elemento * e = arv->raiz;
        int menor = 0;
        while(e != NULL) {
            anterior = e;
            if(num <= e->num){
                e = e->esquerda;
                menor = 1;
            }
            else {
                e = e->direita;
                menor = 0;
            }
        }
        Elemento * novoElemento = malloc(sizeof(Elemento));
        novoElemento->num = num;
        novoElemento->direita = NULL;
        novoElemento->esquerda = NULL;
        if (menor == 0){
            anterior->direita = novoElemento;
        }
        else{
            anterior->esquerda = novoElemento;
        }

    }

    }

int Busca(Elemento *raiz, int num){
    if (raiz == NULL){
        return NULL;
    }
    if (raiz->num == num){
        return raiz;
    }
    if (num > raiz->num){
        return  (Busca(raiz->direita, num));
    }
    else{
        return (Busca(raiz->esquerda, num));
    }
}

void imprimirArvorePre(Elemento *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->num);
        imprimirArvorePre(raiz->esquerda);
        imprimirArvorePre(raiz->direita);
    }
}


void imprimirArvoreIn(Elemento *raiz) {
    if (raiz != NULL) {
        imprimirArvoreIn(raiz->esquerda);
        printf("%d ", raiz->num);
        imprimirArvoreIn(raiz->direita);
    }
}


void imprimirArvorePos(Elemento *raiz) {
    if (raiz != NULL) {
        imprimirArvorePos(raiz->esquerda);
        imprimirArvorePos(raiz->direita);
        printf("%d ", raiz->num);
    }
}

int count = 0;
int Contador(Elemento *raiz) {

    if (raiz != NULL) {
        Contador(raiz->esquerda);
        Contador(raiz->direita);
        count++;
    }

}
