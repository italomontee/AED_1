#ifndef HASH_ENCAD_INTEIRO_H_INCLUDED
#define HASH_ENCAD_INTEIRO_H_INCLUDED
#define MAX 5
typedef struct {
    char* nome;
    char* cpf;
    int chave;
    int idade;
} PESSOA;

typedef struct aux {
    PESSOA pess;
    struct aux* proximo;
} ELEMENTO;

typedef struct {
    ELEMENTO* tabela[MAX];
} TAB_HASH;

void inicializar(TAB_HASH * tab);
int mhash(int cod);
int inserir(TAB_HASH * tab, PESSOA pessoa_nova);
int excluir(TAB_HASH * tab, PESSOA pessoa_excluir);
void mostrar(TAB_HASH * tab);


#endif // HASH_ENCAD_INTEIRO_H_INCLUDED
