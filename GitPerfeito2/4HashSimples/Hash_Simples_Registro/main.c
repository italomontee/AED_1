#include <stdio.h>
#include <stdlib.h>
#include "Hash_Simples_Registro.h"
int main() {
    TAB_HASH tabela;
    Inicializar(&tabela);

    PESSOA pessoa1 = {"Joao", "12345678901", 30, 1};
    PESSOA pessoa2 = {"Maria", "98765432109", 25, 2};
    PESSOA pessoa3 = {"Carlos", "45678912304", 35, 3};

    Inserir(&tabela, pessoa1);
    Inserir(&tabela, pessoa2);
    Inserir(&tabela, pessoa3);

    printf("Tabela apos insercao ");
    Mostrar(&tabela);

    int chave_excluir = 2;
    Excluir(&tabela, chave_excluir);

    printf("Tabela apos exclusa:\n");
    Mostrar(&tabela);

    return 0;
}
