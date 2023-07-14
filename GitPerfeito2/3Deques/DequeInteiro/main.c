#include <stdio.h>
#include <stdlib.h>
#include "DequeInteiro.h"

int main() {
    DEQUE deque;
    InicializaDeque(&deque);

    InserirInicio(&deque, 5);
    InserirFim(&deque, 10);
    InserirInicio(&deque, 3);

    printf("Tamanho do deque: %d\n", TamanhoDeque(&deque));

    printf("Deque:\n");
    MostrarDeque(&deque);

    ExcluirInicio(&deque);

    printf("Deque após excluir o primeiro elemento:\n");
    MostrarDeque(&deque);

    Reinicializar(&deque);

    printf("Deque reinicializado:\n");
    MostrarDeque(&deque);

    return 0;
}
