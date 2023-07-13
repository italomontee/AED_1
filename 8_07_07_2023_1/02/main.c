#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
int main()
{

    TAB_HASH TABELA;
    inicializar(&TABELA);



    PESSOA p;
    p.cod = 10;
    p.cpf =123;
    p.idade=15;
    p.nome = "kaua";

    inserir(&TABELA, p);


    p.cod = 100;
    p.cpf =133;
    p.idade=18;
    p.nome = "joao";
    inserir(&TABELA, p);



    printf("\n");

    mostrar(&TABELA);


    return 0;
}
