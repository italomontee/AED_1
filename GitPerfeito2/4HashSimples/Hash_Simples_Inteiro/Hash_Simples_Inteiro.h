#ifndef HASH_SIMPLES_INTEIRO_H_INCLUDED
#define HASH_SIMPLES_INTEIRO_H_INCLUDED
#define MAX 5
typedef struct {
    int numero;
} NUMERO;

typedef struct {
    NUMERO * tabela[MAX];
} TAB_HASH;

void Inicializar(TAB_HASH *tab);
int mhash(int cod);
int inserir(TAB_HASH *tab, NUMERO num);
int excluir(TAB_HASH *tab, NUMERO num);
void mostrar(TAB_HASH *tab);



#endif // HASH_SIMPLES_INTEIRO_H_INCLUDED
