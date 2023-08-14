#ifndef ARVB_H
#define ARVB_H


// árvore b de ordem 3
#define MAX 2
#define MIN 1

// Declaração da estrutura
typedef struct aux {
    int item[MAX + 1];
    int cont;
    struct aux* linker[MAX + 1];
}No;

typedef struct{
    No *raiz;
}Arvore;


// Declaração das funções

void inicializarArvore(Arvore *t);
No *criarNo(Arvore *t, int item, No *filho);
void inserir(Arvore *t, int item);
int definirValorNo(int item, int *pval, No *node, No **filho);
void addValorNo(int item, int pos, No *node, No *filho);
void split(int item, int *pval, int pos, No *node, No *filho, No **newNode);
int buscarNaAvore(int item, int *pos, No *no);
int busca(Arvore *t, int item);
void imprimir( No *no);



void copySuccessor(No *no, int pos);
void removeVal(No *no, int pos);
void rightShift(No *no, int pos);
void leftShift(No *no, int pos);
void mergeNodes(No *no, int pos);
void adjustNode(No *no, int pos);
int delValFromNode(int item, No *no);
void delete(int item, No *no, No *raiz);
void searching(int item, int *pos, No *no);
void traversal( No *no);

#endif
