#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct  {
    int matricula;
    char nome[20];
    int idade;
} alunos;

typedef struct
{
    alunos alun;
    int proximo;
} elemento;

typedef struct 
{
  elemento matr[MAX]; 
  int inicio;
  int disponivel;
} lista_chave;


void Inicializar(lista_chave* m){
    for (int i = 0; i < 10; i++)
    {
        m->matr->proximo = i+1;
        m->matr[MAX-1].proximo = -1;
        m->inicio = -1;
        m->disponivel = 0;
    }
    
}

int Tamanho(lista_chave* m){
    int tam = 0;
    int i = m->inicio;
    while (i != -1)
    {
        tam++;
        i = m->matr[i].proximo;
    }
    return tam;
}

void Exibir(lista_chave *m){
    int i = m->inicio;
    while (i != -1)
    {
        printf("Aluno: %c", m->matr[i].alun.nome);
        printf("Idade: %d", m->matr[i].alun.idade);
        printf("Matricula: %d", m->matr[i].alun.matricula);
    }
    
}

void BuscaSeqOrd(lista_chave *m, int elem) {
    int i = m->inicio;
    while (i != -1 && m->matr[i].alun.matricula < elem)
    {
        i = m->matr[i].proximo;
        if (m->matr[i].alun.matricula == elem)
        {
            return i;
        }
        else {
            return -1;
        }
    }
    
}

int main() {
    
    alunos lista[3];

    


}