#include <stdio.h>
#include <stdlib.h>
#include "ABBchar.h"


void Inicializar(ARVORE * arvore){
    arvore->raiz = NULL;
}

int Altura(NO* raiz){
    if(!raiz) return(-1);
    else return (raiz->h);
}
int Profundidade(NO* raiz, char codigo, int cont){
    if(raiz ==  NULL){
        cont = 0;
        printf("\n\nPaciente nao encontrado ou arvore sem elementos!");
        return cont;
    }
    if(raiz->chave == codigo){
        return cont;
    }
    else{
        if(codigo < raiz->chave){
            cont++;
            Profundidade(raiz->esquerda, codigo, cont);
        }
        else{
            cont++;
            Profundidade(raiz->direita, codigo, cont);
        }
    }

}
int Nivel(NO* raiz, char codigo, int cont){
    if(raiz ==  NULL){
        cont = 0;
        printf("\n\nPaciente nao encontrado ou arvore sem elementos!");
        return cont;
    }
    if(raiz->chave == codigo){
        return cont;
    }
    else{
        if(codigo < raiz->chave){
            cont++;
            Profundidade(raiz->esquerda, codigo, cont);
        }
        else{
            cont++;
            Profundidade(raiz->direita, codigo, cont);
        }
    }

}
int Contar(NO * no, int * count){

    if (no != NULL){
        Contar(no->esquerda, count);
        Contar(no->direita, count);
        (*count)++;
    }
    return (*count);
}
int maximo (int v1, int v2){
    if (v1>v2)
        return v1;
    else
        return v2;
}


NO * AlocarNo(char codigo){
    //alocar memoria para receber o numero
    NO * novoNo = malloc(sizeof(NO));
    novoNo->chave = codigo;
    novoNo->direita = NULL;
    novoNo->esquerda = NULL;
    novoNo->h = 1;

    return novoNo;
}
void InserirABB(NO ** no, char codigo){
    if (*no == NULL){
        *no = AlocarNo(codigo);
    }
    else{
        if (codigo > ((*no)->chave)){
            InserirABB(&((*no)->direita), codigo);
        }
        else if (codigo < (*no)->chave){
            InserirABB(&((*no)->esquerda), codigo);
        }
        else {
            printf("\nnumero ja inserido");
        }
    }
    (*no)->h = 1 + maximo(Altura((*no)->esquerda), Altura((*no)->direita));
}

void ImprimirInOrder(NO * no){
    // no da esquerda, raiz, no da esquerda
    if (no != NULL){
        ImprimirInOrder(no->esquerda);
        printf("%c ", no->chave);
        ImprimirInOrder(no->direita);
    }

}
void ImprimirPreOrder(NO * no){
    //raiz,no da esquerda, no da direita
    if(no != NULL){
        printf("%c ", no->chave);
        ImprimirPreOrder(no->esquerda);
        ImprimirPreOrder(no->direita);

    }

}
void ImprimirPosOrder(NO * no){
    // no da direita, no da esquerda, raiz
    if (no != NULL){
        ImprimirPosOrder(no->direita);
        ImprimirPosOrder(no->esquerda);
        printf("%c ", no->chave);
    }

}
int PercorrerEmLargura(NO * no) {
    if (no == NULL){
        return;
    }

    //valores iniciais
    NO * lista[1000];
    int inicio = 0;
    int fim = 0;

    //add raiz a lista
    lista[fim] = no;

    fim++;

    //looping

    while (inicio < fim){
        NO * atual = lista[inicio++];
        printf("%c ", atual->chave);
        if (atual->esquerda != NULL){
            lista[fim++] = atual->esquerda;
        }
        if (atual->direita != NULL){
            lista[fim++] = atual->direita;
        }
    }
}

void Buscar(NO * no, char codigo){
    if(no->chave == codigo){
        printf("\nA chave %d esta na arvore");
    }
    Buscar(no->esquerda, codigo);
    Buscar(no->direita, codigo);
}

