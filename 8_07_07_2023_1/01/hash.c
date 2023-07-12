#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int m_hasg (int cod_pess) {
    return (cod_pess % MAX);
}

void inicializarHash(TabelaHash tab){

    for (int i = 0; i < MAX; i++) {
        tab.tabela[i] = NULL;
    }
}

int inserir (TabelaHash tab, PESSOA pess) {

}

void mostrarHash (TabelaHash tab){
    for (int i = 0; i < MAX; i++) {
        printf("nome: %s", tab.tabela[i]->nome);
    }
}
PESSOA * busca(TabelaHash tab, int cod){
    for (int i = 0; i < MAX; i++) {
        if(tab.tabela[i]->codigo == cod) {
            printf("Encontrada a pessoa de codigo: %d", tab.tabela[i]->codigo);
            return (tab.tabela[i]);
        }
    }
}
