#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED
#define MAX 10
//TABELA HASH COM LISTA LIGADA
typedef struct {
    char* nome;
    int idade;
    int cpf;
    int cod;
} PESSOA;

typedef struct  aux{
    PESSOA pessoa;
    struct aux * proximo;
}ELEMENTO;

typedef struct {
    ELEMENTO * tabela[MAX]
} TAB_HASH;

void inicializar(TAB_HASH *tab);
int mhash(int cod);
void inserir(TAB_HASH *tab, PESSOA pessoa);
void mostrar(TAB_HASH *tab);
PESSOA * buscar(TAB_HASH *tab, PESSOA pessoa);

#endif // HASH_H_INCLUDED
