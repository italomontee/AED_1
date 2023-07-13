
#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

void inicializar(TAB_HASH *tab){
    for (int i = 0; i < MAX; i++){
        tab->tabela[i] = NULL;
    }
}
int mhash(int cod){
    return (cod % MAX);
}
void inserir(TAB_HASH *tab, PESSOA pessoa){
    int h = mhash(pessoa.cod);
    if (tab->tabela[h] == NULL){
        ELEMENTO* novo_elemento = malloc(sizeof(ELEMENTO));
        novo_elemento->pessoa = pessoa;
        novo_elemento->proximo=NULL;
        tab->tabela[h] =novo_elemento;

    } else {
        //colisoes
        ELEMENTO * elemento = tab->tabela[h];
        ELEMENTO * anterior = NULL;

        //percorre a lista até achar o vazio
        while (elemento != NULL) {
            anterior = elemento;
            elemento = elemento->proximo;
        }
        //cria espaço para esse elemento
        ELEMENTO* novo_elemento = malloc(sizeof(ELEMENTO));
        novo_elemento->pessoa = pessoa;
        novo_elemento->proximo = NULL;
        //insere valor
        anterior->proximo = novo_elemento;
    }

}
void mostrar(TAB_HASH *tab){
    ELEMENTO * e;
    for(int i = 0; i<MAX;i++){
        if (tab->tabela[i] != NULL){
            e = tab->tabela[i];
            while (e != NULL){
                printf("nome: %s -->", e->pessoa.nome);
                e = e->proximo;
            }
        }else{
            printf("Paciente Null\n");
        }
    }

}

PESSOA * buscar(TAB_HASH *tab, PESSOA pessoa){
    ELEMENTO * e ;
    int h = mhash(pessoa.cod);
    e = tab->tabela[h];
    while(e->pessoa.cod != pessoa.cod){
        e = e->proximo;
    }
    if (e->pessoa.cod == pessoa.cod){
        return &(e->pessoa);
    }


}
