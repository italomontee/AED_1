#ifndef PILHAREGISTRO_H_INCLUDED
#define PILHAREGISTRO_H_INCLUDED

typedef struct {
    char modelo[50];
    char fabricante[50];
    int ano;
} AVIAO;

typedef struct aux {
    AVIAO aviao;
    struct aux* proximo;
} ELEMENTO;

typedef struct {
    ELEMENTO* topo;
} PILHA;

void Inicializar(PILHA* p);
int PilhaVazia(PILHA* p);
void ColocarAeronave(PILHA* p, AVIAO aviao);
void AdicionarAviao(PILHA* p, char modelo[50], char fabricante[50], int ano);
void ListarAvioesHangar(PILHA* p);
void ListarPrimeiroAviao(PILHA* p);
void LancarAviao(PILHA* p, int posicao);

#endif // PILHAREGISTRO_H_INCLUDED
