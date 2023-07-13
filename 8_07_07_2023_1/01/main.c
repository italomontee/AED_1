#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
int main()
{

    TabelaHash TABELA;
    inicializarHash(&TABELA);

    PESSOA p;
    p.codigo = 10;
    p.cpf =123;
    p.idade=15;
    p.nome = "kaua";
    inserir(&TABELA, p);

    p.codigo = 13;
    p.cpf =133;
    p.idade=18;
    p.nome = "joao";
    inserir(&TABELA, p);

    printf("\n");
    mostrarHash(&TABELA);

    return 0;
}
