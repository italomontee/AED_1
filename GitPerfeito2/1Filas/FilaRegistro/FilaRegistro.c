#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FilaRegistro.h"

void Inicializar(FILA* f) {
    f->inicio = NULL;
    f->fim = NULL;
}

void EntrarNaFila(FILA* fila, PESSOA pessoa) {
    ELEMENTO* novo_elemento = malloc(sizeof(ELEMENTO));
    if (novo_elemento == NULL) {
        return;  // Falha na alocação de memória
    }
    novo_elemento->pessoa = pessoa;
    novo_elemento->proximo = NULL;

    if (fila->inicio == NULL) {
        fila->inicio = novo_elemento;
        fila->fim = novo_elemento;
    } else {
        fila->fim->proximo = novo_elemento;
        fila->fim = novo_elemento;
    }
}

int SairDaFila(FILA* fila) {
    if (fila->inicio == NULL) {
        return 0;
    }

    ELEMENTO* primeiro_elemento = fila->inicio;
    fila->inicio = fila->inicio->proximo;
    free(primeiro_elemento);
    return 1;
}

int FurarFila(FILA* fila, PESSOA pessoa, int pos) {
    int count = 0;
    ELEMENTO* novo_elemento = malloc(sizeof(ELEMENTO));
    if (novo_elemento == NULL) {
        return 0;  // Falha na alocação de memória
    }
    novo_elemento->pessoa = pessoa;

    ELEMENTO* elemento_atual = fila->inicio;
    ELEMENTO* elemento_anterior = NULL;

    while (elemento_atual != NULL && count < pos) {
        elemento_anterior = elemento_atual;
        elemento_atual = elemento_atual->proximo;
        count++;
    }

    if (count == pos) {
        if (elemento_anterior == NULL) {
            // Inserir no início da fila
            novo_elemento->proximo = fila->inicio;
            fila->inicio = novo_elemento;
        } else {
            // Inserir no meio ou final da fila
            novo_elemento->proximo = elemento_atual;
            elemento_anterior->proximo = novo_elemento;
        }
        return 1;
    } else {
        // Posição inválida, liberar memória alocada
        free(novo_elemento);
        return 0;
    }
}

int Mostrar(FILA* fila) {
    ELEMENTO* elemento_atual = fila->inicio;
    while (elemento_atual != NULL) {
        printf("Nome: %s, Idade: %d, CPF: %s, Chave: %d\n",
               elemento_atual->pessoa.nome, elemento_atual->pessoa.idade,
               elemento_atual->pessoa.cpf, elemento_atual->pessoa.chave);
        elemento_atual = elemento_atual->proximo;
    }
    return 1;
}
