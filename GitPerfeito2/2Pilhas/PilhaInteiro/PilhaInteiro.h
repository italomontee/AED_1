#ifndef PILHAINTEIRO_H_INCLUDED
#define PILHAINTEIRO_H_INCLUDED

typedef struct aux {
    int numero;
    struct aux* proximo;
} ELEMENTO;

typedef struct {
    ELEMENTO* topo;
} PILHA;

void Inicializar(PILHA* p);
int PilhaVazia(PILHA* p);
void Empilhar(PILHA* p, int numero);
int Desempilhar(PILHA* p);
void MostrarPilha(PILHA* p);



#endif // PILHAINTEIRO_H_INCLUDED
