#include <stdio.h>
#include <stdlib.h>
#include "Hash_Encad_Inteiro.h"

int main() {
    TAB_HASH tabela;
    inicializar(&tabela);

    PESSOA pessoa1 = {"Joao", "12345678901", 1, 30};
    PESSOA pessoa2 = {"Maria", "98765432109", 2, 25};
    PESSOA pessoa3 = {"Carlos", "45678912304", 3, 35};

    inserir(&tabela, pessoa1);
    inserir(&tabela, pessoa2);
    inserir(&tabela, pessoa3);

    printf("Tabela apos inclusao:\n");
    mostrar(&tabela);

    PESSOA pessoa_excluir = {"Maria", "98765432109", 2, 25};
    excluir(&tabela, pessoa_excluir);

    printf("Tabela apos exclusao:\n");
    mostrar(&tabela);

    return 0;
}
