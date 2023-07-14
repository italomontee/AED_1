#include <stdio.h>
#include <stdlib.h>
#include "PilhaInteiro.h"

void Inicializar(PILHA* p) {
    p->topo = NULL;
}

int PilhaVazia(PILHA* p) {
    return p->topo == NULL;
}

void Empilhar(PILHA* p, int numero) {
    ELEMENTO* novo_elemento = malloc(sizeof(ELEMENTO));
    if (novo_elemento == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    novo_elemento->numero = numero;
    novo_elemento->proximo = p->topo;
    p->topo = novo_elemento;
}

int Desempilhar(PILHA* p) {
    if (PilhaVazia(p)) {
        printf("A pilha está vazia.\n");
        return -1; // ou outro valor que represente um erro
    }

    ELEMENTO* elemento_desempilhado = p->topo;
    int numero_desempilhado = elemento_desempilhado->numero;
    p->topo = elemento_desempilhado->proximo;
    free(elemento_desempilhado);

    return numero_desempilhado;
}

void MostrarPilha(PILHA* p) {
    if (PilhaVazia(p)) {
        printf("A pilha está vazia.\n");
        return;
    }

    printf("Elementos na pilha:\n");
    ELEMENTO* elemento_atual = p->topo;
    while (elemento_atual != NULL) {
        printf("%d\n", elemento_atual->numero);
        elemento_atual = elemento_atual->proximo;
    }
}
