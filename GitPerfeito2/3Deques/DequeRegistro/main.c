
#include <stdio.h>
#include <stdlib.h>
#include "DequeRegistro.h"

int main() {
    DEQUE deque;
    InicializaDeque(&deque);

    ALUNO aluno1 = {"Joao"};
    ALUNO aluno2 = {"Maria"};
    ALUNO aluno3 = {"Carlos"};

    InserirInicio(&deque, aluno1);
    InserirFim(&deque, aluno2);
    InserirInicio(&deque, aluno3);

    printf("Tamanho do deque: %d\n", TamanhoDeque(&deque));

    printf("Deque:\n");
    MostrarDeque(&deque);

    printf("Deque a partir da posicao 1:\n");
    MostrarDequeAPartir(&deque, 1, 'd');

    ExcluirInicio(&deque);

    printf("Deque apos excluir o primeiro elemento:\n");
    MostrarDeque(&deque);

    reinicializar(&deque);
}

