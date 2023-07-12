#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED
#define MAX 5
typedef struct aux {
    int codigo;
    char * nome;
    int cpf;
    int idade;
    struct aux* proximo;
} PESSOA;

typedef struct {
    PESSOA * tabela[MAX]
}TabelaHash;

int m_hasg (int cod_pess);
int inserir (TabelaHash tab, PESSOA pess);
void inicializarHash(TabelaHash tab);
void mostrarHash (TabelaHash tab);
PESSOA * busca(TabelaHash tab, int cod);

#endif // HASH_H_INCLUDED
