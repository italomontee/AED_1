#include <stdio.h>
#include <stdlib.h>
#include "DequeInteiro.h"

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

void ExcluirInicio(DEQUE* d) {
    if (d->cabeca->proximo == d->cabeca) {
        printf("O deque está vazio.\n");
        return;
    }

    ELEMENTO* elemento_removido = d->cabeca->proximo;
    d->cabeca->proximo = elemento_removido->proximo;
    elemento_removido->proximo->anterior = d->cabeca;
    free(elemento_removido);
}

void ExcluirFim(DEQUE* d) {
    if (d->cabeca->anterior == d->cabeca) {
        printf("O deque está vazio.\n");
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
    printf("Número não encontrado no deque.\n");
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
