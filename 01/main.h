#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct {
    int matricula;
    char nome[20];
    int idade;
} alunos;

typedef struct {
    alunos alun;
    int proximo;
} elemento;

typedef struct {
    elemento matr[MAX];
    int inicio;
    int disponivel;
} lista_chave;

void Inicializar(lista_chave* m);
int Tamanho(lista_chave* m);
void Exibir(lista_chave *m);
int BuscaSeqOrd(lista_chave *m, int elem);
int InserirOrdenado(lista_chave *m, alunos aluno);
int Excluir(lista_chave *m, int matricula);
int AlterarMatricula(lista_chave *m, int matricula, int nova_matricula);
void Liberar(lista_chave *m);
void ListaVazia(lista_chave *m);
void ListaCheia(lista_chave *m);

void Inicializar(lista_chave* m){
    for (int i = 0; i < MAX - 1; i++) {
        m->matr[i].proximo = i + 1;
    }
    
    m->matr[MAX - 1].proximo = -1;
    m->inicio = -1;
    m->disponivel = 0;
}

int Tamanho(lista_chave* m){
    int tam = 0;
    int i = m->inicio;
    while (i != -1) {
        tam++;
        i = m->matr[i].proximo;
    }
    return tam;
}

void Exibir(lista_chave *m){
    int i = m->inicio;
    while (i != -1) {
        printf("Aluno: %s\n", m->matr[i].alun.nome);
        printf("Idade: %d\n", m->matr[i].alun.idade);
        printf("Matricula: %d\n", m->matr[i].alun.matricula);
        i = m->matr[i].proximo;
    }
}

int BuscaSeqOrd(lista_chave *m, int elem) {
    int i = m->inicio;
    while (i != -1 && m->matr[i].alun.matricula < elem) {
        i = m->matr[i].proximo;
    }
    if (i != -1 && m->matr[i].alun.matricula == elem) {
        return i;
    } else {
        return -1;
    }
}

int InserirOrdenado(lista_chave *m, alunos aluno) {
    int posicao_atual = m->inicio;
    int posicao_anterior = -1;

    // Encontrar a posição correta para inserção
    while (posicao_atual != -1 && m->matr[posicao_atual].alun.matricula < aluno.matricula) {
        posicao_anterior = posicao_atual;
        posicao_atual = m->matr[posicao_atual].proximo;
    }

    // Verificar se a lista está cheia
    if (m->disponivel == -1) {
        printf("A lista esta cheia. Nao e possível inserir.\n");
        return -1;
    }

    // Atualizar a posição do novo elemento na lista
    int nova_posicao = m->disponivel;
    m->disponivel = m->matr[m->disponivel].proximo;
    m->matr[nova_posicao].alun = aluno;

    // Inserir o elemento na posição correta
    if (posicao_anterior == -1) {
        m->matr[nova_posicao].proximo = m->inicio;
        m->inicio = nova_posicao;
    } else {
        m->matr[nova_posicao].proximo = m->matr[posicao_anterior].proximo;
        m->matr[posicao_anterior].proximo = nova_posicao;
    }

    return nova_posicao;
}

int Excluir(lista_chave *m, int matricula) {
    int posicao_atual = m->inicio;
    int posicao_anterior = -1;

    // Encontrar a posição do elemento a ser excluído
    while (posicao_atual != -1 && m->matr[posicao_atual].alun.matricula != matricula) {
        posicao_anterior = posicao_atual;
        posicao_atual = m->matr[posicao_atual].proximo;
    }

    // Verificar se o elemento foi encontrado
    if (posicao_atual == -1) {
        printf("Elemento não encontrado na lista.\n");
        return -1;
    }

    // Atualizar a lista encadeada
    if (posicao_anterior == -1) {
        m->inicio = m->matr[posicao_atual].proximo;
    } else {
        m->matr[posicao_anterior].proximo = m->matr[posicao_atual].proximo;
    }

    // Liberar a posição excluída para reutilização
    m->matr[posicao_atual].proximo = m->disponivel;
    m->disponivel = posicao_atual;

    return posicao_atual;
}

int AlterarMatricula(lista_chave *m, int matricula, int nova_matricula) {
    int posicao_atual = m->inicio;

    // Encontrar a posição do elemento a ser alterado
    while (posicao_atual != -1 && m->matr[posicao_atual].alun.matricula != matricula) {
        posicao_atual = m->matr[posicao_atual].proximo;
    }

    // Verificar se o elemento foi encontrado
    if (posicao_atual == -1) {
        printf("Elemento não encontrado na lista.\n");
        return -1;
    }

    // Alterar o valor da matrícula
    m->matr[posicao_atual].alun.matricula = nova_matricula;

    return posicao_atual;
}

void Liberar(lista_chave *m) {
    m->inicio = -1;
    m->disponivel = 0;
}

void ListaVazia(lista_chave *m) {
    if (m->inicio == -1){
        printf("lista vazia");
    }
    
}

void ListaCheia(lista_chave *m) {
    if (m->disponivel == 0){
        printf("lista cheia");
    }
    
}