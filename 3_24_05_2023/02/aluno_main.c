#include "aluno.h"
#include <stdio.h>

int main() {
    Turma turma = criar_turma(5);

    Aluno aluno1 = {1, "João", 20, 8.5};
    Aluno aluno2 = {2, "Maria", 19, 7.8};
    Aluno aluno3 = {3, "Pedro", 21, 9.2};
    Aluno aluno4 = {4, "Ana", 22, 6.9};
    Aluno aluno5 = {5, "Carlos", 20, 7.2};

    inserir_aluno(&turma, aluno1);
    inserir_aluno(&turma, aluno2);
    inserir_aluno(&turma, aluno3);
    inserir_aluno(&turma, aluno4);
    inserir_aluno(&turma, aluno5);

    Aluno aluno_encontrado = buscar_aluno(turma, 3);
    printf("Aluno encontrado: Codigo: %d, Nome: %s\n", aluno_encontrado.codigo, aluno_encontrado.nome);

    imprimir_alunos(turma);

    return 0;
}
