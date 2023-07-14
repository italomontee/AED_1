#include <stdio.h>
#include <stdlib.h>
#include "Hash_Simples_Inteiro.h"
int main()
{

    TAB_HASH TABELA;
    Inicializar(&TABELA);

    NUMERO p;
    p.numero = 5;
    inserir(&TABELA, p);

    printf("\n");
    mostrar(&TABELA);

    return 0;
}
