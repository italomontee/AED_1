#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PilhaRegistro.h"

void Inicializar(PILHA* p) {
    p->topo = NULL;
}

int PilhaVazia(PILHA* p) {
    return p->topo == NULL;
}

void ColocarAeronave(PILHA* p, AVIAO aviao) {
    ELEMENTO* novo_elemento = malloc(sizeof(ELEMENTO));
    if (novo_elemento == NULL) {
        printf("Erro ao alocar memoria.\n");
        return;
    }
    novo_elemento->aviao = aviao;
    novo_elemento->proximo = p->topo;
    p->topo = novo_elemento;
}

void AdicionarAviao(PILHA* p, char modelo[50], char fabricante[50], int ano) {
    AVIAO aviao;
    strcpy(aviao.modelo, modelo);
    strcpy(aviao.fabricante, fabricante);
    aviao.ano = ano;

    ColocarAeronave(p, aviao);
}

void ListarAvioesHangar(PILHA* p) {
    if (PilhaVazia(p)) {
        printf("O hangar esta vazio.\n");
        return;
    }

    printf("Avioes no hangar:\n");
    ELEMENTO* elemento_atual = p->topo;
    while (elemento_atual != NULL) {
        printf("Modelo: %s, Fabricante: %s, Ano: %d\n",
               elemento_atual->aviao.modelo, elemento_atual->aviao.fabricante, elemento_atual->aviao.ano);
        elemento_atual = elemento_atual->proximo;
    }
}

void ListarPrimeiroAviao(PILHA* p) {
    if (PilhaVazia(p)) {
        printf("O hangar esta vazio.\n");
        return;
    }

    printf("Primeiro aviao no hangar:\n");
    printf("Modelo: %s, Fabricante: %s, Ano: %d\n",
           p->topo->aviao.modelo, p->topo->aviao.fabricante, p->topo->aviao.ano);
}

void LancarAviao(PILHA* p, int posicao) {
    if (posicao < 1) {
        printf("Posição invalida.\n");
        return;
    }

    ELEMENTO* elemento_anterior = NULL;
    ELEMENTO* elemento_atual = p->topo;
    int count = 1;

    while (elemento_atual != NULL && count < posicao) {
        elemento_anterior = elemento_atual;
        elemento_atual = elemento_atual->proximo;
        count++;
    }

    if (elemento_atual == NULL) {
        printf("Posiçao invalida.\n");
        return;
    }

    if (elemento_anterior == NULL) {
        p->topo = elemento_atual->proximo;
    } else {
        elemento_anterior->proximo = elemento_atual->proximo;
    }

    free(elemento_atual);
}
