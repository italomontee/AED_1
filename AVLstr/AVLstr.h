#ifndef AVLSTR_H_INCLUDED
#define AVLSTR_H_INCLUDED

typedef struct aux {
    char chave[100];
    int h;
    struct aux * esquerda;
    struct aux * direita;
} NO;

typedef struct {
    NO * raiz;
} AVL;

//inicializar
void Inicializar(AVL * arvore);

//medidas
int Altura(NO* raiz);
int Profundidade(NO* raiz, char* codigo, int cont);
int Nivel(NO* raiz, char codigo, int cont);
int Contar(NO* raiz, int * count);
int maximo (int v1, int v2);

//rotações
NO* rot_direita(NO* NO_desb);
NO* rot_esquerda(NO* NO_desb);
NO* rot_dir_esquerda(NO* NO_desb);
NO* rot_esq_direita(NO* NO_desb);

//inserir
void atualizaAltura(NO* no);
int fatorBalanceamento(NO* no);
NO* inserir(NO* no, char dado[]);

//imprimir
void ImprimirInOrder(NO* raiz);
void ImprimirPreOrder(NO* raiz);
void ImprimirPosOrder(NO* raiz);
int PercorrerEmLargura(NO* raiz);

//buscar
NO* Buscar(NO * no, char cod[]);


#endif // AVLSTR_H_INCLUDED
