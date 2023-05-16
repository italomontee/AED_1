#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pessoa {
    char nome[50];
    char dataNascimento[11];
    char cpf[12];
} Pessoa;

void preencheDadosPessoa(Pessoa *pessoa) {
    printf("Digite o nome da pessoa: ");
    fgets(pessoa->nome, 50, stdin);

    printf("Digite a data de nascimento (DD/MM/AAAA): ");
    fgets(pessoa->dataNascimento, 12, stdin);
    
    printf("Digite o CPF (somente numeros): ");
    fgets(pessoa->cpf, 13, stdin);
    
}

void imprimeDadosPessoa(Pessoa *pessoa) {
    printf("Nome: %s", pessoa->nome);
    printf("Data de Nascimento: %s", pessoa->dataNascimento);
    printf("CPF: %s", pessoa->cpf);
}

int main() {
    Pessoa *pessoa = (Pessoa *) malloc(sizeof(Pessoa));
    preencheDadosPessoa(pessoa);
    imprimeDadosPessoa(pessoa);
    free(pessoa);
    return 0;
}
