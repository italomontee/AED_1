#include <stdio.h>
#include <stdlib.h>
#include "FilaInteiro.h"

void Inicializar(FILA * f){
    f->inicio = NULL;
    f->fim = NULL;
}

void EntrarNaFila(FILA * fila, NUMERO num){
    //Alocar memoria para o novo elemento
    ELEMENTO * novo_elemento = malloc(sizeof(ELEMENTO));

    //Guardar valor no espaço da memoria
    novo_elemento->num = num;
    novo_elemento->proximo = NULL;

    //Entrar na fila
    //Se a fila estiver vazia
    if (fila->inicio == NULL){
        fila->inicio = novo_elemento;
        fila->fim = novo_elemento;

    } else { // Se não add no final
        fila->fim->proximo = novo_elemento;
        fila->fim = novo_elemento;
        novo_elemento->proximo = NULL;

        }


}

int SairDaFila(FILA * fila){
    if(fila->inicio == NULL){
        return 0;
    }
    //Guardar elemento a ser retirado
    ELEMENTO * i = malloc(sizeof(ELEMENTO));
    //Tirar do inicio
    fila->inicio = fila->inicio->proximo;
    free(i);
    return 1;

}

int FurarFila(FILA * fila, NUMERO num, int pos){
    int count = 0;
    ELEMENTO * i = malloc(sizeof(ELEMENTO));
    i->num = num;

    ELEMENTO * e = malloc(sizeof(ELEMENTO));
    e = fila->inicio;
    ELEMENTO * anterior = malloc(sizeof(ELEMENTO));
    while(e != NULL){
        if (count == pos){
            anterior->proximo = i;
            i->proximo = e;

            return 1;
        }
        anterior = e;
        e = e->proximo;
        count++;

    }
    return 1;
}

int Mostrar(FILA * fila){
    ELEMENTO *e = malloc(sizeof(ELEMENTO));
    e = fila->inicio;
    if (e == NULL){
        return 0;
    }
    while(e!= NULL){
        printf("Num: %d\n", e->num.num);
        e = e->proximo;
    }
    return 1;
}
