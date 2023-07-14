#include <stdio.h>
#include <stdlib.h>

#define M 11

typedef struct elemento {
    int chave;
    struct elemento* proximo;
} Elemento;

void inicializarTabela(Elemento** tabela) {
    for (int i = 0; i < M; i++) {
        tabela[i] = NULL;
    }
}

int hash(int chave) {
    return (2 * chave + 5) % M;
}

void inserir(Elemento** tabela, int chave) {
    int posicao = hash(chave);

    Elemento* novo_elemento = malloc(sizeof(Elemento));
    novo_elemento->chave = chave;
    novo_elemento->proximo = NULL;

    if (tabela[posicao] == NULL) {
        tabela[posicao] = novo_elemento;
    } else {
        Elemento* elemento_atual = tabela[posicao];
        while (elemento_atual->proximo != NULL) {
            elemento_atual = elemento_atual->proximo;
        }
        elemento_atual->proximo = novo_elemento;
    }
}

void mostrarTabela(Elemento** tabela) {
    printf("Tabela Hash:\n");
    for (int i = 0; i < M; i++) {
        printf("Posição %d: ", i);
        Elemento* elemento_atual = tabela[i];
        while (elemento_atual != NULL) {
            printf("%d ", elemento_atual->chave);
            elemento_atual = elemento_atual->proximo;
        }
        printf("\n");
    }
}

int main() {
    Elemento* tabela[M];
    inicializarTabela(tabela);

    int chaves[] = {12, 44, 13, 88, 23, 94, 11, 39, 20, 16, 5};
    int num_chaves = sizeof(chaves) / sizeof(chaves[0]);

    for (int i = 0; i < num_chaves; i++) {
        inserir(tabela, chaves[i]);
    }

    mostrarTabela(tabela);

    return 0;
}
