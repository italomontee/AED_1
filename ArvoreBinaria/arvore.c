#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

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

void imprimirArvore(Elemento *raiz) {
    if (raiz != NULL) {
        imprimirArvore(raiz->esquerda);

        printf("%d ", raiz->num);
        imprimirArvore(raiz->direita);
    }
}

int count = 0;
void Contador(Elemento *raiz) {

    if (raiz != NULL) {
        Contador(raiz->esquerda);
        Contador(raiz->direita);
        count++;
    }

}


