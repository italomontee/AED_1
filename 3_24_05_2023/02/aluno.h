#ifndef TURMA_H
#define TURMA_H

#define MAX_ALUNOS 100

typedef struct {
    int codigo;
    char nome[50];
    int idade;
    float coeficiente;
} Aluno;

typedef struct {
    Aluno alunos[MAX_ALUNOS];
    int quantidade_alunos;
} Turma;

Turma criar_turma(int quantidade_alunos);
void inserir_aluno(Turma* turma, Aluno aluno);
Aluno buscar_aluno(Turma turma, int codigo);
void imprimir_alunos(Turma turma);

#endif
