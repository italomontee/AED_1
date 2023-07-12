#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
int main()
{
    TabelaHash TABELA;
    inicializarHash(TABELA);

    PESSOA p;
    p.codigo = 0;
    p.cpf =123;
    p.idade=15;
    p.nome = 'k';
    //INSERINDO
    TABELA.tabela[0] = malloc(sizeof(PESSOA));
    *(TABELA.tabela[0])= p;

    printf("nome: %d", p.codigo);
    //USANDO FUNÇÕES
    mostrarHash(TABELA);
    return 0;
}
