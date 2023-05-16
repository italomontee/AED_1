#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct Pessoa {
    char nome[50];
    Data dataNascimento;
    char cpf[12];
} Pessoa;

void preencheDadosData (Data *data){
    printf("Dia: ");
    scanf("%d", &(data->dia));
    printf("Mes: ");
    scanf("%d", &(data->mes));
    printf("Ano: ");
    scanf("%d", &(data->ano));
}

void preencheDadosPessoa(Pessoa *pessoa) {
    printf("Digite o nome da pessoa: ");
    fgets(pessoa->nome, 50, stdin);

    printf("Digite a data de nascimento: \n");
    preencheDadosData(&(pessoa->dataNascimento));
    
    printf("Digite o CPF (somente numeros): ");
    fgets(pessoa->cpf, 12, stdin);
    
}

void imprimeDadosData(Data *data) {
    printf("Data de Nascimento: %02d/%02d/%04d\n", data->dia, data->mes, data->ano);
}


void imprimeDadosPessoa(Pessoa *pessoa) {
    printf("Nome: %s", pessoa->nome);
    imprimeDadosData(&(pessoa->dataNascimento));
    printf("CPF: %s", pessoa->cpf);
}

int main() {
    Pessoa *pessoa = (Pessoa *) malloc(sizeof(Pessoa));
    preencheDadosPessoa(pessoa);
    imprimeDadosPessoa(pessoa);
    free(pessoa);
    return 0;
}