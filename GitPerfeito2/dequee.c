#include <stdio.h>
#include <stdlib.h>
#include "dequee.h"

void InicializaDeque(DEQUE* d) {
    d->cabeca = malloc(sizeof(ELEMENTO));
    d->cabeca->anterior = d->cabeca;
    d->cabeca->proximo = d->cabeca;
}

int TamanhoDeque(DEQUE* d) {
    ELEMENTO* i = d->cabeca->proximo;
    int t = 0;
    while (i != d->cabeca) {
        t++;
        i = i->proximo;
    }
    return t;
}

void MostrarDeque(DEQUE* d) {
    ELEMENTO* i = d->cabeca->proximo;
    while (i != d->cabeca) {
        printf("%d\n", i->numero);
        i = i->proximo;
    }
}

int RetornarP(DEQUE *d, int pos){
    ELEMENTO* i = d->cabeca->proximo;
    int count = 0;
    while (count != pos) {
        i = i->proximo;
        count++;
    }
    if(count == pos){
        return (i->numero);
    }
}

void InserirInicio(DEQUE* d, int numero) {
    ELEMENTO* i = malloc(sizeof(ELEMENTO));
    i->numero = numero;
    i->proximo = d->cabeca->proximo;
    i->anterior = d->cabeca;
    d->cabeca->proximo->anterior = i;
    d->cabeca->proximo = i;
}

void InserirFim(DEQUE* d, int numero) {
    ELEMENTO* i = malloc(sizeof(ELEMENTO));
    i->numero = numero;
    i->proximo = d->cabeca;
    i->anterior = d->cabeca->anterior;
    d->cabeca->anterior->proximo = i;
    d->cabeca->anterior = i;
}

void InserirIntercalado(DEQUE *finald, DEQUE * deque1, DEQUE * deque2){
    int tam1 = TamanhoDeque(deque1);
    int tam2 = TamanhoDeque(deque2);
    int tam3 = tam1 + tam2;
    int count0 = 0;
    int count1= 0;
    int count2= 0;

    for(int i = 0; i<tam3; i++){
        // se for deque 1
        if(count0 % 2 ==0){
            InserirFim(finald, RetornarP(deque1, count1));
            count1++;
        }
        else {
            InserirFim(finald, RetornarP(deque2, count2));
            count2++;
        }
        count0++;

    }

}

void ExcluirInicio(DEQUE* d) {
    if (d->cabeca->proximo == d->cabeca) {
        printf("O deque esta vazio.\n");
        return;
    }

    ELEMENTO* elemento_removido = d->cabeca->proximo;
    d->cabeca->proximo = elemento_removido->proximo;
    elemento_removido->proximo->anterior = d->cabeca;
    free(elemento_removido);
}

void ExcluirFim(DEQUE* d) {
    if (d->cabeca->anterior == d->cabeca) {
        printf("O deque esta vazio.\n");
        return;
    }

    ELEMENTO* elemento_removido = d->cabeca->anterior;
    d->cabeca->anterior = elemento_removido->anterior;
    elemento_removido->anterior->proximo = d->cabeca;
    free(elemento_removido);
}

void ExcluirElemento(DEQUE* d, int numero) {
    ELEMENTO* i = d->cabeca->proximo;
    while (i != d->cabeca) {
        if (i->numero == numero) {
            i->anterior->proximo = i->proximo;
            i->proximo->anterior = i->anterior;
            free(i);
            return;
        }
        i = i->proximo;
    }
    printf("Numero nao encontrado no deque.\n");
}

void Reinicializar(DEQUE* d) {
    ELEMENTO* i = d->cabeca->proximo;
    while (i != d->cabeca) {
        ELEMENTO* elemento_removido = i;
        i = i->proximo;
        free(elemento_removido);
    }
    d->cabeca->proximo = d->cabeca;
    d->cabeca->anterior = d->cabeca;
}
