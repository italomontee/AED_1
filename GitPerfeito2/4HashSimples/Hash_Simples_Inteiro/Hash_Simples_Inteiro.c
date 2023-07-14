#include <stdio.h>
#include <stdlib.h>
#include "Hash_Simples_Inteiro.h"

void Inicializar(TAB_HASH *tab){
    for (int i = 0; i < MAX; i++){
        tab->tabela[i] = NULL;
    }
}

int mhash(int cod){
 return cod % MAX;
}

int inserir(TAB_HASH *tab, NUMERO num){

    int h= mhash(num.numero);

    while (tab->tabela[h] != NULL){
        h = (h+1) % MAX;
    }
    if (tab->tabela[h] == NULL){
        tab->tabela[h] = malloc(sizeof(NUMERO));
        *(tab->tabela[h]) = num;
        return 1;
    }
    return 0;
}



int excluir(TAB_HASH *tab, NUMERO num){
    int h = mhash(num.numero);
    while(tab->tabela[h]->numero != num.numero){
        h = (h+1) % MAX;
    }
    if(tab->tabela[h]->numero == num.numero){
        tab->tabela[h] = NULL;
    }
}

void mostrar(TAB_HASH *tab){
    for (int i = 0; i < MAX; i++){
        if(tab->tabela[i] != NULL){
            printf("num: %d\n", tab->tabela[i]->numero);

        } else {
            printf("null\n");
        }
    }
}
