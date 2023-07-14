#ifndef HASH_SIMPLES_REGISTRO_H_INCLUDED
#define HASH_SIMPLES_REGISTRO_H_INCLUDED

#define MAX 5

typedef struct {
    char nome[50];
    char cpf[15];
    int idade;
    int chave;
} PESSOA;

typedef struct aux {
    PESSOA pessoa;
    struct aux* proximo;
} ELEMENTO;

typedef struct {
    ELEMENTO* tabela[MAX];
} TAB_HASH;


#endif // HASH_SIMPLES_REGISTRO_H_INCLUDED
