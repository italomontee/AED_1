#include <stdlib.h>
#include <stdio.h>
#include "aluno.h"

Turma criar_turma(int quantidade_alunos) {
    Turma turma;
    turma.quantidade_alunos = quantidade_alunos;
    return turma;
}

void inserir_aluno(Turma* turma, Aluno aluno) {
    if (turma->quantidade_alunos > 0) {
        turma->alunos[MAX_ALUNOS - turma->quantidade_alunos] = aluno;
        turma->quantidade_alunos--;
        printf("Aluno inserido na turma.\n");
    } else {
        printf("A turma está cheia.\n");
    }
}

Aluno buscar_aluno(Turma turma, int codigo) {
    for (int i = 0; i < MAX_ALUNOS; i++) {
        if (turma.alunos[i].codigo == codigo) {
            return turma.alunos[i];
        }
    }
    Aluno aluno_nulo = {0, "", 0, 0.0};
    return aluno_nulo;
}

void imprimir_alunos(Turma turma) {
    for (int i = 0; i < MAX_ALUNOS - turma.quantidade_alunos; i++) {
        printf("Codigo: %d, Nome: %s\n", turma.alunos[i].codigo, turma.alunos[i].nome);
    }
}
