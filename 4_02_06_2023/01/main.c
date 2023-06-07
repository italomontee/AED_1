#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"


int main() {
    lista_chave lista;
    Inicializar(&lista);

    alunos aluno1 = { 227, "Italo", 19 };
    alunos aluno2 = { 456, "Camila", 20 };
    alunos aluno3 = { 665, "Cortez", 19 };

    InserirOrdenado(&lista, aluno1);
    InserirOrdenado(&lista, aluno2);
    InserirOrdenado(&lista, aluno3);

    printf("Lista de alunos:\n");
    Exibir(&lista);
    printf("Tamanho da lista: %d\n", Tamanho(&lista));

    int posicao = BuscaSeqOrd(&lista, 456);
    if (posicao != -1) {
        printf("Aluno encontrado na posicao %d.\n", posicao);
    } else {
        printf("Aluno nao encontrado na lista.\n");
    }

    int nova_matricula = 7890;
    AlterarMatricula(&lista, 789, nova_matricula);
    printf("Matricula alterada para %d.\n", nova_matricula);
    Exibir(&lista);

    int matricula_excluida = 123;
    Excluir(&lista, matricula_excluida);
}