#ifndef HASH_ENCAD_INTEIRO_H_INCLUDED
#define HASH_ENCAD_INTEIRO_H_INCLUDED

#define MAX 5

typedef struct aux {
    int chave;
    struct aux* proximo;
} ELEMENTO;

typedef struct {
    ELEMENTO* tabela[MAX];
} TAB_HASH;

void inicializar(TAB_HASH * tab);
int mhash(int chave);
int inserir(TAB_HASH* tab, int chave);
int excluir(TAB_HASH* tab, int chave);
void mostrar(TAB_HASH * tab);


#endif // HASH_ENCAD_INTEIRO_H_INCLUDED
