
#include <stdio.h>
#include <stdlib.h>
#include "Hash_Encad_Inteiro.h"


void inicializar(TAB_HASH* tab) {
    for (int i = 0; i < MAX; i++) {
        tab->tabela[i] = NULL;
    }
}

int mhash(int chave) {
    return (chave % MAX);
}

int inserir(TAB_HASH* tab, int chave) {
    int h = mhash(chave);
    if (tab->tabela[h] == NULL) {
        ELEMENTO* novo_elemento = malloc(sizeof(ELEMENTO));
        novo_elemento->chave = chave;
        novo_elemento->proximo = NULL;
        tab->tabela[h] = novo_elemento;
    } else {
        ELEMENTO* elemento = tab->tabela[h];
        ELEMENTO* anterior = NULL;
        while (elemento != NULL) {
            anterior = elemento;
            elemento = elemento->proximo;
        }
        elemento = malloc(sizeof(ELEMENTO));
        elemento->chave = chave;
        elemento->proximo = NULL;
        anterior->proximo = elemento;
    }
    return 1;
}

int excluir(TAB_HASH* tab, int chave) {
    int h = mhash(chave);
    if (tab->tabela[h] == NULL) {
        return 0;  // Elemento não encontrado
    } else {
        ELEMENTO* elemento = tab->tabela[h];
        ELEMENTO* anterior = NULL;
        while (elemento != NULL) {
            if (elemento->chave == chave) {
                if (anterior == NULL) {
                    // O elemento a ser excluído é o primeiro da lista
                    tab->tabela[h] = elemento->proximo;
                } else {
                    anterior->proximo = elemento->proximo;
                }
                free(elemento);
                return 1;  // Elemento excluído com sucesso
            }
            anterior = elemento;
            elemento = elemento->proximo;
        }
        return 0;  // Elemento não encontrado
    }
}

void mostrar(TAB_HASH* tab) {
    for (int i = 0; i < MAX; i++) {
        ELEMENTO* elemento = tab->tabela[i];
        printf("Posicao %d: ", i);
        while (elemento != NULL) {
            printf("Chave: %d | ", elemento->chave);
            elemento = elemento->proximo;
        }
        printf("\n");
    }
}
