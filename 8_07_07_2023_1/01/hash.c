#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#define MAX 10

int m_hash (int cod_pess) {
    return (cod_pess % MAX);
}

void inicializarHash(TabelaHash* tab){

    for (int i = 0; i < MAX; i++) {
        tab->tabela[i] = NULL;
    }
}

int inserir(TabelaHash* tab, PESSOA pess) {
    int h = m_hash(pess.codigo);
    // ENCONTRAR CASA VAZIA
    while (tab->tabela[h] != NULL) {
        h = (h + 1) % MAX;
    }
    // ENCONTROU UMA CASA VAZIA
    if (tab->tabela[h] == NULL) {
        tab->tabela[h] = malloc(sizeof(PESSOA));
        *(tab->tabela[h]) = pess;
    }
    return 0;
}

void mostrarHash (TabelaHash* tab){
    for (int i = 0; i < MAX; i++) {
        if (tab->tabela[i] != NULL){
            printf("nome: %s\n", tab->tabela[i]->nome);
            printf("idade: %d\n", tab->tabela[i]->idade);
            printf("codigo: %d\n", tab->tabela[i]->codigo);
            printf("cpf: %d\n", tab->tabela[i]->cpf);
            printf("\n");
        } else {
            printf("Passoa: %d NULL\n", i);
            printf("\n");

        }

    }
}
PESSOA * busca(TabelaHash tab, int cod){
    int h = m_hash(cod);
    while (tab.tabela[h] != NULL){
        if(tab.tabela[h]->codigo == cod){
            return tab.tabela[h];
        h = (h+1)% MAX;
        }
        return NULL;
    }
}
