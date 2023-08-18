#include <stdio.h>
#include <stdlib.h>
#include "ABB.h"


void Inicializar(ARVORE * arvore){
    arvore->raiz = NULL;
}

NO * AlocarNo(int numero){
    //alocar memoria para receber o numero
    NO * novoNo = malloc(sizeof(NO));
    novoNo->chave = numero;
    novoNo->direita = NULL;
    novoNo->esquerda = NULL;

    return novoNo;
}

void Inserir(NO ** no, int numero){
    if (*no == NULL){
        *no = AlocarNo(numero);
    }
    else{
        if (numero > ((*no)->chave)){
            Inserir(&((*no)->direita), numero);
        }
        else if (numero < (*no)->chave){
            Inserir(&((*no)->esquerda), numero);
        }
        else {
            printf("\nnumero ja inserido");
        }
    }
}
void ImprimirInOrder(NO * no){
    // no da esquerda, raiz, no da esquerda
    if (no != NULL){
        ImprimirInOrder(no->esquerda);
        printf("%d ", no->chave);
        ImprimirInOrder(no->direita);
    }

}
void ImprimirPreOrder(NO * no){
    // no da esquerda, no da direita, raiz
    if(no != NULL){
        ImprimirPreOrder(no->esquerda);
        ImprimirPreOrder(no->direita);
        printf("%d ", no->chave);
    }

}
void ImprimirPosOrder(NO * no){
    // no da direita, no da esquerda, raiz
    if (no != NULL){
        ImprimirPosOrder(no->direita);
        ImprimirPosOrder(no->esquerda);
        printf("%d ", no->chave);
    }

}

int percorrerEmLargura(NO * no) {
    if (no == NULL){
        return;
    }
    // Criação de uma fila para armazenar os nós
    NO* fila[1000];
    int inicio = 0, fim = 0;

    fila[fim++] = no;  // Adiciona o nó raiz à fila

    while (inicio < fim) {
        NO * atual = fila[inicio++];
        printf("%d ", atual->chave);

        // Adiciona os filhos do nó atual à fila
        if (atual->esquerda != NULL)
            fila[fim++] = atual->esquerda;
        if (atual->direita != NULL)
            fila[fim++] = atual->direita;
    }
}
void buscar(NO * no, int numero){
    if(no->chave == numero){
        printf("\nA chave %d está na arvore");
    }
    buscar(no->esquerda, numero);
    buscar(no->direita, numero);
}

int profundidade(NO* raiz, int codigo, int cont){
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
            profundidade(raiz->esquerda, codigo, cont);
        }
        else{
            cont++;
            profundidade(raiz->direita, codigo, cont++);
        }
    }

    }

int count;

int Contar(NO * no){
    if (no != NULL){
        Contar(no->esquerda);
        Contar(no->direita);
        count++;
    }
    return count;
}
