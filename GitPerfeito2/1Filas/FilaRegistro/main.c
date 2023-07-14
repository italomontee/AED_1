#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FilaRegistro.h"


int main() {
    FILA f;
    Inicializar(&f);

    PESSOA pessoa1 = {"Joao", 30, "12345678901", 1};
    PESSOA pessoa2 = {"Maria", 25, "98765432109", 2};
    PESSOA pessoa3 = {"Carlos", 35, "45678912304", 3};

    EntrarNaFila(&f, pessoa1);
    EntrarNaFila(&f, pessoa2);
    EntrarNaFila(&f, pessoa3);

    printf("Fila apos insercao:\n");
    Mostrar(&f);

    PESSOA pessoa4 = {"Ana", 28, "55555555555", 4};
    FurarFila(&f, pessoa4, 1);

    printf("Fila apos furar:\n");
    Mostrar(&f);

    SairDaFila(&f);

    printf("Fila apos remocao:\n");
    Mostrar(&f);

    return 0;
}
