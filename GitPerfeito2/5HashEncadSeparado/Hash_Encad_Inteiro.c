#include <stdio.h>
#include <stdlib.h>
#include "Hash_Encad_Inteiro.h"

void inicializar(TAB_HASH* tab) {
    for (int i = 0; i < MAX; i++) {
        tab->tabela[i] = NULL;
    }
}

int mhash(int cod) {
    return (cod % MAX);
}

int inserir(TAB_HASH* tab, PESSOA pessoa_nova) {
    int h = mhash(pessoa_nova.chave);
    if (tab->tabela[h] == NULL) {
        ELEMENTO* novo_elemento = malloc(sizeof(ELEMENTO));
        novo_elemento->pess = pessoa_nova;
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
        elemento->pess = pessoa_nova;
        elemento->proximo = NULL;
        anterior->proximo = elemento;
    }
    return 1;
}

int excluir(TAB_HASH* tab, PESSOA pessoa_excluir) {
    int h = mhash(pessoa_excluir.chave);
    if (tab->tabela[h] == NULL) {
        return 0;  // Elemento não encontrado
    } else {
        ELEMENTO* elemento = tab->tabela[h];
        ELEMENTO* anterior = NULL;
        while (elemento != NULL) {
            if (elemento->pess.chave == pessoa_excluir.chave) {
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
            printf("Nome: %s, CPF: %s, Chave: %d, Idade: %d | ",
                   elemento->pess.nome, elemento->pess.cpf,
                   elemento->pess.chave, elemento->pess.idade);
            elemento = elemento->proximo;
        }
        printf("\n");
    }
}
