#include <stdio.h>
#include <stdlib.h>
#include "Hash_Encad_Inteiro.h"

int main() {
    TAB_HASH tabela;
    inicializar(&tabela);

    inserir(&tabela, 10);
    inserir(&tabela, 20);
    inserir(&tabela, 30);

    printf("Tabela apos inclusao:\n");
    mostrar(&tabela);

    excluir(&tabela, 20);

    printf("Tabela apos exclusao:\n");
    mostrar(&tabela);

    return 0;
}
