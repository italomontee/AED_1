#include <stdio.h>
#include <stdlib.h>
#include "Hash_Simples_Registro.h"
void Inicializar(TAB_HASH* tab) {
    for (int i = 0; i < MAX; i++) {
        tab->tabela[i] = NULL;
    }
}

int mhash(int chave) {
    return chave % MAX;
}

int Inserir(TAB_HASH* tab, PESSOA pessoa) {
    int h = mhash(pessoa.chave);

    ELEMENTO* novo_elemento = malloc(sizeof(ELEMENTO));
    if (novo_elemento == NULL) {
        return 0;  // Falha na alocação de memória
    }
    novo_elemento->pessoa = pessoa;
    novo_elemento->proximo = NULL;

    if (tab->tabela[h] == NULL) {
        tab->tabela[h] = novo_elemento;
    } else {
        ELEMENTO* elemento = tab->tabela[h];
        while (elemento->proximo != NULL) {
            elemento = elemento->proximo;
        }
        elemento->proximo = novo_elemento;
    }

    return 1;  // Inserção bem-sucedida
}

int Excluir(TAB_HASH* tab, int chave) {
    int h = mhash(chave);

    ELEMENTO* elemento = tab->tabela[h];
    ELEMENTO* anterior = NULL;
    while (elemento != NULL) {
        if (elemento->pessoa.chave == chave) {
            if (anterior == NULL) {
                tab->tabela[h] = elemento->proximo;
            } else {
                anterior->proximo = elemento->proximo;
            }
            free(elemento);
            return 1;  // Exclusão bem-sucedida
        }
        anterior = elemento;
        elemento = elemento->proximo;
    }

    return 0;  // Pessoa não encontrada
}

void Mostrar(TAB_HASH* tab) {
    for (int i = 0; i < MAX; i++) {
        ELEMENTO* elemento = tab->tabela[i];
        printf("Posicao %d: ", i);
        while (elemento != NULL) {
            printf("Nome: %s, CPF: %s, Idade: %d, Chave: %d | ",
                   elemento->pessoa.nome, elemento->pessoa.cpf,
                   elemento->pessoa.idade, elemento->pessoa.chave);
            elemento = elemento->proximo;
        }
        printf("\n");
    }
}
